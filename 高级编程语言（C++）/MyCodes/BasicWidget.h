#pragma once
#include "heads.h"
// "BasicWidget.h"
using namespace std;
//��ģ�飬�����
//��ģ����õ��̳С��麯���ȹ���
class BasicWidget
{
protected: //�����࣬��������
	int x;
	int y;
	int w;
	int h;
public:
	BasicWidget(int x=0, int y=0, int w=40, int h=30);//����
	BasicWidget(const BasicWidget& m);
	virtual ~BasicWidget() {}
	virtual void show(int size_x, int size_y)=0;//���麯��
};

