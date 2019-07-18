#include "enemigo.h"

enemigo::enemigo()
{
}
enemigo::enemigo(int tipo2){
    tipo =tipo2;



    posicion=(rand() %500) +1;

    if(posicion>=1&&posicion<=100){
        posicion=155;
        linea=1;

    }else if(posicion>100 && posicion<=200){
        posicion=300;
        linea=2;
    }
    else if(posicion>200 && posicion<=300){
        posicion=400;
        linea=3;
    }
    else if(posicion>300 && posicion<=400){
        posicion=500;
        linea=4;
    }
    else if(posicion>400){
        posicion=600;
        linea=5;
    }


    x=800;
    y=posicion;
    xlast=800;
    ylast=posicion;








   pSprite.setPosition(x,y);
   if (tipo==1){
    pSprite.setTexture(juego::getjuego()->enemigo1);


    pSprite.setTextureRect(sf::IntRect(1,1,34,40));

   }
   if (tipo==2){

    pSprite.setTexture(juego::getjuego()->enemigo2);


    pSprite.setTextureRect(sf::IntRect(77,48,74,40));
   }
   pSprite.setOrigin(pSprite.getGlobalBounds().width/2,pSprite.getGlobalBounds().height/2);



  // pSprite.setScale(0.5,0.5);




    hitbox.setSize(Vector2f(pSprite.getGlobalBounds().width,pSprite.getGlobalBounds().height));
    hitbox.setFillColor(Color(255,0,0,155));
    hitbox.setOrigin(pSprite.getOrigin());
    hitbox.setPosition(Vector2f(x,y));
}
void enemigo::moverenemigo(float time){
         int  ran=(rand() %100) +1;

    if(estado==1){




        if(ran<3 && ataque==false){

            estado=2;
        }
    }

    if (estado==1){
        xlast=x;
        ylast=y;
        x=x-30*time;



        hitbox.setPosition(x,y);

        if(tipo==2){

                if(subir==true || bajar==true){

                    if (subir==true){
                        contador++;
                        y=y-25;

                    }
                    if(bajar==true){
                        contador++;
                        y=y+25;
                    }

                    if(contador==4){
                        bajar=false;
                        subir=false;
                        contador=0;
                    }
                }

                if(subir==false && bajar==false){
                       if(linea==juego::getjuego()->jugador->linea){
                            if(linea==2){

                                linea=3;
                                bajar=true;
                            }else if(linea==1){

                            }else if(linea==5){

                                linea=4;
                                subir=true;
                            }else{
                            ran=(rand() %2) +1;

                                if(ran==1){
                                    linea++;

                                    bajar=true;
                                }else if(ran==2){
                                    linea--;

                                    subir=true;
                                }
                            }


                        }
            }


        }
    if(x<220){
        for (int i=0;i<juego::getjuego()->cajas->size();i++){
            if(linea==juego::getjuego()->cajas->at(i).fila){
                x=xlast;
                estado=2;
            }

        }
    }

    }else{

        xlast=x;
        hitbox.setPosition(x,y);

    }




}
void enemigo::moversprite(){




if(tipo==1){
     switch (estado){



            case 1:

                if(timesprite.getElapsedTime().asMilliseconds()<200){
                        pSprite.setTextureRect(sf::IntRect(1,1,34,40));
                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<400){
                        pSprite.setTextureRect(sf::IntRect(35,1,35,40));
                 }else{
                 timesprite.restart();
                 }
                 break;


            case 2:

                if(timesprite.getElapsedTime().asMilliseconds()<200){
                        pSprite.setTextureRect(sf::IntRect(195,89,53,64));
                             pSprite.setOrigin(pSprite.getOrigin().x,40);

                 }
                 else if(timesprite.getElapsedTime().asMilliseconds()<400){
                        ;
                        pSprite.setTextureRect(sf::IntRect(149,89,46,64));
                 }

                 else if(timesprite.getElapsedTime().asMilliseconds()<600){
                         pSprite.setOrigin(hitbox.getOrigin());
                        pSprite.setOrigin(40,40);
                        pSprite.setTextureRect(sf::IntRect(89,89,60,64));


                 }

                  else if(timesprite.getElapsedTime().asMilliseconds()<800){
                        // pSprite.setOrigin(hitbox.getOrigin());
                        pSprite.setTextureRect(sf::IntRect(25,89,64,64));

                       if (ataque==false){
                        disparo bala1(2,x-juego::getjuego()->jugador->x,x,y-20);
                       juego::getjuego()->balas->push_back(bala1);
                       ataque=true;
                        }


                  }

                else{

                 pSprite.setOrigin(hitbox.getOrigin());
                  pSprite.setTextureRect(sf::IntRect(1,1,34,40));
                 timesprite.restart();
                 estado=1;
                 ataque=false;

                 }
                      break;

            case 3:

                 if(timeinvul.getElapsedTime().asMilliseconds()<500){
                        pSprite.setTextureRect(sf::IntRect(134,45,50,44));

                 }
                 else{
                timesprite.restart();
                 estado=1;

                    if(vida<=0){
                        muere=true;
                    }
                 }
                 break;



            }




        }else if(tipo==2){

            switch (estado){



            case 1:

                if(timesprite.getElapsedTime().asMilliseconds()<200){
                        pSprite.setTextureRect(sf::IntRect(77,48,74,40));
                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<400){
                        pSprite.setTextureRect(sf::IntRect(77,88,78,48));
                 }
                   else if(timesprite.getElapsedTime().asMilliseconds()<600){
                        pSprite.setTextureRect(sf::IntRect(77,136,75,48));
                 }else{
                 timesprite.restart();
                 }
                 break;


            case 2:

                if(timesprite.getElapsedTime().asMilliseconds()<200){
                        pSprite.setTextureRect(sf::IntRect(160,236,76,52));

                 }
                 else if(timesprite.getElapsedTime().asMilliseconds()<400){
                      //    pSprite.setOrigin(pSprite.getOrigin().x,35);
                        pSprite.setTextureRect(sf::IntRect(157,288,79,56));
                 }

                 else if(timesprite.getElapsedTime().asMilliseconds()<600){
                      //   pSprite.setOrigin(hitbox.getOrigin());
               //   pSprite.setOrigin(pSprite.getOrigin().x,25);
                        pSprite.setTextureRect(sf::IntRect(73,184,84,40));


                 }

                  else if(timesprite.getElapsedTime().asMilliseconds()<800){
                         pSprite.setOrigin(hitbox.getOrigin());
                        pSprite.setTextureRect(sf::IntRect(71,224,86,40));


                        if (ataque==false){


                        disparo bala1(2,x-juego::getjuego()->jugador->x,x,y);
                        juego::getjuego()->balas->push_back(bala1);
                        ataque=true;

                        }



                  }
                   else if(timesprite.getElapsedTime().asMilliseconds()<1000){
                      //   pSprite.setOrigin(hitbox.getOrigin());
               //   pSprite.setOrigin(pSprite.getOrigin().x,25);
                        pSprite.setTextureRect(sf::IntRect(69,264,88,40));


                 }
                  else if(timesprite.getElapsedTime().asMilliseconds()<1200){
                      //   pSprite.setOrigin(hitbox.getOrigin());
               //   pSprite.setOrigin(pSprite.getOrigin().x,25);
                        pSprite.setTextureRect(sf::IntRect(81,304,68,44));


                 }

                else{
                // pSprite.setTextureRect(sf::IntRect(4, 8, 41, 65));
                 pSprite.setOrigin(hitbox.getOrigin());
                 timesprite.restart();
                 estado=1;
                ataque=false;

                 }
                 break;

            case 3:

                 if(timeinvul.getElapsedTime().asMilliseconds()<500){
                        pSprite.setTextureRect(sf::IntRect(9,40,60,52));

                 }
                 else{
                timesprite.restart();
                 estado=1;
                if(vida<=0){
                    muere=true;
                }
                 }
                 break;

            }



        }
}

void enemigo :: hit(){



    for(int i=0; i<juego::getjuego()->balas->size() ; i++){
            if(muere==false){

                if(juego::getjuego()->balas->at(i).tipo==1){

                    if(tipo==2){

                                if(juego::getjuego()->balas->at(i).hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds())){
                                  if(invul==false){

                                        invul=true;
                                        timeinvul.restart();
                                        vida=vida-juego::getjuego()->balas->at(i).dano;
                                        estado=3;
                                        juego::getjuego()->puntuacion=juego::getjuego()->puntuacion+100;


                                  }
                                }

                    }else{


                            if(juego::getjuego()->jugador->linea==linea){

                                if(juego::getjuego()->balas->at(i).hitbox.getGlobalBounds().intersects(hitbox.getGlobalBounds())){
                                  if(invul==false){

                                        invul=true;
                                        timeinvul.restart();
                                        vida=vida-juego::getjuego()->balas->at(i).dano;
                                        estado=3;
                                        juego::getjuego()->puntuacion=juego::getjuego()->puntuacion+100;

                                  }
                                }
                    }
                }
            }
        }
    }
}
void enemigo::invulnerable(){
    if(invul){
        if(timeinvul.getElapsedTime().asMilliseconds()<500){
         pSprite.setColor(Color(255,0,0,255));
        } else{
        pSprite.setColor(Color(255,255,255,255));
        invul=false;
        }
    }

}
void enemigo::bomba(){

    invul=true;
    timeinvul.restart();
    vida=0;
    estado=3;
    juego::getjuego()->puntuacion=juego::getjuego()->puntuacion+100;

}

void enemigo :: render(float ticks){
 pSprite.setPosition(xlast*(1-ticks) + x*ticks,ylast*(1-ticks)+y*ticks);
    juego::getjuego()->ventana->draw(pSprite);
     if(juego::getjuego()->f6){
        juego::getjuego()->ventana->draw(hitbox);
    }
}
enemigo::~enemigo()
{
    //dtor
}
