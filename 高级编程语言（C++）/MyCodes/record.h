#pragma once
#include "study.h"
#include "heads.h"
using namespace std;
//ѧϰ��¼��
// ����ֻ��Ҫ��¼ÿ��ѧϰ�ճ̣�����Ҫɾ������
//��ʹ��������

class Record
{
private:
	list<study>* record;  
	int num;
	//date ����
	int month;
	int day;
	string path;//�洢���ļ�·��
	int cost_min;
public:
	Record();//���캯��
	Record(const Record& r);//���ƹ��캯��
	~Record();
	bool read_file(const string &user);
	bool write_file();
	void start_up_study();//�������ϼ�ʱ
	void start_down_study();//�������¼�ʱ
	//������죨ʡȥ�����Ŀ���ѧϰ��
	void start_up_study(const string& name);//�������ϼ�ʱ
	void start_down_study(const string&name);//�������¼�ʱ
	void show_record();
	string get_task_name(int i);
	void draw_clock(int time_x, int time_y, int space);
};