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
    if(Head==nullptr) return;

    bool intercambiado;
    do
    {
       Nodo *actual=Head;
       intercambiado=false;
       while (actual->next!=nullptr)
       {
            if (actual->valor > actual->next->valor)
            {
                swap(actual->valor, actual->next->valor);
                intercambiado=true;
            }
        
            actual=actual->next;
       }
    } while (intercambiado);
}

void unir(Nodo *listOne, Nodo *listTwo, Nodo *&listaOrdenada)
{
       Nodo *first=listOne;
       Nodo *two=listTwo;

       while (first->next!=nullptr && two->next!=nullptr)
       {
            if (first->valor > two->valor)
            {
                crearNodo(listaOrdenada, two->valor);
                two=two->next;
            } else
            {
                crearNodo(listaOrdenada, first->valor);
                first=first->next;
            }   
       }

        while (first!=nullptr)
        {
            crearNodo(listaOrdenada, first->valor);
            first=first->next;
        }

        while (two!=nullptr)
        {
            crearNodo(listaOrdenada, two->valor);
            two=two->next;
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