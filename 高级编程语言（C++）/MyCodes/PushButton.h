#pragma once
#include "BasicWidget.h"
using namespace std;
//�����࣬�̳��Ի���
class PushButton :
    public BasicWidget
{
private:
    string text; //��������
public:
    PushButton(const string &text, int x=0, int y=0, int w = 85, int h = 40);//Ĭ�ϴ�С
    PushButton(const PushButton& btn);//���ƹ��캯��
    ~PushButton(){}
    void show(int size_x=0, int size_y=0) override;//�����麯��
    bool Click(const ExMessage& msg);//���²���
};

