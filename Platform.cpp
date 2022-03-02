#include<iostream>
using namespace std;
#include<string.h>
#include"Platform.h"

void ModAdmin(Admin& m_Admin) {
	//先进行清屏，然后管理员菜单展示
	system("cls");

	//用来储存用户选项
	int choice = 0;

	while (true) {

		m_Admin.show_Menu();
		cout << "输入选项：";
		cin >> choice;

		switch (choice)
		{
		case 1:	//查看所有商品
			//PL.AdminLogin(AD);
			break;
		case 2:	//搜索商品
			//PL.User_register(AD);
			break;
		case 3:	//下架商品
			//PL.UserLogin(AD);
			break;
		case 4:	//查看所有订单
			//PL.exitPlatform();
			break;
		case 5:	//查看所有用户
			break;
		case 6:	//封禁用户
			break;
		case 7:	//注销
			m_Admin.exitAD();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	return;

}


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

//利用引用传参，避免在局部函数中创建管理员对象容易消亡
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
		system("pause");
		ModAdmin(m_Admin);

	}
};

void Platform::User_register(Admin& m_Admin) {};

void Platform::UserLogin(Admin& m_Admin) {};

