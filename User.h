using namespace std;
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<iomanip>
#include"Goods.h"
#include"Order.h"
#pragma once

#define FILEGOODS "commodity.txt"


class User {
public:
	User();
	User(string userID, string username, string password, string phoneNumber, string address, double balance, int userState);
	User(vector<string> vcstr);
	//User(const User& cpyuser);
	//�û�ID
	string userID;
	//�û���
	string username;
	//����phoneNumber
	string password;
	//��ϵ��ʽ
	string phoneNumber;
	//��ַ
	string address;
	//Ǯ�����
	double balance;
	//�û�״̬��1Ϊ������0Ϊ���
	int userState;



	//-------------���ܺ���-----------------
	// �û��˵���ʾ
	void showUSERMenu();

	//���ģʽ
	void Module_BUYER();

	//����ģʽ
	void Module_SELLER(int& numbgoods, vector<Goods*>& gdvec, vector<Order*>& orvec); // iΪ��Ʒ����, gdvec��ֵ����

	//������Ϣ����,����vector�Է����û���Ϣ�޸�ʱ�����û����ı���
	void infoManageUSER(vector<User*> vec);

	//ע����¼
	void exitUSER();


	//��Ϣ����˵���ʾ
	void showINFOMenu();
	//�鿴��Ϣ
	void GetUserinfo();
	//�޸���Ϣ
	void ModifyUserinfo(vector<User*> vec);
	//��ֵ
	void Topup_Userbalance();
	//�����û�������
	void exitINFO();

};


class Seller : public User {
public:

	using User::User;

	//�������ӵ���Ʒ����������������
	int plbgoodnumb;

	//���Ҳ˵�չʾ
	void showSELLERMenu();
	//������Ʒ
	void publishGOODS(int& numbgoods, vector<Goods*>& gdvec); // i�Ǵ�����ģʽ��������������Ʒ����, gdvec��ֵ����
	//�鿴������Ʒ
	void viewSGOODS(string ID, vector<Goods*>& gdvec);
	//�޸���Ʒ��Ϣ
	void modifyGOODS(vector<Goods*>& gdvec);
	//�¼���Ʒ
	void removeGOODS(vector<Goods*>& gdvec);
	//�鿴��ʷ����
	void viewSORDER(string ID, vector<Order*>& orvec);
	//�����û�������
	void exitSELLER();

};

class Buyer : public User {
public:
	using User::User;

	//��Ҳ˵�չʾ
	void showBUYERMenu();
	//�鿴��Ʒ�б�ֻ�ܿ������ۣ�
	void viewBGOODS();
	//������Ʒ
	void buyGOODS();
	//������Ʒ
	void searchGOODS();
	//�鿴��ʷ����
	void viewBORDER();
	//�鿴��Ʒ��ϸ��Ϣ
	void detailGOODS();
	//�����û�������
	void exitBUYER();

};

//-----------------------Э���Ժ���

//������ƷID��string
string GOODSIDback(int i);
//������Ʒ�б�
void saveGOOD(vector<Goods*> gdvec);