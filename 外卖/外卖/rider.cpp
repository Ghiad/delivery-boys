#include"rider.h"
#include"message.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
Rider* creatmenulist(Rider *rid){//��ʼ������ 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("�ڴ治��"); 
		return head;
	} 
	head->p=rid;
	head->nextmenu=NULL;
}
void addmenulist(){//��Ӷ��� 
	
}
void allocatemenu(Menu a,Rider rid[ridernum]){ //���䶩������ 
	int i,mintime,minrider;
	//��·������ȷ��ʱ�� 
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
void buyrider(Rider rid[ridernum],int *money){//������
	int i;
	while(money>=300){
		for(i=0;rid[i].exist==1;i++){};//�ж���Щ���ִ��� 
		*rid[i].exist=1;
		*money=*money-300; 
	}
}
void performance(Rider rid[ridernum]){
	int i;
	for(i=0;rid[i].exist!=0;i++){
		printf("%d�����ֽӵ���%d\n",i,rid[i].receive);
		printf("%d�����������%d\n",i,rid[i].achieve);
		printf("%d�����ֳ�ʱ��%d\n",i,rid[i].overtime);
		printf("\n");
	}
}

