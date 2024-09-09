#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

void random(vector<int>& array);
void ordenar(vector<int>& array);

int main()
{
    vector<int>array = {2,324,523,4,6,4,8,4,78,34,56,3};
    ordenar(array);

    for(int show : array){cout<<show<<endl;}

    return 0;
}

void random(vector<int>& array)
{
    srand(time(NULL));

}

void ordenar(vector<int>&array)
{
    sort(array.begin(),array.end());
}