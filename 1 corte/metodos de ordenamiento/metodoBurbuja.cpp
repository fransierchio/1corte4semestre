#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{

    int array[] = {3,2,8,4,1,4,9};
    int i,j,aux;
    int tam= (sizeof(array)/sizeof(array[0]))-1;

    for(i = 0; i<tam;i++)
    {
        for(j=0; j<tam-i;j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }

    for (i = 0; i<7;i++)
    {
        cout<<array[i]<<endl;
    }
}