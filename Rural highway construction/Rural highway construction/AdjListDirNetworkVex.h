#pragma once
#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__

// �ڽӱ�����������
struct AdjListNetWorkVex
{
	// ���ݳ�Ա:
	string data;						// ����Ԫ��ֵ
	AdjListNetworkArc* firstarc;        // ָ���ڽӵĵ�һ���ߵ�ָ��

// ���캯��:
	AdjListNetWorkVex();				// �޲����Ĺ��캯��
	AdjListNetWorkVex(string val,AdjListNetworkArc* adj = NULL);// �в����Ĺ��캯��
};

// �ڽӱ������������ʵ�ֲ���
AdjListNetWorkVex::AdjListNetWorkVex()
// �������������һ���ն����㡪���޲ι��캯��
{
	firstarc = NULL;
}

AdjListNetWorkVex::AdjListNetWorkVex(string val, AdjListNetworkArc* adj )
	// �����������������Ϊval,��Ϊeg�Ķ���
{
	data = val;
	firstarc = adj;
}

#endif
