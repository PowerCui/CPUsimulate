#include"simulate.h"
//#include<Windows.h>//线程函数需要的操作系统的函数 即  HANDLE
//extern HANDLE hMutex;

//功能跳转
/*
参数	任务——前操作对象——后操作对象——立即数
	operate dest   src		imm
	代码——数据——寄存器
	*code  *data   ax[]
	程序计数器-- 指令寄存-- 标志寄存
	*ip			*ir		*flag
功能	根据operate 进行 相应的操作
返回值	NULL
*/
void division(int operate, int dest, int src, int imm, int* data, int ax[], int* ip, int* flag, int* id)
{
	switch (operate) {
	case 1://数据传送 
		mov(dest, src, imm, data, ax);
		break;
	case 2:case 3:case 4:case 5://算术运算 
		calculate(operate, dest, src, imm, data, ax);
		break;
	case 6:case 7:case 8://逻辑运算 
		logic(operate, dest, src, imm, data, ax);
		break;
	case 9://比较 
		cmp(dest, src, imm, data, ax, flag);
		break;
	case 10://跳转 
		jmp(src, imm, ip, flag);
		break;
	case 11:case 12://输入输出 
		stdin_out(operate, dest, ax, id);
		break;
	case 13:
		WaitForSingleObject(hMutex, INFINITE);//锁住内存
		break;
	case 14:
		ReleaseMutex(hMutex);//释放内存
		break;
	case 15:
		Sleep(imm);//休眠立即数(ms)时间
		break;
	default:
		break;
	}
}