//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "SchaakStuk.h"
#include "game.h"
#include <iostream>

using namespace std;


// next 2 functions
// this function helps with checking for pinned piece and put all the moves the piece can do,
// as if the board is clear of other pieces


vector<pair<int,int>> SchaakStuk::line_of_sight_rook(Game &game)
{
    vector<pair<int,int>> legal_moves;
    if (this->getTypePiece() == "rook")
    {
        for (int i=1; i <= 9; i++)
        {

            if (!outofBound(this->r+i,this->k))
            {
                pair<int,int> Rookcoordinates = make_pair(this->r+i,this->k);
                legal_moves.push_back(Rookcoordinates);
            }
            if (!outofBound(this->r-i,k)){

                pair<int,int> Rookcoordinates = make_pair(this->r-i,this->k);
                legal_moves.push_back(Rookcoordinates);

            }
        }
        for (int j=1; j <= 9;j++)
        {
            if (!outofBound(this->r,k+j)){

                pair<int,int> Rookcoordinates = make_pair(this->r,this->k+j);
                legal_moves.push_back(Rookcoordinates);

            }
            if (!outofBound(this->r,this->k-j)){

                pair<int,int> Rookcoordinates = make_pair(this->r,this->k-j);
                legal_moves.push_back(Rookcoordinates);

            }
        }
    }
    return legal_moves;
}

vector<pair<int,int>> SchaakStuk::line_of_sight_bishop(Game &game)
{
    vector<pair<int,int>> legal_moves;
    if (this->getTypePiece() == "bishop")
    {
        for (int i=1; i <= 9; i++)
        {
            if(!outofBound(this->r+i,k+i)){

                pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k+i);
                legal_moves.push_back(Bishopcoordinates);

            }

            if(!outofBound(this->r-i,k-i)){

                pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k-i);
                legal_moves.push_back(Bishopcoordinates);

            }

            if(!outofBound(this->r+i,k-i)){

                pair<int,int> Bishopcoordinates = make_pair(this->r+i,this->k-i);
                legal_moves.push_back(Bishopcoordinates);

            }

            if(!outofBound(this->r-i,k+i)){

                pair<int,int> Bishopcoordinates = make_pair(this->r-i,this->k+i);
                legal_moves.push_back(Bishopcoordinates);

            }

        }
    }
    return legal_moves;
}

bool SchaakStuk::outofBound(int rij,int kolom)
{
    // checking if the coordinates is within the board
    if ((0 <= rij) && (rij < 8) && (0 <= kolom) && (kolom < 8)){return false;}
    else{return true;}
}




vector<pair<int, int>> SchaakStuk::geldige_zetten_toren(const Game &game) const
{
    vector<pair<int, int>> legal_moves;
    bool blockedVerticalUp = false;
    bool blockedVerticalDown = false;
    bool blockedHorizontalUp = false;
    bool blockedHorizontalDown = false;
    // rooks have a sliding motion and thus we have to loop over multiple possible square
    // we also need to check if it's block by own color pieces and can't move further
    // or by enemy piece that can be attacked but then can't move further
    // rooks moves vertical or horizontal
    for (int i=1; i <= 8; i++)
    {
        // check if it's within boundaries and not an empty square
        if(game.getPiece(this->getR()+i,this->getK()) != nullptr and !outofBound(this->getR()+i,this->getK()))
        {
            // if it's the same color it can move further
            if(game.getPiece(this->getR()+i,this->getK())->getKleur() == this->getKleur())
            {
                blockedVerticalUp = true;
            }
            // enemy piece can be eaten and can't move any further
            if(game.getPiece(this->getR()+i,this->getK())->getKleur() != this->getKleur() and !blockedVerticalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR()+i,this->getK());
                legal_moves.push_back(Rookcoordinates);
                blockedVerticalUp = true;
            }
        }
        if (!outofBound(this->getR()+i,this->getK()) and !blockedVerticalUp)
        {
            pair<int,int> Rookcoordinates = make_pair(this->getR()+i,this->getK());
            legal_moves.push_back(Rookcoordinates);
        }
        // same for the other dierections
        if (!outofBound(this->getR()-i,this->getK())){
            if(game.getPiece(this->getR()-i,this->getK()) != nullptr)
            {
                if(game.getPiece(this->getR()-i,this->getK())->getKleur() == this->getKleur())
                {
                    blockedVerticalDown = true;
                }
                if(game.getPiece(this->getR()-i,this->getK())->getKleur() != this->getKleur() and !blockedVerticalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR()-i,this->getK());
                    legal_moves.push_back(Rookcoordinates);
                    blockedVerticalDown = true;
                }
            }
            if (!blockedVerticalDown)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR()-i,this->getK());
                legal_moves.push_back(Rookcoordinates);
            }
        }
    }
    for (int j=1; j <= 8;j++)
    {
        if (!outofBound(this->getR(),this->getK()+j)){
            if(game.getPiece(this->getR(),this->getK()+j) != nullptr)
            {
                if(game.getPiece(this->getR(),this->getK()+j)->getKleur() == this->getKleur())
                {
                    blockedHorizontalUp = true;
                }
                if(game.getPiece(this->getR(),this->getK()+j)->getKleur() != this->getKleur() and !blockedHorizontalUp)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR(),this->getK()+j);
                    legal_moves.push_back(Rookcoordinates);
                    blockedHorizontalUp = true;
                }
            }
            if (!blockedHorizontalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR(),this->getK()+j);
                legal_moves.push_back(Rookcoordinates);
            }
        }
        if (!outofBound(this->getR(),this->getK()-j)){
            if(game.getPiece(this->getR(),this->getK()-j) != nullptr)
            {
                if(game.getPiece(this->getR(),this->getK()-j)->getKleur() == this->getKleur()){

                    blockedHorizontalDown = true;
                }
                if(game.getPiece(this->getR(),this->getK()-j)->getKleur() != this->getKleur() and !blockedHorizontalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR(),this->getK()-j);
                    legal_moves.push_back(Rookcoordinates);
                    blockedHorizontalDown = true;
                }
            }
            if (!blockedHorizontalDown)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR(),this->getK()-j);
                legal_moves.push_back(Rookcoordinates);
            }
        }
    }
    return legal_moves;
}



vector<pair<int, int>> Toren::geldige_zetten(const Game &game) const{
    return SchaakStuk::geldige_zetten_toren(game);

}

vector<pair<int, int>> SchaakStuk::geldige_zetten_loper(const Game &game) const{
    vector<pair<int, int>> legal_moves;
    bool blockedUpRight = false;
    bool blockedUpLeft = false;
    bool blockedDownRight = false;
    bool blockedDownLeft = false;
    // bishops have a sliding motion and thus we have to loop over multiple possible square
    // we also need to check if it's block by own color pieces and can't move further
    // or by enemy piece that can be attacked but then can't move any further
    // bishop move on the diagonal and can consequently not change color of square
    // same principle as the rook
    for (int i=1; i <= 8; i++)
    {
        if(!outofBound(this->getR()+i,this->getK()+i)){

            if(game.getPiece(this->getR()+i,this->getK()+i) != nullptr)
            {
                if (game.getPiece(this->getR()+i,this->getK()+i)->getKleur() == this->getKleur())
                {
                    blockedUpRight = true;
                }
                if (game.getPiece(this->getR()+i,this->getK()+i)->getKleur() != this->getKleur() and !blockedUpRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR()+i,this->getK()+i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedUpRight = true;
                }
            }
            if (!blockedUpRight)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR()+i,this->getK()+i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR()-i,this->getK()-i)){
            if(game.getPiece(this->getR()-i,this->getK()-i) != nullptr)
            {
                if (game.getPiece(this->getR()-i,this->getK()-i)->getKleur() == this->getKleur()){
                    blockedDownLeft = true;
                }
                if (game.getPiece(this->getR()-i,this->getK()-i)->getKleur() != this->getKleur() and !blockedDownLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR()-i,this->getK()-i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedDownLeft = true;
                }
            }
            if (!blockedDownLeft)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR()-i,this->getK()-i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR()+i,this->getK()-i)){
            if(game.getPiece(this->getR()+i,this->getK()-i) != nullptr)
            {
                if (game.getPiece(this->getR()+i,this->getK()-i)->getKleur() == this->getKleur()){
                    blockedUpLeft = true;
                }
                if (game.getPiece(this->getR()+i,this->getK()-i)->getKleur() != this->getKleur() and !blockedUpLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR()+i,this->getK()-i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedUpLeft = true;
                }
            }
            if (!blockedUpLeft)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR()+i,this->getK()-i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR()-i,this->getK()+i)){
            if(game.getPiece(this->getR()-i,this->getK()+i) != nullptr)
            {
                if (game.getPiece(this->getR()-i,this->getK()+i)->getKleur() == this->getKleur()){
                    blockedDownRight = true;
                }
                if (game.getPiece(this->getR()-i,this->getK()+i)->getKleur() != this->getKleur() and !blockedDownRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR()-i,this->getK()+i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedDownRight = true;
                }
            }
            if (!blockedDownRight)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR()-i,this->getK()+i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

    }
    return legal_moves;
}

vector<pair<int, int>> Loper::geldige_zetten(const Game &game) const{
    return SchaakStuk::geldige_zetten_loper(game);
}

vector<pair<int, int>> Paard::geldige_zetten(const Game &game)  const
{
    int rij;
    int kolom;
    // there are max 8 position a horse can jump to within the designated boundaries
    vector<pair<int,int>> legal_moves;
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
            // check if it's out of boundaries
            if (!outofBound(rij,kolom))
            {
                if(game.getPiece(rij,kolom) != nullptr)
                {
                    // if it's a piece of the other color it can be eaten
                    if(game.getPiece(rij,kolom)->getKleur() != kleur)
                    {
                        pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                        legal_moves.push_back(Horsecoordinates);
                    }
                }
                // else empty square
                else{
                    pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Horsecoordinates);
                }
            }
        }
    return legal_moves;
}

vector<pair<int, int>> Pion::geldige_zetten(const Game &game) const {

    vector<pair<int,int>> legal_moves;
    pair<int,int> coordinates;
    pair<int,int> coordinates1;
    if (this->getKleur() == zwart)
        {
            if (this->getR() == 1){
                // from the starting square a pion can move 1 or 2 square
                if(game.getPiece(r+1,k) == nullptr and game.getPiece(r+2,k) == nullptr && !this->outofBound(r+1,k))
                {
                    coordinates = make_pair(this->r+1,this->k);
                    coordinates1 = make_pair(this->r+2,this->k);
                    legal_moves.push_back(coordinates);
                    legal_moves.push_back(coordinates1);
                }
                else if (game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k))
                {
                    coordinates = make_pair(this->r+1,this->k);
                    legal_moves.push_back(coordinates);
                }
            }
            // else the pion can move one square
            else if (game.getPiece(r+1,k) == nullptr && !this->outofBound(r+1,k))
            {
                coordinates = make_pair(this->r+1,this->k);
                legal_moves.push_back(coordinates);
            }
            // if there is an enemy piece left up or right up, than that piece can be attack
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
            // same but for white piece
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
        return legal_moves;
}

vector<pair<int, int>> Koning::geldige_zetten(const Game &game) const
{
    int rij;
    int kolom;
    vector<pair<int, int>> legal_moves;
    for (int i=1; i <= 8;i++)
        {
            // max 8 possible position a position can move to
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
            // check for out of boundary
            if (!outofBound(rij,kolom))
            {
                if(game.getPiece(rij,kolom) != nullptr)
                {
                    // if it's an other color, it can be eaten
                    if (game.getPiece(rij,kolom)->getKleur() != kleur)
                    {
                        pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                        legal_moves.push_back(Kingcoordinates);
                    }
                }
                // empty square
                else{
                    pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Kingcoordinates);
                }
            }
        }
    return legal_moves;
}

vector<pair<int, int>> Koningin::geldige_zetten(const Game &game) const {
    auto legal_moves = SchaakStuk::geldige_zetten_toren(game);
    for (auto move: SchaakStuk::geldige_zetten_loper(game))
    {
        legal_moves.push_back(move);
    }
    return legal_moves;
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

void SchaakStuk::setKleur(const zw &kleur_)
{
    kleur = kleur_;
}

const string &SchaakStuk::getTypePiece() const {
    return typePiece;
}

void SchaakStuk::setTypePiece(const string &typepiece) {
    SchaakStuk::typePiece = typepiece;
}



////////////////////////
//COPY FUNCTIONS
///////////////////////

int SchaakStuk::getR_copy() const {
    return r_copy;
}

void SchaakStuk::setR_copy(int rij) {
    SchaakStuk::r_copy = rij;
}

int SchaakStuk::getK_copy() const {
    return k_copy;
}

void SchaakStuk::setK_copy(int kolom) {
    SchaakStuk::k_copy = kolom;
}

vector<pair<int, int>> SchaakStuk::geldige_zetten_toren_copy(const Game &game) const
{
    vector<pair<int, int>> legal_moves;
    bool blockedVerticalUp = false;
    bool blockedVerticalDown = false;
    bool blockedHorizontalUp = false;
    bool blockedHorizontalDown = false;
    // rooks have a sliding motion and thus we have to loop over multiple possible square
    // we also need to check if it's block by own color pieces and can't move further
    // or by enemy piece that can be attacked but then can't move further
    // rooks moves vertical or horizontal
    for (int i=1; i <= 8; i++)
    {
        // check if it's within boundaries and not an empty square
        if(game.getPiece_copy(this->getR_copy()+i,this->getK_copy()) != nullptr and !outofBound(this->getR_copy()+i,this->getK_copy()))
        {
            // if it's the same color it can move further
            if(game.getPiece_copy(this->getR_copy()+i,this->getK_copy())->getKleur_copy() == this->getKleur_copy())
            {
                blockedVerticalUp = true;
            }
            // enemy piece can be eaten and can't move any further
            if(game.getPiece_copy(this->getR_copy()+i,this->getK_copy())->getKleur_copy() != this->getKleur_copy() and !blockedVerticalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR_copy()+i,this->getK_copy());
                legal_moves.push_back(Rookcoordinates);
                blockedVerticalUp = true;
            }
        }
        if (!outofBound(this->getR_copy()+i,this->getK_copy()) and !blockedVerticalUp)
        {
            pair<int,int> Rookcoordinates = make_pair(this->getR_copy()+i,this->getK_copy());
            legal_moves.push_back(Rookcoordinates);
        }
        // same for the other dierections
        if (!outofBound(this->getR_copy()-i,this->getK_copy())){
            if(game.getPiece_copy(this->getR_copy()-i,this->getK_copy()) != nullptr)
            {
                if(game.getPiece_copy(this->getR_copy()-i,this->getK_copy())->getKleur_copy() == this->getKleur_copy())
                {
                    blockedVerticalDown = true;
                }
                if(game.getPiece_copy(this->getR_copy()-i,this->getK_copy())->getKleur_copy() != this->getKleur_copy() and !blockedVerticalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR_copy()-i,this->getK_copy());
                    legal_moves.push_back(Rookcoordinates);
                    blockedVerticalDown = true;
                }
            }
            if (!blockedVerticalDown)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR_copy()-i,this->getK_copy());
                legal_moves.push_back(Rookcoordinates);
            }
        }
    }
    for (int j=1; j <= 8;j++)
    {
        if (!outofBound(this->getR_copy(),this->getK_copy()+j)){
            if(game.getPiece_copy(this->getR_copy(),this->getK_copy()+j) != nullptr)
            {
                if(game.getPiece_copy(this->getR_copy(),this->getK_copy()+j)->getKleur_copy() == this->getKleur_copy())
                {
                    blockedHorizontalUp = true;
                }
                if(game.getPiece_copy(this->getR_copy(),this->getK_copy()+j)->getKleur_copy() != this->getKleur_copy() and !blockedHorizontalUp)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR_copy(),this->getK_copy()+j);
                    legal_moves.push_back(Rookcoordinates);
                    blockedHorizontalUp = true;
                }
            }
            if (!blockedHorizontalUp)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR_copy(),this->getK_copy()+j);
                legal_moves.push_back(Rookcoordinates);
            }
        }
        if (!outofBound(this->getR_copy(),this->getK_copy()-j)){
            if(game.getPiece_copy(this->getR_copy(),this->getK_copy()-j) != nullptr)
            {
                if(game.getPiece_copy(this->getR_copy(),this->getK_copy()-j)->getKleur_copy() == this->getKleur_copy()){

                    blockedHorizontalDown = true;
                }
                if(game.getPiece_copy(this->getR_copy(),this->getK_copy()-j)->getKleur_copy() != this->getKleur_copy() and !blockedHorizontalDown)
                {
                    pair<int,int> Rookcoordinates = make_pair(this->getR_copy(),this->getK_copy()-j);
                    legal_moves.push_back(Rookcoordinates);
                    blockedHorizontalDown = true;
                }
            }
            if (!blockedHorizontalDown)
            {
                pair<int,int> Rookcoordinates = make_pair(this->getR_copy(),this->getK_copy()-j);
                legal_moves.push_back(Rookcoordinates);
            }
        }
    }
    return legal_moves;
}



vector<pair<int, int>> Toren::geldige_zetten_copy(const Game &game) const{
    return SchaakStuk::geldige_zetten_toren_copy(game);

}

vector<pair<int, int>> SchaakStuk::geldige_zetten_loper_copy(const Game &game) const{
    vector<pair<int, int>> legal_moves;
    bool blockedUpRight = false;
    bool blockedUpLeft = false;
    bool blockedDownRight = false;
    bool blockedDownLeft = false;
    // bishops have a sliding motion and thus we have to loop over multiple possible square
    // we also need to check if it's block by own color pieces and can't move further
    // or by enemy piece that can be attacked but then can't move any further
    // bishop move on the diagonal and can consequently not change color of square
    // same principle as the rook
    for (int i=1; i <= 8; i++)
    {
        if(!outofBound(this->getR_copy()+i,this->getK_copy()+i)){

            if(game.getPiece_copy(this->getR_copy()+i,this->getK_copy()+i) != nullptr)
            {
                if (game.getPiece_copy(this->getR_copy()+i,this->getK_copy()+i)->getKleur_copy() == this->getKleur_copy())
                {
                    blockedUpRight = true;
                }
                if (game.getPiece_copy(this->getR_copy()+i,this->getK_copy()+i)->getKleur_copy() != this->getKleur_copy() and !blockedUpRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()+i,this->getK_copy()+i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedUpRight = true;
                }
            }
            if (!blockedUpRight)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()+i,this->getK_copy()+i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR_copy()-i,this->getK_copy()-i)){
            if(game.getPiece_copy(this->getR_copy()-i,this->getK_copy()-i) != nullptr)
            {
                if (game.getPiece_copy(this->getR_copy()-i,this->getK_copy()-i)->getKleur_copy() == this->getKleur_copy()){
                    blockedDownLeft = true;
                }
                if (game.getPiece_copy(this->getR_copy()-i,this->getK_copy()-i)->getKleur_copy() != this->getKleur_copy() and !blockedDownLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()-i,this->getK_copy()-i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedDownLeft = true;
                }
            }
            if (!blockedDownLeft)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()-i,this->getK_copy()-i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR_copy()+i,this->getK_copy()-i)){
            if(game.getPiece_copy(this->getR_copy()+i,this->getK_copy()-i) != nullptr)
            {
                if (game.getPiece_copy(this->getR_copy()+i,this->getK_copy()-i)->getKleur_copy() == this->getKleur_copy()){
                    blockedUpLeft = true;
                }
                if (game.getPiece_copy(this->getR_copy()+i,this->getK_copy()-i)->getKleur_copy() != this->getKleur_copy() and !blockedUpLeft)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()+i,this->getK_copy()-i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedUpLeft = true;
                }
            }
            if (!blockedUpLeft)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()+i,this->getK_copy()-i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

        if(!outofBound(this->getR_copy()-i,this->getK_copy()+i)){
            if(game.getPiece_copy(this->getR_copy()-i,this->getK_copy()+i) != nullptr)
            {
                if (game.getPiece_copy(this->getR_copy()-i,this->getK_copy()+i)->getKleur_copy() == this->getKleur_copy()){
                    blockedDownRight = true;
                }
                if (game.getPiece_copy(this->getR_copy()-i,this->getK_copy()+i)->getKleur_copy() != this->getKleur_copy() and !blockedDownRight)
                {
                    pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()-i,this->getK_copy()+i);
                    legal_moves.push_back(Bishopcoordinates);
                    blockedDownRight = true;
                }
            }
            if (!blockedDownRight)
            {
                pair<int,int> Bishopcoordinates = make_pair(this->getR_copy()-i,this->getK_copy()+i);
                legal_moves.push_back(Bishopcoordinates);
            }
        }

    }
    return legal_moves;
}

const string &SchaakStuk::getTypePieceCopy() const {
    return typePiece_copy;
}

void SchaakStuk::setTypePieceCopy(const string &typePieceCopy) {
    typePiece_copy = typePieceCopy;
}

zw SchaakStuk::getKleur_copy() const {
    return kleur_copy;
}

void SchaakStuk::setKleur_copy(zw kleurCopy) {
    kleur_copy = kleurCopy;
}

vector<pair<int, int>> Loper::geldige_zetten_copy(const Game &game) const{
    return SchaakStuk::geldige_zetten_loper_copy(game);
}

vector<pair<int, int>> Paard::geldige_zetten_copy(const Game &game)  const
{
    int rij;
    int kolom;
    // there are max 8 position a horse can jump to within the designated boundaries
    vector<pair<int,int>> legal_moves;
    for (int i=1; i <= 8;i++)
    {
        switch (i) {
            case 1:
                rij = this->r_copy+2;
                kolom = this->k_copy+1;
                break;
                case 2:
                    rij = this->r_copy+1;
                    kolom = this->k_copy+2;
                    break;
                    case 3:
                        rij = this->r_copy-1;
                        kolom = this->k_copy+2;
                        break;
                        case 4:
                            rij = this->r_copy-2;
                            kolom = this->k_copy+1;
                            break;
                            case 5:
                                rij = this->r_copy-2;
                                kolom = this->k_copy-1;
                                break;
                                case 6:
                                    rij = this->r_copy-1;
                                    kolom = this->k_copy-2;
                                    break;
                                    case 7:
                                        rij = this->r_copy+1;
                                        kolom = this->k_copy-2;
                                        break;
                                        case 8:
                                            rij = this->r_copy+2;
                                            kolom = this->k_copy-1;
                                            break;
        }
        // check if it's out of boundaries
        if (!outofBound(rij,kolom))
        {
            if(game.getPiece_copy(rij,kolom) != nullptr)
            {
                // if it's a piece of the other color it can be eaten
                if(game.getPiece_copy(rij,kolom)->getKleur_copy() != kleur_copy)
                {
                    pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Horsecoordinates);
                }
            }
            // else empty square
            else{
                pair<int,int> Horsecoordinates = make_pair(rij,kolom);
                legal_moves.push_back(Horsecoordinates);
            }
        }
    }
    return legal_moves;
}

vector<pair<int, int>> Pion::geldige_zetten_copy(const Game &game) const {

    vector<pair<int,int>> legal_moves;
    pair<int,int> coordinates;
    pair<int,int> coordinates1;
    if (this->getKleur_copy() == zwart)
    {
        if (this->getR_copy() == 1){
            // from the starting square a pion can move 1 or 2 square
            if(game.getPiece_copy(r_copy+1,k_copy) == nullptr && !this->outofBound(r_copy+1,k_copy))
            {
                coordinates = make_pair(this->r_copy+1,this->k_copy);
                coordinates1 = make_pair(this->r_copy+2,this->k_copy);
                legal_moves.push_back(coordinates);
                legal_moves.push_back(coordinates1);
            }
        }
        // else the pion can move one square
        else if (game.getPiece_copy(r_copy+1,k_copy) == nullptr && !this->outofBound(r_copy+1,k_copy))
        {
            coordinates = make_pair(this->r_copy+1,this->k_copy);
            legal_moves.push_back(coordinates);
        }
        // if there is an enemy piece left up or right up, than that piece can be attack
        if(game.getPiece_copy(r_copy+1,k_copy+1) != nullptr and!this->outofBound(r_copy+1,k_copy+1))
        {
            if (game.getPiece_copy(r_copy+1,k_copy+1)->getKleur_copy() != kleur_copy)
            {
                coordinates = make_pair(this->r_copy+1,this->k_copy+1);
                legal_moves.push_back(coordinates);
            }
        }
        if(game.getPiece_copy(r_copy+1,k_copy-1) != nullptr and!this->outofBound(r_copy+1,k_copy-1))
        {
            if (game.getPiece_copy(r_copy+1,k_copy-1)->getKleur_copy() != kleur_copy)
            {
                coordinates = make_pair(this->r_copy+1,this->k_copy-1);
                legal_moves.push_back(coordinates);
            }
        }
    }

    else if (this->getKleur_copy() == wit)
    {
        // same but for white piece
        if(this->getR_copy() == 6){
            if (game.getPiece_copy(r_copy-1,k_copy) == nullptr && !this->outofBound(r_copy-1,k_copy))
            {
                coordinates = make_pair(this->r_copy-1,this->k_copy);
                coordinates1 = make_pair(this->r_copy-2,this->k_copy);
                legal_moves.push_back(coordinates);
                legal_moves.push_back(coordinates1);
            }
        }
        if(game.getPiece_copy(r_copy-1,k_copy+1) != nullptr and!this->outofBound(r_copy-1,k_copy+1))
        {
            if (game.getPiece_copy(r_copy-1,k_copy+1)->getKleur_copy() != kleur_copy)
            {
                coordinates = make_pair(this->r_copy-1,this->k_copy+1);
                legal_moves.push_back(coordinates);
            }
        }
        if(game.getPiece_copy(r_copy-1,k_copy-1) != nullptr and!this->outofBound(r_copy-1,k_copy-1))
        {
            if (game.getPiece_copy(r_copy-1,k_copy-1)->getKleur_copy() != kleur_copy)
            {
                coordinates = make_pair(this->r_copy-1,this->k_copy-1);
                legal_moves.push_back(coordinates);
            }
        }
        if (game.getPiece_copy(r_copy-1,k_copy) == nullptr && !this->outofBound(r_copy-1,k_copy))
        {
            coordinates = make_pair(this->r_copy-1,this->k_copy);
            legal_moves.push_back(coordinates);
        }
    }
    return legal_moves;
}

vector<pair<int, int>> Koning::geldige_zetten_copy(const Game &game) const
{
    int rij;
    int kolom;
    vector<pair<int, int>> legal_moves;
    for (int i=1; i <= 8;i++)
    {
        // max 8 possible position a position can move to
        switch (i)
        {
            case 1:
                rij = this->r_copy+1;
                kolom = this->k_copy+1;
                break;
                case 2:
                    rij = this->r_copy;
                    kolom = this->k_copy+1;
                    break;
                    case 3:
                        rij = this->r_copy-1;
                        kolom = this->k_copy+1;
                        break;
                        case 4:
                            rij = this->r_copy-1;
                            kolom = this->k_copy;
                            break;
                            case 5:
                                rij = this->r_copy-1;
                                kolom = this->k_copy-1;
                                break;
                                case 6:
                                    rij = this->r_copy;
                                    kolom = this->k_copy-1;
                                    break;
                                    case 7:
                                        rij = this->r_copy+1;
                                        kolom = this->k_copy-1;
                                        break;
                                        case 8:
                                            rij = this->r_copy+1;
                                            kolom = this->k_copy;
                                            break;
        }
        // check for out of boundary
        if (!outofBound(rij,kolom))
        {
            if(game.getPiece_copy(rij,kolom) != nullptr)
            {
                // if it's an other color, it can be eaten
                if (game.getPiece_copy(rij,kolom)->getKleur_copy() != kleur_copy)
                {
                    pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                    legal_moves.push_back(Kingcoordinates);
                }
            }
            // empty square
            else{
                pair<int,int> Kingcoordinates = make_pair(rij,kolom);
                legal_moves.push_back(Kingcoordinates);
            }
        }
    }
    return legal_moves;
}

vector<pair<int, int>> Koningin::geldige_zetten_copy(const Game &game) const {
    auto legal_moves = SchaakStuk::geldige_zetten_toren_copy(game);
    for (auto move: SchaakStuk::geldige_zetten_loper_copy(game))
    {
        legal_moves.push_back(move);
    }
    return legal_moves;
}
