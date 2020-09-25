#include "jeu2048.h"

/**
 @file jeu2048.cpp
 @brief Implémentation de la classe du jeu 2048
 @version 1.9
 @author Quentin BRAULT
 @date 18 Septembre 2020

 */

/**
 * @brief Jeu2048::Jeu2048
 */


Jeu2048::Jeu2048():nbCoups(0), score(0)
{
    srand(time(nullptr));

    int ligne;
    int colonne;
    for(ligne=0;ligne<NB_VAL;ligne++){
    for(colonne=0;colonne<NB_VAL;colonne++){
        grille[ligne][colonne]=0;
    }
    }
   grille[rand() % NB_VAL][rand() % NB_VAL] = ((rand() % 2)+1) *2;
}

/**
 * @brief Jeu2048::TirerAleatoire
 * Renvoie un entier entre 2 ou 4
 * @param _mode
 * @return int la valeur du tirage
 */

int Jeu2048::TirerAleatoire(const Jeu2048::MODE_ALEATOIRE _mode)
{
    int retour;
    if(_mode == POSITION)
        retour = rand() % NB_VAL;
    else if(_mode == TUILE){
        retour = (((rand() % 2) +1 ) * 2);
    }
    return retour;
}

/**
 * @brief Jeu2048::PlacerNouvelleTuile
 * Placer une nouvelle tuile dans la grille
 */
void Jeu2048::PlacerNouvelleTuile()
{
    int ligne;
    int colonne;
    do{
    ligne = TirerAleatoire(POSITION);
    colonne = TirerAleatoire(POSITION);
}while(grille[ligne][colonne] !=0);
        grille[ligne][colonne] = TirerAleatoire(TUILE);

}

void Jeu2048::ObtenirGrille(int _grille[][NB_VAL])
{
    for(int ligne = 0;ligne < NB_VAL;ligne++){
        for(int colonne = 0; colonne < NB_VAL;colonne++){
            _grille[ligne][colonne] = grille[ligne][colonne];
        }
    }
}


int Jeu2048::ObtenirScore()
{
    return score;
}

int Jeu2048::ObtenirNbCoups()
{
return nbCoups;
}

bool Jeu2048::Calculer()
{
    int ligne;
    int colonne;
    bool verif = false;
    switch (direction) {
    case  'G' :
        for(ligne = 0;ligne<NB_VAL;ligne++){
            for(colonne=0;colonne<NB_VAL-1;colonne++){
                if(grille[ligne][colonne] == grille[ligne][colonne+1]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne][colonne+1]=0;
                    verif = true;
                }
            }
        }
    break;
    case 'D' :
        for(ligne = 0;ligne<NB_VAL;ligne++){
            for(colonne=NB_VAL-1;colonne>0;colonne--){
                if(grille[ligne][colonne] == grille[ligne][colonne-1]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne][colonne-1]=0;
                    verif = true;
                }
            }
        }
        break;
        case 'B' :
            for(colonne = 0;colonne<NB_VAL;colonne++){
                for(ligne=NB_VAL-1;ligne>0;ligne--){
                    if(grille[ligne][colonne] == grille[ligne-1][colonne]){
                        grille[ligne][colonne] = grille[ligne][colonne]*2;
                        grille[ligne-1][colonne]=0;
                        verif = true;
                    }
                }
            }
        break;
        case 'H' :
            for(colonne = 0;colonne<NB_VAL;colonne++){
                for(ligne=0;ligne<NB_VAL-1;ligne++){
                    if(grille[ligne][colonne] == grille[ligne+1][colonne]){
                        grille[ligne][colonne] = grille[ligne][colonne]*2;
                        grille[ligne+1][colonne]=0;
                        verif = true;
                    }
                }
            }
        break;
    }
}


void Jeu2048::Deplacer()
{
    int indice;
    int ligne;
    int colonne;

    for(indice=0;indice < NB_VAL-1;indice++){

    switch (direction) {
    case  'G' :
        for(ligne = 0;ligne<NB_VAL;ligne++){
            for(colonne=0;colonne<NB_VAL-1;colonne++){
                if(grille[ligne][colonne] == 0){
                    grille[ligne][colonne] = grille[ligne][colonne+1];
                    grille[ligne][colonne+1]=0;
                }
            }
        }
    break;
    case 'D' :
        for(ligne = 0;ligne<NB_VAL;ligne++){
            for(colonne=NB_VAL-1;colonne>0;colonne--){
                if(grille[ligne][colonne] == 0){
                    grille[ligne][colonne] = grille[ligne][colonne-1];
                    grille[ligne][colonne-1]=0;
                }
            }
        }
        break;
        case 'B' :
            for(colonne = 0;colonne<NB_VAL;colonne++){
                for(ligne=NB_VAL-1;ligne>0;ligne--){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne]=0;
                    }
                }
            }
        break;
        case 'H' :
            for(colonne = 0;colonne<NB_VAL;colonne++){
                for(ligne=0;ligne<NB_VAL-1;ligne++){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne]=0;
                    }
                }
            }
        break;
    }
    }
}

bool Jeu2048::RechercherFinDePartie(){
    bool fin = false;
    int cpt=0;
    int ligne;
    int colonne;
    for(ligne = 0;ligne < NB_VAL;ligne++){
    for(colonne=0;colonne<NB_VAL;colonne++){
        if(grille[ligne][colonne] == 2048){
            fin = true;
        }
        if(grille[ligne][colonne]==0){
            cpt++;
        }
    }
    }
    if(cpt==0){
        fin = true;
    }
    return fin;
}

void Jeu2048::CalculerScore(){
    int somme  =0;
    int ligne;
    int colonne;

    for(ligne=0;ligne<NB_VAL;ligne++){
        for(colonne=0;colonne<NB_VAL;colonne++){
            somme= somme + grille[ligne][colonne];
        }
    }
    score = somme;
}


bool Jeu2048::JouerCoup(char _direction)
{
    direction = _direction;
    Deplacer();
    if(Calculer())
        Deplacer();
    CalculerScore();
    bool fin = RechercherFinDePartie();
    if(!fin)
        PlacerNouvelleTuile();
    nbCoups++;
    return fin;
}




