#include<iostream>
using namespace std;
#include<string.h>
#include"Platform.h"



Platform::Platform() {};

Platform::~Platform() {};

void Platform::show_Menu() {
	cout << "===============================================================" << endl;
	cout << "  1.����Ա��¼	 2.�û�ע��	3.�û���¼	4.�˳�ϵͳ" << endl;
	cout << "===============================================================" << endl;
}

void Platform::exitPlatform() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	exit(0);
}

void Platform::AdminLogin(Admin& m_Admin) {
	

	string A_Name, A_key;
	cout << "���������Ա������";
	cin >> A_Name;
	cout << "���������룺";
	cin >> A_key;

	
	//��¼ʧ���������������˵�
	if (A_Name!=ADNAME || A_key != ADKEY) {
		cout << "---------��¼ʧ�ܣ��������˵�-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ɹ���������Աģ��
	else {
		cout << "��¼�ɹ�����" << endl;
		system("pause");
		m_Admin.Module_Admin();
		
	}
};

void Platform::User_register(Admin& m_Admin) {};

void Platform::UserLogin() {};



