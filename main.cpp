#include <iostream>
#include "jeu2048.h"
using namespace std;

void AfficherGrille(Jeu2048 _leJeu);




int main()
{
    Jeu2048 leJeu;
        bool fin = false;
        char direction;
        do{
            AfficherGrille(leJeu);
            cout << "Saissisez la direction souhaité (H B G D) : ";
            cin >> direction;
            cout << "" << endl;
            direction = toupper(direction);
            if(strchr("BHGD",direction) != nullptr)
                fin = leJeu.JouerCoup(direction);
        }while (direction != 'f' && fin == false);

    return 0;
}

void AfficherGrille(Jeu2048 _leJeu){
    int grille[NB_VAL][NB_VAL];
    int score;
    int nbcoups;
   score = _leJeu.ObtenirScore();
   nbcoups = _leJeu.ObtenirNbCoups();

    _leJeu.ObtenirGrille(grille);
    int ligne;
    int colonne;

    cout << "Score : " << score << " | " << "Nombre de coups : " << nbcoups << " | " << endl;
    cout<< "+" << setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" << setfill(' ') << endl;
    for(ligne=0;ligne<NB_VAL;ligne++){
        for(colonne=0;colonne<NB_VAL;colonne++){
            cout <<"|"<< setw(4)<< left ;
            if(grille[ligne][colonne] != 0){
                cout << grille[ligne][colonne] ;
            }else{
                cout << "";

}

    }
        cout << "|" << endl;
        cout<< "+" << setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" <<setfill ('-') <<setw(4)<<  "" << "+" << setfill(' ') << endl;
}
}

