#pragma once

#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<vector>
#include<sstream>

//判断str是否为数字
bool CisNumber(const string& str);
//判断输入表达式
bool judgecin(const string& kksk);
//进行表达式转后缀
void transform(vector<string>& stk, string str);
//进行计算
double calcalcal(vector<string> vcstr);

//调用计算器接口
double useCal(string str);