#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Image.h"
#include "Niveau.h"

using namespace std;

class personnage{

    Image _image;
    int _X;
    int _Y;
    int _direction;
    int _skinX;
    int _skinY;
    int _animation;

public :

    personnage();

    personnage(Image&, int, int, int, int, int);

    void dessiner();

    void regarderDroite();
    void regarderGauche();
    void regarderHaut();
    void regarderBas();

    void deplacer(int, int);
    int getDirection();
    int getX();
    int getY();
    void inverserDirection();

    void mettreAjourAnimation();
    bool peutBougerVers(int, Niveau);
};

#endif // PERSONNAGE_H_INCLUDED
