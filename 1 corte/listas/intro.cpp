#include <iostream>

using namespace std;


struct  Nodo
{
    int data;
    Nodo *next;
};

struct ListaEnlazada
{
    Nodo* cabeza;

    ListaEnlazada() {
        cabeza = nullptr;
    }
};


void create(int num, ListaEnlazada &lista)
{
    Nodo *nuevo = new Nodo;
    nuevo->data = num;
    nuevo->next = nullptr;


    if (lista.cabeza == nullptr)
    {
        lista.cabeza=nuevo;
        cout<<"Head: "<< lista.cabeza;
        cout<<endl<<"nodo: "<<nuevo<<endl;
    } else
    {
        Nodo *actual = lista.cabeza;
        cout<<endl<<"nodo: "<<nuevo<<endl;
        cout<<"Head: "<< lista.cabeza;
        cout<<endl<<"actual: "<<actual<<endl;
        while (actual->next!=nullptr)
        {
            actual = actual->next;
            cout<<"primero pasa o no";
        }
        actual->next = nuevo;
        cout<<endl<<"actual: "<<actual<<endl;
        cout<<endl<<"NEXT: "<<actual->next<<endl;
    }
    
}

void mostrar(ListaEnlazada &lista)
{
    Nodo *mostrar = lista.cabeza;
    cout<<"Datos: "<<endl<<mostrar->data<<endl;
    while (mostrar->next!=nullptr)
    {
        mostrar=mostrar->next;
        cout<<"Datos: "<<endl<<mostrar->data<<endl;
    }
    
}


int main()
{
    ListaEnlazada lista;
    int num=5;
    // cout<<"Ingresa un numero para crear una lista: ";
    // cin>>num;
    create(5, lista);
    create(10, lista);
    create(15, lista);
    create(20, lista);
    mostrar(lista);

    return 0;
}