#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;
int sumaRecursiva(int *array,int size);
int busquedaBinariaRecursiva(int *array,int inicio, int fin, int objetivo );


int main()
{
    srand(time(NULL));
    int size=10, suma=0, objetivo=7, indice=0;
    int *array= new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i]=(rand()%10)+1;
        cout<<array[i]<<", ";
    }
    cout<<endl;

    sort(array, array+size);
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<", ";
    }
    cout<<endl;
    
    indice=busquedaBinariaRecursiva(array,0,size-1,objetivo);
    suma=sumaRecursiva(array,size);
    cout<<"la suma de los elementos en el array es de: "<< suma<<endl;

    if (indice==-1)
    {
        cout<<"No se enmcontro el numero "<<objetivo<<" en el array"<<endl;
    } else 
    {
        cout<<" el numero "<< objetivo << " se encuentra en la posicion "<< indice+1;
    }
    

    delete[] array;
    

    return 0;
}

int sumaRecursiva(int *array,int size)
{
    if (size!=0)
    {
        return array[size-1] + sumaRecursiva(array,size-1) ;
    } else 
    {
        return 0;
    }
    
}

int busquedaBinariaRecursiva(int *array,int inicio, int fin, int objetivo )
{

    if (inicio>fin)
    {
        return -1;
    }
    
    int mid=(inicio+fin)/2;

    if (array[mid]==objetivo)
    {
        return mid;
    }

    if (array[mid]>objetivo)
    {
        return busquedaBinariaRecursiva(array,inicio,mid-1,objetivo);
    } else 
    {
        return busquedaBinariaRecursiva(array,mid+1,fin,objetivo);
    }
    
}
