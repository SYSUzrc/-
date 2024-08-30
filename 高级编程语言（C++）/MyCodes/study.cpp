#include "study.h"
#include "PushButton.h"
//����Ϊstudy��Ķ��ֹ��캯�����ڲ�ͬ�Ĵ������ʱ������ò�ͬ�Ĺ��캯��
study::study(string n, int sh, int sm, int eh, int em, int ch, int cm, string text)
{//��¼ѧϰʱ����Ϣ�����ݳ�Ա
	name = n;
	start_h = sh;
	end_h = eh;
	end_m = em;
	cost_h = ch;
	cost_m = cm;
	start_m = em;
	this->text = text;
}

study::study(int model)
{
	start_h = start_m  = end_h = end_m =  cost_h = cost_m = 0;
	switch (model)
	{
	case up:
		count_up();
		break;
	case down:
		count_down();
		break;
	}
}

study::study(int model, const string& name)
{
	start_h = start_m = end_h = end_m = cost_h = cost_m = 0;
	switch (model)
	{
	case up:
		count_up(name);
		break;
	case down:
		count_down(name);
		break;
	}
}

study::study(const study& s)
{
	name = s.name;
	start_h = s.start_h;
	start_m = s.start_m;
	end_h = s.end_h;
	end_m = s.end_m;
	cost_h = s.cost_h;
	cost_m = s.cost_m;
	text = s.text;
}

//����ʱģʽ
void study::count_up()
{
	IMAGE background;
	::loadimage(&background, "./file/background.jpg", 1848 / 3 * 2, 862 / 3 * 2);//���մ��ڹ�����ͼƬ
	//��ȡѧϰĿ��
	char txt[50];
	InputBox(txt, 50, "ѧϰĿ��:");
	name = txt;
	MessageBox(Window::m_handle, string("��ʼ��ʱ��").c_str(), string("��ʾ").c_str(), MB_OK);
	//��ȡ��ʼʱ��
	time_t t;
	tm tmp;
	std::time(&t);
	localtime_s(&tmp, &t);
	start_h = tmp.tm_hour;//ʱ
	start_m = tmp.tm_min;//��

	//�м�ʱ��
	time_t t2=t;
	int x = 80;
	int y = 100;
	int space = 30;
	int dist = 0;
	int start_x = x + 190;//���ʱ��ĳ�ʼ����
	ExMessage msg;	//������������Ϣ
	//��ť����
	PushButton end("����", start_x + 150, y + 150);
	PushButton Pause("��ͣ", start_x - 150, y + 150);
	PushButton Continue("����", start_x - 150, y + 150);//���Ƽ�����ť
	PushButton Esc("�˳�", start_x - 150, y + 150);//���Ƽ�����ť
	while (1)
	{
		//���Ƽ�ʱ����
		BeginBatchDraw();
		::putimage(0, 0, &background);//���Ʊ�����
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		outtextxy(x, y - 50, (string("����ѧϰĿ��: ") + name).c_str());
		outtextxy(x, y, string("��ʱ�У����Ѿ�ѧϰ: ").c_str());
		//����Ѿ�ѧϰ��ʱ��
		t = t2;//����tΪ��һ��ѭ����ʱ��
		time(&t2);//��ȡ����ѭ��ʱ��
		if (t2 - t != 0) dist++; //��������ʱ�䲻һ�£���������ӣ�Ϊ��ʵ����ͣʱ����ֹͣ,�����ۼ���ʽ��
		int h = dist / 3600;
		int m = (dist - 3600 * h) / 60;
		int s = dist % 60;
		if (h < 10)
			outtextxy(start_x, y + 50, ("0" + to_string(h) + ":").c_str());
		else
			outtextxy(start_x, y + 50, (to_string(h) + ":").c_str());
		if (m < 10)
			outtextxy(start_x + space, y + 50, ("0" + to_string(m) + ":").c_str());
		else
			outtextxy(start_x + space, y + 50, (to_string(m) + ":").c_str());
		if (s < 10)
			outtextxy(start_x + 2 * space, y + 50, ("0" + to_string(s)).c_str());
		else
			outtextxy(start_x + 2 * space, y + 50, to_string(s).c_str());
		//��������ͣ��ť�������ť
		Pause.show();
		end.show();
		//�·�Сʱ�ӻ���
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		FlushBatchDraw();
		//����Ƿ��������ͣ
		//��ͣʱ��Ҫ��ʱ�����Ҳ��ͣ
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (Pause.Click(msg))//��ͣ��������
			{
				Continue.show();
				FlushBatchDraw();
				//����
				Sleep(5 * 200);//1s
				while (1)
				{
					peekmessage(&msg, EM_MOUSE);
					if (Continue.Click(msg))
						break;
					if (end.Click(msg))
						break;
				}
			}
			if (end.Click(msg))//������������
			{
				break;
			}
		}
	}
	//������ʱ
	time(&t2);
	localtime_s(&tmp, &t);
	end_h = tmp.tm_hour;//ʱ
	end_m = tmp.tm_min;//��
	//����ѧϰʱ��ʱ��
	cost_h = dist / 3600;
	cost_m = (dist - 3600 * cost_h) / 60;

	//�����������
	
	InputBox(txt, 50, "����д����ѧϰ����");
	text = txt;
	
	//�˳�����
	while (1)
	{
		BeginBatchDraw();
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		::putimage(0, 0, &background);//���Ʊ�����
		outtextxy(x, y - 50, (string("����ѧϰ����:") + name).c_str());
		outtextxy(x, y, string("ѧϰ����������ѧϰʱ��:").c_str());
		outtextxy(start_x, y + 50, (to_string(cost_h) + "Сʱ" + to_string(cost_m) + "����").c_str());
		//����ʱ��
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		Esc.show();
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		outtextxy(x, y + 100, ("ѧϰ���ܣ� " + text).c_str());
		FlushBatchDraw();
		peekmessage(&msg, EM_MOUSE);
		if (Esc.Click(msg))
			break;
	}
}

//����ʱģʽ
void study::count_down()
{
	IMAGE background;
	::loadimage(&background, "./file/background.jpg", 1848 / 3 * 2, 862 / 3 * 2);//���մ��ڹ�����ͼƬ
	//��ȡѧϰĿ��
	char txt[50];
	char get_time[5];
	InputBox(txt, 50, "ѧϰĿ��:");
	InputBox(get_time, 5, "�ƻ�ѧϰʱ��(����):");
	name = txt;
	int aim_sec = atoi(get_time)*60;//��ȡ�ƻ�����
	MessageBox(Window::m_handle, string("��ʼ��ʱ��").c_str(), string("��ʾ").c_str(), MB_OK);
	//��ȡ��ʼʱ��
	time_t t;
	tm tmp;
	std::time(&t);
	localtime_s(&tmp, &t);
	start_h = tmp.tm_hour;//ʱ
	start_m = tmp.tm_min;//��

	//�м�ʱ��
	time_t t2 = t;
	int x = 80;
	int y = 100;
	int space = 30;
	int dist = 0;
	int start_x = x + 190;//���ʱ��ĳ�ʼ����
	ExMessage msg;	//������������Ϣ
	//һЩ��ť����
	PushButton end("��ǰֹͣ", start_x + 150, y + 150);
	PushButton Pause("��ͣ", start_x - 150, y + 150);
	PushButton Continue("����", start_x - 150, y + 150);//���Ƽ�����ť
	PushButton Esc("�˳�", start_x - 150, y + 150);//���Ƽ�����ť
	while (dist<aim_sec)
	{
		//���Ƽ�ʱ����
		BeginBatchDraw();
		::putimage(0, 0, &background);//���Ʊ�����
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		outtextxy(x, y - 50, (string("����ѧϰ����:") + name).c_str());
		outtextxy(x, y, string("��ʱ�У�����Ŀ�꣬����:").c_str());
		//���ʣ��ʱ��
		t = t2;//����tΪ��һ��ѭ����ʱ��
		time(&t2);//��ȡ����ѭ��ʱ��
		if (t2 - t != 0) dist++; //��������ʱ�䲻һ�£�������++��Ϊ��ʵ����ͣʱ����ֹͣ,�����ۼ���ʽ��
		int h = (aim_sec-dist) / 3600;
		int m = ((aim_sec-dist) - 3600 * h) / 60;
		int s = (aim_sec-dist) % 60;
		//���ʱ��
		if (h < 10)
			outtextxy(start_x, y + 50, ("0" + to_string(h) + ":").c_str());
		else
			outtextxy(start_x, y + 50, (to_string(h) + ":").c_str());
		if (m < 10)
			outtextxy(start_x + space, y + 50, ("0" + to_string(m) + ":").c_str());
		else
			outtextxy(start_x + space, y + 50, (to_string(m) + ":").c_str());
		if (s < 10)
			outtextxy(start_x + 2 * space, y + 50, ("0" + to_string(s)).c_str());
		else
			outtextxy(start_x + 2 * space, y + 50, to_string(s).c_str());
		//��������ͣ��ť�������ť
		Pause.show();
		end.show();
		//�·�Сʱ�ӻ���
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		FlushBatchDraw();
		//����Ƿ��������ͣ
		//��ͣʱ��Ҫ��ʱ�����Ҳ��ͣ
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (Pause.Click(msg))//��ͣ��������
			{
				Continue.show();
				FlushBatchDraw();
				//����
				Sleep(5 * 200);//1s
				while (1)
				{
					peekmessage(&msg, EM_MOUSE);
					if (Continue.Click(msg))
						break;
					if (end.Click(msg))
						break;
				}
			}
			if (end.Click(msg))//������������
			{
				break;
			}
		}
	}
	//������ʱ
	time(&t2);
	localtime_s(&tmp, &t);
	end_h = tmp.tm_hour;//ʱ
	end_m = tmp.tm_min;//��
	//����ѧϰʱ��ʱ��
	cost_h = dist / 3600;
	cost_m = (dist - 3600 * cost_h) / 60;
	InputBox(txt, 50, "����д����ѧϰ����");
	text = txt;
	//�ȴ��˳�
	while (1)
	{
		BeginBatchDraw();
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		::putimage(0, 0, &background);//���Ʊ�����
		outtextxy(x, y - 50, (string("����ѧϰĿ��: ") + name).c_str());
		outtextxy(x, y, string("ѧϰ����������ѧϰʱ��: ").c_str());
		outtextxy(start_x, y + 50, (to_string(cost_h) + "Сʱ" + to_string(cost_m) + "����").c_str());
		//����ʱ��
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		outtextxy(x, y + 100, ("ѧϰ���ܣ� " + text).c_str());
		Esc.show();
		FlushBatchDraw();
		peekmessage(&msg, EM_MOUSE);
		if (Esc.Click(msg))
			break;
	}
}

void study::count_up(const string& name)
{
	IMAGE background;
	::loadimage(&background, "./file/background.jpg", 1848 / 3 * 2, 862 / 3 * 2);//���մ��ڹ�����ͼƬ
	//��ȡѧϰĿ��
	this->name = name;
	MessageBox(Window::m_handle, string("��ʼ��ʱ��").c_str(), string("��ʾ").c_str(), MB_OK);
	//��ȡ��ʼʱ��
	time_t t;
	tm tmp;
	std::time(&t);
	localtime_s(&tmp, &t);
	start_h = tmp.tm_hour;//ʱ
	start_m = tmp.tm_min;//��

	//�м�ʱ��
	time_t t2 = t;
	int x = 80;
	int y = 200;
	int space = 30;
	int dist = 0;
	int start_x = x + 190;//���ʱ��ĳ�ʼ����
	ExMessage msg;	//������������Ϣ
	//һЩ��ť����
	PushButton end("����", start_x + 150, y + 150);
	PushButton Pause("��ͣ", start_x - 150, y + 150);
	PushButton Continue("����", start_x - 150, y + 150);//���Ƽ�����ť
	PushButton Esc("�˳�", start_x - 150, y + 150);//���Ƽ�����ť
	while (1)
	{
		//���Ƽ�ʱ����
		BeginBatchDraw();
		::putimage(0, 0, &background);//���Ʊ�����
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		outtextxy(x, y - 50, (string("����ѧϰĿ��: ") + name).c_str());
		outtextxy(x, y, string("��ʱ�У����Ѿ�ѧϰ: ").c_str());
		//����Ѿ�ѧϰ��ʱ��
		t = t2;//����tΪ��һ��ѭ����ʱ��
		time(&t2);//��ȡ����ѭ��ʱ��
		if (t2 - t != 0) dist++; //��������ʱ�䲻һ�£�������++��Ϊ��ʵ����ͣʱ����ֹͣ,�����ۼ���ʽ��
		int h = dist / 3600;
		int m = (dist - 3600 * h) / 60;
		int s = dist % 60;
		if (h < 10)
			outtextxy(start_x, y + 50, ("0" + to_string(h) + ":").c_str());
		else
			outtextxy(start_x, y + 50, (to_string(h) + ":").c_str());
		if (m < 10)
			outtextxy(start_x + space, y + 50, ("0" + to_string(m) + ":").c_str());
		else
			outtextxy(start_x + space, y + 50, (to_string(m) + ":").c_str());
		if (s < 10)
			outtextxy(start_x + 2 * space, y + 50, ("0" + to_string(s)).c_str());
		else
			outtextxy(start_x + 2 * space, y + 50, to_string(s).c_str());
		//��������ͣ��ť�������ť
		Pause.show();
		end.show();
		//�·�Сʱ�ӻ���
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		FlushBatchDraw();
		//����Ƿ��������ͣ
		//��ͣʱ��Ҫ��ʱ�����Ҳ��ͣ
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (Pause.Click(msg))//��ͣ��������
			{
				Continue.show();
				FlushBatchDraw();
				//����
				Sleep(5 * 200);//1s
				while (1)
				{
					peekmessage(&msg, EM_MOUSE);
					if (Continue.Click(msg))
						break;
					if (end.Click(msg))
						break;
				}
			}
			if (end.Click(msg))//������������
			{
				break;
			}
		}
	}
	//������ʱ
	time(&t2);
	localtime_s(&tmp, &t);
	end_h = tmp.tm_hour;//ʱ
	end_m = tmp.tm_min;//��
	//����ѧϰʱ��ʱ��
	cost_h = dist / 3600;
	cost_m = (dist - 3600 * cost_h) / 60;

	char txt[50];
	InputBox(txt, 50, "����д����ѧϰ����");
	text = txt;
	//�˳�����
	while (1)
	{
		BeginBatchDraw();
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		::putimage(0, 0, &background);//���Ʊ�����
		outtextxy(x, y - 50, (string("����ѧϰ����:") + name).c_str());
		outtextxy(x, y, string("ѧϰ����������ѧϰʱ��:").c_str());
		outtextxy(start_x, y + 50, (to_string(cost_h) + "Сʱ" + to_string(cost_m) + "����").c_str());
		//����ʱ��
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		Esc.show();
		outtextxy(x, y + 100, ("ѧϰ���ܣ� " + text).c_str());
		FlushBatchDraw();
		peekmessage(&msg, EM_MOUSE);
		if (Esc.Click(msg))
			break;
	}
}

void study::count_down(const string& name)
{
	IMAGE background;
	::loadimage(&background, "./file/background.jpg", 1848 / 3 * 2, 862 / 3 * 2);//���մ��ڹ�����ͼƬ
	//��ȡѧϰĿ��
	char get_time[5];
	InputBox(get_time, 5, "�ƻ�ѧϰʱ��(����):");
	this->name = name;
	int aim_sec = atoi(get_time) * 60;//��ȡ�ƻ�����
	MessageBox(Window::m_handle, string("��ʼ��ʱ��").c_str(), string("��ʾ").c_str(), MB_OK);
	//��ȡ��ʼʱ��
	time_t t;
	tm tmp;
	std::time(&t);
	localtime_s(&tmp, &t);
	start_h = tmp.tm_hour;//ʱ
	start_m = tmp.tm_min;//��

	//�м�ʱ��
	time_t t2 = t;
	int x = 80;
	int y = 100;
	int space = 30;
	int dist = 0;
	int start_x = x + 190;//���ʱ��ĳ�ʼ����
	ExMessage msg;	//������������Ϣ
	//һЩ��ť����
	PushButton end("��ǰֹͣ", start_x + 150, y + 150);
	PushButton Pause("��ͣ", start_x - 150, y + 150);
	PushButton Continue("����", start_x - 150, y + 150);//���Ƽ�����ť
	PushButton Esc("�˳�", start_x - 150, y + 150);//���Ƽ�����ť
	while (dist < aim_sec)
	{
		//���Ƽ�ʱ����
		BeginBatchDraw();
		::putimage(0, 0, &background);//���Ʊ�����
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		outtextxy(x, y - 50, (string("����ѧϰĿ��: ") + name).c_str());
		outtextxy(x, y, string("��ʱ�У�����Ŀ�꣬����: ").c_str());
		//���ʣ��ʱ��
		t = t2;//����tΪ��һ��ѭ����ʱ��
		time(&t2);//��ȡ����ѭ��ʱ��
		if (t2 - t != 0) dist++; //��������ʱ�䲻һ�£�������++��Ϊ��ʵ����ͣʱ����ֹͣ,�����ۼ���ʽ��
		int h = (aim_sec - dist) / 3600;
		int m = ((aim_sec - dist) - 3600 * h) / 60;
		int s = (aim_sec - dist) % 60;
		//���ʱ��
		if (h < 10)
			outtextxy(start_x, y + 50, ("0" + to_string(h) + ":").c_str());
		else
			outtextxy(start_x, y + 50, (to_string(h) + ":").c_str());
		if (m < 10)
			outtextxy(start_x + space, y + 50, ("0" + to_string(m) + ":").c_str());
		else
			outtextxy(start_x + space, y + 50, (to_string(m) + ":").c_str());
		if (s < 10)
			outtextxy(start_x + 2 * space, y + 50, ("0" + to_string(s)).c_str());
		else
			outtextxy(start_x + 2 * space, y + 50, to_string(s).c_str());
		//��������ͣ��ť�������ť
		Pause.show();
		end.show();
		//�·�Сʱ�ӻ���
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		FlushBatchDraw();
		//����Ƿ��������ͣ
		//��ͣʱ��Ҫ��ʱ�����Ҳ��ͣ
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (Pause.Click(msg))//��ͣ��������
			{
				Continue.show();
				FlushBatchDraw();
				//����
				Sleep(5 * 200);//1s
				while (1)
				{
					peekmessage(&msg, EM_MOUSE);
					if (Continue.Click(msg))
						break;
					if (end.Click(msg))
						break;
				}
			}
			if (end.Click(msg))//������������
			{
				break;
			}
		}
	}
	//������ʱ
	time(&t2);
	localtime_s(&tmp, &t);
	end_h = tmp.tm_hour;//ʱ
	end_m = tmp.tm_min;//��
	//����ѧϰʱ��ʱ��
	cost_h = dist / 3600;
	cost_m = (dist - 3600 * cost_h) / 60;
	char txt[50];
	InputBox(txt, 50, "����д����ѧϰ����");
	text = txt;
	//�ȴ��˳�
	while (1)
	{
		BeginBatchDraw();
		settextcolor(BLACK);//������ɫ
		settextstyle(0, 0, "����");//����������ʽ
		::putimage(0, 0, &background);//���Ʊ�����
		outtextxy(x, y - 50, (string("����ѧϰĿ��: ") + name).c_str());
		outtextxy(x, y, string("ѧϰ����������ѧϰʱ��: ").c_str());
		outtextxy(start_x, y + 50, (to_string(cost_h) + "Сʱ" + to_string(cost_m) + "����").c_str());
		//����ʱ��
		settextcolor(WHITE);
		settextstyle(20, 20, "����");
		draw_clock(563, 480, 60);
		outtextxy(x, y + 100, ("ѧϰ���ܣ� " + text).c_str());
		Esc.show();
		FlushBatchDraw();
		peekmessage(&msg, EM_MOUSE);
		if (Esc.Click(msg))
			break;
	}
}

void study::disp(int x,int y)
{
	x = x + 10;
	outtextxy(x, y+30, ("��¼��"+text).c_str());
	settextcolor(BLACK);//������ɫ
	settextstyle(0, 0, "����");//����������ʽ
	outtextxy(x, y, (name+":").c_str());
	x = x + textwidth((name + ":").c_str()) + 5;
	if (start_h < 10) 
		outtextxy(x , y, ("0" + to_string(start_h)+":").c_str());
	else 
		outtextxy(x, y, (to_string(start_h)+":").c_str());
	x = x + textwidth(("0" + to_string(start_h) + ":").c_str()) + 2;
	if (start_m < 10) 
		outtextxy(x , y, ("0" + to_string(start_m) + "-").c_str());
	else
		outtextxy(x, y, (to_string(start_m) + "-").c_str());

	x = x + textwidth(("0" + (to_string(start_m) + "-")).c_str()) + 2;
	if (end_h < 10) 
		outtextxy(x, y, ("0" + to_string(end_h) + ":").c_str());
	else 
		outtextxy(x, y, (to_string(end_h) + ":").c_str());
	x = x + textwidth(("0" + to_string(end_h) + ":").c_str()) + 2;
	if (end_m < 10)
		outtextxy(x, y, ("0" + to_string(end_m)).c_str());
	else 
		outtextxy(x, y, to_string(end_m).c_str());
}

//ʱ�ӻ��ƺ���
void study::draw_clock(int time_x, int time_y, int space)
{
	time_t t;
	tm tmp;
	time(&t);
	localtime_s(&tmp, &t);
	int h = tmp.tm_hour;
	int m = tmp.tm_min;
	int s = tmp.tm_sec;
	outtextxy(time_x - 111, time_y + 30, ("�����ҵ�����������"));
	if (h < 10)
		outtextxy(time_x, time_y, ("0" + to_string(h) + ":").c_str());
	else
		outtextxy(time_x, time_y, (to_string(h) + ":").c_str());
	if (m < 10)
		outtextxy(time_x + space, time_y, ("0" + to_string(m)).c_str());
	else
		outtextxy(time_x + space, time_y, to_string(m).c_str());
}
