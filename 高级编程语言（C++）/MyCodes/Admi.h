#pragma once
#include"User.h"

class Admi : public User {
public:
    //Admi();
    //����Ա����
    static string pw;
    // ����Ա�鿴������Ϣ
    void info() override {};
    // ����Ա���ѧ��
    void addStu();
    //����Աɾ��ѧ��
    void deteStu();
    //����Ա�鿴ѧ���б�
    void viewStuList();
    //����ѧ����ҵ�ɼ�
    void mangeSocres();
    //����Ա��ӽ�ʦ
    void addTeacher();
    //����Աɾ����ʦ
    void deteTeacher();
    //����Ա�鿴ȫ���ʦ��Ϣ
    void viewTlist();
    //����Ա��������
    int add_Notification();
    //����Ա�鿴ȫУ����ԤԼ���
    void viewBooking();
};

