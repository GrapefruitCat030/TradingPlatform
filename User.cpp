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



//-------------¹¦ÄÜº¯Êý-----------------
void User::showUSERMenu() {};

void User::Module_BUYER() {};

void User::Module_SELLER() {};

void User::infoManageUSER() {};

void User::exitUSER() {};



