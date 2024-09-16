#include <iostream>

using namespace std;

int main()
{
    char arreglo[]={'a','b','c','d'}, dato;
    int i = 0;
    bool flag= false;
    dato='d';

    while(flag==false && i<4)
    {
        if (arreglo[i]==dato)
        {
            flag=true;
            break;
        }
        i++;
    }

    if(flag==false)
    {
        cout<<"el dato a buscar no se encuentra en el arreglo"<<endl;
    } else
    {
        cout << "El dato"<< dato <<"se enceuntra en la posicion del artreglo: "<<i;
    }
}