#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <juego.h>
#include <cstdlib>


class enemigo
{
    public:
        enemigo();
        enemigo(int tipo);
        virtual ~enemigo();
        void render(float ticks);
        void moversprite();
        void moverenemigo(float time);
        void hit();
        void invulnerable();
        void bomba();





        int tipo;
        int posicion;
        int estado=1;
        bool ataque=false;
        Sprite pSprite;
        RectangleShape hitbox;
        Clock timesprite;
        float x;
        float y;
        float xlast;
        float ylast;
        int linea;
        int vida=4;
        bool muere=false;
        bool invul=false;
        bool bajar=false;
        bool subir=false;
        int contador=0;

        Clock timeinvul;



    protected:

    private:
};

#endif // ENEMIGO_H
