#include <iostream>
#include <time.h>

using namespace std;

void generar(float (&sueldoBase)[15], int (&nivel)[15]);
void descuentos(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15]);
void bonos(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15]);
void total(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15]);


int main()
{
    srand(time(NULL));
    float sueldoBase[15], sueldoFinal[15];
    int nivel[15];

    generar(sueldoBase, nivel);
    descuentos(sueldoBase, sueldoFinal, nivel);
    bonos(sueldoBase, sueldoFinal, nivel);
    total(sueldoBase, sueldoFinal, nivel);


    return 0;
}


void generar(float (&sueldoBase)[15], int (&nivel)[15])
{   
    cout<<" El sueldo base de trabajadores "<<endl << "-----------------"<<endl;
    for (int i = 0; i < 15; i++)
    {
        sueldoBase[i]=(rand()%250)+56;
        nivel[i]=rand()%4;
        cout<<"Empleado "<<i+1<<" Nivel "<<nivel[i]<<" Sueldo: "<<sueldoBase[i]<<"$ "<<endl;
    }
    

}

void descuentos(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15])
{
    float impuestoOne=0, impuestoTwo=0, seguro=00;
    cout<<endl<<"Deducciones de impuestos"<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        impuestoOne=0.031, impuestoTwo=0.093, seguro=0.114;
        impuestoOne=sueldoBase[i]*impuestoOne;
        impuestoTwo=sueldoBase[i]*impuestoTwo;
        sueldoFinal[i]=sueldoBase[i];

        if (nivel[i]==2||nivel[i]==3)
        {
            seguro=sueldoBase[i]*seguro;
            sueldoFinal[i]=sueldoFinal[i]-seguro-impuestoOne-impuestoTwo;
            cout<<"Empleado "<<i+1<<" -"<<impuestoOne<<"$  -"<<impuestoTwo<<"$ -"<<seguro<<"$ "<<" total: "<<sueldoFinal[i]<<"$ "<<endl;
        } else
        {
            sueldoFinal[i]=sueldoFinal[i]-impuestoOne-impuestoTwo;
            cout<<"Empleado "<<i+1<<" -"<<impuestoOne<<"$  -"<<impuestoTwo<<"$ "<<" total: "<<sueldoFinal[i]<<"$ "<<endl;
        }
    }
    
}

void bonos(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15])
{
    cout<<endl<<"Bonificaciones por nivel"<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        float bono=0;
        if (nivel[i]==0)
        {
           sueldoFinal[i]+7.45;
        } 
        else if (nivel[i]==1)
        {
            bono=0.083;
            bono=bono*sueldoBase[i];
            sueldoFinal[i]=sueldoFinal[i]+bono;
        } 
        else if (nivel[i]==2)
        {
            bono=0.123;
            bono=bono*sueldoBase[i];
            sueldoFinal[i]=sueldoFinal[i]+bono;
        } 
        else 
        {
            bono=0.2025;
            bono=bono*sueldoBase[i];
            sueldoFinal[i]=sueldoFinal[i]+bono;
        }
        cout<<"Empleado "<<i+1<<" Nivel "<<nivel[i]<<" +"<<bono<<"$ "<<" total: "<<sueldoFinal[i]<<"$ "<<endl;
    }
    

}

void total(float (&sueldoBase)[15], float (&sueldoFinal)[15], int (&nivel)[15])
{
    cout<<endl<<"Sueldo Final"<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout<<"Empleado "<<i+1<<" Nivel "<<nivel[i]<<" SB:"<<sueldoBase[i]<<"$ "<<" SF: "<<sueldoFinal[i]<<"$ "<<endl;
    }
    
}

