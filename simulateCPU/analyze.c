#include"simulate.h"

//���� 
//ָ�� �Ĵ��� ir 	ǰ 16λ 
//���� �Ĵ��� ip 	+4 
/*
����	���롪�����ݡ���ax�Ĵ�������
		*code  *data   ax[]
		ָ��ָ��or������������� ָ��Ĵ桪�� ��־�Ĵ�
		*ip							*ir			*flag
����	���� ����Ԫ�أ�����operate ����dest & source ��������  ����operate �ֹ�
����ֵ	NULL
*/
void analyze(char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	int i, head;
	int operate = 1, dest, source, imm;
	while (operate != 0) {
		head = (*ip) / 4 * 33;				//head ��ʼ�����λ�� ���ļ��ж�ȡ���ַ�Ҳ����ÿһ��ĩβ�Ļس��� \n
		operate = btod(code, head, 8); 		//������ 
		head = (*ip) / 4 * 33 + 8;
		dest = btod(code, head, 4); 	//ǰ���� 
		head = (*ip) / 4 * 33 + 8 + 4;
		source = btod(code, head, 4); 	//����� 
		head = (*ip) / 4 * 33 + 16;
		imm = btod(code, head, 16);	//������ 

		*ip = (*ip) + 4; //��������� ���� 		
		*ir = operate * 256 + dest * 16 + source;  //ָ��Ĵ���  16 bit

		division(operate, dest, source, imm, code, data, ax, ip, ir, flag);//�ֹ� 

		//updata���� 
		printf("ip = %d\nflag = %d\nir = %d\n", *ip, *flag, *ir);
		for (i = 1; i <= 4; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n");
		for (i = 5; i <= 8; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n\n");//���ύʱҪɾ��һ���س���

	}
}