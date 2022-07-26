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
                    Black_King.setR(king_z->getR());
                    Black_King.setK(king_z->getK());
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
                    set_coordinates_white_king(rij,kolom);
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
    vector<pair<int,int>> sq = this->King_Under_attack(s->getKleur());
    if(s->getTypePiece() == "king"){
        if (!this->King_Under_attack(s->getKleur()).empty())
        {
            if (geldig_moves.size() != 0){
                for (auto coordinate : geldig_moves)
                {
                    for (auto it : sq){
                        if (it.first == coordinate.first and it.second == coordinate.second)
                        {
                            if (this->getPiece(coordinate.first,coordinate.second) == nullptr)
                            {
                                // erasing the coordiantes that is under attack
                                for (int c=0;c < geldig_moves.size();c++)
                                {
                                    if(geldig_moves[c] == coordinate)
                                    {
                                        if (!geldig_moves.empty())
                                        {
                                            geldig_moves.erase(geldig_moves.begin()+c);
                                                }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int m = 0; m < geldig_moves.size(); m++)
        {
            cout << "coordinates (" << geldig_moves[m].first << "," << geldig_moves[m].second << ")" << endl;
        }
    }
    for(pair<int,int> moves : geldig_moves)
    {

        //cout << "r: " << moves.first << " k: " << moves.second << endl;
        if(new_move == moves){
            if (s->getKleur() == zwart and s->getR() == Black_King.getR() and s->getK() == Black_King.getK())
            {
                this->setPiece(s->getR(),s->getK(), nullptr);
                this->setPiece(r,k,s);
                Black_King.setK(k);
                Black_King.setR(r);
                return true;
            }
            else if (s->getKleur() == wit and s->getR() == White_king.getR() and s->getK() == White_king.getK())
            {
                this->setPiece(s->getR(),s->getK(), nullptr);
                this->setPiece(r,k,s);
                White_king.setK(k);
                White_king.setR(r);
                return true;
            }
            else
            {
                this->setPiece(s->getR(),s->getK(), nullptr);
                this->setPiece(r,k,s);
                return true;
            }
        }

    }
    return false;
}

void Game::set_coordinates_white_king(int r, int k)
{
    White_king.setR(r);
    White_king.setK(k);
}

void Game::set_coordinates_black_king(int r, int k)
{
    Black_King.setR(r);
    Black_King.setK(k);
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
    SchaakStuk* s = get<0>(this->schaak(kleur));
    if(!size)
    {
        /*
        for (auto it : move(get<0>(this->schaak(kleur)),))
        {
            //cout << "r: " << it.first << " k: " << it.second << endl;
        }
         */
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
    //cout << "in functie pat" << endl;
    if ((!get<1>(this->schaak(kleur))) and get<0>(this->schaak(kleur))->geldige_zetten(*this).empty())
    {
       // cout << "in if statement" << endl;
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

vector<pair<int,int>> Game::King_Under_attack(zw kleur)
{
    // checking which square are under attack from the enemy piece
    // looping over the board to see which square near the king is under attack
    vector<pair<int,int>> Square_under_attack;
    vector<pair<int,int>> all_moves;
    for (int i=0; i<=7;i++)
    {
        for (int j=0; j<=7;j++)
        {
            if (this->getPiece(i,j) == nullptr)
            {
                continue;
            }
            else if (this->getPiece(i,j)->getKleur() == kleur)
            {
                continue;
            }
            else
            {
                all_moves = this->getPiece(i,j)->geldige_zetten(*this);
                string piece = this->getPiece(i,j)->getTypePiece();
                for (auto move : all_moves)
                {
                    if (afstand_tot_king(this->getPiece(i,j),move.first,move.second))
                    {
                        Square_under_attack.push_back(move);
                    }
                }
                all_moves.clear();
            }
        }
    }
    return Square_under_attack;
}

void Game::Pinned_this_piece(zw kleur)
{
    vector<SchaakStuk*> line_of_seight;
    vector<pair<int,int>> all_moves;
    for (int i=0; i<=7;i++)
    {
        for (int j=0; j<=7;j++)
        {
            if (this->getPiece(i,j) == nullptr)
            {
                continue;
            }
            else if (this->getPiece(i,j)->getTypePiece() == "rook" and this->getPiece(i,j)->getKleur() != kleur)
            {
                all_moves = this->getPiece(i,j)->line_of_sight_rook(*this);
                for (auto move : all_moves)
                {

                    if (kleur == wit)
                    {
                        if(move.first == White_king.getR() and move.second == White_king.getK())
                        {
                            break;
                        }
                        if (move.first == White_king.getR() or move.second == White_king.getK())
                        {
                            line_of_seight.push_back(this->getPiece(move.first,move.second));
                        }
                    }
                    if (kleur == zwart)
                    {
                        if(move.first == Black_King.getR() and move.second == Black_King.getK())
                        {
                            break;
                        }
                        if (move.first == Black_King.getR() or move.second == Black_King.getK())
                        {
                            line_of_seight.push_back(this->getPiece(move.first,move.second));
                        }
                    }
                }
                if (!line_of_seight.empty()){
                    bool found_peice = false;
                    SchaakStuk *s = nullptr;
                    for(int c=0; c <= line_of_seight.size()-1;c++)
                    {
                        if (line_of_seight[c] != nullptr)
                        {
                            if (line_of_seight[c]->getKleur() != kleur and !found_peice)
                            {
                                cout << "piece found" << endl;
                                found_peice = true;
                                s = line_of_seight[c];
                            }
                            else if (line_of_seight[c] != line_of_seight[line_of_seight.size()])
                            {
                                break;
                            }
                            cout << line_of_seight[c]->getTypePiece() << endl;
                        }
                        if (c == line_of_seight.size()-1)
                        {
                            if (s != nullptr){
                                s->setPin(true);
                                cout << s->getTypePiece() << " is pinned" << endl;
                            }
                        }
                    }

                    line_of_seight.clear();
                }
            }
            else if (this->getPiece(i,j)->getTypePiece() == "bishop" and this->getPiece(i,j)->getKleur() == kleur)
            {

            }
        }
    }
}

bool Game::afstand_tot_king(SchaakStuk *king, int r, int k)
{
    int temp_r = 0;
    int temp_k = 0;
    for (int j = 1; j<= 8; j++)
    {
        switch (j) {
            case 1:
                temp_k = king->getK()+1;
                temp_r = king->getR()-1;
                break;
                case 2:
                    temp_k = king->getK();
                    temp_r = king->getR()-1;
                    break;
                    case 3:
                        temp_r = king->getR()-1;
                        temp_k = king->getK()-1;
                        break;
                        case 4:
                            temp_r = king->getR();
                            temp_k = king->getK()-1;
                            break;
                            case 5:
                                temp_r = king->getR();
                                temp_k = king->getK()+1;
                                break;
                                case 6:
                                    temp_r = king->getR()+1;
                                    temp_k = king->getK()-1;
                                    break;
                                    case 7:
                                        temp_r = king->getR()+1;
                                        temp_k = king->getK();
                                        break;
                                        case 8:
                                            temp_r = king->getR()+1;
                                            temp_k = king->getK()+1;
                                            break;

        }
        if (temp_k == k and temp_r == r)
            {
                //cout << "square under attack: (" << r << ", " << k << ") " << endl;
                return true;
            }
        }
    //cout << "no threat" << endl;
    return false;
}



