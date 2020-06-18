#include <iostream>

using namespace std;

class Secret
{
    int secret_int;

    friend class FriendClass; // friend <deklaracja klasy>
    friend void FriendFunction(Secret & x); //friend <deklaracja funkcji>
};

class FriendClass
{
public:
    void metoda ( Secret & x)
    {
        x.secret_int = 0;
        std::cout << x.secret_int;
    }
};

void FriendFunction( Secret & x)//zaprzyjazniona funkcja moze byc zdefiniowana w kalsie/ a nie metoda
{
    x.secret_int = 0;
}

int main()
{
    Secret x;

    FriendClass k;

    k.metoda(x);
    FriendFunction(x);

    return 0;
}
