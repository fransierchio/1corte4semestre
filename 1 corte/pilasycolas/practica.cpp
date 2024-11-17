#include <iostream>
#include <string>

using namespace std;

class Nodo
{
    public:
        string data;
        Nodo *next;
        Nodo *prev;
        Nodo(string data): data(data),next(nullptr){}
};

class ListasDobles
{
    private:
        Nodo *head;
        Nodo *tail;
    public:
        ListasDobles():head(nullptr),tail(nullptr){}
        void crearLista(string data)
        {
            Nodo *newNodo = new Nodo(data);
            if (head==nullptr)
            {
                head=newNodo;
                tail=newNodo;
            } else 
            {
                tail->next=newNodo;
                newNodo->prev=tail;
                tail=newNodo;
            }
        }

        void mostrar()
        {
            Nodo *actual= head;
            while(actual!=nullptr)
            {
                cout<<actual->data<<"<-";
                actual=actual->next;

            }
        }

        void borrar(string deleted)
        {
            if(head==nullptr)
            {
                cout<<"Lista vacia";
            }
            
            if (deleted==head->data)
            {
                head=head->next;
                head->prev=nullptr;
                return;
            } 
            else if(deleted==tail->data)
            {
                tail=tail->prev;
                tail->next=nullptr;
                return;
            }
            else 
            {
                Nodo *actual=head;
                while (actual!=nullptr)
                {
                    if (actual->next->data==deleted)
                    {
                        Nodo *temp=actual->next;
                        actual->next=temp->next;
                        temp->next->prev=actual;
                        return;
                    }
                }

            } 
            cout<<"No se encontro el dato";  
        }

};

class Pilas
{
    private:
        Nodo *head;
        Nodo *top;
    public:
        Pilas():head(nullptr){}

        void crearPila(string data)
        {
            Nodo *newNodo = new Nodo(data);
            if(head==nullptr)
            {
                head=newNodo;
                top=newNodo;
            } else
            {
                newNodo->next=top;
                top=newNodo;
            }
        }
        void mostrarPila()
        {
            Nodo *actual=top;
            while (actual!=nullptr)
            {
                cout<<actual->data<<endl;
                actual=actual->next;
            }
                
        }


        void liberar()
        {
            if(head==nullptr){cout<<"Pila vacia"; return;}
            Nodo *temp = top;
            top=top->next;
            delete temp;

        }
};

class Colas
{
    private:
        Nodo *head;
        Nodo *tail;
        Pilas pila;
    public:
        Colas():head(nullptr),tail(nullptr){}
        void crearCola(string data)
        {
            Nodo *newNodo = new Nodo(data);
            if (head==nullptr)
            {
                head=newNodo;
                tail=newNodo;
            } else 
            {
                tail->next=newNodo;
                tail=newNodo;
            }
            
        }

        void mostrar()
        {
            Nodo *actual=head;
            while (actual!=nullptr)
            {
                cout<<actual->data<<"->"; 
                actual=actual->next;
            }
            cout<<endl;
        }

        void liberarCola()
        {
            if(head==nullptr){tail=nullptr; cout<<"Cola vacia"; return;}
            Nodo *temp=head;
            head=head->next;
            delete temp;
        }

        Pilas transformar()
        {
            Nodo *actual=head;
            const char *array;
            while (actual!=nullptr)
            {
                array = actual->data.c_str();
                for (int i = 0; i < actual->data.size(); i++)
                {
                    if (array[i]=='a'||array[i]=='e'||array[i]=='i'||array[i]=='o'||array[i]=='u')
                    {
                        string dato(1,array[i]);
                        pila.crearPila(dato);
                    }  
                }
                
                actual=actual->next;
            }
            return pila;
        }
};

int main()
{
    Colas one;
    Pilas pila;

    one.crearCola("Francesco");
    one.crearCola("Sierchio");
   
    
    one.mostrar();
    pila=one.transformar();
    pila.mostrarPila();
    


    return 0;
}