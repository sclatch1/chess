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



    tuple<SchaakStuk*,bool> schaak(zw kleur);
    bool schaakmat(zw kleur);
    bool pat(zw kleur);
    void setStartBord();
    bool move(SchaakStuk* s,int r, int k); // Verplaats stuk s naar rij r en kolom k
    SchaakStuk* getPiece(int r, int k);
    void setPiece(int r, int k, SchaakStuk* s);
    bool moveIsPossible(SchaakStuk* s, int r, int k);
    void set_coordinates_white_king(int r, int k);
    void set_coordinates_black_king(int r, int k);
    vector<pair<int,int>> King_Under_attack(zw kleur);
    static static bool afstand_tot_king(SchaakStuk *king, int r, int k);
    void Pinned_this_piece(zw kleur);
private:
    // Hier zet jij jouw datastructuur neer om het bord te bewaren ...
    SchaakStuk* bord[8][8];

    Koning Black_King = Koning(zwart);
    Koning White_king = Koning(wit);
};


#endif //SCHAKEN_GAME_H
