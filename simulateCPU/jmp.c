//#include<stdio.h> 
//#include<stdlib.h>

/*
��תָ��
����	�������󡪡�������
	src		imm	
	���������- ��־�Ĵ�
	*ip			*flag
����ֵ	NULL
*/
void jmp(int src, int imm,int* ip, int* flag)
{
	if (src == 0)
	{
		*ip += imm - 4;
	}
	if (src == 1)
	{
		if (*flag == 0)
			*ip += imm - 4;
	}
	if (src == 2)
	{
		if (*flag == 1)
			*ip += imm - 4;
	}
	if (src == 3)
	{
		if (*flag == -1)
			*ip += imm - 4;
	}
}