//#include<stdio.h> 
//#include<stdlib.h>

/*
��תָ��
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   source		imm
	���롪�����ݡ����Ĵ���
	*code  *data   ax[]
	���������-- ָ��Ĵ�-- ��־�Ĵ�
	*ip			*ir		*flag
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void jmp(int operate, int dest, int source, int imm
	, char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	if (source == 0)
	{
		*ip += imm - 4;
	}
	if (source == 1)
	{
		if (*flag == 0)
			*ip += imm - 4;
	}
	if (source == 2)
	{
		if (*flag == 1)
			*ip += imm - 4;
	}
	if (source == 3)
	{
		if (*flag == -1)
			*ip += imm - 4;
	}
}