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

    bool schaak(zw kleur);
    bool schaakmat(zw kleur);
    bool pat(zw kleur);
    void setStartBord();

    SchaakStuk* getPiece(int r, int k);
    void setPiece(int r, int k, SchaakStuk* s);
    bool moveIsPossible(SchaakStuk* s, int r, int k);
    bool move_back(SchaakStuk *s,SchaakStuk* temp , int r, int k);
private:
    // Hier zet jij jouw datastructuur neer om het bord te bewaren ...
    SchaakStuk* bord[8][8];
};


#endif //SCHAKEN_GAME_H
