#include"simulate.h"

//��ȡָ�� 
/*
����	code
����	���ļ��ж�ȡ  ������ ָ��
����ֵ	NULL
*/
void read(char *code)
{
	int i = 0;
	//FILE* fPtr = fopen("dict.txt", "r");//�ύʱӦ�л�Ϊ���д���
	FILE* fPtr;
	fopen_s(&fPtr, "D:/Alpha/dict.txt", "r");
	if (fPtr == NULL) {
		printf("error\n");
	}
	else {
		for (i = 0; !feof(fPtr); i++)
		{
			code[i] = getc(fPtr);
		}
	}
	code[i] = '\0';//�ַ���ֵ  ʹ�õ����ţ�˫����"\0" ���к��壬���ַ���
	puts(code);
	printf("code[i]�е�i	%d\n", i);
	if (!fPtr)
		printf("open file fail");
	else
		fclose(fPtr);
}