//
// Created by 50207 on 2022/12/3.
//

#include "AI.h"
#include <bits/stdc++.h>
#include <iostream>


using namespace std;
int AI::max(int a, int b) {
    return a>b?a:b;
}
int AI::x_y_maker(int x, int y) {
    return (100*x+y);
}
int AI::x_analyse(int X_Y) {
    return (X_Y/100);
}
int AI::y_analyse(int X_Y) {
    return (X_Y%100);
}
string* AI::mark_giver_scanner(ChessNode ** chesses,int size,int x,int y,Algorithm algorithm){
    auto *str=new string[8];
    //0 :left   1:right     2:up    3:down  4:left up   5:right down    6:right up  7:left down

    for(int i=0;i<8;i++){
        str[i]="";
    }
    for(int i=y-1;i>=1&&i>=y-4;i--){
        str[0]+=algorithm.NodeTranslator(chesses[x][i]);
    }
    for(int i=y+1;i<=size&&i<=y+4;i++){
        str[1]+=algorithm.NodeTranslator(chesses[x][i]);
    }
    for(int i=x-1;i>=1&&i>=x-4;i--){
        str[2]+=algorithm.NodeTranslator(chesses[i][y]);
    }
    for(int i=x+1;i<=size&&i<=x+4;i++){
        str[3]+=algorithm.NodeTranslator(chesses[i][y]);
    }
    for (int i = x-1,j=y-1; i>=1&&j>=1&&i>=x-4&&j>=y-4; i--,j--) {
        str[4]+=algorithm.NodeTranslator(chesses[i][j]);
    }
    for (int i = x+1,j=y+1; i <=size&&j<=size&&i<=x+4&&j<=y+4 ; i++,j++) {
        str[5]+=algorithm.NodeTranslator(chesses[i][j]);
    }
    for (int i = x-1,j=y+1; i >=1&&j<=size&&i>=x-4&&j<=y+4 ; i--,j++) {
        str[6]+=algorithm.NodeTranslator(chesses[i][j]);
    }
    for (int i = x+1,j=y-1; i <=size&&j>=1&&i<=x+4&&j>=y-4 ; i++,j--) {
        str[7]+=algorithm.NodeTranslator(chesses[i][j]);
    }
//    cout<<"x:"<<x<<"\ty:"<<y<<"\t"<<str[0]<<"\t"<<str[1]<<"\t"<<str[2]<<"\t"<<str[3]<<"\t"<<str[4]<<"\t"<<str[5]<<"\t"<<str[6]<<"\t"<<str[7]<<"\t"<<endl;
    return str;
}
int AI::mark_giver(ChessNode ** chesses,int size,int x,int y){
    Algorithm algorithm;
    string *str=mark_giver_scanner(chesses,size,x,y,algorithm);
    int ans=0;
    int container[8];//能赢 活四，活三，活二 赋分 10000 100 10     防守： 对方 眠四 活三 双三 活二
    for (int i = 0; i < 8; ++i) {
        container[i]=0;
    }
    //对于每个方向进行循环遍历
    for(int i=0;i<4;i++){
        string l1,l2,l3,l4,r1,r2,r3,r4;
        if(str[2*i].length()>=1)l1+=(str[2*i][0]);
        if(str[2*i].length()>=2)l2+=(l1+str[2*i][1]);
        if(str[2*i].length()>=3)l3+=(l2+str[2*i][2]);
        if(str[2*i].length()>=4)l4+=(l3+str[2*i][3]);
        if(str[2*i+1].length()>=1)r1+=str[2*i+1][0];
        if(str[2*i+1].length()>=2)r2+=(r1+str[2*i+1][1]);
        if(str[2*i+1].length()>=3)r3+=(r2+str[2*i+1][2]);
        if(str[2*i+1].length()>=4)r4+=(r3+str[2*i+1][3]);
        //定义 进攻
        if(algorithm.bkmp(l4,"ffff")||algorithm.bkmp(r4,"ffff")||(l2+r2=="ffff")||(l1+r3=="ffff")||(l3+r1=="ffff")) {
//            cout<<"check4:b"<<x<<"\t"<<y<<endl;
            return INT32_MAX;//0:拿下！
        }
        if((l4=="fff?"&&r1=="?")||(r4=="fff?"&&l1=="?")||(l3=="ff?"&&r2=="f?")||(r3=="ff?"&&l2=="f?")){
            return INT32_MAX-2;
        }
        if((l4=="fff"&&r1=="?")||(r4=="fff?")||(l3=="ff?"&&r2=="f")||(r3=="ff"&&l2=="f?")){
            return container[1]+=1;//眠四
        }
        if((l3=="ff?"&&r1=="?")||(l2=="f?"&&r2=="f?")||(l1=="?"&&r3=="ff?"))
        {
            container[2]+=1;
        }
        if((l2=="f?"&&r1=="?")||(l1=="?"&&r2=="f?"))
        {
            container[3]+=1;
        }
        if((l3=="fff"&&r1!="n")||r3=="fff"&&l1!="n"){
            container[4]+=1;
        }
        //定义 防守
        if(algorithm.bkmp(l4,"nnnn")||algorithm.bkmp(r4,"nnnn")||(l2+r2=="nnnn")||(l1+r3=="nnnn")||(l3+r1=="nnnn")) {
//            cout<<"check4:"<<x<<"\t"<<y<<endl;
            return INT32_MAX-1;//4:不堵就寄
        }
        if((l4=="nnn?")||(r4=="nnn?")||(l3=="nn?"&&r1=="n")||(r3=="nn?"&&l1=="n")){
//            cout<<"check3:"<<x<<"\t"<<y<<endl;
            return INT32_MAX-3;//不堵就寄
        }
        if((l3=="nnn"&&r1=="?")||(r4=="nnn?")||(l3=="nn?"&&r2=="n")||(r3=="nn"&&l2=="n?")){
            return container[5]+=1;//5：眠四
        }
        if((l3=="nn?"&&r1=="?")||(l2=="n?"&&r2=="n?")||(l1=="?"&&r3=="nn?"))
        {
            cout<<"check2:"<<x<<"\t"<<y<<endl;
            container[6]+=1;//6: 防止形成活三
        }
        if((l2=="n?"&&r1=="?")||(l1=="?"&&r2=="n?"))
        {
            container[7]+=1;
        }
    }
    if(container[1]>=2){
        return INT32_MAX/10;
    }
    if(container[5]>=2){
        return (INT32_MAX/10)-1;
    }
    if(container[2]>=2){
        return INT32_MAX/100;
    }
    if(container[6]>=2){
        return (INT32_MAX/100)-1;
    }
    if(container[1]==1){
        ans+=100000000;
    }
    if(container[2]==1){
        ans+=100000000;
    }
    if(container[3]!=0){
        ans+=pow(10,container[3]);
    }
    if(container[5]==1){
        ans+=1000000;
    }
    if(container[6]==1){
        ans+=10000000;
    }
    if(container[7]!=0){
        ans+=pow(10,container[3]);
    }
    if(container[4]!=0){
        ans+=pow(10,container[3]);
    }
    return ans;
    //赋分
}

int AI::Strategy_maker(ChessBoard board,int size){
    int scale=pow(size,2);
    int score[scale];
    int score_max=0;
    int num_of_max=0;
    AI ai;
    ChessNode ** chesses=board.ShowBoard();
    for(int i=1;i<=size;i++){
        for (int j = 1; j <=size; ++j) {
            if (chesses[i][j].getPlayerId()!=WHITE&&chesses[i][j].getPlayerId()!=BLACK) {
                int now = ai.mark_giver(chesses, size, i, j);
//                cout << now << endl;
                if (score_max > now)continue;
                else if (score_max == now) {
                    score[num_of_max] = x_y_maker(i, j);
                    num_of_max++;
                } else {
                    score_max = now;
                    for (int k = 0; k < num_of_max; k++) {
                        score[k] = 0;
                    }
                    num_of_max = 1;
                    score[0] = x_y_maker(i, j);
                }
            }
            else{
//                cout<<"check1"<<endl;
                continue;
            }
        }
    }
//    cout<<score_max<<endl;
    //随机返回encode过的最佳选择
    //(unsigned int)time(NULL)
    srand((unsigned int)time(NULL));
    int a=rand()%num_of_max;
    int ans=score[a];
    cout<<num_of_max<<endl;
    return ans;
}

