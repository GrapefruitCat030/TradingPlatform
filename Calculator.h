#pragma once

#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<vector>
#include<sstream>

//�ж�str�Ƿ�Ϊ����
bool CisNumber(const string& str);
//�ж�������ʽ
bool judgecin(const string& kksk);
//���б��ʽת��׺
void transform(vector<string>& stk, string str);
//���м���
double calcalcal(vector<string> vcstr);

//���ü������ӿ�
double useCal(string str);