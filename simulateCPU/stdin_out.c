#include "simulate.h"
//#include<stdio.h> //文件读取 操作
//#include<stdlib.h>free malloc等操作

/*
标准输入输出
参数	任务——前操作对象-数据寄存器
	operate dest   ax[]
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void stdin_out(int operate, int dest, int ax[],int* id)
{
	switch (operate) 
	{
		case 11:
		{
			printf("in:\n");
			scanf_s("%d", &ax[dest]);// 注意提交时 替换scanf_s
		}			
		break;
		case 12:
		{
			/*printf("\n********************\n");
			printf("id = ");
			printf("%d    ", *id);
			printf("out: ");
			printf("%d   *\n", ax[dest]);
			printf("********************\n\n");*/
			//一次输出，防止线程竞争导致输出错乱
			printf("\n********************\nid = %d    out: %d   *\n********************\n\n", *id, ax[dest]);
		}
		break;
	}
}