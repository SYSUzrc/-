#include "Task_list.h"
#include "GUI.h"
using namespace std;

#define undo 0
#define done 1
Task_list::Task_list()
{
	tasks_num = finished_num = unfinished_num = 0;
	tasks = new vector<task>; 
}
Task_list::Task_list(const Task_list& t)
{
	tasks_num = t.tasks_num;
	finished_num = t.finished_num;
	unfinished_num = t.unfinished_num;
	path = t.path;
	//���vector
	tasks = new vector<task>;
	for (vector<task>::iterator it = t.tasks->begin(); it != t.tasks->end(); it++)
	{
		tasks->push_back(task(*it));
	}
}
//��ȡ�б�
bool Task_list::read_file(const string &user)
{
	//���ļ�
	/*�涨�ļ���ʽ:
	file_name: user/Task_list.txt
	��һ��:tasks_num
	��ÿһ�д���һ������
	string task_name; //
	int status;  //״̬
	string tips;
	*/
	path = "./file/" + user + "/Task_list.txt";
	ifstream ifs; //�ļ�����������
	ifs.open(path, ios::in);
	if (!ifs.is_open()) {
		cout << "�û������ʧ��" << endl;
		string dir = "./file/" + user;
		if (CreateDirectory(dir.c_str(), NULL)) 
			cout << "�û������ļ��д����ɹ���" << endl;
		else 
			cout << "�û������ļ��д���ʧ��" << endl;
	}
	else {
		cout << "�û�����򿪳ɹ�!" << endl;
		//��ȡ�ļ�
		ifs >> tasks_num;
		for (int i = 0; i < tasks_num; i++)
		{	
			string name;
			int status;
			char tips[50];
			ifs >> name;
			ifs >> status;
			ifs.getline(tips, sizeof(tips));
			//д��task��
			task new_task(name, status,tips);
			tasks->push_back(new_task);
			//��¼��Ŀ
			if (status == 0) unfinished_num++;
			else if (status == 1) finished_num++;
		}
		
		return true;
	}
	return false;
}

//�������嵥д���ļ�
bool Task_list::write_file()
{
	/*�涨�ļ���ʽ:
	file_name: Task_list.txt
	��һ��:tasks_num
	��ÿһ�д���һ������
	string task_name; //
	int status;  //״̬
	*/
	ofstream ofs;
	ofs.open(path, ios::trunc);//��ɾ���ٴ����ļ���
	ofs << tasks_num << endl;
	for (vector<task>::iterator it = tasks->begin(); it != tasks->end(); it++)
	{
		ofs << it->get_name() << "\t";
		ofs << it->get_status() << "\t";
		ofs	<< it->get_tips() <<endl;
	}
	//�ر��ļ�
	ofs.close();
	return true;
}

string Task_list::get_status(int index)
{
	if ((*tasks)[index].get_status() == 0)
	{
		return "\0";
	}
	else
		return "��";
}

string Task_list::get_task_name(int index)
{
	vector<task>::iterator it = tasks->begin();
	int cout = 1;
	for (cout = 1; cout < index; cout++)
		it++;
	return it->get_name();
}

//�������
void Task_list::add()
{
	if (tasks_num > 8)
	{
		MessageBox(Window::m_handle, "������ҵ̫���ˣ�����ɼ����ɣ�", "̫���ˣ���������", MB_OK);
		return;
	}
	char name[30];
	InputBox(name, 30, "��������:");
	char tips[50];
	InputBox(tips, 50, "��������:");
	task new_T(name,"��ֹ����:"+string(tips));
	tasks->push_back(new_T);
	tasks_num++;
	unfinished_num++;
}


//ת��ĳ������״̬
void Task_list::set_status(int index)
{
	vector<task>::iterator it = tasks->begin();
	for (int i = 1; i < index; i++) it++;
	if (it->set_status() == done)
	{
		finished_num++;
		unfinished_num--;
	}
	else {
		finished_num--;
		unfinished_num++;
	}
}

//ɾ������
void Task_list::del(int index)
{
	//ɾ������
	vector<task>::iterator it1; //�����������ڲ���task
	int num = 1;
	for (it1 = tasks->begin(); num < index; it1++)
		num++;
	if (it1->get_status() == done) finished_num--;
	else unfinished_num--;
	//ɾ��
	tasks->erase(it1);
	tasks_num--;
}

//�޸�����
void Task_list::modify(int index)
{
	vector<task>::iterator it = tasks->begin(); //�����������ڲ���
	for (int i = 1; i < index; i++, it++);
	char new_tips[30];
	InputBox(new_tips, 30, "tips:");
	it->change_tips("��ע:"+string(new_tips));
	MessageBox(Window::m_handle, "�޸ĳɹ���", "��ϲ�㣡", MB_OK);
}

//�����嵥չʾ
/*
	outtextxy(text_x, text_y, text.c_str());
	settextcolor(BLACK);//������ɫ
	settextstyle(0,0, "����");//����������ʽ
*/
void Task_list::disp()
{
	int text_x = 80;
	int text_y = 60;
	vector<task>::iterator it = tasks->begin();
	string s;
	if (tasks->begin() == tasks->end()) 
	{ 
		s = "��ǰ������Ϊ�գ������������ɣ�";
		outtextxy(text_x, text_y, s.c_str());
		return; 
	}
	else 
	{
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		int space = 80;
		s = "��������:";	
		outtextxy(text_x, text_y,s.c_str());		
		outtextxy(text_x+space+20, text_y, to_string(tasks_num).c_str());
		s = "�����:";     
		outtextxy(text_x+200, text_y, s.c_str());	
		outtextxy(text_x+200+space, text_y, to_string(finished_num).c_str());
		s = "δ���:";	
		outtextxy(text_x+400, text_y, s.c_str());
		outtextxy(text_x+400+space, text_y, to_string(unfinished_num).c_str()); 
		for (it; it != tasks->end(); it++)
		{
			text_y += 30;
			it->disp(text_x,text_y);
		}
	}
}

