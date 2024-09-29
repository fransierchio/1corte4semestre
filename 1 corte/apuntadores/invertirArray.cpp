#include <iostream>
#include <time.h>

using namespace std;

void invertir(int *array, int size)
{
    int *inicio=array, *final=array+size-1;
    cout<<endl<<*inicio<<" "<<*final;

    while(inicio<final)
    {
        swap(*inicio, *final);
        inicio++;
        final--;
    }
    
    
}

int main ()
{
    srand(time(NULL));
    int size=10;
    int *array=new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i]=(rand()%10)+1;
        cout<<array[i]<<", ";
    }
    

    invertir(array,size);
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<", ";
    }

    delete[] array;
    array=nullptr;
    return 0;
}