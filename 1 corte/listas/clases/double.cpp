#include <iostream>

using namespace std;

class Nodo 
{
    public:
        int data;
        Nodo *prev;
        Nodo *next;
        Nodo (int valor): data(valor), prev(nullptr), next(nullptr){}
};

class ListasDobles
{
    private: 
        Nodo *head;
        Nodo *tail;
    public:
        ListasDobles(): head(nullptr), tail(nullptr){}

        void crearNodo(int data)
        {
            Nodo *nuevo = new Nodo(data);
            if (head==nullptr)
            {
                head=nuevo;
                tail=nuevo;
            } else 
            {
                tail->next=nuevo;
                nuevo->prev=tail;
                tail=nuevo;
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

        void deleteNodo(int del)
        {
            bool found=false;
            if (head==nullptr)
            {
                cout<<"Lista Vacia";
            }

            while (head!=nullptr && head->data==del)
            {
                found=true;
                Nodo *temp = head;
                head = head->next;
                if (head!=nullptr)
                {
                    head->prev=nullptr;
                } else {tail=nullptr;}
                
                delete temp;
            }

            Nodo *actual=head;

            while (actual->next!=nullptr)
            {
                if (actual->next->data==del)
                {
                    found=true;
                    Nodo *temp = actual->next;
                    actual->next=temp->next;

                    if (temp->next!=nullptr)
                    {
                        temp->next->prev=temp->prev;
                    } else { tail=temp->prev;}

                    delete temp;
                } else {actual=actual->next;}
            }         
            if (!found)
            {
                cout<<"Nodo no encontrado...";
            }
            
        }

        void addFirst(int valor)
        {
            Nodo *nuevo= new Nodo(valor);
            if (head!=nullptr)
            {
                head->prev=nuevo;
            } else{tail=nuevo;}
                nuevo->next=head;
                head=nuevo;
            
        }

        void searchNodo(int find)
        {
            Nodo *actual = head;
            bool encontrado=false;
                while (actual!=nullptr && !encontrado)
                {
                    if (actual->data==find)
                    {
                         cout<<"Nodo: "<<find<<" encontrado"; encontrado=true;
                    }
                    actual=actual->next;
                }
                if (!encontrado)
                {
                    cout<<"Nodo: "<<find<<" no encontrado";
                }
                
        }

        int count()
        {
            int acum=0;
            Nodo *actual = head;
            while (actual!=nullptr)
                {
                    acum++;
                    actual=actual->next;
                }
            return acum;
        }

        void reverse()
        {
            Nodo *actual= tail;

            while (actual!=nullptr)
            {
                cout<<actual->data<<" -> ";
                actual=actual->prev;
            }
            
        }

        void insertIndex(int data, int pos)
        {
            Nodo *nuevo=new Nodo(data);
            //lista vacia
            if (head==nullptr)
            {
                head=nuevo;
                tail=nuevo;
                return;
            }

            //posicion es negativa o 1 se agrega al inicio
            if (pos<=1 && head!=nullptr)
            {
                nuevo->next=head;
                head->prev=nuevo;
                head=nuevo;
                return;
            }

            Nodo *actual = head;
            int acum=0;

            //caso para intermedios
            while (actual!=nullptr)
            {
                cout<<endl<<acum;
                acum++;
                if (acum==pos)
                {
                    nuevo->prev=actual->prev;
                    nuevo->next=actual;

                    actual->prev->next=nuevo;
                    actual->prev=nuevo;
                    return;
                }
                actual=actual->next;
            }

            //caso para el final
            if (actual==nullptr)
            {
                tail->next=nuevo;
                nuevo->prev=tail;
                tail=nuevo;
                return;
            }
            
        }

};

int main()
{
    ListasDobles one;
    ListasDobles two;
    // one.crearNodo(2);
    // one.crearNodo(3);
    // one.crearNodo(4);
    // one.crearNodo(5);
    // one.mostrarNodo();
    // one.deleteNodo(5);
    // one.addFirst(5);
    // one.mostrarNodo();

    
    two.addFirst(50);
    two.insertIndex(-1,-1);
    two.insertIndex(0,0);
    two.addFirst(50);
    two.insertIndex(100,2);
    cout<<endl;
    two.mostrarNodo();

    return 0;
}