#pragma once
#include"User.h"

class Student : public User {
public:
    //������Ϣ���ݳ�Ա
    string NetID = "δ����";
    string pword;
    string name= "δ����";
    string sex = "δ����";
    int grade = 2022;//�꼶
    string pm = "���ܹ���ѧԺ"; //ѧԺ
    string email = "δ����";
    string phone = "δ����";

    //��ҵ�ɼ����ݳ�Ա:�����һ��λ��Ϊ�ɼ�(��ʼ��Ϊ0)���ڶ���λ��Ϊѧ��
    int cpp[2] = { 100 ,3};//C++�������
    int data_struct[2] = { 97 ,4};//���ݽṹ
    int dis_math[2] = { 94 ,2};//��ɢ��ѧ
    int m_learning[2] = { 96 ,3};//����ѧϰ
    int python[2] = { 89 ,3};//Python
    int sig_sys[2] = { 97,2 };//�ź�����̬
    int credits = cpp[1] + data_struct[1] + dis_math[1] + m_learning[1] + python[1]+sig_sys[1]; //��ѧ��

    //���캯��
    Student();

    //��̬�����;�̬��������ͳ��ϵͳ��ѧ������
    static int sCount;
    static int getStuCount() { return sCount; }

    // ѧ���鿴������Ϣ
    void info() override;
    //ѧ���޸ĸ�����Ϣ
    void setinfo();

    //��ʼд��ҵ��
    void to_study();

    //�鿴������ҵ�ɼ�
    void showScores();

    //�鿴��ҵ����
    int notification();
    
};

