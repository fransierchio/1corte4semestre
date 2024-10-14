#include <iostream>
#include <time.h>

using namespace std;

struct Nodo 
{
    int valor;
    Nodo *next;
};

void crearNodo(Nodo *&Head, int data)
{
    Nodo *nuevo=new Nodo;
    nuevo->valor=data;
    nuevo->next=nullptr;
    if (Head==nullptr)
    {
        Head=nuevo;
    } else 
    {
        Nodo *actual=Head;
        while (actual->next!=nullptr)
        {
            actual=actual->next;
        }
        actual->next=nuevo;
    }

}

void mostrar(Nodo *Head)
{
    Nodo *actual=Head;
        while (actual!=nullptr)
        {
            cout<<actual->valor<<" -> ";
            actual=actual->next;
        }
        
}

void ordenar(Nodo *Head)
{

    bool intercambiado;
    do
    {
        Nodo *actual=Head;
        intercambiado=false;
        while (actual->next!=nullptr)
        {
            if (actual->valor > actual->next->valor)
            {
                swap(actual->valor,actual->next->valor);
                intercambiado=true;
            }
            actual=actual->next;
        }
        
        
    } while (intercambiado);
    
}

void unir(Nodo *listaOne,Nodo *listaTwo,Nodo *&listaOrdenada)
{
    Nodo *one = listaOne;
    Nodo *two = listaTwo;

    while (listaOne!=nullptr && listaTwo!=nullptr)
    {
        if (listaOne->valor < listaTwo->valor)
        {
            crearNodo(listaOrdenada, listaOne->valor);
            listaOne= listaOne->next;
        }  
        else 
        {
            crearNodo(listaOrdenada, listaTwo->valor);
            listaTwo= listaTwo->next;
        }
    }

    while (listaOne!=nullptr)
    {
        crearNodo(listaOrdenada, listaOne->valor);
        listaOne= listaOne->next;
    }

    while (listaTwo!=nullptr)
    {
        crearNodo(listaOrdenada, listaTwo->valor);
        listaTwo= listaTwo->next;
    }
    
    
}

int main()
{
    srand(time(NULL));
    Nodo *listaOne = nullptr;
    Nodo *listaTwo = nullptr;
    Nodo *listaOrdenada= nullptr;

    for (int i = 0; i < 5; i++)
    {
        crearNodo(listaOne, rand()%100);   
    }

    for (int i = 0; i < 8; i++)
    {
        crearNodo(listaTwo, rand()%70);   
    }

    cout<<"Primera lista Desordenada: ";
        mostrar(listaOne);
    cout<<endl<<"Segunda lista Desordenada: ";
        mostrar(listaTwo);

    ordenar(listaOne);
    ordenar(listaTwo);
    cout<<endl<<"Primera lista ordenada: ";
    mostrar(listaOne);
    cout<<endl<<"Segunda lista ordenada: ";
    mostrar(listaTwo);

    unir(listaOne, listaTwo, listaOrdenada);
    cout<<endl<<"Tercera lista unida: ";
    mostrar(listaOrdenada);

    
    

    return 0;
}