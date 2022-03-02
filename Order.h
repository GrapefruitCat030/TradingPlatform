#pragma once

class Order {
	//订单ID
	char orderID[4];
	//商品ID
	char commodityID[4];
	//交易单价
	double unitPrice;
	//数量
	int number;
	//交易时间
	char date[13];
	//卖家ID
	char sellerID[4];
	//买家ID
	char buyerID[4];
};