#pragma once
#include "BasicWidget.h"
class Del_btn :
    public BasicWidget
{
private:
    string text; //��������
public:
    Del_btn(int x=0, int y=0, int w = 20, int h = 20);//���캯��
    Del_btn(const Del_btn& btn);//���ƹ��캯��
    ~Del_btn(){}
    void show(int size_x=0, int size_y=0) override;//�����麯��
    bool Click(const ExMessage& msg);//���²���
};

