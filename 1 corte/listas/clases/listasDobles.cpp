#include <iostream>

using namespace std;

class Nodo 
{
    public:
    int data;
    Nodo *next;
    Nodo *previous;

    Nodo(int valor) : data(valor), next(nullptr), previous(nullptr) {}
};

class Lista 
{
    private:
        Nodo *head;
    public:
        Lista () : head(nullptr) {}

        void crearNodo(int valor)
        {
            Nodo* nuevo = new Nodo(valor);
            if (head==nullptr)
            {
                head=nuevo;
            } else 
            {
                Nodo *actual = head;
                while (actual->next!=nullptr)
                {
                    actual=actual->next;
                }
                actual->next=nuevo;
                nuevo->previous=actual;
            }
                 
        }

        void mostrarNodo()
        {
            Nodo *actual = head;
            while (actual!=nullptr)
            {
                cout<<actual->data<<" -> ";
                actual=actual->next;
            }
        }

        void deleteNodo(int valor)
        {
            bool encontrado=false;
            if (head==nullptr)
            {
                cout<<"La lista esta Vacia";
            }

            while (head!=nullptr && head->data==valor)
            {
                Nodo *temp=head;
                head=head->next;
                if (head!=nullptr)
                {
                    head->previous=nullptr;
                }
                
                encontrado=true;
                delete temp;
            }

            Nodo *actual = head;
            while (actual!=nullptr && actual->next!=nullptr )
            {
                if (actual->next->data==valor)
                {
                    encontrado=true;
                    Nodo *temp=actual->next;
                    actual->next=temp->next;

                    if (temp->next!=nullptr)
                    {
                        temp->next->previous=temp->previous;    
                    }
                    delete temp;
                } else {actual=actual->next;}
            }
            if (!encontrado)
            {
                cout<<endl<<"ERROR AL BORRAR!----Ese numero no se encuentra en la lista----";
            }
        }

        void addFirst(int valor)
        {
            Nodo *nuevo= new Nodo(valor);
            head->previous=nuevo;
            nuevo->next=head;
            head=nuevo;
        }
};


int main()
{
    Lista one;
    one.crearNodo(3);
    one.crearNodo(2);
    one.crearNodo(1);
    one.deleteNodo(3);
    one.addFirst(6);
    one.mostrarNodo();
    cout<<endl;
    return 0;
}