#pragma once
#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__

// �ڽӱ����������ࣨ����
struct AdjListNetworkArc
{
	// ���ݳ�Ա:
	int adjVex;								// ��ͷ�������
	int weight;						        // �ߵ�Ȩֵ
	AdjListNetworkArc* nextarc;             // ��һ���߽���ָ�� 
	// ���캯��:
	AdjListNetworkArc();					// �޲����Ĺ��캯��
	AdjListNetworkArc(int v, int w, AdjListNetworkArc* next = NULL);
	// �����ڽӵ�Ϊv��ȨΪw���ڽӱ�
};

// �ڽӱ������������ʵ�ֲ���
AdjListNetworkArc::AdjListNetworkArc()
// �������������һ�����ڽӱ�߽��ߡ����޲ι��캯��
{
	adjVex = -1;
}

AdjListNetworkArc::AdjListNetworkArc(int v, int w, AdjListNetworkArc* next)
// ��������������ڽӵ����Ϊv���ߵ�ȨΪw����һ���߽���ָ��Ϊnext���ڽӱ�
{
	adjVex = v;
	weight = w;
	nextarc = next;
}

#endif
