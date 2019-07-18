#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<juego.h>


#define velocidad 300


using namespace sf;
using namespace std;



class player
{
    public:
        player();
        virtual ~player();
        void update();
        void render(float ticks);
        void moverjugador(float time);
        void moversprite();
        void calcularlinea();
        void hit();
        void invulnerable();



        Sprite pSprite;
        float x;
        float y;
        float xlast;
        float ylast;
        float vx;
        float vy;
        int estado;
        bool ataque=false;
        RectangleShape hitbox;
        int linea;
        int vida=10;
        bool muere=false;
        bool invul=false;

        Clock timesprite;
        Clock timeinvul;






    protected:

    private:
};

#endif // PLAYER_H
