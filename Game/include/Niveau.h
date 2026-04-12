#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>
#include "objet.h"
#include "Dictionnaire.h"
#include "Image.h"

using namespace std;

class Niveau
{
    vector<objet> _niveau;
    int _nbbonus;

    public:
        Niveau();
        Niveau(Image&, string, Dictionnaire&);
        void dessiner();
        bool caseEstLibre(int, int);
        void testerBonusEtPrendre(int, int);
        int getNbBonus();

        virtual ~Niveau();
};

#endif // NIVEAU_H
