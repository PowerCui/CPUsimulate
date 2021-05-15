//#include<stdio.h> 
//#include<stdlib.h>

/*
逻辑运算指令
参数	任务——前操作对象——后操作对象——立即数
	operate dest   source		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void log(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	//立即数  的传递 
	if (source == 0) {
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
			if (ax[dest] && data[(ax[source] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 7:
			if (ax[dest] || data[(ax[source] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 8:
			data[(ax[source] - 16384) / 2] = !data[(ax[source] - 16384) / 2];
			break;
		}
	}
}
