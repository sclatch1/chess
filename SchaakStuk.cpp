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
    if (this->getTypePiece() == "horse")
    {
        int rij;
        int kolom;
        for (int i=1; i <= 8;i++)
        {
            switch (i) {
                case 1:
                    rij = this->r+2;
                    kolom = this->k+1;
                    break;
                    case 2:
                        rij = this->r+1;
                        kolom = this->k+2;
                        break;
                        case 3:
                            rij = this->r-1;
                            kolom = this->k+2;
                            break;
                            case 4:
                                rij = this->r-2;
                                kolom = this->k+1;
                                break;
                                case 5:
                                    rij = this->r-2;
                                    kolom = this->k-1;
                                    break;
                                    case 6:
                                        rij = this->r-1;
                                        kolom = this->k-2;
                                        break;
                                        case 7:
                                            rij = this->r+1;
                                            kolom = this->k-2;
                                            break;
                                            case 8:
                                                rij = this->r+2;
                                                kolom = this->k-1;
                                                break;
            }
            if (!outofBound(rij,kolom))
            {
                if(game.getPiece(rij,kolom) != nullptr)
                {
                    if(game.getPiece(rij,kolom)->getKleur() != kleur)
                    {
                        pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                        legal_moves.push_back(Horsecoordinates);
                    }
                }
                else{
                    pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Horsecoordinates);
                }
            }
        }
    }
    if(this->typePiece == "king")
    {
        int rij;
        int kolom;
        for (int i=1; i <= 8;i++)
        {
            switch (i)
            {
                case 1:
                    rij = this->r+1;
                    kolom = this->k+1;
                    break;
                    case 2:
                        rij = this->r;
                        kolom = this->k+1;
                        break;
                        case 3:
                            rij = this->r-1;
                            kolom = this->k+1;
                            break;
                            case 4:
                                rij = this->r-1;
                                kolom = this->k;
                                break;
                                case 5:
                                    rij = this->r-1;
                                    kolom = this->k-1;
                                    break;
                                    case 6:
                                        rij = this->r;
                                        kolom = this->k-1;
                                        break;
                                        case 7:
                                            rij = this->r+1;
                                            kolom = this->k-1;
                                            break;
                                            case 8:
                                                rij = this->r+1;
                                                kolom = this->k;
                                                break;
            }
            if (!outofBound(rij,kolom))
            {
                if(game.getPiece(rij,kolom) != nullptr)
                {
                    if (game.getPiece(rij,kolom)->getKleur() != kleur)
                    {
                        pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                        legal_moves.push_back(Kingcoordinates);
                    }
                }
                else{
                    pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Kingcoordinates);
                }
            }
        }
    }
    if (this->getTypePiece() == "pion"){

        pair<int,int> coordinates;
        pair<int,int> coordinates1;
        if (this->getKleur() == zwart)
        {
            if (this->getR() == 1){
            if(game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k))
            {
                    coordinates = make_pair(this->r+1,this->k);
                    coordinates1 = make_pair(this->r+2,this->k);
                    legal_moves.push_back(coordinates);
                    legal_moves.push_back(coordinates1);
                }
            }
            else if (game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k))
            {
                coordinates = make_pair(this->r+1,this->k);
                legal_moves.push_back(coordinates);
            }
            if(game.getPiece(r+1,k+1) != nullptr and!this->outofBound(r+1,k+1))
            {
                if (game.getPiece(r+1,k+1)->getKleur() != kleur)
                {
                    coordinates = make_pair(this->r+1,this->k+1);
                    legal_moves.push_back(coordinates);
                }
            }
            if(game.getPiece(r+1,k-1) != nullptr and!this->outofBound(r+1,k-1))
            {
                if (game.getPiece(r+1,k-1)->getKleur() != kleur)
                {
                    coordinates = make_pair(this->r+1,this->k-1);
                    legal_moves.push_back(coordinates);
                }
            }
        }

        else if (this->getKleur() == wit)
        {
            if(this->getR() == 6){
                if (game.getPiece(r-1,k) == nullptr && !this->outofBound(r-1,k))
                {
                    coordinates = make_pair(this->r-1,this->k);
                    coordinates1 = make_pair(this->r-2,this->k);
                    legal_moves.push_back(coordinates);
                    legal_moves.push_back(coordinates1);
                }
            }
            if(game.getPiece(r-1,k+1) != nullptr and!this->outofBound(r-1,k+1))
            {
                if (game.getPiece(r-1,k+1)->getKleur() != kleur)
                {
                    coordinates = make_pair(this->r-1,this->k+1);
                    legal_moves.push_back(coordinates);
                }
            }
            if(game.getPiece(r-1,k-1) != nullptr and!this->outofBound(r-1,k-1))
            {
                if (game.getPiece(r-1,k-1)->getKleur() != kleur)
                {
                    coordinates = make_pair(this->r-1,this->k-1);
                    legal_moves.push_back(coordinates);
                }
            }
            if (game.getPiece(r-1,k) == nullptr && !this->outofBound(r-1,k))
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
                if(game.getPiece(this->r+i,k)->getKleur() == kleur)
                {
                    blockedVerticalUp = true;
                }
                if(game.getPiece(this->r+i,k)->getKleur() != kleur and !blockedVerticalUp)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->r+i,this->k);
                    legal_moves.push_back(Rookcoordinates);
                    blockedVerticalUp = true;
                }
            }
            if (!outofBound(this->r+i,this->k) and !blockedVerticalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->r+i,this->k);
                legal_moves.push_back(Rookcoordinates);
            }
            if (!outofBound(this->r-i,k)){
                if(game.getPiece(this->r-i,k) != nullptr)
                {
                    if(game.getPiece(this->r-i,k)->getKleur() == kleur)
                    {
                        blockedVerticalDown = true;
                    }
                    if(game.getPiece(this->r-i,k)->getKleur() != kleur and !blockedVerticalDown)
                    {
                        pair<int,int> Rookcoordinates = make_pair(this->r-i,this->k);
                        legal_moves.push_back(Rookcoordinates);
                        blockedVerticalDown = true;
                    }
                }
                if (!blockedVerticalDown)
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
                    if(game.getPiece(this->r,k+j)->getKleur() == kleur)
                    {
                        blockedHorizontalUp = true;
                    }
                    if(game.getPiece(this->r,k+j)->getKleur() != kleur and !blockedHorizontalUp)
                    {
                        pair<int,int> Rookcoordinates = make_pair(this->r,this->k+j);
                        legal_moves.push_back(Rookcoordinates);
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
                    if(game.getPiece(this->r,k-j)->getKleur() == this->getKleur()){

                        blockedHorizontalDown = true;
                    }
                    if(game.getPiece(this->r,k-j)->getKleur() != kleur and !blockedHorizontalDown)
                    {
                        pair<int,int> Rookcoordinates = make_pair(this->r,this->k-j);
                        legal_moves.push_back(Rookcoordinates);
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
                    if (game.getPiece(this->r+i,k+i)->getKleur() == kleur)
                    {
                        blockedUpRight = true;
                    }
                    if (game.getPiece(this->r+i,k+i)->getKleur() != kleur and !blockedUpRight)
                    {
                        pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k+i);
                        legal_moves.push_back(Bishopcoordinates);
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
                    if (game.getPiece(this->r-i,k-i)->getKleur() != kleur and !blockedDownLeft)
                    {
                        pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k-i);
                        legal_moves.push_back(Bishopcoordinates);
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
                    if (game.getPiece(this->r+i,k-i)->getKleur() != kleur and !blockedUpLeft)
                    {
                        pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k-i);
                        legal_moves.push_back(Bishopcoordinates);
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
                    if (game.getPiece(this->r-i,k+i)->getKleur() != kleur and !blockedDownRight)
                    {
                        pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k+i);
                        legal_moves.push_back(Bishopcoordinates);
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
    else{return legal_moves;}

    return legal_moves;

}



bool SchaakStuk::outofBound(int rij,int kolom) const
{

    if ((0 <= rij) && (rij < 8) && (0 <= kolom) && (kolom < 8)){return false;}
    else{return true;}
}



int SchaakStuk::getR() const {
    return r;
}

void SchaakStuk::setR(int rij) {
    SchaakStuk::r = rij;
}

int SchaakStuk::getK() const {
    return k;
}

void SchaakStuk::setK(int kolom) {
    SchaakStuk::k = kolom;
}

const string &SchaakStuk::getTypePiece() const {
    return typePiece;
}

void SchaakStuk::setTypePiece(const string &typepiece) {
    SchaakStuk::typePiece = typepiece;
}
