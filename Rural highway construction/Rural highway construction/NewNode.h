#pragma once
#ifndef __NEW_NODE_H__
#define __NEW_NODE_H__

//�¶���ṹ��VexNode�����ڽ�txt���ݴ���vexs������
struct VexNode
{
	string name;                      //�������
	int id=0;                         //�����
}vexs[100];

//�¶���ṹ��ArcNode�����ڽ�txt���ݴ���arcs������
struct ArcNode
{
	int v1;							// ��ͷ������
	int v2;                         //��β������
	string v1name;                //��ͷ��������
	string v2name;               //��β��������
	int weight;					 // �ߵ�Ȩֵ

}arcs[100];



#endif
