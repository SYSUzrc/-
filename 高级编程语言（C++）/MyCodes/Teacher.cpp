#include "Teacher.h"
#include "Students.h"
#include"User.h"
#include<iostream>//ʵ�ֳ����������
#include<string.h>//�����ַ�������
#include <conio.h>//�������̨
#include <windows.h>//���ڿ��Ʋ���̨��ͣʱ��
#include <vector>//ʹ��vector��������
#include<algorithm>//ʹ��STL������
#include<fstream>// �ļ����� 
#include <numeric>
#include <iomanip> // ���ڸ�ʽ�����
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
//�����ⲿ�ļ�����
extern void title();
extern void menu();
//�����ⲿ�ļ�����
extern vector<Student> stu_v;
extern vector<Teacher>tea_v;
//��������
bool findID(vector<Teacher>  , string );
void analyzeHomeworkData(const std::string& fileName);

// ��ʽ����ӡ����
void printT(const std::string& m) {  //m:menuItem
	const int width = 60; // ���
	string border(width, '-'); // �� '-' ������ɵı߿�
	int padding = (width - m.size()) / 2 - 1; // �������ߵ����ռ�
	string kongge(padding, ' '); //kongge:�ո񳤶�

	cout << "|" << kongge << m << kongge;
	// �������Ϊ�������ұ����ռ����߶�һ���ո�
	if (m.size() % 2 != 0) {
		cout << " ";
	}
	cout << "|" << std::endl;
}

//��½����
int tlogin()
{
	static int err;//��̬����err���ڼ�¼�û�������������ÿ���������3�Σ�
	system("cls");  //����
	title();//��ӡҳü
	string NetID;
	string pword;
	//����NetID
	cout << "\t��¼ģʽ : ��ʦ" << endl;
	cout << endl << "\t���������NetID :  ";
	cin >> NetID;
	getchar();//��������������һ���س�

	//��������:��������������Ż�����ÿ����һ���ַ��������ڿ���̨�д�ӡһ��*
	std::cout << "\n\t������������� :  ";
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

	//��ʼ����ΪNetID,����Ƿ����
	if (NetID != pword)
	{
		err++;
		if (3 - err > 0) {//�趨ֻ������������ᣬ����Ҫ�˳����µ�¼
			cout << endl << "\n" << "\tNetID��������Ч��\n" << "\t������" << 3 - err << "���������" << "����5����������롣" << endl;
			Sleep(5000);//5�����������
			tlogin();
			return err;
		}
		else {
			cout << "���Ļ������ù⡣�����˳��С�����" << endl;
			Sleep(1000);//1s���˳�
			return err;
		}
	}

	//�жϸ�NetID�Ƿ���������ݿ���,NetIDֻ�ܹ���Ա��������ʦû��Ȩ�޴���
	int flag = 0;
	if (!findID(tea_v, NetID))
	{
		cout << "\n��NetID�����ڣ����������룡3����Զ���ת��";
		Sleep(2000);//3�����������
		tlogin();
		return err;
	}
	else {
		flag = 1;
	}

	//�����¼�ɹ�������Խ���ѡ��˵�
	if (flag)
	{
		cout << "\n\n\t��¼�ɹ���ҳ������С�����������" << endl;
		//�ҵ����ݿ��еĶ���Ԫ��
		auto iter = tea_v.begin();
		while (iter != tea_v.end())
		{
			if (iter->NetID == NetID)
			{
				break;
			}
			else
			{
				iter++;//����������
			}
		}

	sig1:
		Sleep(2000);//2��������ת
		system("cls");  //����
		title();//��ӡҳü
		cout << "\t��¼ģʽ : ��ʦ" << endl;
		cout << "\t\t�˵�" << endl;
		cout << "\t\t1 : ������ҵ\n\t\t2 : �鿴ѧ��ѧϰ���� \n\t\t3 : �鿴ѧ����ҵ�ɼ�\n\t\t4 : ����ѧ����ҵ�ɼ� \n\t\t5 : �鿴ѧ����ҵ���� \n\t\t6 : �޸ĸ�����Ϣ \n\t\t7 : �˳�" << endl;
		cout << "\t���������ѡ��  : ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			iter->add_w();
			goto sig1;  //ת�᱾�����Ŀ�ʼ�����½��в˵�ѡ��
			break;
		case 2:
			iter->pinggu();
			goto sig1;
			break;
		case 3:
			iter->viewScores();
			goto sig1;
			break;
		case 4:
			iter->setScores();
			goto sig1;
			break;
		case 5:
			iter->view_fb();
			goto sig1;
			break;
		case 6:
			iter->setinfo();
			goto sig1;
			break;
		case 7:
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

//�������ݿ����Ƿ���ڸý�ʦ
bool findID(vector<Teacher>  teachers, string NetID) {
	for (const auto& teacher : teachers) {
		if (teacher.NetID == NetID) {
			return true;
		}
	}
	return false;
}

//������ҵ
int Teacher::add_w()
{
	system("cls");
	ofstream putf("notification.txt", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\t�޷��򿪹����ļ�notification!" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		return -1;
	}
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ��ʦ\n" << endl;
	string date;
	cout << "\t��������ҵ����ʱ�䣺";
	cin >> date;
	cout << "\n\t\t   �������� : " << date << endl;

	string note;
	cout << "\t��������ҵ���ݡ�Ҫ�󡢽������ڡ��ύ��ʽ��: \n\t\t";
	cin.ignore(); // ���֮ǰ�����뻺��
	getline(cin, note);
	putf << "_________________________________________________________________   " << date << "\n" << note << "\n\n\n";
	putf.close();//�ر��ļ�
	cout << "\n\t��ҵ���淢�����..." << endl;
	cin.get();
	system("cls");
	return 0;
}

//�鿴ѧ����������Ҫ�����⣺ʹ���ļ���ȡ����������ѧ��д�롢���̺���ʦ��ȡ
int Teacher::view_fb() {
	system("cls");
	//��ȡ�ļ�
	ifstream readfile("feedback.txt", std::ios::in | std::ios::binary);
	if (!readfile.is_open()) {
		cout << "\tû��ѧ��������Ϣ��  3����Զ����ء�";
		Sleep(2000);
		return -1;
	}

	title();//��ӡҳü
	cout << "\n\tѧ����ҵ����: \n\n";

	string line;//���ж�ȡ
	while (getline(readfile, line)) {
		cout << "\t\t" << line << "\n ";
	}

	cout << "\n\t����ʦ����ѧ�����������ڿ��ص㡣   �밴������˳���";
	_getch();
	readfile.close();  //�ر��ļ�
	return 0;
}

//����ṹ�������洢��ҵ��Ŀ�����ʱ�����ͣ����
struct HomeworkData {
	std::string subject;
	int completionTime; // ���ʱ��
	int pauseCount;     // ��ͣ����
};
//����ṹ�������洢ÿ����ҵ���Ѷȵȼ����͸�ѧ����רע�ȵȼ�
struct Evaluation {
	std::string subject;
	std::string focusLevel;     // רע�ȵȼ�
	std::string difficultyLevel; // �Ѷȵȼ�
};

//��ʦ���Բ�ѯѧ�������ҵ��ѧϰרע������
void Teacher::pinggu()
{
	//�������Լ�������ѧϰרע�������㷨
	// ��Ҫ����ѧ������ҵ���ʱ������;��ͣ������ѧ��д��ҵʱ��״̬��������
	//��ҵ���ʱ������;��ͣ��������Ϣ��ѧ��ѧϰ�˱���¼��������data.txt�ļ���
	std::string fileName = "homework_data.txt";
	analyzeHomeworkData(fileName);
}

void analyzeHomeworkData(const std::string& fileName) {
	std::ifstream file(fileName);
	std::vector<HomeworkData> data;
	std::string line;

	system("cls");  //����
	title();//��ӡҳü

	if (!file.is_open()) {
		std::cerr << "\n\t�޷����ļ� " << fileName << std::endl;
		return;
	}
	//���ж�ȡ
	while (getline(file, line)) {
		std::istringstream iss(line);
		HomeworkData hw;  //ÿһ�д���һ��HomeworkData����
		if (iss >> hw.subject >> hw.completionTime >> hw.pauseCount) {
			data.push_back(hw);
		}
	}

	file.close();
	std::cout << "\n\t\t\t      ѧ������̵ĸ�����ҵ����" << std::endl;
	cout << "\t-----------------------------------------------------------------------" << endl;
	if (data.empty()) {
		std::cerr << "\n\t����Ϊ�գ�" << std::endl;
		return;
	}

	// ����ƽ��ֵ,������ʱƽ��ֵ��ֹͣ����ƽ��ֵ
	double avgTime = accumulate(data.begin(), data.end(), 0.0,
		[](double sum, const HomeworkData& hw) { return sum + hw.completionTime; }) / data.size();
	double avgPauseCount = accumulate(data.begin(), data.end(), 0.0,
		[](double sum, const HomeworkData& hw) { return sum + hw.pauseCount; }) / data.size();

	// ������������
	for (const auto& hw : data) {
		Evaluation eval;
		eval.subject = hw.subject;

		// ����רע�ȣ�����ͣ������0.75��1.25Ϊ��ֵ���ָߡ��С���
		eval.focusLevel = hw.pauseCount < avgPauseCount * 0.75 ? "��" :
			hw.pauseCount <= avgPauseCount * 1.25 ? "��" : "��";

		// �����Ѷȣ������ʱ���0.75��1.25Ϊ��ֵ���ָߡ��С���
		eval.difficultyLevel = hw.completionTime > avgTime * 1.25 ? "��" :
			hw.completionTime >= avgTime * 0.75 ? "��" : "��";

		cout << setw(15) << "\n\t��ҵ��Ŀ: " << setw(20) << eval.subject << setw(20)
			<< " רע�ȵȼ�: " << eval.focusLevel << setw(20)
			<< " �Ѷȵȼ�����: " << eval.difficultyLevel << endl;
	}
	cout << "\n\n\t\t�밴������˳���" << endl;
	_getch();//���û�����һ����������������
}

//�鿴������Ϣ
void Teacher::info() {
	system("cls");  //����
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ��ʦ" << endl;
	cout << "\t\t������Ϣ" << endl;
	cout << "\t\t����:" << name;
	cout << "\n\t\t�Ա�" << sex;
	cout << "\n\t\tNetID:" << NetID;
	cout << "\n\t\t���ڿγ�:" << subject;
	cout << "\n\t\tѧԺ:" << pm;
	cout << "\n\t\tְ��:" << jobtitle;
	cout << "\n\t\t���䣺" << email;
	cout << "\n\t\t�绰��" << phone;
	cout << "\n\n\t\t�밴������˳���" << endl;
	_getch();//���û�����һ����������������
	Sleep(1000);
}

//���ĸ�����Ϣ
void Teacher::setinfo() {
	system("cls");  //����
	title();//��ӡҳü
	cout << "  ��¼ģʽ : ��ʦ" << endl;
	cout << "\t��ǰ������Ϣ" << endl;
	cout << "\t\t����:\t\t" << name;
	cout << "\n\t\t�Ա�\t\t" << sex;
	cout << "\n\t\tNetID:\t\t" << NetID;
	cout << "\n\t\t���ڿγ�:\t\t" << subject;  //��ʾ����Ϣ
	cout << "\n\t\tѧԺ:\t\t" << pm;
	cout << "\n\t\tְ��:\t\t" << jobtitle;
	cout << "\n\t\t����:\t\t" << email;
	cout << "\n\t\t�绰:\t\t" << phone;
	cout << "\n-----------------------------------------------------------------------------------------------------------------------\n" << endl;
	cout << "\t�������µĸ�����Ϣ��";
	cout << "\n\t\t����:\t\t";			cin >> name;
	cout << "\n\t\t�Ա�:\t\t";			cin >> sex;
	cout << "\n\t\tNetID:\t\t" << NetID;
	cout << "\n\t\t���ڿγ�:\t\t";   cin >> subject;     //��������
	cout << "\n\t\tѧԺ:\t\t";			cin >> pm;
	cout << "\n\t\tְ��:\t\t";			cin >> jobtitle;
	cout << "\n\t\t����:\t\t";		    cin >> email;
	cout << "\n\t\t�绰:\t\t";		    cin >> phone;
	cout << "\n\t\t�޸���ɣ����ڸ������ݿ⡤����" << endl;
	//STL���������Զ�ά�����ݿ�����Ϣ,
	Sleep(2000);//
}

//��ʦ����ѧ����ҵ�ɼ�����ʦֻ�����������ڿ�Ŀ����ҵ
void Teacher::setScores()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "  ��¼ģʽ : ��ʦ" << endl;
	//��ʾ��ǰ�ɼ�
	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�����߿�
	cout << border << endl;
	printT("ѧ����ǰ�ɼ�");
	// ��ӡ�ײ��߿�
	cout << border << endl;
	cout << "\t����\t\tѧ��\t\t�ɼ�" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (auto stu = stu_v.begin(); stu != stu_v.end(); stu++) //ʹ��STL�������������ѧ���ÿƳɼ�
	{
		cout << "\t" << stu->name << "\t      " << stu->NetID << "\t         ";
		if (subject == "C++�������")cout << stu->cpp[0] << endl;
		else if (subject == "���ݽṹ")cout << stu->data_struct[0] << endl;
		else if (subject == "��ɢ��ѧ")cout << stu->dis_math[0] << endl;
		else if (subject == "����ѧϰ")cout << stu->m_learning[0] << endl;
		else if (subject == "�ź���ϵͳ")cout << stu->sig_sys[0] << endl;
		else cout << stu->python[0] << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "\n\t������Ҫ������ѧ��ѧ�� : ";
	string id;   cin >> id;
	//�ҵ����ݿ��еĶ�Ӧ��ѧ��
	auto iter = stu_v.begin();
	while (iter != stu_v.end())
	{
		if (iter->NetID == id)
		{
			break;
		}
		else
		{
			++iter;//����������
		}
	}
	if (iter == stu_v.end())
	{
		cout << "\n\t��ѧ�������ڣ�" << endl;
	}
	else {
		cout << "\n\t�������ѧ��������ҵ�ɼ���";
		
		if (subject == "C++�������")		cin>> iter->cpp[0] ;
		else if (subject == "���ݽṹ")		cin >>iter->data_struct[0] ;
		else if (subject == "��ɢ��ѧ")		cin >> iter->dis_math[0] ;
		else if (subject == "����ѧϰ")		cin >> iter->m_learning[0] ;
		else if (subject == "�ź���ϵͳ")		cin >> iter->sig_sys[0];
		else cin>>iter->python[0] ;
	}
	cout<<"\n\n\t��ҵ�ɼ������ɹ���"<<endl;
	Sleep(3000);//3s����ת
}

//��ʦ�鿴ѧ���ɼ�����ʦֻ����鿴����ѧ������ڿγ̵ĳɼ����鿴ȫ���ɼ���Ҫͨ������Ա
void Teacher::viewScores()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "  ��¼ģʽ : ��ʦ" << endl;
	//�ɼ������Ա�����ʽ����
	string sub = subject;
	sub += "�ɼ�ͳ�Ʊ�";//�ַ���ƴ�ӡ�XXX�ɼ�ͳ�Ʊ�
	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�����߿�
	cout << border << endl;
	printT(sub);
	// ��ӡ�ײ��߿�
	cout << border << endl;

	cout << "\t����\t\tѧ��\t\t�ɼ�" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (auto stu = stu_v.begin(); stu != stu_v.end(); stu++) //ʹ��STL�������������ѧ���ÿƳɼ�
	{
		cout << "\t" << stu->name << "\t      " << stu->NetID << "\t         " ;
		if (subject == "C++�������")cout << stu->cpp[0]<<endl;
		else if (subject == "���ݽṹ")cout << stu->data_struct[0]<<endl;
		else if (subject == "��ɢ��ѧ")cout << stu->dis_math[0]<<endl;
		else if (subject == "����ѧϰ")cout << stu->m_learning[0]<<endl;
		else cout << stu->python[0]<<endl;
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "\n\t�밴������˳���";
	_getch();
}