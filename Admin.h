#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"User.h"
#include"Goods.h"
#include"Order.h"

#define FILEUSER "user.txt"


class Admin {
public:
	//用户人数
	int numbUser;

	//用户数组指针
	User** userArray;

	//商品数组指针
	Goods** goodsArray;

	//订单数组指针
	Order** orderArray;



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
	//用户数组文件读取
	void userInitArray();

	//文件保存
	void saveFILE();
	
	//****************以下为管理员的数据成员*******************//


};

//根据文件内容获取用户数量
int getnumb_USER();
