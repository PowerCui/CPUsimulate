#include"simulate.h"

//���룬���ݣ���� 
/*
����	 ָ��ָ�롪�� ���롪������
	*ip		*code  *data
����	���8*16���룬16*16���� ����ʮ���ƣ�
����ֵ 	NULL
*/
void output(int* ip, char* code, int* data)
{
	int cnt, operate, head, i;
	operate = 1;
	cnt = 0;
	*ip = 0;
	//�����  
	printf("\ncodeSegment :\n");
	while (operate != 0)
	{
		head = (*ip) / 4 * 33;
		operate = btod(code, head, 32);
		printf("%d ", operate);
		*ip = (*ip) + 4;
		cnt++;
		if (cnt % 8 == 0)
			printf("\n");
	}
	for (i = 16 * 8 - cnt; i > 0; i--)
	{
		printf("0 ");
		cnt++;
		if (cnt % 8 == 0)
			printf("\n");
	}
	//���ݶ� 
	printf("\ndataSegment :\n");
	cnt = 0;
	for (i = 0; i <= 16 * 16 - 1; i++)
	{
		printf("%d ", data[i]);
		cnt++;
		if (cnt % 16 == 0)
			printf("\n");
	}
}