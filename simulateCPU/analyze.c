#include"simulate.h"

//分析 
//指令 寄存器 ir 	前 16位 
//程序 寄存器 ip 	+4 
/*
参数	代码——数据——ax寄存器——
		*code  *data   ax[]
		指令指针or程序计数器—— 指令寄存—— 标志寄存
		*ip							*ir			*flag
功能	分析 各个元素（操作operate 对象dest & source 立即数）  根据operate 分工
返回值	NULL
*/
void analyze(char *code, int *data, int ax[], int* ip, int* ir, int* flag)
{
	int i, head;
	int operate = 1, dest, source, imm;
	while (operate != 0) {
		head = (*ip) / 4 * 33;				//head 开始翻译的位置 从文件中读取的字符也包括每一行末尾的回车符 \n
		operate = btod(code, head, 8); 		//操作码 
		head = (*ip) / 4 * 33 + 8;
		dest = btod(code, head, 4); 	//前对象 
		head = (*ip) / 4 * 33 + 8 + 4;
		source = btod(code, head, 4); 	//后对象 
		head = (*ip) / 4 * 33 + 16;
		imm = btod(code, head, 16);	//立即数 

		*ip = (*ip) + 4; //程序计数器 更新 		
		*ir = operate * 256 + dest * 16 + source;  //指令寄存器  16 bit

		division(operate, dest, source, imm, code, data, ax, ip, ir, flag);//分工 

		//updata更新 
		printf("ip = %d\nflag = %d\nir = %d\n", *ip, *flag, *ir);
		for (i = 1; i <= 4; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n");
		for (i = 5; i <= 8; i++) {
			printf("ax%d = %d ", i, ax[i]);
		}
		printf("\n\n");//、提交时要删除一个回车符

	}
}