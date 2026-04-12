#include <vector>
#include "personnage.h"
#include "Image.h"

using namespace std;

personnage::personnage(){}

personnage::personnage(Image& image,int direction, int X, int Y, int skinX, int skinY)
{
    _image = image;
    _X = X;
    _Y = Y;
    _direction = direction;
    _skinX = skinX;
    _skinY = skinY;
    _animation = 0;

}

void personnage::dessiner(){
    int colonne = _skinX;
    if(_animation == 0) colonne = _skinX;
    if(_animation == 1) colonne -= 1;
    if(_animation == 2) colonne += 1;
    if(_animation == 3) colonne -= 1;
    _image.dessiner(_X,_Y, colonne*16, _skinY*16 + 16*_direction, 16, 16);
}

void personnage::regarderDroite(){
    _direction = 2;
}

void personnage::regarderGauche(){
    _direction = 1;
}

void personnage::regarderBas(){
    _direction = 0;
}

void personnage::regarderHaut(){
    _direction = 3;
}

void personnage::deplacer(int dx, int dy){
    _X += dx;
    _Y += dy;
    _image.dessiner(16*dx,16*dy);
}

bool personnage::peutBougerVers(int direction, Niveau niv){
    if((_X == 0 && direction== 1) || (!niv.caseEstLibre(_X-16,_Y) && direction== 1)){
        return false;
    }
    if((_X == 16*9 && direction== 2) || (!niv.caseEstLibre(_X+16,_Y) && direction== 2)){
        return false;
    }
    if((_Y == 0 && direction== 3) || (!niv.caseEstLibre(_X,_Y-16) && direction== 3)){
        return false;
    }
    if((_Y == 16*7 && direction== 0) || (!niv.caseEstLibre(_X,_Y+16) && direction== 0)){
        return false;
    }
    else{
        return true;
    }
}

int personnage::getDirection(){ return _direction; }
int personnage::getX(){return _X;}
int personnage::getY(){return _Y;}

void personnage::mettreAjourAnimation(){
    _animation++;
    _animation = _animation%4;
}

void personnage::inverserDirection() {
    if(_direction == 0){
        _direction = 3;
    }
    else if(_direction == 3){
        _direction = 0;
    }
    else if(_direction == 2){
        _direction = 1;
    }
    else if(_direction == 1){
        _direction = 2;
    }
}
