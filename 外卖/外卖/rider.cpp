#include"rider.h"
#include"message.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
Rider* creatmenulist(int minrider){//�������� 
	
}
void allocatemenu(Menu a,Rider rid[ridernum]){ //���䶩������ 
	int i,mintime,minrider;
	mintime=rid[0].t1;
	minrider=0;
	for(i=0;rid[i]!=0;i++){//��·������ȷ��ʱ�� 
		if(rid[i].t1<mintime){
		 	mintime=rid[0].t1;
		 	minrider=i;
		}
	}	
	creatmenulist(int minrider);
}
void buyrider(Rider *rid[ridernum],int *money){//������
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

