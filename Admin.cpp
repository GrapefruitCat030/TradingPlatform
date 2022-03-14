#include"Admin.h"

Admin::Admin() {

	//用户初始化
	this->USERINIT();
	//商品初始化
	this->GOODSINIT();

	//numbUser = 0;

	//userArray = NULL;
	//orderArray = NULL;
	//goodsArray = NULL;
};

Admin::~Admin() {};

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
			system("pause");
			system("cls");
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

void Admin::Goods_show() {
	cout << "商品ID" << "\t" << "名称" << "\t" << "价格" << "\t"
		<< "数量" << "\t" << "描述" << "\t" << "卖家ID" << "\t" 
		<< "上架时间" << "\t"<<"商品状态"<<endl;

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
	cout << "请输入您要查找的商品名：";
	cin.sync();
	getline(cin, gname);

	cout << "****************************************" << endl;
	cout << "商品ID" << "\t" << "名称" << "\t" << "价格" << "\t"
		<< "数量" << "\t" << "描述" << "\t" << "卖家ID" << "\t"
		<< "上架时间" << "\t" << "商品状态" << endl;

	//寻找商品再vec中的位置
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		//寻找字符
		int fdstr = (*it)->commodityName.find(gname, 0);
		//若找到，则记录当前vec下标位置，进行输出
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
	//没有商品存在
	if (!flag) {
		cout << "------没有该商品！！-------" << endl;
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
	//先查看一下商品列表
	cout << "****************************************" << endl;
	this->Goods_show();
	cout << "****************************************" << endl;

	string gstr;
	cout << "输入想要下架的商品：";
	getline(cin, gstr);
	//遍历
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		if ((*it)->commodityID == gstr) break;
	}
	//无商品
	if (it == this->goodsVec.end()) {
		cout << "没有该商品！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "确定下架该商品吗?" << endl;
	cout << "****************************************" << endl;
	cout << "商品ID" << "\t" << "名称" << "\t" << "价格" << "\t"
		<< "数量" << "\t" << "描述" << "\t" << "卖家ID" << "\t"
		<< "上架时间" << "\t" << "商品状态" << endl;
	cout << (*it)->commodityID << "\t";
	cout << (*it)->commodityName << "\t";
	cout << (*it)->price << "\t";
	cout << (*it)->number << "\t";
	cout << (*it)->description << "\t";
	cout << (*it)->sellerID << "\t";
	cout << (*it)->addedDate << "\t";
	cout << (*it)->state << endl;
	cout << "****************************************" << endl;
	cout << "请选择：(y/n)  ";

	string flag;
	cin.sync();
	getline(cin, flag);
	//进行修改
	if (flag == "y") {
		(*it)->state = "已下架";
		cout << "下架成功！！" << endl;
	}
	else
		cout << "取消下架" << endl;


	this->saveGOODFILE();

	system("pause");
	system("cls");
};

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

				this->saveUSERFILE();

				system("pause");
				system("cls");
				return;
			}
		}
		cout << "未找到此用户！！" << endl;
	}


};







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
	this->userInitVec();
}

void Admin::userInitVec() {
	ifstream ifs;
	ifs.open("user.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "FILE OPEN WRONG (AD::userInitVec)";
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

void Admin::GOODSINIT() {
	ifstream ifs("commodity.txt", ios::in);

	//打开失败
	if (!ifs.is_open()) {
		cout << "goods txt open failed!" << endl;
		return;
	}

	//每行读入
	string str;
	//去掉没用的第一行
	getline(ifs, str);
	//继续读入
	while (getline(ifs, str)) {

		stringstream kksk(str);

		vector<string> record;

		//将一行中以逗号为分隔符的字符串记录进record向量中
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//初始化新的商品对象
		Goods* gd = new Goods(record);
		//装进向量里面
		this->goodsVec.push_back(gd);
	}


	ifs.close();

};





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

void Admin::saveUSERFILE() {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (AD::saveUSERFILE)";
		return;
	}

	//用户vec写入
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

void Admin::saveGOODFILE() {
	ofstream ofs(FILEGOOD, ios::out);

	//判断打开是否成功
	if (!ofs.is_open()) {
		cout << "file open failed (AD:saveGOODFILE)" << endl;
		return;
	}

	ofs << "商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态" << endl;

	//商品vec写入
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