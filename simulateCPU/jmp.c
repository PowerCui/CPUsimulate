//#include<stdio.h> 
//#include<stdlib.h>

/*
��תָ��
����	�������󡪡�������
	source		imm	
	���������- ��־�Ĵ�
	*ip			*flag
����ֵ	NULL
*/
void jmp(int source, int imm,int* ip, int* flag)
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