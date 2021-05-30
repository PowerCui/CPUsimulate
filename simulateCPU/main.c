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
//#include<Windows.h>//线程函数需要的操作系统函数
//#include<process.h>//线程函数头文件

int new_sign = 0;
int exit_sign = 0;
typedef struct threadArgument
{
	char filename[32];
	long long address;
	int threadID;
	char* code;//指针的传递问题，malloc分配的内存，要引用，不能直接赋值，赋值等于再分配片内存???
	int* data;
} THREADARGUMENT;

unsigned _stdcall onethread(void* pArguments)
{
	THREADARGUMENT* p;
	p = (THREADARGUMENT*)pArguments;
	hMutex = CreateMutex(NULL, FALSE, NULL);//线程范围内有效
	hMutex_op_lock = CreateMutex(NULL, FALSE, "op_lock");//输入输出锁 最后一个参数指定互斥对象的名字，数据类型 字符串

	int ax[9] = { 0 };
	int ip = 0, flag = 0, ir = 0, id = 0;
	id = p->threadID;
	char* filename = p->filename;
	int* data = p->data;
	char* code = p->code;

	//WaitForSingleObject(hMutex, INFINITE);
	//read(code, filename, data);	//读取指令 //因为读取指令函数位于线程内且未进行读取保护，线程间发生了竞争，因此将此函数移动到主线程
	analyze(code, data, ax, &ip, &ir, &flag, &id); //分析 执行指令

	//ReleaseMutex(hMutex);
	_endthreadex(0);
	return 0;
}

int main(void)
{
	HANDLE hThread1, hThread2;//句柄
	unsigned ThreadID1, ThreadID2;//线程标识号

	//HANDLE hMutex; //全局变量，定义错误在线程范围内createmutex

	THREADARGUMENT th1, th2;
	th1.address = CODESEG_1;
	th2.address = CODESEG_2;
	//*strcpy(th1.filename, "dict1.dic");
	//strcpy(th2.filename, "dict2.dic");  //dev 编辑时候更正 _s*****************************
	strcpy_s(th1.filename, 32 * sizeof(char), "dict1.dic");
	strcpy_s(th2.filename, 32 * sizeof(char), "dict2.dic");
	th1.threadID = 1;
	th2.threadID = 2;


	//char* _code = (char*)malloc(sizeof(char) * (16384 + 10));
	_code = (char*)malloc(sizeof(char) * (16384 + 10));
	int* data = (int*)malloc(sizeof(int) * (8192 + 10));
	for (int i = 0; i < 8192; i++)//动态分配的数据需要手动初始化
	{
		if (data)//警告，因为 malloc 如果可用内存不足，对的调用可能会返回 null：使用前需要验证
		{
			//*(data++) = 0;//bug 数组越界，导致free时报错，产生断点
			data[i] = 0;
		}
	}
	if (data)
		data[0] = TICKETS;

	//对codesegment 进行初始化
	for (int i = 0; i < 16384; i++)//动态分配的数据需要手动初始化
	{
		if (_code)//确保不越界 ；警告，因为 malloc 如果可用内存不足，对的调用可能会返回 null：使用前需要验证
		{
			//*(data++) = 0;//bug 数组越界，导致free时报错，产生断点
			_code[i] = '0';
		}
	}

	th1.code = _code + th1.address*33;//  数据类型要匹配 long 32位 longlong 64bit 指针显然 64bit 
	th1.data = data;
	th2.code = _code + th2.address*33;//内存管理混乱，256为指令相对地址（每一条指令32位），并非内存实际地址（内存按位存储）
	th2.data = data;

	read(th1.code, th1.filename, th1.data);	//读取指令 //因为读取指令函数位于线程内且未进行读取保护，线程间发生了竞争，因此将此函数移动到主线程
	read(th2.code, th2.filename, th2.data);	//读取指令 //因为读取指令函数位于线程内且未进行读取保护，线程间发生了竞争，因此将此函数移动到主线程


	hThread1 = (HANDLE)_beginthreadex(NULL, 0, onethread, (void*)&th1, 0, &ThreadID1);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, onethread, (void*)&th2, 0, &ThreadID2);
	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);

	output(_code, data);

	free(_code);
	free(data);
	system("pause");///注意提交时要删除
	return 0;
}
