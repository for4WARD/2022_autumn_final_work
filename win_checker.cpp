//
// Created by 50207 on 2022/11/29.
//


#include "win_checker.h"
bool Algorithm:: NaiveScan(ChessBoard board,int x,int y,int size){
    int dirvectorx[8] = {0,0,-1,1,-1,1,1,-1};//行
    int dirvectory[8] = {-1,1,0,0,-1,1,-1,1};//列
    //0:left    1:right     2:up   3:down  4:左上    5:右下    6:左下     7:右上  一一对应
    int num[4]={1,1,1,1};
    for (int i = 0; i < 8; ++i) {
        int mx=x,my=y;
        for (int j = 1; j <=4; ++j) {
            if ((mx + dirvectorx[i]) >= 1 && (mx + dirvectorx[i]) <= size && (my + dirvectory[i]) >= 1 &&
                (my + dirvectory[i]) <= size) {

                mx += dirvectorx[i];
                my += dirvectory[i];
                if (board.ShowNode(x, y).getPlayerId() == board.ShowNode(mx, my).getPlayerId() &&
                    board.ShowNode(mx, my).getPlayerId() != -1) {
                    num[i / 2] += 1;//对应方向增加数值；
                }
                else break;

            }
        }

    }
    for (int i = 0; i < 4; ++i) {
        if(num[i]>=5){return true;}
    }
    return false;
}

bool Algorithm::DFS(ChessBoard board,int x,int y,int count,int id,int dir){//dir is the short for direction 两两一组
    int dirvectorx[8] = {0,0,-1,1,-1,1,1,-1};//行
    int dirvectory[8] = {-1,1,0,0,-1,1,-1,1};//列
    //0:left    1:right     2:up   3:down  4:左上    5:右下    6:左下     7:右上  一一对应
    if(count>=5){
        return true;
    }

    else{

        if(board.ShowNode(x,y).getPlayerId()==id){
            return DFS(board,x + dirvectorx[dir],y + dirvectory[dir],count+1,id,dir);
        }
        else{
            return false;
        }
    }

}

bool Algorithm::DFS_improved(ChessBoard board,int x,int y,int count,int id,int dir){//dir is the short for direction 两两一组
    int dirvectorx[8] = {0,0,-1,1,-1,1,1,-1};//行
    int dirvectory[8] = {-1,1,0,0,-1,1,-1,1};//列
    //0:left    1:right     2:up   3:down  4:左上    5:右下    6:左下     7:右上  一一对应
    if(count>=5){
        return true;
    }
    else{

        if(board.ShowNode(x,y).getPlayerId()==id){
            return DFS_improved(board,x + dirvectorx[dir],y + dirvectory[dir],count+1,id,dir);
        }
        else{
            if((dir%2)==0){
                dir+=1;
                return DFS_improved(board,x + dirvectorx[dir]-dirvectorx[dir-1]*count,y + dirvectory[dir]-dirvectory[dir-1]*count,count,id,dir);
            }
            else
                return false;
        }
    }

}
bool Algorithm::bkmp(string LongStr,string ShortStr){
    char *LongArr =(char *)LongStr.c_str();
    char *ShortArr=(char *)ShortStr.c_str();
    //fffnnfffnfffffnnn
    //fffff ||  f is black and n is white;
    for (int i = 0; i < LongStr.length();) {
        int temp=i;
        for (int j = 0; j < ShortStr.length();) {

            if(LongArr[i]==ShortArr[j]){
                i++;
                j++;
                if(j==ShortStr.length()){
                    return true;
                }
            }
            else{
                j=0;i=temp+1;
                break;
            }
        }
    }
    return false;
}
int Algorithm::ikmp(string LongStr,string ShortStr){
    char *LongArr =(char *)LongStr.c_str();
    char *ShortArr=(char *)ShortStr.c_str();
    int count=0;
    //fffnnfffnfffffnnn
    //fffff ||  f is black and n is white;
    for (int i = 0; i < LongStr.length();) {
        int temp=i;
        for (int j = 0; j < ShortStr.length();) {
            if(LongArr[i]==ShortArr[j]){
                i++;
                j++;
                if(j==ShortStr.length()){
                    count++;
                    i=temp+1;
                }
            }
            else{
                j=0;i=temp+1;
                break;
            }
        }
    }
    return count;
}

string Algorithm::NodeTranslator(ChessNode n){
    if(n.getPlayerId()==-1) {
        return "?";
    }
    else if(n.getPlayerId()==BLACK) return "f";
    else if(n.getPlayerId()==WHITE) return "n";
    else return " ";
}
string Algorithm::StringReverse(string str){
    string ans="";
    for (int i = str.length(); i >=0 ; i--) {
        ans+=str[i];
    }
    return ans;
}












