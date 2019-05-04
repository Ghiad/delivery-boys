#include"rider.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
int allocatemenu(Menu a,Rider rid[ridernum]){ //分配订单函数 
	
}
void performance(Rider rid[ridernum]){
	int i;
	for(i=0;rid[i].exist!=0;i++){
		printf("%d号骑手接单数%d\n",i,rid[i].receive);
		printf("%d号骑手完成数%d\n",i,rid[i].achieve);
		printf("%d号骑手超时数%d\n",i,rid[i].overtime);
		printf("\n");
	}
}
