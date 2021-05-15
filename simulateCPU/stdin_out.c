#include<stdio.h> 
#include<stdlib.h>

/*
标准输入输出
参数	任务——前操作对象——后操作对象——立即数
	operate dest   source		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void stdin_out(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	switch (operate) {
	case 11:
		printf("in:\n");
		scanf_s("%d", &ax[dest]);// 注意提交时 替换scanf_s
		break;
	case 12:
		printf("out: ");
		printf("%d\n", ax[dest]);
	}
}