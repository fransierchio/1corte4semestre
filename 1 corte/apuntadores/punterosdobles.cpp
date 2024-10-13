#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
    int filas = 30, columnas = 10;
    int** array;

    // Asignar memoria para las filas
    array = new int*[filas];
    
    // Asignar memoria para cada columna
    for (int i = 0; i < filas; i++) {
        array[i] = new int[columnas];
    }

    // Imprimir direcciones de memoria en formato tabulado
    cout << "Direcciones de memoria del array:\n";
    for (int i = 0; i < filas; i++) {
        cout<<"jefe: "<<&array[i]<<endl;
        for (int j = 0; j < columnas; j++) {
            cout << &array[i][j] << "\t"; // Imprimir dirección de cada elemento
        }
        cout << endl; // Nueva línea al final de cada fila
    }

    // for (int i = 0; i < filas; i++) {
    //     for (int j = 0; j < columnas; j++) {
    //         int x=(rand()%6)+1;
    //         int y=(rand()%6)+1;
    //         array[i][j]=x+y;
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout << endl; // Nueva línea al final de cada fila
    // }
    

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}