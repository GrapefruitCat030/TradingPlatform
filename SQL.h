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

//获取当前系统时间 yyyy-mm-dddd hh:mm:ss
string backTime();

//---------------------------界面

//查看所有(可购买的/发布的)商品(AD,B,S)
string SQLshow_goods(int i, string ID);

//搜索(可购买的)商品(AD,B)
string SQLsearch_goods(int i, string Name);

//下架商品(AD,S)
string SQLremove_goods(int i, string ID);

//查看所有订单(AD,B,S)
string SQLshow_order(int i, string ID);

//查看所有用户
string SQLshow_user();

//封禁用户
string SQLban_userGOOD(string ID);
string SQLban_userUSER(string ID);

//--------------buyer额外

//购买商品
string SQLbuy_goodsOrder(string TID, string MID, string price, string numb, string TIME, string SID, string BID);
string SQLbuy_goodsGoods(string MID, string numb);


//查看商品详细信息
string SQLdetail_goods();

//-------------seller额外

//发布商品
string SQLpublish_goods(string Gname, string Gprice, string Gnumb, string Gdescr);
//商品自动下架
string SQLnone_goods(string ID);

//修改商品信息
string SQLmodify_goodsPrice(string Gprice, string ID);
string SQLmodify_goodsDescr(string Gdescr, string ID);


//解析功能
void analySQL(string SQLSTR);
//指令文件保存
void SQLsaveFile(string command);