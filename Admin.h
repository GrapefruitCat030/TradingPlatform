#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>


using namespace std;
#include"User.h"
#include"Goods.h"
#include"Order.h"

#define FILEUSER "user.txt"
#define FILEGOOD "commodity.txt"

class Admin {
public:
	//�û�����
	int numbUser;

	//�û��б�����
	vector <User*> userVec;

	//��Ʒ�б�����
	vector <Goods*> goodsVec;

	//�����б�����
	vector <Order*> orderVec;

	

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


	/**************************/

	//�û��������������ʼ��
	void USERINIT();
	//�û������ļ���ȡ
	void userInitVec();

	//��Ʒ�ļ����������ʼ��
	void GOODSINIT();

	//�����ļ������ʼ��
	void ORDERINIT();

	//�û��ļ�����
	void saveUSERFILE();

	//��Ʒ�ļ�����
	void saveGOODFILE();
	
	//****************����Ϊ����Ա�����ݳ�Ա*******************//


};

//�����ļ����ݻ�ȡ�û�����
int getnumb_USER();
