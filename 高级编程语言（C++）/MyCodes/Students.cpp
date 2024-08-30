#include "Students.h"
#include"User.h"
#include "Management.h"
#include <random>
#include<string.h>//�����ַ�������
#include <conio.h>//�������̨
#include <windows.h>//���ڿ��Ʋ���̨��ͣʱ��
#include <vector>//ʹ��vector��������
#include<algorithm>//ʹ��STL������
#include<fstream>// �ļ����� 
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//�����ⲿ�ļ�����
extern void title();
extern void menu();
//�����ⲿ�ļ�����
extern vector<Student> stu_v;


//��������
int slogin();
bool findID(vector<Student>,string);

//���캯��
	Student::Student() { 

		//slogin(); 
	};

//��½����
int slogin()
{
	static int err;
	system("cls");  //����
	title();//��ӡҳü
	string NetID;
	string pword;
	//����NetID
	cout << "\t��¼ģʽ : ѧ��" << endl;
	cout << endl << "\t���������NetID :  ";
	cin >> NetID;
	getchar();//��������������һ���س�
	
	//��������:��������������Ż�����ÿ����һ���ַ��������ڿ���̨�д�ӡһ��*
	cout << "\n\t������������� :  ";
	char ch=0;
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

	//��ʼ����ΪNetID,����Ƿ����
	if (NetID != pword)
	{
		err++;
		if (3-err > 0) {//�趨ֻ������������ᣬ����Ҫ�˳����µ�¼
			cout <<endl<<"\n" << "\tNetID��������Ч��\n" << "\t������" << 3 - err << "���������" << "����5����������롣" << endl;
			Sleep(5000);//5�����������
			slogin();
			return err;
		}
		else {
			cout << "���Ļ������ù⡣�����˳��С�����" << endl;
			Sleep(3000);//3s���˳�
			return err;
		}
	}

	//�жϸ�NetID�Ƿ���������ݿ���,NetIDֻ�ܹ���Ա������ѧ�������Լ�����
	int flag = 0;
	if (!findID(stu_v, NetID))
	{
		cout << "\n\n\t��NetID�����ڣ����������룡2����Զ���ת��";
		Sleep(2000);//3�����������
		slogin();
		return err;
	}
	else {
		flag = 1;
	}

	//�����¼�ɹ�������Խ���ѡ��˵�
	if (flag)
	{
		cout << "\n\n\t��¼�ɹ���ҳ������С�����������" << endl;
		Sleep(1000);
		//�ҵ����ݿ��еĶ���Ԫ��
		auto iter = stu_v.begin();
		while (iter != stu_v.end())
		{
			if (iter->NetID == NetID)
			{
				break;
			}
			else 
			{
				++iter;//����������
			}
		}

	sig1:
		Sleep(2000);//2��������ת
		system("cls");  //����
		title();//��ӡҳü
		cout << "\t��¼ģʽ : ѧ��" << endl;
		cout << "\t\t�˵�" << endl;
		cout << "\t\t1 : ����ѧϰϵͳ\n\t\t2 : �޸ĸ�����Ϣ\n\t\t3 : �鿴��ҵ�ɼ�\n\t\t4 : �鿴��ҵ����  \n\t\t5 : �˳�" << endl;
		cout << "\t���������ѡ��  : ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//iter->info();
			iter->to_study();
			goto sig1;  //ת�᱾�����Ŀ�ʼ�����½��в˵�ѡ��
			break;
		case 2:
			iter->setinfo();
			goto sig1;
			break;
		case 3:
			iter->showScores();
			goto sig1;
			break;
		case 4:
			iter->notification();
			goto sig1;
			break;
		case 5:
			cout << "\n\t�����˳�������";
			Sleep(3000);
			system("cls");  //����
			menu();
			return err;
			break;
		default: cout << "\t��Чѡ������˳��� ";
			Sleep(2000);
		}
	}
	return err;
}

//�������ݿ����Ƿ���ڸ�ѧ��
bool findID(vector<Student>  students, string NetID) {
	for (const auto& student : students) {
		if (student.NetID == NetID) {
			return true;
		}
	}
	return false;
}

//��ʼѧϰ
void Student::to_study()
{
	//����һ��Management���ָ��
	Management* new_M = new Management;
	while (new_M->run()) {

	}
	new_M->close();
}


//��ӡѧ����Ϣ
void Student::info() {
	system("cls");  //����
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ѧ��" << endl;
	cout << "\t\t������Ϣ" << endl;
	cout << "\t\t����:"<<name;
	cout << "\n\t\t�Ա�" << sex;
	cout << "\n\t\tNetID:" << NetID;
	cout << "\n\t\t�꼶:" << grade;
	cout << "\n\t\tѧԺ:" << pm;
	cout << "\n\t\t���䣺" << email;
	cout << "\n\t\t�绰��" << phone;
	cout << "\n\n\t\t�밴������˳���"<<endl;
	_getch();//���û�����һ����������������
	Sleep(3000);
}

//������Ϣ
void Student::setinfo() {
	system("cls");  //����
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ѧ��" << endl;
	cout << "\t\t��ǰ������Ϣ" << endl;
	cout << "\t\t����: " << name;
	cout << "\n\t\t�Ա�: " << sex;
	cout << "\n\t\tNetID: " << NetID;         //��ʾ������
	cout << "\n\t\t�꼶: " << grade;
	cout << "\n\t\tѧԺ: " << pm;
	cout << "\n\t\t���䣺" << email;
	cout << "\n\t\t�绰��" << phone;
	cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"<<endl;
	cout << "�������µĸ�����Ϣ��";
	cout << "\n\t\t����: " ;  cin >> name;
	cout << "\n\t\t�Ա�: " ;  cin >> sex;
	cout << "\n\t\tNetID: " ;  cin >> NetID;
	cout << "\n\t\t�꼶: ";  cin >> grade;     //��������
	cout << "\n\t\tѧԺ: ";  cin >> pm;
	cout << "\n\t\t���䣺";  cin >> email;
	cout << "\n\t\t�绰��";  cin >> phone;
	cout << "\n\t\t�޸���ɣ����ڸ������ݿ⡤����" << endl;
	//STL���������Զ�ά�����ݿ�����Ϣ,
	Sleep(4000);//
}

//�鿴�ɼ���ѧ�֡�����
void Student::showScores()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ѧ��" << endl;
	cout << "\n\t\t\t\t     ��������ҵ�ɼ�"<<endl;
	cout << "\t\t----------------------------------------------------------" << endl;
	cout << "\t\t   ��Ŀ  \t|\t��ҵ�ɼ� \t|\t ��ҵ�ȼ�"<<endl;
	cout << "\t\tC++������ƣ�\t|\t   " << cpp[0]<<"\t\t|\t   A+";
	cout << "\n\t\t��ɢ��ѧ��\t|\t   " << dis_math[0]<<"\t\t|\t   A";
	cout << "\n\t\t���ݽṹ��\t|\t   " << data_struct[0]<<"\t\t|\t   A+";
	cout << "\n\t\t����ѧϰ��\t|\t   " << m_learning[0]<<"\t\t|\t   A-";
	cout << "\n\t\tPython��\t|\t   " <<  python[0]<<"\t\t|\t   B+";
	cout << "\n\t\t�ź���ϵͳ��\t|\t   " << sig_sys[0] << "\t\t|\t   A+" << endl;
	cout << "\t\t----------------------------------------------------------" << endl;
	cout << "\n" << endl;
	cout << "\n\n\t�밴������˳���";
	_getch();
	Sleep(500);
}

//�鿴ѧУ���棺ʹ���ļ���ȡ�������Ӹ�Ч
int Student::notification() {
	system("cls");
	//��ȡ�ļ�
	ifstream readfile("notification.txt", ios::in | ios::binary);
	if (!readfile.is_open()) {
		cout << "\tû�й��档  3����Զ����ء�";
		Sleep(2000);
		return -1;
	}

	title();//��ӡҳü
	cout << "\n\t��ҵ����: \n\n";

	string line;//���ж�ȡ
	while (getline(readfile, line)) {
		cout << "\t\t" << line << "\n ";
	}

	cout << "\n\t��ʼ��������ҵ�ɣ�   �밴������˳���";
	_getch();
	readfile.close();  //�ر��ļ�
	return 0; 
}



