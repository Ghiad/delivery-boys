#ifndef RIDER_H
#define  RIDER_H

#include<stdio.h>
#include<stdlib.h>
	typedef struct menu{
			int x1;//���ֽӲ͵�ַ������
			int y1;//���ֽӲ͵�ַ������
			int x2;//�����Ͳ͵�ַ������
			int y2;//�����Ͳ͵�ַ������	
			int endtime;//��һ����ֹ��ʱ�� 
			int *p;//ָ�����ֵ�ָ��
			int take;//�ж������Ƿ�ȡ�� 
			int finish;//�ж������Ƿ��͵����� 
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
	
	int buyrider();//������
	void allocatemenu(Menu*); //���䶩������ 
	Menu* creatmenulist(int);//��ʼ������ 
	void addmenulist(int,Menu*);//��������������� 
	//������ʻ·�����㷨����
	void performance();//��ӡÿλ���ֵĽӵ��������������ʱ��
	
	extern Menu *menu;//���������ṹ������ 
	extern Rider *rid;//�������ֽṹ������ 
#endif 
