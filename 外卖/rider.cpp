#include"rider.h"
//#include"message.h"
#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
//�������ֽṹ������ ��controller�ж����� 
//���嶩���ṹ������ 
Menu* creatmenulist(int rid){//��ʼ������ 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("�ڴ治��"); 
		return head;
	} 
	*head->p=rid;
	head->nextmenu=NULL;
	return head;
}
void addmenulist(int A,Menu *object){//��Ӷ��� 
	Menu *current=Rider[A].nextmenuptr;
	while(current->nextmenu!=NULL){//�ƶ�ָ��ָ���������һ�� 
		current=current->nextmenu;
	}
	current->nextmenu=object;//�������������� 
	current=current->nextmenu;
	current->nextmenu=NULL;
}
int buyrider(){//������
	int i;
	if(money>=300){
		for(i=0;rid[i].exist==1;i++){};//�ж���Щ���ִ���
		rid=(Rider*)realloc(rid,(i+1)*sizeof(Rider)); 
		rid[i].exist=1;
		if(i==1){//��ʼ��,ʹnextmenuptr��Ϊÿ�����ֶ��������ͷָ�� 
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
		printf("%d�����ֽӵ���%d\n",i,rid[i].receive);
		printf("%d�����������%d\n",i,rid[i].achieve);
		printf("%d�����ֳ�ʱ��%d\n",i,rid[i].overtime);
		printf("\n");
	}
}

void allocatemenu(Menu *object){ //���䶩������ 
	int i,mintime,minrider;
	//��·������ȷ��ʱ�� 
	mintime=rid[0].t1;
	minrider=0;
	for(i=0;rid[i].exist!=0;i++){
		if(rid[i].t1<mintime){
		 	mintime=rid[0].t1;
		 	minrider=i;
		}
	}	
	int newrider;
	if(mintime>=30){//������������ֶ���ʱ 
		newrider=buyrider(rid);//��һ�������� 
		if(newrider!=-1)
			addmenulist(newrider,object); 
		else  
			addmenulist(rid[minrider],object);//Ǯ����������ʱ�����ٵ��Ǹ����� 
	}
	else{
		addmenulist(rid[minrider],object);
	}
}
