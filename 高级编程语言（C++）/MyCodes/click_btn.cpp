#include "click_btn.h"
using namespace std;
click_btn::click_btn(const string& text, int x, int y, int w, int h) :BasicWidget(x, y, w, h), text(text)
{
	return;
}
click_btn::click_btn(const click_btn& btn):BasicWidget(btn.x,btn.y,btn.w,btn.h)
{
	text = btn.text;
}
//���ư�ť
void click_btn::show(int size_x, int size_y)
{
	settextcolor(BLACK);//������ɫ
	setfillcolor(RGB(78, 121, 111));//��ͼ��ص�
	::fillroundrect(x, y, x + w, y + h, 0, 0);//����������Ϊ����
	//���־�����ʾ�ڰ�ť�м�
	int text_x = x + (w - textwidth(text.c_str())) / 2;
	int text_y = y + (h - textheight(text.c_str())) / 2;
	outtextxy(text_x, text_y, text.c_str());
}

bool click_btn::Click(const ExMessage& msg)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) //����ڵ�ǰ������ 
	{
		if (msg.message == WM_LBUTTONDOWN)//������
			return true;
	}
	return false;
}

void click_btn::move_y(int y)
{
	this->y = y; 
}

int click_btn::get_y() const
{
	return y; 
}
