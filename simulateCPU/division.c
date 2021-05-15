#include"simulate.h"

//功能跳转
/*
参数	任务——前操作对象——后操作对象——立即数
	operate dest   source		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void division(int operate, int dest, int source, int imm, int *data, int ax[], int* ip,  int* flag)
{
	switch (operate) {
	case 1://数据传送 
		mov(dest, source, imm, data, ax);
		break;
	case 2:case 3:case 4:case 5://算术运算 
		calculate(operate, dest, source, imm, data, ax);
		break;
	case 6:case 7:case 8://逻辑运算 
		log(operate, dest, source, imm, data, ax);
		break;
	case 9://比较 
		cmp(dest, source,imm,data,ax,flag);
		break;
	case 10://跳转 
		jmp(source, imm, ip, flag);
		break;
	case 11:case 12://输入输出 
		stdin_out(operate, dest, ax);
		break;
	default:
		break;
	}
}