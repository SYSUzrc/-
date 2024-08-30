#include "GUI.h"

//��������
ExMessage Window::m_msg; //���徲̬��Ա
int Window::width;
int Window::height;
HWND Window::m_handle;
//�����ʼ��
Window::Window(int w, int h, int f)
{
	//width = 1848;
	//height = 862;
	width = w;
	height = h;
	m_handle = ::initgraph(width, height, f);
	title = "��ɽ��ѧ��ҵϵͳ";
	SetWindowText(m_handle, title.c_str());//д����
	::setbkmode(TRANSPARENT);//���ø�ͼ�����屳��Ϊ͸����ɫ
}

void Window::beginDraw()
{
	::BeginBatchDraw();
}

void Window::flushDraw()
{
	FlushBatchDraw();
}

inline bool Window::hasMsg()
{
	 return ::peekmessage(&m_msg, EM_MOUSE); 
}

inline const ExMessage& Window::getMsg()
{
	return m_msg; 
}
