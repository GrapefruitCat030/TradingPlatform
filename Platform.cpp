#include<iostream>
using namespace std;
#include<string.h>
#include"Platform.h"

void ModAdmin(Admin& m_Admin) {
	//�Ƚ���������Ȼ�����Ա�˵�չʾ
	system("cls");

	//���������û�ѡ��
	int choice = 0;

	while (true) {

		m_Admin.show_Menu();
		cout << "����ѡ�";
		cin >> choice;

		switch (choice)
		{
		case 1:	//�鿴������Ʒ
			//PL.AdminLogin(AD);
			break;
		case 2:	//������Ʒ
			//PL.User_register(AD);
			break;
		case 3:	//�¼���Ʒ
			//PL.UserLogin(AD);
			break;
		case 4:	//�鿴���ж���
			//PL.exitPlatform();
			break;
		case 5:	//�鿴�����û�
			break;
		case 6:	//����û�
			break;
		case 7:	//ע��
			m_Admin.exitAD();
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	return;

}


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

//�������ô��Σ������ھֲ������д�������Ա������������
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
		ModAdmin(m_Admin);

	}
};

void Platform::User_register(Admin& m_Admin) {};

void Platform::UserLogin(Admin& m_Admin) {};

