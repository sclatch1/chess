//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_GAME_H
#define SCHAKEN_GAME_H
#include <vector>
#include "SchaakStuk.h"

using namespace std;

class Game {
// variabelen om de status van het spel/bord te bewaren

public:
    Game();
    ~Game();

    bool move(SchaakStuk* s,int r, int k); // Verplaats stuk s naar rij r en kolom k

    tuple<SchaakStuk*,bool> schaak(zw kleur);
    bool schaakmat(zw kleur);
    bool pat(zw kleur);
    void setStartBord();

    SchaakStuk* getPiece(int r, int k);
    void setPiece(int r, int k, SchaakStuk* s);
    bool moveIsPossible(SchaakStuk* s, int r, int k);
    bool move_back(SchaakStuk *s,SchaakStuk* temp,int r_piece_at_loc,int k_piec_at_loc);
private:
    // Hier zet jij jouw datastructuur neer om het bord te bewaren ...
    SchaakStuk* bord[8][8];
    SchaakStuk* copy_g[8][8];
};


#endif //SCHAKEN_GAME_H
