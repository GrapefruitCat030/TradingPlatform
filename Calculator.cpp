#include"Calculator.h"


bool CisNumber(const string& str) {
	istringstream sin(str);
	double test;
	return sin >> test && sin.eof();
}

bool judgecin(const string& kksk) {
	//ȫ�����ж�(�����ַ�)
	for (int i = 0; i < kksk.size(); i++) {
		if (!(kksk[i] == '+' || kksk[i] == '-' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == '.' || \
			kksk[i] == ' ' || kksk[i] == '(' || kksk[i] == ')' || isdigit(kksk[i]))) {
			cout << "���������ַ�����" << endl;
			return false;
		}

	}

	//�����ж�
	int lefpa = 0, rigpa = 0;
	int p = 0;
	while (p < kksk.length()) {
		if (kksk[p] == '(') lefpa++;
		if (kksk[p] == ')')rigpa++;
		p++;
	}
	p = 0;
	if (lefpa != rigpa) {
		cout << "�����������󣡣�" << endl;
		return false;
	}


	//С����ǰ�������ж�
	if (kksk[0] == '.') {
		cout << "С����ʹ�ô���" << endl;
		return false;
	}
	if (kksk[kksk.length() - 1] == '.') {
		cout << "С����ʹ�ô���" << endl;
		return false;
	}
	//��λС����������ж�
	for (int k = 0; k <= kksk.length() - 1; k++) {
		if (kksk[k] == '.' && k + 2 <= kksk.length() - 1) {
			if (isdigit(kksk[k + 1]) && isdigit(kksk[k + 2])) {
				cout << "ֻ��ΪһλС����" << endl;
				return false;
			}
			if (isdigit(kksk[k + 1]) && kksk[k + 2] == '.') {
				cout << "С�������ã�" << endl;
				return false;
			}

		}
	}
	for (int k = 0; k <= kksk.length() - 1; k++) {
		//��ֹ�±����
		if (k + 1 <= kksk.length() - 2) {
			if (kksk[k + 1] == '.') {
				if (!isdigit(kksk[k])) {
					cout << "С����ʹ�ô���" << endl;
					return false;
				}
				if (!isdigit(kksk[k + 2])) {
					cout << "С����ʹ�ô���" << endl;
					return false;
				}
			}
		}

	}

	////ʹ���ַ������жϲ�����������������Ƿ����
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


	//�����ʹ���ж�
	if (kksk[0] == '+' || kksk[0] == '*' || kksk[0] == '/') {
		cout << "������ʹ�ô��������Ϊ��������Ĳ�������" << endl;
		return false;
	}
	if (kksk[kksk.length() - 1] == '+' || kksk[kksk.length() - 1] == '*' || kksk[kksk.length() - 1] == '/' || kksk[kksk.length() - 1] == '-') {
		cout << "������ʹ�ô���β���Ϊ��������" << endl;
		return false;
	}
	for (int s = 0; s <= kksk.length() - 1; s++) {
		//��ǰsΪ����
		if (isdigit(kksk[s])) {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '(') {
					cout << "���ֲ��ܺ��������ϣ�" << endl;
					return false;
				}
				else if (isdigit(kksk[i]) && spaceFlag) {
					cout << "���ֲ��ܺ����ָ��ſո����ϣ�" << endl;
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

		//��ǰsΪ(
		else if (kksk[s] == '(') {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '+' || kksk[i] == '*' || kksk[i] == '/') {
					cout << "�����Ų���ֱ�Ӹ���������" << endl;
					return false;
				}
				else if (kksk[i] == ')') {
					cout << "�����Ų���ֱ�Ӹ������ţ�" << endl;
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

		//��ǰsΪ)
		else if (kksk[s] == ')') {
			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (isdigit(kksk[i])) {
					cout << "�ո�ʹ�ô��������Ų���ֱ�Ӹ����֣�" << endl;
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

		//��ǰsΪ . || ' ' 
		else if (kksk[s] == '.' || kksk[s] == ' ') {
			continue;
		}

		//��ǰsΪ������
		else if (kksk[s] == '+' || kksk[s] == '-' || kksk[s] == '*' || kksk[s] == '/') {

			bool spaceFlag = false;
			for (int i = s + 1; i <= kksk.length() - 1; i++) {
				if (kksk[i] == '+' || kksk[i] == '*' || kksk[i] == '/' || kksk[i] == '-') {
					cout << "����������ֱ�Ӹ���������" << endl;
					return false;
				}
				else if (kksk[i] == ')') {
					cout << "����������ֱ�Ӹ������ţ�" << endl;
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

	//���Զ�ȡ�������ֵĿ�ʼ�±�
	int flag = 0;
	string temp;

	int i = 0;
	while (i < str.length()) {

		//Ϊ�ո�
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

		//Ϊ�����ţ���ջ
		else if (str[i] == '(') {
			MMstk.push(str[i]);
		}


		//���ch�ǲ�����
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			//����ǰһλΪ������
			if (i - 1 >= 0 && (str[i - 1] == '(') && str[i] == '-') {
				stk.push_back("0");
			}

			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				flag = i;
			}
			while (true) {
				// (a) ջΪ�ջ�ջ��Ԫ��Ϊ��Բ����
				if (MMstk.empty() || MMstk.top() == '(') {
					MMstk.push(str[i]);
					break;
				}
				// �����ȼ��ж���ջ
				else if (MMstk.top() == '+' || MMstk.top() == '-' || MMstk.top() == '*' || MMstk.top() == '/') {
					//(b) ���ch���ȼ���ջ��Ԫ�ظߣ���ô��ch��ջ				
					//(c) ch���ȼ����ڻ��ߵ���ջ��Ԫ��,��ջ��Ԫ�س�ջ�����֮��ת��a��

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
		//Ϊ��Բ����
		else if (str[i] == ')') {
			if (i != flag) {
				temp = str.substr(flag, i - flag);
				stk.push_back(temp);
				flag = i;
			}
			while (!MMstk.empty())
			{
				if (MMstk.top() == '(') {
					//'('��ջ
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



		//�����������(�������ֺ�.)
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
	//���������
	stack<double> ssk;

	int i = 0;
	while (i != cpyvc.size()) {
		if (cpyvc[i] == "+" || cpyvc[i] == "-" || cpyvc[i] == "*" || cpyvc[i] == "/") {
			//�ǲ�����, ��ջ��ȡ���������������㣬����ٽ�����ջ
			double n1 = ssk.top();
			ssk.pop();
			//˫Ŀ����
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
			//��Ŀ����
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
		//�����ֵĻ�����ջ(������)
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