#ifndef DISPARO_H
#define DISPARO_H

#include<SFML/Graphics.hpp>
#include<juego.h>


using namespace sf;
using namespace std;

class disparo
{
    public:
        disparo();
        disparo(int tipo, float fuerza,float x, float y);
        void render(float ticks);
        void moversprite();
        void moverdisparo(float time);
        void calcularlinea();
        void hitcaja();


        int tipo;
        int estado=1;
        float fuerza;
        float x;
        float y;
        float xlast;
        float ylast;
        float yinicio;
        float xinicio;
        virtual ~disparo();
        float seno;
        float coseno;
        bool muere=false;
        bool animacion=false;
        int dano;
        int linea;
        Sprite pSprite;
        RectangleShape hitbox;
        Clock timesprite;
        Clock parabolico;
        Clock horizontal;

    protected:

    private:
};

#endif // DISPARO_H
