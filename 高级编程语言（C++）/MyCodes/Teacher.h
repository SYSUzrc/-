#pragma once
#include"User.h"

class Teacher : public User {
public:
    //��ʦ�ĸ�����Ϣ
    string NetID = "δ����";
    string pword;//��¼����
    string name = "δ����";
    string sex = "δ����";
    string pm = "���ܹ���ѧԺ"; //������λ
    string subject = "δ����";//���ڵĿγ�
    string jobtitle = "δ����";//ְλ�����ڡ������ڡ�������ڡ���ʦ���о�Ա������ѧ��
    string email = "δ����";
    string phone = "δ����";

    //��ʦ��¼����
    //�˺�����Ҫ��һ��Teacher���󴴽�ǰ����
    //����Ҫ����Teacher�ĳ�Ա���ݺͳ�Ա�����������Ϊ��Ԫ����
    friend int tlogin();  
    //������ҵ
    int add_w();
    //��ʦ�鿴������Ϣ
    void info() override;
    //��ʦ���ĸ�����Ϣ
    void setinfo();
    //��ʦ�鿴ѧ����ҵ�ɼ�
    void viewScores();
    //��ʦ����ѧ����ҵ�ɼ�
    void setScores();
    //���Ҳ鿴ѧ������ҵ������Ϣ
    int view_fb();
    //ѧ�������ҵ��ѧϰרע������
    void pinggu();
};

