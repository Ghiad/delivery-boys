#include"rider.h"
#include"message.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
Rider* creatmenulist(Rider *rid){//初始化链表 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("内存不够"); 
		return head;
	} 
	head->p=rid;
	head->nextmenu=NULL;
}
void addmenulist(){//添加订单 
	
}
void allocatemenu(Menu a,Rider rid[ridernum]){ //分配订单函数 
	int i,mintime,minrider;
	//用路径函数确定时间 
	mintime=rid[0].t1;
	minrider=0;
	for(i=0;rid[i]!=0;i++){
		if(rid[i].t1<mintime){
		 	mintime=rid[0].t1;
		 	minrider=i;
		}
	}	
	if(rid[minrider].nextmenuptr==NULL)
		rid[minrider].nextmenuptr=creatmenulist(int minrider,rid,a);
	else
		addmenulist
}
void buyrider(Rider rid[ridernum],int *money){//买骑手
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

