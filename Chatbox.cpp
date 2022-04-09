#include "Chatbox.h"

void ChatBox(string name) {

	system("pause");
	system("cls");

	int enter = 1;
	while (enter) {


		/////////////////////获取时间
		struct tm* tm_ptr;
		time_t the_time;
		(void)time(&the_time);
		tm_ptr = gmtime(&the_time);
		int year = tm_ptr->tm_year + 1900;
		int month = tm_ptr->tm_mon + 1;
		int day = tm_ptr->tm_mday;
		int hour = tm_ptr->tm_hour;
		int minute = tm_ptr->tm_min;
		int second = tm_ptr->tm_sec;

		string mie;
		if (minute < 10) mie = '0' + to_string(minute);
		else mie = to_string(minute);

		string theTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + " " + to_string(hour) + ":" + mie + ":" + to_string(second);
		/////////////////////////////////



		ofstream ofs(FILECHATBOX, ios::out | ios::app);
		ifstream ifs(FILECHATBOX, ios::in);

		cout << "======================================================================" << endl;
		cout << "----------------------------聊天室------------------------------------" << endl;
		cout << "======================================================================" << endl << endl;




		string human, message;
		while (getline(ifs, human) && getline(ifs, message))
		{
			//如果是自己的消息，就靠右，别人的靠左
			stringstream ss(human);
			string temp;
			//做两次getline，获取后面的用户名称
			getline(ss, temp, ',');
			getline(ss, temp, ',');

			if (temp == name) {
				cout.width(70); cout << human << endl;
				cout.width(70); cout << message << endl << endl;
			}
			else {
				cout << human << endl << message << endl << endl;
			}
		}

		cout << "======================================================================" << endl;
		cout << "-----  1.编辑消息发送  0.退出聊天室  ---------------------------------" << endl;
		cout << "-----  请输入数字进行下一步操作 ： ";



		string kksk;
		cin.sync();
		getline(cin, kksk);
		//判断输入是否正确
		if (kksk != "1" && kksk != "0") {
			cout << "输入有误！请重新输入！";
			system("pause");
			system("cls");
			continue;
		}
		else {
			//退出聊天室
			if (kksk == "0") {
				cout << endl << "你已退出聊天室！！" << endl;
				system("pause");
				system("cls");
				//外循环退出标志
				enter = 0;
				break;
			}
			//准备发送信息
			else {
				cout << endl;
				string send;
				cout << "请输入要发送的信息：" << endl;
				cin.sync();
				getline(cin, send);

				ofs << theTime << "," << name << endl;
				ofs << send << endl;

				cout << "已发送！！" << endl;
				system("pause");
				system("cls");
				continue;
			}
		}

		ifs.close();
		ofs.close();

	}

}