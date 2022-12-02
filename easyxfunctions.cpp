#include "easyxfunctions.h"
using namespace std;

void easyxfunctions::BGM() {
    mciSendString("open ../materials/yzcw.mp3", nullptr, 0, nullptr);
    mciSendString("play ../materials/yzcw.mp3", nullptr, 0, nullptr);
}
void easyxfunctions::picture_loader(int x, int y, int sizex,int sizey,const char *location) {
    IMAGE img;
    loadimage(&img,location,sizex,sizey, true);
    putimage(x,y,&img);
}
int easyxfunctions:: change2(const char *title, const char *saysomething, const char *hint) {
    HWND hnd = GetHWnd();//获取窗口句柄
    SetWindowText(hnd, title);//设置窗口标题
        //提示
        int is_ok = MessageBox(hnd, saysomething, hint, MB_OKCANCEL);
        if (is_ok == IDOK) {
            return 1;
        } else if (is_ok == IDCANCEL) {
            return 0;
        }
    }
void easyxfunctions:: change1(const char *title, const char *saysomething, const char *hint) {
    HWND hnd = GetHWnd();//获取窗口句柄
    SetWindowText(hnd, title);//设置窗口标题
    //提示
    int is_ok = MessageBox(hnd, saysomething, hint, MB_OK);
}

    void easyxfunctions::BlackPawn(int x, int y) {
        setfillcolor(RGB(34, 34, 34));
        solidcircle(x, y, 15);
    }
void easyxfunctions::BrownPawn(int x, int y){
    setfillcolor(BROWN);
    solidcircle(x, y, 15);
}

    void easyxfunctions::WhitePawn(int x, int y) {
        setfillcolor(RGB(246, 246, 246));
        solidcircle(x, y, 15);
    }

    void easyxfunctions::Button(const char *message, int x_location, int y_location, int height, int width,int charheight) {
        settextstyle(charheight, 0, "楷体");
        settextcolor(RGB(0,0,0));
        setbkmode(TRANSPARENT);
        setfillcolor(BROWN);
        setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
        setlinecolor(RGB(0,0,0));
        roundrect(x_location, y_location, x_location + width, y_location + height, 10, 10);
        int w = textwidth(message);
        int h = textheight(message);
        int tx = x_location + (width - w) / 2;
        int ty = y_location + (height - h) / 2;
        outtextxy(tx, ty, message);}

