//
// Created by 50207 on 2022/12/3.
//

#ifndef THEFINAL_AI_H
#define THEFINAL_AI_H

#include "win_checker.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

class AI {
public:
    static int x_y_maker(int x,int y);
    static int x_analyse(int X_Y);
    static int y_analyse(int X_Y);
    static string* mark_giver_scanner(ChessNode ** chesses,int size,int x,int y,Algorithm algorithm);
    int mark_giver(ChessNode ** chesses,int size,int x,int y);
    int mark_giver_white(ChessNode ** chesses,int size,int x,int y);
    int max(int a,int b);

    int Strategy_maker(ChessBoard board, int size);
    int Strategy_maker_white(ChessBoard board, int size);
};


#endif //THEFINAL_AI_H
