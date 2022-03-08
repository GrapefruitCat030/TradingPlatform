
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
	cout << "�������û�����";
	cin.sync();
	getline(cin, Uname);
	cout << "�������������룺";
	cin.sync();
	getline(cin, Password);
	cout << "�������ֻ��ţ�";
	cin.sync();
	getline(cin, phnNumber);
	cout << "�������ַ��";
	cin.sync();
	getline(cin, address);

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

	//�����¿ռ䣬���ö�̬���飬Ԫ������ΪUser���ָ�� (usernumb��ʱ��û+1��
	User** newUArray = new User * [m_Admin.numbUser+1];

	//��ԭ���ռ��µ����ݿ������¿ռ���
	//�����жϣ������ݾ��������
	if (m_Admin.userArray != NULL) {
		for (int i = 0; i < m_Admin.numbUser; ++i) {
			newUArray[i] = m_Admin.userArray[i];
		}
	}

	//�����µ��û�����
	User* n_User = new User(UIDback(m_Admin.numbUser + 1), Uname, Password, phnNumber, address, 0.0, 1);

	//�Ž�ȥ
	newUArray[m_Admin.numbUser] = n_User;

	//�ͷ�ԭ�пռ�
	delete[] m_Admin.userArray;
	//�����¿ռ��ָ��
	m_Admin.userArray = newUArray;
	//�����û�����
	m_Admin.numbUser++;

	//�ɹ���Ӻ󣬱��浽�ļ���
	this->saveFILE(m_Admin);



	cout << "ע��ɹ�����" << endl;
	system("pause");
	system("cls");
};

void Platform::UserLogin(Admin& m_Admin) {
	
	//test
	int kksk = 0;
	//����ɹ���,switch!!
	if (kksk) {
		User* the_User = new User;

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

	for (int i = 0; i < m_Admin.numbUser; i++) {
		ofs << m_Admin.userArray[i]->userID << " "
			<< m_Admin.userArray[i]->username << " "
			<< m_Admin.userArray[i]->password << " "
			<< m_Admin.userArray[i]->phoneNumber << " "
			<< m_Admin.userArray[i]->address << " "
			<< m_Admin.userArray[i]->balance << " ";
		if (m_Admin.userArray[i]->userState == 1) {
			ofs << "����" << endl;
		}
		else {
			ofs << "���" << endl;
		}
			
	}
	ofs.close();
};


