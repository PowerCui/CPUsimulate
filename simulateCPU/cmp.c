#include<stdio.h> 
#include<stdlib.h>

/*
�Ƚ�ָ��

*/
void cmp(int dest, int source, int imm, int *data, int ax[], int* flag)
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