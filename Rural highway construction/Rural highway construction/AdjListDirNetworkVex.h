#pragma once
#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__

// 邻接表网顶点结点类
struct AdjListNetWorkVex
{
	// 数据成员:
	string data;						// 数据元素值
	AdjListNetworkArc* firstarc;        // 指向邻接的第一条边的指针

// 构造函数:
	AdjListNetWorkVex();				// 无参数的构造函数
	AdjListNetWorkVex(string val,AdjListNetworkArc* adj = NULL);// 有参数的构造函数
};

// 邻接表网顶点结点类的实现部分
AdjListNetWorkVex::AdjListNetWorkVex()
// 操作结果：构造一个空顶点结点——无参构造函数
{
	firstarc = NULL;
}

AdjListNetWorkVex::AdjListNetWorkVex(string val, AdjListNetworkArc* adj )
	// 操作结果：构造数据为val,边为eg的顶点
{
	data = val;
	firstarc = adj;
}

#endif
