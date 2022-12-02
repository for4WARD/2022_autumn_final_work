//
// Created by 50207 on 2022/11/28.
//
#include "iostream"
#include "stack"
using namespace std;
#define BLACK 1
#define WHITE 2
//x is black and y is white while # is nothing
class ChessNode{
public:


    void SetChessNode(int x, int y, int z){
        location_y=y;
        location_x=x;
        player_id=z;
    }


    int getLocationX() const {
        return location_x;
    }

    void setLocationX(int locationX) {
        location_x = locationX;
    }

    int getLocationY() const {
        return location_y;
    }

    void setLocationY(int locationY) {
        location_y = locationY;
    }

    int getPlayerId() const {
        return player_id;
    }

    void setPlayerId(int playerId) {
        player_id = playerId;
    }

private:
    int location_x;
    int location_y;
    int player_id;
};





class ChessBoard
{
public:
    ChessBoard(int size)//initialize
    {
        this ->size=size;
        board =new ChessNode * [size+2];
        for (int i = 0; i < size+2; ++i) {
            board[i]=new ChessNode[size+2];
        }
        for (int i = 0; i < size+2; ++i) {
            for (int j = 0; j < size+2; ++j) {
                board[i][j].SetChessNode(i,j,-1);//-1无人落子
            }
        }
    }
    void Reinitialize(){
        for (int i = 0; i < size+2; ++i) {
            for (int j = 0; j < size+2; ++j) {
                board[i][j].SetChessNode(i,j,-1);//-1无人落子
            }
        }
    }
    void PlaceNode(int x,int y,int id){
        if(board[x][y].getPlayerId()!=-1) return;
        if(x>=1&&y>=1&&x<=size&y<=size)
        {
            board[x][y].setPlayerId(id);
            AddStep(board[x][y]);
        }
    }
    ChessNode ShowNode(int x,int y){
        if(x>=1&&y>=1&&x<=size&y<=size)
        {
            return board[x][y];
        }
        return board[0][0];
    }
    void AddStep(ChessNode c){
        route.push(c);
    }
    ChessNode ShowRecentStep()
    {
        if (!route.empty()){
            return route.top();
        }
        return board[0][0];
    }
    void RepentStep(){
        if(!route.empty()){
            ChessNode temp=route.top();
            board[temp.getLocationX()][temp.getLocationY()].setPlayerId(-1);
        }
    }
    void Display(){
        cout<<"\t";
        for (int i = 1; i <=size; ++i) {
            cout<<i<<"\t";
        }
        cout<<endl;
        for (int i = 1; i <= size; ++i) {
            cout<<i<<"\t";
            for (int j = 1; j <= size; ++j) {
                if(board[i][j].getPlayerId()==1){
                    cout<<"x\t";
                }
                else if(board[i][j].getPlayerId()==2){
                    cout<<"o\t";
                }
                else{
                    cout<<"#\t";
                }
            }
            cout<<endl;
        }
    }

    int getSize() const {
        return size;
    }

    stack<ChessNode> ShowRoute(){
        return route;
    }
    ChessNode **ShowBoard(){
        return board;
    }
private:
    int size;
    ChessNode **board;
    stack<ChessNode> route;
};

#include "checkboard.h"