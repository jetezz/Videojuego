#include "player.h"


player::player()
{
    pSprite.setTexture(juego::getjuego()->Tjugador);
    pSprite.setTextureRect(sf::IntRect(1, 125, 32, 36));

    pSprite.setOrigin(pSprite.getGlobalBounds().width/2,pSprite.getGlobalBounds().height/2);

    x=50;
    y=150;
    xlast=50;
    ylast=150;
    pSprite.setPosition(10,10);

    hitbox.setSize(Vector2f(pSprite.getGlobalBounds().width,pSprite.getGlobalBounds().height));
    hitbox.setFillColor(Color(255,0,0,155));
    hitbox.setOrigin(pSprite.getOrigin());
    hitbox.setPosition(Vector2f(x,y));

}
void player:: update(){

 }

void player::moverjugador(float time){
    if (estado!=2){

        vx=0;
        vy=0;

        xlast=x;
        ylast=y;

        if(juego::getjuego()->a){
            vx=-velocidad;
        }
        if(juego::getjuego()->s){
            vy=velocidad;
        }
         if(juego::getjuego()->d){
            vx=velocidad;
        }
         if(juego::getjuego()->w){
            vy=-velocidad;
        }
        if(juego::getjuego()->click && estado!=2){
            estado=2;
            timesprite.restart();
        }

        x=x+time*vx;
        y=y+time*vy;

        if(x>120 || x-hitbox.getGlobalBounds().width/2<0){
            x=xlast;
        }
        if(y>650|| y<120){
            y=ylast;
        }

        hitbox.setPosition(x,y);
    }{


    }


    if(estado!=2 && estado!=3){
        if(vx!=0 || vy!=0 ){
            estado=1;
        }
        if(vx==0 && vy==0){

            estado=0;
        }
    }else{
    x=xlast;
    y=ylast;
     hitbox.setPosition(x,y);
    }





}

void player::moversprite(){



     switch (estado){

        case 0:
            if(timesprite.getElapsedTime().asMilliseconds()<200){
                    pSprite.setTextureRect(sf::IntRect(1,125,32,36));


            }else if(timesprite.getElapsedTime().asMilliseconds()<400){
                pSprite.setTextureRect(sf::IntRect(33,125,32,36));
            }
            else if(timesprite.getElapsedTime().asMilliseconds()<600){
                    pSprite.setTextureRect(sf::IntRect(65,125,32,36));

            }else if(timesprite.getElapsedTime().asMilliseconds()<800){
                pSprite.setTextureRect(sf::IntRect(33,125,32,36));
            }
            else{
            timesprite.restart();
            }
            break;


            case 1:

                if(timesprite.getElapsedTime().asMilliseconds()<200){
                        pSprite.setTextureRect(sf::IntRect(97,129 , 32,32));
                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<400){
                        pSprite.setTextureRect(sf::IntRect(128,133,40,28));
                 }
                 else if(timesprite.getElapsedTime().asMilliseconds()<600){
                        pSprite.setTextureRect(sf::IntRect(169,129,36,32));
                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<800){
                        pSprite.setTextureRect(sf::IntRect(205,133,31,28));
                 }

                  else{
                 timesprite.restart();
                 }
                 break;


            case 2:

                if(timesprite.getElapsedTime().asMilliseconds()<50){
                        pSprite.setTextureRect(sf::IntRect(74,177,35,36));

                 }
                 else if(timesprite.getElapsedTime().asMilliseconds()<100){
                          pSprite.setOrigin(pSprite.getOrigin().x,35);
                        pSprite.setTextureRect(sf::IntRect(109,161,40,52));
                 }

                 else if(timesprite.getElapsedTime().asMilliseconds()<150){
                         pSprite.setOrigin(hitbox.getOrigin());
                  pSprite.setOrigin(pSprite.getOrigin().x,25);
                        pSprite.setTextureRect(sf::IntRect(149,169,36,44));


                 }

                  else if(timesprite.getElapsedTime().asMilliseconds()<300){
                         pSprite.setOrigin(hitbox.getOrigin());
                        pSprite.setTextureRect(sf::IntRect(185,177,36,36));

                        if (ataque==false){
                         disparo bala1(1,juego::getjuego()->potencia,x,y);
                        juego::getjuego()->balas->push_back(bala1);
                        ataque=true;
                        }


                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<350){

                        pSprite.setTextureRect(sf::IntRect(1,213,37,35));


                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<400){

                        pSprite.setTextureRect(sf::IntRect(38,213,39,35));


                 }


                else{
                // pSprite.setTextureRect(sf::IntRect(4, 8, 41, 65));
                 pSprite.setOrigin(hitbox.getOrigin());
                 timesprite.restart();
                 estado=0;
                 ataque=false;

                 }
                 break;

            case 3:

                 if(timeinvul.getElapsedTime().asMilliseconds()<500){
                        pSprite.setTextureRect(sf::IntRect(38,177,37,36));

                 }
                 else{
                     estado=0;
                      timesprite.restart();

                 }
                 break;






        }


}
void player:: calcularlinea(){

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
void player :: hit(){



    for(int i=0; i<juego::getjuego()->balas->size() ; i++){
            if(muere==false){

                if(juego::getjuego()->balas->at(i).tipo==2){


                    if(juego::getjuego()->balas->at(i).linea==linea){

                        if(juego::getjuego()->balas->at(i).hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds())){
                            if(invul==false){


                                invul=true;
                                timeinvul.restart();
                                if(vida ==-9){

                                }else{
                                 vida=vida-juego::getjuego()->balas->at(i).dano;
                                }
                                estado=3;

                                if(vida<=0){
                                    if(vida==-9){
                                    muere=false;
                                    }else{
                                        juego::getjuego()->timegame.restart();
                                    muere=true;
                                    }

                                }
                            }
                        }
                    }
                }
            }
    }
}
void player::invulnerable(){
    if(invul){
        if(timeinvul.getElapsedTime().asMilliseconds()<500){
         pSprite.setColor(Color(255,0,0,255));
        } else{
        pSprite.setColor(Color(255,255,255,255));
        invul=false;
        }
    }

}
void player::render(float ticks){


    pSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
    juego::getjuego()->ventana->draw(pSprite);

    if(juego::getjuego()->f6){
        juego::getjuego()->ventana->draw(hitbox);
    }


}

player::~player()
{
    //dtor
}
