#include"rider.h"
#include"menu.h"
#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
//定义骑手结构体数组 在controller中定义了 
//定义订单结构体数组 

Menu* creatmenulist(){//初始化链表 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("内存不够，应终止程序"); 
		return head;
	} 
	head->nextmenu=NULL;
	return head;
}

void addmenulist(int A,int object){//添加订单 
	Menu *current=Rider[A].waitlist;
	while(current->nextmenu!=NULL){//移动指针指向链表最后一个 
		current=current->nextmenu;
	}
	current->nextmenu=&Menu[object];//将订单加入链表
	current=current->nextmenu;
	current->nextmenu=(Menu*)malloc(sizeof(Menu));//开创新的空间 
	current->nextmenu=NULL;
}

void buyrider(){//买骑手
	int i;
	while(money>=400){//大于400是为了留一段缓冲，防止买完骑手没钱导致破产 
		for(i=0;rider[i].exist==1;i++){};//判断哪些骑手存在
		rider=(Rider*)realloc(rider,(i+2)*sizeof(Rider)); 
		rider[i].exist=1;
		rider[i+1].exist=0;
		if(i==1){//初始化,使nextmenuptr成为每个骑手订单链表的头指针 
			rider[0].waitlist=creatmenulist();
			rider[i].waitlist=creatmenulist();
		}
		else{ 
			rider[i].waitlist=creatmenulist();
		}
		money=money-300;
	}
}

void allocatemenu(int object){ //分配订单函数 
	int i,mintime,minrider;
	CalculatePath(&menu[object]);//参数应该加入骑手 
	mintime=rider[0].t1;//此处应该为确定的时间，暂用这个代替 
	minrider=0;
	for(i=0;rider[i].exist!=0;i++){
		if(rider[i].t1<mintime){
		 	mintime=rider[i].t1;
		 	minrider=i;
		}
	}
	menu(object).p=&rider[minrider];//明确订单被分配到那个骑手 
	menu(object).underline=minrider; 
	addmenulist(minrider,object);
}

void performance(){
	int i;
	for(i=0;rider[i].exist!=0;i++){
		printf("%d号骑手接单数%d 完成数%d 超时数%d\n",i,rid[i].receive,rid[i].achieve,rid[i].overtime);

	}
}

void deletelist(int menunum){//订单送到时删除该订单 
	Menu *tmp,*current,*previous;
	current=rid[menu[menunum].underline].waitlist; 
	for(;*current!=menu[menunum];current=current->nextmenu){//寻找到要删除的订单 
		previous=current;
	}
	tmp=current;
	current=current->nextmenu;
	previous->nextmenu=current;
	free(tmp);
}

void destory(){//破产时调用？ 
	int i;
	Menu *tmp,*current;
	for(;rid[i].exist!=0;i++){//释放骑手订单链表 
		current=rid[i].waitptr;
		while(current!=NULL){
			tmp=current;
			current=current->nextmenu;
			free(tmp);
		}
	}
}
