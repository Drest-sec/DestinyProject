#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include <vector>
#include <string>
#include "Tuile.h"

using namespace std;

class Dictionnaire
{
    vector<Tuile> _dico;

    public:
        Dictionnaire(string);
        void afficher();
        bool recherche(string, Tuile&);
        vector<Tuile> getDico();

        virtual ~Dictionnaire();

};

#endif // DICTIONNAIRE_H
