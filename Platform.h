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


	//注册用户后用来保存到文件中的函数
	void saveFILE(Admin& m_Admin);
};

//做出用户ID的字符数组；(注意数据放在堆区，记得用后delete！）
string UIDback(int i);


