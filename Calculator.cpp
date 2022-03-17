#include"Calculator.h"


bool CisNumber(const string& str) {
	istringstream sin(str);
	double test;
	return sin >> test && sin.eof();
}

bool judgecin(const string& kksk) {
	//全区域判断(特殊字符)
	for (int i = 0; i < kksk.size(); i++) {
		if (!(kksk[i] == '+' || kksk[i] == '-' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == '.' || \
			kksk[i] == ' ' || kksk[i] == '(' || kksk[i] == ')' || isdigit(kksk[i]))) {
			cout << "含有特殊字符！！" << endl;
			return false;
		}

	}

	//括号判断
	int lefpa = 0, rigpa = 0;
	int p = 0;
	while (p < kksk.length()) {
		if (kksk[p] == '(') lefpa++;
		if (kksk[p] == ')')rigpa++;
		p++;
	}
	p = 0;
	if (lefpa != rigpa) {
		cout << "括号数量错误！！" << endl;
		return false;
	}


	//小数点前后数字判断
	if (kksk[0] == '.') {
		cout << "小数点使用错误！" << endl;
		return false;
	}
	if (kksk[kksk.length() - 1] == '.') {
		cout << "小数点使用错误！" << endl;
		return false;
	}
	//两位小数输入错误判断
	for (int k = 0; k <= kksk.length() - 1; k++) {
		if (kksk[k] == '.' && k + 2 <= kksk.length() - 1) {
			if (isdigit(kksk[k + 1]) && isdigit(kksk[k + 2])) {
				cout << "只能为一位小数！" << endl;
				return false;
			}
			if (isdigit(kksk[k + 1]) && kksk[k + 2] == '.') {
				cout << "小数点误用！" << endl;
				return false;
			}

		}
	}
	for (int k = 0; k <= kksk.length() - 1; k++) {
		//防止下标溢出
		if (k + 1 <= kksk.length() - 2) {
			if (kksk[k + 1] == '.') {
				if (!isdigit(kksk[k])) {
					cout << "小数点使用错误！" << endl;
					return false;
				}
				if (!isdigit(kksk[k + 2])) {
					cout << "小数点使用错误！" << endl;
					return false;
				}
			}
		}

	}

	////使用字符串流判断操作符与操作数数量是否相等
	//stringstream jud_bySpace(kksk);
	//vector<string> jbS;
	//string s;
	//while (getline(jud_bySpace,s,' ')) {
	//	jbS.push_back(s);
	//}
	//int numNumb = 0, opeRand = 0;
	//for (int i = 0; i < jbS.size(); i++) {
	//	if (isNumber(jbS[i])) numNumb++;
	//	if (jbS[i] == "+");
	//}


	//运算符使用判断
	if (kksk[0] == '+' || kksk[0] == '*' || kksk[0] == '/') {
		cout << "操作符使用错误！首项不能为除减号外的操作符！" << endl;
		return false;
	}
	if (kksk[kksk.length() - 1] == '+' || kksk[kksk.length() - 1] == '*' || kksk[kksk.length() - 1] == '/' || kksk[kksk.length() - 1] == '-') {
		cout << "操作符使用错误！尾项不能为操作符！" << endl;
		return false;
	}
	for (int s = 0; s <= kksk.length() - 1; s++) {
		//当前s为数字
		if (isdigit(kksk[s])) {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '(') {
					cout << "数字不能和括号贴合！" << endl;
					return false;
				}
				else if (isdigit(kksk[i]) && spaceFlag) {
					cout << "数字不能和数字隔着空格贴合！" << endl;
					return false;
				}
				else {
					if (kksk[i] == ' ') {
						spaceFlag = true;
						continue;
					}
					else if (kksk[i] == '+' || kksk[i] == '-' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == ')')
						break;
				}
			}
		}

		//当前s为(
		else if (kksk[s] == '(') {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '+' || kksk[i] == '*' || kksk[i] == '/') {
					cout << "左括号不能直接跟操作符！" << endl;
					return false;
				}
				else if (kksk[i] == ')') {
					cout << "左括号不能直接跟右括号！" << endl;
					return false;
				}

				else {
					if (kksk[i] == ' ') {
						spaceFlag = true;
						continue;
					}
					else if (kksk[i] == '-' || isdigit(kksk[i]) || kksk[s] == '(')
						break;
				}
			}
		}

		//当前s为)
		else if (kksk[s] == ')') {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (isdigit(kksk[i])) {
					cout << "空格使用错误！右括号不能直接跟数字！" << endl;
					return false;
				}
				else {
					if (kksk[i] == ' ') {
						spaceFlag = true;
						continue;
					}
					else if (kksk[i] == '-' || kksk[i] == '+' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == ')')
						break;
				}
			}
		}

		//当前s为 . || ' ' 
		else if (kksk[s] == '.' || kksk[s] == ' ') {
			continue;
		}

		//当前s为操作符
		else if (kksk[s] == '+' || kksk[s] == '-' || kksk[s] == '*' || kksk[s] == '/') {

			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '+' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == '-') {
					cout << "操作符不能直接跟操作符！" << endl;
					return false;
				}
				else if (kksk[i] == ')') {
					cout << "操作符不能直接跟右括号！" << endl;
					return false;
				}
				else {
					if (kksk[i] == ' ') {
						spaceFlag = true;
						continue;
					}
					else if (isdigit(kksk[i]) || kksk[i] == '(')
						break;
				}
			}

		}

	}


	return true;
}

void transform(vector<string>& stk, string str) {

	str += " ";

	stack<char> MMstk;

	//用以读取整个数字的开始下标
	int flag = 0;
	string temp;

	int i = 0;
	while (i < str.length()) {

		//为空格
		if (str[i] == ' ') {
			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				i++;
				flag = i;
				continue;
			}
			i++;
			flag = i;
			continue;
		}

		//为左括号，入栈
		else if (str[i] == '(') {
			MMstk.push(str[i]);
		}


		//如果ch是操作符
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			//减号前一位为左括号
			if (i - 1 >= 0 && (str[i - 1] == '(') && str[i] == '-') {
				stk.push_back("0");
			}

			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				flag = i;
			}
			while (true) {
				// (a) 栈为空或栈顶元素为左圆括号
				if (MMstk.empty() || MMstk.top() == '(') {
					MMstk.push(str[i]);
					break;
				}
				// 按优先级判断入栈
				else if (MMstk.top() == '+' || MMstk.top() == '-' || MMstk.top() == '*' || MMstk.top() == '/') {
					//(b) 如果ch优先级比栈顶元素高，那么把ch入栈				
					//(c) ch优先级低于或者等于栈顶元素,把栈顶元素出栈并输出之，转（a）

					if (MMstk.top() == '*' || MMstk.top() == '/') {
						char theTop = MMstk.top();
						MMstk.pop();
						string s(1, theTop);
						stk.push_back(s);
						continue;
					}


					else if (MMstk.top() == '+' || MMstk.top() == '-') {
						if (str[i] == '-' || str[i] == '+') {
							char theTop = MMstk.top();
							MMstk.pop();
							string s(1, theTop);
							stk.push_back(s);
							continue;
						}
						else if (str[i] == '*' || str[i] == '/' || str[i] == '+') {
							MMstk.push(str[i]);
							break;
						}

					}
				}

				else
					break;
			}
		}
		//为右圆括号
		else if (str[i] == ')') {
			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				flag = i;
			}
			while (!MMstk.empty())
			{
				if (MMstk.top() == '(') {
					//'('出栈
					MMstk.pop();
					break;
				}
				char theTop = MMstk.top();
				MMstk.pop();
				string s(1, theTop);
				stk.push_back(s);

			}
			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				i++;
				flag = i;
				continue;
			}
		}



		//将浮点数存好(遇到数字和.)
		else {
			i++;
			continue;
		}


		i++;
		flag = i;
	}

	while (!MMstk.empty())
	{
		char theTop = MMstk.top();
		MMstk.pop();
		string s(1, theTop);
		stk.push_back(s);
	}
}

double calcalcal(vector<string> vcstr) {

	vector<string> cpyvc = vcstr;
	//储存操作数
	stack<double> ssk;

	int i = 0;
	while (i != cpyvc.size()) {
		if (cpyvc[i] == "+" || cpyvc[i] == "-" || cpyvc[i] == "*" || cpyvc[i] == "/") {
			//是操作符, 从栈里取出两个数进行运算，结果再进行入栈
			double n1 = ssk.top();
			ssk.pop();
			//双目操作
			if (!ssk.empty()) {
				double n2 = ssk.top();
				ssk.pop();

				if (cpyvc[i] == "+") {
					double rel = n1 + n2;
					ssk.push(rel);
				}

				else if (cpyvc[i] == "-") {
					double rel = n2 - n1;
					ssk.push(rel);
				}
				else if (cpyvc[i] == "*") {
					double rel = n1 * n2;
					ssk.push(rel);
				}
				else if (cpyvc[i] == "/") {
					double rel = n2 / n1;
					ssk.push(rel);
				}
			}
			//单目操作
			else {
				double n2 = 0.0;
				if (cpyvc[i] == "-") {
					double rel = n2 - n1;
					ssk.push(rel);
				}
				else
					cout << "wrong, its not '-' ";
			}
		}
		//是数字的话就入栈(浮点数)
		else {
			ssk.push(stod(cpyvc[i]));
		}

		i++;
	}
	return ssk.top();
}

double useCal(string str) {
	double rel = 0.0;
	vector<string> stk;
	if (judgecin(str)) {

		transform(stk, str);
		rel = calcalcal(stk);
		return rel;
	}
	return 0.0;
}