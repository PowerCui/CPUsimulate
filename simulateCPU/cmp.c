#include<stdio.h> 
#include<stdlib.h>

/*
比较指令

*/
void cmp(int dest, int source, int imm, int *data, int ax[], int* flag)
{
	//立即数  的传递 
	if (source == 0) {
		if (ax[dest] > imm)
			*flag = 1;
		if (ax[dest] == imm)
			*flag = 0;
		if (ax[dest] < imm)
			*flag = -1;
	}
	//寄存器 之间的传递
	else {
		if (ax[dest] > data[(ax[source] - 16384) / 2])
			*flag = 1;
		if (ax[dest] == data[(ax[source] - 16384) / 2])
			*flag = 0;
		if (ax[dest] < data[(ax[source] - 16384) / 2])
			*flag = -1;
	}

}