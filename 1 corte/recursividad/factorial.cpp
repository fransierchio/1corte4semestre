#include <iostream>

using namespace std;

int factorial(int puntero);
int potencia(int puntero, int exponente);


int main ()
{
    int numero=5;
    int *puntero= new int(numero);
    numero=factorial(*puntero);
    cout<<numero<<endl;

    int exponente=3;
    *puntero=10;
    numero=potencia(*puntero, exponente);
    cout<<numero;

    delete puntero;
    puntero=nullptr;



    return 0;
}

int factorial(int puntero)
{
    if (puntero > 1)
    {
        return  puntero  * factorial(puntero-1);
    } else 
    {
        return 1;
    }
    
}

int potencia(int puntero, int exponente)
{
    if (exponente>0)
    {
        return puntero * potencia(puntero,exponente-1);
    } else
    {
        return puntero;
    }
    
}