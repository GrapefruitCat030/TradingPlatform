#include<iostream>
using namespace std;
#include<string>
#include"Platform.h"


int main() {

	//ʵ����ƽ̨����
	Platform PL;
	//ʵ���������߶���
	Admin AD;
	//���������û�ѡ��
	string choice;
	while (true) {

		PL.show_Menu();
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choice);
		if (size(choice) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (choice[0])
		{
		case '1':	//����Ա��¼
			PL.AdminLogin(AD);
			break;
		case '2':	//�û�ע��
			PL.User_register(AD);
			break;
		case '3':	//�û���¼
			PL.UserLogin(AD);
			break;
		case '4':	//�˳�ƽ̨
			PL.exitPlatform();
			break;
		default:
			cout << "������������������!!" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}
}

