#include"rider.h"
#include<stdio.h>
#include<stdlib.h>
Rider rid[ridernum];
Menu menu[menunum];
int allocatemenu(Menu a,Rider rid[ridernum]){ //���䶩������ 
	
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
