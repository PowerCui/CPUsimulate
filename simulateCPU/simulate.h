#ifndef simulate
#define simulate
#include<stdio.h> 
#include<stdlib.h>

void read(char *code);//��ȡָ�� 
void analyze(char *code, int *data, int ax[], int* ip, int* ir, int* flag);//���� 
void division(int operate, int dest, int source, int imm
	,int *data, int ax[], int* ip,int* flag);//operate�ֹ� 
void output(int* ip, char *code, int *data);//��� 
int btod(char *code, int head, int n);//������תʮ���� 

void mov(int dest, int source, int imm, int* data, int ax[]);//���ݴ���
void calculate(int operate, int dest, int source, int imm, int* data, int ax[]); //���� 
void log(int operate, int dest, int source, int imm, int* data, int ax[]);//�߼� 
void cmp(int dest, int source, int imm, int* data, int ax[], int* flag);//�Ƚ�
void jmp(int source, int imm, int* ip, int* flag);//��ת
void stdin_out(int operate, int dest, int ax[]);//������� 
#endif // !simulate.h


