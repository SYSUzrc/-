#pragma once
//#include<User.h>
//#include "Students.h"
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

class Assit
{
public:
    //������Ϣ���ݳ�Ա
    string NetID = "20354111";
    string pword;
    string name = "������";
    string sex = "��";
    int grade = 2020;//�꼶
    string pm = "���ܹ���ѧԺ"; //ѧԺ
    string email = "shenzhj@mail2.sysu.edu.cn";
    string phone = "13939368767";
    string subject = "C++�������";//�γ�

    //�����޸ĸ�����Ϣ
    void setinfo();

    //����������ҵ��¼����ҵ�ɼ�
    void setScores();

    //�鿴ѧ����������Ҫ�����⣺ʹ���ļ���ȡ����������ѧ��д�롢���̺���ʦ��ȡ
    int view_fb();  //fb:feedback
  
    //ԤԼ���ҽ���ϰ��ν���
    void bookingroom();
    void shenzhen();//����У������ԤԼϵͳ
    void gzn();//������У������ԤԼϵͳ
    void gzb();//���ݱ�У������ԤԼϵͳ
    void gzd();//���ݶ�У������ԤԼϵͳ
    void zhuhai();//�麣У������ԤԼϵͳ

    //������Ԥ����ϰ��ο��Һ���ѧ������ϰ��ι���
    int xitike();
};

