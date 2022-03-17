#include"Admin.h"

Admin::Admin() {
	numbUser = 0;
	numbGoods = 0;
	numbOrder = 0;
	//�û���ʼ��
	this->USERINIT();
	//��Ʒ��ʼ��
	this->GOODSINIT();
	//������ʼ��
	this->ORDERINIT();

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
	cout << "========================================================================================" << endl;
	cout << "------------------------------�����ڴ��ڹ���Աģʽ--------------------------------------"<< endl;
	cout << "========================================================================================" << endl;
	cout << "  1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" << endl;
	cout << "========================================================================================" << endl;

}

void Admin::exitAD() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	system("cls");
	return;
}

void Admin::Goods_show() {
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "����" << setw(20) << "����" << setw(20) << "����ID" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "��Ʒ״̬" << setw(20) << endl;

	for (vector<Goods*>::iterator it = this->goodsVec.begin(); it != this->goodsVec.end(); it++) {
		cout << left << setw(20) << (*it)->commodityID << setw(20)
			<< (*it)->commodityName << setw(20)
			<< (*it)->price << setw(20)
			<< (*it)->number << setw(20)
			<< (*it)->description << setw(20)
			<< (*it)->sellerID << setw(20)
			<< (*it)->addedDate << setw(20)
			<< (*it)->state << setw(20) << endl;
	}
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << endl;
};

void Admin::searchGoods() {
	string gname;
	cout << "��������Ҫ���ҵ���Ʒ����";
	cin.sync();
	getline(cin, gname);

	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "����" << setw(20) << "����" << setw(20) << "����ID" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "��Ʒ״̬" << endl;

	//Ѱ����Ʒ��vec�е�λ��
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		//Ѱ���ַ�
		int fdstr = (*it)->commodityName.find(gname, 0);
		//���ҵ������¼��ǰvec�±�λ�ã��������
		if (fdstr < (*it)->commodityName.length()) {
			cout << left << setw(20) << (*it)->commodityID << setw(20)
				<< (*it)->commodityName << setw(20)
				<< (*it)->price << setw(20)
				<< (*it)->number << setw(20)
				<< (*it)->description << setw(20)
				<< (*it)->sellerID << setw(20)
				<< (*it)->addedDate << setw(20)
				<< (*it)->state << endl;
			flag = true;
		}
		i++;
	}
	//û����Ʒ����
	if (!flag) {
		cout << endl;
		cout << "                                   û�и���Ʒ����                                         " << endl;
		cout << endl;
		cout << "**********************************************************************************************************************************************************" << endl;
		cout << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << "**********************************************************************************************************************************************************" << endl;
	cout << endl;
	
	system("pause");
	system("cls");
};

void Admin::removeGoods() {
	//�Ȳ鿴һ����Ʒ�б�
	this->Goods_show();

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
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "����" << setw(20) << "����" << setw(20) << "����ID" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "��Ʒ״̬" << setw(20) << endl;
	cout << left << setw(20) << (*it)->commodityID << setw(20)
		<< (*it)->commodityName << setw(20)
		<< (*it)->price << setw(20)
		<< (*it)->number << setw(20)
		<< (*it)->description << setw(20)
		<< (*it)->sellerID << setw(20)
		<< (*it)->addedDate << setw(20)
		<< (*it)->state << setw(20) << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << endl;
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
		cout << "ȡ���¼�!!" << endl;



	this->saveGOODFILE();

	system("pause");
	system("cls");
};

void Admin::Order_show() {
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "����ID" << setw(20) << "��ƷID" << setw(20) << "���׵���" << setw(20)
		<< "����" << setw(20) << "����ʱ��" << setw(20) << "����ID" << setw(20)
		<< "���ID" << endl;

	for (vector<Order*>::iterator it = this->orderVec.begin(); it != this->orderVec.end(); it++) {
		cout << left << setw(20) << (*it)->orderID << setw(20)
			<< (*it)->commodityID << setw(20)
			<< (*it)->unitPrice << setw(20)
			<< (*it)->number << setw(20)
			<< (*it)->date << setw(20)
			<< (*it)->sellerID << setw(20)
			<< (*it)->buyerID << endl;
	}
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << endl;

	system("pause");
	system("cls");
};

void Admin::User_show() {
	cout << endl;
	cout << "*******************************************************************************************************************************************" << endl;
	cout << left<< setw(20)<<"�û�ID" << setw(20) << "����" << setw(20) << "����" << setw(20)
		<<"�ֻ���" << setw(20) <<"��ַ" << setw(20) << "�û����" << setw(20) << "�û�״̬" << endl;
	if (!this->numbUser) {
		cout << endl;
		cout << "       ���û�����      " << endl;
		cout << endl;
		cout << "*******************************************************************************************************************************************" << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}
	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
		cout << left << setw(20) << (*it)->userID << setw(20)
			<< (*it)->username << setw(20)
			<< (*it)->password << setw(20)
			<< (*it)->phoneNumber << setw(20)
			<< (*it)->address << setw(20)
			<< (*it)->balance << setw(20);
		if ((*it)->userState == 1) {
			cout << "����" << setw(20);
		}
		else {
			cout << "���" << setw(20);
		}

		cout << endl;

	}
	cout << "*******************************************************************************************************************************************" << endl;
	cout << endl;

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

				//˳���¼���Ʒ
				for (vector<Goods*>::iterator gt = this->goodsVec.begin(); gt != this->goodsVec.end(); gt++) {
					if ((*gt)->sellerID == theID) {
						(*gt)->state = "���¼�";
					}
				}

				cout << "����ɹ�����" << endl;

				this->saveUSERFILE();
				this->saveGOODFILE();
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "δ�ҵ����û�����" << endl;
	}


};







void Admin::USERINIT() {
	ifstream ifs(FILEUSER, ios::in);

	//��ʧ��
	if (!ifs.is_open()) {
		//cout << "user txt open failed!" << endl;
		//cout << "���ڴ����ļ�" << endl;
		ofstream ofs(FILEUSER, ios::out);
		ofs.close();
		return;
	}

	//ÿ�ж���
	string str;
	//ȥ��û�õĵ�һ��
	getline(ifs, str);
	//��������
	while (getline(ifs, str)) {
		numbUser++;
		stringstream kksk(str);

		vector<string> record;

		//��һ�����Զ���Ϊ�ָ������ַ�����¼��record������
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//��ʼ���µ���Ʒ����
		User* gd = new User(record);
		//װ����������
		this->userVec.push_back(gd);
	}


	ifs.close();



}

void Admin::GOODSINIT() {
	ifstream ifs(FILEGOOD, ios::in);

	//��ʧ��
	if (!ifs.is_open()) {
		//cout << "goods txt open failed!" << endl;
		//cout << "���ڴ����ļ�" << endl;
		ofstream ofs(FILEGOOD, ios::out);
		return;
	}

	//ÿ�ж���
	string str;
	//ȥ��û�õĵ�һ��
	getline(ifs, str);
	//��������
	while (getline(ifs, str)) {
		numbGoods++;

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

void Admin::ORDERINIT() {
	ifstream ifs("order.txt", ios::in);

	//��ʧ��
	if (!ifs.is_open()) {
		//cout << "order txt open failed!" << endl;
		//cout << "���ڴ����ļ�" << endl;
		ofstream ofs("order.txt", ios::out);
		return;
	}

	//ÿ�ж���
	string str;
	//ȥ��û�õĵ�һ��
	getline(ifs, str);
	//��������
	while (getline(ifs, str)) {
		numbOrder++;

		stringstream kksk(str);

		vector<string> record;

		//��һ�����Զ���Ϊ�ָ������ַ�����¼��record������
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//��ʼ���µ���Ʒ����
		Order* gd = new Order(record);
		//װ����������
		this->orderVec.push_back(gd);
	}


	ifs.close();


}



/***************���⺯��***********************/

void Admin::saveUSERFILE() {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (AD::saveUSERFILE)";
		return;
	}

	ofs << "�û�ID,�û���,����,��ϵ��ʽ,��ַ,Ǯ�����,�û�״̬" << endl;

	//�û�vecд��
	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
		ofs << (*it)->userID << ","
			<< (*it)->username << ","
			<< (*it)->password << ","
			<< (*it)->phoneNumber << ","
			<< (*it)->address << ","
			<< to_string((*it)->balance) << ",";	//doubleתstring
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
