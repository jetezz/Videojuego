#ifndef JUEGO_H
#define JUEGO_H


#include <iostream>

#include<disparo.h>
#include <SFML/Graphics.hpp>
#include <player.h>
#include <enemigo.h>
#include <math.h>
#include <caja.h>
#include <sstream>
#include <Mapa.h>




using namespace std;
using namespace sf;

class caja;
class player;
class disparo;
class enemigo;



class juego
{
    public:
        juego();
        virtual ~juego();
        static juego* getjuego(); //Singleton
        void imput();
        void calcularhud();
        void renderhud(float time);


        RenderWindow * ventana;
        Texture Tjugador;
        Texture bala;
        Texture enemigo1;
        Texture enemigo2;
        Texture tcaja;
        Texture tcorazon;
        Texture tbomba;
        Sprite corazon;
        Sprite bomba;
        player * jugador;
        bool a=false;
        bool s=false;
        bool d=false;
        bool w=false;
        bool f6=false;
        bool b=false;
        bool click=false;
        float potencia=300;
        float potencialast=300;
        RectangleShape cuapotencia;
        RectangleShape cuapotencia2;
        RectangleShape cuavida;
        RectangleShape pasillo1;
        RectangleShape pasillo2;
        RectangleShape pasillo3;
        RectangleShape pasillo4;
        RectangleShape pasillo5;

        float puntuacion=0;
        int numronda=1;
        int contador=3;
        int contbomba=3;

        Clock timeronda;
        Clock timebomba;
        Clock timegame;




        Text puntu;
        Text ronda;
        Text game;


        Font font;

        vector <disparo>* balas;
        vector <enemigo>* enemigos;
        vector <caja>* cajas;









    protected:

    private:
         static juego* _instancia;
};

#endif // JUEGO_H
