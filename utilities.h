//
// Created by david Scalais on 22/08/2022.
//

#ifndef CHESS_UTILITIES_H
#define CHESS_UTILITIES_H

bool outofBound(int rij,int kolom)
{
    // checking if the coordinates is within the board
    if ((0 <= rij) && (rij < 8) && (0 <= kolom) && (kolom < 8)){return false;}
    else{return true;}
}


#endif //CHESS_UTILITIES_H
