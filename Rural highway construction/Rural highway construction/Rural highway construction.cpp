#include "AdjListDirNetwork.h"		    // 邻接表有向网


int Getnumber(VexNode* vexs, string vexname, int vexnum)
{
	int i;
	for (i = 0; i < vexnum;i++) 
	{
		if (vexs[i].name.compare(vexname) == 0)
		{   
			if (vexs[i].id < vexnum)
			{
				return vexs[i].id;
			}
		}
	}
}


	int main()
	{
		int vexnum = 0;//记录总行数,点数
		string document;//保存文件名字/用来判断是不是空行
		//找文件并尝试打开
		cout << "欢迎使用系统，请输入您需要绘图的文件名（格式为“文件名.txt”）" << endl;
		cin >> document;
		ifstream infile(document.data());
		if (!infile.is_open()) {
			cout << "没有找到该文件，请尝试重新输入" << endl;
			return 1;
		}

		//记录点数
		cout << "请问您需要绘图的村庄数是" << endl;
		cin >> vexnum;

		//创建存储结点信息的数组
		cout << "Start loading vexs" << endl;
		if (vexs == NULL) {
			cout << "点数组内存申请失败！" << endl;
			exit(1);
		}

		//创建存储边信息的数组
		int arcnum = 0;
		cout << "请问您需要绘制的公路总数" << endl;
		cin >> arcnum;
		cout << "Start loading arcs" << endl;
		if (arcs == NULL) {
			cout << "边数组内存申请失败！" << endl;
			exit(1);
		}

		//将文件中的点数据输入vex[],序号保存到id里
		 int n = 0;
		  while (!infile.eof() && n < vexnum) { 
			infile >> vexs[n].name;
			n++;
		}

		  for (int i = 0; i < vexnum; i++)
		  {
			  vexs[i].id = i;
		}

		 //测试方便的，最后删掉
		cout << "以下用来测试点信息是否正确" << endl;
		for (int i = 0; i < vexnum; i++)
		{
			cout << "vex.name:" << vexs[i].name << endl;
			cout << "vex.id:" << vexs[i].id << endl;
		}
		cout << "测试getnumber函数" << endl;
		for (int i = 0; i < vexnum; i++)
		{
			cout <<"vex.name:" << vexs[i].name << "通过函数获得的id"<< Getnumber(vexs, vexs[i].name,vexnum)<<endl;
		}

		//将边数据输入arc[],第一个顶点保存到vex1，第二个顶点保存到vex2，权重保存到weight
		string tempe;//用来存储中间那一行废话，此处可优化
		for (int i = 0; i < 1; i++) { //把中间那句话存进去
			infile >> tempe;
		}
		for (int i = 0; i < arcnum; i++) { //把顶点名字转换成编号以后存进边数组
			infile >> arcs[i].v1name >> arcs[i].v2name >> arcs[i].weight;
			arcs[i].v1 = Getnumber(vexs, arcs[i].v1name, vexnum);
			arcs[i].v2 = Getnumber(vexs, arcs[i].v2name, vexnum);
		}
			//测试方便的，最后删掉
			cout << "以下用来测试边信息是否正确" << endl;
			for (int i = 0; i < arcnum; ++i)
			{
				cout << "arcs.v1:" << arcs[i].v1 << endl;
				cout << "arcs.v2:" << arcs[i].v2 << endl;
				cout << "arcs.weight:" << arcs[i].weight << endl;
			}
			infile.close();   //关闭文件
		
        //创建无向网
		AdjListDirNetwork net(vexs, vexnum, arcs, arcnum);
		cout << "无向网创建成功啦" << endl;
		    
		    int num = 0;
			int infity = DEFAULT_INFINITY;//无限大
			while (1) {
				cout << endl << "1. 显示公路建设图";
				cout << endl << "2. 最少资金建设方案";
				cout << endl << "3. 展示医院设置点和对应总路程";
				cout << endl << "0. 退出";
				cout << endl << "选择功能(0~3):";
				cin >> num;
				if (num == 0) {
					return 0;
				}
				else {
					switch (num) {
					case 1:
						if (net.IsEmpty())
							cout << "该有向网为空。" << endl;
						else
							net.Display();
						break;
					case 2:
						cout << "happiness lin 干巴爹" << endl;
						break;
					case 3:
						cout << "happiness wang 干巴爹" << endl;
						break;
					}
				}
				}
		return 0;							// 返回值0, 返回操作系统
	}

