#include"Admin.h"

Admin::Admin() {
	orderArray = NULL;
	goodsArray = NULL;
	//�û���ʼ��
	this->USERINIT();


	//numbUser = 0;

	//userArray = NULL;
	//orderArray = NULL;
	//goodsArray = NULL;
};

Admin::~Admin() {};

void Admin::show_Menu() {
	cout << "-----�����ڴ��ڹ���Աģʽ-----" << endl;
	cout << "====================================================================" << endl;
	cout << "  1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" << endl;
	cout << "===================================================================" << endl;

}

void Admin::exitAD() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
}

void Admin::Goods_show() {};

void Admin::searchGoods() {};

void Admin::removeGoods() {};

void Admin::Order_show() {};

void Admin::User_show() {
	cout << "�û�ID" << "\t" << "����" << "\t" << "����" <<"\t" 
		<<"�ֻ���" << "\t" <<"��ַ" << "\t" << "�û����" << "\t" << "�û�״̬" << endl;
	if (!this->numbUser) {
		cout << "----------���û�����-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->numbUser; i++) {
		cout << this->userArray[i]->userID << "\t";
		cout << this->userArray[i]->username << "\t";
		cout << this->userArray[i]->password << "\t";
		cout << this->userArray[i]->phoneNumber << "\t";
		cout << this->userArray[i]->address << "\t";
		cout << this->userArray[i]->balance << "\t";
		if (this->userArray[i]->userState == 1) {
			cout << "����";
		}
		else {
			cout << "���";
		}

		cout << endl;
	}
	system("pause");
	system("cls");

};

void Admin::banUser() {
	string UID;
	cout << "������Ҫ������û�ID��";
	cin.sync();
	getline(cin, UID);
	cout << "ȷ�������(Y/����) ";
	string judge;
	cin.sync();
	getline(cin, judge);

	if (judge != "Y") {
		cout << "�����������" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0; i < this->numbUser; i++) {
			string theID;
			theID = this->userArray[i]->userID;
			if (UID == theID) {
				this->userArray[i]->userState = 0;
				cout << "����ɹ�����" << endl;

				this->saveFILE();

				system("pause");
				system("cls");
				return;
			}
		}
		cout << "δ�ҵ����û�����" << endl;
	}


};

void Admin::Module_Admin() {
	//�Ƚ���������Ȼ�����Ա�˵�չʾ
	system("cls");
	//���������û�ѡ��
	string choicecc;
	bool judge = true;

	while (judge) {

		this->show_Menu();
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choicecc);
		//if (cin >> choicecc) {

		//}
		//else {
		//	cin.clear();
		//}
		if (size(choicecc) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		//char kksk = choicecc[0];
		switch (choicecc[0])
		{
		case '1':	//�鿴������Ʒ
			this->Goods_show();
			break;
		case '2':	//������Ʒ
			this->searchGoods();
			break;
		case '3':	//�¼���Ʒ
			this->removeGoods();
			break;
		case '4':	//�鿴���ж���
			this->Order_show();
			break;
		case '5':	//�鿴�����û�
			this->User_show();
			break;
		case '6':	//����û�
			this->banUser();
			break;
		case '7':	//ע��
			this->exitAD();
			judge = false;
			break;
		default:
			cout << "������������������!!" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}
}

void Admin::USERINIT() {
	//�����������ʼ��
	ifstream ifs;
	ifs.open("user.txt", ios::in);

	//1.�û��ļ�������ʱ
	if (!ifs.is_open()) {
		cout << "�ļ�Ϊ�գ���" << endl;
		numbUser = 0;
		userArray = NULL;
		ifs.close();
		return;
	}

	//2.�û��ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "����Ϊ�գ���" << endl;
		numbUser = 0;
		userArray = NULL;
		ifs.close();
		return;
	}

	//3.�û��ļ������Ҳ�Ϊ��
	numbUser = getnumb_USER();
	cout << "�û�����Ϊ��" << numbUser << endl;
	userArray = new User * [numbUser];
	this->userInitArray();
}

void Admin::userInitArray() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::userInitArray)";
		return;
	}

	//�û�ID
	string userID;
	//�û���
	string username;
	//����
	string password;
	//��ϵ��ʽ
	string phoneNumber;
	//��ַ
	string address;
	//Ǯ�����
	double balance;
	//�û�״̬��1Ϊ������0Ϊ���
	string userState;

	int index = 0;
	while (ifs >> userID && ifs >> username && ifs >> password
		&& ifs >> phoneNumber && ifs >> address && ifs >> balance && ifs >> userState)
	{
		User* n_user = new User;
		n_user->userID = userID;
		n_user->username = username;
		n_user->password = password;
		n_user->phoneNumber = phoneNumber;
		n_user->address = address;
		n_user->balance = balance;
		if (userState == "����") {
			n_user->userState = 1;
		}
		else {
			n_user->userState = 0;
		}

		this->userArray[index] = n_user;

		index++;
	}

	ifs.close();
}


/***************���⺯��***********************/
int getnumb_USER() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::getnumbUser)";
		exit(-1);
	}

	//�û�ID
	string userID;
	//�û���
	string username;
	//����
	string password;
	//��ϵ��ʽ
	string phoneNumber;
	//��ַ
	string address;
	//Ǯ�����
	double balance;
	//�û�״̬��1Ϊ������0Ϊ���
	//int userState;
	string userState;

	int num = 0;
	while (ifs >> userID && ifs >> username && ifs >> password
		&& ifs >> phoneNumber && ifs >> address && ifs >> balance && ifs >> userState)
	{
		num++;
	}

	ifs.close();
	return num;
}

void Admin::saveFILE() {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (PL::saveFILE)";
		return;
	}

	for (int i = 0; i < this->numbUser; i++) {
		ofs << this->userArray[i]->userID << " "
			<< this->userArray[i]->username << " "
			<< this->userArray[i]->password << " "
			<< this->userArray[i]->phoneNumber << " "
			<< this->userArray[i]->address << " "
			<< this->userArray[i]->balance << " ";
		if (this->userArray[i]->userState == 1) {
			ofs << "����" << endl;
		}
		else {
			ofs << "���" << endl;
		}

	}
	ofs.close();
};
