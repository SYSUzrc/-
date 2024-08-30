#include "record.h"
#include "PushButton.h"
using namespace std;
Record::Record()
{
	record = new list<study>;
	num = 0;
	time_t t;tm tmp;
	time(&t);localtime_s(&tmp, &t);
	month = tmp.tm_mon+1;day = tmp.tm_mday;
}
Record::Record(const Record& r):num(r.num),month(r.month),day(r.day),path(r.path),cost_min(r.cost_min)
{
	record = new list<study>;
	//�����㷨ʵ�����record
	copy(r.record->begin(), r.record->end(), record->begin());
}
Record::~Record()
{
	delete record; //���ݳ�Ա��ָ�룬ָ��list,ֱ��ɾ��list�ͺ�
}
//�����ļ�
bool Record::read_file(const string &user)
{

	path = "./file/" + user + "/ Record_" + to_string(month) + "_" + to_string(day) + ".txt";   //Ŀ���ļ�·��
	/**
		��Ѱ�ļ������Ƿ���ڵ�ǰ���ڵ���־�ļ�������У����������ޣ������´���
		�ļ�����:��һ�д��浱��ѧϰ����
		ÿ1�����δ洢study������
		string name;
		int  start_h;
		int start_m;
		int end_h;
		int end_m;
		int cost_h;
		int cost_m;
		string text
	**/
	ifstream ifs; //�ļ�����������
	ifs.open(path, ios::in);
	if (!ifs.is_open()) {
		cout << "�û����ϴ�ʧ��" << endl;
	}
	else {
		cout << "�û������ļ��򿪳ɹ�!" << endl;
		//��ȡ�ļ�
		ifs >> num;
		for (int i = 0; i < num; i++)
		{
			string name;
			char text[50];
			int start_h, start_m, end_h, end_m, cost_h, cost_m;
			ifs >> name>>start_h >> start_m >> end_h >> end_m >> cost_h >> cost_m;
			ifs.getline(text,sizeof(text));//ֻ��ȡ��һ�С���ʣ�µ�Ϊ����ʱ��
			//ȥ��һ���ո�
			int x =0;
			int p = 0;
			while (text[x] != '\0')
			{
				if (text[x] != ' ' && text[x] != '\t')
					text[p++] = text[x];
				x++;
			}
			text[p] = '\0';
			//д��task��
			study new_study(name, start_h , start_m , end_h , end_m , cost_h , cost_m,string(text));
			record->push_back(new_study); //����ʹ������ȸ��ƣ�����
			cost_min += (cost_h * 60 + cost_m);
		}
		return true;
	}
	return false;
}
//д���ļ�
bool Record::write_file()
{
	/**
		��Ѱ�ļ������Ƿ���ڵ�ǰ���ڵ���־�ļ�������У����������ޣ������´���
		�ļ�����:��һ�д��浱��ѧϰ����
		ÿ1�����δ洢study������
		string name;
		int  start_h;
		int start_m;
		int end_h;
		int end_m;
		int cost_h;
		int cost_m;
	**/
	ofstream ofs;
	ofs.open(path, ios::trunc);//trunc��ɾ���ٴ����ļ���
	ofs << num << endl;
	for (list<study>::iterator it = record->begin(); it != record->end(); it++)
	{
		ofs << it->get_name() << " ";
		ofs << it->get_sh() << " ";
		ofs << it->get_sm() << " ";
		ofs << it->get_eh() << " ";
		ofs << it->get_em() << " ";
		ofs << it->get_ch() << " ";
		ofs << it->get_cm() << " ";
		ofs << it->get_text() << endl;
	}
	//�ر��ļ�
	ofs.close();
	return true;
}
//���ϼ�ʱ
void Record::start_up_study()
{
	study *new_study = new study(up);
	num++;
	record->push_back(*new_study);
	cost_min += (new_study->get_ch()* 60 + new_study->get_cm());
	delete new_study;
}
//����ʱ
void Record::start_down_study()
{
	study* new_study = new study(down);
	num++;
	record->push_back(*new_study);
	cost_min += (new_study->get_ch() * 60 + new_study->get_cm());
	delete new_study;
}
void Record::start_up_study(const string& name)
{
	study* new_study = new study(up,name);
	num++;
	record->push_back(*new_study);
	cost_min += (new_study->get_ch() * 60 + new_study->get_cm());
	delete new_study;
}
void Record::start_down_study(const string& name)
{
	study* new_study = new study(down,name);
	num++;
	record->push_back(*new_study);
	cost_min += (new_study->get_ch() * 60 + new_study->get_cm());
	delete new_study;
}
void Record::show_record()
{
	IMAGE background;
	::loadimage(&background, "./file/background.jpg", 1848 / 3 * 2, 862 / 3 * 2);//���մ��ڹ�����ͼƬ
	PushButton  Esc("����", 1848 / 3 * 2 - 350, 40);
	ExMessage msg;	//������������Ϣ
	int x = 50;
	int y = 50;
	while (1)
	{
		x = 70;
		y = 70;
		BeginBatchDraw();
		::putimage(0, 0, &background);//���Ʊ�����
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		//���ѧϰ��¼
		outtextxy(x+10, y, (string("������һ��ѧϰ:") + to_string(num) + "��").c_str());
		outtextxy(x+10+textwidth((string("������һ��ѧϰ:") + to_string(num) + "��").c_str())+20, y, (string("��") + to_string(cost_min/60) + "Сʱ"+to_string(cost_min%60)+"����").c_str());
		int i = 1;
		for (list<study>::iterator it = record->begin(); it != record->end(); it++)
		{
			y += 50;
			outtextxy(x, y, (to_string(i)+".").c_str());
			it->disp(x+15, y);
			i++;
		}
		if (num < 2)
			outtextxy(x+10, y+60, string("����ѧϰʱ���Ե�Ŷ,�������ͣ�") .c_str());
		else 
			outtextxy(x+10, y + 60, string("����״̬����Ŷ���������֣�").c_str());


		Esc.show();

		FlushBatchDraw();
		//�ȴ��˳�
		peekmessage(&msg, EM_MOUSE);
		if (Esc.Click(msg))
			break;
	}

}

string Record::get_task_name(int i)
{

	list<study>::iterator it = record->begin();
	int cout = 1;
	for (cout = 1; cout < i; cout++)
		it++;
	return it->get_name();
}


void Record::draw_clock(int time_x, int time_y, int space)
{
	time_t t;
	tm tmp;
	time(&t);
	localtime_s(&tmp, &t);
	int h = tmp.tm_hour;
	int m = tmp.tm_min;
	int s = tmp.tm_sec;
	if (h < 10)
		outtextxy(time_x, time_y, ("0" + to_string(h) + ":").c_str());
	else
		outtextxy(time_x, time_y, (to_string(h) + ":").c_str());
	if (m < 10)
		outtextxy(time_x + space, time_y, ("0" + to_string(m)).c_str());
	else
		outtextxy(time_x + space, time_y, to_string(m).c_str());
}
