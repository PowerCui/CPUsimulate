#include"simulate.h"
//#include<Windows.h>//�̺߳�����Ҫ�Ĳ���ϵͳ�ĺ��� ��  HANDLE
//extern HANDLE hMutex;

//������ת
/*
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   src		imm
	���롪�����ݡ����Ĵ���
	*code  *data   ax[]
	���������-- ָ��Ĵ�-- ��־�Ĵ�
	*ip			*ir		*flag
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void division(int operate, int dest, int src, int imm, int* data, int ax[], int* ip, int* flag, int* id)
{
	switch (operate) {
	case 1://���ݴ��� 
		mov(dest, src, imm, data, ax);
		break;
	case 2:case 3:case 4:case 5://�������� 
		calculate(operate, dest, src, imm, data, ax);
		break;
	case 6:case 7:case 8://�߼����� 
		logic(operate, dest, src, imm, data, ax);
		break;
	case 9://�Ƚ� 
		cmp(dest, src, imm, data, ax, flag);
		break;
	case 10://��ת 
		jmp(src, imm, ip, flag);
		break;
	case 11:case 12://������� 
		stdin_out(operate, dest, ax, id);
		break;
	case 13:
		WaitForSingleObject(hMutex, INFINITE);//��ס�ڴ�
		break;
	case 14:
		ReleaseMutex(hMutex);//�ͷ��ڴ�
		break;
	case 15:
		Sleep(imm);//����������(ms)ʱ��
		break;
	default:
		break;
	}
}