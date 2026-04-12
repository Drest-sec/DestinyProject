#include "Niveau.h"
#include <fstream>

Niveau::Niveau()
{
    //ctor
}

Niveau::Niveau(Image& image, string nomFichier, Dictionnaire& dico){
    ifstream Flux(nomFichier);
    int nblignes;
    int niveauX;
    int niveauY;
    Tuile t;
    string nom;
    _nbbonus = 0;

    Flux>>nblignes;
    for(int i=1; i<=nblignes; i++){
        Flux>>nom;
        dico.recherche(nom, t);
        Flux>>niveauX;
        Flux>>niveauY;
        objet temp(image, nom, dico, niveauX, niveauY);
        _niveau.push_back(temp);
        if(temp.getPropriete() == "bonus"){_nbbonus = _nbbonus+1;}
    }

}

void Niveau::dessiner(){
    for(int i=0; i<_niveau.size(); i++){
        if(!(_niveau[i].getPropriete() == "cache")){
            _niveau[i].dessiner();
        }
    }
}

bool Niveau::caseEstLibre(int x, int y){
    for(int i=0; i<_niveau.size(); i++){
        if (_niveau[i].getPropriete() == "solide" && _niveau[i].getX() == x && _niveau[i].getY() == y){
            return false;
        }
    }
    return true;
}

void Niveau::testerBonusEtPrendre(int x, int y){
    for(int i=0; i<_niveau.size(); i++){
        if(_niveau[i].getPropriete() == "bonus" && _niveau[i].getX() == x && _niveau[i].getY() == y){
            _nbbonus--;
            _niveau[i].cacher();
        }
    }
}

int Niveau::getNbBonus(){return _nbbonus; }

Niveau::~Niveau()
{
    //dtor
}
