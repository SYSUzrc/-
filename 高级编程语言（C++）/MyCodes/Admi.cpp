#include "Admi.h"
#include "Students.h"
#include"User.h"
#include"Teacher.h"
#include<string.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include<algorithm>
#include<fstream>// �ļ����� 
using namespace std;

extern void title();
extern void menu();
extern void printM();
extern vector<Student> stu_v;
extern vector<Teacher> tea_v;

//��½����
int alogin()
{
	static int err;
	system("cls");  //����
	title();//��ӡҳü
	string NetID;
	string pword;
	//����NetID
	cout << "\t��¼ģʽ : ����Ա" << endl;
	cout << endl << "\t��������Ĺ���Ա�˺�:  ";
	cin >> NetID;
	getchar();//��������������һ���س�

	//��������:��������������Ż�����ÿ����һ���ַ��������ڿ���̨�д�ӡһ��*
	cout << "\n\t������������� :  ";
	char ch = 0;
	while ((ch = _getch()) != '\r') { // �س����� '\r'
		if (ch != '\b') { // ��������˸��
			pword.push_back(ch);
			cout << '*';
		}
		else { // �����˸��
			if (!pword.empty()) {
				pword.pop_back();
				cout << "\b \b"; // ɾ������̨�ϵ�һ���ַ�
			}
		}
	}
	//��ʼ����Ϊ123456,����Ƿ����
	if (NetID != "Cpp\0" || pword!="123456\0")
	{
		err++;
		if (3 - err > 0) {//�趨ֻ������������ᣬ����Ҫ�˳����µ�¼
			cout << "\n\n" << "\tNetID��������Ч��\n" << "\t������" << 3 - err << "���������" << "����5����������롣" << endl;
			Sleep(5000);//5�����������
			alogin();
			return err;
		}
		else {
			cout << "���Ļ������ù⡣" << endl;
			return err;
		}
	}

	//�����¼�ɹ�������Խ���ѡ��˵�
	if (1)
	{
		cout << "\n\n\t��¼�ɹ���ҳ������С�����������" << endl;
		Admi a1;//����һ������Ա�����Ե���Admi���еĳ�Ա����
	sig2:
		Sleep(2000);//2��������ת
		system("cls");  //����
		title();//��ӡҳü
		cout << "\t��¼ģʽ : ����Ա" << endl;
		cout << "\t\t���˵���" << endl;
		cout << "\t\t1 : ���ѧ��\n\t\t2 : ɾ��ѧ��\n\t\t3 : �鿴ѧ����Ϣ";
		cout << "\n\t\t4 : ����ѧ���ɼ�\n\t\t5 : �����ʦ\n\t\t6 : ɾ����ʦ";
		cout<<" \n\t\t7 : �鿴��ʦ�б�\n\t\t8 : ��������\n\t\t9 : �鿴����ԤԼ \n\t\t10 : �˳�" << endl; 
		cout << "\t���������ѡ��  : ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			a1.addStu();
			goto sig2;  //���β���������ת�ر������Ŀ�ʼ�����½��в˵�ѡ��
			break;
		case 2:
			a1.deteStu();
			goto sig2;
			break;
		case 3:
			a1.viewStuList();
			goto sig2;
			break;
		case 4:
			a1.mangeSocres();
			goto sig2;
			break;
		case 5:
			a1.addTeacher();
			goto sig2;
			break;
		case 6:
			a1.deteTeacher();
			goto sig2;
			break;
		case 7:
			a1.viewTlist();
			goto sig2;
			break;
		case 8:
			a1.add_Notification();
			goto sig2;
			break;
		case 9:
			a1.viewBooking();
			goto sig2;
			break;
		case 10:
			cout << "\n\t�����˳�������";
			Sleep(3000);
			system("cls");  //����
			menu();
			return err;
			break;
		default: cout << "\t��Чѡ������˳��� ";
			Sleep(1000);
		}
	}
	return err;
}


//��������
int Admi::add_Notification()
{
    system("cls");
    ofstream putf("notification.dat", ios::binary | ios::out | ios::app);
    if (!putf) {
        cerr << "\t�޷��򿪹����ļ�notification!" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
        return -1;
    }
    title();//��ӡҳü
	cout << "\t��¼ģʽ : ����Ա\n" << endl;
    string date;
    cout << "\t�����빫�淢��ʱ�䣺";   
    cin >> date;
    cout << "\n\t\t   �������� : " << date << endl;

    string note;
    cout << "\t�����빫������: \n\t\t";
    cin.ignore(); // ���֮ǰ�����뻺��
    getline(cin, note);
    putf << "_________________________________________________________________   " << date << "\n" << note << "\n\n\n";
    putf.close();//�ر��ļ�
    cout << "\n\t���淢�����..." << endl;
    cin.get();
    system("cls");
    return 0;
}

//���ѧ�������������Ա����ѧ����NetID
void Admi::addStu()
{
	system("cls");
	title();
	cout << "   ��¼ģʽ : ����Ա\n" << endl;
	cout << " ����д���ѧ����Ϣ��" << endl;
	cout << endl << "_______________________________________________________________________________" << endl;
	Student s2;
	cout << "\n\t ������ѧ��NetID           : "; cin >> s2.NetID;
	cout << "\n\t ������ѧ������             : "; cin>>s2.name;
	cout << "\n\t ������ѧ���Ա�             : "; cin >> s2.sex;
	cout << "\n\t ������ѧ��ѧԺ             : "; cin >> s2.pm;
	cout << "\n\t ������ѧ���꼶             : "; cin >> s2.grade;
	cout << "\n\t ������ѧ���绰             : "; cin >> s2.phone;
	cout << "\n\t ������ѧ������             : "; cin >> s2.email;
	cout << endl << "_______________________________________________________________________________" << endl;
	//�������Ķ���������ݿ���
	stu_v.push_back(s2);
	cout << "�������ѧ��"<<s2.name<<"������������"; 
	Sleep(2000);//���ӵ���һ��
	cout << endl << " ѧ����ӳɹ���"; cin.get();
}

//ɾ��ѧ�������������Աɾ��ѧ��
void Admi::deteStu()
{
	system("cls");
	title();
	cout << "    ��¼ģʽ : ����Ա\n" << endl;
	cout << endl << "_______________________________________________________________________________" << endl;
	string id;
	cout << "������Ҫɾ��ѧ����NetID:";
	cin >> id;
	//�ҵ����ݿ��еĶ���Ԫ�ز�ɾ��
	auto iter = stu_v.begin();
	int flag = 0;//flag���ڱ�ʾ��ѧ���Ƿ������ݿ���
	while (iter != stu_v.end())
	{
		if (iter->NetID == id)
		{
			flag = 1;
			iter = stu_v.erase(iter);//��iter���շ���ֵ
			break;
		}
		else
		{
			iter++;//����������
		}
	}
	if (flag == 1) {
		cout << "\t��ɾ����ѧ��" << iter->name << "��" << endl;
	}
	else {
		cout << "\t��ѧ�������ڣ�";
	}
	_getch();
	cout << "�밴��������ء�����" << endl;
	Sleep(2000);
}

//�鿴ѧ���б�����Ա��Ȩ�޲鿴����ѧ�������
void Admi::viewStuList()
{
	system("cls");
	title();
	cout << "   ��¼ģʽ : ����Ա\n" << endl;
	cout << "\t\t\t  ��ѧ����Ϣ��" << endl;
	cout << "_______________________________________________________________" << endl;
	cout << "\t����\t   NetID   \t�Ա�\t�꼶";
	cout << endl << "_______________________________________________________________" << endl;
	auto iter = stu_v.begin();
	while (iter != stu_v.end())
	{
		cout << "\t" << iter->name << "\t   " << iter->NetID << "\t" << iter->sex << "\t" << iter->grade <<endl;
		iter++;//����������
	}
	cout <<endl<< "\n\t�밴��������ء�����";
	_getch();
	Sleep(100);
}

// ��ʽ����ӡ����
void print(const std::string& menuItem) {
	const int width = 60; // ���
	std::string border(width, '-'); // �� '-' ������ɵı߿�
	int padding = (width - menuItem.size()) / 2 - 1; // �������ߵ����ռ�
	std::string paddingSpaces(padding, ' ');

	std::cout << "|" << paddingSpaces << menuItem << paddingSpaces;
	// �������Ϊ�������ұ����ռ����߶�һ���ո�
	if (menuItem.size() % 2 != 0) {
		std::cout << " ";
	}
	std::cout << "|" << std::endl;
}

//����ѧ���ɼ�
void Admi::mangeSocres()
{
	system("cls");
	title();
	cout << "\t��¼ģʽ : ����Ա\n" << endl;
	string id;
	cout << "\t������Ҫ���ĳɼ�ѧ����NetID : ";
	cin >> id;
	auto it = stu_v.begin();
	int flag = 0;//flag�����ж��Ƿ���ڴ�ѧ��
	while (it != stu_v.end())  //ʹ��STL�����������ݿ����ҵ���Ҫ���ĳɼ���ѧ��
	{
		if (it->NetID == id)
		{
			flag = 1;
			break;
		}
		it++;
	}
	if (!flag) //�����ݿ��в����ڴ�ѧ�����˳�����
	{
		cout << endl << "\t��ѧ�������ڣ������˳�������" << endl;
		Sleep(2000);
		return;
	}
	//�����ݿ��д��ڴ�ѧ��,���һ�����ĳɼ�
	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout <<endl << border << endl;
	// ��ӡ�˵���
	print("ѧ����ǰ�ɼ�");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;
	cout << "\t\tC++�������\t\t" << it->cpp[0];
	cout << "\n\t\t���ݽṹ\t\t" << it->data_struct[0];
	cout << "\n\t\t��ɢ��ѧ\t\t" << it->dis_math[0];
	cout << "\n\t\tPython\t\t\t" << it->python[0];
	cout << "\n\t\t����ѧϰ\t\t" << it->m_learning[0];
	cout << endl << "\n\t�������µĳɼ���\n";
	cout << "\t\tC++������� : ";      cin >> it->cpp[0];
	cout << "\n\t\t���ݽṹ : ";          cin >> it->data_struct[0];
	cout << "\n\t\t��ɢ��ѧ : ";          cin >> it->dis_math[0];
	cout << "\n\t\tPython : ";              cin >> it->python[0];
	cout << "\n\t\t����ѧϰ : ";          cin >> it->m_learning[0];
	cout << endl << "\n\t��ҵ�ɼ�������ɡ�����" << endl;
	cin.get();
	return;
}

//����Ա�����ʦ
void Admi::addTeacher()
{
	system("cls");
	title();
	cout << "  ��¼ģʽ : ����Ա\n" << endl;
	cout << " ����д��ӽ�ʦ��Ϣ��" << endl;
	cout << endl << "_______________________________________________________________________________" << endl;
	Teacher t2;
	cout << "\n\t ��ʦNetID          : "; cin >> t2.NetID;
	cout << "\n\t ��ʦ����             : "; cin >> t2.name;
	cout << "\n\t ��ʦ�Ա�             : "; cin >> t2.sex;
	cout << "\n\t ��ʦ����             : "; cin >> t2.pm;
	cout << "\n\t ���ڿγ�             : "; cin >> t2.subject;
	cout << "\n\t ��ʦְ��             : "; cin >> t2.jobtitle;
	cout << "\n\t ��ʦ�绰             : "; cin >> t2.phone;
	cout << "\n\t ��ʦ����             : "; cin >> t2.email;
	cout << endl << "_______________________________________________________________________________" << endl;
	//�������Ķ���������ݿ���
	tea_v.push_back(t2);
	cout << "   ������ӽ�ʦ" << t2.name << "������������";
	Sleep(2000);//���ӵ���һ��
	cout << endl << "   ��ʦ��ӳɹ���"; cin.get();
}

//����Ա��Ȩ��ɾ����ʦ
void Admi::deteTeacher()
{
	system("cls");
	title();
	cout << "    ��¼ģʽ : ����Ա\n" << endl;
	cout << endl << "_______________________________________________________________________________" << endl;
	string id;
	cout << "\t������Ҫɾ����ʦ��NetID:";
	cin >> id;
	//�ҵ����ݿ��ж�Ӧ�Ľ�ʦ��ɾ��
	auto iter = tea_v.begin();
	int flag = 0;//flag���ڱ�ʾ��ѧ���Ƿ������ݿ���
	while (iter != tea_v.end())
	{
		if (iter->NetID == id)
		{
			flag = 1;
			iter = tea_v.erase(iter);//��iter���շ���ֵ
			break;
		}
		else
		{
			iter++;//����������
		}
	}
	if (flag == 1) {
		cout << "\t��ɾ���˽�ʦ��" << iter->name << "��" << endl;
	}
	else {
		cout << "\t�˽�ʦ�����ڣ�";
	}
	cout << "\n\n\t�밴��������ء�����"<<endl;
	_getch();
	Sleep(2000);
}

//����Ա��Ȩ�޲鿴ȫ���ʦ��Ϣ
void Admi::viewTlist()
{
	system("cls");
	title();
	cout << "   ��¼ģʽ : ����Ա\n" << endl;
	cout << "\t\t\t     ����ʦ��Ϣ��" << endl;
	cout << "_________________________________________________________________________________" << endl;
	cout << "\t����\t   ���� \t�Ա�\t      ����  \t  ���ڿγ�  \tְ��";
	cout << endl << "_________________________________________________________________________________" << endl;
	auto iter = tea_v.begin();
	while (iter != tea_v.end())
	{
		cout << "\t" << iter->name << "\t   " << iter->NetID << "\t       " << iter->sex << "      " <<   iter->pm  << "  " <<   iter->subject  <<" \t"<<iter->jobtitle;
		iter++;//����������
	}
	cout << endl << "\n\t�밴��������ء�����";
	_getch();
	Sleep(100);
}


//����Ա��Ȩ�޲鿴ȫУ����ԤԼ���
void Admi::viewBooking()
{
		system("cls");
		title();//��ӡҳü
		//��ȡ�ļ�
		ifstream readfile("bookingroom1.dat");
		if (!readfile.is_open()) {
			cout << "\n\tû��ԤԼ��Ϣ��3����Զ����ء�";
			Sleep(3000);
			return ;
		}

		//��ӡ����
		const int menuWidth = 60;
		string border(menuWidth, '-'); // ʹ�� '-' �����߿�
		// ��ӡ�˵��Ķ����߿�
		cout << endl << border << endl;
		// ��ӡ�˵���
		print("���ó���ԤԼ��Ϣ");
		// ��ӡ�˵��ĵײ��߿�
		cout << border << endl;
		cout << "     У�� " << "   ԤԼ��" << "  �������� " << " ԤԼʱ��"<<endl;
		string line;//���ж�ȡ
		while (getline(readfile, line)) {
			cout << "  " << line << "\n ";
		}

		cout << "\n\t�밴������˳���";
		_getch();
		readfile.close();  //�ر��ļ�
		return;
}