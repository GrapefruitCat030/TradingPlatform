#pragma once
#include<iostream>
using namespace std;
#include"Admin.h"

#define ADNAME "admin"
#define ADKEY "123456"

class Platform {
public:
	Platform();
	~Platform();

	//��ʾ��ʼ�˵���
	void show_Menu();

	//�˳�����ƽ̨��
	void exitPlatform();

	//����Ա��¼��
	void AdminLogin(Admin& m_Admin);

	//�û�ע��
	void User_register(Admin& m_Admin);

	//�û���¼
	void UserLogin(Admin& m_Admin);
};

//-------���⺯��---------

//����Աģʽ�������������Ա��¼���ģʽ
void ModAdmin(Admin& m_Admin);
