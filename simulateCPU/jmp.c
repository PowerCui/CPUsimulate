//#include<stdio.h> 
//#include<stdlib.h>

/*
跳转指令
参数	任务——前操作对象——后操作对象——立即数
	operate dest   source		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void jmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	if (source == 0)
	{
		*ip += imm - 4;
	}
	if (source == 1)
	{
		if (*flag == 0)
			*ip += imm - 4;
	}
	if (source == 2)
	{
		if (*flag == 1)
			*ip += imm - 4;
	}
	if (source == 3)
	{
		if (*flag == -1)
			*ip += imm - 4;
	}
}