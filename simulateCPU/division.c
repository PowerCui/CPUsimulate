#include"simulate.h"

//������ת
/*
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   source		imm
	���롪�����ݡ����Ĵ���
	*code  *data   ax[]
	���������-- ָ��Ĵ�-- ��־�Ĵ�
	*ip			*ir		*flag
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void division(int operate, int dest, int source, int imm, int *data, int ax[], int* ip,  int* flag)
{
	switch (operate) {
	case 1://���ݴ��� 
		mov(dest, source, imm, data, ax);
		break;
	case 2:case 3:case 4:case 5://�������� 
		calculate(operate, dest, source, imm, data, ax);
		break;
	case 6:case 7:case 8://�߼����� 
		log(operate, dest, source, imm, data, ax);
		break;
	case 9://�Ƚ� 
		cmp(dest, source,imm,data,ax,flag);
		break;
	case 10://��ת 
		jmp(source, imm, ip, flag);
		break;
	case 11:case 12://������� 
		stdin_out(operate, dest, ax);
		break;
	default:
		break;
	}
}