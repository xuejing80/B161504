/*��car.c�ļ�����������*/
#include "car.h"
#include <stdio.h>

int readC(CAR  *c , int n)          /*����������¼ֵ�������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{    
		printf("������һ��������Ϣ\n");
		printf("�������:  ");
		printf("(�밴��˳��������)");
	        scanf("%ld", &c[i].num);	
		printf("��������: ");
		scanf("%s",c[i].name);	
		printf("ԭ�ۣ�");
                scanf("%ld",&c[i].p1);
                printf("�ּۣ�");
                scanf("%ld",&c[i].p2);
    	        c[i].p3=c[i].p1-c[i].p2; 
				c[i].rank=0;				
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printC ( CAR  *c , int n)       /*�������������¼��ֵ*/
{	
    int i;
	for (i=0;i<n;i++)
	{
		printf("%5ld  ", c[i].num);
		printf("%12s", c[i].name);
		printf("%10d", c[i].p1);
	    printf("%7d",  c[i].p2);
	    printf("%7d", c[i].p3);
		printf("%7d\n",c[i].rank);
	    
	}
}

int equal(CAR c1,CAR c2,int condition)  /*����ж�����CAR��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return c1.num==c2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚϳ���*/
     {
	     if (strcmp(c1.name,c2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
		return c1.rank==c2.rank;
 else if (condition==4)
	 return c1.p3==c2.p3;          /*�������condition��ֵΪ4����Ƚϲ��*/
	else return 1;                       /*�����������1*/
} 

int larger(CAR c1,CAR c2,int condition)  /*����condition�����Ƚ�����CAR��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return c1.num>c2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚϲ��*/
		return c1.p3>c2.p3;
	if (condition==3)                    /*�������condition��ֵΪ3����Ƚ�����*/
		return c1.rank>c2.rank;
	else return 1; /*�����������1*/
}

void reverse(CAR c[],int n)             /*����Ԫ������*/
{
	int i;
	CAR temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=c[i];
		c[i]=c[n-1-i];
		c[n-1-i]=temp;
	}
}

void calcuRank(CAR c[],int n)          /*���ݲ�ۼ������Գ����������������ͬ��������ͬ*/
{
	int i;
	sortC(c,n,2);                     /*�ȵ���sortC�㷨���������С��������*/
	reverse(c,n);                     /*�����ã��򰴲���ɴ�С����*/
	c[0].rank=1;                       /*��1����¼������һ����1*/
	for(i=1;i<n;i++)                   /*�ӵ�2����¼һֱ�����һ������ѭ��*/
	{
		if(equal(c[i],c[i-1],4))       /*�����ǰ��¼�������ڵ�ǰһ����¼������*/
			c[i].rank=c[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/
		else
			c[i].rank=i+1;             /*�粻���ʱ����ǰ��¼���ε������±��+1*/
	}
}

void sortC(CAR c[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	CAR t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(c[minpos],c[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=c[i];
			c[i]=c[minpos];
			c[minpos]=t;
		}
	}
}

int searchC(CAR c[],int n,CAR ca,int condition,int f[ ])  /*��c��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(c[i],ca,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertC(CAR c[],int n,CAR ca)              /*��c����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortC(c,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(c[i],ca,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("������¼�Ѵ��ڣ��޷�����!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(c[i],ca,1))                    /*���ca���ڵ�ǰԪ��c[i]�����˳�ѭ��*/
		break;
		c[i+1]=c[i];                         /*����Ԫ��c[i]����һ��λ��*/
	}
	c[i+1]=ca;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteC(CAR c[],int n,CAR ca)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(c[i],ca,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("������¼������!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(c[i],s,1)����*/ 
		c[j]=c[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}