/*��student.c�ļ�����������*/
#include "student.h"
#include <stdio.h>

int readStu(Student  *stu , int n)          /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one student\'s information\n");
		printf("num:  ");
	     scanf("%ld", &stu[i].num);
		if (stu[i].num==0) break;
		printf("name: ");
		scanf("%s",stu[i].name);	
		printf("sex:  ");
		scanf("%s",stu[i].sex);
    	     stu[i].total=0;                /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
		printf("Input three courses of the student:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&stu[i].score[j]);	
		}
		stu[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printStu ( Student  *stu , int n)       /*�������ѧ����¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", stu[i].num);
		printf("%8s", stu[i].name);
		printf("%8s", stu[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",stu[i].score[j]);
	    printf("%7d",stu[i].total);
	    printf("%5d\n",stu[i].rank);
	}
}

int equal(Student s1,Student s2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num==s2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return s1.total==s2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Student s1,Student s2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return s1.num>s2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return s1.total>s2.total;	
	else return 1; /*�����������1*/
}

void reverse(Student stu[],int n)             /*����Ԫ������*/
{
	int i;
	Student temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=stu[i];
		stu[i]=stu[n-1-i];
		stu[n-1-i]=temp;
	}
}

void calcuTotal(Student stu[],int n)         /*��������ѧ�����ܷ�*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ����������ѧ����¼*/
	{
		stu[i].total =0;
		for (j=0;j<3;j++)               /*�ڲ�ѭ���������Ź���*/
			stu[i].total +=stu[i].score[j];
	}	
}

void calcuRank(Student stu[],int n)          /*�����ּܷ�������ѧ�����������ɼ���ͬ��������ͬ*/
{
	int i ;                       
	sortStu(stu,n,2);                     /*�ȵ���sortStu�㷨�����ܷ���С��������*/
	reverse(stu,n);                      /*�����ã����ܷ��ɴ�С������*/
	stu[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(stu[i],stu[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			stu[i].rank=stu[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			stu[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[3][3],Student stu[],int n) /*�����ſε���ߡ���͡�ƽ����*/
/*������ʽ������ά����m�ĵ�һά�������ſΣ��ڶ�ά������ߡ���͡�ƽ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*�����ſε���߷�*/		
	{ 
		m[i][0]=stu[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<stu[j].score[i])
				m[i][0]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                  /*�����ſε���ͷ�*/
	{ 
		m[i][1]=stu[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>stu[j].score[i])
				m[i][1]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                 /*�����ſε�ƽ����*/
	{ 
		m[i][2]=stu[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=stu[j].score[i];
		m[i][2]/=n;
	}
}

void sortStu(Student stu[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Student t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(stu[minpos],stu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=stu[i];
			stu[i]=stu[minpos];
			stu[minpos]=t;
		}
	}
}

int searchStu(Student stu[],int n,Student s,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(stu[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertStu(Student stu[],int n,Student s)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortStu(stu,n,1);                              /*�Ȱ�ѧ������*/
	for (i=0;i<n;i++)
	{
		if (equal(stu[i],s,1))                      /*ѧ����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(stu[i],s,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/
		break;
		stu[i+1]=stu[i];                         /*����Ԫ��stu[i]����һ��λ��*/
	}
	stu[i+1]=s;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteStu(Student stu[],int n,Student s)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(stu[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		stu[j]=stu[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
