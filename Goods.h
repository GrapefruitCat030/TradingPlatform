#pragma once

class Goods {
	//��ƷID
	char commodityID[4];
	//����
	char commodityName[21];
	//�۸�
	double price;
	//����
	int number;
	//����
	char description[201];
	//����ID
	char sellerID[4];
	//�ϼ�ʱ��
	char addedDate[13];
	//��Ʒ״̬��0Ϊ���¼�(removed)��1Ϊ������(onSale)
	int state;
};