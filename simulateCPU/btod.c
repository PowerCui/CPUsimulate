//#include<stdio.h> 
//#include<stdlib.h>

//二进制  转  十进制 
/*
参数	    代码——开始 位置——转换 偏置数
		*code   head  n
功能	将 n 位 二进制数 转化为 十进制
返回值	十进制数
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
		sum = (sum) * 2 + (code[i] - '0');//   数组越界???

	}

	//立即数需要判断，是否为负数 ,补码转码
	if (n == 16) {
		if (sum <= 32767)
			return sum;
		else
			return sum - 65536;
	}
	else
		return sum;
}