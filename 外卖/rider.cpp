#include"rider.h"
//#include"message.h"
#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
//定义骑手结构体数组 在controller中定义了 
//定义订单结构体数组 
Menu* creatmenulist(int rid){//初始化链表 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("内存不够"); 
		return head;
	} 
	*head->p=rid;
	head->nextmenu=NULL;
	return head;
}
void addmenulist(int A,Menu *object){//添加订单 
	Menu *current=Rider[A].nextmenuptr;
	while(current->nextmenu!=NULL){//移动指针指向链表最后一个 
		current=current->nextmenu;
	}
	current->nextmenu=object;//将订单加入链表 
	current=current->nextmenu;
	current->nextmenu=NULL;
}
int buyrider(){//买骑手
	int i;
	if(money>=300){
		for(i=0;rid[i].exist==1;i++){};//判断哪些骑手存在
		rid=(Rider*)realloc(rid,(i+1)*sizeof(Rider)); 
		rid[i].exist=1;
		if(i==1){//初始化,使nextmenuptr成为每个骑手订单链表的头指针 
			rid[0].nextmenuptr=creatmenulist(0);
			rid[i].nextmenuptr=creatmenulist(i);
		}
		else{ 
			rid[i].nextmenuptr=creatmenulist(i);
		}
		money=money-300;
		return i; 
	}
	else
		return -1;
}
void performance(){
	int i;
	for(i=0;rid[i].exist!=0;i++){
		printf("%d号骑手接单数%d\n",i,rid[i].receive);
		printf("%d号骑手完成数%d\n",i,rid[i].achieve);
		printf("%d号骑手超时数%d\n",i,rid[i].overtime);
		printf("\n");
	}
}

void allocatemenu(Menu *object){ //分配订单函数 
	int i,mintime,minrider;
	//用路径函数确定时间 
	mintime=rid[0].t1;
	minrider=0;
	for(i=0;rid[i].exist!=0;i++){
		if(rid[i].t1<mintime){
		 	mintime=rid[0].t1;
		 	minrider=i;
		}
	}	
	int newrider;
	if(mintime>=30){//如果都现有骑手都超时 
		newrider=buyrider(rid);//买一个新骑手 
		if(newrider!=-1)
			addmenulist(newrider,object); 
		else  
			addmenulist(rid[minrider],object);//钱不够，返回时间最少的那个骑手 
	}
	else{
		addmenulist(rid[minrider],object);
	}
}
