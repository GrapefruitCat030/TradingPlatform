#include"SQL.h"

//要注意，生成用来储存的语句分两段，后段用来返回解析

//查看所有(可购买的/发布的)商品(AD,B,S)
string SQLshow_goods(int i,string ID) {
	string front = backTime();
	string behind;
	switch (i)
	{
	case ADMIN: {
		behind = "SELECT * FROM commodity";
	}
		break;
	case BUYER: {
		behind = "SELECT * FROM commodity WHERE 商品状态 CONTAINS 销售中";
	}
		break;
	case SELLER: {
		behind = "SELECT * FROM commodity WHERE 卖家ID CONTAINS "+ ID;
	}
		break;
	default:
		break;
	}
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//搜索(可购买的)商品(AD,B)
string SQLsearch_goods(int i, string Name) {
	string front = backTime();
	string behind;

	switch (i)
	{
	case ADMIN: {
		behind = "SELECT * FROM commodity WHERE 名称 CONTAINS " + Name;
	}
		break;
	case BUYER: {
		behind = "SELECT * FROM commodity WHERE 名称 CONTAINS " + Name;
	}
		break;
	default:
		break;
	}

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//下架商品(AD,S)
string SQLremove_goods(int i, string ID) {
	string front = backTime();
	string behind;

	switch (i)
	{
	case ADMIN: {
		behind = "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = " + ID;
	}
			  break;
	case SELLER: {
		behind = "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = " + ID;
	}
			   break;
	default:
		break;
	}


	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//查看所有订单(AD,B,S)
string SQLshow_order(int i, string ID) {
	string front = backTime();
	string behind;
	switch (i)
	{
	case ADMIN: {
		behind = "SELECT * FROM order";
	}
			  break;
	case BUYER: {
		behind = "SELECT * FROM order WHERE 买家ID CONTAINS " + ID;
	}
			  break;
	case SELLER: {
		behind = "SELECT * FROM order WHERE 卖家ID CONTAINS " + ID;
	}
			   break;
	default:
		break;
	}
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//查看所有用户
string SQLshow_user() {
	string front = backTime();
	string behind = "SELECT * FROM user";

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//封禁用户
string SQLban_userGOOD(string ID) {
	string front = backTime();
	string behind = "UPDATE commodity SET 商品状态 = 已下架 WHERE 卖家ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}
string SQLban_userUSER(string ID) {
	string front = backTime();
	string behind = "UPDATE user SET 用户状态 = 封禁 WHERE 用户ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}


//--------------buyer额外

//购买商品
string SQLbuy_goodsOrder(string TID, string MID, string price, string numb, string TIME, string SID, string BID) {
	string front = backTime();
	string behind;

	behind = "INSERT INTO order VALUES (" +TID + "," + MID + "," + price + "," + numb + "," + TIME + "," + SID + "," + BID + ")";

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}
string SQLbuy_goodsGoods(string MID, string numb) {
	string front = backTime();
	string behind;

	behind = "UPDATE commodity SET 数量 = " + numb + " WHERE 商品ID = " + MID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}


//商品自动下架
string SQLnone_goods(string ID) {
	string front = backTime();
	string behind;
	behind = "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID = " + ID;
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//查看商品详细信息
string SQLdetail_goods() {
	string front = backTime();
	string behind;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//-------------seller额外

//发布商品
string SQLpublish_goods(string Gname, string Gprice, string Gnumb, string Gdescr) {
	string front = backTime();
	string behind;

	behind = "INSERT INTO commodity VALUES (" + Gname + "," + "," + Gprice + "," + Gnumb + "," + Gdescr + ")";

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//修改商品信息
string SQLmodify_goodsPrice(string Gprice, string ID) {
	string front = backTime();
	string behind;

	behind = "UPDATE commodity SET 价格 = " + Gprice + " WHERE 商品ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}
string SQLmodify_goodsDescr(string Gdescr, string ID) {
	string front = backTime();
	string behind;

	behind = "UPDATE commodity SET 描述 = " + Gdescr + " WHERE 商品ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//返回系统时间
string backTime() {

	/////////////////////获取时间
	struct tm* tm_ptr;
	time_t the_time;
	(void)time(&the_time);
	tm_ptr = gmtime(&the_time);
	int year = tm_ptr->tm_year + 1900;
	int month = tm_ptr->tm_mon + 1;
	int day = tm_ptr->tm_mday;
	int hour = tm_ptr->tm_hour;
	int minute = tm_ptr->tm_min;
	int second = tm_ptr->tm_sec;
	string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day)\
		+ " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second) + ": ";
	/////////////////////////////////


	return theTime;
}

void SQLsaveFile(string command) {
	//以写入和追加方式打开文件
	ofstream ofs("commands.txt", ios::out | ios::app);

	//无文件，进行创建
	if (!ofs.is_open()) {
		cout << "现在创建SQLcommand文件";
	}
	ifstream ifs("commands.txt", ios::in);
	char ch;
	if (!ifs.get(ch)) {
		ofs << command << endl;
	}
	else {
		ofs << endl << command << endl;
	}

	//关闭文件
	ofs.close();
	ifs.close();
}


//解析功能
void analySQL(string SQLSTR) {}
