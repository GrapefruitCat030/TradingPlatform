#include"Admin.h"

Admin::Admin() {

	//�û���ʼ��
	this->USERINIT();
	//��Ʒ��ʼ��
	this->GOODSINIT();

	//numbUser = 0;

	//userArray = NULL;
	//orderArray = NULL;
	//goodsArray = NULL;
};

Admin::~Admin() {};

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
			system("pause");
			system("cls");
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

void Admin::Goods_show() {
	cout << "��ƷID" << "\t" << "����" << "\t" << "�۸�" << "\t"
		<< "����" << "\t" << "����" << "\t" << "����ID" << "\t" 
		<< "�ϼ�ʱ��" << "\t"<<"��Ʒ״̬"<<endl;

	for (vector<Goods*>::iterator it = this->goodsVec.begin(); it != this->goodsVec.end(); it++) {
		cout << (*it)->commodityID << "\t";
		cout << (*it)->commodityName << "\t";
		cout << (*it)->price << "\t";
		cout << (*it)->number << "\t";
		cout << (*it)->description << "\t";
		cout << (*it)->sellerID << "\t";
		cout << (*it)->addedDate << "\t";
		cout << (*it)->state << endl;
	}

};

void Admin::searchGoods() {
	string gname;
	cout << "��������Ҫ���ҵ���Ʒ����";
	cin.sync();
	getline(cin, gname);

	cout << "****************************************" << endl;
	cout << "��ƷID" << "\t" << "����" << "\t" << "�۸�" << "\t"
		<< "����" << "\t" << "����" << "\t" << "����ID" << "\t"
		<< "�ϼ�ʱ��" << "\t" << "��Ʒ״̬" << endl;

	//Ѱ����Ʒ��vec�е�λ��
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		//Ѱ���ַ�
		int fdstr = (*it)->commodityName.find(gname, 0);
		//���ҵ������¼��ǰvec�±�λ�ã��������
		if (fdstr < (*it)->commodityName.length()) {
			cout << (*it)->commodityID << "\t";
			cout << (*it)->commodityName << "\t";
			cout << (*it)->price << "\t";
			cout << (*it)->number << "\t";
			cout << (*it)->description << "\t";
			cout << (*it)->sellerID << "\t";
			cout << (*it)->addedDate << "\t";
			cout << (*it)->state << endl;
			flag = true;
		}
		i++;
	}
	//û����Ʒ����
	if (!flag) {
		cout << "------û�и���Ʒ����-------" << endl;
		cout << "**************************************" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "**************************************" << endl;
	system("pause");
	system("cls");
};

void Admin::removeGoods() {
	//�Ȳ鿴һ����Ʒ�б�
	cout << "****************************************" << endl;
	this->Goods_show();
	cout << "****************************************" << endl;

	string gstr;
	cout << "������Ҫ�¼ܵ���Ʒ��";
	getline(cin, gstr);
	//����
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		if ((*it)->commodityID == gstr) break;
	}
	//����Ʒ
	if (it == this->goodsVec.end()) {
		cout << "û�и���Ʒ����" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ȷ���¼ܸ���Ʒ��?" << endl;
	cout << "****************************************" << endl;
	cout << "��ƷID" << "\t" << "����" << "\t" << "�۸�" << "\t"
		<< "����" << "\t" << "����" << "\t" << "����ID" << "\t"
		<< "�ϼ�ʱ��" << "\t" << "��Ʒ״̬" << endl;
	cout << (*it)->commodityID << "\t";
	cout << (*it)->commodityName << "\t";
	cout << (*it)->price << "\t";
	cout << (*it)->number << "\t";
	cout << (*it)->description << "\t";
	cout << (*it)->sellerID << "\t";
	cout << (*it)->addedDate << "\t";
	cout << (*it)->state << endl;
	cout << "****************************************" << endl;
	cout << "��ѡ��(y/n)  ";

	string flag;
	cin.sync();
	getline(cin, flag);
	//�����޸�
	if (flag == "y") {
		(*it)->state = "���¼�";
		cout << "�¼ܳɹ�����" << endl;
	}
	else
		cout << "ȡ���¼�" << endl;


	this->saveGOODFILE();

	system("pause");
	system("cls");
};

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
	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
		cout << (*it)->userID << "\t";
		cout << (*it)->username << "\t";
		cout << (*it)->password << "\t";
		cout << (*it)->phoneNumber << "\t";
		cout << (*it)->address << "\t";
		cout << (*it)->balance << "\t";
		if ((*it)->userState == 1) {
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
		for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
			string theID;
			theID = (*it)->userID;
			if (UID == theID) {
				(*it)->userState = 0;
				cout << "����ɹ�����" << endl;

				this->saveUSERFILE();

				system("pause");
				system("cls");
				return;
			}
		}
		cout << "δ�ҵ����û�����" << endl;
	}


};







void Admin::USERINIT() {
	//�����������ʼ��
	ifstream ifs;
	ifs.open("user.txt", ios::in);

	//1.�û��ļ�������ʱ
	if (!ifs.is_open()) {
		cout << "�ļ�Ϊ�գ���" << endl;
		numbUser = 0;
		//userVec = NULL;
		ifs.close();
		return;
	}

	//2.�û��ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "����Ϊ�գ���" << endl;
		numbUser = 0;
		//userVec = NULL;
		ifs.close();
		return;
	}

	//3.�û��ļ������Ҳ�Ϊ��
	numbUser = getnumb_USER();
	cout << "�û�����Ϊ��" << numbUser << endl;
	//userVec = new User * [numbUser];
	this->userInitVec();
}

void Admin::userInitVec() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::userInitVec)";
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

	//int index = 0;
	while (ifs >> userID && ifs >> username && ifs >> password
		&& ifs >> phoneNumber && ifs >> address && ifs >> balance && ifs >> userState)
	{
		User* n_user = new User(userID,username,password,phoneNumber,address,balance,1);
		//n_user->userID = userID;
		//n_user->username = username;
		//n_user->password = password;
		//n_user->phoneNumber = phoneNumber;
		//n_user->address = address;
		//n_user->balance = balance;
		if (userState == "����") {
			n_user->userState = 1;
		}
		else {
			n_user->userState = 0;
		}

		//this->userArray[index] = n_user;
		userVec.push_back(n_user);

		//index++;
	}

	ifs.close();
}

void Admin::GOODSINIT() {
	ifstream ifs("commodity.txt", ios::in);

	//��ʧ��
	if (!ifs.is_open()) {
		cout << "goods txt open failed!" << endl;
		return;
	}

	//ÿ�ж���
	string str;
	//ȥ��û�õĵ�һ��
	getline(ifs, str);
	//��������
	while (getline(ifs, str)) {

		stringstream kksk(str);

		vector<string> record;

		//��һ�����Զ���Ϊ�ָ������ַ�����¼��record������
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//��ʼ���µ���Ʒ����
		Goods* gd = new Goods(record);
		//װ����������
		this->goodsVec.push_back(gd);
	}


	ifs.close();

};





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

void Admin::saveUSERFILE() {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (AD::saveUSERFILE)";
		return;
	}

	//�û�vecд��
	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
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

void Admin::saveGOODFILE() {
	ofstream ofs(FILEGOOD, ios::out);

	//�жϴ��Ƿ�ɹ�
	if (!ofs.is_open()) {
		cout << "file open failed (AD:saveGOODFILE)" << endl;
		return;
	}

	ofs << "��ƷID,����,�۸�,����,����,����ID,�ϼ�ʱ��,��Ʒ״̬" << endl;

	//��Ʒvecд��
	for (vector<Goods*>::iterator it = this->goodsVec.begin(); it != this->goodsVec.end(); it++) {
		ofs << (*it)->commodityID << ","
			<< (*it)->commodityName << ","
			<< (*it)->price << ","
			<< (*it)->number << ","
			<< (*it)->description << ","
			<< (*it)->sellerID << ","
			<< (*it)->addedDate << ","
			<< (*it)->state << endl;
	}

	ofs.close();
}