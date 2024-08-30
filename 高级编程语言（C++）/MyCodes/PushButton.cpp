#include "PushButton.h"
using namespace std;
PushButton::PushButton(const string& text, int x, int y, int w, int h) :BasicWidget(x, y, w, h),text(text)
{
	return;
}
PushButton::PushButton(const PushButton& btn) : BasicWidget(btn.x, btn.y, btn.w, btn.h)
{
	text = btn.text;
}
//���ư�ť
void PushButton::show(int size_x,int size_y)
{
	settextcolor(BLACK);//������ɫ
	settextstyle(size_x, size_y, "����");//����������ʽ
	setfillcolor(RGB(150, 95, 50));//��ͼ��ص�
	::fillroundrect(x-6,y,x+w+6,y+h,10,10);//ǰ�ĸ����������ϡ��ҡ��µı߿�λ�ã�����������Ϊ����
	//���־�����ʾ�ڰ�ť�м�
	int text_x =x+ (w - textwidth(text.c_str()))/2;
	int text_y = y + (h - textheight(text.c_str())) / 2;
	outtextxy(text_x, text_y, text.c_str());
}
bool PushButton::Click(const ExMessage &msg)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h) //����ڵ�ǰ������ 
	{
		if (msg.message == WM_LBUTTONDOWN)//������
		return true;
	}
	return false;
}
