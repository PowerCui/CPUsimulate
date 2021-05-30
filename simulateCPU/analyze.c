#include"simulate.h"

//���� 
//ָ�� �Ĵ��� ir 	ǰ 16λ 
//���� �Ĵ��� ip 	+4 
/*
����	���롪�����ݡ���ax�Ĵ�������
	*code  *data   ax[]
	������������� ָ��Ĵ桪�� ��־�Ĵ�
	*ip				*ir			*flag
����	���� ����Ԫ�أ�����operate ����dest & src ��������  ����operate �ֹ�
����ֵ	NULL
*/
void analyze(char* code, int* data, int ax[], int* ip, int* ir, int* flag, int* id)
{
	
	//WaitForSingleObject(hMutex_op_lock, INFINITE);//������룬��������һ�β�������������һ���������
	int i, head;
	int operate = 1, dest, src, imm;
	while (operate != 0)
	{
		head = (*ip) / 4 * 33;				//head ��ʼ�����λ�� ���ļ��ж�ȡ���ַ�Ҳ����ÿһ��ĩβ�Ļس��� \n
		operate = btod(code, head, 8); 		//������ 
		head = (*ip) / 4 * 33 + 8;
		dest = btod(code, head, 4); 	//ǰ���� 
		head = (*ip) / 4 * 33 + 8 + 4;
		src = btod(code, head, 4); 	//����� 
		head = (*ip) / 4 * 33 + 16;
		imm = btod(code, head, 16);	//������ 

		*ip = (*ip) + 4; //��������� ���� 		
		*ir = operate * 256 + dest * 16 + src;  //ָ��Ĵ���  16 bit

		division(operate, dest, src, imm, data, ax, ip, flag,id);//������ת 

		WaitForSingleObject(hMutex_op_lock, INFINITE); //���ǰ����
		printf("-----------------------------------\n");
		printf("id = %d\nip = %d\nflag = %d\nir = %d\n", *id, *ip, *flag, *ir);
		for (i = 1; i <= 4; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n");
		for (i = 5; i <= 8; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n");//���ύʱֻ��һ���س���
		ReleaseMutex(hMutex_op_lock);//�����������
	}
	
}