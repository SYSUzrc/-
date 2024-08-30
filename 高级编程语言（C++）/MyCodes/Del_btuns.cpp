#include "Del_btuns.h"
using namespace std;

Del_btn::Del_btn(int x, int y, int w, int h) :BasicWidget(x, y, w, h), text("��")
{
	return;
}
Del_btn::Del_btn(const Del_btn& btn) : BasicWidget(btn.x, btn.y, btn.w, btn.h)
{
	text = ("x");
}
//���ư�ť
void Del_btn::show(int size_x, int size_y)
{
	settextcolor(BLACK);//������ɫ
	setfillcolor(RGB(80, 130, 110));//������ɫ
	::fillroundrect(x, y, x + w, y + h, 90, 90);//����������Ϊ����
	//���־�����ʾ�ڰ�ť�м�
	int text_x = x + (w - textwidth(text.c_str())) / 2;
	int text_y = y + (h - textheight(text.c_str())) / 2;
	outtextxy(text_x, text_y, text.c_str());
}
bool Del_btn::Click(const ExMessage& msg)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) //����ڵ�ǰ������ 
	{
		if (msg.message == WM_LBUTTONDOWN)//������
			return true;
	}
	return false;
}
