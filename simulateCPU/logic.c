//#include<stdio.h> 
//#include<stdlib.h>

/*
�߼�����ָ��
����	���񡪡�ǰ�������󡪡���������󡪡�������
	operate dest   src		imm
	���ݡ����Ĵ���
	 *data   ax[]
����	����operate ���� ��Ӧ�Ĳ���
����ֵ	NULL
*/
void logic(int operate, int dest, int src, int imm,  int *data, int ax[])
{
	//������  �Ĵ��� 
	if (src == 0) {
		switch (operate)
		{
		case 6:
			if (ax[dest] && imm)
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 7:
			if (ax[dest] || imm)
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 8:
			ax[dest] = !ax[dest];
			break;
		}
	}
	//�Ĵ��� ֮��Ĵ���
	else {
		switch (operate) {
		case 6:
			if (ax[dest] && data[(ax[src] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 7:
			if (ax[dest] || data[(ax[src] - 16384) / 2])
				ax[dest] = 1;
			else
				ax[dest] = 0;
			break;
		case 8:
			data[(ax[src] - 16384) / 2] = !data[(ax[src] - 16384) / 2];
			break;
		}
	}
}
