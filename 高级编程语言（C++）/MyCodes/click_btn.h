#pragma once
#include "BasicWidget.h"
using namespace std;
class click_btn :
    public BasicWidget
{
private:
    string text; //��������
public:
    // ���캯������ʼ����ť��λ�á���С����ʾ���ı���Ĭ�ϴ�СΪ 20x20
    click_btn(const string& text="\0", int x = 0, int y = 0, int w = 20, int h = 20);
    click_btn(const click_btn& btn);
    ~click_btn(){}
    void show(int size_x=0, int size_y=0) override;  // �����麯����������ʾ��ť
    bool Click(const ExMessage& msg);// ���������¼����ж�����Ƿ����˰�ť
    void move_y(int y);// �ƶ���ť��������
    int get_y()const;// ��ȡ��ť��������
};


