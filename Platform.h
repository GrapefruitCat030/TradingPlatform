#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"Admin.h"
#include"User.h"
#include<string>



#define ADNAME "admin"
#define ADKEY "123456"

#define FILEUSER "user.txt"

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


	//ע���û����������浽�ļ��еĺ���
	void saveFILE(Admin& m_Admin);
};

//�����û�ID���ַ����飻(ע�����ݷ��ڶ������ǵ��ú�delete����
string UIDback(int i);


