//
// Created by 50207 on 2022/12/1.
//

#include "pages.h"
using namespace std;

void pages::page1() {
    easyxfunctions easyxfunctions1;
    setbkcolor(RGB(255,255,255));
    cleardevice();
    easyxfunctions1.picture_loader(0,0,1000,1000,"../materials/backgropund1.jpg");
    easyxfunctions1.Button("��������ѽ��",300,300,100,700,100);
    easyxfunctions1.Button("PVP!",600,500,100,300,50);
    easyxfunctions1.Button("PVE��",600,650,100,300,50);
    easyxfunctions1.Button("EVE��",600,800,100,300,50);
    easyxfunctions1.Button("�˳���Ϸ",100,900,100,200,30);
}
void pages::pageboard() {
    easyxfunctions easyxfunctions2;
    setbkcolor(RGB(255,255,255));
    cleardevice();
    easyxfunctions2.picture_loader(0,0,1000,1000,"../materials/backgropund1.jpg");
    easyxfunctions2.picture_loader(0,0,800,800,"../materials/thehboard.png");
    easyxfunctions2.Button("������",830,80,100,170,50);
    easyxfunctions2.Button("����",830,500,100,170,50);
    easyxfunctions2.Button("remake",830,700,100,170,50);
}
void pages::pageboardeve() {
    easyxfunctions easyxfunctions2;
    setbkcolor(RGB(255,255,255));
    cleardevice();
    easyxfunctions2.picture_loader(0,0,1000,1000,"../materials/backgropund1.jpg");
    easyxfunctions2.picture_loader(0,0,800,800,"../materials/thehboard.png");
    easyxfunctions2.Button("������",830,80,100,170,50);
    easyxfunctions2.Button("��һ��",830,500,100,170,50);
    easyxfunctions2.Button("remake",830,700,100,170,50);
}
void pages::page_switch() {
    easyxfunctions easyxfunctionss;
    setbkcolor(RGB(255,255,255));
    cleardevice();
    easyxfunctionss.picture_loader(0,0,1000,1000,"../materials/backgropund1.jpg");
    easyxfunctionss.Button("ģʽѡ��",200,150,150,600,100);
    easyxfunctionss.Button("����",300,550,125,400,80);
    easyxfunctionss.Button("�޽���",300,700,125,400,80);
    easyxfunctionss.Button("���˵�",300,850,125,400,80);

}
void pages::page_review() {
    easyxfunctions easyxfunctions2;
    setbkcolor(RGB(255,255,255));
    cleardevice();
    easyxfunctions2.picture_loader(0,0,1000,1000,"../materials/backgropund1.jpg");
    easyxfunctions2.picture_loader(0,0,800,800,"../materials/thehboard.png");
    easyxfunctions2.Button("������",830,80,100,170,50);
    easyxfunctions2.Button("��һ��",830,500,100,170,50);
    easyxfunctions2.Button("remake",830,700,100,170,50);
}