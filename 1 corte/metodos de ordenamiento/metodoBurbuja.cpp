#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{

    int array[] = {3,2,8,4,1,4,9,657,567,56,56,565,45,4,5,4};
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

    for (i = 0; i<tam;i++)
    {
        cout<<array[i]<<endl;
    }
}