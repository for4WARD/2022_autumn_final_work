//
// Created by 50207 on 2022/11/29.
//

#ifndef THEFINAL_WIN_CHECKER_H
#define THEFINAL_WIN_CHECKER_H


#include <iostream>
#include "checkboard.cpp"
#define PVPBAN 11
#define PVPNON 12
#define PVE 13
using namespace std;

class Algorithm{
public:
    bool NaiveScan(ChessBoard board,int x,int y,int size);
    bool DFS(ChessBoard board,int x,int y,int count,int id,int dir);
    bool DFS_improved(ChessBoard board,int x,int y,int count,int id,int dir);
    bool bkmp(string LongStr,string ShortStr);
    int ikmp(string LongStr,string ShortStr);
    string NodeTranslator(ChessNode n);
    string StringReverse(string str);
    string* ScanNode(ChessBoard board,int size,ChessNode ** chesses){
        string *str=new string[8];
        for (int i = 0; i < 8; ++i) {
            str[i]="";
        }

        for (int i = 0; i <=size+1 ; ++i) {
            str[0]+= NodeTranslator(chesses[board.ShowRecentStep().getLocationX()][i]);
            //0:左到右
//            cout<<str[0]<<endl;
//            cout<<"id:"<<chesses[board.ShowRecentStep().getLocationX()][i].getPlayerId()<<endl;
        }

        for (int i = 0; i <=size+1 ; ++i) {
            str[1]+= NodeTranslator(chesses[i][board.ShowRecentStep().getLocationY()]);
            //1:上到下
        }
        //2:左上到右下
        string tmp2="";
        for(int i= board.ShowRecentStep().getLocationX(),j=board.ShowRecentStep().getLocationY();i>=0&&j>=0;i--,j--){
            tmp2+= NodeTranslator(chesses[i][j]);
        }
        str[2]+= StringReverse(tmp2);
        for(int i=board.ShowRecentStep().getLocationX()+1,j=board.ShowRecentStep().getLocationY()+1;i<=size+1&&j<=size+1;i++,j++){
            str[2]+= NodeTranslator(chesses[i][j]);
        }
        //3: 右上到左下
        string tmp3="";
        for(int i= board.ShowRecentStep().getLocationX(),j=board.ShowRecentStep().getLocationY();i>=0&&j<=size+1;i--,j++){
            tmp3+= NodeTranslator(chesses[i][j]);
        }
        str[3]+= StringReverse(tmp3);
        for(int i=board.ShowRecentStep().getLocationX()+1,j=board.ShowRecentStep().getLocationY()-1;i<=size+1&&j>=0;i++,j--){
            str[3]+= NodeTranslator(chesses[i][j]);
        }
        for(int i=4;i<8;i++){
            str[i]= StringReverse(str[i-4]);
        }
//        cout<<str[1]<<endl;
return str;
    }

    int Judeger(ChessBoard board,int size,int mode){
        string *str=ScanNode(board,size,board.ShowBoard());
        if (mode==PVPBAN) {
            //判断长连禁手
            bool *tag = new bool[4];
            for (int i = 0; i < 4; i++) {
                tag[i] = false;
            }
            bool istaged = false;
            for (int i = 0; i < 4; ++i) {
                if (bkmp(str[i], "ffffff")) {
                    tag[i] = true;
                    istaged = true;
                }
            }//胜利优先级高于长连
            if (istaged) {
                for (int i = 0; i < 4; ++i) {
                    if (!tag[i] && bkmp(str[i], "fffff"))
                        return BLACK;
                }
                return WHITE;
            }
            //三三禁手 四四禁手
            string BanRoutes3[] = {"?fff?", "?ff?f?"};
            double Weights3[] = {0.5, 1};//左右都会扫到
            string BanRoutes4[] = {"?ffff?", "fff?f", "nffff?", "ffff?n"};
            double Weights4[] = {0.5, 1, 1, 1};
            //三三开始判断
            double temp3 = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 8; j++) {
                    //                cout<<"33:"<<Weights3[i]* ikmp(str[j],BanRoutes3[i])<<endl;
                    temp3 += Weights3[i] * ikmp(str[j], BanRoutes3[i]);
                }
            }
            if (temp3 > 1.1)//防止精度丢失
            {
                return WHITE;
            }
            double temp4 = 0;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 8; ++j) {
                    temp4 += Weights4[i] * ikmp(str[j], BanRoutes4[i]);
                }
            }
            if (temp4 > 1.1) {
                return WHITE;
            }
        }


        //判断五连子
//        cout<<str[0]<<endl;
        for(int i=0;i<8;i++){
            if(bkmp(str[i],"fffff")){
                return BLACK;
            }
            else if(bkmp(str[i],"nnnnn")){
                return WHITE;
            }
        }
        return -1;
    }

};


#endif //THEFINAL_WIN_CHECKER_H
