#pragma once

class User {
public:
	//用户ID
	char userID[5];
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



	//-------------功能函数-----------------
	// 用户菜单显示
	void showUSERMenu();
	//买家模式
	void Module_BUYER();
	//卖家模式
	void Module_SELLER();
	//个人信息管理
	void infoManageUSER();
	//注销登录
	void exitUSER();


	//信息管理菜单显示
	void showINFOMenu();
	//查看信息
	void GetUserinfo();
	//修改信息
	void ModifyUserinfo();
	//充值
	void Topup_Userbalance();
	//返回用户主界面
	void exitINFO();

};


class Seller : public User {
	//卖家菜单展示
	void showSELLERMenu();
	//发布商品
	void publishGOODS();
	//查看发布商品
	void viewSGOODS();
	//修改商品信息
	void modifyGOODS();
	//下架商品
	void removeGOODS();
	//查看历史订单
	void viewSORDER();
	//返回用户主界面
	void exitSELLER();

};

class Buyer : public User {
	//买家菜单展示
	void showBUYERMenu();
	//查看商品列表（只能看到在售）
	void viewBGOODS();
	//购买商品
	void buyGOODS();
	//搜索商品
	void searchGOODS();
	//查看历史订单
	void viewBORDER();
	//查看商品详细信息
	void detailGOODS();
	//返回用户主界面
	void exitBUYER();

};

