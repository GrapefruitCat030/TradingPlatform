#pragma once
using namespace std;
#include<string>
#include<vector>

class Order {
public:
	//����ID
	string orderID;
	//��ƷID
	string commodityID;
	//���׵���
	string unitPrice;
	//����
	string number;
	//����ʱ��
	string date;
	//����ID
	string sellerID;
	//���ID
	string buyerID;


	//��ʼ��
	Order(vector<string> strvc);
	Order(string ordID, string gID, string price, string numb,string theTime, string seID, string buyID);

};