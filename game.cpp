//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "game.h"
#include "SchaakStuk.h"

Game::Game() {}

Game::~Game() {}

// Zet het bord klaar; voeg de stukken op de juiste plaats toe
void Game::setStartBord()
{

    Pion* pion_w = new Pion(wit);
    Pion* pion_z = new Pion(zwart);
    Toren* rook_w = new Toren(wit);
    Toren* rook_z = new Toren(zwart);
    Loper* bishop_w = new Loper(wit);
    Loper* bishop_z = new Loper(zwart);
    Paard* horse_w = new Paard(wit);
    Paard* horse_z = new Paard(zwart);
    Koning* king_w = new Koning(wit);
    Koning* king_z = new Koning(zwart);
    Koningin* queen_w = new Koningin(wit);
    Koningin* queen_z = new Koningin(zwart);
    for(int rij = 0; rij <= 7;rij++){
        for(int kolom=0; kolom <= 7;kolom++)
        {
            // set pawns
            setPiece(1,kolom, pion_z);
            setPiece(6,kolom,pion_w);
            // set black pieces
            if(rij == 0)
            {
                // set rooks
                if(kolom == 0 || kolom == 7)
                {
                    setPiece(rij,kolom,rook_z);
                }
                // set bishop
                if(kolom == 1 || kolom == 6)
                {
                    setPiece(rij,kolom,bishop_z);
                }
                // set horse
                if(kolom == 2 || kolom == 5)
                {
                    setPiece(rij,kolom,horse_z);
                }
                // set queen
                if(kolom == 4)
                {
                    setPiece(rij,kolom,queen_z);
                }
                // set king
                if(kolom == 3)
                {
                    setPiece(rij,kolom,king_z);
                }
            }
            // set white pieces
            else if(rij == 7)
            {
                // set rooks
                if(kolom == 0 || kolom == 7)
                {
                    setPiece(rij,kolom,rook_w);
                }
                // set bishop
                if(kolom == 1 || kolom == 6)
                {
                    setPiece(rij,kolom,bishop_w);
                }
                // set horse
                if(kolom == 2 || kolom == 5)
                {
                    setPiece(rij,kolom,horse_w);
                }
                // set queen
                if(kolom == 3)
                {
                    setPiece(rij,kolom,queen_w);
                }
                // set king
                if(kolom == 4)
                {
                    setPiece(rij,kolom,king_w);
                }
            }
            else
            {
                setPiece(rij,kolom,nullptr);
            }
        }
    }
}






// Verplaats stuk s naar positie (r,k)
// Als deze move niet mogelijk is, wordt false teruggegeven
// en verandert er niets aan het schaakbord.
// Anders wordt de move uitgevoerd en wordt true teruggegeven
bool Game::move(SchaakStuk* s, int r, int k) {
    pair<int,int> new_move = make_pair(r,k);
    for(pair<int,int> moves : s->geldige_zetten(*this))
    {
        if(new_move == moves)
        {
            move(s,r,k);
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Geeft true als kleur schaak staat
bool Game::schaak(zw kleur) {
    return false;
}

// Geeft true als kleur schaakmat staat
bool Game::schaakmat(zw kleur) {
    return false;
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool Game::pat(zw kleur) {
    return false;
}

// Geeft een pointer naar het schaakstuk dat op rij r, kolom k staat
// Als er geen schaakstuk staat op deze positie, geef nullptr terug
SchaakStuk* Game::getPiece(int r, int k) {
    // Hier komt jouw code om op te halen welk stuk op rij r, kolom k staat
    SchaakStuk* piece = bord[r][k];
    if (piece != nullptr)
    {
        return piece;
    }
    return nullptr;
}

// Zet het schaakstuk waar s naar verwijst neer op rij r, kolom k.
// Als er al een schaakstuk staat, wordt het overschreven.
// Bewaar in jouw datastructuur de *pointer* naar het schaakstuk,
// niet het schaakstuk zelf.
void Game::setPiece(int r, int k, SchaakStuk* s)
{
    // Hier komt jouw code om een stuk neer te zetten op het bord
    bord[r][k] = s;
}

