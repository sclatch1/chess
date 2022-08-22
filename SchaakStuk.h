//  Student: Scalais David
//  Rolnummer: s0206073
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_SCHAAKSTUK_H
#define SCHAKEN_SCHAAKSTUK_H
#include "guicode/chessboard.h"
#include <utility>

using namespace std;

class Game;

enum zw{zwart,wit};

class SchaakStuk {
public:
    SchaakStuk(zw kleur): kleur(kleur) {}

    virtual Piece piece() const=0;      // Verander deze functie niet!
                                        // Deze functie wordt gebruikt door
                                        // setItem(x,y,SchaakStuk*) van
                                        // SchaakGUI

    zw getKleur() const { return kleur; };


private:
    vector<pair<int,int>> zetten_van_tegenstander;
    bool pin= false;
    bool is_protected= false;
    string typePiece;
    string typePiece_copy;

protected:
    vector<pair<int, int>> geldige_zetten_loper(const Game &game) const;
    vector<pair<int, int>> geldige_zetten_toren(const Game &game) const;

    vector<pair<int, int>> geldige_zetten_toren_copy(const Game &game) const;
    vector<pair<int, int>> geldige_zetten_loper_copy(const Game &game) const;
    int r;
    int k;
    int r_copy;
    int k_copy;
    zw kleur_copy;
    zw kleur;
public:
    zw getKleur_copy() const;
    void setKleur(const zw &kleur);
    const string &getTypePieceCopy() const;

    void setTypePieceCopy(const string &typePieceCopy);
    void setKleur_copy(zw kleurCopy);

public:
    virtual vector<pair<int,int>> geldige_zetten(const Game& game) const = 0;
    virtual vector<pair<int,int>> geldige_zetten_copy(const Game& game) const = 0;


    const string &getTypePiece() const;

    static bool outofBound(int rij,int kolom) ;



    void setTypePiece(const string &typePiece);

    vector<pair<int,int>> line_of_sight_rook(Game &game);

    vector<pair<int,int>> line_of_sight_bishop(Game &game);

    int getR() const;

    void setR(int r);

    int getK() const;

    void setK(int k);

    //copy

    int getR_copy() const;
    void setR_copy(int rij);
    int getK_copy() const ;
    void setK_copy(int kolom);
};

class Pion:public SchaakStuk {
public:
    Pion(zw kleur):SchaakStuk(kleur) {}
    virtual Piece piece() const override {
        return Piece(Piece::Pawn,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game) const;
};

class Toren:public SchaakStuk {
public:
    Toren(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Rook,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game) const;
};

class Paard:public SchaakStuk {
public:
    Paard(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Knight,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game)  const;
};

class Loper:public SchaakStuk {
public:
    Loper(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Bishop,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game) const;
};

class Koning:public SchaakStuk {
public:
    Koning(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::King,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game) const;
};

class Koningin:public SchaakStuk{
public:
    Koningin(zw kleur):SchaakStuk(kleur) {}

    Piece piece() const override {
        return Piece(Piece::Queen,getKleur()==wit?Piece::White:Piece::Black);
    }
    vector<pair<int,int>> geldige_zetten(const Game& game) const override;
    vector<pair<int, int>> geldige_zetten_copy(const Game &game) const;
};

#endif //SCHAKEN_SCHAAKSTUK_H
