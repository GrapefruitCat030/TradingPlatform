#pragma once
using namespace std;
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iomanip>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

enum USER { NONE, ADMIN, BUYER, SELLER };//0,1,2,3

//��ȡ��ǰϵͳʱ�� yyyy-mm-dddd hh:mm:ss
string backTime();

//---------------------------����

//�鿴����(�ɹ����/������)��Ʒ(AD,B,S)
string SQLshow_goods(int i, string ID);

//����(�ɹ����)��Ʒ(AD,B)
string SQLsearch_goods(int i, string Name);

//�¼���Ʒ(AD,S)
string SQLremove_goods(int i, string ID);

//�鿴���ж���(AD,B,S)
string SQLshow_order(int i, string ID);

//�鿴�����û�
string SQLshow_user();

//����û�
string SQLban_userGOOD(string ID);
string SQLban_userUSER(string ID);

//--------------buyer����

//������Ʒ
string SQLbuy_goodsOrder(string TID, string MID, string price, string numb, string TIME, string SID, string BID);
string SQLbuy_goodsGoods(string MID, string numb);


//�鿴��Ʒ��ϸ��Ϣ
string SQLdetail_goods();

//-------------seller����

//������Ʒ
string SQLpublish_goods(string Gname, string Gprice, string Gnumb, string Gdescr);
//��Ʒ�Զ��¼�
string SQLnone_goods(string ID);

//�޸���Ʒ��Ϣ
string SQLmodify_goodsPrice(string Gprice, string ID);
string SQLmodify_goodsDescr(string Gdescr, string ID);


//��������
void analySQL(string SQLSTR);
//ָ���ļ�����
void SQLsaveFile(string command);