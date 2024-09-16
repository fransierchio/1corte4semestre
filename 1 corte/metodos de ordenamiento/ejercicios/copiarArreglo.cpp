#include <iostream>
#include <cmath>

using namespace std;
void copia(int (&array)[10]);
void mostrar(int (&array)[10]);

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"ingresa el valor N-"<<i<<": ";
        cin>>array[i];
    }
    mostrar(array);
    copia(array);

    return 0;
}

void mostrar(int (&array)[10])
{
    for(int show : array)
    {
        cout<< show << " ";
    }
    cout<<endl;
}

void copia(int (&array)[10])
{   
    int copia[10];
    for (int i = 0; i < 10; i++)
    {   
        array[i]<0 ? copia[i]=abs(array[i]):NULL;
        array[i]>0 ? copia[i]=ceil(pow(array[i],2)):NULL;
        array[i]==0 ? copia[i]=array[i]:NULL;
    }
    cout<<"modificado"<<endl;
    mostrar(copia);
}