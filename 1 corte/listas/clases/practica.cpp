#include <iostream>
#include <time.h>
#include<string.h>

using namespace std;

class Persona 
{
    private:
        string nombre;
        int edad;
        string cedula;
        char sexo;
        float peso;
        float altura;
    public:
    const char defaulSex = 'h';
    Persona():nombre(""),edad(0),cedula("0"),sexo(defaulSex),peso(0), altura(0){}
    Persona(string nombre, int edad, char sexo):nombre(nombre), edad(edad), cedula("0"),
    sexo(sexo), peso(0), altura(0) {}
    Persona(string nombre, int edad, char sexo, float peso, float altura):nombre(nombre), edad(edad), cedula("0"),
    sexo(comprobarSexo(sexo)), peso(peso), altura(altura) {}
    int calcularIMC()
    {
        float IMC=0;
        IMC = peso/(altura*altura);
        if(IMC<20){return -1;} 
        else if(IMC>=20&&IMC<=25){return 0;} 
        else{return 1;}
    }
    bool esMayorDeEdad()
    {
        if(edad>=18){return true;} else {return false;}
    }
    char comprobarSexo(char sexo)
    {
        if (sexo=='h'||sexo=='H'||sexo=='m'||sexo=='M')
        {
            return sexo;
        } else {return 'H';}
        
    }
    void toString()
    {
        cout<<"Nombre: "<<nombre<<" Edad: "<<edad<<" Sexo: "<<sexo<<" Peso: "<<peso<<" Altura: "<<altura;
    }
    int generarCedula()
    {
        int num;
        num = rand() % 90000000 + 10000000;
        return num;
    }
};

class Grupo
{

};


int main()
{
    srand(time(NULL));
    int IMC;
    Persona one("Francesco", 20, 'H', 70, 1.75);
    one.calcularIMC();
    one.esMayorDeEdad();
    one.comprobarSexo('h');
    one.toString();
    IMC=one.generarCedula();
    cout<<endl<<IMC;
    return 0;
}