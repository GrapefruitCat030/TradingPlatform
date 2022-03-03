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

	//显示初始菜单；
	void show_Menu();

	//退出交易平台；
	void exitPlatform();

	//管理员登录；利用引用传参，避免在局部函数中创建管理员对象容易消亡
	void AdminLogin(Admin& m_Admin);

	//用户注册；将创建好的用户放到管理员对象中的用户数组指针中
	void User_register(Admin& m_Admin);

	//用户登录
	void UserLogin(Admin& m_Admin);

};

//-------类外函数---------


