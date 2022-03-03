#include"Admin.h"

Admin::Admin() {};

Admin::~Admin() {};

void Admin::show_Menu() {
	cout << "-----您现在处于管理员模式-----" << endl;
	cout << "====================================================================" << endl;
	cout << "  1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "===================================================================" << endl;

}

void Admin::exitAD() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	return;
}

void Admin::Goods_show() {};

void Admin::searchGoods() {};

void Admin::removeGoods() {};

void Admin::Order_show() {};

void Admin::User_show() {};

void Admin::banUser() {};

void Admin::Module_Admin() {
	//先进行清屏，然后管理员菜单展示
	system("cls");

	//用来储存用户选项
	int choice = 0;
	bool judge = true;

	while (judge) {

		this->show_Menu();
		cout << "输入选项：";
		cin >> choice;

		switch (choice)
		{
		case 1:	//查看所有商品
			this->Goods_show();
			break;
		case 2:	//搜索商品
			this->searchGoods();
			break;
		case 3:	//下架商品
			this->removeGoods();
			break;
		case 4:	//查看所有订单
			this->Order_show();
			break;
		case 5:	//查看所有用户
			this->User_show();
			break;
		case 6:	//封禁用户
			this->banUser();
			break;
		case 7:	//注销
			this->exitAD();
			judge = false;
			system("cls");
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	return;

}