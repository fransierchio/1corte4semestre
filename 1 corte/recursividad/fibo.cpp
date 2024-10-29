#include <iostream>

using namespace std;

int fibonacci(int *array, int n)
{
    if (array[n]!=-1)
    {
        return array[n];
    }
    
    if (n<=1)
    {
        return array[n]=n;
    } else 
    {
       return array[n]=(fibonacci(array, n-1) + fibonacci(array, n-2));
    }
    
}

int main()
{
    int n=0;
    cout<<"Ingresa un num: ";
    cin>>n;
    int *array= new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i]=-1;
    }
    

    for (int i = 0; i < n; i++)
    {
        fibonacci(array,i);
        cout<<array[i]<<" ";
    }
    
    
    return 0;
}