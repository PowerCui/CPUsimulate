#ifndef simulate
#define simulate
#include<stdio.h> 
#include<stdlib.h>
#include<Windows.h>//线程函数需要的操作系统函数
#include<process.h>//线程函数头文件
#define TICKETS 100
#define CODESEG_1 0
#define CODESEG_2 256
HANDLE hMutex;//互斥对象句柄
HANDLE hMutex_op_lock;//输出前锁，输出后释放
char* _code;


void read(char* code, char* filename, int* data);//读取指令 
void analyze(char* code, int* data, int ax[], int* ip, int* ir, int* flag, int* id);//分析 
void division(int operate, int dest, int src, int imm
	, int* data, int ax[], int* ip, int* flag, int* id);//operate分工 
void output(char* code, int* data);//输出 
int btod(char* code, int head, int n);//二进制转十进制 

void mov(int dest, int src, int imm, int* data, int ax[]);//数据传送
void calculate(int operate, int dest, int src, int imm, int* data, int ax[]); //算数 
void logic(int operate, int dest, int src, int imm, int* data, int ax[]);//逻辑   log 与系统函数冲突修改 数学计算
void cmp(int dest, int src, int imm, int* data, int ax[], int* flag);//比较
void jmp(int src, int imm, int* ip, int* flag);//跳转
void stdin_out(int operate, int dest, int ax[], int* id);//输入输出 
#endif // !simulate.h


