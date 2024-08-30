#pragma once
#include "Task.h"
using namespace std;
//�����嵥�࣬��������У��������񣬲�������ɾ�������޸����񡣸���ļ������������ļ�������ļ�
class Task_list
{
private:
	vector<task> *tasks;  //�����嵥��ʹ��vector����,���ļ���  
	int tasks_num;
	int finished_num; //���������
	int unfinished_num; //δ���������
	string path;
public:
	Task_list();
	Task_list(const Task_list& t);
	~Task_list() { delete tasks; }
	bool read_file(const string& user);
	void add();
	void del(int index);
	void modify(int index); // �޸Ĵ���
	void disp();//��ӡ���д���
	void set_status(int index);//ת�ô����״̬
	bool write_file(); //д���ļ�
	int get_num() { return tasks_num; }//��ȡ������
	string get_status(int index); //��ȡ��index������״̬
	string get_task_name(int index);
};



