#include <vector>
#include <ctime>

#include "Moteur.h"
#include "Image.h"
#include "coffre.h"
#include "personnage.h"
#include "Avatar.h"
#include "ennemi.h"
#include "Dictionnaire.h"
#include "Tuile.h"
#include "objet.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version speciale du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo", 4);
  srand(time(NULL));

  Image fond;
  Image coffre;
  Image perso;
  Image gameOver;
  Image objets;
  Image bravo;
  Image coffre_ferme;
  Image coffre_ouvert;

  try{
    fond = Image(moteur, "./assets/fond.png");
    perso= Image(moteur, "./assets/personnages.png");
    gameOver = Image(moteur,"./assets/gameover.png");
    objets = Image(moteur,"./assets/objets.png");
    bravo = Image(moteur,"./assets/bravo.png");
  }
  catch(const std::runtime_error& e){
        cout<<"erreur"<<endl;
  }

  avatar chevalier(perso, 0, TAILLE_CASE, 2*TAILLE_CASE, 4, 0);
  ennemi ennemi1(perso, 0, 5*16, 16, 6, 4);
  ennemi ennemi2(perso, 1, 16, 5*16, 3, 4);
  Dictionnaire test("./assets/dictionnaire.txt");
  objet lune(objets, "Icone_lune", test, 3,3);
  Niveau niveau1(objets, "./assets/niveau.txt", test);

  bool BcoffreOuvert = false;
  bool quitter = false;
  bool restart = true;
  bool gagne = false;
  int latence = 1;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        case QUITTER_APPUYE:
          quitter = true;
          break;
        // TODO: gerer les autres evenements
        case ESPACE_APPUYE:
            BcoffreOuvert = true;
            break;
        case ESPACE_RELACHE:
            BcoffreOuvert = false;
            break;
        case DROITE_APPUYE:
            if(latence<=0){
            chevalier.allerDroite(niveau1);
            niveau1.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
            chevalier.mettreAjourAnimation();
            latence=1;
            }
            break;
        case GAUCHE_APPUYE:
            if(latence<=0){
            chevalier.allerGauche(niveau1);
            niveau1.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
            chevalier.mettreAjourAnimation();
            latence=1;
            }
            break;
        case HAUT_APPUYE:
            if(latence<=0){
            chevalier.allerHaut(niveau1);
            niveau1.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
            chevalier.mettreAjourAnimation();
            latence=1;
            }
            break;
        case BAS_APPUYE:
            if(latence<=0){
            chevalier.allerBas(niveau1);
            niveau1.testerBonusEtPrendre(chevalier.getX(), chevalier.getY());
            chevalier.mettreAjourAnimation();
            latence=1;
            }
            break;
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    if(moteur.animationsAmettreAjour()){
        latence--;
        ennemi1.avancer(chevalier, niveau1);
        ennemi2.avancer(chevalier, niveau1);
    }

    moteur.initialiserRendu();
    fond.dessiner(0,0);
    niveau1.dessiner();
    gagne = (niveau1.getNbBonus() == 0);

    if(!chevalier.touche(ennemi1)&&!chevalier.touche(ennemi2)){
        chevalier.dessiner();
    }
    ennemi1.dessiner();
    ennemi2.dessiner();

    if(chevalier.touche(ennemi1)||chevalier.touche(ennemi2)){
        gameOver.dessiner(30,51);
        moteur.finaliserRendu();
        moteur.attendre(3);
        quitter = true;
    }

    if(gagne){
        bravo.dessiner(30,51);
        moteur.finaliserRendu();
        moteur.attendre(3);
        quitter = true;
    }


    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
  }

  return 0;
}
