#ifndef MAPA_H
#define MAPA_H
#include <tinyxml2.h>
#include<juego.h>

#include "SFML/Graphics.hpp"



using namespace tinyxml2;

class Mapa{
    public:
        Mapa(char *archivo, string urlTiles);
        void        dibujarmapa();
        void        atcivarlayer(int layer);
    private:
        int         _width=0;
        int         _height=0;
        int         _tileWidth=0;
        int         _tileHeight=0;
        int         _tilesetWidth;
        int         _tilesetHeight;
        int         _imageWidth;
        int         _imageHeight;
        int         _numLayers=0;
        int         filas;
        int         columnas;
        int         posicion=0;
        int         gid;
        int         _activeLayer;
        string      ficheroimg;

        XMLDocument doc;
        XMLElement  *imageTileset;
        XMLElement  *imagen;
        XMLElement  *layers;


        Sprite  _tilesetSprite;
        Texture _tilesetTexture;
        Sprite  ****_tileMapSprite;

};
#endif //MAPA_H
