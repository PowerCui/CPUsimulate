#include<stdio.h> 
#include<stdlib.h>

/*
��׼�������
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   source		imm
	���롪�����ݡ����Ĵ���
	*code  *data   ax[]
	���������-- ָ��Ĵ�-- ��־�Ĵ�
	*ip			*ir		*flag
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void stdin_out(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	switch (operate) {
	case 11:
		printf("in:\n");
		scanf_s("%d", &ax[dest]);// ע���ύʱ �滻scanf_s
		break;
	case 12:
		printf("out: ");
		printf("%d\n", ax[dest]);
	}
}