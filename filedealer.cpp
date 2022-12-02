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
    FILE *fp = fopen("../memory/allthegame.out", "a+");
    fprintf(fp, "%d %d %d\n", x, y, id);
    fclose(fp);
}
void filedealer::file_add_line(){
        FILE *fp= fopen("../memory/allthegame.out","a+");
        fprintf(fp,"-----------分割线-----------\n");
        fclose(fp);
}
void filedealer::file_add_rep() {
    FILE *fp1= fopen("../memory/allthegame.out","a+");
    fprintf(fp1,"10000\n");
    fclose(fp1);
    FILE *fp2= fopen("../memory/lastgame.out","a+");
    fprintf(fp2,"10000\n");
    fclose(fp2);
}

