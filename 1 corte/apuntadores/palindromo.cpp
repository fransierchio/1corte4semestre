#include <iostream>
#include <string.h>

using namespace std;

int palindromo(string palabra, int inicio, int final);

int main()
{
    string palabra;
    bool is=false;
    cout<<"ingresa la palabra: ";
    getline(cin,palabra);
    int inicio=0;
    int final=palabra.size()-1;

    is=palindromo(palabra, inicio, final);

    is ? cout<<"Es una palabra palindroma" : cout<<"No es una palabra palindroma";

    return 0;
}

int palindromo(string palabra, int inicio, int final)
{
    if (inicio>=final)
    {
        return true;
    }
    
    if (palabra[inicio]!=palabra[final])
    {
        return false;
    }

    if (tolower(palabra[inicio])==tolower(palabra[final]))
    {
        return palindromo(palabra, inicio+1, final-1);
    }
    
    
}