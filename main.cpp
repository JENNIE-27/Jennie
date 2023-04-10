#include "Assistance.h"					// 实用程序软件包
#include "ChildSiblingTree.h"			// 孩子兄弟表示树类
#include "conio.h"                      // getche的头文件


int main() {
	int a[19];
	cout << "欢迎使用家庭管理系统，下面创建家谱树" << endl;
// 初始化1，把zupu.txt中的数据输入数组p[]里
	int n = 0;
	ifstream in( "zupu.txt", ios::in | ios::binary);
	if (!in.is_open()) {
		cout << "Error: opening file fail" << endl;
		exit (1);
	}
	while (!in.eof() && n < 19) {
		in >> p[n].name >> p[n].birth >> p[n].marriage >> p[n].address >> p[n].condition >> p[n].death;
		n++;
	}
//test
	for ( int i = 0; i < n; ++i)
		cout << "name:" << p[i].name << "birth:" << p[i].birth << "marriage:" << p[i].marriage << "address:" << p[i].address <<
		     "condition:" << p[i].condition << "death:" << p[i].death << endl;
	in.close();

//初始化2，把parent.txt中的数据传入数组里
	int m = 0;
	ifstream parin( "parent.txt", ios::in);
	if (!parin.is_open()) {
		cout << "Error: opening file fail" << endl;
		exit (1);
	}
	while (!parin.eof() && m < 19) {
		parin >> a[m];
		m++;
	}

//test
	for ( int i = 0; i < 19; ++i)
		cout << "parent:" << a[i] << endl;
	parin.close();

//开始功能目录
	ChildSiblingTree zupu(p, a, 19); //创建树
	cout << "树创建成功啦" << endl;
	while (1) {
		int n;
		cout << "          *******家谱管理功能目录*******         " << endl;
		cout << "          ------------------------------         " << endl;
		cout << "                  0. 退出系统                    " << endl;
		cout << "                  1.打印家谱树                   " << endl;
		cout << "               2.显示一代人姓名和人数            " << endl;
		cout << "                3.按姓名查询成员信息             " << endl;
		cout << "               4.按生日查找家谱成员              " << endl;
		cout << "               5.根据姓名确定关系                " << endl;
		cout << "                   6.添加孩子                    " << endl;
		cout << "                   7.删除成员                    " << endl;
		cout << "                 8.修改成员信息                  " << endl;
		cout << "         -------------------------------         " << endl;
		cout << "请输入你的操作(0~9):" << endl;
		cin >> n;
		if (n == 0) {
			return 0;
		} else {
			switch (n) {
				case 1:
					cout << "打印树:" << endl;
					DisplayTWithConcaveShape(zupu);
					cout << "打印树完成" << endl;
					break;
				case 2:
					cout << "等着你写了，加油" << endl;
					break;
				case 3:
					cout << "等着你写了，加油" << endl;
					break;
				case 4:
					cout << "等着你写了，加油" << endl;
					break;
				case 5:
					cout << "等着你写了，加油" << endl;
					break;
				case 6:
					cout << "等着你写了，加油" << endl;
					break;
				case 7:
					cout << "等着你写了，加油" << endl;
					break;
				case 8:
					cout << "等着你写了，加油" << endl;
					break;


			}
		}
	}

}



