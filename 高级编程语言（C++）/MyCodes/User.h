#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
protected://����������������ʹ��
    string name;
    string ID;
    string pword; 
public:
    virtual void info() = 0; // ���麯�����������ʵ��
    
};







