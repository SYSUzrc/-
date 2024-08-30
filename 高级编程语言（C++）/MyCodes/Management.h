#pragma once
#include "Task_list.h"
#include "record.h"
#include "PushButton.h"
#include "click_btn.h"
#include"Del_btuns.h"
#include "GUI.h"
/*������, ���ڹ������й���
* ����һ������ֻ�ᱻ����һ�Σ����Բ��ظ��ƹ���
*/
class Management
{
private:
	Task_list *tasks_list;        //�����嵥
	string user;                  //�û���---���ڵ�¼
	Record* record;               //���ڼ�¼�������ļ���
	vector<string> users_list;    //�û��б������û��Ƿ����
	vector<PushButton>* menu_btns;//�˵�����İ�ť����
	vector<click_btn>* Tasks_btns;//����İ�ť��������ԶԴ����
	vector<Del_btn>* Del_btns;    //���ɾ����������
	vector<PushButton>* Study_btns;//���ɾ����������
	vector<PushButton>* Modify_btns;//�޸Ĵ���İ�ť
	click_btn *add_btns;
	//ͼ���ĳߴ�
	int width;
	int height;
public:
	Management();
	~Management(); 
	bool run();
	bool load();//��¼
	void load_userList();
	void write_userList();//д�û��嵥�ļ�
	bool find_user(const string& user);
	void draw_page1();//���������
	void study(int model);//ѧϰ��ʱ�������:1Ϊ����ʱ��2Ϊ����ʱ
	int menu_click(const ExMessage &msg); //��ȡ�˵���ť������
	int tasks_click(const ExMessage& msg); //��ȡ����¼������
	int del_click(const ExMessage& msg);//��ȡɾ����������
	int study_click(const ExMessage& msg);
	int modify_click(const ExMessage& msg);
	void del_task(int index);//ɾ��������ļ�
	void draw_time(int time_x, int time_y, int space);
	bool close(); //�رղ�д���ļ�
	IMAGE background1;  //����ͼ
	template <typename it>
	void disp(it in, it out);
};

//ģ�庯�������ڻ��Ƹ��ְ�ť
template<typename it>
inline void Management::disp(it in, it out)
{
		while (in != out)
		{
			in->show();
			in++;
		}
}
