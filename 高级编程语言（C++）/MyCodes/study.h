#pragma once
#include "GUI.h"  //����һ�����á�management���ͻ��
using namespace std;
#define up 1
#define down 2
//����ѧϰ��¼��
class study
{
private:
	string name;
	 int start_h;
	int start_m;
	 int end_h;
	int end_m;
	int cost_h;
	int cost_m;
	string text; //ѧϰ��¼
public:
	study(int model);
	study(int model,const string & name);
	study(const study& s);//���ƹ��캯��
	study(string n, int start_h, int start_m, int end_h, int end_m, int cost_h, int cost_m,string text);
	string get_name() { return name; }
	int get_sh() { return start_h; }
	int get_sm() { return start_m; }
	int get_eh() { return end_h; }
	int get_em() { return end_m; }
	int get_ch() { return cost_h; }
	int get_cm() { return cost_m; }
	string get_text() { return text; }
	void count_up();//����ʱ
	void count_down();//����ʱ
	void count_up(const string &name);//����ʱ
	void count_down(const string &name);//����ʱ
	void disp(int x,int y);//չʾ����ѧϰ����
	void draw_clock(int time_x, int time_y, int space);
};

