#include<iostream>
using namespace std;
#include<string.h>
#include"Platform.h"





Platform::Platform() {};

Platform::~Platform() {};

void Platform::show_Menu() {
	cout << "===============================================================" << endl;
	cout << "  1.管理员登录	 2.用户注册	3.用户登录	4.退出系统" << endl;
	cout << "===============================================================" << endl;
}

void Platform::exitPlatform() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	exit(0);
}

//利用引用传参，避免在函数中创建管理员对象容易消亡
void Platform::AdminLogin(Admin& m_Admin) {
	


	string A_Name, A_key;
	cout << "请输入管理员姓名：";
	cin >> A_Name;
	cout << "请输入密码：";
	cin >> A_key;

	
	//登录失败则清屏返回主菜单
	if (A_Name!=ADNAME || A_key != ADKEY) {
		cout << "---------登录失败，返回主菜单-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	//成功则进入管理员模块
	else {
		cout << "登录成功！！" << endl;



		//test
		system("pause");
		system("cls");
		cout << "-----您现在处于管理员模式-----" << endl;
		system("pause");
		system("cls");
		return;

	}
};

