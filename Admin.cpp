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