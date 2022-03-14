#include"User.h"


User::User() { userState = 1; balance = 0.0; };
User::User(string userID, string username, string password, string phoneNumber, string address, double balance, int userState) {
	this->userID = userID;
	this->username = username;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->address = address;
	this->balance = balance;
	this->userState = userState;
};
User::User(vector<string> vcstr) {
	//�û�ID,�û���,����,��ϵ��ʽ,��ַ,Ǯ�����,�û�״̬
	//U001, �ϴ�, 123456, 12345678, ���ִ��163��, 1024.0, ����
	//											double	int
	int i = 0;
	for (i; i < 7; ++i) {
		switch (i)
		{
		case 0:
			userID = vcstr.at(i);
			break;
		case 1:
			username = vcstr.at(i);
			break;
		case 2:
			password = vcstr.at(i);
			break;
		case 3:
			phoneNumber = vcstr.at(i);
			break;
		case 4:
			address = vcstr.at(i);
			break;
		case 5:
		{
			balance = 0.0;
			//balance
			string blcstr = vcstr.at(i);
			balance = stod(blcstr);
			//balance = vcstr.at(i);
		}
			break;
		case 6:
		{
			userState = 1;
			//state
			string usstr = vcstr.at(i);	//	������� ����/���
			if (usstr == "����") {
				userState = 1;
			}
			if (usstr == "���") {
				userState = 0;
			}
			//userState = vcstr.at(i);
		}
			break;
		default:
			break;
		}

	}
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


//����PL��switch������Ѿ��б��溯��
void User::infoManageUSER(vector<User*> vec) {
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
			this->ModifyUserinfo(vec);
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

void User::ModifyUserinfo(vector<User*> vec) {
	
	string choice;
	bool judge = true;

	//����ѭ��
	while (judge) {
		//�˵�չʾ
		cout << "=====================================" << endl;
		cout << "=========������Ҫ�޸ĵ���Ϣ===========" << endl;
		cout << "====== 1.�û���  2.��ϵ��ʽ  3.��ַ  4.ȡ���޸�======" << endl;
		cout << "==========================================" << endl;

		//����ѡ��
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choice);

		if (size(choice) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choice[0])
		{
		case '1':	//�޸��û���,ע���û���������ͬ
		{
			cout << "�������޸ĺ���û�����";
			string Uname;
			cin.sync();
			getline(cin, Uname);

			//�����û����ı���
			for (vector<User*>::iterator it =vec.begin(); it != vec.end(); it++) {
				if (Uname == (*it)->username) {
					//ʧ�ܣ��Ѵ����û���
					cout << "ע��ʧ�ܣ����Ѵ����û�������" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			
			
			//�ɹ����޸�
			this->username = Uname;
			cout << "�޸ĳɹ�����" << endl;
			judge = false;
			system("pause");
			system("cls");
		}
			break;
		case '2':	//�޸���ϵ��ʽ
		{
			cout << "�������޸ĺ����ϵ��ʽ��";
			string number;
			cin.sync();
			getline(cin, number);

			this->phoneNumber = number;
			cout << "�޸ĳɹ�����" << endl;
			judge = false;

			system("pause");
			system("cls");
		}
			break;
		case '3':	//�޸ĵ�ַ
		{
			cout << "�������޸ĺ�ĵ�ַ��";
			string addr;
			cin.sync();
			getline(cin, addr);

			this->address = addr;


			cout << "�޸ĳɹ�����" << endl;
			judge = false;

			system("pause");
			system("cls");

		}
			break;
		case '4':
		{
			judge = false;

			system("pause");
			system("cls");
		}
			break;
		default:
			cout << "������������������!!" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}



};

void User::Topup_Userbalance() {

	double money;
	cout << "������Ҫ��ֵ�Ľ�";
	cin.sync();
	(cin >> money).get();	//cin>>�Ľ��������س������߿ո񶼿��ԣ����ǵ�cin��ȡ������cin�Ľ����������ٻ������д��ڣ������´���Ҫ��ȡʱ���ж�ȡ
							//�����.get(),��cin.get()�������������в����ġ�\n��

	//cin.ignore(numeric_limits<std::streamsize>::max());				//��ջ�����(������뻺��������������) //��ƨ
	this->balance += money;

	cout << "��ֵ�ɹ�����" << endl;


	//�����������û���ļ������ļ�ʱ
	//��д���׷�ӷ�ʽ���ļ�
	ofstream ofs("balance.txt", ios::out | ios::app);
	ifstream ifs("balance.txt", ios::in);

	//�õ���ǰ��ֵ��ϵͳʱ��
	time_t blcTime;
	time(&blcTime);

	//���ļ������д���
	if (!ofs.is_open()) {
		cout << "the balance txt open failed." << endl;
		//ofs << setw(10) << setiosflags(ios::left) << "��ֵ�û�ID" 
		//	<< setw(10) << setiosflags(ios::left) <<"��ֵ���"
		//	<< setw(30) << setiosflags(ios::left) <<"��ֵʱ��" << endl;

		//ofs << setw(10) << setiosflags(ios::left) << this->userID 
		//	<< setw(10) << setiosflags(ios::left) << money 
		//	<< setw(30) << setiosflags(ios::left) << ctime(&blcTime) << endl;

		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	if (!ifs.is_open()) {
		cout << "blcfile ifs open failed." << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}


	//�ж��ļ�Ϊ��(eof)
	char ch;
	if (!ifs.get(ch)) {
		ofs << setw(20) << setiosflags(ios::left) << "��ֵ�û�ID"
			<< setw(20) << setiosflags(ios::left) << "��ֵ���"
			<< setw(30) << setiosflags(ios::left) << "��ֵʱ��" << endl;
	}
	//��ǰ�Ѿ����ļ�����
	ofs << setw(20) << setiosflags(ios::left) << this->userID
		<< setw(20) << setiosflags(ios::left) << money
		<< setw(30) << setiosflags(ios::left) << ctime(&blcTime);

	//�ر��ļ�
	ofs.close();
	ifs.close();

	system("pause");
	system("cls");
};

void User::exitINFO() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
};

