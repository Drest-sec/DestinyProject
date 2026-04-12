#include <vector>
#include "personnage.h"
#include "Image.h"
#include "Avatar.h"

using namespace std;

avatar::avatar(Image& image, int direction, int X, int Y, int skinX, int skinY)
{
    _perso = personnage(image, direction, X, Y, skinX, skinY);
}

void avatar::dessiner(){
    _perso.dessiner();
}

int avatar::getX(){return _perso.getX();}
int avatar::getY(){return _perso.getY();}

void avatar::allerDroite(Niveau niveau){
    bool deplacement = _perso.peutBougerVers(2, niveau);
    _perso.regarderDroite();
    if(deplacement){
        _perso.deplacer(16,0);
    }
}

void avatar::allerGauche(Niveau niveau){
    bool deplacement = _perso.peutBougerVers(1, niveau);
    _perso.regarderGauche();
    if(deplacement){
        _perso.deplacer(-16,0);
    }
}

void avatar::allerBas(Niveau niveau){
    bool deplacement = _perso.peutBougerVers(0, niveau);
    _perso.regarderBas();
    if(deplacement){
        _perso.deplacer(0,16);
    }
}

void avatar::allerHaut(Niveau niveau){
    bool deplacement = _perso.peutBougerVers(3, niveau);
    _perso.regarderHaut();
    if(deplacement){
        _perso.deplacer(0,-16);
    }
}

void avatar::mettreAjourAnimation(){
    _perso.mettreAjourAnimation();
}

bool avatar::touche(ennemi& ennemi){
    if(ennemi.getX()== _perso.getX() && ennemi.getY() == _perso.getY()){
        return true;
    }
    else{
        return false;
    }
}
