#ifndef CAJA_H
#define CAJA_H
#include<juego.h>


class caja
{
    public:
        caja();
        caja(int fila);
        bool movercaja();
        void render();
        void calcuinvul();



        virtual ~caja();
        Sprite pSprite;
        int dano=0;
        bool muere=false;
        bool invul;
        int fila;

        Clock timecaja;


    protected:

    private:
};

#endif // CAJA_H
