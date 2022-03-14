#include"Order.h"

Order::Order(vector<string> vcstr) {
	//����ID,��ƷID,���׵���,����,����ʱ��,����ID,���ID
	//T001, M001, 10.0, 10, 2022 - 02 - 15, U001, U002
	int i = 0;
	for (i; i < 7; ++i) {
		switch (i)
		{
		case 0:
			orderID = vcstr.at(i);
			break;
		case 1:
			commodityID = vcstr.at(i);
			break;
		case 2:
			unitPrice = vcstr.at(i);
			break;
		case 3:
			number = vcstr.at(i);
			break;
		case 4:
			date = vcstr.at(i);
			break;
		case 5:
			sellerID = vcstr.at(i);
			break;
		case 6:
			buyerID = vcstr.at(i);
			break;
		default:
			break;
		}

	}
}