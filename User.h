#pragma once

class User {
public:
	//�û�ID
	char userID;
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


	//���ܺ���
};


class Seller : public User {

};

class Buyer : public User {

};

