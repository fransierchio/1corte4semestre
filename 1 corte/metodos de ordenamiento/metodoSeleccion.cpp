#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> array={3,4,2,1,5,1};
    int tam=array.size();
    int i,j,min;

    for (i=0; i<tam;i++)
    {
        min=i;
        for (j=i+1; j<tam; j++)
        {
            if(array[min]>array[j])
            {
                min=j;
            }
        }
        swap(array[i],array[min]);
    }

    for (int cont : array) {cout<<cont<<endl;}

}
