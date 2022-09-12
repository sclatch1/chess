//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (om de AI te laten spelen moet er nog eens op het bord worden geclicked)
//

#include "game.h"
#include "SchaakStuk.h"
#include "iostream"
#include "utilities.h"
#include <algorithm>

using namespace std;

Game::Game()
{
    cout << "Constructor is executed\n";

}

Game::~Game() {
    cout << "Destructor is executed\n";

    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            if (bord[i][j] != nullptr)
            {
                bord[i][j] = nullptr;
                delete bord[i][j];
            }
        }
    }

}

void Game::delete_copy()
{

    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            if (copy[i][j] != nullptr)
            {
                copy[i][j] = nullptr;
                delete copy[i][j];
            }
        }
    }

}


void Game::Make_copy()
{
    for (int i=0;i<=7;i++)
    {
        for (int j=0;j<=7;j++)
        {
            if (this->bord[i][j] == nullptr)
            {
                this->copy[i][j] = nullptr;
            }
            else if(this->bord[i][j]->getTypePiece() == "Rb")
            {
                auto s = new Toren(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);

            }
            else if(this->bord[i][j]->getTypePiece() == "Bb")
            {
                auto s = new Loper(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Hb")
            {
                auto s = new Paard(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Qb")
            {
                auto s = new Koningin(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Kb")
            {
                auto s = new Koning(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);
                s->setTypePieceCopy("Kb");
            }
            else if(this->bord[i][j]->getTypePiece() == "Pb")
            {
                auto s = new Pion(zwart);
                s->setKleur_copy(zwart);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Rw")
            {
                auto s = new Toren(wit);
                s->setKleur_copy(wit);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Bw")
            {
                auto s = new Loper(wit);
                s->setKleur_copy(wit);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Hw")
            {
                auto s = new Paard(wit);
                s->setKleur_copy(wit);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Qw")
            {
                auto s = new Koningin(wit);
                s->setKleur_copy(wit);
                setPiece_copy(i,j,s);
            }
            else if(this->bord[i][j]->getTypePiece() == "Kw")
            {
                auto s = new Koning(wit);
                setPiece_copy(i,j,s);
                s->setKleur_copy(wit);
                s->setTypePieceCopy("Kw");
            }
            else if(this->bord[i][j]->getTypePiece() == "Pw")
            {
                auto s = new Pion(wit);
                s->setKleur_copy(wit);
                setPiece_copy(i,j,s);
            }
        }
    }

}


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
                pion_z->setTypePiece("Pb");
                continue;
            }
            if(rij == 6)
            {
                Pion* pion_w = new Pion(wit);
                setPiece(6,kolom,pion_w);
                pion_w->setTypePiece("Pw");
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
                    rook_z->setTypePiece("Rb");
                }
                // set bishop
                if(kolom == 2 || kolom == 5)
                {
                    Loper* bishop_z = new Loper(zwart);
                    setPiece(rij,kolom,bishop_z);
                    bishop_z->setTypePiece("Bb");
                }
                // set horse
                if(kolom == 1 || kolom == 6)
                {
                    Paard* horse_z = new Paard(zwart);
                    setPiece(rij,kolom,horse_z);
                    horse_z->setTypePiece("Hb");
                }
                // set queen
                if(kolom == 3)
                {
                    Koningin* queen_z = new Koningin(zwart);
                    setPiece(rij,kolom,queen_z);
                    queen_z->setTypePiece("Qb");
                }
                // set king
                if(kolom == 4)
                {
                    Koning* king_z = new Koning(zwart);
                    setPiece(rij,kolom,king_z);
                    Black_King.setR(king_z->getR());
                    Black_King.setK(king_z->getK());
                    king_z->setTypePiece("Kb");
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
                    rook_w->setTypePiece("Rw");
                }
                // set bishop
                if(kolom == 2 || kolom == 5)
                {
                    Loper* bishop_w = new Loper(wit);
                    setPiece(rij,kolom,bishop_w);
                    bishop_w->setTypePiece("Bw");
                }
                // set horse
                if(kolom == 1 || kolom == 6)
                {
                    Paard* horse_w = new Paard(wit);
                    setPiece(rij,kolom,horse_w);
                    horse_w->setTypePiece("Hw");
                }
                // set queen
                if(kolom == 3)
                {
                    Koningin* queen_w = new Koningin(wit);
                    setPiece(rij,kolom,queen_w);
                    queen_w->setTypePiece("Qw");
                }
                // set king
                if(kolom == 4)
                {
                    Koning* king_w = new Koning(wit);
                    setPiece(rij,kolom,king_w);
                    White_king.setR(rij);
                    White_king.setK(kolom);
                    king_w->setTypePiece("Kw");
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
    // alle bedreigde plekken worden van de geldige zetten van de koning verwijdert
    if(s->getTypePiece() == "Kb" or s->getTypePiece() == "Kw"  ){
        vector<pair<int,int>> sq = this->King_Under_attack(s->getKleur());
        if (!this->King_Under_attack(s->getKleur()).empty())
        {
            if (!geldig_moves.empty()){
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
    }
    for(pair<int,int> moves : geldig_moves)
    {


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

// zelfde als move, maar dan maakt gebruikt van de data structuur copy
bool Game::move_copy(SchaakStuk* s,const int r,const int k) {
    pair<int,int> new_move = make_pair(r,k);
    vector<pair<int,int>> geldig_moves = s->geldige_zetten_copy(*this);
    if(s->getTypePiece() == "king"){
        vector<pair<int,int>> sq = this->King_Under_attack(s->getKleur());
        if (!this->King_Under_attack(s->getKleur()).empty())
        {
            if (!geldig_moves.empty()){
                for (auto coordinate : geldig_moves)
                {
                    for (auto it : sq){
                        if (it.first == coordinate.first and it.second == coordinate.second)
                        {
                            if (this->getPiece_copy(coordinate.first,coordinate.second) == nullptr)
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
    }
    for(pair<int,int> moves : geldig_moves)
    {

        if(new_move == moves){
            if (s->getKleur_copy() == zwart and s->getR_copy() == Black_King.getR_copy() and s->getK_copy() == Black_King.getK_copy())
            {
                this->setPiece_copy(s->getR_copy(),s->getK_copy(), nullptr);
                this->setPiece_copy(r,k,s);
                Black_King.setK_copy(k);
                Black_King.setR_copy(r);
                return true;
            }
            else if (s->getKleur_copy() == wit and s->getR_copy() == White_king.getR_copy() and s->getK_copy() == White_king.getK_copy())
            {
                this->setPiece_copy(s->getR_copy(),s->getK_copy(), nullptr);
                this->setPiece_copy(r,k,s);
                White_king.setK_copy(k);
                White_king.setR_copy(r);
                return true;
            }
            else
            {
                this->setPiece_copy(s->getR_copy(),s->getK_copy(), nullptr);
                this->setPiece_copy(r,k,s);
                return true;
            }
        }

    }
    return false;
}

// Kijk na of een zet mogelijk is zonder het te bewegen
bool Game::moveIsPossible(SchaakStuk *s, int r, int k)
{
    pair<int,int> new_move = make_pair(r,k);
    vector<pair<int,int>> geldig_moves = s->geldige_zetten(*this);
    if(s->getTypePiece() == "Kb" or s->getTypePiece() == "Kw"  ){
        vector<pair<int,int>> sq = this->King_Under_attack(s->getKleur());
        if (!this->King_Under_attack(s->getKleur()).empty())
        {
            if (!geldig_moves.empty()){
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
    }

    for(pair<int,int> moves : geldig_moves)
    {
        if(new_move == moves)
        {
            return true;
        }
    }
    return false;
}

// HulpFunctie Om te zien of de koning is Schaakmat staat
bool Game::NoMove(SchaakStuk *s)
{
    vector<pair<int,int>> geldig_moves = s->geldige_zetten(*this);
    vector<pair<int,int>> totaal = s->geldige_zetten(*this);
    if(s->getTypePiece() == "Kb" or s->getTypePiece() == "Kw"  ){
        vector<pair<int,int>> sq = this->King_Under_attack(s->getKleur());
        if (!this->King_Under_attack(s->getKleur()).empty())
        {
            if (!geldig_moves.empty()){
                for (auto coordinate : geldig_moves)
                {
                    if (this->getPiece(coordinate.first,coordinate.second) != nullptr)
                    {
                        for (int x=0;x<geldig_moves.size();x++)
                        {
                            if (geldig_moves[x] == coordinate and !geldig_moves.empty())
                            {
                                geldig_moves.erase(geldig_moves.begin()+x);
                            }
                        }
                    }
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

        for (auto it : totaal)
        {
            this->Make_copy();
            this->move_copy(s,it.first,it.second);
            if(!get<1>(this->schaak_copy(s->getKleur())))
            {
                geldig_moves.push_back(it);
            }
            delete_copy();
        }
    }


    if (geldig_moves.empty()){return true;}
    return false;
}

// Geeft true als kleur schaak staat
tuple<SchaakStuk*,bool> Game::schaak(const zw kleur) {
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
                       if (this->getPiece(move.first,move.second)->getTypePiece() == "Kb" or this->getPiece(move.first,move.second)->getTypePiece() == "Kw" and this->getPiece(move.first,move.second)->getKleur() == kleur)
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

// zelfde als schaak maar voor de datastructuur copy
tuple<SchaakStuk*,bool> Game::schaak_copy(const zw kleur) {
    for (int r=0;r <= 7;r++)
    {
        for (int k=0;k <= 7;k++)
        {
            if( this->getPiece_copy(r,k) == nullptr )
            {
                continue;
            }
            if (this->getPiece_copy(r,k)->getTypePiece() == "Qw")
            {
                //cout << "wit";
            }
            for (auto move : this->getPiece_copy(r,k)->geldige_zetten_copy(*this))
                {
                    if (this->getPiece_copy(move.first,move.second) != nullptr)
                    {

                        if (this->getPiece_copy(move.first,move.second)->getTypePieceCopy() == "Kb")
                        {
                            if(kleur != this->getPiece_copy(r,k)->getKleur_copy())
                            {
                                tuple<SchaakStuk*,bool> my_tuple = make_tuple(this->getPiece_copy(move.first,move.second),true);
                                return my_tuple;
                            }
                        }
                        if (this->getPiece_copy(move.first,move.second)->getTypePieceCopy() == "Kw")
                        {
                            if(kleur != this->getPiece_copy(r,k)->getKleur_copy())
                            {
                                tuple<SchaakStuk*,bool> my_tuple = make_tuple(this->getPiece_copy(move.first,move.second),true);
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
bool Game::schaakmat(const zw kleur) {
    bool result = get<1>(this->schaak(kleur));
    SchaakStuk* s = nullptr;
    if (result){
        bool size = get<0>(this->schaak(kleur))->geldige_zetten(*this).empty();
        s = get<0>(this->schaak(kleur));
    }

    if (result and this->NoMove(s))
    {
        return true;
    }
    else{return false;}
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool Game::pat(const zw kleur) {
    //cout << "in functie pat" << endl;
    if ((!get<1>(this->schaak(kleur))) and NoMove(get<0>(this->schaak(kleur))))
    {
        return true;
    }
    return false;
}

// Geeft een pointer naar het schaakstuk dat op rij r, kolom k staat
// Als er geen schaakstuk staat op deze positie, geef nullptr terug
SchaakStuk* Game::getPiece(const int r,const int k) const {
    // Hier komt jouw code om op te halen welk stuk op rij r, kolom k staat
    SchaakStuk* piece = bord[r][k];
    if (piece != nullptr)
    {
        return piece;
    }
    return nullptr;
}

// datastructuur copy
SchaakStuk* Game::getPiece_copy(const int r,const int k) const {
    // Hier komt jouw code om op te halen welk stuk op rij r, kolom k staat
    SchaakStuk* piece = copy[r][k];
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
void Game::setPiece(const int r,const int k, SchaakStuk* s)
{
    // Hier komt jouw code om een stuk neer te zetten op het bord
    this->bord[r][k] = s;

    if (s != nullptr){
        s->setK(k);
        s->setR(r);
    }
}

void Game::setPiece_copy(const int r,const int k, SchaakStuk* s)
{
    // Hier komt jouw code om een stuk neer te zetten op het bord
    this->copy[r][k] = s;

    if (s != nullptr){
        s->setK_copy(k);
        s->setR_copy(r);

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
                //all_moves.clear();
            }
        }
    }
    for (auto move : Square_under_attack)
    {
        //cout << "following square are under attack: (" << move.first << "," << move.second << ")";
    }
    return Square_under_attack;
}

// hulp functie om te zien welke square zijn bedreigd naast de king
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

// om te zien welke squares worden bedreigt
vector<pair<int,int>> Game::threatMap(const zw kleur)
{
    vector<pair<int,int>> threat;
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
           if (bord[i][j] != nullptr and bord[i][j]->getKleur() != kleur)
           {
               if (kleur == wit and not (outofBound(i+1,j+1) or outofBound(i+1,j-1)))
               {
                   threat.push_back(make_pair(i+1,j+1));
                   threat.push_back(make_pair(i+1,j-1));
               }
               else if (kleur == zwart and not (outofBound(i-1,j+1) or outofBound(i-1,j-1)))
               {
                   threat.push_back(make_pair(i-1,j+1));
                   threat.push_back(make_pair(i-1,j-1));
               }
               else{
                   for(auto move : bord[i][j]->geldige_zetten(*this)){
                       threat.push_back(move);
                   }
               }
           }
        }
    }
    return threat;
}

// Computer AI: Prioriteiten -> schaak,stuk slaan,random moves
// mag geen moves die eigen koning in schaak laat
// performatie is niet goed bij schaak,want er wordt een random move gedaan
// en dan gecheck of het nog in schaak is.

tuple<int,int,int,int> Game::AI()
{
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (bord[i][j] != nullptr){
                if(bord[i][j]->getKleur() == zwart)
                {
                    this->Make_copy();
                    for (auto move :this->getPiece_copy(i,j)->geldige_zetten_copy(*this))
                    {
                        this->move_copy(this->getPiece_copy(i,j),move.first,move.second);
                        if (get<1>(this->schaak_copy(wit)))
                        {
                            delete_copy();
                            //cout << i << " schaak  " << j << endl;
                            tuple<int,int,int,int> result = make_tuple(i,j,move.first,move.second);
                            return result;
                        }
                        else{
                            delete_copy();
                            Make_copy();}
                    }
                    delete_copy();
                }
            }
        }
    }
    Make_copy();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if (bord[i][j] != nullptr){
                if (this->getPiece_copy(i,j)->getKleur() == zwart){
                    for (auto move: this->getPiece_copy(i,j)->geldige_zetten_copy(*this))
                    {
                        if (this->getPiece_copy(move.first,move.second) != nullptr)
                        {
                            if (this->getPiece_copy(move.first,move.second)->getKleur() != zwart){
                                delete_copy();
                                //cout << i << "  d    " << j << endl;
                                tuple<int,int,int,int> result = make_tuple(i,j,move.first,move.second);
                                return result;
                            }
                        }
                        else{delete_copy();
                            Make_copy();}
                    }
                }
            }
        }
    }
    delete_copy();
    bool Not_moved = true;
    tuple<int,int,int,int> result;
    while(Not_moved)
        {
            int i = rand()%8;
            int j = rand()%8;

            if (bord[i][j] != nullptr and bord[i][j]->getKleur() ==zwart)
            {

                if (!bord[i][j]->geldige_zetten(*this).empty())
                {
                    result = make_tuple(i,j,bord[i][j]->geldige_zetten(*this)[0].first,bord[i][j]->geldige_zetten(*this)[0].second);
                    //cout << "computer moves from: (" << get<0>(result) << ", " << get<1>(result) << ") -> (" << get<2>(result) << ", "  << get<3>(result) << ")\n";
                    Not_moved = false;
                }
            }
            /*
            if (get<1>(this->schaak(zwart)))
            {
                i = get<1>(this->schaak(zwart));
                j = get<1>(this->schaak(zwart));
                result = make_tuple(i,j,bord[i][j]->geldige_zetten(*this)[0].first,bord[i][j]->geldige_zetten(*this)[0].second);
                return result;
            }
             */
        }
    return result;
}


// hulp functie om te zien of stuk kan worden geslaan
vector<pair<int,int>> Game::CanBeTaken(zw kleur)
{
    vector<pair<int,int>> result;
    for (int i=0;i<=7;i++)
    {
        for(int j=0;j<=7;j++)
        {
            if (bord[i][j] != nullptr)
            {
                if (bord[i][j]->getKleur() == kleur)
                {
                    for(auto it : bord[i][j]->geldige_zetten(*this))
                    {
                        if (bord[it.first][it.second] != nullptr)
                        {
                            if(bord[it.first][it.second]->getKleur() != kleur)
                            {
                                result.push_back(it);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}