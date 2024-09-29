#include <iostream>
#include <time.h>

using namespace std;

void mayor(int *array,int size, int max);
int recursiva(int *array, int i);

int main()
{   
    srand(time(NULL));
    int size=10, suma=0;
    int *array= new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i]=rand()%10;
        cout<<array[i]<<" ";
    }
    int max=array[0];
    
    mayor(array,size-1,max);
    suma=recursiva(array, size-1);

    cout<<endl<<suma;

    delete[] array;
    return 0;
}

void mayor(int *array,int size, int max)
{
    if (size==0)
    {
        cout<<"el numero mayor es: "<< max;
        return;
    } 
    if (array[size]>max)
    {
        max=array[size];
    }


    mayor(array,size-1,max);
}

int recursiva(int *array, int i)
{
    
    if (i<0)
    {
        return 0;
    } 
        return array[i] + recursiva(array, i-1);
}