#include"simulate.h"

//代码，数据，输出 
/*
参数	 指令指针—— 代码——数据
	*ip		*code  *data
功能	输出8*16代码，16*16数据 （以十进制）
返回值 	NULL
*/
void output(char* code, int* data)
{
	int cnt, operate, head, i;
	operate = 1;
	cnt = 0;
	int ip = 0;
	//代码段  
	printf("\ncodeSegment :\n");
	//单核输出
	/*while (operate != 0)
	{
		head = (ip) / 4 * 33;
		operate = btod(code, head, 32);
		printf("%d ", operate);
		ip = (ip) + 4;
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
	}*/
	//多核输出
	while (operate != 0)
	{
		head = (ip) / 4 * 33;
		operate = btod(code, head, 32);
		printf("%d ", operate);
		ip = (ip)+4;
		cnt++;
		if (cnt % 8 == 0)
			printf("\n");
	}
	for (i = 8 * 8 - cnt; i > 0; i--)
	{

		printf("0 ");
		cnt++;
		if (cnt % 8 == 0)
			printf("\n");
	}
	ip = 4 * CODESEG_2;
	head = (ip) / 4 * 33;
	if (code[CODESEG_2] != NULL)
		operate = btod(code, head, 32);
	while (operate != 0)
	{
		head = (ip) / 4 * 33;
		operate = btod(code, head, 32);
		printf("%d ", operate);
		ip = (ip)+4;
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
	//数据段 
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