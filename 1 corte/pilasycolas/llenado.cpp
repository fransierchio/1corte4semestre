#include <iostream>
#include <graphics.h>
#include <time.h>

using namespace std;

class Nodo
{
    public:
        int data;
        Nodo *next;
        Nodo(int data): data(data),next(nullptr){}
};

class Colas
{
    private:
        Nodo *head;
        Nodo *tail;
    public:
        Colas():head(nullptr),tail(nullptr){}
        void crearCola(int data)
        {
            Nodo *newNodo = new Nodo(data);
            if (head==nullptr)
            {
                head=newNodo;
                tail=newNodo;
            } else 
            {
                tail->next=newNodo;
                tail=newNodo;
            }
            
        }

          Nodo* obtenerCabeza() 
          {
            return head;
          }
            
        void mostrar()
        {
            Nodo *actual=head;
            while (actual!=nullptr)
            {
                cout<<actual->data<<"->"; 
                actual=actual->next;
            }
            cout<<endl;
        }

        void liberarCola()
        {
            if(head==nullptr){tail=nullptr; cout<<"Cola vacia"; return;}
            Nodo *temp=head;
            head=head->next;
            delete temp;
        }

};

class Sistema 
{
    private: 
    int windowWidth, windowHeight;
    bool simulando;


    public:
    Sistema(int windowWidth, int windowHeight):windowWidth(windowWidth), windowHeight(windowHeight){}
    
    void iniciarSistema() 
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, (char*)"");
        initwindow(windowWidth, windowHeight, "UGMA PAY", 100, 100);
    }

    void dibujarBoton(int x, int y, string texto) {
        setfillstyle(SOLID_FILL, WHITE);
        rectangle(x, y, x + 100, y + 50);
        floodfill(x + 1, y + 1, WHITE);
        settextstyle(8,0,3);
        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(x + 5, y + 15, (char*)texto.c_str());
    }

    bool verificarBoton(int x, int y, int mx, int my) {
        return (mx >= x && mx <= x + 100 && my >= y && my <= y + 50);
    }

void simularCola(Colas& cola) {
        int x = 50, y = 100;
        char strData[100];
        int nodosIndex=0;
        Nodo* actual = cola.obtenerCabeza();
        while (actual != nullptr) {
            
            
            setcolor(WHITE);
            rectangle(x, y, x + 145, y + 60); 

          
            setcolor(BLACK);
            settextstyle(8, 0, 1); 
            outtextxy(x + 15, y + 20, itoa(actual->data, strData, 10));

           
            setcolor(WHITE);
            rectangle(x, y, x + 60, y + 60); 

            char strDireccion[100];
            itoa((int)(actual->next), strDireccion, 16);
            setcolor(BLACK);
            outtextxy(x + 65, y + 40, strDireccion); 

            char strACTUAL[100];
            itoa((int)(actual), strDireccion, 16);
            setcolor(BLACK);
            outtextxy(x + 38, y + 80, strDireccion); 

            x += 180;
            nodosIndex++;
            if (nodosIndex == 8) {
            x = 50;  
            y += 180;  
            nodosIndex = 0;  
        }

            actual = actual->next;
            delay(50); 
        }
    }


void detectarClick(Colas& cola) {
    int x, y;
    bool simulando = false;
    bool detenido = false; 
    int nodes = 0;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (verificarBoton(750, 600, x, y) && !simulando) {
                simulando = true;
                detenido = false;  
                while (nodes < 24 && !detenido) {
                    int randomData = rand() % 100 + 1;
                    cola.crearCola(randomData);
                    simularCola(cola); 
                    delay(1000); 
                    nodes++;

                    if (kbhit()) {
                        char key = getch();
                        if (key == ' ') {
                            detenido = true;  
                        }
                    }
                }
                simulando = false; 
            }
            else if (verificarBoton(750, 650, x, y) && simulando) {
                detenido = true;
                simulando = false; 
            }
        }
        delay(50);
    }
}
};

int main()
{
    srand(time(0));
    Colas cola;
    Sistema sistema(1500,750);
    sistema.iniciarSistema();
    sistema.dibujarBoton(750,600,"Inicio");
    sistema.detectarClick(cola);

    getch();
    closegraph();
    return 0;
}