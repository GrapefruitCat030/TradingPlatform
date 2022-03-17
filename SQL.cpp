#include"SQL.h"

//Ҫע�⣬��������������������Σ�����������ؽ���

//�鿴����(�ɹ����/������)��Ʒ(AD,B,S)
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
		behind = "SELECT * FROM commodity WHERE ��Ʒ״̬ CONTAINS ������";
	}
		break;
	case SELLER: {
		behind = "SELECT * FROM commodity WHERE ����ID CONTAINS "+ ID;
	}
		break;
	default:
		break;
	}
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//����(�ɹ����)��Ʒ(AD,B)
string SQLsearch_goods(int i, string Name) {
	string front = backTime();
	string behind;

	switch (i)
	{
	case ADMIN: {
		behind = "SELECT * FROM commodity WHERE ���� CONTAINS " + Name;
	}
		break;
	case BUYER: {
		behind = "SELECT * FROM commodity WHERE ���� CONTAINS " + Name;
	}
		break;
	default:
		break;
	}

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//�¼���Ʒ(AD,S)
string SQLremove_goods(int i, string ID) {
	string front = backTime();
	string behind;

	switch (i)
	{
	case ADMIN: {
		behind = "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ��ƷID = " + ID;
	}
			  break;
	case SELLER: {
		behind = "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ��ƷID = " + ID;
	}
			   break;
	default:
		break;
	}


	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//�鿴���ж���(AD,B,S)
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
		behind = "SELECT * FROM order WHERE ���ID CONTAINS " + ID;
	}
			  break;
	case SELLER: {
		behind = "SELECT * FROM order WHERE ����ID CONTAINS " + ID;
	}
			   break;
	default:
		break;
	}
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//�鿴�����û�
string SQLshow_user() {
	string front = backTime();
	string behind = "SELECT * FROM user";

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//����û�
string SQLban_userGOOD(string ID) {
	string front = backTime();
	string behind = "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ����ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}
string SQLban_userUSER(string ID) {
	string front = backTime();
	string behind = "UPDATE user SET �û�״̬ = ��� WHERE �û�ID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}


//--------------buyer����

//������Ʒ
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

	behind = "UPDATE commodity SET ���� = " + numb + " WHERE ��ƷID = " + MID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}


//��Ʒ�Զ��¼�
string SQLnone_goods(string ID) {
	string front = backTime();
	string behind;
	behind = "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ��ƷID = " + ID;
	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//�鿴��Ʒ��ϸ��Ϣ
string SQLdetail_goods() {
	string front = backTime();
	string behind;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//-------------seller����

//������Ʒ
string SQLpublish_goods(string Gname, string Gprice, string Gnumb, string Gdescr) {
	string front = backTime();
	string behind;

	behind = "INSERT INTO commodity VALUES (" + Gname + "," + "," + Gprice + "," + Gnumb + "," + Gdescr + ")";

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}

//�޸���Ʒ��Ϣ
string SQLmodify_goodsPrice(string Gprice, string ID) {
	string front = backTime();
	string behind;

	behind = "UPDATE commodity SET �۸� = " + Gprice + " WHERE ��ƷID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;

}
string SQLmodify_goodsDescr(string Gdescr, string ID) {
	string front = backTime();
	string behind;

	behind = "UPDATE commodity SET ���� = " + Gdescr + " WHERE ��ƷID = " + ID;

	string result = front + behind;
	SQLsaveFile(result);

	return behind;
}

//����ϵͳʱ��
string backTime() {

	/////////////////////��ȡʱ��
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
	//��д���׷�ӷ�ʽ���ļ�
	ofstream ofs("commands.txt", ios::out | ios::app);

	//���ļ������д���
	if (!ofs.is_open()) {
		cout << "���ڴ���SQLcommand�ļ�";
	}
	ifstream ifs("commands.txt", ios::in);
	char ch;
	if (!ifs.get(ch)) {
		ofs << command << endl;
	}
	else {
		ofs << endl << command << endl;
	}

	//�ر��ļ�
	ofs.close();
	ifs.close();
}


//��������
void analySQL(string SQLSTR) {}
