//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "SchaakStuk.h"
#include "game.h"
#include <iostream>

using namespace std;

vector<pair<int,int>> SchaakStuk::geldige_zetten(Game& game)
{
    vector<pair<int,int>> legal_moves;
    bool isQueen = false;


    if(this->getTypePiece() == "queen")
    {
        isQueen = true;
    }
    if (this->getTypePiece() == "pion"){

        pair<int,int> coordinates;
        pair<int,int> coordinates1;
        if (this->getKleur() == zwart)
        {
            if (this->getR() == 1){
            //game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k)
            if(game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k))
            {
                    coordinates = make_pair(this->r+1,this->k);
                    coordinates1 = make_pair(this->r+2,this->k);
                    legal_moves.push_back(coordinates);
                    legal_moves.push_back(coordinates1);
                    cout << legal_moves.size() << endl;
                }
            }
            else
            {
                coordinates = make_pair(this->r+1,this->k);
                legal_moves.push_back(coordinates);
            }
        }

        else if (this->getKleur() == wit)
        {
            if(this->getR() == 6){
                if (game.getPiece(r-1,k) == nullptr && !this->outofBound(r+1,k))
                {
                    coordinates = make_pair(this->r-1,this->k);
                    coordinates1 = make_pair(this->r-2,this->k);
                    legal_moves.push_back(coordinates);
                    legal_moves.push_back(coordinates1);
                }
            }
            else
            {
                coordinates = make_pair(this->r-1,this->k);
                legal_moves.push_back(coordinates);
            }
        }
    }
    if (this->getTypePiece() == "rook" or isQueen)
    {
        bool blockedVerticalUp = false;
        bool blockedVerticalDown = false;
        bool blockedHorizontalUp = false;
        bool blockedHorizontalDown = false;
        for (int i=1; i <= 9; i++)
        {
            if(game.getPiece(this->r+i,k) != nullptr and !outofBound(this->r+i,k))
            {
                if(game.getPiece(this->r+i,k)->getKleur() == kleur){

                    blockedVerticalUp = true;
                }
            }
            if (i != this->getR() and !outofBound(this->r+i,this->k) and !blockedVerticalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->r+i,this->k);
                legal_moves.push_back(Rookcoordinates);
            }
            if (!outofBound(this->r-i,k)){
                if(game.getPiece(this->r-i,k) != nullptr)
                {
                    if(game.getPiece(this->r-i,k)->getKleur() == kleur){
                        blockedVerticalDown = true;
                    }
                }
                if (i != this->getR() and !blockedVerticalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->r-i,this->k);
                    legal_moves.push_back(Rookcoordinates);
                }
            }
        }
        for (int j=1; j <= 9;j++)
        {
            if (!outofBound(this->r,k+j)){
                if(game.getPiece(this->r,k+j) != nullptr)
                {
                    if(game.getPiece(this->r,k+j)->getKleur() == kleur){
                        blockedHorizontalUp = true;
                    }
                }
                if (!blockedHorizontalUp)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->r,this->k+j);
                    legal_moves.push_back(Rookcoordinates);
                }
            }
            if (!outofBound(this->r,this->k-j)){
                if(game.getPiece(this->r,k-j) != nullptr)
                {
                    if(game.getPiece(this->r,k-j)->getKleur() != this->getKleur()){

                        blockedHorizontalDown = true;
                    }
                }
                if (!blockedHorizontalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->r,this->k-j);
                    legal_moves.push_back(Rookcoordinates);
                }
            }
        }
    }
    if (this->getTypePiece() == "bishop" or isQueen)
    {
        bool blockedUpRight = false;
        bool blockedUpLeft = false;
        bool blockedDownRight = false;
        bool blockedDownLeft = false;

        for (int i=1; i <= 9; i++)
        {
            if(!outofBound(this->r+i,k+i)){

                if(game.getPiece(this->r+i,k+i) != nullptr)
                {
                    if (game.getPiece(this->r+i,k+i)->getKleur() == kleur){
                        blockedUpRight = true;
                    }
                }
                if (!blockedUpRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k+i);
                    legal_moves.push_back(Bishopcoordinates);
                }
            }

            if(!outofBound(this->r-i,k-i)){
                if(game.getPiece(this->r-i,k-i) != nullptr)
                {
                    if (game.getPiece(this->r-i,k-i)->getKleur() == kleur){
                        blockedDownLeft = true;
                    }
                }
                if (!blockedDownLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k-i);
                    legal_moves.push_back(Bishopcoordinates);
                }
            }

            if(!outofBound(this->r+i,k-i)){
                if(game.getPiece(this->r+i,k-i) != nullptr)
                {
                    if (game.getPiece(this->r+i,k-i)->getKleur() == kleur){
                        blockedUpLeft = true;
                    }
                }
                if (!blockedUpLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k-i);
                    legal_moves.push_back(Bishopcoordinates);
                }
            }

            if(!outofBound(this->r-i,k+i)){
                if(game.getPiece(this->r-i,k+i) != nullptr)
                {
                    if (game.getPiece(this->r-i,k+i)->getKleur() == kleur){
                        blockedDownRight = true;
                    }
                }
                if (!blockedDownRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k+i);
                    legal_moves.push_back(Bishopcoordinates);
                }
            }
        }
    }
    if (this->getTypePiece() == "horse")
    {
        if (!outofBound(r+2,k+1))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r+2,this->k+1);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r+1,k+2))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r+1,this->k+2);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r-1,k+2))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r-1,this->k+2);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r-2,k+1))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r-2,this->k+1);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r-2,k-1))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r-2,this->k-1);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r-1,k-2))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r-1,this->k-2);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r+1,k-2))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r+1,this->k-2);
            legal_moves.push_back(Horsecoordinates);
        }
        if (!outofBound(r+2,k-1))
        {
            pair<int,int> Horsecoordinates = make_pair(this->r+2,this->k-1);
            legal_moves.push_back(Horsecoordinates);
        }
    }
    else{return legal_moves;}

    return legal_moves;
}


bool SchaakStuk::outofBound(int rij,int kolom) const
{

    if ((0 <= rij) && (rij < 8) && (0 <= kolom) && (kolom < 8)){return false;}
    else{return true;}
}

bool SchaakStuk::Blocked(Game &g,SchaakStuk &s)
{

}

int SchaakStuk::getR() const {
    return r;
}

void SchaakStuk::setR(int r) {
    SchaakStuk::r = r;
}

int SchaakStuk::getK() const {
    return k;
}

void SchaakStuk::setK(int k) {
    SchaakStuk::k = k;
}

const string &SchaakStuk::getTypePiece() const {
    return typePiece;
}

void SchaakStuk::setTypePiece(const string &typePiece) {
    SchaakStuk::typePiece = typePiece;
}
