#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

class Tuile
{
    string _nom;
    int _x;
    int _y;
    string _propriete;

    public:
        Tuile();
        Tuile(string, int, int, string);
        void afficher();
        string getnom();
        int getX();
        int getY();
        string getPropriete();
        void setPropriete(string);

        virtual ~Tuile();
};

#endif // TUILE_H
