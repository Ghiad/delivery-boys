#include"rider.h"
#include"message.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
Rider* creatmenulist(int minrider){//创建链表 
	
}
void allocatemenu(Menu a,Rider rid[ridernum]){ //分配订单函数 
	int i,mintime,minrider;
	mintime=rid[0].t1;
	minrider=0;
	for(i=0;rid[i]!=0;i++){//用路径函数确定时间 
		if(rid[i].t1<mintime){
		 	mintime=rid[0].t1;
		 	minrider=i;
		}
	}	
	creatmenulist(int minrider);
}
void buyrider(Rider *rid[ridernum],int *money){//买骑手
	int i;
	while(money>=300){
		for(i=0;rid[i].exist==1;i++){};//判断哪些骑手存在 
		*rid[i].exist=1;
		*money=*money-300; 
	}
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

