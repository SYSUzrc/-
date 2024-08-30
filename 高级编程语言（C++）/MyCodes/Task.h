#pragma once
#include "heads.h"
using namespace std;

#define undo 0
#define done 1
class task
{
private:
	string task_name="\0"; //������
	int m_status=0;  //״̬,0��ʾδ��ɣ�1��ʾ���
	string tips;//��ע
public:
	task(){}
	task(const task& t);
	task(const string& name, int status, const string& tops);
	task(const string& name,const string&tips);
	~task() {}
	string get_name()const { return task_name; }
	int get_status()const { return m_status; }
	string get_tips()const { return tips; }
	void change_tips(const string& new_tips) { tips = new_tips; }
	void disp(int x,int y) const;
	int set_status(); //���������״̬
};

