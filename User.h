using namespace std;
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iomanip>
#include"Goods.h"
#include"Order.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#pragma once

#define FILEGOODS "commodity.txt"
#define FILEORDER "order.txt"


class User {
public:
	User();
	User(string userID, string username, string password, string phoneNumber, string address, double balance, int userState);
	User(vector<string> vcstr);
	//User(const User& cpyuser);
	//用户ID
	string userID;
	//用户名
	string username;
	//密码phoneNumber
	string password;
	//联系方式
	string phoneNumber;
	//地址
	string address;
	//钱包余额
	double balance;
	//用户状态：1为正常，0为封禁
	int userState;



	//-------------功能函数-----------------
	// 用户菜单显示
	void showUSERMenu();

	//买家模式
	void Module_BUYER(int& numbgoods, int& numborder, vector <User*>& userVec, vector<Goods*>& gdvec, vector<Order*>& orvec);

	//卖家模式
	void Module_SELLER(int& numbgoods, vector<Goods*>& gdvec, vector<Order*>& orvec); // i为商品数量, gdvec传值传参

	//个人信息管理,传入vector以方便用户信息修改时进行用户名的遍历
	void infoManageUSER(vector<User*> vec);

	//注销登录
	void exitUSER();


	//信息管理菜单显示
	void showINFOMenu();
	//查看信息
	void GetUserinfo();
	//修改信息
	void ModifyUserinfo(vector<User*> vec);
	//充值
	void Topup_Userbalance();
	//返回用户主界面
	void exitINFO();

};


class Seller : public User {
public:

	using User::User;

	//卖家菜单展示
	void showSELLERMenu();
	//发布商品
	void publishGOODS(int& numbgoods, vector<Goods*>& gdvec); // i是从卖家模式函数传进来的商品数量, gdvec传值传参
	//查看发布商品
	void viewSGOODS(string ID, vector<Goods*>& gdvec);
	//修改商品信息
	void modifyGOODS(vector<Goods*>& gdvec);
	//下架商品
	void removeGOODS(vector<Goods*>& gdvec);
	//查看历史订单
	void viewSORDER(string ID, vector<Order*>& orvec);
	//返回用户主界面
	void exitSELLER();

};

class Buyer : public User {
public:
	using User::User;

	//买家菜单展示
	void showBUYERMenu();
	//查看商品列表（只能看到在售）
	void viewBGOODS(vector<Goods*>& gdvec);
	//购买商品
	void buyGOODS(int& numbgoods, int& numborder,vector <User*>& userVec, vector<Goods*>& gdvec, vector<Order*>& orvec);
	//搜索商品
	void searchGOODS(vector<Goods*>& gdvec);
	//查看历史订单
	void viewBORDER(vector<Order*>& orvec);
	//查看商品详细信息
	void detailGOODS(vector<Goods*>& gdvec);
	//返回用户主界面
	void exitBUYER();

};

//-----------------------协助性函数

//返回商品ID的string
string GOODSIDback(int i);

//返回订单ID
string ORDERIDback(int i);

//保存商品列表
void saveGOOD(vector<Goods*> gdvec);
//保存订单列表
void saveORDER(vector<Order*> orvec);

//判断输入是否为数字
bool isNumber(const string& str);
