#include <iostream>

using namespace std;

const int NODOS_size=6;
const int ARISTAS_size=9; 


class Nodo 
{
    public:
    int indice;
    string name;

    Nodo ():indice(-1), name(""){} //defecto
    Nodo (int i, string name):indice(i), name(name){}
};

class Grafos 
{
    private:
    Nodo nodo[NODOS_size];
    int matrizAdyacente[NODOS_size][NODOS_size];
    int matrizIncidencia[NODOS_size][ARISTAS_size];
    int contNodos;
    int contAristas;

    public:

    Grafos()
    {
        contNodos=0;
        contAristas=0;

        for (int i = 0; i < NODOS_size; i++)
        {
            for (int j = 0; j < NODOS_size; j++)
            {
                matrizAdyacente[i][j]=0;
            }
            for (int j = 0; j < ARISTAS_size; j++)
            {
                matrizIncidencia[i][j]=0;
            }
        }
    }

    void crearNodo(string name)
    {
        if (contNodos<NODOS_size)
        {
            nodo[contNodos]=Nodo(contNodos,name);
            contNodos++;
        } else 
        {
            cout<<"Limite alcanzado";
        }
    }

    void mostrarNodos()
    {
        for (int i = 0; i < NODOS_size; i++)
        {
            cout<<"Nodo "<<nodo[i].indice<<": "<<nodo[i].name<<endl;
        }
    }

    void crearArista(int origen, int destino, int peso)
    {
        if (origen<contNodos && destino < contNodos)
        {
            //Adyacencia
            matrizAdyacente[origen][destino]=peso;
            
            //Incidencia (aristas)
            matrizIncidencia[origen][contAristas]=-peso;
            matrizIncidencia[destino][contAristas]=peso;
            contAristas++;
        } else 
        {
            cout<< "Indices invalidos";
        } 
    }

    void mostrarAdyacencia()
    {
        cout<<"Matriz de Adyacencia"<<endl;
        for (int i = 0; i < NODOS_size; i++)
        {
            for (int j = 0; j < NODOS_size; j++)
            {
                cout<<matrizAdyacente[i][j]<<" ";
            }
            cout<<endl; 
        }
    }

    void mostrarIncidencia()
    {
        cout<<"Matriz de Incidencia"<<endl;
        for (int i = 0; i < NODOS_size; i++)
        {
            for (int j = 0; j < ARISTAS_size; j++)
            {
                cout<<matrizIncidencia[i][j]<<"  ";
            }
            cout<<endl; 
        }
    }



};





int main()
{
    Grafos one;
    //NODOS
    one.crearNodo("A");//0
    one.crearNodo("B");//1
    one.crearNodo("C");//2
    one.crearNodo("D");//3
    one.crearNodo("E");//4
    one.crearNodo("F");//5

    //ARISTAS
    one.crearArista(0,1,2);//A->B
    one.crearArista(0,2,5);//A->C
    one.crearArista(1,4,2);//B->E
    one.crearArista(1,3,1);//B->D
    one.crearArista(2,4,3);//C->E
    one.crearArista(2,3,1);//C->D
    one.crearArista(3,5,10);//D->F
    one.crearArista(3,4,8);//D->E
    one.crearArista(4,5,9);//E->F

    one.mostrarNodos();
    cout<<endl;
    one.mostrarAdyacencia();
    cout<<endl;
    one.mostrarIncidencia();

    return 0;
}