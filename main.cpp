#include "Assistance.h"					// ʵ�ó��������
#include "ChildSiblingTree.h"			// �����ֵܱ�ʾ����
#include "conio.h"                      // getche��ͷ�ļ�


int main() {
	int a[19];
	cout << "��ӭʹ�ü�ͥ����ϵͳ�����洴��������" << endl;
// ��ʼ��1����zupu.txt�е�������������p[]��
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

//��ʼ��2����parent.txt�е����ݴ���������
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

//��ʼ����Ŀ¼
	ChildSiblingTree zupu(p, a, 19); //������
	cout << "�������ɹ���" << endl;
	while (1) {
		int n;
		cout << "          *******���׹�����Ŀ¼*******         " << endl;
		cout << "          ------------------------------         " << endl;
		cout << "                  0. �˳�ϵͳ                    " << endl;
		cout << "                  1.��ӡ������                   " << endl;
		cout << "               2.��ʾһ��������������            " << endl;
		cout << "                3.��������ѯ��Ա��Ϣ             " << endl;
		cout << "               4.�����ղ��Ҽ��׳�Ա              " << endl;
		cout << "               5.��������ȷ����ϵ                " << endl;
		cout << "                   6.��Ӻ���                    " << endl;
		cout << "                   7.ɾ����Ա                    " << endl;
		cout << "                 8.�޸ĳ�Ա��Ϣ                  " << endl;
		cout << "         -------------------------------         " << endl;
		cout << "��������Ĳ���(0~9):" << endl;
		cin >> n;
		if (n == 0) {
			return 0;
		} else {
			switch (n) {
				case 1:
					cout << "��ӡ��:" << endl;
					DisplayTWithConcaveShape(zupu);
					cout << "��ӡ�����" << endl;
					break;
				case 2:
					cout << "������д�ˣ�����" << endl;
					break;
				case 3:
					cout << "������д�ˣ�����" << endl;
					break;
				case 4:
					cout << "������д�ˣ�����" << endl;
					break;
				case 5:
					cout << "������д�ˣ�����" << endl;
					break;
				case 6:
					cout << "������д�ˣ�����" << endl;
					break;
				case 7:
					cout << "������д�ˣ�����" << endl;
					break;
				case 8:
					cout << "������д�ˣ�����" << endl;
					break;


			}
		}
	}

}



