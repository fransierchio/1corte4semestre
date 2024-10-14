#include <iostream>
#include <iomanip> //usado para setw (ancho fijo) de la tabla
#include <conio.h> // Para _getch(), para pausar hasta que se toque una tecla
#include <time.h> //para el random

using namespace std;
void interfaz(int **lanza, int filas, int columnas);
void generar_simulacion(int **lanza, int filas, int columnas);
void mostrar_simulacion(int **lanza, int filas, int columnas);
void premios(int **lanza, int filas, int columnas, int &ganancia);
void frecuencia(int **lanza, int filas, int columnas, int *FR, int sizeFrec);
void ordenar(int *FR, int sizeFrec, int *indiceFR);
void pausaBorrar();


int main()
{
    srand(time(NULL));
    int filas=30,columnas=10;
    int **lanza; //puntero doble para crear array bidimensional
    lanza = new int*[filas]; //creando memoria dinamico para las 30 filas
    for (int i = 0; i < filas; i++) //creando espacio para las 10 columnas en cada fila
    {
        lanza[i]=new int[columnas];
    }
    lanza[0][0]=13; //usado para verificar si se generó la simulacion;
    interfaz(lanza,filas, columnas); //ABRIR MENU;

    //liberando memorias

    for (int i = 0; i < filas; i++) //liberando memoria de las columnas
    {
        delete[] lanza[i];
    }

    delete[] lanza; //liberando memoria filas

    return 0;
}

void interfaz(int **lanza, int filas, int columnas)
{
    bool exit=false;
    int ganancia=0;
    int sizeFrec=11;
    int FR[sizeFrec];
    do
    {
       
        char opc;
        cout << "Bienvenido a la simulacion" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Generar simulacion" << endl;
        cout << "2. Mostrar resultados" << endl;
        cout << "3. Mostrar ganancias" << endl;
        cout << "4. Tabla de frecuencia" << endl;
        cout << "Escribe el numero de la opcion que desees elegir: ";
        cin>>opc;
        cin.clear();
        cin.ignore();
        //menu de opciones
        switch (opc)
        {
        case '0':
            cout<<"Gracias por usas nuestros servicios...";
            exit=true;
            break;
        case '1':
            generar_simulacion(lanza, filas, columnas);
            pausaBorrar();
            break;
        case '2':
            mostrar_simulacion(lanza,filas, columnas);
            pausaBorrar();
            break;
        case '3': 
            
            premios(lanza,filas-1, columnas-1, ganancia);
            pausaBorrar();
            ganancia=0;
            break;

        case '4': 
            
            frecuencia(lanza,filas, columnas, FR, sizeFrec);
            pausaBorrar();
            break;
        
        default:
            cout<<"Opcion Invalida, vuelve a intentar"<<endl; 
            pausaBorrar();
            break;
        }
    } while (exit==false);
    
}

void generar_simulacion(int **lanza, int filas, int columnas)
{
    cout<<"GENERANDO APUESTAS..."<<endl;
    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            int x = rand() % 6 + 1; 
            int y = rand() % 6 + 1;  
            lanza[i][j] = x + y; //se guarda la suma de los dos numeros random
        }
    }
}

void mostrar_simulacion(int **lanza, int filas, int columnas)
{
    if (lanza[0][0]>12)
    {
        cout<<"Recuerda generar la simulacion antes..."<<endl;
        return;
    }
    
    // Imprimir encabezados de la tabla
    cout << "Intento  |"; // Encabezado
    for (int j = 1; j <= columnas; j++) {
        cout <<setw(3) << j << "  |"; // Encabezados de intentos
    }
    cout << endl;

    // Imprimir línea de separación
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < filas; i++) 
    {
        // Mostrar el día con un ancho fijo
        cout << "Dia " << setw(2) << (i + 1) << "   |"; // Usar setw para alinear

        for (int j = 0; j < columnas; j++) 
        { 
            cout << setw(3) << lanza[i][j] << "  |"; // Alinear resultados con setw
        }
        cout << endl; // Nueva línea después de cada fila
    }
}

void premios(int **lanza, int filas, int columnas, int &ganancia)
{
     if (lanza[0][0]>12)
    {
        cout<<"Recuerda generar la simulacion antes..."<<endl;
        return;
    }

    if (filas<0)
    {
        cout<<"En esta simulacion se tuvo un balance total de: "<<ganancia<<endl;
        return;
    }
    if (columnas<0)
    {
        premios(lanza, filas - 1, 9, ganancia); // Reinicia a la última columna y baja una fila
        return;
    }
    if (lanza[filas][columnas]==10||lanza[filas][columnas]==11||lanza[filas][columnas]==12) //convertir en positivo en 10,11 y 12
    {
        int aux=50*((7-lanza[filas][columnas])-2);
        aux=-aux;
        ganancia+=aux;
    } else 
    {
        ganancia+=50*((7-lanza[filas][columnas])-2); // 2,3,4 positivo, 6,7,8,9 negativo;
    }
    
    
    cout<<"k: "<< lanza[filas][columnas]<< " Premio: "<< ganancia<<endl;

    premios(lanza,filas,columnas-1,ganancia);
    
}

void frecuencia(int **lanza, int filas, int columnas, int *FR, int sizeFrec)
{
    if (lanza[0][0]>12)
    {
        cout<<"Recuerda generar la simulacion antes..."<<endl;
        return;
    }

    for (int i = 0; i < sizeFrec; i++) //inicializar en cero las frecuencias
    {
        FR[i]=0;
    }
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int resultado=lanza[i][j]; //se guarda el resultado (K)
            FR[resultado-2]++; //FR TIENE 11 espacios, le restamos 2, pues los arrays
            //comienzan en 0 y  le subimos al correspondiente su frecuencia
        }
    }
        
    // Imprimir tabla de frecuencias
    cout << "Resultado | Frecuencia" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < sizeFrec; i++) {
        cout << setw(9) << (i + 2) << " | " << setw(10) << FR[i] << endl;
    }

    int indiceFR[sizeFrec]; //creamos un indice para no perder su frecuencia respectiva.
    cout<<endl;
    ordenar(FR,sizeFrec,indiceFR);

    // Imprimir tabla de frecuencias ORDENADO DE MENOR A MAYOR
    cout << "Resultado | Frecuencia" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < sizeFrec; i++) {
        cout << setw(9) << indiceFR[i] << " | " << setw(10) << FR[i] << endl;
    }
   
}

void ordenar(int *FR, int sizeFrec, int *indiceFR)
{

    //ordenar de menor a mayor
    //primero se guarda los indices de cada frecuencia (a que valor se refiere)

    for (int i = 0; i < sizeFrec; i++)
    {
        indiceFR[i]=i+2; //guarda los indices del 2 al 12
    }
    
    for (int i = 0; i < sizeFrec - 1; i++) {
        for (int j = i + 1; j < sizeFrec; j++) {
            if (FR[i] > FR[j]) {
                // Intercambiar frecuencias
                swap(FR[i], FR[j]);
                // Intercambiar los indices correspondientes
                swap(indiceFR[i], indiceFR[j]);
            }
        }
    }
}

void pausaBorrar()
{
    cout << "Presiona cualquier tecla para continuar..." << endl;
    _getch(); // Espera a que se presione una tecla
    system("cls");
}