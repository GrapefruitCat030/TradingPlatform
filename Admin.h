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

	//****************����Ϊ����Ա�Ĺ��ܺ�����Ա*******************//

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
	//����Աģʽ�������������Ա��¼���ģʽ
	void Module_Admin();

	//****************����Ϊ����Ա�����ݳ�Ա*******************//

	//�û�����ָ��
	User** userArray;

	//��Ʒ����ָ��
	Goods** goodsArray;

	//��������ָ��
	Order** orderArray;
};