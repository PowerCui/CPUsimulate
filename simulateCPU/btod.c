//#include<stdio.h> 
//#include<stdlib.h>

//������  ת  ʮ���� 
/*
����	    ���롪����ʼ λ�á���ת�� ƫ����
		*code   head  n
����	�� n λ �������� ת��Ϊ ʮ����
����ֵ	ʮ������
*/
int btod(char *code, int head, int n)
{
	int sum, i;
	/*
	printf("%d\n", head);
	for (i = head, sum = 0; i < head + n; i++)
	{
		printf("%c", code[i]);
	}
	printf("\n");
	*/
	for (i = head, sum = 0; i < head + n; i++)
	{
		sum = (sum) * 2 + (code[i] - '0');//   ����Խ��???

	}

	//��������Ҫ�жϣ��Ƿ�Ϊ���� ,����ת��
	if (n == 16) {
		if (sum <= 32767)
			return sum;
		else
			return sum - 65536;
	}
	else
		return sum;
}