#include <iostream>

using namespace std;

int maximo(int a, int b);
int minimo(int a, int b);

int main()
{
    int a=0,b=0, max=0, min=0;
    cout<<"escribe el primer numero: ";
    cin>>a;
    cout<<"escribe el segundo numero: ";
    cin>>b;
    max=maximo(a,b);
    cout<<"el MCD ES: "<<max;
    min=minimo(a,b);
    cout<<endl<<"el MCM ES: "<<min;
    return 0;
}

int maximo(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    return maximo(b, a%b);
}

int minimo(int a, int b)
{
    return (a*b)/maximo(a,b);
}