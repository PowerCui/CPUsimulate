//#include<stdio.h> 
//#include<stdlib.h>

/*
���ݴ���
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   source		imm
	���롪�����ݡ����Ĵ���
	*code  *data   ax[]
	���������-- ָ��Ĵ�-- ��־�Ĵ�
	*ip			*ir		*flag
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void mov(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	//������  �Ĵ��� 
	if (source == 0) {
		ax[dest] = imm;
	}
	//�Ĵ��� ֮��Ĵ���
	else {
		if (dest <= 4)
			ax[dest] = data[((ax[source] - 16384) / 2) / 2];
		else//dest >= 5
			data[(ax[dest] - 16384) / 2] = ax[source];
	}
}