#include <iostream>

using namespace std;

void inverso(int array)
{
    if (array<10)
    {
        cout<<array;
        return;
    }
    cout<<array%10;
    inverso(array/10);
}

int main()
{
    int *numeros = new int;
    *numeros=12134324;
    inverso(*numeros);

    delete numeros;
    numeros = nullptr;
    return 0;
}