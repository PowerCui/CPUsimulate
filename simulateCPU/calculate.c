//#include<stdio.h> 
//#include<stdlib.h>

/*
��������ָ��
��������ͬdivision�����Ĳ���
*/
void calculate(int operate, int dest, int src, int imm,int *data, int ax[])
{
	//������ imm  �Ĵ���
	if (src == 0) {
		switch (operate) {
		case 2:
			ax[dest] += imm;
			break;
		case 3:
			ax[dest] -= imm;
			break;
		case 4:
			ax[dest] *= imm;
			break;
		case 5:
			ax[dest] /= imm;
			break;
		default:
			break;
		}
	}
	//�Ĵ��� ֮��Ĵ��� 
	else {
		switch (operate) {
		case 2:
			ax[dest] += data[(ax[src] - 16384) / 2];
			break;
		case 3:
			ax[dest] -= data[(ax[src] - 16384) / 2];
			break;
		case 4:
			ax[dest] *= data[(ax[src] - 16384) / 2];
			break;
		case 5:
			ax[dest] /= data[(ax[src] - 16384) / 2];
			break;
		default:
			break;
		}
	}
}