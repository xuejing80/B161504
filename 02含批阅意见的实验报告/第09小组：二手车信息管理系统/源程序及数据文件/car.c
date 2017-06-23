/*②car.c文件的完整内容*/
#include "car.h"
#include <stdio.h>

int readC(CAR  *c , int n)          /*读入汽车记录值，读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{    
		printf("请输入一辆汽车信息\n");
		printf("汽车编号:  ");
		printf("(请按照顺序输入编号)");
	        scanf("%ld", &c[i].num);	
		printf("汽车车型: ");
		scanf("%s",c[i].name);	
		printf("原价：");
                scanf("%ld",&c[i].p1);
                printf("现价：");
                scanf("%ld",&c[i].p2);
    	        c[i].p3=c[i].p1-c[i].p2; 
				c[i].rank=0;				
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printC ( CAR  *c , int n)       /*输出所有汽车记录的值*/
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

int equal(CAR c1,CAR c2,int condition)  /*如何判断两个CAR记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return c1.num==c2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较车型*/
     {
	     if (strcmp(c1.name,c2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
		return c1.rank==c2.rank;
 else if (condition==4)
	 return c1.p3==c2.p3;          /*如果参数condition的值为4，则比较差价*/
	else return 1;                       /*其余情况返回1*/
} 

int larger(CAR c1,CAR c2,int condition)  /*根据condition条件比较两个CAR记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return c1.num>c2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较差价*/
		return c1.p3>c2.p3;
	if (condition==3)                    /*如果参数condition的值为3，则比较名次*/
		return c1.rank>c2.rank;
	else return 1; /*其余情况返回1*/
}

void reverse(CAR c[],int n)             /*数组元素逆置*/
{
	int i;
	CAR temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=c[i];
		c[i]=c[n-1-i];
		c[n-1-i]=temp;
	}
}

void calcuRank(CAR c[],int n)          /*根据差价计算所以车辆的排名，差价相同的名次相同*/
{
	int i;
	sortC(c,n,2);                     /*先调用sortC算法，按差价由小到大排序*/
	reverse(c,n);                     /*再逆置，则按差价由大到小排序*/
	c[0].rank=1;                       /*第1条记录的名次一定是1*/
	for(i=1;i<n;i++)                   /*从第2条记录一直到最后一条进行循环*/
	{
		if(equal(c[i],c[i-1],4))       /*如果当前记录与其相邻的前一条记录差价相等*/
			c[i].rank=c[i-1].rank;     /*则当前记录名次等于其相邻的前一条记录名次*/
		else
			c[i].rank=i+1;             /*如不相等时，则当前记录名次等于其下标号+1*/
	}
}

void sortC(CAR c[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	CAR t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(c[minpos],c[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=c[i];
			c[i]=c[minpos];
			c[minpos]=t;
		}
	}
}

int searchC(CAR c[],int n,CAR ca,int condition,int f[ ])  /*在c数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(c[i],ca,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertC(CAR c[],int n,CAR ca)              /*向c数组中依编号递增插入一个元素s*/
{
	int i;
	sortC(c,n,1);                              /*先按编号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(c[i],ca,1))                      /*编号相同不允许插入，保证编号的唯一性*/
		{
		    printf("这条记录已存在，无法插入!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编号从小到大有序*/
	{
		if (!larger(c[i],ca,1))                    /*如果ca大于当前元素c[i]，则退出循环*/
		break;
		c[i+1]=c[i];                         /*否则元素c[i]后移一个位置*/
	}
	c[i+1]=ca;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteC(CAR c[],int n,CAR ca)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(c[i],ca,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("这条记录不存在!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(c[i],s,1)成立*/ 
		c[j]=c[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}