#pragma once

class Goods {
	//商品ID
	char commodityID[5];
	//名称
	char commodityName[21];
	//价格
	double price;
	//数量
	int number;
	//描述
	char description[201];
	//卖家ID
	char sellerID[5];
	//上架时间
	char addedDate[13];
	//商品状态：0为已下架(removed)，1为销售中(onSale)
	int state;
};