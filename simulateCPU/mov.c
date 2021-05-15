//#include<stdio.h> 
//#include<stdlib.h>

/*
数据传送
参数	任务——前操作对象——后操作对象——立即数
	operate dest   source		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void mov(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	//立即数  的传递 
	if (source == 0) {
		ax[dest] = imm;
	}
	//寄存器 之间的传递
	else {
		if (dest <= 4)
			ax[dest] = data[((ax[source] - 16384) / 2) / 2];
		else//dest >= 5
			data[(ax[dest] - 16384) / 2] = ax[source];
	}
}