// un instituto desea tomar las temperatura diarias de un mes para calcular el dia mas caluroso y el mas frio. ademas indicar cual es el promedio de la temperatura
#include <iostream>
#include <time.h>

using namespace std;

void generar(int (&array)[4][7]);
void algoritmo(int (&array)[4][7]);
void ordenarSemana (int array[4][7]);
void mostrar(int array[4][7]);
void ordenarMes (int array[4][7]);
void mostrarlineal(int array[28]);

int main ()
{
    srand(time(NULL));
    int array[4][7];
    generar(array);
    algoritmo(array);
    ordenarSemana(array);
    ordenarMes (array);
    

    return 0;
}

void generar(int (&array)[4][7])
{
    for (int i = 0; i < 4; i++)
    {
        cout<<"Semana "<<i+1<<": ";
        for (int j = 0; j < 7; j++)
        {
            array[i][j]=(rand()%20)+16;
            cout<<array[i][j]<< " ";
        }
        cout<<endl;
    }
    
    
}

void algoritmo(int (&array)[4][7])
{
    int calor=array[0][0],frio=array[0][0], diaFrio=0,diaCalor=0,semanaFrio=0, semanaCalor=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (array[i][j]<frio)
            {
                frio=array[i][j];
                diaFrio=j+1;
                semanaFrio=i+1;
            }
            if (array[i][j]>calor)
            {
                calor=array[i][j];
                diaCalor=j+1;
                semanaCalor=i+1;
            }
            
        }
        
    }
    cout<<"el dia con mas frio del mes fue el "<<diaFrio<<" de la semana "<<semanaFrio<<" con "<<frio<<" grados celsius"<<endl;
    cout<<"el dia con mas calor del mes fue el "<<diaCalor<<" de la semana "<<semanaCalor<<" con "<<calor<<" grados celsius"<<endl;
}

void ordenarSemana (int array[4][7])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7-1; j++)
        {
            for (int k = 0; k < 7-1-j; k++)
            {
                if (array[i][k]<array[i][k+1])
                {
                    swap(array[i][k], array[i][k+1]);
                }
                
            }
            
        }
    }
    
    mostrar(array);
}

void ordenarMes (int array[4][7])
{
    int linealArray[28], index=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            linealArray[index++]=array[i][j];
        }
    }


    for (int i = 0; i < 28-1; i++)
    {
        for (int j = 0; j < 28-1-i; j++)
        {
            if (linealArray[j]<linealArray[j+1])
            {
                swap(linealArray[j],linealArray[j+1]);
            }
            
        }
    }

    mostrarlineal(linealArray);
}

void mostrar(int array[4][7])
{
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<"Semana "<<i+1<<": ";
        for (int j = 0; j < 7; j++)
        {
            cout<<array[i][j]<< " ";
        }
        cout<<endl;
    }
}

void mostrarlineal(int array[28])
{
    cout<<endl;
    for (int i = 0; i < 28; i++)
    {
        cout<<array[i]<<" ";
    }
}