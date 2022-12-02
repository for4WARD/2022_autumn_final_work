#include <iostream>
#include "win_checker.h"
#include "graphics.h"
#include "easyxfunctions.h"
#include "pages.h"
#include "xytranslator.h"
#include "filedealer.h"
using namespace std;
#define BLACK 1
#define WHITE 2
#define PVPBAN 11
#define PVPNON 12
#define PVE 13
int main()
{
    filedealer filedealer;
    easyxfunctions easyxfunctionmain;
    easyxfunctionmain.BGM();
    initgraph(1000,1000,0);
    pages page_page;
    HWND hnd = GetHWnd();//获取窗口句柄
    SetWindowText(hnd, "zjx的五子棋");//设置窗口标题
    ExMessage msg;//initialized
    xytranslator locationtranslator;
    int id=BLACK;//黑棋先手
    int size=19;//棋盘大小为19
    ChessBoard chessBoard(size);
    Algorithm algorithm;
    int turns=0;
    int mode= 0;
    TAG1:

    page_page.page1();
    while(TRUE){
        Sleep(5);
        if(peekmessage(&msg,EM_MOUSE)){
            switch (msg.message) {
                case WM_LBUTTONDOWN:
                    //pvp
                {
                    if (msg.x >= 600 && msg.x <= 900 && msg.y >= 600 && msg.y <= 700) {
                        goto SWITCH;
                    }
                    //pve
                    if (msg.x >= 600 && msg.x <= 900 && msg.y >= 800 && msg.y <= 900) {
                        easyxfunctionmain.change1("zjx的五子棋",
                                                  "由于练习时长未到两年半，所以只做了无禁手的AI，祝您玩得愉快", "提示");
                        mode=PVE;
                        goto TAGBOARD;//棋盘
                    }
                    if (msg.x >= 100 && msg.x <= 300 && msg.y >= 900 && msg.y <= 1000) {
                        int flag = easyxfunctionmain.change2("zjx的五子棋", "是否退出游戏？", "提示");
                        if (flag == 0) {
                            msg.x = 0, msg.y = 0;
                            goto TAG1;
                        } else {
                            goto EXIT;
                        }

                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    SWITCH:
    //PVP模式选择

    page_page.page_switch();

    while(TRUE){
        if(peekmessage(&msg,EM_MOUSE)){

            if (msg.message==WM_LBUTTONDOWN) {
                int mx = msg.x, my = msg.y;
                //禁手

                if (mx >= 300 && mx <= 700 && my >= 550 && my <= 675) {
                    easyxfunctionmain.change1("zjx的五子棋",
                                              "禁手？牛哇！", "提示");
                    mode=PVPBAN;
                    goto TAGBOARD;
                }
                    //不禁手
                else if (mx >= 300 && mx <= 700 && my >= 700 && my <= 825) {
                    easyxfunctionmain.change1("zjx的五子棋",
                                              "正经人谁玩禁手啊", "提示");
                    mode=PVPNON;
                    goto TAGBOARD;//棋盘
                } else if (mx >= 300 && mx <= 700 && my >= 850 && my <= 975) {
                    goto TAG1;
                }

            }
        }
    }




    //棋盘
    TAGBOARD:
    page_page.pageboard();
    chessBoard.Reinitialize();
    id=BLACK;
    while(TRUE){
        Sleep(10);

        if(peekmessage(&msg,EM_MOUSE)){
            if(id==BLACK){
                easyxfunctionmain.picture_loader(830,300,160,100,"../materials/Snipaste_2022-12-02_16-46-18.png");
            }
            else{
                easyxfunctionmain.picture_loader(830,300,160,100,"../materials/Snipaste_2022-12-02_16-46-57.png");
            }
            if (msg.message==WM_LBUTTONDOWN) {
                int mx = msg.x, my = msg.y;
                if (mx >= 830 && mx <= 1000 && my >= 700 && my <= 800) {
                    int temp = easyxfunctionmain.change2("zjx的五子棋", "是否返回主页并重开？", "提示");
                    if (temp == 1) {
                        msg.x=0,msg.y=0;
                        goto TAG1;
                    } else {
                        msg.x=0,msg.y=0;
                        continue;
                    }
                }
                else if(mx >= 0 && mx <= 800 && my >= 0 && my <= 800)
                {
                    int in_x=locationtranslator.translator(mx);
                    int in_y=locationtranslator.translator(my);
                    chessBoard.PlaceNode(in_x,in_y,id);
                    if (id == BLACK) {
                            easyxfunctionmain.BlackPawn(25 + 41 * (in_x - 1), 24 + 41 * (in_y - 1));

                            id = WHITE;
                        }
                    else {
                            easyxfunctionmain.WhitePawn(25 + 41 * (in_x - 1), 24 + 41 * (in_y - 1));

                            id = BLACK;
                        }
                        //                    cout<<algorithm.Judeger(chessBoard,size)<<endl;
                        //        int temp=chessBoard.ShowBoard()[chessBoard.ShowRecentStep().getLocationX()][chessBoard.ShowRecentStep().getLocationY()].getPlayerId();
                        //        cout<<"id:"<<temp<<"\t"<<"x:"<<chessBoard.ShowRecentStep().getLocationX()<<"\t"<<"y:"<<chessBoard.ShowRecentStep().getLocationY()<<endl;

                        if (algorithm.Judeger(chessBoard, size, mode) == BLACK)
                            /////////////
                        {
                            int temp = easyxfunctionmain.change2("zjx的五子棋", "黑棋胜利!是否复盘？", "提示");
                            if (temp == 0) {
                                goto TAG1;
                            } else {
                                goto REVIEW;
                            }
                        }
                        if (algorithm.Judeger(chessBoard, size, mode) == WHITE) { cout << "WHITE WINS" << endl; }



                }
            }
        }
    }
REVIEW:


    EXIT:
    exit(0);
}

//int main() {
//
//    int size,x,y,id;
//    cin>>size;
//    ChessBoard chessBoard(size);
//    Algorithm algorithm;
//    chessBoard.Display();
//    while(cin>>x>>y>>id){
//        if(x>size||y>size||x<1||y<1){
//            break;
//        }
//        chessBoard.PlaceNode(x,y,id);
//        chessBoard.Display();
////        int temp=chessBoard.ShowBoard()[chessBoard.ShowRecentStep().getLocationX()][chessBoard.ShowRecentStep().getLocationY()].getPlayerId();
////        cout<<"id:"<<temp<<"\t"<<"x:"<<chessBoard.ShowRecentStep().getLocationX()<<"\t"<<"y:"<<chessBoard.ShowRecentStep().getLocationY()<<endl;
//        if(algorithm.Judeger(chessBoard,size)==BLACK) { cout << "BLACK WINS" << endl; }
//        if(algorithm.Judeger(chessBoard,size)==WHITE) { cout << "WHITE WINS" << endl; }//kmp算法版本
//        //        if(algorithm.NaiveScan(chessBoard,x,y,size))
////        {
////            cout<<id<<"wins"<<endl;
////            break;
////        }//广度优先
////
////
////
////
////        stack<ChessNode> temp=chessBoard.ShowRoute();
////
////        while (!temp.empty()) {
////            int sx=temp.top().getLocationX();
////            int sy=temp.top().getLocationY();
////            int sid=temp.top().getPlayerId();
////            for (int i = 0; i < 8; ++i) {
////                if (algorithm.DFS(chessBoard, sx, sy, 0, sid, i)) {
////                    cout << id << "wins" << endl;
////                    exit(0);
////                }
////            }
////
////            temp.pop();
////        }//dfs暴搜版本
////
////
////
////        for (int i = 0; i < 4; ++i) {
////                if (algorithm.DFS_improved(chessBoard, x, y, 0, id, 2*i)) {
////                    cout << id << "wins" << endl;
////                    exit(0);
////                }
////            }//dfs改进版本
//
//
//    }
//}




