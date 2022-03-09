#include<string>
#include<vector>
#include<iostream>

using namespace std;
#pragma once


class User {
public:
	User();
	User(string userID, string username, string password, string phoneNumber, string address, double balance, int userState);
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
	void Module_SELLER();

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
	//���Ҳ˵�չʾ
	void showSELLERMenu();
	//������Ʒ
	void publishGOODS();
	//�鿴������Ʒ
	void viewSGOODS();
	//�޸���Ʒ��Ϣ
	void modifyGOODS();
	//�¼���Ʒ
	void removeGOODS();
	//�鿴��ʷ����
	void viewSORDER();
	//�����û�������
	void exitSELLER();

};

class Buyer : public User {
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

