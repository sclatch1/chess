//
// Created by toonc on 12/17/2021.
//

#include "SchaakGUI.h"
#include "guicode/message.h"
#include "guicode/fileIO.h"
#include <iostream>
#include <algorithm>

// Constructor
SchaakGUI::SchaakGUI():ChessWindow(nullptr) {

    g.setStartBord();
    update();
}


// Deze functie wordt opgeroepen telkens er op het schaakbord
// geklikt wordt. x,y geeft de positie aan waar er geklikt
// werd; r is de 0-based rij, k de 0-based kolom
void SchaakGUI::clicked(int r, int k) {
    // Wat hier staat is slechts een voorbeeldje dat wordt afgespeeld ter illustratie.
    // Jouw code zal er helemaal anders uitzien en zal enkel de aanpassing in de spelpositie maken en er voor
    // zorgen dat de visualisatie (al dan niet via update) aangepast wordt.

    // Volgende schaakstukken worden aangemaakt om het voorbeeld te illustreren.
    // In jouw geval zullen de stukken uit game g komen

    bool is_schaak = false;
    clicks ++;
    if (turn%2 == 0)
    {
        cout << "wit" << endl;
        kleur = wit;

    }
    else if (turn%2 == 1)
    {
        cout << "zwart" << endl;
        kleur = zwart;

    }
    /*
    if (schaak)
    {
        is_schaak = true;
        if(clicks == 1)
        {
            if (g.getPiece(r,k) != nullptr && g.getPiece(r,k)->getKleur() == kleur)
            {
                cout << "nieuw piece: " << g.getPiece(r,k)->getTypePiece() <<endl;
                s = g.getPiece(r,k);

            }
            else{
                clicks = 0;
                return;
            }
        }
        if (clicks == 2)
        {
            if(s->getR() == r and s->getK() == k)
            {
                s = nullptr;
                clicks = 0;

            }
            else{
                for (auto it : s->geldige_zetten(g))
                {
                    cout << "r: " << it.first << " k: " << it.second << endl;
                }
                if (g.moveIsPossible(s,r,k) && s->getKleur() == kleur)
                {


                    g.move(s,r,k);
                    update();
                }
                else
                {
                    clicks = 0;
                    return;
                }
            }
        }

    }
     */
    if(clicks == 1)
    {
        if (g.getPiece(r,k) != nullptr && g.getPiece(r,k)->getKleur() == kleur)
            {
                cout << "nieuw piece: " << g.getPiece(r,k)->getTypePiece() <<endl;
                s = g.getPiece(r,k);
            }
        else{
                clicks = 0;
                return;
            }
        }

    if (clicks == 2)
        {
            if(s->getR() == r and s->getK() == k)
            {
                s = nullptr;
                clicks = 0;

            }
            else{
                for (auto it : s->geldige_zetten(g))
                {
                    cout << "r: " << it.first << " k: " << it.second << endl;
                }
                if (g.moveIsPossible(s,r,k) && s->getKleur() == kleur)
                {
                    g.move(s,r,k);
                    update();
                    clicks = 0;
                    turn++;
                }
                else
                {
                    clicks = 0;
                    return;
                }
            }
        }
        //cout << "voor pat" << endl;
        /*
        else if(g.pat(kleur))
        {
            message("pat");
            return;
        }
         */
        if(get<1>(g.schaak(zwart)))
        {
            cout << "schaak" << endl;
            if (g.schaakmat(zwart))
            {
                cout << "in schaakmat" << endl;
                message("zwart in schaakmat");
                return;
            }

            message( "zwart is in check");
        }
        if(get<1>(g.schaak(wit)))
        {
            cout << "schaak" << endl;
            if (g.schaakmat(wit))
            {
                cout << "wit is in schaakmat" << endl;
                message("wit is in schaakmat");
                return;
            }

            message( "wit is in check");
        }


    /*
    if (g.schaak(zwart))
    {
        schaak = true;
        message("zwart is in check");
    }
    if (g.schaak(wit))
    {
        schaak = true;
        message("wit is in check");
    }
     */










    /*
    SchaakStuk* p1=new Pion(zwart);
    SchaakStuk* p2=new Pion(zwart);
    SchaakStuk* Q=new Koningin(zwart);
    SchaakStuk* K=new Koning(zwart);

    SchaakStuk* p3=new Pion(wit);
    SchaakStuk* P=new Paard(wit);
    SchaakStuk* L=new Loper(wit);
    SchaakStuk* Kw=new Koning(wit);


    removeAllMarking();  // Alle markeringen weg
    clearBoard();        // Alle stukken weg

    // plaats alle stukken
    setItem(3,0,P);
    setItem(1,1,p1);
    setItem(0,3,Q);
    setItem(0,4,K);
    setItem(2,4,p2);
    setItem(3,3,p3);
    setItem(2,7,L);
    setItem(5,3,Kw);

    if (displayKills()) {
        // Markeer de stukken die je kan slaan
        setPieceThreat(3,0,true);
        setPieceThreat(3,3,true);
    }
    if (displayThreats()) {
        // Markeer jouw bedreigde stukken
        setPieceThreat(2,4,true);
        setPieceThreat(1,1,true);
    }

    message("Illustratie voor click; zwart is aan de beurt");

    removeAllPieceThreats();  // Eens een stuk gekozen is, worden alle bedreigde stukken niete langer gemarkeerd
    setTileSelect(2,4,true);  // De geselecteerde positie wordt steeds gemarkeerd
    if (displayMoves()) {
        // Geef de mogelijke zetten weer
        setTileFocus(3,3,true);
        setTileFocus(3,4,true);
    }

    message("Illustratie na click; zwart kiest doelpositie");

    clearBoard();
    removeAllMarking();

    setItem(3,0,P);
    setItem(1,1,p1);
    setItem(0,3,Q);
    setItem(0,4,K);
    setItem(2,7,L);
    setItem(5,3,Kw);
    setItem(3,3,p2);

    if (displayKills()) {
        setPieceThreat(2,4,true);
        setPieceThreat(1,1,true);
    }
    if (displayThreats()) {
        setPieceThreat(3,0,true);
    }


    message("Illustratie na doelpositie gekozen is; nu is wit aan de beurt");

    removeAllPieceThreats();

    setTileSelect(2,7,true);
    if (displayMoves()) {
        for (int r=0;r<8;r++) {
            if (r==2) continue;
            int c=7-abs(r-2);
            setTileFocus(r,c,true);
        }
    }
    if (displayThreats()) {
        setTileThreat(0,5,true);
        setTileThreat(3,6,true);
    }

    message("Wit stuk geselecteerd; wit moet nu een doelpositie kiezen");
    removeAllMarking();
    // etc. etc. ...

    delete p1;
    delete p2;
    delete Q;
    delete K;
    delete p3;
    delete P;
    delete L;
    delete Kw;
    */
}



void SchaakGUI::newGame()
{}


void SchaakGUI::save() {
    QFile file;
    if (openFileToWrite(file)) {
        QDataStream out(&file);
        out << QString("Rb") << QString("Hb") << QString("Bb") << QString("Qb") << QString("Kb") << QString("Bb") << QString("Hb") << QString("Rb");
        for  (int i=0;i<8;i++) {
            out << QString("Pb");
        }
        for  (int r=3;r<7;r++) {
            for (int k=0;k<8;k++) {
                out << QString(".");
            }
        }
        for  (int i=0;i<8;i++) {
            out << QString("Pw");
        }
        out << QString("Rw") << QString("Hw") << QString("Bw") << QString("Qw") << QString("Kw") << QString("Bw") << QString("Hw") << QString("Rw");
    }
}

void SchaakGUI::open() {
    QFile file;
    if (openFileToRead(file)) {
        try {
            QDataStream in(&file);
            QString debugstring;
            for (int r=0;r<8;r++) {
                for (int k=0;k<8;k++) {
                    QString piece;
                    in >> piece;
                    debugstring += "\t" + piece;
                    if (in.status()!=QDataStream::Ok) {
                        throw QString("Invalid File Format");
                    }
                }
                debugstring += "\n";
            }
            message(debugstring);
        } catch (QString& Q) {
            message(Q);
        }
    }
    update();
}


void SchaakGUI::undo() {
    message("Je hebt undo gekozen");
}

void SchaakGUI::redo() {}


void SchaakGUI::visualizationChange() {
    QString visstring = QString(displayMoves()?"T":"F")+(displayKills()?"T":"F")+(displayThreats()?"T":"F");
    message(QString("Visualization changed : ")+visstring);
}


// Update de inhoud van de grafische weergave van het schaakbord (scene)
// en maak het consistent met de game state in variabele g.
void SchaakGUI::update()
{
    this->clearBoard();
    for(int rij=0;rij <= 7;rij++)
    {
        for(int kolom=0;kolom <= 7;kolom++)
        {
            if(this->g.getPiece(rij,kolom) != nullptr)
            {
                this->setItem(rij,kolom,this->g.getPiece(rij,kolom));
            }
        }
    }
    cout << "new board" << endl;
}

