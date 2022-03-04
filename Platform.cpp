#include<string>
#include<string.h>
#include"Platform.h"



Platform::Platform() {};

Platform::~Platform() {};

void Platform::show_Menu() {
	cout << "===============================================================" << endl;
	cout << "  1.管理员登录	 2.用户注册	3.用户登录	4.退出系统" << endl;
	cout << "===============================================================" << endl;
}

void Platform::exitPlatform() {
	cout << "欢迎下次使用！！" << endl;
	system("pause");
	exit(0);
}

void Platform::AdminLogin(Admin& m_Admin) {

	string A_Name, A_key;
	cout << "请输入管理员姓名：";
	cin >> A_Name;
	cout << "请输入密码：";
	cin >> A_key;

	
	//登录失败则清屏返回主菜单
	if (A_Name!=ADNAME || A_key != ADKEY) {
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
	char Uname[11] = { 0 };
	char Password[21] = { 0 };
	char phnNumber[21] = { 0 };
	char address[41] = { 0 };
	cout << "请输入用户名：";
	cin >> Uname;
	cout << "请输入设置密码：";
	cin >> Password;
	cout << "请输入手机号：";
	cin >> phnNumber;
	cout << "请输入地址：";
	cin >> address;


	//开辟新空间，利用动态数组，元素类型为User类的指针 (usernumb暂时还没+1）
	User** newUArray = new User * [m_Admin.numbUser+1];

	//将原来空间下的数据拷贝到新空间下
	//先做判断，有数据就往里面放
	if (m_Admin.userArray != NULL) {
		for (int i = 0; i < m_Admin.numbUser; ++i) {
			newUArray[i] = m_Admin.userArray[i];
		}
	}

	//创建新的用户对象
	User* n_User = new User;
	//char* the_cpy = UIDback(m_Admin.numbUser + 1);
	strcpy(n_User->userID, UIDback(m_Admin.numbUser + 1));
	//delete[] the_cpy;
	strcpy_s(n_User->username, Uname);
	strcpy_s(n_User->password, Password);
	strcpy_s(n_User->phoneNumber, phnNumber);
	strcpy_s(n_User->address, address);
	n_User->balance = 0.0;
	n_User->userState = 1;


	//放进去
	newUArray[m_Admin.numbUser] = n_User;

	//释放原有空间
	delete[] m_Admin.userArray;
	//更改新空间的指向
	m_Admin.userArray = newUArray;
	//更新新职工人数
	m_Admin.numbUser++;

	cout << "注册成功！！" << endl;
	system("pause");
	system("cls");
};

void Platform::UserLogin(Admin& m_Admin) {
	
	//test
	int kksk = 0;
	//如果成功了,switch!!
	if (kksk) {
		User* the_User = new User;

	}
	else {
		cout << "fail to login" << endl;
		system("pause");
		system("cls");
	}
};

char* UIDback(int i) {

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

	char* suki = new char[4];
	strcpy(suki, kksk.c_str());
	
	return suki;
}

