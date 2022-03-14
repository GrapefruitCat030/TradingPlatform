#pragma once
#include<string>
#include<vector>
using namespace std;

class Goods {

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
public:
	Goods();
	Goods(vector<string> strvc);
};