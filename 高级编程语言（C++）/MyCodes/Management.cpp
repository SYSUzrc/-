#include "Management.h"
using namespace std;

//�������ʼ�����ڴ˽��и������϶�ȡ
Management::Management()
{
	//��ȡ�û��б�
	width = 1848 / 3 * 2;
	height = 862 / 3 * 2;
	load_userList();
	Window GUI(width, height, EX_SHOWCONSOLE||EX_NOCLOSE);//����ͼ��
	//��¼
	if (!load()) exit(0);//ȡ����¼���˳�����
	//��ȡ����¼
	tasks_list = new Task_list;
	tasks_list->read_file(user);
	//��ȡѧϰ��¼
	record = new Record;
	record->read_file(user);
	//��ȡ����ͼ
	width = 1850 / 3 * 2;
	height = 850 / 3 * 2;
	::loadimage(&background1, "./file/background.jpg", width, height);//���մ��ڹ�����ͼƬ
	//�����水ť��ʼ��
	//�ҷ��˵���ť
	menu_btns = new vector<PushButton>;
	menu_btns->push_back(PushButton("����ʱ", width - 550, 33));//λ�õ�x,y����
	menu_btns->push_back(PushButton("����ʱ", width - 450, 33));
	menu_btns->push_back(PushButton("���ռ�¼", width - 350, 33));
	menu_btns->push_back(PushButton("�˳�", width - 250, 33));
	//��ʼ��Task_list�򹳴���  Del_btns����¼ɾ����
	Tasks_btns = new vector<click_btn>;
	Study_btns = new vector<PushButton>;
	Del_btns = new vector<Del_btn>;
	Modify_btns = new vector<PushButton>;
	int num = tasks_list->get_num();
	int c_x = 80;
	int y = 90;
	int d_x = 650;
	for (int i = 0; i < num; i++, y += 30)
	{
		Tasks_btns->push_back(click_btn("\0", c_x,y));
		Study_btns->push_back(PushButton("��ʼѧϰ", d_x-80, y,70,20));
		Del_btns->push_back(Del_btn( d_x, y));
		Modify_btns->push_back(PushButton("ѧϰ��¼", d_x + 32, y, 70, 20));
	}
	add_btns=new click_btn("+", c_x, y);//��Ӵ�������İ�ť
}

//��������
Management::~Management()
{
	delete menu_btns;
	delete tasks_list;
	delete record;
	delete Tasks_btns;
	delete Del_btns;
	delete Study_btns;
	delete Modify_btns;
	delete add_btns;
}

//��¼����
bool Management::load()
{
	IMAGE png;
	::loadimage(&png, "./file/background1.jpg", width, height);
	PushButton P("*������ҵ֮��*", width / 2 - 80, height - 350,150,50);

	PushButton esc("*һ����ѧ*", width / 2 - 80, height-280,150,50);
	ExMessage msg;
	//�ȴ����
	while (1)
	{
		BeginBatchDraw();
		::putimage(0, 0, &png);//���Ʊ�����
		P.show();//��ʾ����
		
		esc.show();
		FlushBatchDraw();
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (P.Click(msg))//��¼
			{
				//ѭ�� ʹ���Զ�γ��Ե�¼
				while (1)
				{
					//�����û���
					char name[10];
					InputBox(name, 10, "�������û�����  ");
					//�Ƿ���ڸ��û���
					if (find_user(name))//���û�
					{
						user = name;
						return true;
					}
					else//�޴��û�
					{
						//��ʾ�����������û�
						int order;
						order = MessageBox(Window::m_handle, "��ѯ�޸��û�����->�������û� ��->�������� ȡ��->�˳�", "��ʾ", MB_YESNOCANCEL);
						if (order == IDYES)
						{
							user = name;
							users_list.push_back(user);
							write_userList();
							//���Ӹ��û���д�û��嵥
							return true;
						}
						else if (order == IDNO)//����
						{
							continue;
						}
						else if (order == IDCANCEL)
						{
							break;
						}
					}
				}
			}
			
			else if (esc.Click(msg))
			{
				return false;
			}
		}
	}
}
//��ȡ�û��б�
void Management::load_userList()
{
	ifstream ifs; //�ļ�����������
	ifs.open("./file/users_list.txt", ios::in);
	if (!ifs.is_open()) cout << "�û��嵥��ʧ��" << endl;
	else {
		cout << "�û��嵥�򿪳ɹ�!" << endl;
		//��ȡ�ļ�
		while (1)
		{
			string name;
			if (!(ifs >> name))
				break;
			else
				users_list.push_back(name);
		}
	}
}

void Management::write_userList()
{
	ofstream ofs;
	ofs.open("./file/users_list.txt", ios::trunc);//trunc��ɾ���ٴ����ļ���
	for (vector<string>::iterator it = users_list.begin(); it != users_list.end(); it++)
		ofs << (*it) << endl;
	//�ر��ļ�
	ofs.close();
}

bool Management::find_user(const string& user)
{
	if (find(users_list.begin(), users_list.end(), user) != users_list.end())
	{
		return true;
	}
	else return false;
}

void Management::study(int model)
{
	//�������棺����ѧϰ���ݣ�ѧϰģʽ��ѧϰʱ��
	switch(model)
	{
	case 1://�����ʱģʽ
		record->start_up_study();
		break;
	case 2://����ʱģʽ
		record->start_down_study();
		break; 
	}
}

//���������й����嵥ѡ��
bool Management::run()
{
	ExMessage msg;	//������������Ϣ
	peekmessage(&msg, EM_MOUSE);
	int click = 0;
	while (true)
	{
		//ҳ��һ�����������
		BeginBatchDraw();
		draw_page1();
		//����������һ�������Ϣ�ǵ��ʱ������delayһ��
		if (msg.message == WM_LBUTTONDOWN)
			Sleep(5 * 50);//0.25s
		peekmessage(&msg, EM_MOUSE);
		//1:����ʱ 2������ʱ 3:����״̬ 
		click = menu_click(msg);
		if (click)
		{
			switch (click)
			{
			case 1://ѧϰ��ʱ���� 
				study(click);
				break;
			case 2:
				study(click);
				break;
			case 3:
				record->show_record();
				break;
			case 4:
				cout << "�˳�" << endl;
				return false;
			}
		}
		//��������� �򹳴��
		click = tasks_click(msg);
		if (click)
		{
			tasks_list->set_status(click);
			continue; //һ��ֻ����һ����������continue ���Ч��
		}
		click = del_click(msg);
		if (click)
		{
			del_task(click);
			continue;
		}
		click = modify_click(msg);
		if (click)
		{
			tasks_list->modify(click);
		}
		//����ѧϰ��������
		click = study_click(msg);
		if (click)
		{
			int order = MessageBox(Window::m_handle, "ѡ��ģʽ������ʱ->��  or  ����ʱ->��", "OK",MB_YESNOCANCEL );
			switch (order)
			{
			case IDCANCEL:
				break;
			case IDYES:
			{
				record->start_up_study(tasks_list->get_task_name(click));
				break;
			}
			case IDNO:
				record->start_down_study(tasks_list->get_task_name(click));
				break;
			}
		}
		FlushBatchDraw();
		if (add_btns->Click(msg))
		{
			tasks_list->add();
			//���Ӱ���
			Tasks_btns->clear();
			Del_btns->clear();
			Study_btns->clear();
			Modify_btns->clear();
			int num = tasks_list->get_num();
			int c_x = 80;
			int y = 90;
			int d_x = 650;
			for (int i = 0; i < num; i++, y += 30)
			{

				Tasks_btns->push_back(click_btn("\0", c_x, y));
				Study_btns->push_back(PushButton("��ʼѧϰ", d_x - 80, y, 70, 20));
				Del_btns->push_back(Del_btn(d_x, y));
				Modify_btns->push_back(PushButton("ѧϰ��¼", d_x + 32, y, 70, 20));

			}
			add_btns = new click_btn("+", c_x, y);
		}
	}
	
}

//�ļ��رգ��ڴ˽����¾��ļ�����
bool Management::close()
{
	if(!tasks_list->write_file())  
		return false;
	if (!record->write_file())
		return false;

	record->read_file(user);
	tasks_list->read_file(user);
	return true;
}

//��GUI�����ϻ���ʱ��
void Management::draw_time(int time_x, int time_y, int space)  
{
	time_t t; 
	tm tmp; 
	time(&t); 
	localtime_s(&tmp, &t);
	int h = tmp.tm_hour; //ʱ
	int m = tmp.tm_min; //��
	int s = tmp.tm_sec;
	outtextxy(time_x-111, time_y+30, ("�����ҵ�����������"));
	if (h < 10) 
		outtextxy(time_x, time_y, ("0" + to_string(h) + "��").c_str());
	else 
		outtextxy(time_x, time_y, (to_string(h) + "��").c_str());
	if (m < 10) 
		outtextxy(time_x + space, time_y, ("0" + to_string(m)).c_str());
	else
		outtextxy(time_x + space, time_y, to_string(m).c_str());
}


//�����棺
void Management::draw_page1()
{
	::putimage(0, 0, &background1);//���Ʊ�����
	//���ư���
	disp<vector<PushButton>::iterator>(menu_btns->begin(), menu_btns->end());
	disp<vector<click_btn>::iterator>(Tasks_btns->begin(), Tasks_btns->end());
	disp<vector<PushButton>::iterator>(Study_btns->begin(), Study_btns->end());
	disp<vector<Del_btn>::iterator>(Del_btns->begin(), Del_btns->end());
	disp<vector<PushButton>::iterator>(Modify_btns->begin(), Modify_btns->end());
	//������Ӽ�
	add_btns->show();
	//���Ʊ���¼
	tasks_list->disp();
	//����ʱ��
	settextcolor(WHITE);
	settextstyle(20, 20, "����");
	draw_time(563, 480, 60);
}

//�������click��ȡ
int Management::menu_click(const ExMessage& msg)
{
	int index = 1; //��ʾ��ť˳��
	for (vector<PushButton>::iterator it = menu_btns->begin(); it != menu_btns->end(); it++, index++)
		if (it->Click(msg)) 
			return index;
	return 0;
}

//�����嵥��click��ȡ
int Management::tasks_click(const ExMessage& msg)
{
	int index = 1; //��ʾ��ť˳��
	for (vector<click_btn>::iterator it = Tasks_btns->begin(); it != Tasks_btns->end(); it++, index++)
		if (it->Click(msg)) 
			return index;
	return 0;
}

int Management::study_click(const ExMessage& msg)
{
	int index = 1; //��ʾ��ť˳��
	for (vector<PushButton>::iterator it = Study_btns->begin(); it != Study_btns->end(); it++, index++)
		if (it->Click(msg))
			return index;
	return 0;
}

int Management::del_click(const ExMessage& msg)
{
	int index = 1; //��ʾ��ť˳��
	for (vector<Del_btn>::iterator it = Del_btns->begin(); it != Del_btns->end(); it++, index++)
		if (it->Click(msg))
			return index;
	return 0;
}
int Management::modify_click(const ExMessage& msg)
{
	int index = 1; //��ʾ��ť˳��
	for (vector<PushButton>::iterator it = Modify_btns->begin(); it != Modify_btns->end(); it++, index++)
		if (it->Click(msg))
			return index;
	return 0;
}
//ɾ������
void Management::del_task(int index)
{
	//ȷ����ʾ��
	if (MessageBox(Window::m_handle, string("ȷ��Ҫɾ���ô�����").c_str(), string("������ҵ�Ƿ���ɡ�").c_str(), MB_OKCANCEL) == IDCANCEL) 
		return;
	//�ع�����
	Del_btns->pop_back();
	Study_btns->pop_back();
	Tasks_btns->pop_back();
	Modify_btns->pop_back();
	//ɾ���������
	tasks_list->del(index);
	add_btns->move_y(add_btns->get_y() - 30);
	//��ʾ��
	MessageBox(Window::m_handle, string("���ѳɹ���ɸ���ҵ").c_str(), string("�������ͣ�").c_str(), MB_OK);
}

