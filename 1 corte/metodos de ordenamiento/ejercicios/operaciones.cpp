#include <iostream>
#include <vector>

using namespace std;
void write(vector<int>&array);
void read(vector<int>&array);
void operaciones(vector<int>&array);

int main()
{
    int size=0;
    cout<<"Ingresa el tamano del vector: ";
    cin>>size;
    vector<int> array(size);
    
    write(array);
    read(array);
    operaciones(array);

    return 0;
}

void write(vector<int>&array)
{
    //1.1
    for (int i = 0; i < array.size(); i++)
    {
        cout<<"Valor N-"<<i<<": ";
        cin>>array[i];
    }
}

void read(vector<int>&array)
{
    //1.1
    cout<<"valores del array"<<endl;
    for(float show : array)
    {
        cout<<show<<endl;
    }
}

void operaciones(vector<int>&array)
{
    //1.2 1.3 1.4
    float total=0;
    int par=0,impar=0;
    for (int i = 0; i < array.size(); i++)
    {
        total+=array[i];
        array[i]%2==0 ? par++ : impar++;
    }
    float media=total/array.size();
    cout<<"la suma de los vectores es de: "<<total<<endl;
    cout<<"la media de los vectores es de: "<<media<<endl;
    cout<<"Hay "<<par<<" numeros pares y "<<impar<<" numeros impares"<<endl;

    //1.5
    int mayor=0,menor=0;
    for (int i = 0; i < array.size(); i++)
    {
        array[i] > media ? mayor++ : menor++;
        if (i%2==0 && i!=0) {
        cout<<"Nuevo valor N-"<<i<<": ";
        cin>>array[i];
        }

    }
    cout<<"Hay "<<mayor<<" numeros mayores a la media y "<<menor<<" numeros menores a la media"<<endl;
    cout<<"-Array Transformado-"<<endl;
    read(array);

}

