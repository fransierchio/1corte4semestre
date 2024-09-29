#include <iostream>
#include <time.h>

using namespace std;

void game(int *goalPointer, int tries);

int main()
{
    srand(time(NULL));
    int goal = (rand()%100)+1;
    int *goalPointer= &goal;
    int guess=0, tries=0;
    cout<<*goalPointer<<endl;
    game(goalPointer, tries);
    

    delete goalPointer;
    goalPointer=nullptr;

    return 0;
}

void game(int *goalPointer, int tries)
{

    int guess=0;
    cout<<"intenta adivinar el numero: ";
    cin>>guess;
    cin.ignore();
    cin.clear();

    if (guess>*goalPointer)
    {
        cout<<"El numero ingresado es mayor al buscado"<<endl;
        game(goalPointer, tries+1);
    } else if (guess<*goalPointer)
    {
        cout<<"El numero ingresado es menor al buscado"<<endl;
        game(goalPointer, tries+1);
    } else 
    {
        tries++;
        cout<<"Felicidades, has ganado el juego en un total de "<<tries<<" intentos"<<endl;
    }
    
    
}