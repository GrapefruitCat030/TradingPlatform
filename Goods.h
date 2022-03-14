#pragma once
using namespace std;
#include<string>
#include<vector>


class Goods {
public:
	//商品ID
	string commodityID;
	//名称
	string commodityName;
	//价格(需要时再进行转换)
	string price;
	//数量(需要时再进行转换)
	string number;
	//描述
	string description;
	//卖家ID
	string sellerID;
	//上架时间
	string addedDate;
	//商品状态：销售中 || 已下架
	string state;

	Goods();
	Goods(string cID, string cName, string prc, string numb, \
		string descr, string sID, string addD, string sta);
	Goods(vector<string> strvc);
};