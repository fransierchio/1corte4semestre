#include <iostream>
#include <vector>
#include <algorithm>
/*Crear un programa en C++ que gestione un sistema de estudiantes, permitiendo agregar, mostrar y eliminar estudiantes. Cada estudiante tendrá un nombre, un ID, una calificación y un curso. Además, implementar funciones adicionales como calcular la calificación promedio, generar una tabla de calificaciones y comparar las calificaciones entre dos estudiantes. También incluir las siguientes funciones:

ModificarCalificacion(int id, float nuevaCalificacion): Permitir al usuario modificar la calificación de un estudiante dado su ID.
listarEstudiantesPorCurso(std::string curso): Mostrar todos los estudiantes que están inscritos en un curso específico.
contarEstudiantes(): Devolver el número total de estudiantes registrados en el sistema.
 */

using namespace std;

class Estudiante 
{
    private:
    string nombre;
    string ID;
    float calificacion;
    string curso;

    public:
    Estudiante(string nombre, string ID, float calificacion, string curso): nombre(nombre), ID(ID), calificacion(calificacion),
    curso(curso){}

    void mostrarDatos()
    {
        cout<<"Nombre: "<<nombre<<" | ID: "<<ID<<" | Curso: "<<curso<<" | Nota: "<<calificacion;
    }
    string getid(){return ID;}
    float getCalificacion(){return calificacion;}
    string getNombre(){return nombre;}
};

class Sistema
{
    private:
    vector<Estudiante> estudiantes;
    
    public:

    //destructor
    // ~Sistema()
    // {
    //     for (auto registro : estudiantes)
    //     {
    //         delete registro;
    //     }
    // }

    void agregarEstudiante ()
    {
        string nombre;
        string ID;
        float calificacion;
        string curso;
        cout<<"Ingresa el Nombre: ";
        cin>>nombre;
        cout<<endl<<"Ingresa el ID: ";
        cin>>ID;
        cout<<endl<<"Ingresa el curso: ";
        cin>>curso;
        cout<<endl<<"Ingresa la calificacion: ";
        cin>>calificacion;
        Estudiante *nuevoEstudiante = new Estudiante(nombre,ID,calificacion,curso);
        estudiantes.push_back(*nuevoEstudiante);
        system("cls");
    }

    void mostrarEstudiante()
    {
        if(estudiantes.empty()){cout<< " Lista Vacia... ";} 

        for(auto registro: estudiantes)
        {
            registro.mostrarDatos();
            cout<<endl;
        }
        
    }

    void eliminarEstudiante()
    {
        string del;
        bool encontrado=false;
        cout<<"Ingresa el ID del estudiante a eliminar: ";
        cin>>del;

        for (int i = 0; i < estudiantes.size(); i++)
        {
            if (estudiantes[i].getid()==del)
            {
                estudiantes.erase(estudiantes.begin()+i);
                cout<<"estudiante eliminado";
                encontrado=true;
                return;
            }  
        }
        if(!encontrado){cout<<"No se encontraron alumnos";}
        
    }

    void promedio()
    {
        float promedio;
        for (int i = 0; i < estudiantes.size(); i++)
        {
            promedio=promedio+estudiantes[i].getCalificacion();
        }
        cout<<"El promedio de la nota de todos los alumnos fue de: "<<promedio/estudiantes.size();
        
    }

    void comparar()
    {
        string one, two;
        Estudiante *first = nullptr;
        Estudiante *second = nullptr;
        cout<<"Ingresa el ID del primer estudiante";
        cin>>one;
        cout<<"Ingresa el ID del segundo estudiante";
        cin>>two;
        for (int i = 0; i < estudiantes.size(); i++)
        {
            if (one==estudiantes[i].getid())
            {
                first=&estudiantes[i];
            }
            if (two==estudiantes[i].getid())
            {
                second=&estudiantes[i];
            }
        }
        if (first->getCalificacion()>second->getCalificacion())
        {
            cout<<first->getNombre()<<" tiene mayor nota";
        } else if (first->getCalificacion()<second->getCalificacion())
        {
            cout<<second->getNombre()<<" tiene mayor nota";
        } else {cout<<"Tienen la misma nota";}
        
    }


    bool comp(Estudiante& a, Estudiante& b)
    {
        return (a.getCalificacion() > b.getCalificacion());
    }

    void tabla()
    {
        sort(estudiantes.begin(), estudiantes.end(), comp);

    }

};



int main()
{
    Sistema activo;
    activo.agregarEstudiante();
    activo.agregarEstudiante();

    cout<<endl<<"Lista de Estudiantes"<<endl;
    activo.mostrarEstudiante();

    activo.promedio();
    activo.comparar();
    return 0;
}