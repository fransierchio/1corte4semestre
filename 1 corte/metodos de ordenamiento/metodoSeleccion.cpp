#include <iostream>

using namespace std;

int main()
{
    int array[]={3,4,2,1,5,1};
    int i,j,aux,min;

    for (i=0; i<6;i++)
    {
        min=i;
        for (j=i+1; j<6; j++)
        {
            if(array[min]>array[j])
            {
                min=j;
            }
        }
        aux = array[i];
        array[i]=array[min];
        array[min]=aux;
    }

    for(i=0;i<6;i++)
    {
        cout<<array[i]<<endl;
    }

}
