#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

void random(vector<int>&array);
void imprimir(vector<int>&array);
void par(vector<int>&array, float mitad);
void min(vector<int>&array, float mitad);

int main()
{
    srand(time(NULL));
    int size=rand()%10+2;
    vector<int> array(size);
    float mitad = size/2;

    random(array);
    imprimir(array);
    par(array,mitad);
    min(array,mitad);


    return 0;
}

void random(vector<int>&array)
{
    srand(time(NULL));
    cout<<"Elementos del vector: "<< endl;

    for(int i=0;i<array.size();i++)
    {
        array[i]=rand()%10;
    }
}

void imprimir(vector<int>&array)
{
    int pos=0;
    for(int show:array)
    {
        cout<<show<<endl;
        pos++;
    }
}

void par(vector<int>&array, float mitad)
{
    int suma=0;
    for(int i=0;i<array.size();i++)
    {
        if(i>=mitad)
        {
            if((array[i]%2)==0)
            {
                suma+=array[i];
            }
        }

    }
    cout<<"La suma de los numeros pares desde la mitad hasta el final del vector es de: "<<suma<<endl;
}

void min(vector<int>&array, float mitad)
{
    int menor=array[0];
    for(int i=0;i<array.size();i++)
    {
        if(i<=mitad-1)
        {
            if(menor>array[i])
            {
                menor=array[i];
            }
        }

    }
    cout<<"el numero menor desde la mitad hasta el inicio del vector es de: "<<menor<<endl;
}
