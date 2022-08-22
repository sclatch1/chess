//
//  !!! Dit bestand moet je in principe NIET wijzigen !!!
//

#include <QApplication>
#include "SchaakGUI.h"


// DONE: In Schaakstuk geldige zetten overerving van loper en toren voor koninging
// DONE: deep copy of game
// TODO: schaakmat
// TODO: threatMap, HELP functions
// pat

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    SchaakGUI w;
    w.show();

    return a.exec();
}
