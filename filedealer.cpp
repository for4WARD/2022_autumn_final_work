//
// Created by 50207 on 2022/12/2.
//

#include "filedealer.h"
#include <bits/stdc++.h>
#include <iostream>


using namespace std;
void filedealer::file_now_in(int x,int y,int id){
    FILE *fp= fopen("../memory/lastgame.out","a+");
    fprintf(fp,"%d %d %d\n",x,y,id);
    fclose(fp);
}
void filedealer::file_all_add(int x, int y, int id) {
    FILE *fp= fopen("../memory/allthegame.out","a+");
    fprintf(fp,"%d %d %d\n",x,y,id);
    fclose(fp);
}