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

void User::infoManageUSER() {
	//先进行清屏，然后用户菜单展示
	system("cls");
	//用来储存用户选项
	string choiceii;
	bool judge = true;

	while (judge) {

		this->showINFOMenu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choiceii);

		if (size(choiceii) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choiceii[0])
		{
		case '1':	//查看信息
			this->GetUserinfo();
			break;
		case '2':	//修改信息
			this->ModifyUserinfo();
			break;
		case '3':	//充值
			this->Topup_Userbalance();
			break;
		case '4':	//返回用户主界面
			this->exitINFO();
			judge = false;
			break;
		default:
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}

};

void User::exitUSER() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
};



//信息管理菜单
void User::showINFOMenu() {
	cout << "——————现在处于用户个人信息管理模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.查看信息  2.修改信息  3.充值  4.返回用户主界面" << endl;
	cout << "=================================================" << endl;

};

void User::GetUserinfo() {
	cout << "==============================" << endl;
	cout << "用户名："<<this->username << endl;
	cout << "联系方式："<<this->phoneNumber << endl;
	cout << "地址："<<this->address << endl;
	cout << "钱包余额："<<this->balance << endl;
	cout << "==============================" << endl;
	system("pause");
	system("cls");
	return;
};
void User::ModifyUserinfo() {};
void User::Topup_Userbalance() {};
void User::exitINFO() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
};

