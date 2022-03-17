#include"Admin.h"

Admin::Admin() {
	numbUser = 0;
	numbGoods = 0;
	numbOrder = 0;
	//用户初始化
	this->USERINIT();
	//商品初始化
	this->GOODSINIT();
	//订单初始化
	this->ORDERINIT();

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
	cout << "========================================================================================" << endl;
	cout << "------------------------------您现在处于管理员模式--------------------------------------"<< endl;
	cout << "========================================================================================" << endl;
	cout << "  1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "========================================================================================" << endl;

}

void Admin::exitAD() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	system("cls");
	return;
}

void Admin::Goods_show() {
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "数量" << setw(20) << "描述" << setw(20) << "卖家ID" << setw(20)
		<< "上架时间" << setw(20) << "商品状态" << setw(20) << endl;

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
	cout << "请输入您要查找的商品名：";
	cin.sync();
	getline(cin, gname);

	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "数量" << setw(20) << "描述" << setw(20) << "卖家ID" << setw(20)
		<< "上架时间" << setw(20) << "商品状态" << endl;

	//寻找商品再vec中的位置
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = this->goodsVec.begin();
	for (it; it != this->goodsVec.end(); it++) {
		//寻找字符
		int fdstr = (*it)->commodityName.find(gname, 0);
		//若找到，则记录当前vec下标位置，进行输出
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
	//没有商品存在
	if (!flag) {
		cout << endl;
		cout << "                                   没有该商品！！                                         " << endl;
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
	//先查看一下商品列表
	this->Goods_show();

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
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "数量" << setw(20) << "描述" << setw(20) << "卖家ID" << setw(20)
		<< "上架时间" << setw(20) << "商品状态" << setw(20) << endl;
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
		cout << "取消下架!!" << endl;



	this->saveGOODFILE();

	system("pause");
	system("cls");
};

void Admin::Order_show() {
	cout << endl;
	cout << "**********************************************************************************************************************************************************" << endl;
	cout << left << setw(20) << "订单ID" << setw(20) << "商品ID" << setw(20) << "交易单价" << setw(20)
		<< "数量" << setw(20) << "交易时间" << setw(20) << "卖家ID" << setw(20)
		<< "买家ID" << endl;

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
	cout << left<< setw(20)<<"用户ID" << setw(20) << "姓名" << setw(20) << "密码" << setw(20)
		<<"手机号" << setw(20) <<"地址" << setw(20) << "用户余额" << setw(20) << "用户状态" << endl;
	if (!this->numbUser) {
		cout << endl;
		cout << "       无用户！！      " << endl;
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
			cout << "正常" << setw(20);
		}
		else {
			cout << "封禁" << setw(20);
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

				//顺便下架商品
				for (vector<Goods*>::iterator gt = this->goodsVec.begin(); gt != this->goodsVec.end(); gt++) {
					if ((*gt)->sellerID == theID) {
						(*gt)->state = "已下架";
					}
				}

				cout << "封禁成功！！" << endl;

				this->saveUSERFILE();
				this->saveGOODFILE();
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "未找到此用户！！" << endl;
	}


};







void Admin::USERINIT() {
	ifstream ifs(FILEUSER, ios::in);

	//打开失败
	if (!ifs.is_open()) {
		//cout << "user txt open failed!" << endl;
		//cout << "现在创建文件" << endl;
		ofstream ofs(FILEUSER, ios::out);
		ofs.close();
		return;
	}

	//每行读入
	string str;
	//去掉没用的第一行
	getline(ifs, str);
	//继续读入
	while (getline(ifs, str)) {
		numbUser++;
		stringstream kksk(str);

		vector<string> record;

		//将一行中以逗号为分隔符的字符串记录进record向量中
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//初始化新的商品对象
		User* gd = new User(record);
		//装进向量里面
		this->userVec.push_back(gd);
	}


	ifs.close();



}

void Admin::GOODSINIT() {
	ifstream ifs(FILEGOOD, ios::in);

	//打开失败
	if (!ifs.is_open()) {
		//cout << "goods txt open failed!" << endl;
		//cout << "现在创建文件" << endl;
		ofstream ofs(FILEGOOD, ios::out);
		return;
	}

	//每行读入
	string str;
	//去掉没用的第一行
	getline(ifs, str);
	//继续读入
	while (getline(ifs, str)) {
		numbGoods++;

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

void Admin::ORDERINIT() {
	ifstream ifs("order.txt", ios::in);

	//打开失败
	if (!ifs.is_open()) {
		//cout << "order txt open failed!" << endl;
		//cout << "现在创建文件" << endl;
		ofstream ofs("order.txt", ios::out);
		return;
	}

	//每行读入
	string str;
	//去掉没用的第一行
	getline(ifs, str);
	//继续读入
	while (getline(ifs, str)) {
		numbOrder++;

		stringstream kksk(str);

		vector<string> record;

		//将一行中以逗号为分隔符的字符串记录进record向量中
		while (kksk) {
			string tmp;
			getline(kksk, tmp, ',');
			record.push_back(tmp);
		}

		//初始化新的商品对象
		Order* gd = new Order(record);
		//装进向量里面
		this->orderVec.push_back(gd);
	}


	ifs.close();


}



/***************类外函数***********************/

void Admin::saveUSERFILE() {
	ofstream ofs;
	ofs.open(FILEUSER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (AD::saveUSERFILE)";
		return;
	}

	ofs << "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态" << endl;

	//用户vec写入
	for (vector<User*>::iterator it = this->userVec.begin(); it != this->userVec.end(); it++) {
		ofs << (*it)->userID << ","
			<< (*it)->username << ","
			<< (*it)->password << ","
			<< (*it)->phoneNumber << ","
			<< (*it)->address << ","
			<< to_string((*it)->balance) << ",";	//double转string
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
