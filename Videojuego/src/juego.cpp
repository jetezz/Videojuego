#include "juego.h"



juego::juego()
{

    if(!Tjugador.loadFromFile("resources/personaje.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

    if(!bala.loadFromFile("resources/disparo.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

    if(!enemigo1.loadFromFile("resources/enemigo.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }

    if(!enemigo2.loadFromFile("resources/enemigo2.png")){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }


    if(!font.loadFromFile("resources/fuente/Marker Felt.ttf")){
        std::cerr <<"Error al cargar la fuente";
        exit(0);
    }

      if(!tcaja.loadFromFile("resources/caja.png")){
        std::cerr <<"Error al cargar la fuente";
        exit(0);
    }

       if(!tcorazon.loadFromFile("resources/corazon.png")){
        std::cerr <<"Error al cargar la fuente";
        exit(0);
    }
        if(!tbomba.loadFromFile("resources/bomba.png")){
        std::cerr <<"Error al cargar la fuente";
        exit(0);
    }


     corazon.setTexture(tcorazon);
    corazon.setScale(0.1,0.1);

     bomba.setTexture(tbomba);

    bomba.setScale(0.4,0.4);

   // corazon.setTextureRect(sf::IntRect(1, 125, 32, 36));

    puntu.setFont(font);
    puntu.setPosition(700,50);
    puntu.setColor((sf::Color::White));
    puntu.setCharacterSize(30);

    ronda.setFont(font);
    ronda.setPosition(300,300);
    ronda.setColor((sf::Color::White));
    ronda.setCharacterSize(50);

    game.setFont(font);
    game.setPosition(300,300);
    game.setColor((sf::Color::White));
    game.setCharacterSize(50);

      stringstream ss;
        ss <<"Game Over";


    game.setString(ss.str());





    cuapotencia.setFillColor(Color(255,0,0,155));
    cuapotencia.setPosition(Vector2f(50,760));


    cuapotencia2.setFillColor(Color(0,0,0,155));
    cuapotencia2.setPosition(Vector2f(50,760));
    cuapotencia2.setOutlineColor(Color(0,0,0,255));
    cuapotencia2.setOutlineThickness(3);
    cuapotencia2.setSize(Vector2f(700,20));

    cuavida.setFillColor(Color(255,0,0,155));
    cuavida.setOutlineColor(Color(0,0,0,255));
    cuavida.setOutlineThickness(1);

    pasillo1.setFillColor(Color(255,0,0,50));
    pasillo1.setPosition(0,125);
    pasillo1.setSize(Vector2f(800,75));


    pasillo2.setFillColor(Color(255,255,0,50));
    pasillo2.setPosition(0,250);
    pasillo2.setSize(Vector2f(800,100));


    pasillo3.setFillColor(Color(255,0,255,50));
    pasillo3.setPosition(0,350);
    pasillo3.setSize(Vector2f(800,100));


    pasillo4.setFillColor(Color(0,255,0,50));
    pasillo4.setPosition(0,450);
    pasillo4.setSize(Vector2f(800,100));


    pasillo5.setFillColor(Color(0,255,255,50));
    pasillo5.setPosition(0,550);
    pasillo5.setSize(Vector2f(800,100));













}

void juego::imput(){

    a=false;
    s=false;
    d=false;
    w=false;
    potencialast=potencia;

    click=false;

    //if (Keyboard::isKeyPressed(Keyboard::A))
      //      {
        //           a=true;
        //    }
          //  if (Keyboard::isKeyPressed(Keyboard::D))
            //{
              //   d=true;
         //   }
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                w=true;
            }
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                s=true;
            }
              if (Keyboard::isKeyPressed(Keyboard::B))
            {
                if(contbomba>0 && timebomba.getElapsedTime().asMilliseconds()>5000){
                contbomba--;
                timebomba.restart();

                for(int i=0;i<enemigos->size();i++){

               enemigos->at(i).bomba();
                }








            }


            }
             if (Keyboard::isKeyPressed(Keyboard::G))
            {
                if(f6){
                f6=false;
                }else{
                f6=true;
                }
                jugador->vida=-9;
                contbomba=3;
            }


           if (Keyboard::isKeyPressed(Keyboard::Space)) {

                click=true;
            }


            if (Keyboard::isKeyPressed(Keyboard::D))
            {

                if(potencia+50<=700)
                potencia=potencia+50;

            }

             if (Keyboard::isKeyPressed(Keyboard::A))
            {
                if(potencia-50>0)
                potencia=potencia-50;
            }

               if (Keyboard::isKeyPressed(Keyboard::Q))
            {
               ventana->close();
            }









}

void juego::calcularhud(){




    cuavida.setPosition(Vector2f(juego::getjuego()->jugador->x-20,juego::getjuego()->jugador->y-30));

      stringstream ss;
        ss <<puntuacion;

        stringstream ron;
        ron<<"Ronda "<<numronda;

    puntu.setString(ss.str());
    ronda.setString(ron.str());



}

void juego::renderhud(float ticks){

    cuapotencia.setSize(Vector2f(potencialast*(1-ticks) + potencia*ticks,20));
     cuavida.setSize(Vector2f(juego::getjuego()->jugador->vida*5,5));
     ventana->draw(cuapotencia2);
    ventana->draw(cuapotencia);
    ventana->draw(cuavida);
    ventana->draw(puntu);

    for (int i=0;i<contador;i++){
        corazon.setPosition(50*i,25);

         ventana->draw(corazon);


    }
      for (int i=0;i<contbomba;i++){
        bomba.setPosition(300+i*50,20);

         ventana->draw(bomba);


    }





 if(timeronda.getElapsedTime().asMilliseconds()<5000){
        ventana->draw(ronda);
 }






if(f6){
ventana->draw(pasillo1);
ventana->draw(pasillo2);
ventana->draw(pasillo3);
ventana->draw(pasillo4);
ventana->draw(pasillo5);


}

}









juego * juego::_instancia=NULL;

juego * juego::getjuego(){

    if(_instancia==NULL){
        _instancia = new juego();
    }
    return _instancia;
}




juego::~juego()
{
    //dtor
}
