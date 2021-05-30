//#include<stdio.h> 
//#include<stdlib.h>

/*
算数运算指令
参数——同division函数的参数
*/
void calculate(int operate, int dest, int src, int imm,int *data, int ax[])
{
	//立即数 imm  的传递
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
	//寄存器 之间的传递 
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