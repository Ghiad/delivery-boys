#ifndef RIDER_H
#define  RIDER_H

#include"menu.h"
#include<stdio.h>
#include<stdlib.h>
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
	
	Rider allocatemenu(Menu,Rider []); //���䶩������ 
	
	//������ʻ·�����㷨����
	
	void performance(Rider []);//��ӡÿλ���ֵĽӵ��������������ʱ��
	int buyrider(Rider [],int *money);//������ 
	Menu* creatmenulist(int,Rider []);
	void addmenulist();
	extern Menu *menu;//���������ṹ������ 
	extern Rider *rid;//�������ֽṹ������ 
#endif 
