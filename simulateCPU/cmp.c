#include<stdio.h> 
#include<stdlib.h>

/*
�Ƚ�ָ��
��������ͬdivision�����Ĳ���
*/
void cmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	//������  �Ĵ��� 
	if (source == 0) {
		if (ax[dest] > imm)
			*flag = 1;
		if (ax[dest] == imm)
			*flag = 0;
		if (ax[dest] < imm)
			*flag = -1;
	}
	//�Ĵ��� ֮��Ĵ���
	else {
		if (ax[dest] > data[(ax[source] - 16384) / 2])
			*flag = 1;
		if (ax[dest] == data[(ax[source] - 16384) / 2])
			*flag = 0;
		if (ax[dest] < data[(ax[source] - 16384) / 2])
			*flag = -1;
	}

}