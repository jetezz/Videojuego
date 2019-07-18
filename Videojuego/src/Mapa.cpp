#include <Mapa.h>
#include <iostream>

Mapa::Mapa(char *archivo, string urlTiles){
    doc.LoadFile(archivo);
    doc.LoadFile(archivo);



    XMLElement* mapaXML = doc.FirstChildElement("map");
    doc.FirstChildElement("map");



    mapaXML->QueryIntAttribute("width",&_width);
    mapaXML->QueryIntAttribute("height",&_height);
    mapaXML->QueryIntAttribute("tilewidth",&_tileWidth);
    mapaXML->QueryIntAttribute("tileheight",&_tileHeight);
    doc.FirstChildElement("map");





    imageTileset = mapaXML->FirstChildElement("tileset");
    imageTileset->QueryIntAttribute("tilewidth", &_tilesetWidth);
    imageTileset->QueryIntAttribute("tileheight", &_tilesetHeight);



    imagen = mapaXML->FirstChildElement("tileset")->FirstChildElement("image");
    ficheroimg   = (string)imageTileset->FirstChildElement("image")->Attribute("source");
    imagen->QueryIntAttribute("width",&_imageWidth);
    imagen->QueryIntAttribute("height",&_imageHeight);



    _tilesetTexture.loadFromFile(urlTiles);

    if(_tilesetTexture.loadFromFile(urlTiles));



    XMLElement *layer = mapaXML->FirstChildElement("layer");

    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    filas       = _tilesetTexture.getSize().y/_tileHeight;
    columnas    = _tilesetTexture.getSize().x/_tileWidth;


    sf::Sprite _tilesetSprite[filas*columnas+1];
    int t = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            posicion++;
            _tilesetSprite[posicion].setTexture(_tilesetTexture);
            _tilesetSprite[posicion].setTextureRect(sf::IntRect(j*_tileWidth,i*_tileHeight,_tileWidth,_tileHeight));
        }
    }


    int _tileMap[_numLayers][_height][_width];



    XMLElement *data[_numLayers];

    data[0] = mapaXML->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    layer = mapaXML->FirstChildElement("layer");
    sf::String *nombreLayer=new sf::String[_numLayers];



    for(int i=0;i<_numLayers;i++){
        for(int j=0;j<_height;j++){
            for(int k=0;k<_width;k++){

                data[i]->QueryIntAttribute("gid",&_tileMap[i][j][k]);

                data[i]=data[i]->NextSiblingElement("tile");
            }
        }


    }





    _tileMapSprite = new sf::Sprite***[_numLayers];
    for(int i=0;i<_numLayers;i++){
        _tileMapSprite[i]=new sf::Sprite**[_height];
    }

    for(int l=0;l<_numLayers;l++){
        for(int y=0;y<_height;y++){
            _tileMapSprite[l][y]=new sf::Sprite*[_width];
            for(int x=0;x<_width;x++){
                _tileMapSprite[l][y][x]=new sf::Sprite();
            }
        }
    }

    for(int i=0;i<_numLayers;i++){
        for(int j=0;j<_height;j++){
            for(int k=0;k<_width;k++){
                gid = _tileMap[i][j][k];
                if(gid>=filas*columnas){
                    cout<<"Error"<<endl;
                }else if(gid>0){
                    _tileMapSprite[i][j][k]->setTextureRect(_tilesetSprite[gid].getTextureRect());//?
                    _tileMapSprite[i][j][k]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tileMapSprite[i][j][k]->setPosition(k*_tileWidth,j*_tileHeight);
                }else{
                    _tileMapSprite[i][j][k]=NULL;
                }
            }
        }
    }
}
void Mapa::atcivarlayer(int layer){
    _activeLayer=layer;
}
void Mapa::dibujarmapa(){

        for(int i=0;i<_height;i++){
            for(int j=0;j<_width;j++){
                 if(_tileMapSprite[_activeLayer][i][j]!=NULL){
                    juego::getjuego()->ventana->draw(*(_tileMapSprite[_activeLayer][i][j]));
                 }
            }
        }

}
