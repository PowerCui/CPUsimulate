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
	//FILE* fPtr = fopen("dict.dic", "r");//�ύʱӦ�л�Ϊ���д���
	FILE* fPtr;									//�ύʱҪע��
	fopen_s(&fPtr, "D:/Alpha/dict.txt", "r");//�ύʱҪע��
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
	code[i] = '\0';//�ַ���ֵ  ʹ�õ����ţ�˫����"\0" ���к��壬���ַ���
	//puts(code);//�ύʱ��Ҫע�͵�
	//printf("code[i]�е�i	%d\n", i);//�ύʱҪע��
	if (!fPtr)
		printf("open file fail");
	else
		fclose(fPtr);
}