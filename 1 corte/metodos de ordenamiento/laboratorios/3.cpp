#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    srand(time(NULL));
    int filas=0, columnas=0;
    cout<<"Ingresa el numero de filas de tu array: ";
    cin>>filas;
    cout<<"Ingresa el numero de columnas de tu array: ";
    cin>>columnas;
    int array[filas][columnas];

    if (filas==columnas)
    {
        cout<<"Es una matris cuadrada"<<endl;
    } else 
    {
        cout<<"Es una matris asimetrica"<<endl;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            array[i][j]=rand()%5;
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

    return 0;
}