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
	//用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态
	//U001, 南大, 123456, 12345678, 仙林大道163号, 1024.0, 正常
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
			string usstr = vcstr.at(i);	//	传入的是 正常/封禁
			if (usstr == "正常") {
				userState = 1;
			}
			if (usstr == "封禁") {
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



//----------------------功能函数------------------------
void User::showUSERMenu() {
	cout << "——————现在处于用户模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.我是买家  2.我是卖家  3.个人信息管理  4.退出登录" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER() {};

void User::Module_SELLER(int& numbgoods, vector<Goods*>& gdvec, vector<Order*>& orvec) {
	Seller n_seller;
	n_seller.userID = this->userID;

	//先进行清屏，然后用户菜单展示
	system("cls");
	//用来储存用户选项
	string choicess;
	bool judge = true;

	while (judge) {

		n_seller.showSELLERMenu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choicess);

		if (size(choicess) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choicess[0])
		{
		case '1':	//发布商品
			n_seller.publishGOODS(numbgoods,gdvec);
			break;
		case '2':	//查看发布商品
			n_seller.viewSGOODS(userID,gdvec);
			break;
		case '3':	//修改商品信息
			n_seller.modifyGOODS(gdvec);
			break;
		case '4':	//下架商品
			n_seller.removeGOODS(gdvec);
			break;
		case '5':	//查看历史订单
			n_seller.viewSORDER(userID, orvec);
			break;
		case '6':	//返回用户主界面
			n_seller.exitSELLER();
			judge = false;
			break;

		default:
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}



};
														//外面PL的switch语句中已经有保存函数
void User::infoManageUSER(vector<User*> vec) {
	//先进行清屏，然后用户菜单展示
	system("cls");
	//用来储存用户选项
	string choiceii;
	bool judge = true;

	while (judge) {

		this->showINFOMenu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choiceii);

		if (size(choiceii) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choiceii[0])
		{
		case '1':	//查看信息
			this->GetUserinfo();
			break;
		case '2':	//修改信息
			this->ModifyUserinfo(vec);
			break;
		case '3':	//充值
			this->Topup_Userbalance();
			break;
		case '4':	//返回用户主界面
			this->exitINFO();
			judge = false;
			break;
		default:
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}

};

void User::exitUSER() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
};






//---------------------卖家菜单

//卖家菜单展示
void Seller::showSELLERMenu() {
	cout << "————————————现在处于用户卖家模式————————————" << endl;
	cout << "==============================================================================" << endl;
	cout << "1.发布商品  2.查看发布商品  3.修改商品信息  4.下架商品 5.查看历史订单  6.返回用户主界面" << endl;
	cout << "==============================================================================" << endl;

};

//发布商品
void Seller::publishGOODS(int& numbgoods, vector<Goods*>& gdvec) {

	cout << endl << endl;

	string gname;
	string gprice;
	string gnumb;
	string gdescrib;

	cout << "请输入商品名称：";
	cin.sync();
	getline(cin, gname);
	cout << "请输入商品价值：";
	cin.sync();
	getline(cin, gprice);
	cout << "请输入商品数量：";
	cin.sync();
	getline(cin, gnumb);
	cout << "请输入商品描述：";
	cin.sync();
	getline(cin, gdescrib);


	cout << endl << endl;

	cout << "请再次确定商品信息:" << endl;
	cout << "商品名称：" << gname << endl;
	cout << "商品价格：" << gprice << endl;
	cout << "商品数量：" << gnumb << endl;
	cout << "商品描述：" << gdescrib << endl;

	cout << "确定发布？(y/n)";
	string judge;
	cin.sync();
	getline(cin, judge);

	//---发布并进行文件写入
	if (judge != "y") {
		cout << "已取消发布。" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		string st = "销售中";

		/////////////////////获取时间
		struct tm* tm_ptr;
		time_t the_time;
		(void)time(&the_time);
		tm_ptr = gmtime(&the_time);
		int year = tm_ptr->tm_year + 1900;
		int month = tm_ptr->tm_mon + 1;
		int day = tm_ptr->tm_mday;
		string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
		/////////////////////////////////

		Goods* good = new Goods(GOODSIDback(numbgoods + 1), gname, gprice, gnumb, gdescrib, this->userID, theTime, st);
		gdvec.push_back(good);
		numbgoods++;
		//-------保存该vec，进行文件写入

		saveGOOD(gdvec);

		cout << "发布成功！！" << endl;
	}
	system("pause");
	system("cls");
};

//查看发布商品
void Seller::viewSGOODS(string ID,vector<Goods*>& gdvec) {
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "商品ID" << "\t" << "名称" << "\t" << "价格" << "\t"
		<< "数量" << "\t" << "上架时间" << "\t" << "商品状态" << endl;

	for (vector<Goods*>::iterator it = gdvec.begin(); it != gdvec.end(); it++) {
		if ((*it)->sellerID == ID) {
			cout << (*it)->commodityID << "\t";
			cout << (*it)->commodityName << "\t";
			cout << (*it)->price << "\t";
			cout << (*it)->number << "\t";
			cout << (*it)->addedDate << "\t";
			cout << (*it)->state << endl;
		}
	
	}
	cout << "*****************************************" << endl;

	system("pause");
	system("cls");
};


//修改商品信息
void Seller::modifyGOODS(vector<Goods*>& gdvec) {};
//下架商品
void Seller::removeGOODS(vector<Goods*>& gdvec) {};
//查看历史订单
void Seller::viewSORDER(string ID, vector<Order*>& orvec) {
	cout << endl;
	cout << "*****************************************" << endl;
	cout << "订单ID" << "\t" << "商品ID" << "\t" << "交易单价" << "\t"
		<< "数量" << "\t" << "交易时间" << "\t" << "买家ID" << endl;

	for (vector<Order*>::iterator it = orvec.begin(); it != orvec.end(); it++) {
		if ((*it)->sellerID == ID) {
			cout << (*it)->orderID << "\t";
			cout << (*it)->commodityID << "\t";
			cout << (*it)->unitPrice << "\t";
			cout << (*it)->number << "\t";
			cout << (*it)->date << "\t";
			cout << (*it)->buyerID << endl;
		}

	}
	cout << "*****************************************" << endl;

	system("pause");
	system("cls");
};
//返回用户主界面
void Seller::exitSELLER() {
	system("pause");
	system("cls");
};






//---------------------信息管理菜单
void User::showINFOMenu() {
	cout << "——————现在处于用户个人信息管理模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.查看信息  2.修改信息  3.充值  4.返回用户主界面" << endl;
	cout << "=================================================" << endl;

};

void User::GetUserinfo() {
	cout << "==============================" << endl;
	cout << "用户名："<<this->username << endl;
	cout << "联系方式："<<this->phoneNumber << endl;
	cout << "地址："<<this->address << endl;
	cout << "钱包余额："<<this->balance << endl;
	cout << "==============================" << endl;
	system("pause");
	system("cls");
	return;
};

void User::ModifyUserinfo(vector<User*> vec) {
	
	string choice;
	bool judge = true;

	//进入循环
	while (judge) {
		//菜单展示
		cout << "=====================================" << endl;
		cout << "=========请输入要修改的信息===========" << endl;
		cout << "====== 1.用户名  2.联系方式  3.地址  4.取消修改======" << endl;
		cout << "==========================================" << endl;

		//输入选择
		cout << "输入选项：";
		cin.sync();
		getline(cin, choice);

		if (size(choice) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choice[0])
		{
		case '1':	//修改用户名,注意用户名不能相同
		{
			cout << "请输入修改后的用户名：";
			string Uname;
			cin.sync();
			getline(cin, Uname);

			//进行用户名的遍历
			for (vector<User*>::iterator it =vec.begin(); it != vec.end(); it++) {
				if (Uname == (*it)->username) {
					//失败，已存在用户名
					cout << "注册失败！！已存在用户名！！" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			
			
			//成功则修改
			this->username = Uname;
			cout << "修改成功！！" << endl;
			judge = false;
			system("pause");
			system("cls");
		}
			break;
		case '2':	//修改联系方式
		{
			cout << "请输入修改后的联系方式：";
			string number;
			cin.sync();
			getline(cin, number);

			this->phoneNumber = number;
			cout << "修改成功！！" << endl;
			judge = false;

			system("pause");
			system("cls");
		}
			break;
		case '3':	//修改地址
		{
			cout << "请输入修改后的地址：";
			string addr;
			cin.sync();
			getline(cin, addr);

			this->address = addr;


			cout << "修改成功！！" << endl;
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
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls"); //清屏
			break;
		}
	}



};

void User::Topup_Userbalance() {

	double money;
	cout << "请输入要充值的金额：";
	cin.sync();
	(cin >> money).get();	//cin>>的结束符，回车，或者空格都可以，但是当cin读取结束后，cin的结束符还会再缓冲区中存在，并让下次需要读取时进行读取
							//添加了.get(),用cin.get()来消除缓冲区中残留的‘\n’

	//cin.ignore(numeric_limits<std::streamsize>::max());				//清空缓冲区(清除输入缓冲区的所有内容) //放屁
	this->balance += money;

	cout << "充值成功！！" << endl;


	//分两种情况：没有文件和有文件时
	//以写入和追加方式打开文件
	ofstream ofs("balance.txt", ios::out | ios::app);
	ifstream ifs("balance.txt", ios::in);

	//拿到当前充值的系统时间
	struct tm* tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);
	int year = tm_ptr->tm_year + 1900;
	int month = tm_ptr->tm_mon + 1;
	int day = tm_ptr->tm_mday;
	string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);


	//无文件，进行创建
	if (!ofs.is_open()) {
		cout << "the balance txt open failed." << endl;
		//ofs << setw(10) << setiosflags(ios::left) << "充值用户ID" 
		//	<< setw(10) << setiosflags(ios::left) <<"充值金额"
		//	<< setw(30) << setiosflags(ios::left) <<"充值时间" << endl;

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


	//判断文件为空(eof)
	char ch;
	if (!ifs.get(ch)) {
		ofs << setw(20) << setiosflags(ios::left) << "充值用户ID"
			<< setw(20) << setiosflags(ios::left) << "充值金额"
			<< setw(30) << setiosflags(ios::left) << "充值时间" << endl;
	}
	//先前已经有文件存在
	ofs << setw(20) << setiosflags(ios::left) << this->userID
		<< setw(20) << setiosflags(ios::left) << money
		<< setw(30) << setiosflags(ios::left) << theTime;

	//关闭文件
	ofs.close();
	ifs.close();

	system("pause");
	system("cls");
};

void User::exitINFO() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
};



//-----------------------协助性函数
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


void saveGOOD(vector<Goods*> gdvec) {
	ofstream ofs;
	ofs.open(FILEGOODS, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (Us::saveGoods)";
		return;
	}

	ofs << "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态" << endl;

	//用户vec写入
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