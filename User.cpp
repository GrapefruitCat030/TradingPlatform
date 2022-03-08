#include"User.h"

User::User() {};
User::User(string userID,string username,string password,string phoneNumber,string address,double balance,int userState) {
	this->userID = userID;
	this->username = username;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->address = address;
	this->balance = balance;
	this->userState = userState;
};
//User::User(const User& cpyuser) {};



//-------------���ܺ���-----------------
void User::showUSERMenu() {
	cout << "���������������ڴ����û�ģʽ������������" << endl;
	cout << "==================================================" << endl;
	cout << "1.�������  2.��������  3.������Ϣ����  4.�˳���¼" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER() {};

void User::Module_SELLER() {};

void User::infoManageUSER() {
	//�Ƚ���������Ȼ���û��˵�չʾ
	system("cls");
	//���������û�ѡ��
	string choiceii;
	bool judge = true;

	while (judge) {

		this->showINFOMenu();
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choiceii);

		if (size(choiceii) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choiceii[0])
		{
		case '1':	//�鿴��Ϣ
			this->GetUserinfo();
			break;
		case '2':	//�޸���Ϣ
			this->ModifyUserinfo();
			break;
		case '3':	//��ֵ
			this->Topup_Userbalance();
			break;
		case '4':	//�����û�������
			this->exitINFO();
			judge = false;
			break;
		default:
			cout << "������������������!!" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}

};

void User::exitUSER() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
};



//��Ϣ����˵�
void User::showINFOMenu() {
	cout << "���������������ڴ����û�������Ϣ����ģʽ������������" << endl;
	cout << "==================================================" << endl;
	cout << "1.�鿴��Ϣ  2.�޸���Ϣ  3.��ֵ  4.�����û�������" << endl;
	cout << "=================================================" << endl;

};

void User::GetUserinfo() {
	cout << "==============================" << endl;
	cout << "�û�����"<<this->username << endl;
	cout << "��ϵ��ʽ��"<<this->phoneNumber << endl;
	cout << "��ַ��"<<this->address << endl;
	cout << "Ǯ����"<<this->balance << endl;
	cout << "==============================" << endl;
	system("pause");
	system("cls");
	return;
};
void User::ModifyUserinfo() {};
void User::Topup_Userbalance() {};
void User::exitINFO() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
};

