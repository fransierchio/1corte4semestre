#include <iostream>
#include <windows.h>
#include <conio.h>

using  namespace std;

class Cronometro
{  
    protected:
    int min;
    int hora;
    int seg;

    public:
    Cronometro():hora(0),min(0),seg(0) {}

    void setHora(int h){hora=h;}
    void setMin(int m){min=m;}
    void setSeg(int s){seg=s;}

    void limpiarBufferTeclado() {
        while (kbhit()) {
            getch();
        }
    }

    void Iniciar()
    {
        bool stop=false;
        while(!stop)
        {
            cout<<"Presiona Enter para detener"<<endl;
            cout<<hora<<" : "<<min<<" : "<<seg;


            if (seg<60)
            {
                seg++;
            }
            else if (seg==60)
            {
                min++;
                seg=0;
            } 
            else if(min==60)
            {
                hora++;
                min=0;
            }


            Sleep(1000);
            system("cls");

            stop=Parar();
            if(stop){stop=Reiniciar(seg,min,hora);}
        }


        cout<<hora<<" : "<<min<<" : "<<seg;
    }
    bool Parar()
   {
         if(kbhit())
        {
            char tecla=getch();
            if (tecla=='\r')
            {
                return true;
            }    else 
            {
                return false;
            }      
        }
        
    }
    bool Reiniciar(int &seg, int &min, int &hora){
        char reanudar;
        cout<<endl<<"Deseas Reiniciar el cronometro?(1=Si)";
        cin>>reanudar;
        if(reanudar=='1')
        {
            seg=0; min=0; hora=0;
            return false;
        } else 
        {
            return true;
        }
    }
 };

class Reloj : public Cronometro
{
    public:
    void Adelantar()
    {
 
        if(hora==24)
        {
            hora=0;
        } else 
        {
            hora=hora+1;
        }
    }
    void Atrasar()
    {
        if(hora==0)
        {
            hora=23;
        } else 
        {
            hora=hora-1;
        }
    }
    void Establecer(int h, int m, int s)
    {
        setHora(h); setMin(m), setSeg(s);
    }

    void Iniciar()
    {
        bool stop=false;
        while(!stop)
        {
            cout<<"Presione espacio para adelantar 1 hora o Enter para retrasar 1 Hora"<<endl;
            cout<<hora<<" : "<<min<<" : "<<seg;

            if (seg<60)
            {
                seg++;
            }
            else if (seg==60)
            {
                min++;
                seg=0;
            } 
            else if(min==60)
            {
                hora++;
                min=0;
            } else if(hora==24)
            {
                hora=0;seg=0;min=0;
            }
           
            Sleep(1000);
            system("cls");

            if(kbhit())
            {
            char tecla = getch();
            if(tecla=='\r')
            {
                Atrasar();
            } else if(tecla == ' ')
            {
                Adelantar();
            } else 
            {
                limpiarBufferTeclado();
            }

    
            }

        }
        cout<<hora<<" : "<<min<<" : "<<seg;
    }
};



int main()
{
    // Cronometro one;
    // one.Iniciar();

    Reloj reloj;
    reloj.Establecer(10,20,40);
    reloj.Iniciar();

    return 0;
}