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
	//��ƷID,����,�۸�,����,����,����ID,�ϼ�ʱ��,��Ʒ״̬
	//M001,���ض�,100.0,10,2022���¼�����,U001,2022-02-15,������
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