#ifndef simulate
#define simulate
#include<stdio.h> 
#include<stdlib.h>

void read(char *code);//��ȡָ�� 
void analyze(char *code, int *data, int ax[], int* ip, int* ir, int* flag);//���� 
void division(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//operate�ֹ� 
void output(int* ip, char *code, int *data);//��� 
int btod(char *code, int head, int n);//������תʮ���� 

void mov(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//���ݴ���
void calculate(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag); //���� 
void log(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//�߼� 
void cmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//�Ƚ�
void jmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//��ת
void stdin_out(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag);//������� 
#endif // !simulate.h


