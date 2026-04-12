#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED
#include "personnage.h"
#include "Image.h"
#include "ennemi.h"
#include "Niveau.h"

using namespace std;

class avatar{

    personnage _perso;

public :

    avatar(Image&, int, int, int, int, int);

    void dessiner();
    int getX();
    int getY();

    void allerDroite(Niveau);
    void allerGauche(Niveau);
    void allerHaut(Niveau);
    void allerBas(Niveau);
    void mettreAjourAnimation();
    bool touche(ennemi&);
};

#endif // AVATAR_H_INCLUDED
