#include "Assit.h"
#include "../../../360MoveData/Users/DELL/Desktop/1/Students.h"

//�����ⲿ�ļ�����
extern void title();
extern void menu();
extern void printT(const std::string& m);

//�����ⲿ�ļ�����
extern vector<Assit> assit_v;
extern vector<Student> stu_v;

//���¾�̬������¼�˸�У���������͵Ŀ��ҵĳ�ʼʣ�����
//Ϊ��ֹ�˱����������ļ��޸ģ�������λ��̬������ÿ�쿪ʼ����һ��
static int sroom[5] = { 30,20,40,60,50 };
static int mroom[5] = { 30,20,40,60,50 };
static int lroom[5] = { 10,8,15,25,20 };
static int gym[5] = { 60,80,100,100,100 };
static int proom[5] = { 15,10,15,25,25 };
static int meetingroom[5] = { 33,25,35,45,40 };


//�������ݿ����Ƿ���ڸ�����
bool findID(vector<Assit>  students, string NetID) {
	for (const auto& student : students) {
		if (student.NetID == NetID) {
			return true;
		}
	}
	return false;
}

//��½����
int aslogin()
{
	static int err;
	system("cls");  //����
	title();//��ӡҳü
	string NetID;
	string pword;
	//����NetID
	cout << "\t��¼ģʽ : ����" << endl;
	cout << endl << "\t���������NetID :  ";
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

	//��ʼ����ΪNetID,����Ƿ����
	if (NetID != pword)
	{
		err++;
		if (3 - err > 0) {//�趨ֻ������������ᣬ����Ҫ�˳����µ�¼
			cout << endl << "\n" << "\tNetID��������Ч��\n" << "\t������" << 3 - err << "���������" << "����5����������롣" << endl;
			Sleep(3000);//5�����������
			aslogin();
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
	if (!findID(assit_v, NetID))
	{
		cout << "\n\n\t��NetID�����ڣ����������룡3����Զ���ת��";
		Sleep(2000);//3�����������
		aslogin();
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
		auto iter = assit_v.begin();
		while (iter != assit_v.end())
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
		cout << "\t��¼ģʽ : ����" << endl;
		cout << "\t\t�˵�" << endl;
		cout << "\t\t1 : ¼����ҵ�ɼ�\n\t\t2 : ԤԼϰ��ο���\n\t\t3 : ����ϰ��ι���\n\t\t4 : �鿴ѧ����ҵ����\n\t\t5 : �޸ĸ�����Ϣ \n\t\t6 : �˳�" << endl;
		cout << "\t���������ѡ��  : ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//iter->info();
			iter->setScores();
			goto sig1;  //ת�ر������Ŀ�ʼ�����½��в˵�ѡ��
			break;
		case 2:
			iter->bookingroom();
			goto sig1;
			break;
		case 3:
			iter->xitike();
			goto sig1;
			break;
		case 4:
			iter->view_fb();
			goto sig1;
			break;
		case 5:
			iter->setinfo();
			goto sig1;
			break;
		case 6:
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


//��������ѧ����ҵ�ɼ�������ֻ���������Ŀ����ҵ
void Assit::setScores()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "  ��¼ģʽ : ����" << endl;
	//��ʾ��ǰ�ɼ�
	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�����߿�
	cout << border << endl;
	printT("ѧ����ǰ��ҵ�ɼ�");
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
		cout << "\n\t�������ѧ����ҵ�ɼ���";

		if (subject == "C++�������")		cin >> iter->cpp[0];
		else if (subject == "���ݽṹ")		cin >> iter->data_struct[0];
		else if (subject == "��ɢ��ѧ")		cin >> iter->dis_math[0];
		else if (subject == "����ѧϰ")		cin >> iter->m_learning[0];
		else if (subject == "�ź���ϵͳ")		cin >> iter->sig_sys[0];
		else cin >> iter->python[0];
	}
	cout << "\n\t��ҵ�ɼ������ɹ���" << endl;
	Sleep(3000);
}

//�鿴ѧ����������Ҫ�����⣺ʹ���ļ���ȡ����������ѧ��д�롢���̺���ʦ��ȡ
int Assit::view_fb() {
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

	cout << "\n\t�����̸���ѧ����������ϰ�⽲�⡣   �밴������˳���";
	_getch();
	readfile.close();  //�ر��ļ�
	return 0;
}

//���̸��ĸ�����Ϣ
void Assit::setinfo() {
	system("cls");  //����
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ����" << endl;
	cout << "\t\t��ǰ������Ϣ" << endl;
	cout << "\t\t����: " << name;
	cout << "\n\t\t�Ա�: " << sex;
	cout << "\n\t\t��Ŀ:  " << subject;
	cout << "\n\t\tNetID: " << NetID;         //��ʾ������
	cout << "\n\t\t�꼶: " << grade;
	cout << "\n\t\tѧԺ: " << pm;
	cout << "\n\t\t����: " << email;
	cout << "\n\t\t�绰: " << phone;
	cout << "\n-----------------------------------------------------------------------------------------------------------------------\n" << endl;
	cout << "�������µĸ�����Ϣ: ";
	cout << "\n\t\t����: ";  cin >> name;
	cout << "\n\t\t�Ա�: ";  cin >> sex;
	cout << "\n\t\t��Ŀ: ";  cin >> subject;
	cout << "\n\t\tNetID: ";  cin >> NetID;
	cout << "\n\t\t�꼶: ";  cin >> grade;     //��������
	cout << "\n\t\tѧԺ: ";  cin >> pm;
	cout << "\n\t\t����: ";  cin >> email;
	cout << "\n\t\t�绰: ";  cin >> phone;
	cout << "\n\t\t�޸���ɣ����ڸ������ݿ⡤����" << endl;
	//STL���������Զ�ά�����ݿ�����Ϣ,
	Sleep(3000);//
}

//����ϰ���ʱ�䡢��ַ�����ݣ�����ѧ����ʱ�μ�
int Assit::xitike()
{
	system("cls");
	ofstream putf("notification.txt", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\t�޷��򿪹����ļ�notification!" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		return -1;
	}
	title();//��ӡҳü
	cout << "\t��¼ģʽ : ����\n" << endl;
	string date;
	cout << "\t�����빫�淢��ʱ�䣺";
	cin >> date;
	cout << "\n\t\t   �������� : " << date << "\n"<<endl;

	string note;
	cout << "\t������ϰ������ݡ�ʱ�䡢�ص��: \n\t\t";
	cin.ignore(); // ���֮ǰ�����뻺��
	getline(cin, note);
	putf << "_________________________________________________________________   " << date << "\n" << note << "\n\n\n";
	putf.close();//�ر��ļ�
	cout << "\n\tϰ��ι��淢�����..." << endl;
	cin.get();
	system("cls");
	return 0;
}

//����ԤԼϰ��ν���
void Assit::bookingroom()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;
	cout << "����������������������������������������������������������������������������������������������������";
	cout << "\n\t��ѡ�������ڵ�У����" << endl;
	cout << "\t\t��1��������У��" << endl;
	cout << "\t\t��2�����ݱ�У��" << endl;
	cout << "\t\t��3�����ݶ�У��" << endl;
	cout << "\t\t��4������У��" << endl;
	cout << "\t\t��5���麣У��" << endl;
	cout << "\t\t��6���˳�" << endl;
	cout << "\n\t���������ѡ��";
	int choice;
	cin >> choice;
	// �����û�������벻ͬ��ԤԼ����
	switch (choice) {
	case 1:
		gzn();//������У������ԤԼϵͳ
		break;
	case 2:
		gzb();//���ݱ�У������ԤԼϵͳ
		break;
	case 3:
		gzd();//���ݶ�У������ԤԼϵͳ
		break;
	case 4:
		shenzhen();//����У������ԤԼϵͳ
		break;
	case 5:
		zhuhai();//�麣У������ԤԼϵͳ
		break;
	case 6:
		cout << "\t�˳�ϵͳ�С�����������" << endl;
		Sleep(2000);//���ӵ���һ��~
		break;
	default:
		cout << "\t��Чѡ��!" << endl;
		Sleep(2000);
		break;
	}
}

// ��ʽ����ӡ����
void printAS(const std::string& menuItem) {
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

//����У������ԤԼϵͳ
void Assit::shenzhen()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;

	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout << endl << border << endl;
	// ��ӡ�˵���
	printAS("����У������ԤԼϵͳ");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;

	cout << "\t��ӭ��������У������ԤԼϵͳ��" << endl;
	cout << "\t\t��1��С�Ϳ���    ʣ�ࣺ" << sroom[3] << "�䡣" << endl;
	cout << "\t\t��2�����Ϳ���    ʣ�ࣺ" << mroom[3] << "�䡣" << endl;
	cout << "\t\t��3�����Ϳ���    ʣ�ࣺ" << sroom[3] << "�䡣" << endl;
	cout << "\t\t��4��������      ʣ�ࣺ" << meetingroom[3] << "�䡣" << endl;
	cout << "\t\t��5�����ֽ���      ʣ�ࣺ" << proom[3] << "����" << endl;
	cout << "\t\t��6����������      ʣ�ࣺ" << gym[3] << "�䡣" << endl;
	cout << "\t��ѡ����ҪԤԼ�Ŀ������ͣ�";
	int choice1;
	cin >> choice1;//�û�����ԤԼ��������
	cout << "\tԤԼʱ�䣺" << endl;
	cout << "\t\t��1��1~2��    ��2��3~4��" << endl;
	cout << "\t\t��3��5~6��    ��4��7~8��" << endl;
	cout << "\t\t��5��9~10��   ��6��11~12��" << endl;
	cout << "\n\t��ѡ����ҪԤԼ��ʱ�䣺";
	int choice2;
	cin >> choice2;//�û��ṩԤԼʱ��

	int flag = 0;//flag���ڱ�־ԤԼ�Ƿ�ɹ�

	string t;//��������
	string time;//Ԥ��ʱ��
	switch (choice1) {
	case 1:
		if (sroom[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\tС�Ϳ���һ��ԤԼ�ɹ���" << endl;
			sroom[3]--;  flag = 1;
			t = "С�Ϳ���";
		}
		break;
	case 2:
		if (mroom[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			mroom[3]--;   flag = 1;  //������ʣ���������1
			t = "���Ϳ���";
		}
		break;
	case 3:
		if (lroom[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			lroom[3]--;   flag = 1;
			t = "���Ϳ���";
		}
		break;
	case 4:
		if (meetingroom[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t������һ��ԤԼ�ɹ���" << endl;
			meetingroom[3]--;   flag = 1;
			t = "������";
		}
		break;
	case 5:
		if (proom[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���ֽ���һ��ԤԼ�ɹ���" << endl;
			proom[3]--;   flag = 1;
			t = "���ֽ���";
		}
		break;
	case 6:
		if (gym[3] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t��������һ��ԤԼ�ɹ���" << endl;
			gym[3]--;   flag = 1;
			t = "��������";
		}
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}
	//ȷ��time
	switch (choice2) {
	case 1:
		time = "��1~2��";
		break;
	case 2:
		time = "��3~4��";
		break;
	case 3:
		time = "��5~6��";
		break;
	case 4:
		time = "��7~8��";
		break;
	case 5:
		time = "��9~10��";
		break;
	case 6:
		time = "��11~12��";
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}

	//����ԤԼ��Ҫ��ԤԼ�˵���Ϣ���м�¼���������Ա�鿴�͹���
	//����ʹ���ļ���������ɴ˹���
	ofstream putf("bookingroom1.dat", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		Sleep(2000);
		return;
	}
	putf << "______________________________________________________________  " << "\n����У��  " << name << "  " << t << "  " << time << "\n\n";
	putf.close();//�ر��ļ�

	cout << "\n\t�밴������˳�������" << endl;
	_getch();
}


//�麣У������ԤԼϵͳ
void Assit::zhuhai()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;

	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout << endl << border << endl;
	// ��ӡ�˵���
	printAS("�麣У������ԤԼϵͳ");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;

	cout << "\t��ӭ�����麣У������ԤԼϵͳ��" << endl;
	cout << "\t\t��1��С�Ϳ���    ʣ�ࣺ" << sroom[4] << "�䡣" << endl;
	cout << "\t\t��2�����Ϳ���    ʣ�ࣺ" << mroom[4] << "�䡣" << endl;
	cout << "\t\t��3�����Ϳ���    ʣ�ࣺ" << sroom[4] << "�䡣" << endl;
	cout << "\t\t��4��������      ʣ�ࣺ" << meetingroom[4] << "�䡣" << endl;
	cout << "\t\t��5�����ֽ���      ʣ�ࣺ" << proom[4] << "�䡣" << endl;
	cout << "\t\t��6����������      ʣ�ࣺ" << gym[4] << "�䡣" << endl;
	cout << "\t��ѡ����ҪԤԼ�Ŀ������ͣ�";
	int choice1;
	cin >> choice1;//�û�����ԤԼ��������
	cout << "\tԤԼʱ�䣺" << endl;
	cout << "\t\t��1��1~2��    ��2��3~4��" << endl;
	cout << "\t\t��3��5~6��    ��4��7~8��" << endl;
	cout << "\t\t��5��9~10��   ��6��11~12��" << endl;
	cout << "\n\t��ѡ����ҪԤԼ��ʱ�䣺";
	int choice2;
	cin >> choice2;//�û��ṩԤԼʱ��

	int flag = 0;//flag���ڱ�־ԤԼ�Ƿ�ɹ�

	string t;//��������
	string time;//Ԥ��ʱ��
	switch (choice1) {
	case 1:
		if (sroom[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\tС�Ϳ���һ��ԤԼ�ɹ���" << endl;
			sroom[4]--;  flag = 1;
			t = "С�Ϳ���";
		}
		break;
	case 2:
		if (mroom[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			mroom[4]--;   flag = 1;  //������ʣ���������1
			t = "���Ϳ���";
		}
		break;
	case 3:
		if (lroom[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			lroom[4]--;   flag = 1;
			t = "���Ϳ���";
		}
		break;
	case 4:
		if (meetingroom[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t������һ��ԤԼ�ɹ���" << endl;
			meetingroom[4]--;   flag = 1;
			t = "������";
		}
		break;
	case 5:
		if (proom[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���ֿ���һ��ԤԼ�ɹ���" << endl;
			proom[4]--;   flag = 1;
			t = "���ֿ���";
		}
		break;
	case 6:
		if (gym[4] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t��������һλԤԼ�ɹ���" << endl;
			gym[4]--;   flag = 1;
			t = "��������";
		}
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}
	//ȷ��time
	switch (choice2) {
	case 1:
		time = "��1~2��";
		break;
	case 2:
		time = "��3~4��";
		break;
	case 3:
		time = "��5~6��";
		break;
	case 4:
		time = "��7~8��";
		break;
	case 5:
		time = "��9~10��";
		break;
	case 6:
		time = "��11~12��";
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}

	//����ԤԼ��Ҫ��ԤԼ�˵���Ϣ���м�¼���������Ա�鿴�͹���
	//����ʹ���ļ���������ɴ˹���
	ofstream putf("bookingroom1.dat", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		Sleep(2000);
		return;
	}
	putf << "______________________________________________________________  " << "\n�麣У��  " << name << "  " << t << "  " << time << "\n\n";
	putf.close();//�ر��ļ�

	cout << "\n\t�밴������˳�������" << endl;
	_getch();
}

//������У������ԤԼϵͳ
void Assit::gzn()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;

	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout << endl << border << endl;
	// ��ӡ�˵���
	printAS("������У������ԤԼϵͳ");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;

	cout << "\t��ӭ����������У������ԤԼϵͳ��" << endl;
	cout << "\t\t��1��С�Ϳ���    ʣ�ࣺ" << sroom[0] << "�䡣" << endl;
	cout << "\t\t��2�����Ϳ���    ʣ�ࣺ" << mroom[0] << "�䡣" << endl;
	cout << "\t\t��3�����Ϳ���    ʣ�ࣺ" << sroom[0] << "�䡣" << endl;
	cout << "\t\t��4��������      ʣ�ࣺ" << meetingroom[0] << "�䡣" << endl;
	cout << "\t\t��5�����ֿ���      ʣ�ࣺ" << proom[0] << "�䡣" << endl;
	cout << "\t\t��6����������      ʣ�ࣺ" << gym[0] << "�䡣" << endl;
	cout << "\t��ѡ����ҪԤԼ�Ŀ������ͣ�";
	int choice1;
	cin >> choice1;//�û�����ԤԼ��������
	cout << "\tԤԼʱ�䣺" << endl;
	cout << "\t\t��1��1~2��    ��2��3~4��" << endl;
	cout << "\t\t��3��5~6��    ��4��7~8��" << endl;
	cout << "\t\t��5��9~10��   ��6��11~12��" << endl;
	cout << "\n\t��ѡ����ҪԤԼ��ʱ�䣺";
	int choice2;
	cin >> choice2;//�û��ṩԤԼʱ��

	int flag = 0;//flag���ڱ�־ԤԼ�Ƿ�ɹ�

	string t;//��������
	string time;//Ԥ��ʱ��
	switch (choice1) {
	case 1:
		if (sroom[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\tС�Ϳ���һ��ԤԼ�ɹ���" << endl;
			sroom[0]--;  flag = 1;
			t = "С�Ϳ���";
		}
		break;
	case 2:
		if (mroom[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			mroom[0]--;   flag = 1;  //������ʣ���������1
			t = "���Ϳ���";
		}
		break;
	case 3:
		if (lroom[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			lroom[0]--;   flag = 1;
			t = "���Ϳ���";
		}
		break;
	case 4:
		if (meetingroom[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t������һ��ԤԼ�ɹ���" << endl;
			meetingroom[0]--;   flag = 1;
			t = "������";
		}
		break;
	case 5:
		if (proom[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���ֿ���һ��ԤԼ�ɹ���" << endl;
			proom[0]--;   flag = 1;
			t = "���ֿ���";
		}
		break;
	case 6:
		if (gym[0] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t��������һλԤԼ�ɹ���" << endl;
			gym[0]--;   flag = 1;
			t = "��������";
		}
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}
	//ȷ��time
	switch (choice2) {
	case 1:
		time = "��1~2��";
		break;
	case 2:
		time = "��3~4��";
		break;
	case 3:
		time = "��5~6��";
		break;
	case 4:
		time = "��7~8��";
		break;
	case 5:
		time = "��9~10��";
		break;
	case 6:
		time = "��11~12��";
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}

	//����ԤԼ��Ҫ��ԤԼ�˵���Ϣ���м�¼���������Ա�鿴�͹���
	//����ʹ���ļ���������ɴ˹���
	ofstream putf("bookingroom.dat", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		Sleep(2000);
		return;
	}
	putf << "______________________________________________________________  " << "\n��У��  " << name << "  " << t << "  " << time << "\n\n";
	putf.close();//�ر��ļ�

	cout << "\n\t�밴������˳�������" << endl;
	_getch();
}


//���ݶ�У������ԤԼϵͳ
void Assit::gzd()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;

	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout << endl << border << endl;
	// ��ӡ�˵���
	printAS("���ݶ�У������ԤԼϵͳ");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;

	cout << "\t��ӭ�������ݶ�У������ԤԼϵͳ��" << endl;
	cout << "\t\t��1��С�Ϳ���    ʣ�ࣺ" << sroom[2] << "�䡣" << endl;
	cout << "\t\t��2�����Ϳ���    ʣ�ࣺ" << mroom[2] << "�䡣" << endl;
	cout << "\t\t��3�����Ϳ���    ʣ�ࣺ" << sroom[2] << "�䡣" << endl;
	cout << "\t\t��4��������      ʣ�ࣺ" << meetingroom[2] << "�䡣" << endl;
	cout << "\t\t��5�����ֽ���      ʣ�ࣺ" << proom[2] << "�䡣" << endl;
	cout << "\t\t��6����������      ʣ�ࣺ" << gym[2] << "�䡣" << endl;
	cout << "\t��ѡ����ҪԤԼ�Ŀ������ͣ�";
	int choice1;
	cin >> choice1;//�û�����ԤԼ��������
	cout << "\tԤԼʱ�䣺" << endl;
	cout << "\t\t��1��1~2��    ��2��3~4��" << endl;
	cout << "\t\t��3��5~6��    ��4��7~8��" << endl;
	cout << "\t\t��5��9~10��   ��6��11~12��" << endl;
	cout << "\n\t��ѡ����ҪԤԼ��ʱ�䣺";
	int choice2;
	cin >> choice2;//�û��ṩԤԼʱ��

	int flag = 0;//flag���ڱ�־ԤԼ�Ƿ�ɹ�

	string t;//��������
	string time;//Ԥ��ʱ��
	switch (choice1) {
	case 1:
		if (sroom[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\tС�Ϳ���һ��ԤԼ�ɹ���" << endl;
			sroom[2]--;  flag = 1;
			t = "С�Ϳ���";
		}
		break;
	case 2:
		if (mroom[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			mroom[2]--;   flag = 1;  //������ʣ���������1
			t = "���Ϳ���";
		}
		break;
	case 3:
		if (lroom[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			lroom[2]--;   flag = 1;
			t = "���Ϳ���";
		}
		break;
	case 4:
		if (meetingroom[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t������һ��ԤԼ�ɹ���" << endl;
			meetingroom[2]--;   flag = 1;
			t = "������";
		}
		break;
	case 5:
		if (proom[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���ֽ���һ��ԤԼ�ɹ���" << endl;
			proom[2]--;   flag = 1;
			t = "���ֽ���";
		}
		break;
	case 6:
		if (gym[2] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t��������һ��ԤԼ�ɹ���" << endl;
			gym[2]--;   flag = 1;
			t = "��������";
		}
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}
	//ȷ��time
	switch (choice2) {
	case 1:
		time = "��1~2��";
		break;
	case 2:
		time = "��3~4��";
		break;
	case 3:
		time = "��5~6��";
		break;
	case 4:
		time = "��7~8��";
		break;
	case 5:
		time = "��9~10��";
		break;
	case 6:
		time = "��11~12��";
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}

	//����ԤԼ��Ҫ��ԤԼ�˵���Ϣ���м�¼���������Ա�鿴�͹���
	//����ʹ���ļ���������ɴ˹���
	ofstream putf("bookingroom1.dat", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		Sleep(2000);
		return;
	}
	putf << "______________________________________________________________  " << "\n��У��  " << name << "  " << t << "  " << time << "\n\n";
	putf.close();//�ر��ļ�

	cout << "\n\t�밴������˳�������" << endl;
	_getch();
}


//���ݱ�У������ԤԼϵͳ
void Assit::gzb()
{
	system("cls");  //����
	title();//��ӡҳü
	cout << "   ��¼ģʽ : ����" << endl;

	const int menuWidth = 60;
	string border(menuWidth, '-'); // ʹ�� '-' �����߿�
	// ��ӡ�˵��Ķ����߿�
	cout << endl << border << endl;
	// ��ӡ�˵���
	printAS("���ݱ�У������ԤԼϵͳ");
	// ��ӡ�˵��ĵײ��߿�
	cout << border << endl;

	cout << "\t��ӭ�������ݱ�У������ԤԼϵͳ��" << endl;
	cout << "\t\t��1��С�Ϳ���    ʣ�ࣺ" << sroom[1] << "�䡣" << endl;
	cout << "\t\t��2�����Ϳ���    ʣ�ࣺ" << mroom[1] << "�䡣" << endl;
	cout << "\t\t��3�����Ϳ���    ʣ�ࣺ" << sroom[1] << "�䡣" << endl;
	cout << "\t\t��4��������      ʣ�ࣺ" << meetingroom[1] << "�䡣" << endl;
	cout << "\t\t��5�����ֽ���      ʣ�ࣺ" << proom[1] << "�䡣" << endl;
	cout << "\t\t��6����������      ʣ�ࣺ" << gym[1] << "�䡣" << endl;
	cout << "\t��ѡ����ҪԤԼ�Ŀ������ͣ�";
	int choice1;
	cin >> choice1;//�û�����ԤԼ��������
	cout << "\tԤԼʱ�䣺" << endl;
	cout << "\t\t��1��1~2��    ��2��3~4��" << endl;
	cout << "\t\t��3��5~6��    ��4��7~8��" << endl;
	cout << "\t\t��5��9~10��   ��6��11~12��" << endl;
	cout << "\n\t��ѡ����ҪԤԼ��ʱ�䣺";
	int choice2;
	cin >> choice2;//�û��ṩԤԼʱ��

	int flag = 0;//flag���ڱ�־ԤԼ�Ƿ�ɹ�

	string t;//��������
	string time;//Ԥ��ʱ��
	switch (choice1) {
	case 1:
		if (sroom[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\tС�Ϳ���һ��ԤԼ�ɹ���" << endl;
			sroom[1]--;  flag = 1;
			t = "С�Ϳ���";
		}
		break;
	case 2:
		if (mroom[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			mroom[1]--;   flag = 1;  //������ʣ���������1
			t = "���Ϳ���";
		}
		break;
	case 3:
		if (lroom[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���Ϳ���һ��ԤԼ�ɹ���" << endl;
			lroom[1]--;   flag = 1;
			t = "���Ϳ���";
		}
		break;
	case 4:
		if (meetingroom[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t������һ��ԤԼ�ɹ���" << endl;
			meetingroom[1]--;   flag = 1;
			t = "������";
		}
		break;
	case 5:
		if (proom[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t���ֽ���һ��ԤԼ�ɹ���" << endl;
			proom[1]--;   flag = 1;
			t = "���ֽ���";
		}
		break;
	case 6:
		if (gym[1] > 0)//�жϿ����Ƿ���ʣ��
		{
			cout << "\t��������һ��ԤԼ�ɹ���" << endl;
			gym[1]--;   flag = 1;
			t = "��������";
		}
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}
	//ȷ��time
	switch (choice2) {
	case 1:
		time = "��1~2��";
		break;
	case 2:
		time = "��3~4��";
		break;
	case 3:
		time = "��5~6��";
		break;
	case 4:
		time = "��7~8��";
		break;
	case 5:
		time = "��9~10��";
		break;
	case 6:
		time = "��11~12��";
		break;
	}
	if (flag == 0)
	{
		cout << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;//flag���ڱ�־ԤԼ�Ƿ�ɹ�
		Sleep(2000);
	}

	//����ԤԼ��Ҫ��ԤԼ�˵���Ϣ���м�¼���������Ա�鿴�͹���
	//����ʹ���ļ���������ɴ˹���
	ofstream putf("bookingroom1.dat", ios::binary | ios::out | ios::app);
	if (!putf) {
		cerr << "\n\tԤԼʧ�ܣ������˳��С�����" << endl;   //����ʹ�������һ�����ۿ�ѧ��cerr�����
		Sleep(2000);
		return;
	}
	putf << "______________________________________________________________  " << "\n��У��  " << name << "  " << t << "  " << time << "\n\n";
	putf.close();//�ر��ļ�

	cout << "\n\t�밴������˳�������" << endl;
	_getch();
}

