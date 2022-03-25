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



//----------------------用户函数
void User::showUSERMenu() {
	cout << "——————现在处于用户模式——————" << endl;
	cout << "==================================================" << endl;
	cout << "1.我是买家  2.我是卖家  3.个人信息管理  4.退出登录" << endl;
	cout << "=================================================" << endl;

};

void User::Module_BUYER(int& numbgoods, int& numborder, vector <User*>& userVec, vector<Goods*>& gdvec, vector<Order*>& orvec) {
	Buyer n_buyer;
	n_buyer.userID = this->userID;

	//先进行清屏，然后用户菜单展示
	system("cls");
	//用来储存用户选项
	string choicebb;
	bool judge = true;

	while (judge) {

		n_buyer.showBUYERMenu();
		cout << "输入选项：";
		cin.sync();
		getline(cin, choicebb);

		if (size(choicebb) > 1) {
			cout << "输入有误！请重新输入!!" << endl;
			system("pause");
			system("cls");
			continue;
		}

		switch (choicebb[0])
		{
		case '1':	//查看商品列表（只能看到在售）
			n_buyer.viewBGOODS(gdvec);
			break;
		case '2':	//购买商品
			n_buyer.buyGOODS(numbgoods, numborder, userVec, gdvec, orvec);
			break;
		case '3':	//搜索商品
			n_buyer.searchGOODS(gdvec);
			break;
		case '4':	//查看历史订单
			n_buyer.viewBORDER(orvec);
			break;
		case '5':	//查看商品详细信息
			n_buyer.detailGOODS(gdvec);
			break;
		case '6':	//返回用户主界面
			n_buyer.exitBUYER();
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
			n_seller.publishGOODS(numbgoods, gdvec);
			break;
		case '2':	//查看发布商品
			n_seller.viewSGOODS(userID, gdvec);
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
void User::infoManageUSER(vector<User*> vec, vector<Order*>& orvec) {
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
			this->GetUserinfo(orvec);
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




//---------------------买家菜单

//买家菜单展示
void Buyer::showBUYERMenu() {
	cout << "——————————          现在处于用户买家模式          ——————————" << endl;
	cout << "============================================================================================" << endl;
	cout << "1.查看商品列表  2.购买商品  3.搜索商品 4.查看历史订单  5.查看商品详细信息  6.返回用户主界面" << endl;
	cout << "============================================================================================" << endl;
};

//查看商品列表（只能看到在售）
void Buyer::viewBGOODS(vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_goods(BUYER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "上架时间" << setw(20) << "卖家ID" << endl;

	for (vector<Goods*>::iterator it = gdvec.begin(); it != gdvec.end(); it++) {
		if ((*it)->state == "销售中") {
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

//购买商品
void Buyer::buyGOODS(int& numbgoods, int& numborder, vector <User*>& usvec, vector<Goods*>& gdvec, vector<Order*>& orvec) {

	//利用iterator找到商品对应的买家
	vector<User*>::iterator bt = usvec.begin();
	for (bt; bt != usvec.end(); bt++) {
		if (this->userID == (*bt)->userID) break;
	}



	cout << "请输入商品ID： ";
	string gID;
	cin.sync();
	getline(cin, gID);

	//利用iterator找到商品所在位置
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->state == "销售中") break;
	}
	if (it == gdvec.end()) {
		cout << "无此商品！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//找到后
	cout << "请输入数量： ";
	string gnumb;
	cin.sync();
	getline(cin, gnumb);
	//判断输入是否为数字
	if (!isNumber(gnumb)) {
		cout << "输入有误！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断是否为整数
	int k = 0;
	for (k; k < gnumb.length(); k++) {
		if (gnumb[k] == '.') break;
	}
	if (gnumb.length() != k) {
		cout << "输入数量不是整数！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//判断商品数量够不够
	if (stoi(gnumb) > stoi((*it)->number)) {	//库存不足的情况
		cout << "没有足够库存！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//交易额
	double prcsum = stoi(gnumb) * stod((*it)->price);
	//判断交易额与买家余额关系
	if (prcsum > (*bt)->balance) {
		cout << "没有足够余额！！" << endl;
		system("pause");
		system("cls");
		return;
	}

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

	//SSSQQQLLL
	string sqlstr1 = SQLbuy_goodsOrder(ORDERIDback(numborder + 1), (*it)->commodityID, (*it)->price, gnumb, theTime, (*it)->sellerID, this->userID);
	string sqlstr2 = SQLbuy_goodsGoods((*it)->commodityID, gnumb);
	//analySQL(sqlstr1);
	//analySQL(sqlstr2);

	//商品够并且买家余额足够，生成订单
	Order* order = new Order(ORDERIDback(numborder + 1), (*it)->commodityID, (*it)->price, gnumb, theTime, (*it)->sellerID, this->userID);
	orvec.push_back(order);

	//进行商品修改
	int remainNumb = stoi((*it)->number) - stoi(gnumb);//剩余商品数量
	(*it)->number = to_string(remainNumb);
	//进一步修改商品状态及商品种类数
	if (remainNumb == 0) {
		(*it)->state = "已下架";

		//SSSQQQLLL
		string sqlstr3 = SQLnone_goods((*it)->commodityID);
		//analySQL(sqlstr3);

	}

	//利用iterator找到商品对应的卖家
	vector<User*>::iterator sut = usvec.begin();
	for (sut; sut != usvec.end(); sut++) {
		if ((*it)->sellerID == (*sut)->userID) break;
	}

	//进行买卖家余额变动
	(*sut)->balance += prcsum;
	(*bt)->balance -= prcsum;



	cout << "**************************************" << endl;
	cout << "**交易提醒*************************" << endl;
	cout << "交易时间：" << theTime << endl;
	cout << "交易单价：" << (*it)->price << endl;
	cout << "交易数量：" << gnumb << endl;
	cout << "交易状态：交易成功" << endl;
	cout << "您的余额：" << (*bt)->balance << endl;
	cout << "**************************************" << endl;
	cout << endl;

	saveGOOD(gdvec);
	saveORDER(orvec);

	system("pause");
	system("cls");
};

//搜索商品（只能看到在售）
void Buyer::searchGOODS(vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLsearch_goods(BUYER, this->userID);
	//analySQL(sqlstr1);

	string gname;
	cout << "请输入您要查找的商品名：";
	cin.sync();
	getline(cin, gname);

	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "上架时间" << setw(20) << "卖家ID" << endl;

	//寻找商品再vec中的位置
	bool flag = false;
	int i = 0;
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		//寻找字符
		int fdstr = (*it)->commodityName.find(gname, 0);
		//若找到，则记录当前vec下标位置，进行输出
		if (fdstr < (*it)->commodityName.length() && (*it)->state == "销售中") {
			cout << left << setw(20) << (*it)->commodityID << setw(20)
				<< (*it)->commodityName << setw(20)
				<< (*it)->price << setw(20)
				<< (*it)->addedDate << setw(20)
				<< (*it)->sellerID << endl;
			flag = true;
		}
		i++;
	}
	//没有商品存在
	if (!flag) {
		cout << "                   没有该商品！！                " << endl;
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

//查看历史订单
void Buyer::viewBORDER(vector<Order*>& orvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_order(BUYER, this->userID);
	//analySQL(sqlstr1);


	cout << endl;
	cout << "************************************************************************************************************" << endl;
	cout << left << setw(20) << "订单ID" << setw(20) << "商品ID" << setw(20) << "交易单价" << setw(20)
		<< "数量" << setw(20) << "交易时间" << setw(20) << "卖家ID" << setw(20) << endl;

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

//查看商品详细信息
void Buyer::detailGOODS(vector<Goods*>& gdvec) {



	cout << endl;

	string gID;

	cout << "请输入想要查看的商品ID：";
	cin.sync();
	getline(cin, gID);

	//SSSQQQLLL
	string sqlstr = SQLdetail_goods(gID);
	//analySQL(sqlstr1);

	//利用iterator找到商品所在位置
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->state == "销售中") break;
	}
	if (it == gdvec.end()) {
		cout << "无此商品！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	//找到商品
	cout << endl;
	cout << "************************************************" << endl;
	cout << "商品ID：" << (*it)->commodityID << endl;
	cout << "商品名称：" << (*it)->commodityName << endl;
	cout << "商品价格：" << (*it)->price << endl;
	cout << "上架时间：" << (*it)->addedDate << endl;
	cout << "商品描述：" << (*it)->description << endl;
	cout << "商品卖家: " << (*it)->sellerID << endl;
	cout << "************************************************" << endl;

	system("pause");
	system("cls");

};

//返回用户主界面
void Buyer::exitBUYER() {
	system("pause");
	system("cls");
};




//---------------------卖家菜单

//卖家菜单展示
void Seller::showSELLERMenu() {
	cout << "————————————         现在处于用户卖家模式        ———————————" << endl;
	cout << "========================================================================================" << endl;
	cout << "1.发布商品  2.查看发布商品  3.修改商品信息  4.下架商品 5.查看历史订单  6.返回用户主界面" << endl;
	cout << "========================================================================================" << endl;
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

	cout << "请输入商品价值：（需要一位小数） ";
	cin.sync();
	getline(cin, gprice);
	//判断是否为一位小数
	//判断输入是否为数字
	if (!isNumber(gprice)) {
		cout << "输入有误！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断是否为保留一位小数,先找到小数点，再进行长度相减
	int i = 0;
	for (i; i < gprice.length(); i++) {
		if (gprice[i] == '.') break;
	}
	if (gprice.length() - i - 1 > 1) {
		//超出小数位长度
		cout << "输入超出小数位长度！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "请输入商品数量：";
	cin.sync();
	getline(cin, gnumb);
	//判断输入是否为数字
	if (!isNumber(gnumb)) {
		cout << "输入有误！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断是否为整数
	int k = 0;
	for (k; k < gnumb.length(); k++) {
		if (gnumb[k] == '.') break;
	}
	if (gnumb.length() != k) {
		cout << "输入数量不是整数！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "请输入商品描述：";
	cin.sync();
	getline(cin, gdescrib);


	cout << endl;

	cout << "请再次确定商品信息:" << endl;
	cout << "*********************************************" << endl;
	cout << "商品名称：" << gname << endl;
	cout << "商品价格：" << gprice << endl;
	cout << "商品数量：" << gnumb << endl;
	cout << "商品描述：" << gdescrib << endl;
	cout << "*********************************************" << endl;
	cout << endl;

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

		//SSSQQQLLL
		string sqlstr = SQLpublish_goods(gname, gprice, gnumb, gdescrib);
		//analySQL(sqlstr1);



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
void Seller::viewSGOODS(string ID, vector<Goods*>& gdvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_goods(SELLER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "数量" << setw(20) << "上架时间" << setw(20) << "商品状态" << setw(20) << endl;


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

//修改商品信息
void Seller::modifyGOODS(vector<Goods*>& gdvec) {

	cout << endl;

	string gID;
	string gchoose;

	cout << "请输入需要修改的商品ID：";
	cin.sync();
	getline(cin, gID);

	//利用iterator找到商品所在位置
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->sellerID == this->userID) break;
	}
	if (it == gdvec.end()) {
		cout << "无此商品！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入需要修改的商品属性：（1.价格 2.描述） ";
	cin.sync();
	while (getline(cin, gchoose)) {
		if (gchoose.length() > 1) {
			cout << "输入有误！！请重新输入！！" << endl;
			cout << "请输入需要修改的商品属性：（1.价格 2.描述） ";
			cin.sync();
			continue;
		}
		if (gchoose != "1" && gchoose != "2") {
			cout << "输入有误！！请重新输入！！" << endl;
			cout << "请输入需要修改的商品属性：（1.价格 2.描述） ";
			cin.sync();
			continue;
		}
		//修改描述
		if (gchoose == "2") {
			cout << "请输入修改商品的描述： ";
			string desci;
			cin.sync();
			getline(cin, desci);

			cout << "请确定商品信息无误！！" << endl;
			cout << "**********************************************" << endl;
			cout << "商品名称：" << gID << endl;
			cout << "商品价格：" << (*it)->commodityName << endl;
			cout << "商品数量：" << (*it)->price << endl;
			cout << "商品描述：" << desci << endl;
			cout << "**********************************************" << endl;

			cout << "确定修改？(y/n) ";
			string judge;
			cin.sync();
			getline(cin, judge);

			//---修改并进行文件写入
			if (judge != "y") {
				cout << "已取消修改。" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {

				//SSSQQQLLL
				string sqlstr = SQLmodify_goodsDescr(desci, (*it)->commodityID);
				//analySQL(sqlstr1);

				//进行修改
				(*it)->description = desci;
				saveGOOD(gdvec);
				cout << "修改成功！！" << endl;
				system("pause");
				system("cls");
				return;
			}

		}
		//修改价格
		if (gchoose == "1") {
			cout << "请输入修改商品的价格：（需要一位小数） ";
			string prc;
			cin.sync();
			getline(cin, prc);

			//判断输入是否为数字
			if (!isNumber(prc)) {
				cout << "输入有误！！修改失败！！" << endl;
				system("pause");
				system("cls");
				return;
			}

			//判断是否为保留一位小数,先找到小数点，再进行长度相减
			int i = 0;
			for (i; i < prc.length(); i++) {
				if (prc[i] == '.') break;
			}
			if (prc.length() - i - 1 > 1) {
				//超出小数位长度
				cout << "输入超出小数位长度！！修改失败！！" << endl;
				system("pause");
				system("cls");
				return;
			}


			cout << "请确定商品信息无误！！" << endl;
			cout << "*****************************************" << endl;
			cout << "商品名称：" << gID << endl;
			cout << "商品价格：" << (*it)->commodityName << endl;
			cout << "商品数量：" << prc << endl;
			cout << "商品描述：" << (*it)->description << endl;
			cout << "*****************************************" << endl;

			cout << "确定修改？(y/n) ";
			string judge;
			cin.sync();
			getline(cin, judge);

			//---修改并进行文件写入
			if (judge != "y") {
				cout << "已取消修改。" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {

				//SSSQQQLLL
				string sqlstr = SQLmodify_goodsPrice(prc, (*it)->commodityID);
				//analySQL(sqlstr1);

				//进行修改
				(*it)->price = prc;
				saveGOOD(gdvec);
				cout << "修改成功！！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

//下架商品
void Seller::removeGOODS(vector<Goods*>& gdvec) {

	cout << endl;

	string gID;

	cout << "请输入需要修改的商品ID：";
	cin.sync();
	getline(cin, gID);

	//利用iterator找到商品所在位置
	vector<Goods*>::iterator it = gdvec.begin();
	for (it; it != gdvec.end(); it++) {
		if ((*it)->commodityID == gID && (*it)->sellerID == this->userID) break;
	}
	if (it == gdvec.end()) {
		cout << "无此商品！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "确定下架该商品？" << endl;
	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "商品ID" << setw(20) << "名称" << setw(20) << "价格" << setw(20)
		<< "上架时间" << setw(20) << "商品状态" << setw(20) << endl;
	cout << left << setw(20) << (*it)->commodityID << setw(20)
		<< (*it)->commodityName << setw(20)
		<< (*it)->price << setw(20)
		<< (*it)->addedDate << setw(20)
		<< (*it)->state << setw(20) << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << endl;

	cout << "请选择：(y/n) ";
	string judge;
	cin.sync();
	getline(cin, judge);

	//---修改并进行文件写入
	if (judge != "y") {
		cout << "已取消修改。" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {

		//SSSQQQLLL
		string sqlstr = SQLremove_goods(SELLER, (*it)->commodityID);
		//analySQL(sqlstr1);

		//进行修改
		(*it)->state = "已下架";
		saveGOOD(gdvec);
		cout << "下架成功！！" << endl;
		system("pause");
		system("cls");
		return;
	}
};

//查看历史订单
void Seller::viewSORDER(string ID, vector<Order*>& orvec) {

	//SSSQQQLLL
	string sqlstr = SQLshow_order(SELLER, this->userID);
	//analySQL(sqlstr1);

	cout << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << left << setw(20) << "订单ID" << setw(20) << "商品ID" << setw(20) << "交易单价" << setw(20)
		<< "数量" << setw(20) << "交易时间" << setw(20) << "买家ID" << setw(20) << endl;

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

//返回用户主界面
void Seller::exitSELLER() {
	system("pause");
	system("cls");
};


//---------------------信息管理菜单
void User::showINFOMenu() {
	cout << "————    现在处于用户个人信息管理模式    ————" << endl;
	cout << "==================================================" << endl;
	cout << "1.查看信息  2.修改信息  3.充值  4.返回用户主界面" << endl;
	cout << "==================================================" << endl;

};

void User::GetUserinfo(vector<Order*>& orvec) {

	cout << endl;
	//获取余额算式并进行计算
	string Balc = createBlcStr(orvec, this->userID);
	double blc = useCal(Balc);
	cout << endl;

	cout << "==============================" << endl;
	cout << "用户名：" << this->username << endl;
	cout << "联系方式：" << this->phoneNumber << endl;
	cout << "地址：" << this->address << endl;
	cout << "钱包余额：" << blc << endl;
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
		cout << endl;
		//菜单展示
		cout << "================================================================" << endl;
		cout << "===================请输入要修改的信息===========================" << endl;
		cout << "====== 1.用户名  2.联系方式  3.地址  4.修改密码 5.取消修改  ====" << endl;
		cout << "================================================================" << endl;
		cout << endl;

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
			for (vector<User*>::iterator it = vec.begin(); it != vec.end(); it++) {
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
		case'4':	//修改用户密码
		{
			string ogpword, nwpword1, nwpword2;
			cout << "请输入原密码:  ";
			cin.sync();
			getline(cin, ogpword);
			if (ogpword == this->password) {
				cout << "请输入新密码:  ";
				//输入密码回显*
				cin.sync();
				char a;
				int i = 0;
				while (1)
				{
					a = _getch();        //获取输入的密码
					if (a == 13)		//回车返回
					{
						break;
					}
					if (a == 8)			//退格
					{
						if (nwpword1.length() == 0)		//如果第一个键为退格键
						{
							cout << "密码为空,请输入密码：";
							continue;
						}
						cout << "\b \b";
						i++;							//清除所要删掉的字符
						nwpword1[nwpword1.length() - i] = '\0';

					}
					else
					{
						nwpword1 += a;
						cout << "*";
					}

				}
				cin.sync();
				cout << endl;

				cout << "请再次输入新密码:  ";
				//输入密码回显*
				char b;
				i = 0;
				while (1)
				{
					b = _getch();        //获取输入的密码
					if (b == 13)		//回车返回
					{
						break;
					}
					if (b == 8)			//退格
					{
						if (nwpword2.length() == 0)		//如果第一个键为退格键
						{
							cout << "密码为空,请输入密码：";
							continue;
						}
						cout << "\b \b";
						i++;							//清除所要删掉的字符
						nwpword2[nwpword2.length() - i] = '\0';

					}
					else
					{
						nwpword2 += b;
						cout << "*";
					}

				}
				cout << endl;

				if (nwpword1 == nwpword2) {
					this->password = nwpword1;
					cout << "修改成功！！" << endl;
				}
				else {
					cout << "两次输入不符！！修改失败！！" << endl;
				}

			}
			else {
				cout << "与原密码不符！！修改失败！！" << endl;
			}
			judge = false;
			system("pause");
			system("cls");
		}
		break;
		case '5':
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

	string money;
	cout << "请输入要充值的金额：（要求一位小数） ";
	cin.sync();
	getline(cin, money);

	//if (!(cin >> money).get())			//cin>>的结束符，回车，或者空格都可以，但是当cin读取结束后，cin的结束符还会再缓冲区中存在，并让下次需要读取时进行读取
	//	cout << "输入有误！！" << endl;	//添加了.get(),用cin.get()来消除缓冲区中残留的‘\n’
	//cin.ignore(numeric_limits<std::streamsize>::max());				//清空缓冲区(清除输入缓冲区的所有内容) //放屁

	//判断输入是否为数字
	if (!isNumber(money)) {
		cout << "输入有误！！充值失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	////判断是否为保留一位小数,先找到小数点，再进行长度相减
	int i = 0;
	for (i; i < money.length(); i++) {
		if (money[i] == '.') break;
	}
	if (money.length() - i - 1 > 1) {
		//超出小数位长度
		cout << "输入超出小数位长度！！充值失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//终于搞好
	this->balance += stod(money);

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
		ofs << left << setw(20) << "充值用户ID"
			<< setw(20) << "充值金额"
			<< setw(30) << "充值时间" << endl;
	}
	//先前已经有文件存在
	ofs << left << setw(20) << this->userID
		<< setw(20) << money
		<< setw(30) << theTime << endl;

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

void saveORDER(vector<Order*> orvec) {
	ofstream ofs;
	ofs.open(FILEORDER, ios::out);
	if (!ofs.is_open()) {
		cout << "FILE OPEN WRONG (Us::saveGoods)";
		return;
	}

	ofs << "订单ID,商品ID,交易单价,数量,交易时间,卖家ID,买家ID" << endl;

	//用户vec写入
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

	//打开充值文件，抓取用户充值数据
	ifstream ifs("balance.txt", ios::in);
	//未有文件
	if (!ifs.is_open()) {
		return "0.0";
	}
	vector<string> AddBlc; //储存充值数
	string str;
	//去掉没用的第一行
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
		if (it + 1 != AddBlc.end()) rel1 += " + "; //可能需要保留末尾加号
	}


	//遍历订单文件，生成订单式子
	string bbb;
	string sss;
	vector<string> BuyPrc; //储存买家数
	vector<string> SelPrc; //储存卖家数

	vector<Order*>::iterator ot = orvec.begin();
	for (ot; ot != orvec.end(); ot++) {
		//买家减余额
		if ((*ot)->buyerID == inID) {
			bbb = (*ot)->unitPrice + " * " + (*ot)->number;
			BuyPrc.push_back(bbb);
		}
		//卖家加余额
		if ((*ot)->sellerID == inID) {
			sss = (*ot)->unitPrice + " * " + (*ot)->number;
			SelPrc.push_back(sss);
		}
	}

	string rel2;
	for (vector<string>::iterator bt = BuyPrc.begin(); bt != BuyPrc.end(); bt++) {
		rel2 += (*bt);
		if (bt + 1 != BuyPrc.end()) rel2 += " - "; //可能需要保留末尾加号
	}

	string rel3;
	for (vector<string>::iterator st = SelPrc.begin(); st != SelPrc.end(); st++) {
		rel3 += (*st);
		if (st + 1 != SelPrc.end()) rel3 += " + "; //可能需要保留末尾加号
	}


	string result = rel1;
	if (!rel2.empty()) result = result + " - " + rel2;
	if (!rel3.empty()) result = result + " + " + rel3;

	return result;
}