#include"Admin.h"

Admin::Admin() {};

Admin::~Admin() {};

void Admin::show_Menu() {
	cout << "-----�����ڴ��ڹ���Աģʽ-----" << endl;
	cout << "====================================================================" << endl;
	cout << "  1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" << endl;
	cout << "===================================================================" << endl;

}

void Admin::exitAD() {
	cout << "��ӭ�´�ʹ�ã���" << endl;
	system("pause");
	return;
}

void Admin::Goods_show() {};

void Admin::searchGoods() {};

void Admin::removeGoods() {};

void Admin::Order_show() {};

void Admin::User_show() {};

void Admin::banUser() {};

void Admin::Module_Admin() {
	//�Ƚ���������Ȼ�����Ա�˵�չʾ
	system("cls");

	//���������û�ѡ��
	int choice = 0;
	bool judge = true;

	while (judge) {

		this->show_Menu();
		cout << "����ѡ�";
		cin >> choice;

		switch (choice)
		{
		case 1:	//�鿴������Ʒ
			this->Goods_show();
			break;
		case 2:	//������Ʒ
			this->searchGoods();
			break;
		case 3:	//�¼���Ʒ
			this->removeGoods();
			break;
		case 4:	//�鿴���ж���
			this->Order_show();
			break;
		case 5:	//�鿴�����û�
			this->User_show();
			break;
		case 6:	//����û�
			this->banUser();
			break;
		case 7:	//ע��
			this->exitAD();
			judge = false;
			system("cls");
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	return;

}