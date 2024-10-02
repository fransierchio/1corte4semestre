#include <iostream>

using namespace std;

int sumaDigitos(int numero);

int main()
{
    int *numero = new int;
    cin>>*numero;
    int suma=0;

    suma=sumaDigitos(*numero);
    cout<<suma;

    delete numero;
    numero=nullptr;
    return 0;
}

int sumaDigitos(int numero)
{
    if (numero < 10)
    {
        return numero;
    }
    return numero%10 + sumaDigitos(numero/10);
}