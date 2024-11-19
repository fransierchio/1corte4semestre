#include <iostream>

using namespace std;

class Alumno
{
    private:
        string nombre;
        int notas[5];
    public:

    void crearAlumno()
    {
        cin.ignore();
        cin.clear();
        cout<<"ingresa el nombre: ";
        getline(cin,nombre);
        for (int i = 0; i < 5; i++)
        {
            cout<<"Ingresa la nota N-"<<i+1<<": ";
            cin>>notas[i];
            cout<<endl;
        }
        system("cls");
    }

    float promedio()
    {
        float promedio;
        for (int i = 0; i < 5; i++)
        {
           promedio+=notas[i];
        }
        return promedio=promedio/5;
    }

    string getName(){return nombre;}

};


int main()
{
    int count=0;
    cout<<"Cuantos alumnos deseas crear: ";
    cin>>count;

    Alumno alumno[count];
    for (int i = 0; i < count; i++)
    {
        alumno[i].crearAlumno();
    }

    int maxpromedio=0, indice=0;
    for (int i = 0; i < count; i++)
    {
        if (alumno[i].promedio()>maxpromedio)
        {
            indice=i;
        }
    }

    cout<<"El mejor alumno es: "<<alumno[indice].getName()<<" con un promedio de: "<<alumno[indice].promedio();


    return 0;
}