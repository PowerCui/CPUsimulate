#include "simulate.h"
//#include<stdio.h> //�ļ���ȡ ����
//#include<stdlib.h>free malloc�Ȳ���

/*
��׼�������
����	���񡪡�ǰ��������-���ݼĴ���
	operate dest   ax[]
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void stdin_out(int operate, int dest, int ax[],int* id)
{
	switch (operate) 
	{
		case 11:
		{
			printf("in:\n");
			scanf_s("%d", &ax[dest]);// ע���ύʱ �滻scanf_s
		}			
		break;
		case 12:
		{
			/*printf("\n********************\n");
			printf("id = ");
			printf("%d    ", *id);
			printf("out: ");
			printf("%d   *\n", ax[dest]);
			printf("********************\n\n");*/
			//һ���������ֹ�߳̾��������������
			printf("\n********************\nid = %d    out: %d   *\n********************\n\n", *id, ax[dest]);
		}
		break;
	}
}