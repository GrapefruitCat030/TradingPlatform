#include"Goods.h"

Goods::Goods(vector<string> vcstr) {
	//��ƷID,����,�۸�,����,����,����ID,�ϼ�ʱ��,��Ʒ״̬
	//M001,���ض�,100.0,10,2022���¼�����,U001,2022-02-15,������
	//string string double int str str str str
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