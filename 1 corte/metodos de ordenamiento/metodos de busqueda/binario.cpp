#include <iostream>
#include <time.h>

using namespace std;

void random(int (&array)[10]);
void ordenar(int (&array)[10]);
void buscar(int (&array)[10]);

int main()
{
    int array[10];
    random(array);
    ordenar(array);
    buscar(array);

    return 0;
}

void random(int (&array)[10])
{
    srand(time(NULL));
    for(int i=0; i<10;i++)
    {
        array[i]=rand()%10;
    }
}

void ordenar(int (&array)[10])
{
    int i,j,min;
    int size=sizeof(array)/sizeof(array[0]);
    for(i=0;i<size;i++)
    {
        min=i;
        for (j = i+1; j < size; j++)
        {
            if (array[j]<array[min])
            {
                min=j;
            }
            swap(array[i],array[min]);
        }
    }
    for(int show : array){cout<<show<<endl;}
}

void buscar(int (&array)[10])
{
    int target, primero=0,ultimo=9,mitad;
    bool flag= false;
    int xd;

    cout<<"Cual numero buscas(1 cifra)?"<<endl;
    cin>>target;
    
    while(flag==false&&primero <= ultimo)
    {
        mitad= (primero + ultimo)/2;

         if (array[mitad] == target)
        {
            flag = true;
        }
        else if (array[mitad] < target)
        {
            primero = mitad + 1;
        }
        else
        {
            ultimo = mitad - 1;
        }

    }

    if(flag==false)
    {
        cout<<"no se ha encontrado el numero en el arreglo";
    } else 
    {
        cout << "el numero: " << target<<" se encuentra en el array en la posicion " << mitad;
    }
}