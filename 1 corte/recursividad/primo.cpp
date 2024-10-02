#include <iostream>
#include <math.h>

using namespace std;

int isPrimo(int *num, int divisor);

int main()
{
    int *num= new int;
    int divisor=2;
    bool test=false;
    cout<<"Escribe un numero para saber si es primo: ";
    cin>>*num;
    test=isPrimo(num, divisor);
    
    test ? cout<<"Es primo" : cout<<"no es primo";

    delete num;
    return 0;
}

int isPrimo(int *num, int divisor)
{
    if (*num<=1) //menor o igual a uno no es primo
    {
        return false;
    }
    
    if (*num==2) // si es dos es primo EXCEPCION
    {
        return true;
    }
    
    if (*num%2==0) // si es par mayor a 2 no es primo
    {
        return false;
    } 

    if (divisor>*num/2)
    {
        return true;
    }

    if (*num%divisor==0)
    {
        return false;
    }
    
    

    return isPrimo(num, divisor+1);

}