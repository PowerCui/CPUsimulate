#ifndef simulate
#define simulate
#include<stdio.h> 
#include<stdlib.h>
#include<Windows.h>//�̺߳�����Ҫ�Ĳ���ϵͳ����
#include<process.h>//�̺߳���ͷ�ļ�
#define TICKETS 100
#define CODESEG_1 0
#define CODESEG_2 256
HANDLE hMutex;//���������
HANDLE hMutex_op_lock;//���ǰ����������ͷ�
char* _code;


void read(char* code, char* filename, int* data);//��ȡָ�� 
void analyze(char* code, int* data, int ax[], int* ip, int* ir, int* flag, int* id);//���� 
void division(int operate, int dest, int src, int imm
	, int* data, int ax[], int* ip, int* flag, int* id);//operate�ֹ� 
void output(char* code, int* data);//��� 
int btod(char* code, int head, int n);//������תʮ���� 

void mov(int dest, int src, int imm, int* data, int ax[]);//���ݴ���
void calculate(int operate, int dest, int src, int imm, int* data, int ax[]); //���� 
void logic(int operate, int dest, int src, int imm, int* data, int ax[]);//�߼�   log ��ϵͳ������ͻ�޸� ��ѧ����
void cmp(int dest, int src, int imm, int* data, int ax[], int* flag);//�Ƚ�
void jmp(int src, int imm, int* ip, int* flag);//��ת
void stdin_out(int operate, int dest, int ax[], int* id);//������� 
#endif // !simulate.h


