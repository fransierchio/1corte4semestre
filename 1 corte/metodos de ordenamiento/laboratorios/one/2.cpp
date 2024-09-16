#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int array[5], copia[5];
    
    for (int i = 0; i < 5; i++)
    {
        array[i]=rand()%5;
        copia[i]=array[i]*2;
    }

    for (int show: array)
    {
        cout<<show<<" ";
    }

    cout<<endl;

    for (int show: copia)
    {
        cout<<show<<" ";
    }


    

    return 0;
}