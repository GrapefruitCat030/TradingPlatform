#include<iostream>
using namespace std;
#include<string.h>
#include"Platform.h"


int main() {
	//ʵ����ƽ̨����
	Platform PL;
	//ʵ���������߶���
	Admin AD;
	//���������û�ѡ��
	int choice = 0;
	while (true) {

		PL.show_Menu();
		cout << "����ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:	//����Ա��¼
			PL.AdminLogin(AD);
			break;
		case 2:	//�û�ע��
			PL.User_register(AD);
			break;
		case 3:	//�û���¼
			PL.UserLogin(AD);
			break;
		case 4:	//�˳�ƽ̨
			PL.exitPlatform();
			break;
		default:
			system("cls"); //����
			break;
		}
	}
}





