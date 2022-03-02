#pragma once
#include<iostream>
using namespace std;


class Admin {
public:
	Admin();
	~Admin();

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
};