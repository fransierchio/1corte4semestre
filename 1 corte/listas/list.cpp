#include <iostream>

using namespace std;

struct Nodo
{
    int data;
    Nodo *next;
};

struct List
{
    Nodo *head;

    List()
    {
        head=nullptr;
    }
};

void crear(List &list, int data);
void mostrar(List &list);
void insertarFirst(List &list, int data);
bool encontrar(List &list, int encontrar);
void deleteNode(List &list, int borrar);

int main()
{
    List list;
    int num=88;
    bool encontrado=0, borrado=0;
    crear(list, 10);
    crear(list, 10);
    crear(list, 10);
    crear(list, 10);
    crear(list, 10);

    cout << "Lista inicial: ";
    mostrar(list);
    cout << endl;

    insertarFirst(list, 10);
    cout << "Lista después de insertar al principio: ";
    mostrar(list);
    cout << endl;

    encontrado=encontrar(list, num);

    deleteNode(list, 10);  

    encontrado ? cout<<num<<" Si esta en la lista" : cout<<num<<" no esta en la lista";
    cout<<endl<<"Lista despues del borrado: ";
    mostrar(list);
    
    return 0;
}

void crear(List &list, int data)
{
    Nodo *Nuevo = new Nodo;
    Nuevo->data=data;
    Nuevo->next=nullptr;

    if (list.head==nullptr)
    {
        list.head=Nuevo;
    } 
    else
    {
        Nodo *actual = list.head;
        while (actual->next!=nullptr)
        {
            actual=actual->next;
        }
        actual->next=Nuevo;
    }
    
}

void mostrar(List &list)
{
    Nodo *actual=list.head;

    if (actual==nullptr)
    {
        cout<<"La lista esta vacia";
    }
    
    while (actual!=nullptr)
    {
        cout<<actual->data<<" ";
        actual=actual->next;
    }
    cout<<endl;
    
}

void insertarFirst(List &list, int data)
{
    Nodo *nuevo= new Nodo;
    nuevo->next=list.head;
    nuevo->data=data;
    list.head=nuevo;
}

bool encontrar(List &list, int encontrar)
{
    Nodo *actual=list.head;
    while (actual!=nullptr && actual->data!=encontrar)
    {
        actual=actual->next;
    }
    if (actual==nullptr)
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
    
}

void deleteNode(List &list, int borrar)
{
    Nodo *actual = list.head;
    if (actual==nullptr)
    {
        cout<<"La lista esta vacia";
        return;
    }
    
    while (actual!=nullptr && actual->data==borrar)
    {
        Nodo *temp = actual;
        list.head=actual->next;
        actual=actual->next;
        delete temp;
    }

    while (actual!=nullptr && actual->next!=nullptr)
    {
        if (actual->next->data==borrar)
        {
            Nodo *temp= actual->next;
            actual->next=actual->next->next;
            delete temp;
            
        } else { actual=actual->next; }
       
    } 
    
}