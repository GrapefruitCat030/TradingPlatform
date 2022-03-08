#include"User.h"

User::User() {};
User::User(string userID,string username,string password,string phoneNumber,string address,double balance,int userState) {
	this->userID = userID;
	this->username = username;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->address = address;
	this->balance = balance;
	this->userState = userState;
};
//User::User(const User& cpyuser) {};



//-------------功能函数-----------------
void User::showUSERMenu() {
	cout << "——————现在处于用户模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.我是买家  2.我是卖家  3.个人信息管理  4.退出登录" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER() {};

void User::Module_SELLER() {};

void User::infoManageUSER() {};

void User::exitUSER() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
};



