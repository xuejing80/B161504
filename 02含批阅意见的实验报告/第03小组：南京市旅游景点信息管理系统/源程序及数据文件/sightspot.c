/*②sightspot.c文件的完整内容*/
#include "sightspot.h"
#include <stdio.h>

int readSig(Sightspot  *sig , int n)          /*读入景点记录值，序号为0或读满规定条数记录时停止*/
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
	    printf("人流量: \n");
	    scanf("%d",&sig[i].num);
	    printf("月份: \n");
	    scanf("%d",&sig[i].month);
        sig[i].rank=0;      /*名次需要根据人流量来计算，初值置为0*/
	}
	printf("\n");
	return i;                         /*返回实际读入的记录条数*/
}

void printSig ( Sightspot  *sig , int n)       /*输出所有景点记录的值*/
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

int equal(Sightspot s1,Sightspot s2,int condition)  /*如何判断两个Sight spot记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较序号*/
		return s1.number==s2.number;
	else if (condition==2)                /*如果参数condition的值为2，则比较景点名称*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较人流量*/
		return s1.num==s2.num;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Sightspot s1,Sightspot s2,int condition)  /*根据condition条件比较两个景点记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较序号*/
		return s1.number>s2.number;
	if (condition==2)                    /*如果参数condition的值为2，则比较人流量*/
		return s1.num>s2.num;	
	else return 1; /*其余情况返回1*/
}

void reverse(Sightspot sig[],int n)             /*数组元素逆置*/
{
	int i;
	Sightspot temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=sig[i];
		sig[i]=sig[n-1-i];
		sig[n-1-i]=temp;
	}
}
void calcuRank(Sightspot sig[],int n)          /*根据人流量计算所有景点的排名，人流量相同者名次相同*/
{
	int i ;                       
	sortSig(sig,n,2);                     /*先调用sortSig算法，按人流量由小到大排序*/
	reverse(sig,n);                      /*再逆置，则按人流量由大到小排序了*/
	sig[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(sig[i],sig[i-1],4))         /*当前记录与其相邻的前一条记录如果人流量相等*/
			sig[i].rank=sig[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			sig[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
	printSig(sig,n) ;
}
void sortSig(Sightspot sig[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Sightspot t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(sig[minpos],sig[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=sig[i];
			sig[i]=sig[minpos];
			sig[minpos]=t;
		}
	}
}

int searchSig(Sightspot sig[],int n,Sightspot s,int condition,int f[ ])  /*在sig数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(sig[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertSig(Sightspot sig[],int n,Sightspot s)              /*向sig数组中依序号递增插入一个元素s*/
{
	int i;
	sortSig(sig,n,1);                              /*先按序号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(sig[i],s,1))                      /*序号相同不允许插入，保证序号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按序号从小到大有序*/
	{
		if (!larger(sig[i],s,1))                    /*如果s大于当前元素sig[i]，则退出循环*/
		break;
		sig[i+1]=sig[i];                         /*否则元素sig[i]后移一个位置*/
	}
	sig[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteSig(Sightspot sig[],int n,Sightspot s)            /*从数组中删除指定序号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(sig[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/ 
		sig[j]=sig[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}

