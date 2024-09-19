#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string frase;
    cout<<"Ingrese una frase: ";
    getline(cin, frase);
    int size=frase.size(), caracteres=0;

    for (int i = 0; i < size; i++)
    {
        cout<<frase[i];
        caracteres++;
    }
    cout<<" Esta frase tiene "<<caracteres<<" caracteres incluyendo los espacios"<<endl;
    caracteres=0;
    for (int i = 0; i < size; i++)
    {
        if (frase[i]!=' ')
        {
            cout<<frase[i];
            caracteres++;
        }
        
    }
    cout<<" Esta frase tiene "<<caracteres<<" caracteres sin los espacios";
    

    return 0;
}