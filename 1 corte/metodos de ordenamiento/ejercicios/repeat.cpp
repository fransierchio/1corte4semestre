#include <iostream>
#include <vector>

using namespace std;

int main () 
{
    vector<int> array;
    bool exitEntry=false, exitOut;
    int actualNum=0, bestNum=0,reps=0,repsMax=0;

    //ciclo de entrada
    while(!exitEntry)
    {
        cout<<"Ingresa un numero: ";
        cin>>actualNum;
        if(actualNum == 0)
        {
            array.push_back(actualNum);
            exitEntry=true;
        } else{array.push_back(actualNum);}
    }

    for (int i = 0; i < array.size(); i++)
    {
        reps=1;
        exitOut=false;
        int j=i+1;
        while (!exitOut) 
        { 
            if (array[i]==array[j])
            {
                reps++;
            } else 
            {
                exitOut=true;
            }
            j++;
        }
        if (reps>repsMax)
        {
            bestNum=array[i];
            repsMax=reps;
        }
        
    }
    cout<<endl<<"el numero que mas se repite es: " << bestNum <<" - " <<repsMax << "veces"<<endl;
    


    return 0;
}