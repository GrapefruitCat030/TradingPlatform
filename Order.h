#pragma once
using namespace std;
#include<string>
#include<vector>

class Order {
public:
	//订单ID
	string orderID;
	//商品ID
	string commodityID;
	//交易单价
	string unitPrice;
	//数量
	string number;
	//交易时间
	string date;
	//卖家ID
	string sellerID;
	//买家ID
	string buyerID;

	//初始化
	Order(vector<string> strvc);
	Order(string ordID, string gID, string price, string numb, string theTime, string seID, string buyID);

};