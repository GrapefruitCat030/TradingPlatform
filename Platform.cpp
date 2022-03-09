
#include"Platform.h"



Platform::Platform() {};

Platform::~Platform() {};

void Platform::show_Menu() {
	cout << "===============================================================" << endl;
	cout << "  1.����Ա��¼	 2.�û�ע��	3.�û���¼	4.�˳�ϵͳ" << endl;
	cout << "===============================================================" << endl;
}

void Platform::exitPlatform() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	exit(0);
}

void Platform::AdminLogin(Admin& m_Admin) {

	string A_Name, A_key;
	cout << "���������Ա������";
	cin.sync();
	getline(cin, A_Name);
	cout << "���������룺";
	cin.sync();
	getline(cin, A_key);

	
	//��¼ʧ���������������˵�
	if (A_Name!=ADNAME || A_key != ADKEY) {
		cout << "---------��¼ʧ�ܣ��������˵�-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ɹ���������Աģ��
	else {
		cout << "��¼�ɹ�����" << endl;
		system("pause");
		m_Admin.Module_Admin();
		
	}
};

void Platform::User_register(Admin& m_Admin) {
	string Uname;
	string Password;
	string phnNumber;
	string address;

	cout << "�������û���(���10λ)��";
	cin.sync();
	getline(cin, Uname);
	if (size(Uname) > 10) {
		cout << "�û����������ȣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�û��������ظ�
	//���������û�
	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		if (Uname == (*it)->username) {
			//ʧ�ܣ��Ѵ����û���
			cout << "ע��ʧ�ܣ����Ѵ����û�������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}



	cout << "��������������(���20λ)��";
	cin.sync();
	getline(cin, Password);
	if (size(Password) > 20) {
		cout << "���볬�����ȣ���" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�������ֻ���(���20������)��";
	cin.sync();
	getline(cin, phnNumber);
	if (size(phnNumber) > 20) {
		cout << "�ֻ��ų������ȣ���" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�������ַ(���40����)��";
	cin.sync();
	getline(cin, address);
	if (size(address) > 40) {
		cout << "��ַ�������ȣ���" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ȷ��ע�᣿(Y/����) ";
	string judge;
	cin.sync();
	getline(cin, judge);
	if (judge != "Y") {
		cout << "����ע�ᣡ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	////�����¿ռ䣬���ö�̬���飬Ԫ������ΪUser���ָ�� (usernumb��ʱ��û+1��
	//User** newUArray = new User * [m_Admin.numbUser+1];

	////��ԭ���ռ��µ����ݿ������¿ռ���
	////�����жϣ������ݾ��������
	//if (m_Admin.userArray != NULL) {
	//	for (int i = 0; i < m_Admin.numbUser; ++i) {
	//		newUArray[i] = m_Admin.userArray[i];
	//	}
	//}

	////�����µ��û�����
	//User* n_User = new User(UIDback(m_Admin.numbUser + 1), Uname, Password, phnNumber, address, 0.0, 1);

	////�Ž�ȥ
	//newUArray[m_Admin.numbUser] = n_User;

	////�ͷ�ԭ�пռ�
	//delete[] m_Admin.userArray;
	////�����¿ռ��ָ��
	//m_Admin.userArray = newUArray;
	////�����û�����
	//m_Admin.numbUser++;

	//�����µ��û�����
	User* n_User = new User(UIDback(m_Admin.numbUser + 1), Uname, Password, phnNumber, address, 0.0, 1);

	//ȷ��ע�ᣬֱ����userVec����push���û���ָ��
	m_Admin.userVec.push_back(n_User);

	//�����û�����
	m_Admin.numbUser++;



	//�ɹ���Ӻ󣬱��浽�ļ���
	this->saveFILE(m_Admin);



	cout << "ע��ɹ�����" << endl;
	system("pause");
	system("cls");
};

void Platform::UserLogin(Admin& m_Admin) {
	//�������û�ָ�룬��ָ���û�����
	User* n_user;

	string U_Name, U_key;
	cout << "�������û�����";
	cin.sync();
	getline(cin, U_Name);
	cout << "���������룺";
	cin.sync();
	getline(cin, U_key);

	int flag = 0;
	string judgeUN, judgeUK;
	//���������û�
	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		judgeUN = (*it)->username;
		judgeUK = (*it)->password;
		if (U_Name == judgeUN && U_key == judgeUK) {
			//�������û�
			n_user = (*it);
			flag = 1;
			cout << "�ɹ���¼��" << endl;
			system("pause");
			break;
		}
	}

	//����ɹ���,switch!!
	if (flag) {
		//�Ƚ���������Ȼ���û��˵�չʾ
		system("cls");
		//���������û�ѡ��
		string choiceuu;
		bool judge = true;

		while (judge) {

			n_user->showUSERMenu();
			cout << "����ѡ�";
			cin.sync();
			getline(cin, choiceuu);

			if (size(choiceuu) > 1) {
				cout << "������������������!!" << endl;
				system("pause");
				system("cls");
				continue;
			}

			switch (choiceuu[0])
			{
			case '1':	//�������
				n_user->Module_BUYER();
				break;
			case '2':	//��������
				n_user->Module_SELLER();
				break;
			case '3':	//������Ϣ����
				n_user->infoManageUSER();
				//��������
				this->saveFILE(m_Admin);
				break;
			case '4':	//�˳���¼
				n_user->exitUSER();
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
	else {
		cout << "fail to login" << endl;
		system("pause");
		system("cls");
	}
};


/*************Э���Ժ���****************************************/
string UIDback(int i) {

	string kksk;
	if (i < 10) {
		kksk = "U00" + to_string(i);
	}
	else if (i < 100) {
		kksk = "U0" + to_string(i);
	}
	else if (i < 1000) {
		kksk = "U" + to_string(i);
	}

	//char* suki = new char[4];
	//strcpy(suki, kksk.c_str());
	
	return kksk;
}

void Platform::saveFILE(Admin& m_Admin) {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (PL::saveFILE)";
		return;
	}

	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		ofs << (*it)->userID << " "
			<< (*it)->username << " "
			<< (*it)->password << " "
			<< (*it)->phoneNumber << " "
			<< (*it)->address << " "
			<< (*it)->balance << " ";
		if ((*it)->userState == 1) {
			ofs << "����" << endl;
		}
		else {
			ofs << "���" << endl;
		}
			
	}
	ofs.close();
};


