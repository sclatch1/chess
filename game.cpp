//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "game.h"
#include "SchaakStuk.h"
#include "iostream"
#include <algorithm>

using namespace std;

Game::Game()
{
    { cout << "Constructor is executed\n"; }
}

Game::~Game() {{ cout << "Destructor is executed\n"; }}

// Zet het bord klaar; voeg de stukken op de juiste plaats toe
void Game::setStartBord()
{
    for(int rij = 0; rij <= 7;rij++){
        for(int kolom=0; kolom <= 7;kolom++)
        {
            // set pawns
            if(rij == 1)
            {
                Pion* pion_z = new Pion(zwart);
                setPiece(1,kolom, pion_z);
                pion_z->setTypePiece("pion");
                continue;
            }
            if(rij == 6)
            {
                Pion* pion_w = new Pion(wit);
                setPiece(6,kolom,pion_w);
                pion_w->setTypePiece("pion");
                continue;
            }
            // set black pieces
            if(rij == 0)
            {
                // set rooks
                if(kolom == 0 || kolom == 7)
                {
                    Toren* rook_z = new Toren(zwart);
                    setPiece(rij,kolom,rook_z);
                    rook_z->setTypePiece("rook");
                }
                // set bishop
                if(kolom == 2 || kolom == 5)
                {
                    Loper* bishop_z = new Loper(zwart);
                    setPiece(rij,kolom,bishop_z);
                    bishop_z->setTypePiece("bishop");
                }
                // set horse
                if(kolom == 1 || kolom == 6)
                {
                    Paard* horse_z = new Paard(zwart);
                    setPiece(rij,kolom,horse_z);
                    horse_z->setTypePiece("horse");
                }
                // set queen
                if(kolom == 3)
                {
                    Koningin* queen_z = new Koningin(zwart);
                    setPiece(rij,kolom,queen_z);
                    queen_z->setTypePiece("queen");
                }
                // set king
                if(kolom == 4)
                {
                    Koning* king_z = new Koning(zwart);
                    setPiece(rij,kolom,king_z);
                    king_z->setTypePiece("king");
                }
            }
            // set white pieces
            else if(rij == 7)
            {
                // set rooks
                if(kolom == 0 || kolom == 7)
                {
                    Toren* rook_w = new Toren(wit);
                    setPiece(rij,kolom,rook_w);
                    rook_w->setTypePiece("rook");
                }
                // set bishop
                if(kolom == 2 || kolom == 5)
                {
                    Loper* bishop_w = new Loper(wit);
                    setPiece(rij,kolom,bishop_w);
                    bishop_w->setTypePiece("bishop");
                }
                // set horse
                if(kolom == 1 || kolom == 6)
                {
                    Paard* horse_w = new Paard(wit);
                    setPiece(rij,kolom,horse_w);
                    horse_w->setTypePiece("horse");
                }
                // set queen
                if(kolom == 3)
                {
                    Koningin* queen_w = new Koningin(wit);
                    setPiece(rij,kolom,queen_w);
                    queen_w->setTypePiece("queen");
                }
                // set king
                if(kolom == 4)
                {
                    Koning* king_w = new Koning(wit);
                    setPiece(rij,kolom,king_w);
                    king_w->setTypePiece("king");
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
    vector<pair<int,int>> geldig_moves = s->geldige_zetten(*this);
    for(pair<int,int> moves : geldig_moves)
    {
        if(new_move == moves)
        {
            this->setPiece(s->getR(),s->getK(), nullptr);
            this->setPiece(r,k,s);
            return true;
        }
    }
    return false;
}

bool Game::move_back(SchaakStuk *temp,SchaakStuk* piece_at_location,int r_piece_at_loc,int k_piec_at_loc)
{
    this->bord[temp->getR()][temp->getK()] = temp;

    this->bord[r_piece_at_loc][k_piec_at_loc] = piece_at_location;
    return true;
}

bool Game::moveIsPossible(SchaakStuk *s, int r, int k)
{
    pair<int,int> new_move = make_pair(r,k);
    vector<pair<int,int>> geldig_moves = s->geldige_zetten(*this);
    for(pair<int,int> moves : geldig_moves)
    {
        if(new_move == moves)
        {
            return true;
        }
    }
    return false;
}


// Geeft true als kleur schaak staat
tuple<SchaakStuk*,bool> Game::schaak(zw kleur) {
    for (int r=0;r <= 7;r++)
    {
        for (int k=0;k <= 7;k++)
        {
            if( this->getPiece(r,k) == nullptr )
           {
               continue;
           }
            else if (this->getPiece(r,k)->getKleur() != kleur)
           {
               for (auto move : this->getPiece(r,k)->geldige_zetten(*this))
               {
                   if (this->getPiece(move.first,move.second) != nullptr)
                   {
                       if (this->getPiece(move.first,move.second)->getTypePiece() == "king" and this->getPiece(move.first,move.second)->getKleur() == kleur)
                       {
                           tuple<SchaakStuk*,bool> my_tuple = make_tuple(this->getPiece(move.first,move.second),true);
                           return my_tuple;
                       }
                   }
               }
           }
        }
    }
    tuple<SchaakStuk*,bool> my_tuple = make_tuple(nullptr, false);
    return my_tuple;
}

// Geeft true als kleur schaakmat staat
bool Game::schaakmat(zw kleur) {
    bool result = get<1>(this->schaak(kleur));
    bool size = get<0>(this->schaak(kleur))->geldige_zetten(*this).empty();
    if(!size)
    {
        for (auto it : get<0>(this->schaak(kleur))->geldige_zetten(*this))
        {
            cout << "r: " << it.first << " k: " << it.second << endl;
        }
    }
    if (get<1>(this->schaak(kleur)) and get<0>(this->schaak(kleur))->geldige_zetten(*this).empty())
    {
        return true;
    }
    return false;
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool Game::pat(zw kleur) {
    cout << "in functie pat" << endl;
    if ((!get<1>(this->schaak(kleur))) and get<0>(this->schaak(kleur))->geldige_zetten(*this).empty())
    {
        cout << "in if statement" << endl;
        return true;
    }
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
    this->bord[r][k] = s;

    if (s != nullptr){
        s->setK(k);
        s->setR(r);
    }
}



