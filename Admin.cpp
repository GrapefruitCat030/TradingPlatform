#include"Admin.h"

Admin::Admin() {

	numbUser = 0;

	userArray = NULL;
	orderArray = NULL;
	goodsArray = NULL;
};

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
	system("cls");
	return;
}

void Admin::Goods_show() {};

void Admin::searchGoods() {};

void Admin::removeGoods() {};

void Admin::Order_show() {};

void Admin::User_show() {
	cout << "�û�ID" << "\t" << "����" << "\t" << "����" <<"\t" 
		<<"�ֻ���" << "\t" <<"��ַ" << endl;
	if (!this->numbUser) {
		cout << "----------���û�����-----------" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->numbUser; i++) {
		cout << this->userArray[i]->userID << "\t";
		cout << this->userArray[i]->username << "\t";
		cout << this->userArray[i]->password << "\t";
		cout << this->userArray[i]->phoneNumber << "\t";
		cout << this->userArray[i]->address;
		cout << endl;
	}
	system("pause");
	system("cls");

};

void Admin::banUser() {};

void Admin::Module_Admin() {
	//�Ƚ���������Ȼ�����Ա�˵�չʾ
	system("cls");
	//���������û�ѡ��
	char choicecc[100] = { 0 };
	bool judge = true;

	while (judge) {

		this->show_Menu();
		cout << "����ѡ�";
		cin >> choicecc;
		//if (cin >> choicecc) {

		//}
		//else {
		//	cin.clear();
		//}
		if (strlen(choicecc) > 1) {
			cout << "������������������!!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		//char kksk = choicecc[0];
		switch (choicecc[0])
		{
		case '1':	//�鿴������Ʒ
			this->Goods_show();
			break;
		case '2':	//������Ʒ
			this->searchGoods();
			break;
		case '3':	//�¼���Ʒ
			this->removeGoods();
			break;
		case '4':	//�鿴���ж���
			this->Order_show();
			break;
		case '5':	//�鿴�����û�
			this->User_show();
			break;
		case '6':	//����û�
			this->banUser();
			break;
		case '7':	//ע��
			this->exitAD();
			judge = false;
			break;
		default:
			cout << "������������������!!" << endl;
			system("pause");
			system("cls"); //����
			break;
		}
	}
}