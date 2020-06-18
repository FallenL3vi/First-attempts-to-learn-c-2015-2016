#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cstdlib>
#include <ctime>

struct chip8
{
	unsigned short opcode;
	unsigned char memory[4096];
	unsigned char V[16];
	unsigned short I;
	unsigned short pc;
	unsigned char gfx[64 *32];
	unsigned char delay_timer;
	unsigned char sound_timer;
	unsigned short stack[16];
	unsigned short sp;
	unsigned char key[16];

	unsigned char chip8_fontset[80] =
	{
	  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	  0x20, 0x60, 0x20, 0x20, 0x70, // 1
	  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  	  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  	  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  	  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  	  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  	  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  	  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  	  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  	  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  	  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
 	  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
 	  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  	  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  	  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

	void initialize();
	void loadGame(std::string name);
	void emulateCycle();
};

void chip8::initialize()
{
	pc = 0x200; //Program counter starts at 0x200
	opcode = 0; //Reset current opcode
	I = 0; //Reset index register
	sp = 0; //Reset stack pointer


	//Clear display
	for(auto &i : gfx)
		i = 0;

	//Clear stack
	for(auto &i : stack)
		i = 0;

	//Clear registers V0-VF
	for(auto &i : V)
		i = 0;

	//Clear memory
	for(auto &i : memory)
		i = 0;
	
	//Load fontset
	for(int i = 0; i < 80; ++i)
		memory[i] = chip8_fontset[i];

	//Reset timers
	delay_timer = 60;
	sound_timer = 60;
}

void chip8::loadGame(std::string name)
{
	int bufferSize = 4096 - 512;
	char buffer[bufferSize];
	std::ifstream file;
	file.open(name, std::ifstream::binary);
	
	if(!file.good())
	{
		std::cout << "BUE" << std::endl;
	}

	file.read(buffer,bufferSize);

	for(int i = 0; i < bufferSize; ++i)
		memory[i + 512] = buffer[i];

	file.close();

	for(auto i : memory)
		std::cout << i;
}

void chip8::emulateCycle()
{
	//Fetch opcode
	opcode = memory[pc] << 8 | memory[pc + 1];
	
	//Decode opcode
	switch(opcode & 0xF000)
	{
		case 0x0000:
			{
				switch(opcode & 0x000F)
				{
					case 0x0000: //0x00E0: Clears the screen
					{
						for(auto &i : gfx)
							i = 0;
						pc +=2;
						break;
					}
					
					case 0x000E: //0x00EE: Returns from subroutine
					{
						pc = stack[sp];
						sp--;
						break;
					}
					
					default:
						break;
				}
			}
		//Some opcodes

		case 0xA000: //ANNN: Sets I to the adress NNN
			{
				I = opcode & 0x0FFF;
				pc += 2;
				break;
			}
		
		case 0x1000: //Jump to the adress NNN
			{
				pc = opcode & 0x0FFF;
				break;
			}

		case 0x2000: //Call subroutine on NNN
			{
				stack[sp] = pc;
				sp++;
				pc = opcode & 0x0FFF;
				break;
			}

		case 0x3000: //if Vx == NN skip the next instruction 3XNN
			{
				if(V[(opcode & 0x0F00) >> 8] == opcode & 0x00FF)
					pc += 4;
				break;
			}

		case 0x4000:
			{
				if(V[(opcode & 0x0F00) >> 8] != opcode & 0x00FF)
					pc += 4;
				break;
			}

		case 0x5000:
			{
				if(V[(opcode & 0x0F00) >> 8] == V[(opcode & 0x00F0) >> 4])
					pc +=4;
				break;
			}

		case 0x6000:
			{
				V[(opcode & 0x0F00) >> 8] = opcode & 0x00FF;
				pc += 2;
				break;
			}

		case 0x7000:
			{
				V[(opcode & 0x0F00) >> 8] += opcode & 0x00FF;
				pc += 2;
				break;
			}

		case 0x8000:
		{
			switch(opcode & 0x000F)
			{
				case 0x0000:
				{
					V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x00F0) >> 4];
					pc += 2;
					break;
				}

				case 0x0001:
				{
					V[(opcode & 0x0F00) >> 8] = (V[(opcode & 0x0F00) >> 8] | V[(opcode & 0x00F0) >> 4]);
					pc += 2;
					break;
				}

				case 0x0003:
				{
					V[(opcode & 0x0F00) >> 8] = (V[(opcode & 0x0F00) >> 8] & V[(opcode & 0x00F0) >> 4]);
					pc += 2;
					break;
				}				

				case 0x0004:
				{
					if(V[(opcode & 0x00F0) >> 4] > V[0xFF - (opcode & 0x0F00 >> 8)])
						V[0xF] = 1;
					else
						V[0xF] = 0;

					V[(opcode & 0x0F00) >> 8] += V[(opcode & 0x00F0) >> 4];
					pc += 2;

					break;
				}

				case 0x0005:
				{
					if(V[(opcode & 0x0F00) >> 8] > V[(opcode & 0x00F0) >> 4])
						V[0xF] = 1;
					else
						V[0xF] = 0;
					V[(opcode & 0x0F00) >> 8] -= V[(opcode & 0x00F0) >> 4];
					pc += 2;
					break;
				}

				case 0x0006:
				{
					V[0xF] = (V[(opcode & 0x0F00) >> 8]) & 1;
					V[(opcode & 0x0F00) >> 8] >>= 1;
					pc += 2;
					break;
				}

				case 0x0007:
				{
					if(V[(opcode & 0x0F00) >> 8] > V[(opcode & 0x00F0) >> 4])
						V[0xF] = 1;
					else
						V[0xF] = 0;

					V[(opcode & 0x0F00) >> 8] = (V[(opcode & 0x00F0) >> 4] - V[(opcode & 0x0F00) >> 8]);
					pc += 2;
					break;
				}

				case 0x000E:
				{
					V[0xF] = (V[(opcode & 0x0F00) >> 8] & 0b10000000) >> 7;
					V[(opcode & 0x0F00) >> 8] <<= 1; 
					pc += 2;
					break;
				}

				default:
					break;
			}
		}
		
		case 0x9000:
		{
			if(V[(opcode & 0x0F00) >> 8] != V[(opcode & 0x00F0) >> 8])
				V[0xF] = 1;
			else
				V[0xF] = 0;
			pc += 2;
			break;
		}
		
		case 0xB000:
		{
			pc = V[0] + (opcode & 0x0FFF);
			break;
		}

		case 0xC000:
		{
			V[(opcode & 0x0F00) >> 8] = (std::rand()&(opcode & 0x00FF));
			pc += 2;
			break;
		}

		case 0xD000:
		{
			unsigned short x = V[(opcode & 0x0F00) >> 8];
			unsigned short y = V[(opcode & 0x00F0) >> 4];
			unsigned short height = V[(opcode & 0x000F)];
			unsigned short pixel;

			V[0xF] = 0;
			
			for(int yline = 0; yline < height; yline++)
			{
				pixel = memory[I + yline];
				for(int xline = 0; xline < 8; xline++)
				{
					if((pixel & (0x80 >> xline)) != 0)
					{
						if(gfx[(x + xline + ((y + yline) * 64))] == 1)
							V[0xF] = 1;
						gfx[x + xline + ((y + yline) * 64)] ^= 1;
					}
				}
			}

			drawFlag = true;
			pc += 2;
			break;
		}
		
		case 0xE000:
		{
			switch(opcode & 0x00FF)
			{
				case 0x009E:
					{
						if(key[V[(opcode & 0x0F00) >> 8]] != 0)
							pc += 4;
						else
							pc += 2;
						break;
					}

				case 0x00A1:
					{
						if(key[V[(opcode & 0x0F00) >> 8]] == 0)
							pc += 4;
						else
							pc += 2;
						break;
					}

				defautl:
					break;
			}
		}
					
		case 0xF000:
		{
			switch(opcode & 0x00FF)
			{
				case 0x0007:
					{
						V[(opcode & 0x0F00) >> 8] = delay_timer;
						pc += 2;
						break;
					}
				case 0x000A:
					{
						std::cout << "nope" << std::endl;
						pc += 2;
						break;
					}
				
				case 0x0015:
					{
						delay_timer = V[(opcode & 0x0F00) >> 8];
						pc += 2;
						break;
					}

				case 0x0018:
					{
						sound_timer = V[(opcode & 0x0F00) >> 8];
						pc += 2;
						break;
					}
				case 0x001E:
					{
						I += V[(opcode & 0x0F00) >> 8];
						pc += 2;
						break;
					}
				
				case 0x0029:
					{

						pc += 2;
						break;
					}
				case 0x0033:
					{
						memory[I] = V[(opcode & 0x0F00) >> 8] / 100;
						memory[I + 1] = (V[(opcode & 0x0F00) >> 8] /10) % 10;
						memory[I + 2] = (V[(opcode & 0x0F00) >> 8] % 100) % 10;
						pc += 2;
						break;
					}
				default:
					break;
			}
		}

		default:
			std::cout << "Unknown opcode" << std:: endl;
	}

	//Update timers
	if(delay_timer > 0)
		--delay_timer;
	if(sound_timer > 0)
	{	
		if(sound_timer == 1)
		{
			std::cout << "BEEP!\n" << std::endl;
			--sound_timer;
		}
	}	
}

chip8 myChip8;

int main(int argc, char **argv)
{
	std::srand(time(nullptr));
/*	setupGraphics();
	setupInput();
*/
	myChip8.initialize();
	myChip8.loadGame("games/PONG");

/*	for(;;)
	{
		myChip8.emulateCycle();

		if(myChip8.drawFlag)
			drawGraphics();

		myChip8.setKeys();
	}
*/
	return 0;
}
