#include "Task.h"

//���캯��1
task::task(const string &name, int status, const string &tips)
{
	task_name = name;
	m_status = status;
	this->tips = tips;
}

//��ȸ��ƹ���
task::task(const task& t)
{
	task_name = t.task_name;
	m_status = t.m_status;
	tips = t.tips;
}

//���캯��2
task::task(const string& name,const string&tips)
{
	task_name = name;
	m_status = undo;
	this->tips = tips;
}

void task::disp(int x,int y)const
{
	settextcolor(BLACK);//������ɫ
	settextstyle(0, 0, "����");//����������ʽ
	string text = "��";
	if(m_status==done)
		outtextxy(x, y, text.c_str());
	x += 30;
	outtextxy(x, y, task_name.c_str()); //�����ҵ����
	x += textwidth(task_name.c_str())+30;
	outtextxy(x, y, tips.c_str());		//�������ʱ��
}

int task::set_status()
{
	if (m_status == done)
	{
		m_status = undo;
		return undo;
	}
	else
	{
		m_status = done;
		return done;
	}
}
