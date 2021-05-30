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
//#include<Windows.h>//�̺߳�����Ҫ�Ĳ���ϵͳ����
//#include<process.h>//�̺߳���ͷ�ļ�

int new_sign = 0;
int exit_sign = 0;
typedef struct threadArgument
{
	char filename[32];
	long long address;
	int threadID;
	char* code;//ָ��Ĵ������⣬malloc������ڴ棬Ҫ���ã�����ֱ�Ӹ�ֵ����ֵ�����ٷ���Ƭ�ڴ�???
	int* data;
} THREADARGUMENT;

unsigned _stdcall onethread(void* pArguments)
{
	THREADARGUMENT* p;
	p = (THREADARGUMENT*)pArguments;
	hMutex = CreateMutex(NULL, FALSE, NULL);//�̷߳�Χ����Ч
	hMutex_op_lock = CreateMutex(NULL, FALSE, "op_lock");//��������� ���һ������ָ�������������֣��������� �ַ���

	int ax[9] = { 0 };
	int ip = 0, flag = 0, ir = 0, id = 0;
	id = p->threadID;
	char* filename = p->filename;
	int* data = p->data;
	char* code = p->code;

	//WaitForSingleObject(hMutex, INFINITE);
	//read(code, filename, data);	//��ȡָ�� //��Ϊ��ȡָ���λ���߳�����δ���ж�ȡ�������̼߳䷢���˾�������˽��˺����ƶ������߳�
	analyze(code, data, ax, &ip, &ir, &flag, &id); //���� ִ��ָ��

	//ReleaseMutex(hMutex);
	_endthreadex(0);
	return 0;
}

int main(void)
{
	HANDLE hThread1, hThread2;//���
	unsigned ThreadID1, ThreadID2;//�̱߳�ʶ��

	//HANDLE hMutex; //ȫ�ֱ���������������̷߳�Χ��createmutex

	THREADARGUMENT th1, th2;
	th1.address = CODESEG_1;
	th2.address = CODESEG_2;
	//*strcpy(th1.filename, "dict1.dic");
	//strcpy(th2.filename, "dict2.dic");  //dev �༭ʱ����� _s*****************************
	strcpy_s(th1.filename, 32 * sizeof(char), "dict1.dic");
	strcpy_s(th2.filename, 32 * sizeof(char), "dict2.dic");
	th1.threadID = 1;
	th2.threadID = 2;


	//char* _code = (char*)malloc(sizeof(char) * (16384 + 10));
	_code = (char*)malloc(sizeof(char) * (16384 + 10));
	int* data = (int*)malloc(sizeof(int) * (8192 + 10));
	for (int i = 0; i < 8192; i++)//��̬�����������Ҫ�ֶ���ʼ��
	{
		if (data)//���棬��Ϊ malloc ��������ڴ治�㣬�Եĵ��ÿ��ܻ᷵�� null��ʹ��ǰ��Ҫ��֤
		{
			//*(data++) = 0;//bug ����Խ�磬����freeʱ���������ϵ�
			data[i] = 0;
		}
	}
	if (data)
		data[0] = TICKETS;

	//��codesegment ���г�ʼ��
	for (int i = 0; i < 16384; i++)//��̬�����������Ҫ�ֶ���ʼ��
	{
		if (_code)//ȷ����Խ�� �����棬��Ϊ malloc ��������ڴ治�㣬�Եĵ��ÿ��ܻ᷵�� null��ʹ��ǰ��Ҫ��֤
		{
			//*(data++) = 0;//bug ����Խ�磬����freeʱ���������ϵ�
			_code[i] = '0';
		}
	}

	th1.code = _code + th1.address*33;//  ��������Ҫƥ�� long 32λ longlong 64bit ָ����Ȼ 64bit 
	th1.data = data;
	th2.code = _code + th2.address*33;//�ڴ������ң�256Ϊָ����Ե�ַ��ÿһ��ָ��32λ���������ڴ�ʵ�ʵ�ַ���ڴ水λ�洢��
	th2.data = data;

	read(th1.code, th1.filename, th1.data);	//��ȡָ�� //��Ϊ��ȡָ���λ���߳�����δ���ж�ȡ�������̼߳䷢���˾�������˽��˺����ƶ������߳�
	read(th2.code, th2.filename, th2.data);	//��ȡָ�� //��Ϊ��ȡָ���λ���߳�����δ���ж�ȡ�������̼߳䷢���˾�������˽��˺����ƶ������߳�


	hThread1 = (HANDLE)_beginthreadex(NULL, 0, onethread, (void*)&th1, 0, &ThreadID1);
	hThread2 = (HANDLE)_beginthreadex(NULL, 0, onethread, (void*)&th2, 0, &ThreadID2);
	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);

	output(_code, data);

	free(_code);
	free(data);
	system("pause");///ע���ύʱҪɾ��
	return 0;
}
