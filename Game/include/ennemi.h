#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "personnage.h"
#include "Image.h"
#include "Niveau.h"

using namespace std;

class avatar;

class ennemi{

    personnage _perso;

public :

    ennemi(Image&, int, int, int, int, int);

    void dessiner();

    void avancer(avatar&, Niveau);

    int getX();
    int getY();

    bool aPortee(avatar&);
};

#endif // ENNEMI_H_INCLUDED
