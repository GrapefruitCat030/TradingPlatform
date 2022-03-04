#pragma once

class Order {
	//订单ID
	char orderID[5];
	//商品ID
	char commodityID[5];
	//交易单价
	double unitPrice;
	//数量
	int number;
	//交易时间
	char date[13];
	//卖家ID
	char sellerID[5];
	//买家ID
	char buyerID[5];
};