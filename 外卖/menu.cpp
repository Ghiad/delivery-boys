#include"rider.h"
#include"menu.h"
#include"controller.h"
#include<stdio.h>
#include<stdlib.h>
//�������ֽṹ������ ��controller�ж����� 
//���嶩���ṹ������ 

Menu* creatmenulist(){//��ʼ������ 
	Menu *head;
	head=(Menu*)malloc(sizeof(Menu));
	if(head==NULL){
		printf("�ڴ治����Ӧ��ֹ����"); 
		return head;
	} 
	head->nextmenu=NULL;
	return head;
}

void addmenulist(int A,int object){//��Ӷ��� 
	Menu *current=Rider[A].waitlist;
	while(current->nextmenu!=NULL){//�ƶ�ָ��ָ���������һ�� 
		current=current->nextmenu;
	}
	current->nextmenu=&Menu[object];//��������������
	current=current->nextmenu;
	current->nextmenu=(Menu*)malloc(sizeof(Menu));//�����µĿռ� 
	current->nextmenu=NULL;
}

void buyrider(){//������
	int i;
	while(money>=400){//����400��Ϊ����һ�λ��壬��ֹ��������ûǮ�����Ʋ� 
		for(i=0;rider[i].exist==1;i++){};//�ж���Щ���ִ���
		rider=(Rider*)realloc(rider,(i+2)*sizeof(Rider)); 
		rider[i].exist=1;
		rider[i+1].exist=0;
		if(i==1){//��ʼ��,ʹnextmenuptr��Ϊÿ�����ֶ��������ͷָ�� 
			rider[0].waitlist=creatmenulist();
			rider[i].waitlist=creatmenulist();
		}
		else{ 
			rider[i].waitlist=creatmenulist();
		}
		money=money-300;
	}
}

void allocatemenu(int object){ //���䶩������ 
	int i,mintime,minrider;
	CalculatePath(&menu[object]);//����Ӧ�ü������� 
	mintime=rider[0].t1;//�˴�Ӧ��Ϊȷ����ʱ�䣬����������� 
	minrider=0;
	for(i=0;rider[i].exist!=0;i++){
		if(rider[i].t1<mintime){
		 	mintime=rider[i].t1;
		 	minrider=i;
		}
	}
	menu(object).p=&rider[minrider];//��ȷ���������䵽�Ǹ����� 
	menu(object).underline=minrider; 
	addmenulist(minrider,object);
}

void performance(){
	int i;
	for(i=0;rider[i].exist!=0;i++){
		printf("%d�����ֽӵ���%d �����%d ��ʱ��%d\n",i,rid[i].receive,rid[i].achieve,rid[i].overtime);

	}
}

void deletelist(int menunum){//�����͵�ʱɾ���ö��� 
	Menu *tmp,*current,*previous;
	current=rid[menu[menunum].underline].waitlist; 
	for(;*current!=menu[menunum];current=current->nextmenu){//Ѱ�ҵ�Ҫɾ���Ķ��� 
		previous=current;
	}
	tmp=current;
	current=current->nextmenu;
	previous->nextmenu=current;
	free(tmp);
}

void destory(){//�Ʋ�ʱ���ã� 
	int i;
	Menu *tmp,*current;
	for(;rid[i].exist!=0;i++){//�ͷ����ֶ������� 
		current=rid[i].waitptr;
		while(current!=NULL){
			tmp=current;
			current=current->nextmenu;
			free(tmp);
		}
	}
}
