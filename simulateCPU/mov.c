//#include<stdio.h> 
//#include<stdlib.h>

/*
���ݴ���
����	ǰ�������󡪡���������󡪡�������
	dest   source		imm
	���ݡ����Ĵ���
	*data   ax[]
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void mov(int dest, int source, int imm, int *data, int ax[])
{
	//������  �Ĵ��� 
	if (source == 0) {
		ax[dest] = imm;
	}
	//�Ĵ��� ֮��Ĵ���
	else {
		if (dest <= 4)
			ax[dest] = data[(ax[source] - 16384) / 2];////////////////////////////�滻ʱ�򲢷�ȫ��ƥ��,���¶���滻,�������
		else//dest >= 5
			data[(ax[dest] - 16384) / 2] = ax[source];
	}
}