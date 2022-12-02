//
// Created by 50207 on 2022/12/1.
//

#ifndef THEFINAL_EASYXFUNCTIONS_H
#define THEFINAL_EASYXFUNCTIONS_H

#include<iostream>
#include "graphics.h"
#include "mmsystem.h"
#pragma comment(lib,"libwinmm.a")
#include "conio.h"
#include "easyxfunctions.h"
#pragma once

using namespace std;
class easyxfunctions {
public:
    void BGM();
    void picture_loader(int x, int y, int sizex,int sizey,const char *location);
    int change2(const char *title, const char *saysomething, const char *hint);
    void change1(const char *title, const char *saysomething, const char *hint);

    void BlackPawn(int x, int y);

    void WhitePawn(int x, int y);

    void Button(const char *message, int x_location, int y_location, int height, int width,int charheight);
};
#endif //THEFINAL_EASYXFUNCTIONS_H
