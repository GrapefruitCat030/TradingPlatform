#pragma once

class User {
	//用户ID
	char userID;
	//用户名
	char username[11];
	//密码
	char password[21];
	//联系方式
	char phoneNumber[21];
	//地址
	char address[41];
	//钱包余额
	double balance;
	//用户状态：1为正常，0为封禁
	int userState;
};
