
#include"Platform.h"



Platform::Platform() {};

Platform::~Platform() {};

void Platform::show_Menu() {
	cout << "===============================================================" << endl;
	cout << "============      欢迎使用冬奥纪念品交易平台     =============" << endl;
	cout << "===============================================================" << endl;
	cout << "  1.管理员登录	 2.用户注册	3.用户登录	4.退出系统" << endl;
	cout << "===============================================================" << endl;
	cout << endl;
}

void Platform::exitPlatform() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	exit(0);
}

void Platform::AdminLogin(Admin& m_Admin) {

	string A_Name, A_key;
	cout << "请输入管理员姓名：";
	cin.sync();
	getline(cin, A_Name);
	cout << "请输入密码：";
	cin.sync();
	//getline(cin, A_key);
	//输入密码回显*
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
			if (A_key.length() == 0)		//如果第一个键为退格键
			{
				cout << "密码为空,请输入密码：";
				continue;
			}
			cout << "\b \b";
			i++;							//清除所要删掉的字符
			A_key[A_key.length() - i] = '\0';

		}
		else
		{
			A_key += a;
			cout << "*";
		}

	}
	cin.sync();
	cout << endl;


	//登录失败则清屏返回主菜单
	if (A_Name != ADNAME || A_key != ADKEY) {
		cout << "---------登录失败，返回主菜单-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	//成功则进入管理员模块
	else {
		cout << "登录成功！！" << endl;
		system("pause");
		m_Admin.Module_Admin();

	}
};

void Platform::User_register(Admin& m_Admin) {
	string Uname;
	string Password;
	string phnNumber;
	string address;

	cout << endl;
	cout << "请输入用户名(最大10位)：";
	cin.sync();
	getline(cin, Uname);
	if (size(Uname) > 10) {
		cout << "用户名超过长度！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//用户名不能重复
	//遍历搜索用户
	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		if (Uname == (*it)->username) {
			//失败，已存在用户名
			cout << "注册失败！！已存在用户名！！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}



	cout << "请输入设置密码(最大20位)：";
	cin.sync();
	getline(cin, Password);
	if (size(Password) > 20) {
		cout << "密码超过长度！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入手机号(最多20个数字)：";
	cin.sync();
	getline(cin, phnNumber);
	if (!isNumber(phnNumber)) {
		cout << "不是数字！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//判断是否为整数,先找到小数点，再进行长度相减
	int k = 0;
	for (k; k < phnNumber.length(); k++) {
		if (phnNumber[k] == '.') break;
	}
	if (phnNumber.length() != k) {
		cout << "输入数量不是整数！！发布失败！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (size(phnNumber) > 20) {
		cout << "手机号超过长度！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入地址(最多40个字)：";
	cin.sync();
	getline(cin, address);
	if (size(address) > 40) {
		cout << "地址超过长度！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "确定注册？(Y/其它) ";
	string judge;
	cin.sync();
	getline(cin, judge);
	if (judge != "Y") {
		cout << "放弃注册！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	////开辟新空间，利用动态数组，元素类型为User类的指针 (usernumb暂时还没+1）
	//User** newUArray = new User * [m_Admin.numbUser+1];

	////将原来空间下的数据拷贝到新空间下
	////先做判断，有数据就往里面放
	//if (m_Admin.userArray != NULL) {
	//	for (int i = 0; i < m_Admin.numbUser; ++i) {
	//		newUArray[i] = m_Admin.userArray[i];
	//	}
	//}

	////创建新的用户对象
	//User* n_User = new User(UIDback(m_Admin.numbUser + 1), Uname, Password, phnNumber, address, 0.0, 1);

	////放进去
	//newUArray[m_Admin.numbUser] = n_User;

	////释放原有空间
	//delete[] m_Admin.userArray;
	////更改新空间的指向
	//m_Admin.userArray = newUArray;
	////更新用户人数
	//m_Admin.numbUser++;

	//创建新的用户对象
	User* n_User = new User(UIDback(m_Admin.numbUser + 1), Uname, Password, phnNumber, address, 0.0, 1);

	//确定注册，直接往userVec里面push新用户类指针
	m_Admin.userVec.push_back(n_User);

	//更新用户人数
	m_Admin.numbUser++;



	//成功添加后，保存到文件中
	this->saveFILE(m_Admin);



	cout << "注册成功！！" << endl;
	system("pause");
	system("cls");
};

void Platform::UserLogin(Admin& m_Admin) {

	cout << endl;
	//创建新用户指针，后指向用户数据
	User* n_user;

	string U_Name, U_key;
	cout << "请输入用户名：";
	cin.sync();
	getline(cin, U_Name);
	cout << "请输入密码：";
	cin.sync();
	//getline(cin, U_key);

	//输入密码回显*
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
			if (U_key.length() == 0)		//如果第一个键为退格键
			{
				cout << "密码为空,请输入密码：";
				continue;
			}
			cout << "\b \b";
			i++;							//清除所要删掉的字符
			U_key[U_key.length() - i] = '\0';

		}
		else
		{
			U_key += a;
			cout << "*";
		}

	}
	cin.sync();
	cout << endl;


	int flag = 0;
	string judgeUN, judgeUK;

	//遍历搜索用户
	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		judgeUN = (*it)->username;
		judgeUK = (*it)->password;
		//找到用户
		if (U_Name == judgeUN && U_key == judgeUK) {
			n_user = (*it);
			//如果用户为封禁状态，则登录失败
			if (n_user->userState == 0) {
				cout << "登录失败！！用户已被封禁！！" << endl;
				system("pause");
				system("cls");
				return;
			}
			flag = 1;
			cout << "成功登录！" << endl;
			system("pause");
			break;
		}
	}

	//如果成功了,switch!!
	if (flag) {
		//先进行清屏，然后用户菜单展示
		system("cls");
		//用来储存用户选项
		string choiceuu;
		bool judge = true;

		while (judge) {

			n_user->showUSERMenu();
			cout << "输入选项：";
			cin.sync();
			getline(cin, choiceuu);

			if (size(choiceuu) > 1) {
				cout << "输入有误！请重新输入!!" << endl;
				system("pause");
				system("cls");
				continue;
			}

			switch (choiceuu[0])
			{
			case '1':	//我是买家
				n_user->Module_BUYER(m_Admin.numbGoods, m_Admin.numbOrder, m_Admin.userVec, m_Admin.goodsVec, m_Admin.orderVec);
				break;
			case '2':	//我是卖家
				//引用传参
				n_user->Module_SELLER(m_Admin.numbGoods, m_Admin.goodsVec, m_Admin.orderVec);
				break;
			case '3':	//个人信息管理
				//传值传参，不怕原vector修改
				n_user->infoManageUSER(m_Admin.userVec, m_Admin.orderVec);
				//保存数据
				this->saveFILE(m_Admin);
				break;
			case '4': //聊天室
				ChatBox(n_user->username);
				break;
			case '5':	//退出登录
				n_user->exitUSER();
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
	else {
		cout << "登录失败！请检查用户名或密码是否正确！" << endl;
		system("pause");
		system("cls");
	}
};


/*************协助性函数****************************************/
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

	ofs << "用户ID,用户名,密码,联系方式,地址,钱包余额,用户状态" << endl;

	//用户vec写入
	for (vector<User*>::iterator it = m_Admin.userVec.begin(); it != m_Admin.userVec.end(); it++) {
		ofs << (*it)->userID << ","
			<< (*it)->username << ","
			<< (*it)->password << ","
			<< (*it)->phoneNumber << ","
			<< (*it)->address << ","
			<< (*it)->balance << ",";	//double转string
		if ((*it)->userState == 1) {
			ofs << "正常" << endl;
		}
		else {
			ofs << "封禁" << endl;
		}

	}
	ofs.close();
};

