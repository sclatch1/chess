//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "SchaakStuk.h"
#include "game.h"

vector<pair<int,int>> SchaakStuk::geldige_zetten(Game& game)
{
    vector<pair<int,int>> legal_moves;

    if (this == NULL)
    {
        return legal_moves;
    }
    pair<int,int> coordinates;
    pair<int,int> coordinates1;
    if (this->getKleur() == zwart)
    {
        coordinates = make_pair(this->r+1,this->k);
        coordinates1 = make_pair(this->r+2,this->k);
        legal_moves.push_back(coordinates);
        legal_moves.push_back(coordinates1);
    }
    else if (this->getKleur() == wit)
    {
        coordinates = make_pair(this->r-1,this->k);
        coordinates1 = make_pair(this->r-2,this->k);
        legal_moves.push_back(coordinates);
        legal_moves.push_back(coordinates1);
    }

    return legal_moves;
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
