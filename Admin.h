#pragma once
#include<iostream>
using namespace std;


class Admin {
public:
	Admin();
	~Admin();

	//����Ա�˵���ʾ
	void show_Menu();
	//�鿴������Ʒ
	void Goods_show();
	//������Ʒ
	void searchGoods();
	//�¼���Ʒ
	void removeGoods();
	//�鿴���ж���
	void Order_show();
	//�鿴�����û�
	void User_show();
	//����û�
	void banUser();
	//�˳���ע����
	void exitAD();
};