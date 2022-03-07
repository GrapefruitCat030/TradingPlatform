#pragma once

class User {
public:
	//�û�ID
	char userID[5];
	//�û���
	char username[11];
	//����
	char password[21];
	//��ϵ��ʽ
	char phoneNumber[21];
	//��ַ
	char address[41];
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
	//������Ϣ����
	void infoManageUSER();
	//ע����¼
	void exitUSER();


	//��Ϣ����˵���ʾ
	void showINFOMenu();
	//�鿴��Ϣ
	void GetUserinfo();
	//�޸���Ϣ
	void ModifyUserinfo();
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

