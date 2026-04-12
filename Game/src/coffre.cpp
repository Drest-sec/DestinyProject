#include <iostream>
#include <vector>

#include "Image.h"
#include "coffre.h"

using namespace std;

coffre::coffre(){

}

coffre::coffre(Moteur& moteur, Image& texture, int X, int Y)
    : _moteur(&moteur), _texture(&texture)
{
    _X = X;
    _Y = Y;
}

void coffre::afficher(int X, int Y){
//    _texture.dessiner(X,Y);
}

