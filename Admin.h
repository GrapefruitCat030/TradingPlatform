﻿#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>


using namespace std;
#include"User.h"
#include"Goods.h"
#include"Order.h"
#include"SQL.h"


#define FILEUSER "user.txt"
#define FILEGOOD "commodity.txt"

class Admin {
public:
	//用户数量
	int numbUser;
	//商品数量
	int numbGoods;
	//订单数量
	int numbOrder;

	//用户列表向量
	vector <User*> userVec;

	//商品列表向量
	vector <Goods*> goodsVec;

	//订单列表向量
	vector <Order*> orderVec;



	Admin();
	~Admin();

	//****************以下为管理员的功能函数成员*******************//

	//管理员菜单显示
	void show_Menu();
	//查看所有商品
	void Goods_show();
	//搜索商品
	void searchGoods();
	//下架商品
	void removeGoods();
	//查看所有订单
	void Order_show();
	//查看所有用户
	void User_show();
	//封禁用户
	void banUser();
	//退出（注销）
	void exitAD();
	//管理员模式，用来接入管理员登录后的模式
	void Module_Admin();


	/**************************/

	//用户整体整体整体初始化
	void USERINIT();

	//商品文件整体整体初始化
	void GOODSINIT();

	//订单文件整体初始化
	void ORDERINIT();

	//用户文件保存
	void saveUSERFILE();

	//商品文件保存
	void saveGOODFILE();

	//****************以下为管理员的数据成员*******************//


};
