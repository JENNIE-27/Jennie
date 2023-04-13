#pragma once
#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__
#include "Assistance.h"
#include "AdjListDirNetworkArc.h"			// �����ڽӱ�ı߽����
#include "AdjListDirNetworkVex.h"			// �����ڽӱ�Ķ�������
#include "NewNode.h"



// ���������ڽӱ���
class AdjListDirNetwork
{
protected:
	// �ڽӱ�����ݳ�Ա:
	int vexNum, vexMaxNum=1000, arcNum;				// ������Ŀ������Ķ��������Ŀ�ͱ���
	AdjListNetWorkVex* vexTable;	                // �����
	mutable Status* tag;					        // ��־����				
	int infinity=1000000;							// ������ֵ 

public:
	// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	AdjListDirNetwork(VexNode* vexs, int vertexNum, ArcNode* arcs, int arcnum, int vertexMaxNum, int infinit = (int)DEFAULT_INFINITY);
	// ������es[]Ϊ��������,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,
	// infinit��ʾ�����,����Ϊ0������������ȷ�����ã�
	AdjListDirNetwork(int vertexMaxNum, int infinit = (int)DEFAULT_INFINITY);
	// ��������Ķ��������ĿΪvertexMaxNum,infinit��ʾ�����,����Ϊ0��������
	~AdjListDirNetwork();						 // ��������
	void Clear();			                     // ���������			 
	bool IsEmpty();                              // �ж��������Ƿ�Ϊ�� ��ȷ�����ã�
	Status GetElem(int v, string& d) const;    // �󶥵��Ԫ��ֵ	
	Status SetElem(int v, const string& d);    // ���ö����Ԫ��ֵ
	int GetOrder(string& d) const;
	int GetInfinity() const;				 // ȡ������ֵ			 
	int GetVexNum() const;						 // ���������Ķ������			 
	int GetArcNum() const;						 // ���������ı�������			 
	int FirstAdjVex(int v) const;				 // ���������ж���v�ĵ�һ���ڽӵ�			 
	int NextAdjVex(int v1, int v2) const;		 // ���������ж���v1�������v2����һ���ڽӵ�			 	 
	void InsertArc(int v1, int v2, int w);// ����Ӷ���Ϊv1��v2��ȨΪw�ı�			 	 		 
	int GetWeight(int v1, int v2) const;	 // ��Ӷ���Ϊv1��v2�ıߵ�Ȩֵ
	void SetWeight(int v1, int v2, int w);// ���ôӶ���Ϊv1��v2�ıߵ�Ȩֵ
	Status GetTag(int v) const;				     // �󶥵�v�ı�־		 
	void SetTag(int v, Status tag) const;	     // ���ö���v�ı�־Ϊtag	 
	void Display();	                             // ��ʾ�������ڽӱ� (��ȷ������)
};

// ���������ڽӱ����ʵ�ֲ���
AdjListDirNetwork::AdjListDirNetwork(VexNode* vexs, int vertexNum,  ArcNode* arcs, int arcnum, int vertexMaxNum=DEFAULT_SIZE,int infinit)//n�Ǳ���

	// ������������춥������Ϊes[],������ΪnumVex,�������ΪvertexNum,infinit��ʾ�����,����Ϊ0��
{
	//�������ж��㲢��������
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
		throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

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
	//��ʼ�����
	for (int i = 0; i < arcnum;i++)
	{ //����������
		InsertArc(arcs[i].v1, arcs[i].v2, arcs[i].weight);
	}


}

AdjListDirNetwork::AdjListDirNetwork(int vertexMaxNum, int infinit)
// ������������춥�������ĿΪvertexMaxNum,infinit��ʾ�����Ŀ�������
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex[vexMaxNum];
}

AdjListDirNetwork::~AdjListDirNetwork()
// ����������ͷ��ڽӱ���������ռ�ÿռ�
{
	Clear();                                // �ͷű߽��
	delete[]tag;							// �ͷű�־
	delete[]vexTable;						// �ͷ��ڽӱ�
}


void AdjListDirNetwork::Clear()
// ����������ͷ����еı߽�㣬�����������Ķ������ͱ�������Ϊ0.			 
{
	AdjListNetworkArc* p;
	for (int v = 0; v < vexNum; v++) {	// �ͷű߽��
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
// ������������������Ϊ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}


int AdjListDirNetwork::GetOrder(string& d) const
// ����������󶥵�d�����.�������Ŵ�0��ʼ��ͼ�в����ڶ���dʱ����-1. 
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (d == vexTable[v].data)
			break;

	if (v < 0 || v >= vexNum)
		return -1;	// ����d������,����-1
	else
		return v;	// ����d������,����������� 
}


Status AdjListDirNetwork::GetElem(int v, string& d) const
// ��������������Ϊv�Ķ���ֵ, v��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ����
//	ͨ��dȡ�ö���ֵ��������ENTRY_FOUND������������NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;			// Ԫ�ز�����
	else {
		d = vexTable[v].data;		// ������v��Ԫ��ֵ����d
		return ENTRY_FOUND;			// Ԫ�ش���
	}
}

Status AdjListDirNetwork::SetElem(int v, const string& d)
// ������������ö����Ԫ��ֵv��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ��������
//	SUCCESS, ����������RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;			// λ�ô�
	else {
		vexTable[v].data = d;		// ����Ԫ��
		return SUCCESS;				// �ɹ�
	}
}

int AdjListDirNetwork::GetInfinity() const
// �������������������ֵ 
{
	return infinity;
}

int AdjListDirNetwork::GetVexNum() const
// ������������ض������			 
{
	return vexNum;
}


int AdjListDirNetwork::GetArcNum() const
// ������������ر�������
{
	return arcNum;
}


int AdjListDirNetwork::FirstAdjVex(int v) const
// ������������ض���v�ĵ�һ���ڽӵ�			 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");// �׳��쳣

	if (vexTable[v].firstarc == NULL)
		return -1;              // �������ڽӵ�
	else
		return vexTable[v].firstarc->adjVex;
}


int AdjListDirNetwork::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	AdjListNetworkArc* p;
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");// �׳��쳣

	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;

	if (p == NULL || p->nextarc == NULL)
		return -1;                   // ��������һ���ڽӵ�
	else
		return p->nextarc->adjVex;
}

void AdjListDirNetwork::InsertArc(int v1, int v2, int w)
// ������������붥��Ϊv1��v2,ȨΪw�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");// �׳��쳣


	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	vexTable[v1].firstarc = new AdjListNetworkArc(v2, w, p);
	arcNum++;
}


int AdjListDirNetwork::GetWeight(int v1, int v2) const
// ������������ض���Ϊv1��v2�ıߵ�Ȩֵ
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");	// �׳��쳣

	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		return p->weight;			// ����Ȩֵ
	else
		return infinity;				// ����ȨֵΪinfinity����ʾ�߲�����
}

void AdjListDirNetwork::SetWeight(int v1, int v2, int w)
// ������������ö���Ϊv1��v2�ıߵ�Ȩֵ
{
	if (v1 < 0 || v1 >= vexNum)
		throw Error("v1���Ϸ�!");        // �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
		throw Error("v2���Ϸ�!");	    // �׳��쳣
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");    // �׳��쳣
	if (w == infinity)
		throw Error("w����Ϊ�޿մ�!");   // �׳��쳣

	AdjListNetworkArc* p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p != NULL)
		p->weight = w;		            // �޸�Ȩֵ
}


Status AdjListDirNetwork::GetTag(int v) const
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");		// �׳��쳣

	return tag[v];
}


void AdjListDirNetwork::SetTag(int v, Status val) const
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
		throw Error("v���Ϸ�!");		// �׳��쳣

	tag[v] = val;
}




void AdjListDirNetwork::Display()
// �������: ��ʾ�ڽӾ���������
{
	AdjListNetworkArc* p;
	cout << "����������" << vexNum << "�����㣬" << arcNum << "���ߡ�" << endl;
	for (int v = 0; v < vexNum; v++) {	// ��ʾ��v���ڽ�����
		cout << v << ":\t" << vexTable[v].data;				// ��ʾ�����
		p = vexTable[v].firstarc;
		while (p != NULL) {
			cout << "-->(" << p->adjVex << "," << p->weight << ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}

#endif
