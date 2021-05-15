/*
主函数main
 1>取指令，保存到寄存器
 2>分析指令，执行指令
 3>输出代码，数据

代码 code
数据 data
指令 寄存器 ir 	前 16位
程序计数器 ip 	+4
标志 寄存器 flag   		       
4个数据 寄存器 ax1~ax4 
4个地址 寄存器 ax5-ax8 存放地址
ax[i]  第 i 个寄存器
*/

#include"simulate.h"

int main(void)
{
	char* code = (char*)malloc(sizeof(char) * (16384+10));
	int ax[9] = { 0 };
	int* data = (int*)malloc(sizeof(int) * (8192+10));
	for (int i = 0; i < 8192; i++)//动态分配的数据需要手动初始化
	{
		if (data)//警告，因为 malloc 如果可用内存不足，对的调用可能会返回 null：使用前需要验证
		{
			//*(data++) = 0;//bug 数组越界，导致free时报错，产生断点
			data[i] = 0;
			
		}
		
	}
		
	int ip = 0, flag = 0, ir = 0;

	read(code);	//读取指令 
	analyze(code, data, ax, &ip, &ir, &flag); //分析 执行指令
	output(&ip, code, data);
	free(code);
	free(data);
	system("pause");///注意提交时要删除
}
