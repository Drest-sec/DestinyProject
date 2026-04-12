#include "objet.h"

objet::objet(Image image, string nom, Dictionnaire dico, int x, int y)
{
    _image = image;
    _niveauX = x;
    _niveauY = y;

    dico.recherche(nom, _tuile);
}

void objet::dessiner(){
    _image.dessiner(_niveauX*16,_niveauY*16,_tuile.getX()*16,_tuile.getY()*16,16,16);
}

string objet::getPropriete(){return _tuile.getPropriete();}
int objet::getX(){return _niveauX*16;}
int objet::getY(){return _niveauY*16;}

void objet::cacher(){
    _tuile.setPropriete("cache");
}

objet::~objet()
{
    //dtor
}
