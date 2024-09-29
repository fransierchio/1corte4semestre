#include <iostream>

using namespace std;

int contarDigitos(long long numero, int digito);
int sumarDigitos(long long numero);
void binarios(int numero);
int stringDigit(string numero, int i);

int main()
{
    long long numero=0;
    int digito=0, suma=0, i=0;
    string num;
    cout<<"Ingresa un valor para hacer operaciones: ";
    cin>>numero;
    cin.ignore();
    cin.clear();
    cout<<"INGRESA UNA CADENA DE CARCATERES PARA CONTAR LOS NUMEROS: ";
    getline(cin, num);
    digito=contarDigitos(numero, digito);
    cout<<endl<<"el numero "<<numero<<" tiene "<<digito<<" digitos";
    suma=sumarDigitos(numero);
    cout<<endl<<"la suma de los digitos de "<<numero<<" es de "<<suma;

    cout<<endl<<"el equivalente binario de "<<numero<<" es de ";
    binarios(numero);

    digito=stringDigit(num, i);
    cout<<endl<<"la cadena "<<num<<" tiene "<<digito<<" digitos";

    return 0;
}

int contarDigitos(long long numero, int digito)
{
    if (numero!=0)
    {
        return digito + contarDigitos(numero/10,digito++);
    } else 
    {
        digito;
    }
    
}

int sumarDigitos(long long numero)
{

    if (numero>1)
    {
        return numero%10 + sumarDigitos(numero/10);
    } else
    {
        return numero;
    }
    
}

void binarios(int numero)
{
    if (numero>1)
    {
        binarios(numero/2);
        cout<<numero%2;
    } else 
    {
        cout<<numero;
        numero;
    }
    
}

int stringDigit(string numero, int i)
{
    if(numero.size()>i)
    {
        int digitos=(isdigit(numero[i])?1:0);
        return digitos + stringDigit(numero, i+1);
    } else 
    {
        return 0;
    }
}
