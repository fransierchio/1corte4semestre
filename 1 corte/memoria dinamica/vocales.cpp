#include <iostream>
using namespace std;
void vocalChar(char  *frasePointer);
void vocalString(string  *frasePointer);


int main()
{
    int size=100;
    cout<<"ingresa la frase: ";
    char *frasePointer = new char[size];
    cin.getline(frasePointer, size, '\n');

    vocalChar(frasePointer);

    delete[] frasePointer;
    frasePointer = nullptr;

    string *frasePointer2 = new string;
    cout<<"ingresa la frase: ";
    getline(cin, *frasePointer2);
    vocalString(frasePointer2);

    delete frasePointer2;
    frasePointer2 = nullptr;

    

    return 0;
}

void vocalChar(char *frasePointer)
{
    int a=0;
    while (*frasePointer)
    {
        cout<<*frasePointer;
        switch (*frasePointer)
        {
        case 'a':
        case 'A':
            a++;
            break;
        
        default:
            break;
        }
        *frasePointer++;
    }
    cout<<endl<<a<<endl;
}

void vocalString( string  *frasePointer)
{
    int a=0;
    for(char caracter : *frasePointer)
    {
        cout<<caracter<<endl;
        switch (caracter)
        {
        case 'a':
        case 'A':
            a++;
            break;
        
        default:
            break;
        }
    }
    cout<<endl<<a;
}