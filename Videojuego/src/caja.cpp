#include "caja.h"

caja::caja()
{

}
caja::caja(int fila2){

    fila=fila2;

    if(fila==1){
        pSprite.setPosition(175,160);
    }else if(fila==2){
         pSprite.setPosition(175,300);
    }else if(fila==3){
         pSprite.setPosition(175,400);
    }else if(fila==4){
         pSprite.setPosition(175,500);
    }else if(fila==5){
         pSprite.setPosition(175,600);
    }else if(fila==6){
         pSprite.setPosition(175,700);
    }

    pSprite.setTexture(juego::getjuego()->tcaja);
    pSprite.setTextureRect(sf::IntRect(34, 12, 66, 64));
    pSprite.setOrigin(pSprite.getGlobalBounds().width/2,pSprite.getGlobalBounds().height/2);

    pSprite.setScale(0.5,0.5);
}
bool caja::movercaja(){

    if(invul==false){
            dano++;
            invul=true;

            timecaja.restart();

        if (dano==1){
             pSprite.setTextureRect(sf::IntRect(155,13,63,62));
        }else if(dano==2){
          pSprite.setTextureRect(sf::IntRect(274,13,63,62));
        }else if(dano==3){
          pSprite.setTextureRect(sf::IntRect(35,100,63,63));
        }else if(dano==4){
          pSprite.setTextureRect(sf::IntRect(155,100,63,63));
        }else if(dano==5){
          pSprite.setTextureRect(sf::IntRect(274,100,63,63));
        }else if(dano==6){
          pSprite.setTextureRect(sf::IntRect(35,189,63,63));
        }else if(dano==7){
          pSprite.setTextureRect(sf::IntRect(155,189,63,63));
        }else if(dano==8){
          pSprite.setTextureRect(sf::IntRect(274,189,63,63));
        }
    }
    if(dano>8){
        muere=true;
    }

    return muere;
}
void caja::calcuinvul(){
       if(timecaja.getElapsedTime().asMilliseconds()>200){
        invul=false;

       }

}

void caja::render(){
 juego::getjuego()->ventana->draw(pSprite);
}

caja::~caja()
{
    //dtor
}
