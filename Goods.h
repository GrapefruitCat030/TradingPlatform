#pragma once
#include<string>
#include<vector>
using namespace std;

class Goods {

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
public:
	Goods();
	Goods(vector<string> strvc);
};