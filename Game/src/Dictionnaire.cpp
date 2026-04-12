#include "Dictionnaire.h"
#include "Tuile.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Dictionnaire::Dictionnaire(string nomFichier)
{
    ifstream Flux(nomFichier);
    int nblignes;
    string nom;
    int x;
    int y;
    string propriete;

    Flux >> nblignes;
    for(int i=1; i<=nblignes; i++){
        Flux >> nom;
        Flux >> x;
        Flux >> y;
        Flux >> propriete;
        Tuile temp(nom, x, y, propriete);
        _dico.push_back(temp);
    }

}

vector<Tuile> Dictionnaire::getDico(){return _dico;}

void Dictionnaire::afficher(){
    for(int j=0; j<_dico.size(); j++){
        _dico[j].afficher();
    }
}

bool Dictionnaire::recherche(string nomTuile, Tuile& tuile){ //recherche dicotomique
    int debut = 0;
    int fin = _dico.size()-1;
    int milieu;
    bool trouve = false;

    while(!trouve && debut <= fin){
        milieu = (debut+fin)/2;
        trouve = (_dico[milieu].getnom()==nomTuile);
        if(!trouve){
            if(_dico[milieu].getnom() > nomTuile){
                fin = milieu-1;
            }
            else{
                debut = milieu+1;
            }
        }
        else{
            tuile = _dico[milieu];
        }
    }
    return trouve;
}

Dictionnaire::~Dictionnaire()
{
    //dtor
}
