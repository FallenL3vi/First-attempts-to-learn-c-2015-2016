#include "world.hpp"

World::World(std::string file_path)
{
    std::string p = "asas";
    std::fstream file;

    file.open(file_path, std::ios::in);

    int tab [x][y];

    if(file.good() == true)
    {
        printf("Open");

        file.getline(map,25);
               // std::getline(file,map[x][y]);
               //printf(const_cast<char*>(map.c_str()));
               // file.seekg(+10,std::ios_base::cur);
        std::cout << map << std::endl;
        file.close();
    }
    else
    {
        printf("Faile");
    }
}
