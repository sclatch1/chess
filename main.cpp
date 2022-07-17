//
//  !!! Dit bestand moet je in principe NIET wijzigen !!!
//

#include <QApplication>
#include "SchaakGUI.h"
#include "game.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    SchaakGUI w;
    w.show();

    return a.exec();


    /*
    Game g;
    g.setStartBord();
    SchaakStuk* s = g.getPiece(3,1);
    vector<pair<int,int>> v=s->geldige_zetten(g);
    return 0;
    */
}
