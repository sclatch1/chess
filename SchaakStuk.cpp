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

    if (this == NULL)
    {
        return legal_moves;
    }
    pair<int,int> coordinates;
    pair<int,int> coordinates1;
    if (this->getTypePiece() == "pion"){

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
    if (this->getTypePiece() == "rook")
    {
        for (int i=0; i <= 7; i++)
        {
            //if (game.getPiece(i,this->k) != nullptr){break;}
            if (i != this->getR() and !outofBound(i,this->k))
            {
                pair<int,int> Rookcoordinates = make_pair(i,this->k);
                legal_moves.push_back(Rookcoordinates);
            }
        }
        for (int j=0; j <= 7;j++)
        {
            //if (game.getPiece(this->r,j) != nullptr){break;}
            if (j != this->k)
            {
                pair<int,int> Rookcoordinates = make_pair(this->r,j);
                legal_moves.push_back(Rookcoordinates);
            }
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
