#include <iostream>

using namespace std;

int fibonacci(int *array,int i)
{
    if (array[i]!=-1)
    {
        return array[i];
    }

    if (i==0){return array[i]=0;}
    if (i==1){return array[i]=1;}
     
    return array[i]=fibonacci(array,i-1)+fibonacci(array,i-2);
    
}

int main()
{
    int n=0, resultado=0;
    cout<<"Ingrese un numero para calcular la secuancia fibonacci: ";
     cin>>n;
    
    int *array=new int[n+1];
    for (int i = 0; i <= n+1; i++)
    {
        array[i]=-1;
    }
     
    for (int i = 0; i < n; i++)
    {
        resultado=fibonacci(array,i);
        cout<<resultado<<" ";
    }
    delete[] array;

    return 0;
}