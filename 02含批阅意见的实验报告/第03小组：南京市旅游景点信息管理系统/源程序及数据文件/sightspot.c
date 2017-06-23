/*��sightspot.c�ļ�����������*/
#include "sightspot.h"
#include <stdio.h>

int readSig(Sightspot  *sig , int n)          /*���뾰���¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i,num;
	int month;
	for (i=0;i<n;i++)
	{
		printf("Input one sightspot's information\n");
		printf("number:  \n");
	    scanf("%ld", &sig[i].number);
		if (sig[i].number==0) break;
		printf("name: \n");
		scanf("%s",sig[i].name);
		printf("place:  \n");
		scanf("%s",sig[i].place);
	    printf("������: \n");
	    scanf("%d",&sig[i].num);
	    printf("�·�: \n");
	    scanf("%d",&sig[i].month);
        sig[i].rank=0;      /*������Ҫ���������������㣬��ֵ��Ϊ0*/
	}
	printf("\n");
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printSig ( Sightspot  *sig , int n)       /*������о����¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld", sig[i].number);
		printf("%22s", sig[i].name);
		printf("%27s", sig[i].place);
		printf("%12d", sig[i].num);
		printf("%8d", sig[i].month);
	    printf("%12d\n", sig[i].rank);
	}
}

int equal(Sightspot s1,Sightspot s2,int condition)  /*����ж�����Sight spot��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����*/
		return s1.number==s2.number;
	else if (condition==2)                /*�������condition��ֵΪ2����ȽϾ�������*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ�������*/
		return s1.num==s2.num;
	else return 1;                       /*�����������1*/
} 

int larger(Sightspot s1,Sightspot s2,int condition)  /*����condition�����Ƚ����������¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ����*/
		return s1.number>s2.number;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ�������*/
		return s1.num>s2.num;	
	else return 1; /*�����������1*/
}

void reverse(Sightspot sig[],int n)             /*����Ԫ������*/
{
	int i;
	Sightspot temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=sig[i];
		sig[i]=sig[n-1-i];
		sig[n-1-i]=temp;
	}
}
void calcuRank(Sightspot sig[],int n)          /*�����������������о������������������ͬ��������ͬ*/
{
	int i ;                       
	sortSig(sig,n,2);                     /*�ȵ���sortSig�㷨������������С��������*/
	reverse(sig,n);                      /*�����ã����������ɴ�С������*/
	sig[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(sig[i],sig[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼������������*/
			sig[i].rank=sig[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			sig[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
	printSig(sig,n) ;
}
void sortSig(Sightspot sig[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Sightspot t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(sig[minpos],sig[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=sig[i];
			sig[i]=sig[minpos];
			sig[minpos]=t;
		}
	}
}

int searchSig(Sightspot sig[],int n,Sightspot s,int condition,int f[ ])  /*��sig��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(sig[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertSig(Sightspot sig[],int n,Sightspot s)              /*��sig����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortSig(sig,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(sig[i],s,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(sig[i],s,1))                    /*���s���ڵ�ǰԪ��sig[i]�����˳�ѭ��*/
		break;
		sig[i+1]=sig[i];                         /*����Ԫ��sig[i]����һ��λ��*/
	}
	sig[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteSig(Sightspot sig[],int n,Sightspot s)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(sig[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		sig[j]=sig[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}

