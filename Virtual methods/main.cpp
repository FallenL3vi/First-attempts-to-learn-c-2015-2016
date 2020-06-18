#include <iostream>

using namespace std;

class Ksztalt
{
public:
        virtual ~Ksztalt()
        {}

        virtual void rysuj() = 0; //kazdy okreslony ksztalt musi dac sie narysowac
};

class Kolo  :public Ksztalt
{
public:
    virtual void rysuj()
    {
        std::cout << "Rysuj kolo: ()" << std::endl;
    }
};

class Kwadrat :public Ksztalt
{
public:
    virtual void rysuj()
    {
        std::cout << "Rysuj kwadrat: []" << std::endl;
    }
};

int main()
{
    Ksztalt * a = new Kolo, * b = new Kwadrat;

    a-> rysuj();
    b-> rysuj();

    delete a;
    delete b;

    return 0;
}
