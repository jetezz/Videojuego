#include <SFML/Graphics.hpp>
#include<juego.h>






#define UPDATE_TICK_TIME 1000/15

using namespace std;
using namespace sf;






void sacarenemigos();
void update(float elapsedTime);
void render(float percentick);
 vector <disparo> vectordisparos;
 vector <enemigo> vectorenemigos;
 vector <caja> vectorcaja;
 int cantidad=0;
 int contador=0;
 int masimo=5;
 float tiempo=5000;
 bool inicioronda=true;
 Mapa *mapa;


   Clock respaum;




int main()
{
    // Create the main window
    RenderWindow * ventana;
    ventana=new  RenderWindow(VideoMode(800, 800), "CANNON");
    juego::getjuego()->ventana=ventana;

    player *jugador;
    jugador=new player();
    juego::getjuego()->jugador=jugador;


    for (int i=1;i<6;i++){
     vectorcaja.push_back(caja(i));

   }

    mapa = new Mapa("resources/mapa2.tmx", "resources/mapa2.png");


    juego::getjuego()->balas=&vectordisparos;
    juego::getjuego()->enemigos=&vectorenemigos;
    juego::getjuego()->cajas=&vectorcaja;


















    Clock clock;
        Clock updateCLock;
        Time tiempo = clock.getElapsedTime();

        float timeElapsed;
        float tiempoRefresco;
        float percentick;



	// Start the game loop
    while (ventana->isOpen())
    {

         if(clock.getElapsedTime().asMilliseconds() - tiempo.asMilliseconds() > UPDATE_TICK_TIME){


            update(updateCLock.restart().asSeconds());
            tiempo = clock.getElapsedTime();


         }

             timeElapsed=updateCLock.getElapsedTime().asMilliseconds();
             tiempoRefresco = UPDATE_TICK_TIME;                                //Hay un bug que si utilizas el  UPDATE TIME directamente no hace la division bien
            percentick=min(1.f,timeElapsed/tiempoRefresco);

        render(percentick);

        // Process events
        sf::Event event;
        while (ventana->pollEvent(event))
        {
            // Close window : exit
          if (event.type == Event::Closed) {
            ventana->close();
            delete ventana;
            }
        }



    }

    return EXIT_SUCCESS;
}

void update(float elapsedTime){

    if(juego::getjuego()->jugador->muere==false){

        juego::getjuego()->imput();
        juego::getjuego()->jugador->moverjugador(elapsedTime);
        juego::getjuego()->jugador->moversprite();

         juego::getjuego()->calcularhud();

        sacarenemigos();
        juego::getjuego()->jugador->calcularlinea();

        for(int i=0; i<vectorenemigos.size(); i++){
            vectorenemigos[i].moversprite();
            vectorenemigos[i].moverenemigo(elapsedTime);
            vectorenemigos[i].hit();
            vectorenemigos[i].invulnerable();
            if( vectorenemigos[i].muere)  {
                     juego::getjuego()->puntuacion=juego::getjuego()->puntuacion+500;
                   juego::getjuego()->enemigos->erase(vectorenemigos.begin()+i);
            }
            if(vectorenemigos[i].x<0){

                 juego::getjuego()->enemigos->erase(vectorenemigos.begin()+i);
                    juego::getjuego()->contador--;
                 if (juego::getjuego()->contador==0){
                    juego::getjuego()->timegame.restart();
                    juego::getjuego()->jugador->muere=true;

                 }

            }
        }


        juego::getjuego()->jugador->hit();
        juego::getjuego()->jugador->invulnerable();



      for(int i=0; i<vectordisparos.size(); i++){
        vectordisparos[i].moversprite();
       vectordisparos[i].moverdisparo(elapsedTime);
         vectordisparos[i].hitcaja();
       if(vectordisparos[i].muere){
     vectordisparos.erase(vectordisparos.begin()+i);
       }
         for(int i=0; i<vectorcaja.size(); i++){
                vectorcaja[i].calcuinvul();

         }

    }
}else{
if(juego::getjuego()->timegame.getElapsedTime().asSeconds()>3){




   vectordisparos.clear();
    vectorenemigos.clear();
    vectorcaja.clear();



    cantidad=0;
    contador=0;
    masimo=5;
    tiempo=5000;

    inicioronda=true;
    respaum.restart();
    juego::getjuego()->timeronda.restart();
      for (int i=1;i<6;i++){
     vectorcaja.push_back(caja(i));

   }
   juego::getjuego()->jugador->vida=10;
   juego::getjuego()->contbomba=3;
   juego::getjuego()->contador=3;
   juego::getjuego()->numronda=1;
   juego::getjuego()->puntuacion=0;

   juego::getjuego()->jugador->muere=false;


}


}










}
void render(float percentick){

      juego::getjuego()->ventana->clear();


    if(juego::getjuego()->jugador->muere==false){




           mapa->atcivarlayer(0);
           mapa->dibujarmapa();





        juego::getjuego()->jugador->render(percentick);



        for(int i=0; i<vectordisparos.size(); i++){
       vectordisparos[i].render(percentick);
    }

       for(int i=0; i<vectorenemigos.size(); i++){

        vectorenemigos[i].render(percentick);
    }
     for(int i=0; i<vectorcaja.size(); i++){

        vectorcaja[i].render();
    }


         juego::getjuego()->renderhud(percentick);


       } else{

           juego::getjuego()->ventana->draw(juego::getjuego()->game);
           juego::getjuego()->ventana->draw(juego::getjuego()->puntu);


        }

         juego::getjuego()->ventana->display();


}


void sacarenemigos(){




    if (inicioronda==true){



        if(respaum.getElapsedTime().asMilliseconds()>tiempo && cantidad<=masimo ){

            int ran=rand()%5 +1;
            respaum.restart();
            cantidad++;
            if (tiempo>500){
                tiempo=tiempo-500;
            }

            if(ran>2){
                 ran=1 ;
            }else{
                ran=2;
            }

            enemigo enemigo1(ran);
            juego::getjuego()->enemigos->push_back(enemigo1);


        }else if(cantidad==masimo){
            inicioronda=false;


        }

    }else if(inicioronda==false && juego::getjuego()->enemigos->size()==0){

        cantidad=0;
        masimo++;
        respaum.restart();
        juego::getjuego()->timeronda.restart();
        juego::getjuego()->numronda++;
        inicioronda=true;




    }



}
