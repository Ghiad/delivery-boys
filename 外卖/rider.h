#ifndef RIDER_H
#define  RIDER_H

#include<stdio.h>
#include<stdlib.h>
#define ridernum 10
#define menunum 20
typedef struct rider{
	int exist;//�жϸ����ִ��� 
	int x;//���ֵ�ǰλ�ú�����
	int y;//���ֵ�ǰλ��������
	int t1;//������һ����ֹʱ��
	int receive;//���ֵĽӵ���
	int achieve;//���ֵ������ 
	int overtime;//���ֳ�ʱ�� 
	struct rider* rodeptr;//����·������ 
	struct rider* menuptr; //���ֶ������� 
}Rider;
typedef struct menu{
	int x1;//���ֽӲ͵�ַ������
	int y1;//���ֽӲ͵�ַ������
	int x2;//�����Ͳ͵�ַ������
	int y2;//�����Ͳ͵�ַ������	
	int endtime;//��һ����ֹ��ʱ�� 
	int *p;//ָ�����ֵ�ָ��
}Menu;
//������ʻ·�����㷨����
int allocatemenu(Menu,Rider []); //���䶩������ 
void performance(Rider[]);//��ӡÿλ���ֵĽӵ��������������ʱ��
extern Menu menu[menunum];
extern Rider rid[ridernum];
#endif 
