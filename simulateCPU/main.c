/*
������main
 1>ȡָ����浽�Ĵ���
 2>����ָ�ִ��ָ��
 3>������룬����

���� code
���� data
ָ�� �Ĵ��� ir 	ǰ 16λ
��������� ip 	+4
��־ �Ĵ��� flag   		       
4������ �Ĵ��� ax1~ax4 
4����ַ �Ĵ��� ax5-ax8 ��ŵ�ַ
ax[i]  �� i ���Ĵ���
*/

#include"simulate.h"

int main(void)
{
	char* code = (char*)malloc(sizeof(char) * (16384+10));
	int ax[9] = { 0 };
	int* data = (int*)malloc(sizeof(int) * (8192+10));
	for (int i = 0; i < 8192; i++)//��̬�����������Ҫ�ֶ���ʼ��
	{
		if (data)//���棬��Ϊ malloc ��������ڴ治�㣬�Եĵ��ÿ��ܻ᷵�� null��ʹ��ǰ��Ҫ��֤
		{
			//*(data++) = 0;//bug ����Խ�磬����freeʱ���������ϵ�
			data[i] = 0;
			
		}
		
	}
		
	int ip = 0, flag = 0, ir = 0;

	read(code);	//��ȡָ�� 
	analyze(code, data, ax, &ip, &ir, &flag); //���� ִ��ָ��
	output(&ip, code, data);
	free(code);
	free(data);
	system("pause");///ע���ύʱҪɾ��
}
