#include <iostream>
#include <time.h>

using namespace std;

void random(int(&array)[10]);
void imprimir(int (&array)[10]);
void ordernar(int (&array)[10]);

int main ()
{
    int array[10];
    srand(time(NULL));
    random(array);
    ordernar(array);
    imprimir(array);

}

void random(int (&array)[10])
{
    for(int i=0;i<10;i++)
    {
        array[i] = rand()%50;
    }
}

void imprimir(int (&array)[10])
{
    for(int i=0;i<10;i++)
    {
        cout<<array[i]<<endl;
    }
}

void ordernar(int (&array)[10])
{
    int i,pos,aux;
    for(i=0;i<10;i++)
    {
        pos=i;
        aux=array[i];

        while (pos>0 && array[pos-1]>aux)
        {
            array[pos] = array[pos-1];
            pos--;
        }
        array[pos]=aux;
    }
}