#include <iostream>

int main(int argc, char* argv[])
{
    int l1, l2;

    std::cin >> l1 >> l2;
    double w = static_cast<float>(l1)/static_cast<float>(l2);

    double* s = &w;
    std::cout << *s << std::endl;
    return 0;
}
