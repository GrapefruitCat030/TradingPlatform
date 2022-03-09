#include"User.h"


User::User() { userState = 1; balance = 0.0; };
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



//-------------功能函数-----------------
void User::showUSERMenu() {
	cout << "——————现在处于用户模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.我是买家  2.我是卖家  3.个人信息管理  4.退出登录" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER() {};

void User::Module_SELLER() {};


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


//信息管理菜单
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
	time_t blcTime;
	time(&blcTime);

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
		<< setw(30) << setiosflags(ios::left) << ctime(&blcTime);

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

