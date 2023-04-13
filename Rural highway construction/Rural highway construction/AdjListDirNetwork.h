#pragma once
#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__
#include "Assistance.h"
#include "AdjListDirNetworkArc.h"			// 网络邻接表的边结点类
#include "AdjListDirNetworkVex.h"			// 网络邻接表的顶点结点类
#include "NewNode.h"



// 无向网的邻接表类
class AdjListDirNetwork
{
protected:
	// 邻接表的数据成员:
	int vexNum, vexMaxNum=1000, arcNum;				// 顶点数目、允许的顶点最大数目和边数
	AdjListNetWorkVex* vexTable;	                // 顶点表
	mutable Status* tag;					        // 标志数组				
	int infinity=1000000;							// 无穷大的值 

public:
	// 抽象数据类型方法声明及重载编译系统默认方法声明:
	AdjListDirNetwork(VexNode* vexs, int vertexNum, ArcNode* arcs, int arcnum, int vertexMaxNum, int infinit = (int)DEFAULT_INFINITY);
	// 以数组es[]为顶点数据,顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,
	// infinit表示无穷大,边数为0构造无向网（确认能用）
	AdjListDirNetwork(int vertexMaxNum, int infinit = (int)DEFAULT_INFINITY);
	// 构造允许的顶点最大数目为vertexMaxNum,infinit表示无穷大,边数为0的无向网
	~AdjListDirNetwork();						 // 析构函数
	void Clear();			                     // 清空有向网			 
	bool IsEmpty();                              // 判断有向网是否为空 （确认能用）
	Status GetElem(int v, string& d) const;    // 求顶点的元素值	
	Status SetElem(int v, const string& d);    // 设置顶点的元素值
	int GetOrder(string& d) const;
	int GetInfinity() const;				 // 取无穷大的值			 
	int GetVexNum() const;						 // 求有向网的顶点个数			 
	int GetArcNum() const;						 // 求有向网的边数个数			 
	int FirstAdjVex(int v) const;				 // 求有向网中顶点v的第一个邻接点			 
	int NextAdjVex(int v1, int v2) const;		 // 求有向网中顶点v1的相对于v2的下一个邻接点			 	 
	void InsertArc(int v1, int v2, int w);// 插入从顶点为v1到v2、权为w的边			 	 		 
	int GetWeight(int v1, int v2) const;	 // 求从顶点为v1到v2的边的权值
	void SetWeight(int v1, int v2, int w);// 设置从顶点为v1到v2的边的权值
	Status GetTag(int v) const;				     // 求顶点v的标志		 
	void SetTag(int v, Status tag) const;	     // 设置顶点v的标志为tag	 
	void Display();	                             // 显示有向网邻接表 (已确认能用)
};

// 无向网的邻接表类的实现部分
AdjListDirNetwork::AdjListDirNetwork(VexNode* vexs, int vertexNum,  ArcNode* arcs, int arcnum, int vertexMaxNum=DEFAULT_SIZE,int infinit)//n是边数

	// 操作结果：构造顶点数据为es[],顶点数为numVex,顶点个数为vertexNum,infinit表示无穷大,边数为0，
{
	//建立所有顶点并输入数据
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");        // 抛出异常

	if (vertexMaxNum < vertexNum)
		throw Error("顶点数目不能大于允许的顶点最大数目!");// 抛出异常

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex[vexMaxNum];

	for (int v = 0; v < vexNum; v++) {
		tag[v] = UNVISITED;
		vexTable[v].data = vexs[v].name;
		vexTable[v].firstarc = NULL;
	}
	//开始构造边
	for (int i = 0; i < arcnum;i++)
	{ //遍历边数组
		InsertArc(arcs[i].v1, arcs[i].v2, arcs[i].weight);
	}


}

AdjListDirNetwork::AdjListDirNetwork(int vertexMaxNum, int infinit)
// 操作结果：构造顶点最大数目为vertexMaxNum,infinit表示无穷大的空有向网
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点最大数目不能为负!");// 抛出异常

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex[vexMaxNum];
}

AdjListDirNetwork::~AdjListDirNetwork()
// 操作结果：释放邻接表有向网所占用空间
{
	Clear();                                // 释放边结点
	delete[]tag;							// 释放标志
	delete[]vexTable;						// 释放邻接表
}


void AdjListDirNetwork::Clear()
// 操作结果：释放所有的边结点，并把有向网的顶点数和边数设置为0.			 
{
	AdjListNetworkArc* p;
	for (int v = 0; v < vexNum; v++) {	// 释放边结点
		p = vexTable[v].firstarc;
		while (p != NULL) {
			vexTable[v].firstarc = p->nextarc;
			delete p;
			p = vexTable[v].firstarc;
		}
	}
	vexNum = 0;
	arcNum = 0;
}


bool AdjListDirNetwork::IsEmpty()
// 操作结果：如果有向网为空返回true,否则返回false.
{
	return vexNum == 0;
}


int AdjListDirNetwork::GetOrder(string& d) const
// 操作结果：求顶点d的序号.顶点的序号从0开始，图中不存在顶点d时返回-1. 
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (d == vexTable[v].data)
			break;

	if (v < 0 || v >= vexNum)
		return -1;	// 顶点d不存在,返回-1
	else
		return v;	// 顶点d不存在,返回它的序号 
}


Status AdjListDirNetwork::GetElem(int v, string& d) const
// 操作结果：求序号为v的顶点值, v的取值范围为0 ≤ v ＜ vexNum, v合法时函数
//	通过d取得顶点值，并返回ENTRY_FOUND；否则函数返回NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;			// 元素不存在
	else {
		d = vexTable[v].data;		// 将顶点v的元素值赋给d
		return ENTRY_FOUND;			// 元素存在
	}
}

Status AdjListDirNetwork::SetElem(int v, const string& d)
// 操作结果：设置顶点的元素值v的取值范围为0 ≤ v ＜ vexNum, v合法时函数返回
//	SUCCESS, 否则函数返回RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;			// 位置错
	else {
		vexTable[v].data = d;		// 顶点元素
		return SUCCESS;				// 成功
	}
}

int AdjListDirNetwork::GetInfinity() const
// 操作结果：返回无穷大的值 
{
	return infinity;
}

int AdjListDirNetwork::GetVexNum() const
// 操作结果：返回顶点个数			 
{
	return vexNum;
}


int AdjListDirNetwork::GetArcNum() const
// 操作结果：返回边数个数
{
	return arcNum;
}


int AdjListDirNetwork::FirstAdjVex(int v) const
// 操作结果：返回顶点v的第一个邻接点			 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");// 抛出异常

	if (vexTable[v].firstarc == NULL)
		return -1;              // 不存在邻接点
	else
		return vexTable[v].firstarc->adjVex;
}


int AdjListDirNetwork::NextAdjVex(int v1, int v2) const
// 操作结果：返回顶点v1的相对于v2的下一个邻接点			 
{
	AdjListNetworkArc* p;
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
		throw Error("v1不能等于v2!");// 抛出异常

	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;

	if (p == NULL || p->nextarc == NULL)
		return -1;                   // 不存在下一个邻接点
	else
		return p->nextarc->adjVex;
}

void AdjListDirNetwork::InsertArc(int v1, int v2, int w)
// 操作结果：插入顶点为v1和v2,权为w的边			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
		throw Error("v1不能等于v2!");// 抛出异常


	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	vexTable[v1].firstarc = new AdjListNetworkArc(v2, w, p);
	arcNum++;
}


int AdjListDirNetwork::GetWeight(int v1, int v2) const
// 操作结果：返回顶点为v1和v2的边的权值
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");	// 抛出异常

	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		return p->weight;			// 返回权值
	else
		return infinity;				// 返回权值为infinity，表示边不存在
}

void AdjListDirNetwork::SetWeight(int v1, int v2, int w)
// 操作结果：设置顶点为v1和v2的边的权值
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1不合法!");        // 抛出异常
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2不合法!");	    // 抛出异常
	if (v1 == v2)
		throw Error("v1不能等于v2!");    // 抛出异常
	if (w == infinity)
		throw Error("w不能为无空大!");   // 抛出异常

	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		p->weight = w;		            // 修改权值
}


Status AdjListDirNetwork::GetTag(int v) const
// 操作结果：返回顶点v的标志		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");		// 抛出异常

	return tag[v];
}


void AdjListDirNetwork::SetTag(int v, Status val) const
// 操作结果：设置顶点v的标志为val		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v不合法!");		// 抛出异常

	tag[v] = val;
}




void AdjListDirNetwork::Display()
// 操作结果: 显示邻接矩阵无向网
{
	AdjListNetworkArc* p;
	cout << "有向网共有" << vexNum << "个顶点，" << arcNum << "条边。" << endl;
	for (int v = 0; v < vexNum; v++) {	// 显示第v个邻接链表
		cout << v << ":\t" << vexTable[v].data;				// 显示顶点号
		p = vexTable[v].firstarc;
		while (p != NULL) {
			cout << "-->(" << p->adjVex << "," << p->weight << ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}

#endif
