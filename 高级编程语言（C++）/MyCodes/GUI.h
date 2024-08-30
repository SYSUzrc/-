#pragma once
using namespace std;
#include "heads.h"
//GUI����
class Window
{
	friend class study;
	friend class Task_list;
	friend class Management;
public:
	Window(int w, int h, int flag);
	static void beginDraw(); //ȫ�� beginbatch_draw ������ͼ
	static void flushDraw();
	//���ð�����������ʶ����  ����Ϊ����������С����
	//�ж���û�а����Ͳ���
	inline static bool hasMsg();//����ֵ��=0ʱ����Ϣ
	inline  static const ExMessage& getMsg();//get message(); 
private:
	static int width;
	static int height;
	static HWND m_handle; //���ڵľ��,HWND������
	static ExMessage m_msg; //��ȡ��Ϣ ��Ҫ��Ϊ��̬��Ա,��Ҫ����
	string title;//ͼ������
};


