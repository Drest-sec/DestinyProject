#include <vector>
#include <ctime>
#include "personnage.h"
#include "Image.h"
#include "ennemi.h"
#include "Avatar.h"

using namespace std;

ennemi::ennemi(Image& image, int direction, int X, int Y, int skinX, int skinY)
{
    _perso = personnage(image, direction, X, Y, skinX, skinY);
}

void ennemi::dessiner()
{
    _perso.dessiner();
}

void ennemi::avancer(avatar& hero, Niveau niveau)
{

    if(aPortee(hero))
    {
        int allerX = hero.getX();
        int allerY = hero.getY();
        int ennemiX = _perso.getX();
        int ennemiY = _perso.getY();

        if(abs(ennemiX - allerX) > abs(ennemiY - allerY))
        {
            if(ennemiX < allerX)
            {
                if (_perso.peutBougerVers(2, niveau))
                {
                    _perso.regarderDroite();
                    _perso.deplacer(16, 0);
                    return;
                }
            }
            else
            {
                if (_perso.peutBougerVers(1, niveau))
                {
                    _perso.regarderGauche();
                    _perso.deplacer(-16, 0);
                    return;
                }
            }
        }
        if(ennemiY < allerY)
        {
            if(_perso.peutBougerVers(0, niveau))
            {
                _perso.regarderBas();
                _perso.deplacer(0, 16);
                return;
            }
        }
        else if(ennemiY > allerY)
        {
            if(_perso.peutBougerVers(3, niveau))
            {
                _perso.regarderHaut();
                _perso.deplacer(0, -16);
                return;
            }
        }
    }

    int direction = _perso.getDirection();
    int changerDirection = rand()%2;
    if(changerDirection == 1)
    {
        direction = rand()%4;
    }
    if(_perso.peutBougerVers(direction, niveau))
    {
        if(direction == 0)
        {
            _perso.regarderBas();
            _perso.deplacer(0,16);
        }
        else if(direction == 1)
        {
            _perso.regarderGauche();
            _perso.deplacer(-16,0);
        }
        else if(direction == 2)
        {
            _perso.regarderDroite();
            _perso.deplacer(16,0);
        }
        else if(direction == 3)
        {
            _perso.regarderHaut();
            _perso.deplacer(0,-16);
        }
    }
    else{
        _perso.inverserDirection();
    }
}

int ennemi::getX()
{
    return _perso.getX();
}
int ennemi::getY()
{
    return _perso.getY();
}

bool ennemi::aPortee(avatar& hero)
{
    int dx = _perso.getX();
    int dy = _perso.getY();
    return(dx + dy <= 64);
}


