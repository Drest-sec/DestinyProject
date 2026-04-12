#include <iostream>
#include "Tuile.h"

using namespace std;

Tuile::Tuile(){

}

Tuile::Tuile(string nom, int x, int y, string propriete)
{
    _nom = nom;
    _x = x;
    _y = y;
    _propriete = propriete;
}

void Tuile::afficher(){
    cout<<_nom<<" : x="<<_x<<" y="<<_y<<" objet "<<_propriete<<endl;
}

string Tuile::getnom(){return _nom;}
int Tuile::getX(){return _x;}
int Tuile::getY(){return _y;}
string Tuile::getPropriete(){return _propriete;}

void Tuile::setPropriete(string nouvellePropriete){
    _propriete = nouvellePropriete;
}

Tuile::~Tuile()
{
    //dtor
}
