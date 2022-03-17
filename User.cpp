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
	balance = 0.0;
	userState = 1;

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



//----------------------�û�����
void User::showUSERMenu() {
	cout << "���������������ڴ����û�ģʽ������������" << endl;
	cout << "==================================================" << endl;
	cout << "1.�������  2.��������  3.������Ϣ����  4.�˳���¼" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER(int& numbgoods, int& numborder, vector <User*>& userVec, vector<Goods*>& gdvec, vector<Order*>& orvec) {
	Buyer n_buyer;
	n_buyer.userID = this->userID;

	//�Ƚ���������Ȼ���û��˵�չʾ
	system("cls");
	//���������û�ѡ��
	string choicebb;
	bool judge = true;

	while (judge) {

		n_buyer.showBUYERMenu();
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choicebb);

		if (size(choicebb) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choicebb[0])
		{
		case '1':	//�鿴��Ʒ�б�ֻ�ܿ������ۣ�
			n_buyer.viewBGOODS(gdvec);
			break;
		case '2':	//������Ʒ
			n_buyer.buyGOODS(numbgoods,numborder,userVec,gdvec,orvec);
			break;
		case '3':	//������Ʒ
			n_buyer.searchGOODS(gdvec);
			break;
		case '4':	//�鿴��ʷ����
			n_buyer.viewBORDER(orvec);
			break;
		case '5':	//�鿴��Ʒ��ϸ��Ϣ
			n_buyer.detailGOODS(gdvec);
			break;
		case '6':	//�����û�������
			n_buyer.exitBUYER();
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

void User::Module_SELLER(int& numbgoods, vector<Goods*>& gdvec, vector<Order*>& orvec) {
	Seller n_seller;
	n_seller.userID = this->userID;

	//�Ƚ���������Ȼ���û��˵�չʾ
	system("cls");
	//���������û�ѡ��
	string choicess;
	bool judge = true;

	while (judge) {

		n_seller.showSELLERMenu();
		cout << "����ѡ�";
		cin.sync();
		getline(cin, choicess);

		if (size(choicess) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choicess[0])
		{
		case '1':	//������Ʒ
			n_seller.publishGOODS(numbgoods,gdvec);
			break;
		case '2':	//�鿴������Ʒ
			n_seller.viewSGOODS(userID,gdvec);
			break;
		case '3':	//�޸���Ʒ��Ϣ
			n_seller.modifyGOODS(gdvec);
			break;
		case '4':	//�¼���Ʒ
			n_seller.removeGOODS(gdvec);
			break;
		case '5':	//�鿴��ʷ����
			n_seller.viewSORDER(userID, orvec);
			break;
		case '6':	//�����û�������
			n_seller.exitSELLER();
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
														//����PL��switch������Ѿ��б��溯��
void User::infoManageUSER(vector<User*> vec, vector<Order*>& orvec) {
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
			this->GetUserinfo(orvec);
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




//---------------------��Ҳ˵�

//��Ҳ˵�չʾ
void Buyer::showBUYERMenu() {
	cout << "��������������������          ���ڴ����û����ģʽ          ��������������������" << endl;
	cout << "============================================================================================" << endl;
	cout << "1.�鿴��Ʒ�б�  2.������Ʒ  3.������Ʒ 4.�鿴��ʷ����  5.�鿴��Ʒ��ϸ��Ϣ  6.�����û�������" << endl;
	cout << "============================================================================================" << endl;
};

//�鿴��Ʒ�б�ֻ�ܿ������ۣ�
void Buyer::viewBGOODS(vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_goods(BUYER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "����ID" << endl;

	for (vector<Goods*>::iterator it = gdvec.begin(); it != gdvec.end(); it++) {
		if ((*it)->state == "������") {
			cout << left << setw(20) << (*it)->commodityID << setw(20)
			 << (*it)->commodityName << setw(20)
			 << (*it)->price << setw(20)
			 << (*it)->addedDate << setw(20)
			 << (*it)->sellerID << endl;
		}

	}
	cout << "************************************************************************************************************" << endl;
	cout << endl;

	system("pause");
	system("cls");

};

//������Ʒ
void Buyer::buyGOODS(int& numbgoods, int& numborder, vector <User*>& usvec, vector<Goods*>& gdvec, vector<Order*>& orvec) {
	
	//����iterator�ҵ���Ʒ��Ӧ�����
	vector<User*>::iterator bt = usvec.begin();
	for (bt; bt != usvec.end(); bt++) {
		if (this->userID == (*bt)->userID) break;
	}

	
	
	cout << "��������ƷID�� ";
	string gID;
	cin.sync();
	getline(cin, gID);

	//����iterator�ҵ���Ʒ����λ��
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->state == "������") break;
	}
	if (it == gdvec.end()) {
		cout << "�޴���Ʒ����" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�ҵ���
	cout << "������������ ";
	string gnumb;
	cin.sync();
	getline(cin, gnumb);
	//�ж������Ƿ�Ϊ����
	if (!isNumber(gnumb)) {
		cout << "�������󣡣�����ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ж��Ƿ�Ϊ����
	int k = 0;
	for (k; k < gnumb.length(); k++) {
		if (gnumb[k] == '.') break;
	}
	if (gnumb.length() != k) {
		cout << "������������������������ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�ж���Ʒ����������
	if (stoi(gnumb) > stoi((*it)->number)) {	//��治������
		cout << "û���㹻��棡��" << endl;
		system("pause");
		system("cls");
		return;
	}

	//���׶�
	double prcsum = stoi(gnumb) * stod((*it)->price);
	//�жϽ��׶����������ϵ
	if (prcsum > (*bt)->balance) {
		cout << "û���㹻����" << endl;
		system("pause");
		system("cls");
		return;
	}

	/////////////////////��ȡʱ��
	struct tm* tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);
	int year = tm_ptr->tm_year + 1900;
	int month = tm_ptr->tm_mon + 1;
	int day = tm_ptr->tm_mday;
	string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	/////////////////////////////////

	//SSSQQQLLL
	string sqlstr1 = SQLbuy_goodsOrder(ORDERIDback(numborder + 1), (*it)->commodityID, (*it)->price, gnumb, theTime, (*it)->sellerID, this->userID);
	string sqlstr2 = SQLbuy_goodsGoods((*it)->commodityID, gnumb);
	//analySQL(sqlstr1);
	//analySQL(sqlstr2);

	//��Ʒ�������������㹻�����ɶ���
	Order* order = new Order(ORDERIDback(numborder + 1), (*it)->commodityID, (*it)->price, gnumb, theTime, (*it)->sellerID, this->userID);
	orvec.push_back(order);

	//������Ʒ�޸�
	int remainNumb = stoi((*it)->number) - stoi(gnumb);//ʣ����Ʒ����
	(*it)->number = to_string(remainNumb);
	//��һ���޸���Ʒ״̬����Ʒ������
	if (remainNumb == 0) {
		(*it)->state = "���¼�";

		//SSSQQQLLL
		string sqlstr3 = SQLnone_goods((*it)->commodityID);
		//analySQL(sqlstr3);

	}

	//����iterator�ҵ���Ʒ��Ӧ������
	vector<User*>::iterator sut = usvec.begin();
	for (sut; sut != usvec.end(); sut++) {
		if ((*it)->sellerID == (*sut)->userID) break;
	}

	//�������������䶯
	(*sut)->balance += prcsum;
	(*bt)->balance -= prcsum;



	cout << "**************************************" << endl;
	cout << "**��������*************************" << endl;
	cout << "����ʱ�䣺" << theTime << endl;
	cout << "���׵��ۣ�" << (*it)->price << endl;
	cout << "����������" << gnumb << endl;
	cout << "����״̬�����׳ɹ�"<< endl;
	cout << "������" << (*bt)->balance << endl;
	cout << "**************************************" << endl;
	cout << endl;

	saveGOOD(gdvec);
	saveORDER(orvec);

	system("pause");
	system("cls");
};

//������Ʒ��ֻ�ܿ������ۣ�
void Buyer::searchGOODS(vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLsearch_goods(BUYER, this->userID);
	//analySQL(sqlstr1);

	string gname;
	cout << "��������Ҫ���ҵ���Ʒ����";
	cin.sync();
	getline(cin, gname);

	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "����ID" << endl;

	//Ѱ����Ʒ��vec�е�λ��
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		//Ѱ���ַ�
		int fdstr = (*it)->commodityName.find(gname, 0);
		//���ҵ������¼��ǰvec�±�λ�ã��������
		if (fdstr < (*it)->commodityName.length() && (*it)->state == "������") {
			cout << left << setw(20) << (*it)->commodityID << setw(20)
				<< (*it)->commodityName << setw(20)
				<< (*it)->price << setw(20)
				<< (*it)->addedDate << setw(20)
				<< (*it)->sellerID << endl;
			flag = true;
		}
		i++;
	}
	//û����Ʒ����
	if (!flag) {
		cout << "                   û�и���Ʒ����                " << endl;
		cout << "************************************************************************************************************" << endl;
		cout << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "************************************************************************************************************" << endl;
	cout << endl;
	system("pause");
	system("cls");

};

//�鿴��ʷ����
void Buyer::viewBORDER(vector<Order*>& orvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_order(BUYER, this->userID);
	//analySQL(sqlstr1);


	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "����ID" << setw(20) << "��ƷID" << setw(20) << "���׵���" << setw(20)
		<< "����" << setw(20) << "����ʱ��" << setw(20) << "����ID" << setw(20) << endl;

	for (vector<Order*>::iterator it = orvec.begin(); it != orvec.end(); it++) {
		if ((*it)->buyerID == this->userID) {
			cout << left << setw(20) << (*it)->orderID << setw(20)
				<< (*it)->commodityID << setw(20)
				<< (*it)->unitPrice << setw(20)
				<< (*it)->number << setw(20)
				<< (*it)->date << setw(20)
				<< (*it)->sellerID << setw(20) << endl;
		}

	}
	cout << "************************************************************************************************************" << endl;
	cout << endl;

	system("pause");
	system("cls");

};

//�鿴��Ʒ��ϸ��Ϣ
void Buyer::detailGOODS(vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLdetail_goods();
	//analySQL(sqlstr1);

	cout << endl;

	string gID;

	cout << "��������Ҫ�鿴����ƷID��";
	cin.sync();
	getline(cin, gID);

	//����iterator�ҵ���Ʒ����λ��
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->state == "������") break;
	}
	if (it == gdvec.end()) {
		cout << "�޴���Ʒ����" << endl;
		system("pause");
		system("cls");
		return;
	}

	//�ҵ���Ʒ
	cout << endl;
	cout << "************************************************" << endl;
	cout << "��ƷID��" << (*it)->commodityID << endl;
	cout << "��Ʒ���ƣ�" << (*it)->commodityName << endl;
	cout << "��Ʒ�۸�" << (*it)->price << endl;
	cout << "�ϼ�ʱ�䣺" << (*it)->addedDate << endl;
	cout << "��Ʒ������" << (*it)->description << endl;
	cout << "��Ʒ����: " << (*it)->sellerID << endl;
	cout << "************************************************" << endl;

	system("pause");
	system("cls");

};

//�����û�������
void Buyer::exitBUYER() {
	system("pause");
	system("cls");
};




//---------------------���Ҳ˵�

//���Ҳ˵�չʾ
void Seller::showSELLERMenu() {
	cout << "������������������������         ���ڴ����û�����ģʽ        ����������������������" << endl;
	cout << "========================================================================================" << endl;
	cout << "1.������Ʒ  2.�鿴������Ʒ  3.�޸���Ʒ��Ϣ  4.�¼���Ʒ 5.�鿴��ʷ����  6.�����û�������" << endl;
	cout << "========================================================================================" << endl;
};

//������Ʒ
void Seller::publishGOODS(int& numbgoods, vector<Goods*>& gdvec) {


	cout << endl << endl;

	string gname;
	string gprice;
	string gnumb;
	string gdescrib;

	cout << "��������Ʒ���ƣ�";
	cin.sync();
	getline(cin, gname);

	cout << "��������Ʒ��ֵ������ҪһλС���� ";
	cin.sync();
	getline(cin, gprice);
	//�ж��Ƿ�ΪһλС��
	//�ж������Ƿ�Ϊ����
	if (!isNumber(gprice)) {
		cout << "�������󣡣�����ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ж��Ƿ�Ϊ����һλС��,���ҵ�С���㣬�ٽ��г������
	int i = 0;
	for (i; i < gprice.length(); i++) {
		if (gprice[i] == '.') break;
	}
	if (gprice.length() - i - 1 > 1) {
		//����С��λ����
		cout << "���볬��С��λ���ȣ�������ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "��������Ʒ������";
	cin.sync();
	getline(cin, gnumb);
	//�ж������Ƿ�Ϊ����
	if (!isNumber(gnumb)) {
		cout << "�������󣡣�����ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ж��Ƿ�Ϊ����
	int k = 0;
	for (k; k < gnumb.length(); k++) {
		if (gnumb[k] == '.') break;
	}
	if (gnumb.length() != k) {
		cout << "������������������������ʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "��������Ʒ������";
	cin.sync();
	getline(cin, gdescrib);


	cout << endl;

	cout << "���ٴ�ȷ����Ʒ��Ϣ:" << endl;
	cout << "*********************************************" << endl;
	cout << "��Ʒ���ƣ�" << gname << endl;
	cout << "��Ʒ�۸�" << gprice << endl;
	cout << "��Ʒ������" << gnumb << endl;
	cout << "��Ʒ������" << gdescrib << endl;
	cout << "*********************************************" << endl;
	cout << endl;

	cout << "ȷ��������(y/n)";
	string judge;
	cin.sync();
	getline(cin, judge);

	//---�����������ļ�д��
	if (judge != "y") {
		cout << "��ȡ��������" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		string st = "������";

		/////////////////////��ȡʱ��
		struct tm* tm_ptr;
		time_t the_time;
		(void)time(&the_time);
		tm_ptr = gmtime(&the_time);
		int year = tm_ptr->tm_year + 1900;
		int month = tm_ptr->tm_mon + 1;
		int day = tm_ptr->tm_mday;
		string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
		/////////////////////////////////

		//SSSQQQLLL
		string sqlstr = SQLpublish_goods(gname, gprice, gnumb, gdescrib);
		//analySQL(sqlstr1);



		Goods* good = new Goods(GOODSIDback(numbgoods + 1), gname, gprice, gnumb, gdescrib, this->userID, theTime, st);
		gdvec.push_back(good);
		numbgoods++;
		//-------�����vec�������ļ�д��

		saveGOOD(gdvec);

		cout << "�����ɹ�����" << endl;
	}
	system("pause");
	system("cls");
};

//�鿴������Ʒ
void Seller::viewSGOODS(string ID,vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_goods(SELLER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "����" << setw(20) << "�ϼ�ʱ��" << setw(20) << "��Ʒ״̬" << setw(20) << endl;


	for (vector<Goods*>::iterator it = gdvec.begin(); it != gdvec.end(); it++) {
		if ((*it)->sellerID == ID) {
			cout << left << setw(20) << (*it)->commodityID << setw(20)
				<< (*it)->commodityName << setw(20)
				<< (*it)->price << setw(20)
				<< (*it)->number << setw(20)
				<< (*it)->addedDate << setw(20)
				<< (*it)->state << setw(20) << endl;
		}
	
	}
	cout << "************************************************************************************************************************" << endl;
	cout << endl;

	system("pause");
	system("cls");
};

//�޸���Ʒ��Ϣ
void Seller::modifyGOODS(vector<Goods*>& gdvec) {

	cout << endl;

	string gID;
	string gchoose;

	cout << "��������Ҫ�޸ĵ���ƷID��";
	cin.sync();
	getline(cin, gID);

	//����iterator�ҵ���Ʒ����λ��
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->sellerID == this->userID) break;
	}
	if (it == gdvec.end()) {
		cout << "�޴���Ʒ����" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��������Ҫ�޸ĵ���Ʒ���ԣ���1.�۸� 2.������ ";
	cin.sync();
	while (getline(cin, gchoose)) {
		if (gchoose.length() > 1 ) {
			cout << "�������󣡣����������룡��" << endl;
			cout << "��������Ҫ�޸ĵ���Ʒ���ԣ���1.�۸� 2.������ ";
			cin.sync();
			continue;
		}
		if (gchoose != "1" && gchoose != "2") {
			cout << "�������󣡣����������룡��" << endl;
			cout << "��������Ҫ�޸ĵ���Ʒ���ԣ���1.�۸� 2.������ ";
			cin.sync();
			continue;
		}
		//�޸�����
		if (gchoose == "2") {
			cout << "�������޸���Ʒ�������� ";
			string desci;
			cin.sync();
			getline(cin, desci);
			
			cout << "��ȷ����Ʒ��Ϣ���󣡣�" << endl;
			cout << "**********************************************" << endl;
			cout << "��Ʒ���ƣ�" << gID << endl;
			cout << "��Ʒ�۸�" << (*it)->commodityName << endl;
			cout << "��Ʒ������" << (*it)->price << endl;
			cout << "��Ʒ������" << desci << endl;
			cout << "**********************************************" << endl;

			cout << "ȷ���޸ģ�(y/n) ";
			string judge;
			cin.sync();
			getline(cin, judge);

			//---�޸Ĳ������ļ�д��
			if (judge != "y") {
				cout << "��ȡ���޸ġ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {

				//SSSQQQLLL
				string sqlstr = SQLmodify_goodsDescr(desci, (*it)->commodityID);
				//analySQL(sqlstr1);

				//�����޸�
				(*it)->description = desci;
				saveGOOD(gdvec);
				cout << "�޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				return;
			}

		}
		//�޸ļ۸�
		if (gchoose == "1") {
			cout << "�������޸���Ʒ�ļ۸񣺣���ҪһλС���� ";
			string prc;
			cin.sync();
			getline(cin, prc);

			//�ж������Ƿ�Ϊ����
			if (!isNumber(prc)) {
				cout << "�������󣡣��޸�ʧ�ܣ���" << endl;
				system("pause");
				system("cls");
				return;
			}

			//�ж��Ƿ�Ϊ����һλС��,���ҵ�С���㣬�ٽ��г������
			int i = 0;
			for (i; i < prc.length(); i++) {
				if (prc[i] == '.') break;
			}
			if (prc.length() - i - 1 > 1) {
				//����С��λ����
				cout << "���볬��С��λ���ȣ����޸�ʧ�ܣ���" << endl;
				system("pause");
				system("cls");
				return;
			}


			cout << "��ȷ����Ʒ��Ϣ���󣡣�" << endl;
			cout << "*****************************************" << endl;
			cout << "��Ʒ���ƣ�" << gID << endl;
			cout << "��Ʒ�۸�" << (*it)->commodityName << endl;
			cout << "��Ʒ������" << prc << endl;
			cout << "��Ʒ������" << (*it)->description << endl;
			cout << "*****************************************" << endl;

			cout << "ȷ���޸ģ�(y/n) ";
			string judge;
			cin.sync();
			getline(cin, judge);

			//---�޸Ĳ������ļ�д��
			if (judge != "y") {
				cout << "��ȡ���޸ġ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {

				//SSSQQQLLL
				string sqlstr = SQLmodify_goodsPrice(prc, (*it)->commodityID);
				//analySQL(sqlstr1);

				//�����޸�
				(*it)->price = prc;
				saveGOOD(gdvec);
				cout << "�޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

//�¼���Ʒ
void Seller::removeGOODS(vector<Goods*>& gdvec) {

	cout << endl;

	string gID;

	cout << "��������Ҫ�޸ĵ���ƷID��";
	cin.sync();
	getline(cin, gID);

	//����iterator�ҵ���Ʒ����λ��
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->sellerID == this->userID) break;
	}
	if (it == gdvec.end()) {
		cout << "�޴���Ʒ����" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ȷ���¼ܸ���Ʒ��" << endl;
	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "��ƷID" << setw(20) << "����" << setw(20) << "�۸�" << setw(20)
		<< "�ϼ�ʱ��" << setw(20) << "��Ʒ״̬" << setw(20) << endl;
	cout << left << setw(20) << (*it)->commodityID << setw(20)
		<< (*it)->commodityName << setw(20)
		<< (*it)->price << setw(20)
		<< (*it)->addedDate << setw(20)
		<< (*it)->state << setw(20) << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << endl;

	cout << "��ѡ��(y/n) ";
	string judge;
	cin.sync();
	getline(cin, judge);

	//---�޸Ĳ������ļ�д��
	if (judge != "y") {
		cout << "��ȡ���޸ġ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {

		//SSSQQQLLL
		string sqlstr = SQLremove_goods(SELLER, (*it)->commodityID);
		//analySQL(sqlstr1);

		//�����޸�
		(*it)->state = "���¼�";
		saveGOOD(gdvec);
		cout << "�¼ܳɹ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
};

//�鿴��ʷ����
void Seller::viewSORDER(string ID, vector<Order*>& orvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_order(SELLER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "����ID" << setw(20) << "��ƷID" << setw(20) << "���׵���" << setw(20)
		<< "����" << setw(20) << "����ʱ��" << setw(20) << "���ID" << setw(20) << endl;

	for (vector<Order*>::iterator it = orvec.begin(); it != orvec.end(); it++) {
		if ((*it)->sellerID == ID) {
			cout << left << setw(20) << (*it)->orderID << setw(20)
				<< (*it)->commodityID << setw(20)
				<< (*it)->unitPrice << setw(20)
				<< (*it)->number << setw(20)
				<< (*it)->date << setw(20)
				<< (*it)->buyerID << setw(20) << endl;
		}

	}
	cout << "************************************************************************************************************************" << endl;
	cout << endl;

	system("pause");
	system("cls");
};

//�����û�������
void Seller::exitSELLER() {
	system("pause");
	system("cls");
};


//---------------------��Ϣ����˵�
void User::showINFOMenu() {
	cout << "��������    ���ڴ����û�������Ϣ����ģʽ    ��������" << endl;
	cout << "==================================================" << endl;
	cout << "1.�鿴��Ϣ  2.�޸���Ϣ  3.��ֵ  4.�����û�������" << endl;
	cout << "==================================================" << endl;

};

void User::GetUserinfo(vector<Order*>& orvec) {

	cout << endl;
	//��ȡ�����ʽ�����м���
	string Balc = createBlcStr(orvec, this->userID);
	double blc = useCal(Balc);
	cout << endl;

	cout << "==============================" << endl;
	cout << "�û�����"<<this->username << endl;
	cout << "��ϵ��ʽ��"<<this->phoneNumber << endl;
	cout << "��ַ��"<<this->address << endl;
	cout << "Ǯ����"<<blc << endl;
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
		cout << "===================================================" << endl;
		cout << "===============������Ҫ�޸ĵ���Ϣ==================" << endl;
		cout << "====== 1.�û���  2.��ϵ��ʽ  3.��ַ  4.ȡ���޸�  ==" << endl;
		cout << "===================================================" << endl;

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

	string money;
	cout << "������Ҫ��ֵ�Ľ���Ҫ��һλС���� ";
	cin.sync();
	getline(cin, money);

	//if (!(cin >> money).get())			//cin>>�Ľ��������س������߿ո񶼿��ԣ����ǵ�cin��ȡ������cin�Ľ����������ٻ������д��ڣ������´���Ҫ��ȡʱ���ж�ȡ
	//	cout << "�������󣡣�" << endl;	//�����.get(),��cin.get()�������������в����ġ�\n��
	//cin.ignore(numeric_limits<std::streamsize>::max());				//��ջ�����(������뻺��������������) //��ƨ

	//�ж������Ƿ�Ϊ����
	if (!isNumber(money)) {
		cout << "�������󣡣���ֵʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	////�ж��Ƿ�Ϊ����һλС��,���ҵ�С���㣬�ٽ��г������
	int i = 0;
	for (i; i < money.length(); i++) {
		if (money[i] == '.') break;
	}
	if (money.length() - i - 1 > 1) {
		//����С��λ����
		cout << "���볬��С��λ���ȣ�����ֵʧ�ܣ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	//���ڸ��
	this->balance += stod(money);

	cout << "��ֵ�ɹ�����" << endl;


	//�����������û���ļ������ļ�ʱ
	//��д���׷�ӷ�ʽ���ļ�
	ofstream ofs("balance.txt", ios::out | ios::app);
	ifstream ifs("balance.txt", ios::in);

	//�õ���ǰ��ֵ��ϵͳʱ��
	struct tm* tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);
	int year = tm_ptr->tm_year + 1900;
	int month = tm_ptr->tm_mon + 1;
	int day = tm_ptr->tm_mday;
	string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);


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
		ofs << left << setw(20) << "��ֵ�û�ID"
			<< setw(20) << "��ֵ���"
			<< setw(30) << "��ֵʱ��" << endl;
	}
	//��ǰ�Ѿ����ļ�����
	ofs << left << setw(20) << this->userID
		<< setw(20) << money
		<< setw(30) << theTime << endl;

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



//-----------------------Э���Ժ���
string GOODSIDback(int i) {

	string kksk;
	if (i < 10) {
		kksk = "M00" + to_string(i);
	}
	else if (i < 100) {
		kksk = "M0" + to_string(i);
	}
	else if (i < 1000) {
		kksk = "M" + to_string(i);
	}
	return kksk;
}
string ORDERIDback(int i) {

	string kksk;
	if (i < 10) {
		kksk = "T00" + to_string(i);
	}
	else if (i < 100) {
		kksk = "T0" + to_string(i);
	}
	else if (i < 1000) {
		kksk = "T" + to_string(i);
	}
	return kksk;
}

void saveGOOD(vector<Goods*> gdvec) {
	ofstream ofs;
	ofs.open(FILEGOODS, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (Us::saveGoods)";
		return;
	}

	ofs << "��ƷID,����,�۸�,����,����,����ID,�ϼ�ʱ��,��Ʒ״̬" << endl;

	//�û�vecд��
	for (vector<Goods*>::iterator it = gdvec.begin(); it != gdvec.end(); it++) {
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

void saveORDER(vector<Order*> orvec) {
	ofstream ofs;
	ofs.open(FILEORDER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (Us::saveGoods)";
		return;
	}

	ofs << "����ID,��ƷID,���׵���,����,����ʱ��,����ID,���ID" << endl;

	//�û�vecд��
	for (vector<Order*>::iterator it = orvec.begin(); it != orvec.end(); it++) {
		ofs << (*it)->orderID << ","
			<< (*it)->commodityID << ","
			<< (*it)->unitPrice << ","
			<< (*it)->number << ","
			<< (*it)->date << ","
			<< (*it)->sellerID << ","
			<< (*it)->buyerID << endl;
	}
	ofs.close();
}

bool isNumber(const string& str) {
	istringstream sin(str);
	double test;
	return sin >> test && sin.eof();
}

string createBlcStr(vector<Order*> orvec, string inID) {

	//�򿪳�ֵ�ļ���ץȡ�û���ֵ����
	ifstream ifs("balance.txt", ios::in);
	//δ���ļ�
	if (!ifs.is_open()) {
		return "0.0";
	}
	vector<string> AddBlc; //�����ֵ��
	string str;
	//ȥ��û�õĵ�һ��
	getline(ifs, str);
	string UID, Balc, BTime;
	while (ifs >> UID && ifs >> Balc && ifs >> BTime) {
		if (inID == UID) {
			AddBlc.push_back(Balc);
		}
	}
	string rel1;
	for (vector<string>::iterator it = AddBlc.begin(); it != AddBlc.end(); it++) {
		rel1 += (*it);
		if (it + 1 != AddBlc.end()) rel1 += " + "; //������Ҫ����ĩβ�Ӻ�
	}


	//���������ļ������ɶ���ʽ��
	string bbb;
	string sss;
	vector<string> BuyPrc; //���������
	vector<string> SelPrc; //����������

	vector<Order*>::iterator ot = orvec.begin();
	for (ot; ot != orvec.end(); ot++) {
		//��Ҽ����
		if ((*ot)->buyerID == inID) {
			bbb = (*ot)->unitPrice + " * " + (*ot)->number;
			BuyPrc.push_back(bbb);
		}
		//���Ҽ����
		if ((*ot)->sellerID == inID) {
			sss = (*ot)->unitPrice + " * " + (*ot)->number;
			SelPrc.push_back(sss);
		}
	}

	string rel2;
	for (vector<string>::iterator bt = BuyPrc.begin(); bt != BuyPrc.end(); bt++) {
		rel2 += (*bt);
		if (bt + 1 != BuyPrc.end()) rel2 += " - "; //������Ҫ����ĩβ�Ӻ�
	}

	string rel3;
	for (vector<string>::iterator st = SelPrc.begin(); st != SelPrc.end(); st++) {
		rel3 += (*st);
		if (st + 1 != SelPrc.end()) rel3 += " + "; //������Ҫ����ĩβ�Ӻ�
	}


	string result = rel1;
	if (!rel2.empty()) result = result + " - " + rel2;
	if (!rel3.empty()) result = result + " + " + rel3;

	return result;
}