#ifndef OBJET_H
#define OBJET_H
#include "Image.h"
#include "Dictionnaire.h"
#include "Tuile.h"

class objet
{

    Image _image;
    int _niveauX;
    int _niveauY;
    Tuile _tuile;

public:
    objet(Image, string, Dictionnaire, int, int);
    void dessiner();
    string getPropriete();
    int getX();
    int getY();
    void cacher();

    virtual ~objet();
};

#endif // OBJET_H
