#ifndef RIDER_H
#define  RIDER_H

#include<stdio.h>
#include<stdlib.h>
#define ridernum 10
#define menunum 20
	typedef struct menu{
		int x1;//���ֽӲ͵�ַ������
		int y1;//���ֽӲ͵�ַ������
		int x2;//�����Ͳ͵�ַ������
		int y2;//�����Ͳ͵�ַ������	
		int endtime;//��һ����ֹ��ʱ�� 
		int *p;//ָ�����ֵ�ָ��
		struct menu *nextmenu;
	}Menu;
	typedef struct rider{
		int exist;//�жϸ����ִ��� 
		int x;//���ֵ�ǰλ�ú�����
		int y;//���ֵ�ǰλ��������
		int t1;//������һ����ֹʱ��
		int receive;//���ֵĽӵ���
		int achieve;//���ֵ������ 
		int overtime;//���ֳ�ʱ�� 
		Menu *nextmenuptr; //���ֶ�������
	}Rider;
	
	//������ʻ·�����㷨����
	void allocatemenu(Menu,Rider []); //���䶩������ 
	void performance(Rider []);//��ӡÿλ���ֵĽӵ��������������ʱ��
	void buyrider(Rider [],int *money);//������ 
	Rider* creatmenulist(int,Rider []);
	void addmenulist();
	
	extern Menu menu[menunum];
	extern Rider rid[ridernum];
#endif 
