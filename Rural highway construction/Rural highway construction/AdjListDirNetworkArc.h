#pragma once
#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__

// 邻接表网边数据类（弧）
struct AdjListNetworkArc
{
	// 数据成员:
	int adjVex;								// 弧头顶点序号
	int weight;						        // 边的权值
	AdjListNetworkArc* nextarc;             // 下一条边结点的指针 
	// 构造函数:
	AdjListNetworkArc();					// 无参数的构造函数
	AdjListNetworkArc(int v, int w, AdjListNetworkArc* next = NULL);
	// 构造邻接点为v，权为w的邻接边
};

// 邻接表网边数据类的实现部分
AdjListNetworkArc::AdjListNetworkArc()
// 操作结果：构造一个空邻接表边结点边——无参构造函数
{
	adjVex = -1;
}

AdjListNetworkArc::AdjListNetworkArc(int v, int w, AdjListNetworkArc* next)
// 操作结果：构造邻接点序号为v，边的权为w，下一条边结点的指针为next的邻接边
{
	adjVex = v;
	weight = w;
	nextarc = next;
}

#endif
