#include"Goods.h"

Goods::Goods(string cID, string cName, string prc, string numb, string descr, string sID, string addD, string sta) {
	commodityID = cID;
	commodityName = cName;
	price = prc;
	number = numb;
	description = descr;
	sellerID = sID;
	addedDate = addD;
	state = sta;
}

Goods::Goods(vector<string> vcstr) {
	//商品ID,名称,价格,数量,描述,卖家ID,上架时间,商品状态
	//M001,冰敦敦,100.0,10,2022冬奥吉祥物,U001,2022-02-15,销售中
	int i = 0;
	for (i; i < 8; ++i) {
		switch (i)
		{
		case 0:
			commodityID = vcstr.at(i);
			break;
		case 1:
			commodityName = vcstr.at(i);
			break;
		case 2:
			price = vcstr.at(i);
			break;
		case 3:
			number = vcstr.at(i);
			break;
		case 4:
			description = vcstr.at(i);
			break;
		case 5:
			sellerID = vcstr.at(i);
			break;
		case 6:
			addedDate = vcstr.at(i);
			break;
		case 7:
			state = vcstr.at(i);
			break;
		default:
			break;
		}

	}

}