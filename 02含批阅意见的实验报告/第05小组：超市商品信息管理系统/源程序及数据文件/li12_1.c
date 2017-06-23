 /*�� file.h�ļ����������£�*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"staff.h"
void printHead()      /*��ӡ��Ʒ��Ϣ�ı�ͷ*/
{
	printf("%10s%10s%12s%10s%10s%10s%8s\n","���","����","����","�۸�","���","������","����");
}
void menu()         /*����˵�����*/
{
	printf("*******1.��ʾ��Ʒ������Ϣ*******\n");
	printf("*******2.��Ʒ������Ϣ����*******\n");
	printf("*******3.������������*******\n");
	printf("*******4.��ѯ��Ʒ��Ϣ*******\n");
	printf("*******5.��Ʒ����*******\n");
	printf("*******0.�˳�*******\n");
}
void menuBase()     /*2��������Ϣ����˵�����*/
{
	printf("*******1.�����Ʒ��Ϣ*******\n");
	printf("*******2.ɾ����Ʒ��Ϣ*******\n");
	printf("*******3.�޸���Ʒ��Ϣ*******\n");
	printf("*******0.�����ϲ�˵�*******\n");
}
void menuSearch()    /*3������������ѯ�˵�����*/
{
	printf("*******1.����Ų�ѯ*******\n");
	printf("*******2.�����Ʋ�ѯ*******\n");
	printf("*******3.������ѯ*******\n");
	printf("*******0.�����ϲ�˵�*******\n");
}
int baseManage(Staff sta[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{
	int choice,t,find[NUM];
	Staff s;
	do
	{
		menuBase();                  /*��ʾ��Ӧ�Ķ����˵�*/
		printf("��ѡ��Ҫִ�еĲ���:\n");
		scanf("%d",&choice);	          /*����ѡ��*/
		switch(choice)
		{
		case 1: readSta(&s,1);       /*����һ�����������Ʒ��¼*/
			n=insertSta(sta,n,s);   /*���ú���������Ʒ��¼*/
			break;
		case 2:printf("������Ҫɾ������Ʒ��ţ�\n");
			scanf("%ld",&s.num);  /*����һ����ɾ������Ʒ���*/
			n=deleteSta(sta,n,s);  /*���ú���ɾ��ָ��ѧ�ŵ�ѧ����¼*/
			break;
		case 3:
			printf("������Ҫ�޸ĵ���Ʒ��ţ�\n");
			scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ʒ���*/
			t=searchSta(sta,n,s,1,find); /*���ú�������ָ����ŵ���Ʒ��¼*/
			if(t)                 /*����ñ�ŵļ�¼����*/
			{
				readSta(&s,1);   /*����һ����������Ʒ��¼��Ϣ*/
				sta[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/
			}
			else                 /*����ñ�ŵļ�¼������*/
				printf("����Ʒ������\n"); /*�����ʾ��Ϣ*/
			break;
		case 0:break;
		}
	}while(choice);
	return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void searchManage(Staff sta[],int n)               /*�ú�����ɸ���������ѯ����*/
{
	int i,choice,findnum,f[NUM];
Staff s;
	do
	{
		menuSearch();                         /*��ʾ��Ӧ�Ķ����˵�*/
		printf("��ѡ��Ҫִ�еĲ���:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("������Ҫ��ѯ����Ʒ���:\n");
			scanf("%ld",&s.num);         /*�������ѯ��Ʒ�ı��*/
			break;
		case 2:printf("������Ҫ��ѯ����Ʒ����:\n");
			scanf("%s",s.name);	          /*�������ѯ��Ʒ������*/
			break;
		case 3:printf("������Ҫ��ѯ����Ʒ���:\n");
			scanf("%s",s.kind);          /*�������ѯ��Ʒ�����*/
			break;
		case 0:break;
		}
		if(choice>=1&&choice<=3)
		{
			findnum=searchSta(sta,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
			if(findnum)				     /*������ҳɹ�*/
			{
				printHead();                  /*��ӡ��ͷ*/
				for(i=0;i<findnum;i++)         /*ѭ������f������±�*/
		printSta(&sta[f[i]],1);      /*ÿ�����һ����¼*/
			}
			else
				printf("�ü�¼������!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		}
	}while(choice);
}
int runMain(Staff sta[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
	Staff s;
	switch(choice)
	{
	case 1:printHead();           /* 1. ��ʾ������Ϣ*/
		sortSta(sta,n,1);         /*�������С�����˳�������¼*/ 
		printSta(sta,n);          /*�������С�����˳��������м�¼*/
		break;
	case 2:n=baseManage(sta,n);    /* 2. ������Ϣ����*/
		break;
	case 3:calcuRank(sta,n);      /* 3. ������������*/
	    break;
	case 4:searchManage(sta,n);     /* 4. ����������ѯ*/
		break;
	case 5:sellSta(sta,n,s);     /* 5. ��Ʒ����*/
			break;
	case 0:break;
	}
	return n;
}

int main()
{
	char str[10];    /*����һ�����������洢������ַ���*/
	char *gets(char *p);    
    do
	{	
	    int i=0;
		printf("���������룺");
		gets(str);
	}while(check(str)==0);    /*����check�����Ƚ�������������趨�õ�����*/
	Staff sta[NUM];                /*����ʵ��һά����洢��Ʒ��¼*/
	int choice,n;
	n=readFile(sta);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	if(!n)                          /*���ԭ�����ļ�Ϊ��*/
	{
		n=creatFile(sta);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	}
	do
	{
		menu();                      /*��ʾ���˵�*/
		printf("���������ѡ��:");
		scanf("%d",&choice);
		if(choice>=0&&choice<=5)
			n=runMain(sta,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
		else
			printf("����������ٴ�����!\n");
	}while(choice);
	sortSta(sta,n,1);                   /*�����ļ�ǰ�������С��������*/
	saveFile(sta,n);                   /*����������ļ�*/
	
	return 0;
}


			



	


