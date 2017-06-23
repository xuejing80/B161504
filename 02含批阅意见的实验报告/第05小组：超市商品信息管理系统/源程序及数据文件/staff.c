/*��student.c�ļ�����������*/
#include "staff.h"
#include <stdio.h>

int readSta(Staff  sta[],int n)				/*������Ʒ��¼ֵ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("��������Ʒ��Ϣ��\n");
		printf("���:  ");
	    scanf("%ld", &sta[i].num);
   		if (sta[i].num==0) break;
		printf("����: ");
		scanf("%s",sta[i].name);
		printf("����: ");
		scanf("%s",sta[i].kind);
	    printf("�۸�: ");
		scanf("%lf",&sta[i].price);
		printf("���:");
		scanf("%d",&sta[i].inventory);
    	     sta[i].account=0;				/*��������Ҫ������ã���ֵ��Ϊ0*/
			 sta[i].rank=0;					/*������Ҫ���������������㣬��ֵ��Ϊ0*/

	}
	return i;
}

void printSta (Staff  *sta,int n)			/*���������Ʒ��¼��ֵ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", sta[i].num);
		printf("%10s", sta[i].name);
		printf("%12s", sta[i].kind);
		printf("%10.2lf", sta[i].price);
		printf("%10d",sta[i].inventory);
	    printf("%7d",sta[i].account);
	    printf("%10d\n",sta[i].rank);
	}

}

int equal(Staff s1,Staff s2,int condition)	/*����ж�����Staff��¼���*/
{
	if (condition==1)						/*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num==s2.num;
	else if (condition==2)					/*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)						/*�������condition��ֵΪ3����Ƚ�����*/
	     return strcmp(s1.kind,s2.kind)==0;
 else if (condition==4)						/*�������condition��ֵΪ4����Ƚ�������*/
		return s1.account==s2.account;
	else return 1;							/*�����������1*/
}

int larger(Staff s1,Staff s2,int condition)	/*����condition�����Ƚ�����Staff��¼�Ĵ�С*/
{
	if (condition==1)						/*�������condition��ֵΪ1����Ƚϱ��*/
		return s1.num>s2.num;
	if (condition==2)						 /*�������condition��ֵΪ2����Ƚ�������*/
		return s1.account>s2.account;
	else return 1;							 /*�����������1*/
}

void reverse(Staff sta[],int n)				 /*����Ԫ������*/
{
	int i;
	Staff temp;
	for (i=0;i<n/2;i++)						 /*ѭ������ΪԪ��������һ��*/
	{
		temp=sta[i];
		sta[i]=sta[n-1-i];
		sta[n-1-i]=temp;
	}
}


void calcuRank(Staff sta[],int n)			 /*��������������������Ʒ����������������ͬ��������ͬ*/
{
	int i ;
	sortSta(sta,n,2);					 /*�ȵ���sortSta�㷨������������С��������*/
	reverse(sta,n);						/*�����ã����������ɴ�С������*/
	sta[0].rank=1;						/*��һ����¼������һ����1*/
	for (i=1;i<n;i++)					 /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(sta[i],sta[i-1],4))        /*��ǰ��¼�������ڵ�ǰһ����¼������������*/
			sta[i].rank=sta[i-1].rank;	  /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/
	    else
			sta[i].rank=i+1;			/*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void sortSta(Staff sta[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Staff t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(sta[minpos],sta[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=sta[i];
			sta[i]=sta[minpos];
			sta[minpos]=t;
		}
	}
}

int searchSta(Staff sta[],int n,Staff s,int condition,int f[ ])  /*��sta��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���Щ��Ԫ���±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(sta[i],s,condition))
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/
}

int insertSta(Staff sta[],int n,Staff s)              /*��sta����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortSta(sta,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(sta[i],s,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("��¼�Ѵ��ڣ����ٴ�����!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(sta[i],s,1))                    /*���s���ڵ�ǰԪ��sta[i]�����˳�ѭ��*/
		break;
		sta[i+1]=sta[i];                         /*����Ԫ��sta[i]����һ��λ��*/
	}
	sta[i+1]=s;                                /*���±�i+1������Ԫ��s*/
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteSta(Staff sta[],int n,Staff s)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(sta[i],s,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("��¼������!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(sta[i],s,1)����*/
		sta[j]=sta[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/

	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}


 
int sellSta(Staff sta[],int n,Staff s)    /*�޸�ָ�����Ԫ�صĿ����������*/
{
	int i,m;
	printf("��������Ʒ��ţ�\n");
	scanf("%ld",&s.num);				 /*����Ҫ�޸ĵı��*/
	printf("������������");
	scanf("%d",&m);                     /*�����޸�����*/
	for (i=0;i<n;i++)					/*ͨ��ѭ���ҵ�ָ����ŵ�Ԫ��*/
	{
		if (equal(sta[i],s,1))			/*����equal�����Ƚ�����ı�������еı��*/
		{
			sta[i].inventory=sta[i].inventory-m;			/*�޸ĸ�Ԫ�صĿ��*/
			sta[i].account=sta[i].account+m;               /*�޸ĸ�Ԫ�ص�������*/
		}
		if(i==n)
		{
			printf("δ�ҵ�����Ʒ");						/*���еı��������ı�Ŷ�����ͬ*/
			break;
		}
	}
	return n;
}

int check(char *ps)							/*�ж������������Ԥ�������Ƿ�һ��*/
{
	char passwd[]="PLWRV";					/*�趨������*/
	int i=0;
	int flag=0;								/*�趨��־λ*/
	for(;*ps!='\0';ps++)					/*�Ա�������������趨�������Ƿ����*/
	{
		if(*ps>='a'&&*ps<='z')
		{
		*ps=*ps-32+2;						/*���ܹ���*/
		flag=1;
		} 
		if(*ps!=passwd[i])
		flag=0;
		else
		i++;
	}
	return flag;                                  /*����flag��ֵ*/
}

