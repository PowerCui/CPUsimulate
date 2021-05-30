//#include<stdio.h> 
//#include<stdlib.h>

/*
逻辑运算指令
参数	任务——前操作对象——后操作对象——立即数
	operate dest   src		imm
	数据——寄存器
	 *data   ax[]
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void logic(int operate, int dest, int src, int imm,  int *data, int ax[])
{
	//立即数  的传递 
	if (src == 0) {
		switch (operate)
		{
		case 6:
			if (ax[dest] && imm)
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 7:
			if (ax[dest] || imm)
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 8:
			ax[dest] = !ax[dest];
			break;
		}
	}
	//寄存器 之间的传递
	else {
		switch (operate) {
		case 6:
			if (ax[dest] && data[(ax[src] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 7:
			if (ax[dest] || data[(ax[src] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 8:
			data[(ax[src] - 16384) / 2] = !data[(ax[src] - 16384) / 2];
			break;
		}
	}
}
