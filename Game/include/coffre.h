#ifndef COFFRE_H_INCLUDED
#define COFFRE_H_INCLUDED
#include "Image.h"
#include "Moteur.h"
#include <memory>

using namespace std;

class coffre{

    Moteur* _moteur;
    Image* _texture;
    int _X;
    int _Y;

public :

    coffre();

    coffre(Moteur&, Image&, int, int);

    void afficher(int, int);
};


#endif // COFFRE_H_INCLUDED
