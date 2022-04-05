#include<iostream>
using namespace std;
#include<string>
#include"Platform.h"


int main() {
	//实例化平台对象
	Platform PL;
	//实例化管理者对象
	Admin AD;
	//用来储存用户选项
	string choice;
	while (true) {

		PL.show_Menu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choice);
		if (size(choice) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (choice[0])
		{
		case '1':	//管理员登录
			PL.AdminLogin(AD);
			break;
		case '2':	//用户注册
			PL.User_register(AD);
			break;
		case '3':	//用户登录
			PL.UserLogin(AD);
			break;
		case '4':	//退出平台
			PL.exitPlatform();
			break;
		default:
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}
}

