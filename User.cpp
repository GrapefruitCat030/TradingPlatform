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



//-------------���ܺ���-----------------
void User::showUSERMenu() {
	cout << "���������������ڴ����û�ģʽ������������" << endl;
	cout << "==================================================" << endl;
	cout << "1.�������  2.��������  3.������Ϣ����  4.�˳���¼" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER() {};

void User::Module_SELLER() {};

void User::infoManageUSER() {};

void User::exitUSER() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
};



