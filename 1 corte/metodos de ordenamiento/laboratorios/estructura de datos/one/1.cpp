#include <iostream>

using namespace std;

int main()
{
    int array[5];
    int size = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < size; i++)
    {
        cout<<"Ingrese valor: "<<endl;
        cin>> array[i];
    }

    int suma=0;
    for (int i = 0; i < size; i++)
    {
        suma=0;
        for (int j = i+1; j < size; j++)
        {
            suma+=array[j];
        }
        if (suma==array[i])
        {
              cout << "El valor " << array[i] << " en el indice " << i << " es igual a la suma de los elementos siguientes." << endl;
        }
        
    }
    
    

    return 0;
}