//#include<stdio.h> 
//#include<stdlib.h>

/*
跳转指令
参数	操作对象——立即数
	src		imm	
	程序计数器- 标志寄存
	*ip			*flag
返回值	NULL
*/
void jmp(int src, int imm,int* ip, int* flag)
{
	if (src == 0)
	{
		*ip += imm - 4;
	}
	if (src == 1)
	{
		if (*flag == 0)
			*ip += imm - 4;
	}
	if (src == 2)
	{
		if (*flag == 1)
			*ip += imm - 4;
	}
	if (src == 3)
	{
		if (*flag == -1)
			*ip += imm - 4;
	}
}