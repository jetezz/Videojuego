#include "disparo.h"

disparo::disparo()
{


}
disparo::disparo(int tipo2,float fuerza2, float x2, float y2){

    tipo=tipo2;
   fuerza=fuerza2;
   x=x2;
   y=y2;
   yinicio=y2;
   xinicio=x2;
   xlast=x;
   ylast=y;
   calcularlinea();

   pSprite.setTexture(juego::getjuego()->bala);


   pSprite.setPosition(x,y);
   if (tipo==1){
        dano=2;


    pSprite.setTextureRect(sf::IntRect(157,235,68,53));
    pSprite.setScale(0.5,0.5);

   }
   if (tipo==2){
        dano=1;


    pSprite.setTextureRect(sf::IntRect(43,143,118,84));
     pSprite.setScale(-0.3,0.3);
   }
   pSprite.setOrigin(pSprite.getGlobalBounds().width/2,pSprite.getGlobalBounds().height/2);



    hitbox.setSize(Vector2f(pSprite.getGlobalBounds().width,pSprite.getGlobalBounds().height));
    hitbox.setFillColor(Color(255,0,0,155));
    hitbox.setOrigin(pSprite.getOrigin());
    hitbox.setPosition(Vector2f(x,y));

}
void disparo:: moverdisparo(float time){

        seno=sin(45)*fuerza;
        coseno=cos(45)*fuerza;

        xlast=x;
        ylast=y;

        if(tipo==2){
                if(x<juego::getjuego()->jugador->x &&animacion==false){

                    estado=2;
                    timesprite.restart();
                    animacion=true;

                }


        }else{
          y=yinicio-parabolico.getElapsedTime().asSeconds()*coseno+(0,5*50*pow(parabolico.getElapsedTime().asSeconds(),2));



              if(y>yinicio && animacion==false){

                estado=2;
                timesprite.restart();
                animacion=true;
              }


        }








    if (tipo==1){
;


        x=xinicio+parabolico.getElapsedTime().asSeconds()*seno;





    }else{
        x=xinicio-parabolico.getElapsedTime().asSeconds()*200;


    }

    if(estado==2){
        x=xlast;
        y=ylast;
    }
      hitbox.setPosition(x,y);

}

void disparo:: calcularlinea(){

     if(y>125&&y<=200){
        linea=1;

    }else if(y>250 && y<=350){
        linea=2;

    }
    else if(y>350 && y<=450){
        linea=3;
    }
    else if(y>450 && y<=550){
        linea=4;
    }
    else if(y>550 && y<=650){
        linea=5;
    }


}
void disparo::hitcaja(){

    for(int i=0; i<juego::getjuego()->cajas->size(); i++){

          if(juego::getjuego()->cajas->at(i).pSprite.getGlobalBounds().intersects(hitbox.getGlobalBounds())){
                estado=2;
                if(juego::getjuego()->cajas->at(i).movercaja()){
                         juego::getjuego()->cajas->erase(juego::getjuego()->cajas->begin()+i);

                }

          }

}

}
void disparo::render(float ticks){

  pSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
    juego::getjuego()->ventana->draw(pSprite);

     if(juego::getjuego()->f6){
        juego::getjuego()->ventana->draw(hitbox);
    }
}
void disparo::moversprite(){
    if(estado==1){


        if(tipo==1){

                if(timesprite.getElapsedTime().asMilliseconds()<100){
                        pSprite.setTextureRect(sf::IntRect(155,235,68,53));


                }else if(timesprite.getElapsedTime().asMilliseconds()<200){
                    pSprite.setTextureRect(sf::IntRect(224,235,68,53));
                }
                else if(timesprite.getElapsedTime().asMilliseconds()<300){
                        pSprite.setTextureRect(sf::IntRect(291,235,68,53));

                }else if(timesprite.getElapsedTime().asMilliseconds()<400){
                    pSprite.setTextureRect(sf::IntRect(357,235,68,53));
                }
                else{
                timesprite.restart();
                }
        }
        if(tipo==2){

                if(timesprite.getElapsedTime().asMilliseconds()<100){
                        pSprite.setTextureRect(sf::IntRect(43,143,118,84));


                }else if(timesprite.getElapsedTime().asMilliseconds()<200){
                    pSprite.setTextureRect(sf::IntRect(168,143,136,84));
                }
                else if(timesprite.getElapsedTime().asMilliseconds()<300){
                        pSprite.setTextureRect(sf::IntRect(315,143,137,84));

                }else if(timesprite.getElapsedTime().asMilliseconds()<400){
                    pSprite.setTextureRect(sf::IntRect(454,143,141,84));
                }
                else{
                timesprite.restart();
                }

        }


    }else if(estado==2){

        if(tipo==1){

             if(timesprite.getElapsedTime().asMilliseconds()<100){
                        pSprite.setTextureRect(sf::IntRect(443,240,48,41));


                }else if(timesprite.getElapsedTime().asMilliseconds()<200){
                    pSprite.setTextureRect(sf::IntRect(491,240,48,41));
                }
                else if(timesprite.getElapsedTime().asMilliseconds()<300){
                        pSprite.setTextureRect(sf::IntRect(539,240,48,41));

                }else{
                muere=true;
                }



        }else{

            if(timesprite.getElapsedTime().asMilliseconds()<50){
                        pSprite.setTextureRect(sf::IntRect(10,406,50,105));


                }else if(timesprite.getElapsedTime().asMilliseconds()<100){
                    pSprite.setTextureRect(sf::IntRect(65,406,80,105));
                }
                else if(timesprite.getElapsedTime().asMilliseconds()<150){
                        pSprite.setTextureRect(sf::IntRect(150,406,88,105));

                }else if(timesprite.getElapsedTime().asMilliseconds()<200){
                    pSprite.setTextureRect(sf::IntRect(260,406,88,105));

                }else if(timesprite.getElapsedTime().asMilliseconds()<250){
                    pSprite.setTextureRect(sf::IntRect(380,406,100,105));

                }else if(timesprite.getElapsedTime().asMilliseconds()<300){
                    pSprite.setTextureRect(sf::IntRect(480,406,88,105));

                }else if(timesprite.getElapsedTime().asMilliseconds()<350){
                    pSprite.setTextureRect(sf::IntRect(532,406,88,105));
                }
                else{
                muere=true;
                }



        }
    }

}

disparo::~disparo()
{
    //dtor
}
