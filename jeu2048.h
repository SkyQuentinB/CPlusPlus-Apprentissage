/**
 @file jeu2048.cpp
 @brief Déclaration de la classe du jeu 2048
 @version 1.9
 @author Quentin BRAULT
 @date 18 Septembre 2020
 */


#ifndef JEU2048_H
#define JEU2048_H

#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

#define NB_VAL 4

class Jeu2048
{
    enum MODE_ALEATOIRE
    {
        POSITION,
        TUILE
    };



private:
    int grille[NB_VAL][NB_VAL];
    char direction;
    int nbCoups;
    int score;

    int TirerAleatoire(const MODE_ALEATOIRE _mode);
    void PlacerNouvelleTuile();
    bool Calculer();
    void Deplacer();
    void CalculerScore();
    bool RechercherFinDePartie();
public:
    Jeu2048();
    bool JouerCoup(char _direction);
    int ObtenirNbCoups();
    int ObtenirScore();
    void ObtenirGrille(int _grille[][NB_VAL]);
};

#endif // JEU2048_H
