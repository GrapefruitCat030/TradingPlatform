#pragma once
using namespace std;
#include<string>
#include<vector>


class Goods {
public:
	//��ƷID
	string commodityID;
	//����
	string commodityName;
	//�۸�(��Ҫʱ�ٽ���ת��)
	string price;
	//����(��Ҫʱ�ٽ���ת��)
	string number;
	//����
	string description;
	//����ID
	string sellerID;
	//�ϼ�ʱ��
	string addedDate;
	//��Ʒ״̬�������� || ���¼�
	string state;

	Goods();
	Goods(string cID, string cName, string prc, string numb, \
		string descr, string sID, string addD, string sta);
	Goods(vector<string> strvc);
};