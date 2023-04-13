#pragma once
#ifndef __NEW_NODE_H__
#define __NEW_NODE_H__

//新定义结构体VexNode，用在将txt数据传入vexs数组中
struct VexNode
{
	string name;                      //结点名字
	int id=0;                         //结点编号
}vexs[100];

//新定义结构体ArcNode，用在将txt数据传入arcs数组中
struct ArcNode
{
	int v1;							// 弧头顶点编号
	int v2;                         //弧尾顶点编号
	string v1name;                //弧头顶点名字
	string v2name;               //弧尾顶点名字
	int weight;					 // 边的权值

}arcs[100];



#endif
