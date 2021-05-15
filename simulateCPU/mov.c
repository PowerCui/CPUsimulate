//#include<stdio.h> 
//#include<stdlib.h>

/*
数据传送
参数	前操作对象——后操作对象——立即数
	dest   source		imm
	数据——寄存器
	*data   ax[]
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void mov(int dest, int source, int imm, int *data, int ax[])
{
	//立即数  的传递 
	if (source == 0) {
		ax[dest] = imm;
	}
	//寄存器 之间的传递
	else {
		if (dest <= 4)
			ax[dest] = data[(ax[source] - 16384) / 2];////////////////////////////替换时候并非全字匹配,导致多次替换,结果出错
		else//dest >= 5
			data[(ax[dest] - 16384) / 2] = ax[source];
	}
}