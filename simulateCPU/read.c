#include"simulate.h"

//读取指令 
/*
参数	code
功能	从文件中读取  二进制 指令
返回值	NULL
*/
void read(char *code)
{
	int i = 0;
	//FILE* fPtr = fopen("dict.dic", "r");//提交时应切换为此行代码
	FILE* fPtr;									//提交时要注释
	fopen_s(&fPtr, "D:/Alpha/dict.txt", "r");//提交时要注释
	if (fPtr == NULL) {
		printf("error\n");
	}
	else {
		for (i = 0; !feof(fPtr); i++)
		{
			code[i] = getc(fPtr);
			if (code[i] == '#')
				break;
		}
	}
	code[i] = '\0';//字符赋值  使用单引号，双引号"\0" 另有含义，是字符串
	//puts(code);//提交时候要注释掉
	//printf("code[i]中的i	%d\n", i);//提交时要注释
	if (!fPtr)
		printf("open file fail");
	else
		fclose(fPtr);
}