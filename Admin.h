#pragma once
#include<iostream>
using namespace std;
#include"User.h"
#include"Goods.h"
#include"Order.h"

class Admin {
public:
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

	//****************以下为管理员的数据成员*******************//

	//用户数组指针
	User** userArray;

	//商品数组指针
	Goods** goodsArray;

	//订单数组指针
	Order** orderArray;
};