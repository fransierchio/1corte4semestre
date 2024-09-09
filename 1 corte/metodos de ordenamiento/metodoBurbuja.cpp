#include <iostream>
#include <conio.h>

using namespace std;

int main ()
{
    int array[] = {3,2,7,4,1,4,9};
    int i,j,aux;

    for(i = 0; i<7;i++)
    {
        for(j=0; j<7;j++)
        {
            if (array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }

    for (i = 0; i<7;i++)
    {
        cout<<array[i]<<endl;
    }
}