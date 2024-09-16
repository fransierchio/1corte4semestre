#include <iostream>
#include <time.h>

using namespace std;
void minMax(int (&array)[10]);
void random(int (&array)[10]);
void repeated(int (&array)[10], int min, int max);

int main()
{
    srand(time(NULL));
    int array[10];
    random(array);
    minMax(array);

    return 0;
}

void random(int (&array)[10])
{
    for (int i = 0; i < 10; i++)
    {
        array[i]=rand()%10;
    }

    for (int show : array)
    {
        cout<<show<<endl;
    }
    
}

void minMax(int (&array)[10])
{
    int min=array[0],max=array[0];
    for (int i = 0; i < 10; i++)
    {
        if (min>array[i])
        {
            min=array[i];
        } 
        if (max<array[i])
        {
            max=array[i];
        }
    }
    cout << "el numero minimo es: "<< min<< " y el maximo es: "<<max<<endl;
    repeated(array,min,max);
}

void repeated(int (&array)[10], int min, int max)
{
    int repsMin=0, repsMax=0;
    for (int i = 0; i < 10; i++)
    {
        array[i]==min ? repsMin++:NULL;
        array[i]==max ? repsMax++:NULL;
    }
    cout <<"el numero maximo se repite: "<<repsMax<< " veces"<<endl;
    cout <<"el numero minimo se repite: "<<repsMin<< " veces"<<endl;
}