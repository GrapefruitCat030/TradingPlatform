#include"Admin.h"

Admin::Admin() {
	orderArray = NULL;
	goodsArray = NULL;
	//用户初始化
	this->USERINIT();


	//numbUser = 0;

	//userArray = NULL;
	//orderArray = NULL;
	//goodsArray = NULL;
};

Admin::~Admin() {};

void Admin::show_Menu() {
	cout << "-----您现在处于管理员模式-----" << endl;
	cout << "====================================================================" << endl;
	cout << "  1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "===================================================================" << endl;

}

void Admin::exitAD() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
}

void Admin::Goods_show() {};

void Admin::searchGoods() {};

void Admin::removeGoods() {};

void Admin::Order_show() {};

void Admin::User_show() {
	cout << "用户ID" << "\t" << "姓名" << "\t" << "密码" <<"\t" 
		<<"手机号" << "\t" <<"地址" << "\t" << "用户余额" << "\t" << "用户状态" << endl;
	if (!this->numbUser) {
		cout << "----------无用户！！-----------" << endl;
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
			cout << "正常";
		}
		else {
			cout << "封禁";
		}

		cout << endl;
	}
	system("pause");
	system("cls");

};

void Admin::banUser() {
	string UID;
	cout << "请输入要封禁的用户ID：";
	cin.sync();
	getline(cin, UID);
	cout << "确定封禁？(Y/其他) ";
	string judge;
	cin.sync();
	getline(cin, judge);

	if (judge != "Y") {
		cout << "放弃封禁！！" << endl;
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
				cout << "封禁成功！！" << endl;

				this->saveFILE();

				system("pause");
				system("cls");
				return;
			}
		}
		cout << "未找到此用户！！" << endl;
	}


};

void Admin::Module_Admin() {
	//先进行清屏，然后管理员菜单展示
	system("cls");
	//用来储存用户选项
	string choicecc;
	bool judge = true;

	while (judge) {

		this->show_Menu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choicecc);
		//if (cin >> choicecc) {

		//}
		//else {
		//	cin.clear();
		//}
		if (size(choicecc) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		//char kksk = choicecc[0];
		switch (choicecc[0])
		{
		case '1':	//查看所有商品
			this->Goods_show();
			break;
		case '2':	//搜索商品
			this->searchGoods();
			break;
		case '3':	//下架商品
			this->removeGoods();
			break;
		case '4':	//查看所有订单
			this->Order_show();
			break;
		case '5':	//查看所有用户
			this->User_show();
			break;
		case '6':	//封禁用户
			this->banUser();
			break;
		case '7':	//注销
			this->exitAD();
			judge = false;
			break;
		default:
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}
}

void Admin::USERINIT() {
	//分三种情况初始化
	ifstream ifs;
	ifs.open("user.txt", ios::in);

	//1.用户文件不存在时
	if (!ifs.is_open()) {
		cout << "文件为空！！" << endl;
		numbUser = 0;
		//userVec = NULL;
		ifs.close();
		return;
	}

	//2.用户文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "内容为空！！" << endl;
		numbUser = 0;
		//userVec = NULL;
		ifs.close();
		return;
	}

	//3.用户文件存在且不为空
	numbUser = getnumb_USER();
	cout << "用户人数为：" << numbUser << endl;
	//userVec = new User * [numbUser];
	this->userInitArray();
}

void Admin::userInitArray() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::userInitArray)";
		return;
	}

	//用户ID
	string userID;
	//用户名
	string username;
	//密码
	string password;
	//联系方式
	string phoneNumber;
	//地址
	string address;
	//钱包余额
	double balance;
	//用户状态：1为正常，0为封禁
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
		if (userState == "正常") {
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


/***************类外函数***********************/
int getnumb_USER() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::getnumbUser)";
		exit(-1);
	}

	//用户ID
	string userID;
	//用户名
	string username;
	//密码
	string password;
	//联系方式
	string phoneNumber;
	//地址
	string address;
	//钱包余额
	double balance;
	//用户状态：1为正常，0为封禁
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

	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
		ofs << (*it)->userID << " "
			<< (*it)->username << " "
			<< (*it)->password << " "
			<< (*it)->phoneNumber << " "
			<< (*it)->address << " "
			<< (*it)->balance << " ";
		if ((*it)->userState == 1) {
			ofs << "正常" << endl;
		}
		else {
			ofs << "封禁" << endl;
		}

	}
	ofs.close();
};
