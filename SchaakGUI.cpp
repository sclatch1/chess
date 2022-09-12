//
// Created by toonc on 12/17/2021.
//

#include "SchaakGUI.h"
#include "guicode/message.h"
#include "guicode/fileIO.h"
#include <iostream>
#include <algorithm>
#include "unistd.h"

char to_char(string input);

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


    clicks ++;
    if (turn%2 == 0)
    {
        //cout << "wit" << endl;
        kleur = wit;
    }
    else if (turn%2 == 1)
    {
        //cout << "zwart" << endl;
        kleur = zwart;
    }
    if (displayKills()){
        for(auto it : g.CanBeTaken(zwart))
        {
            //cout << "threating: " << it.first << " " << it.second << endl;
            setPieceThreat(it.first,it.second,true);
        }
        for(auto it : g.CanBeTaken(wit))
        {
            //cout << "threating: " << it.first << " " << it.second << endl;
            setPieceThreat(it.first,it.second,true);
        }
    }
    if(schaak)
    {
        // check if a color is in checkmate
        /*
        if(get<1>(g.schaak(zwart)))
        {
            if (g.schaakmat(zwart))
            {
                message("zwart in schaakmat");
                return;
            }
        }
         */
        if(get<1>(g.schaak(wit)))
        {
            if (g.schaakmat(wit))
            {
                message("wit is in schaakmat");
                return;
            }
        }
    }


    if(kleur == zwart)
    {
        //cout << "zwart\n";
        g.Make_copy();
        bool check = true;
        while (check){
            tuple<int,int,int,int> result = g.AI();
            g.Make_copy();
            int S_i = get<0>(result);
            int S_j = get<1>(result);
            int D_i = get<2>(result);
            int D_j = get<3>(result);
            g.move_copy(g.getPiece_copy(S_i,S_j),D_i,D_j);
            if(!get<1>(g.schaak_copy(zwart))){check = false;}
            if (!check){
                //cout << "computer moves from: (" << S_i << ", " << S_j << ") to (" << D_i << ", "<< D_j << ") \n";
                g.move(g.getPiece(S_i,S_j),D_i,D_j);
            }

            if(get<1>(g.schaak(zwart))){
                if(g.schaakmat(zwart)){
                    message("zwart in schaakmat");
                    return;}
            }


            g.delete_copy();
        }
        g.delete_copy();
        if(displayKills()){
            for(auto it : g.CanBeTaken(zwart))
            {
                //cout << "threating: " << it.first << " " << it.second << endl;
                setPieceThreat(it.first,it.second,false);
            }
        }
        kleur = wit;
        turn++;
        clicks=0;
        update();
        schaak = false;
        if (get<1>(g.schaak(zwart)))
        {
            schaak = true;
            message("zwart is in check");
        }
        if (get<1>(g.schaak(wit)))
        {
            schaak = true;
            message("wit is in check");
        }
        return;
    }
    else{
        if(clicks == 1)
        {

            if (g.getPiece(r,k) == nullptr)
            {
                clicks = 0;
                return;
            }
            if (g.getPiece(r,k) != nullptr && g.getPiece(r,k)->getKleur() == kleur)
            {
                //cout << "nieuw piece: " << g.getPiece(r,k)->getTypePiece() <<endl;
                s = g.getPiece(r,k);
                if(displayMoves()){
                    this->setTileSelect(r,k,true);

                    auto threatMap = g.threatMap(kleur);
                    for (auto move : s->geldige_zetten(g))
                    {
                        /*
                        auto p = std::find(threatMap.begin(),threatMap.end(),move);
                        if (p == threatMap.end()){
                                this->setTileThreat(move.first,move.second,true);
                            }
                        else{this->setTileFocus(move.first,move.second,true); }
                         */
                        this->setTileFocus(move.first,move.second,true);
                    }
                }
                return;
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
                    if(displayMoves()){
                    this->setTileSelect(r,k,false);

                    //auto threatMap = g.threatMap(kleur);
                    for (auto move : g.getPiece(r,k)->geldige_zetten(g))
                    {

                        /*
                        auto p = std::find(threatMap.begin(),threatMap.end(),move);
                        if (p == threatMap.end()){
                            this->setTileThreat(move.first,move.second,false);
                        }
                        else{this->setTileFocus(move.first,move.second,true); }
                        */
                        this->setTileFocus(move.first,move.second,false);


                    }
                }
                clicks = 0;
                return;
            }
            else{
                for (auto it : s->geldige_zetten(g))
                {
                    //cout << "r: " << it.first << " k: " << it.second << endl;
                }
                if (displayMoves()){
                    this->setTileSelect(s->getR(),s->getK(),false);
                    //auto threatMap = g.threatMap(kleur);
                    for (auto move : g.getPiece(s->getR(),s->getK())->geldige_zetten(g))
                    {
                        /*
                        auto p = std::find(threatMap.begin(),threatMap.end(),move);
                        if (p == threatMap.end()){
                            this->setTileThreat(move.first,move.second,false);
                        }
                        else{this->setTileFocus(move.first,move.second,true); }
                         */
                        this->setTileFocus(move.first,move.second,false);


                    }
                }
                if(displayKills()){
                    for(auto it : g.CanBeTaken(wit))
                    {
                        //cout << "threating: " << it.first << " " << it.second << endl;
                        setPieceThreat(it.first,it.second,false);
                    }
                }
                if (g.moveIsPossible(s,r,k) && s->getKleur() == kleur)
                {
                    if(schaak){
                        g.Make_copy();
                        g.move_copy(g.getPiece_copy(s->getR(),s->getK()),r,k);
                        if (s->getTypePiece() == "Qw")
                        {
                            //cout << "queen";
                        }
                        if(!get<1>(g.schaak_copy(zwart)) and !get<1>(g.schaak_copy(wit))){
                            g.delete_copy();
                            if (displayMoves()){
                                this->setTileSelect(s->getR(),s->getK(),false);
                                for (auto move : s->geldige_zetten(g))
                                {
                                    this->setTileFocus(move.first,move.second,false);
                                }
                            }
                            if(!g.move(s,r,k))
                            {
                                //cout << "no moves" << endl;
                                update();
                                clicks = 0;
                                return;
                            }
                            schaak = false;
                            turn++;
                            clicks = 0;
                            kleur = zwart;
                            update();
                        }
                        else
                        {
                            g.delete_copy();
                            if(displayMoves()){
                                this->setTileSelect(s->getR(),s->getK(),false);
                                for (auto move : g.getPiece(s->getR(),s->getK())->geldige_zetten(g))
                                {
                                    /*
                                    auto p = std::find(threatMap.begin(),threatMap.end(),move);
                                    if (p == threatMap.end()){
                                        this->setTileThreat(move.first,move.second,false);
                                    }

                                    else{this->setTileFocus(move.first,move.second,true); }*/
                                    this->setTileFocus(move.first,move.second,false);

                                }
                            }
                            clicks = 0;
                            return;
                        }
                    }
                    else
                    {
                        g.Make_copy();
                        g.move_copy(g.getPiece_copy(s->getR(),s->getK()),r,k);

                        if (kleur == wit){
                            if(!get<1>(g.schaak_copy(wit))){
                                g.delete_copy();
                                if(!g.move(s,r,k))
                                {
                                    //cout << "no moves" << endl;
                                    update();
                                    clicks = 0;
                                    return;
                                }
                                turn++;
                                clicks = 0;
                                update();
                                kleur = zwart;
                                if (get<1>(g.schaak(zwart)))
                                {
                                    schaak = true;
                                    message("zwart is in check");
                                }
                                if (get<1>(g.schaak(wit)))
                                {
                                    schaak = true;
                                    message("wit is in check");
                                }
                                return;
                            }
                        }
                        else
                        {
                            clicks = 0;
                            return;
                        }
                    }
                }

                else
                {
                    clicks = 0;
                    return;
                }
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
{
    this->clearBoard();
    update();
}


void SchaakGUI::save() {
    QFile file;
    if (openFileToWrite(file)) {
        QDataStream out(&file);
        for  (int r=0;r<8;r++) {
            for (int k=0;k<8;k++) {
                if (g.getPiece(r,k) == nullptr)
                {
                    out << QString(".");
                }
                else{
                    out << QString(to_char(g.getPiece(r,k)->getTypePiece()));
                    cout << to_char(g.getPiece(r,k)->getTypePiece()) << " ";
                }
            }
        }
    }
}

char SchaakGUI::to_char(const string &input)
{
    char arr[input.length()+1]; //code overgenomen van https://www.geeksforgeeks.org/convert-string-char-array-cpp/
    strcpy(arr,input.c_str());
    for(int i =0;i < input.length();i++)
    {
        arr[i] = input[i];
    }
    return *arr;
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

void SchaakGUI::redo() {

}


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
    removeAllMarking();
}

