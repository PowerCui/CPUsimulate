#ifndef simulate
#define simulate
#include<stdio.h> 
#include<stdlib.h>

void read(char *code);//读取指令 
void analyze(char *code, int *data, int ax[], int* ip, int* ir, int* flag);//分析 
void division(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//operate分工 
void output(int* ip, char *code, int *data);//输出 
int btod(char *code, int head, int n);//二进制转十进制 

void mov(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//数据传送
void calculate(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag); //算数 
void log(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//逻辑 
void cmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//比较
void jmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//跳转
void stdin_out(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//输入输出 
#endif // !simulate.h


