#pragma once
#include<iostream>
using namespace std;
#include"Admin.h"
#include"User.h"


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

	//����Ա��¼���������ô��Σ������ھֲ������д�������Ա������������
	void AdminLogin(Admin& m_Admin);

	//�û�ע�᣻�������õ��û��ŵ�����Ա�����е��û�����ָ����
	void User_register(Admin& m_Admin);

	//�û���¼
	void UserLogin(Admin& m_Admin);

};

//-------���⺯��---------


