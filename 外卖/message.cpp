#include<stdio.h>
#include"point.h"
#include"tools.h"
#include"message.h"
void printmessage(Message a){
	int i;
	SetCursorPosition(52,0);
	printf("当前钱数：%d\n",a.money);
	for(i=0;rider[i].exist==1;i++){ 
		printf("骑手%d的位置：(%d,%d)\n",i+1,rider[i].x,rider[i].y);
	} 
	printf("接单数：%d\n",a.sum);
	printf("完成数：%d\n",a.accomplish);
	printf("超时数：%d\n",a.overtime);
}
