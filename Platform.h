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

	//显示初始菜单；
	void show_Menu();

	//退出交易平台；
	void exitPlatform();

	//管理员登录；
	void AdminLogin(Admin& m_Admin);

	//用户注册
	void User_register(Admin& m_Admin);

	//用户登录
	void UserLogin(Admin& m_Admin);
};

//-------类外函数---------

//管理员模式，用来接入管理员登录后的模式
void ModAdmin(Admin& m_Admin);
