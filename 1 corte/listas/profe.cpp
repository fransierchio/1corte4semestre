#include<iostream>
using namespace std;

struct nodo //estructura de los nodos de la lista
{
  int dato;
  nodo *next;
};


nodo *cabeza=NULL; //cabeza o inicio de la lista


void crear_nodo(int valor) 
{
    nodo *nuevo=new nodo();
    nuevo->dato=valor;
    nuevo->next =NULL;
    if(cabeza==NULL)
        cabeza=nuevo;
    else{
       nodo *ultimo=cabeza;
       while(ultimo->next !=NULL){
           ultimo=ultimo->next;
       }
       ultimo->next =nuevo;
   }
}
void insertar_nodo(nodo *cabeza,int valor){
    nodo *aux=new nodo();
    aux->dato=valor;
    aux->next=cabeza;
    cabeza=aux;
}

bool buscar_elemento(nodo *&cabeza, int valor){
    nodo *aux =new nodo();
    bool encontrado;
    aux=cabeza;
    while((aux!=NULL)&&(aux->dato !=valor))
   
         aux=aux->next;
    if(aux==NULL)
       encontrado=false;
    else
        encontrado=true;
    return encontrado;
}

void mostrar_lista(nodo *&cabeza){ //muestra la lista ingresada
    nodo *aux = new nodo();
    aux=cabeza;
    
    while(aux!=NULL){
        cout<<aux->dato<<"->";
        aux=aux->next;
    }
}

void borrar_nodo(nodo *&cabeza, int borrar)
{

    nodo *actual=cabeza;
    while (actual!=nullptr && actual->dato==borrar)
    {
        nodo *temp;
        temp=actual;
        cabeza=actual->next;
        actual=actual->next;
        delete temp;
    }
    
    while (actual!=NULL && actual->next!=NULL)
    {
        if (actual->next->dato==borrar)
        {
            nodo *temp=actual->next;
            actual->next=actual->next->next;
            delete temp;
        } else {actual=actual->next;}
    }
    
    if (cabeza==NULL)
    {
        cout<<"La lista esta vacia";
        return;
    }
    
}
int main()
{
    int x,buscar=0, borrar=0;
    cout<<"ingrese valores para finalizar ingrese 0"<<endl;
    do{
        cin>>x;
        if (x!=0)
        {
            crear_nodo(x);
            
        }
   }while(x!=0);


   mostrar_lista(cabeza);
   cout<<endl<<"Cual elemento quiere buscar: ?"<<endl;
   cin>>buscar;
   if(buscar_elemento(cabeza,buscar)==true)
      cout<<"el elemento esta en la lista"<<endl;
    else
      cout<<"el elemento no esta en la lista"<<endl;

    cout<<"Cual valor deseas eliminar: ";
    cin>>borrar;
    borrar_nodo(cabeza, borrar);
    mostrar_lista(cabeza);
    return 0;
}