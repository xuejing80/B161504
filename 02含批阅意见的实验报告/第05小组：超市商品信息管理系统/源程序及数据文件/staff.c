/*②student.c文件的完整内容*/
#include "staff.h"
#include <stdio.h>

int readSta(Staff  sta[],int n)				/*读入商品记录值*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("请输入商品信息：\n");
		printf("编号:  ");
	    scanf("%ld", &sta[i].num);
   		if (sta[i].num==0) break;
		printf("名称: ");
		scanf("%s",sta[i].name);
		printf("类型: ");
		scanf("%s",sta[i].kind);
	    printf("价格: ");
		scanf("%lf",&sta[i].price);
		printf("库存:");
		scanf("%d",&sta[i].inventory);
    	     sta[i].account=0;				/*销售量需要计算求得，初值置为0*/
			 sta[i].rank=0;					/*名次需要根据销售量来计算，初值置为0*/

	}
	return i;
}

void printSta (Staff  *sta,int n)			/*输出所有商品记录的值*/
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

int equal(Staff s1,Staff s2,int condition)	/*如何判断两个Staff记录相等*/
{
	if (condition==1)						/*如果参数condition的值为1，则比较编号*/
		return s1.num==s2.num;
	else if (condition==2)					/*如果参数condition的值为2，则比较名称*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)						/*如果参数condition的值为3，则比较型类*/
	     return strcmp(s1.kind,s2.kind)==0;
 else if (condition==4)						/*如果参数condition的值为4，则比较销售量*/
		return s1.account==s2.account;
	else return 1;							/*其余情况返回1*/
}

int larger(Staff s1,Staff s2,int condition)	/*根据condition条件比较两个Staff记录的大小*/
{
	if (condition==1)						/*如果参数condition的值为1，则比较编号*/
		return s1.num>s2.num;
	if (condition==2)						 /*如果参数condition的值为2，则比较销售量*/
		return s1.account>s2.account;
	else return 1;							 /*其余情况返回1*/
}

void reverse(Staff sta[],int n)				 /*数组元素逆置*/
{
	int i;
	Staff temp;
	for (i=0;i<n/2;i++)						 /*循环次数为元素数量的一半*/
	{
		temp=sta[i];
		sta[i]=sta[n-1-i];
		sta[n-1-i]=temp;
	}
}


void calcuRank(Staff sta[],int n)			 /*根据销售量计算所有商品的排名，销售量相同者名次相同*/
{
	int i ;
	sortSta(sta,n,2);					 /*先调用sortSta算法，按销售量由小到大排序*/
	reverse(sta,n);						/*再逆置，则按销售量由大到小排序了*/
	sta[0].rank=1;						/*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)					 /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(sta[i],sta[i-1],4))        /*当前记录与其相邻的前一条记录如果销售量相等*/
			sta[i].rank=sta[i-1].rank;	  /*当前记录名次等于其相邻的前一条记录名次*/
	    else
			sta[i].rank=i+1;			/*不相等时当前记录名次等于其下标号+1*/
	}
}

void sortSta(Staff sta[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Staff t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(sta[minpos],sta[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=sta[i];
			sta[i]=sta[minpos];
			sta[minpos]=t;
		}
	}
}

int searchSta(Staff sta[],int n,Staff s,int condition,int f[ ])  /*在sta数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些的元素下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(sta[i],s,condition))
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/
		}
	 return find;                                /*返回find，其值为0则表示没找到*/
}

int insertSta(Staff sta[],int n,Staff s)              /*向sta数组中依编号递增插入一个元素s*/
{
	int i;
	sortSta(sta,n,1);                              /*先按编号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(sta[i],s,1))                      /*编号相同不允许插入，保证编号的唯一性*/
		{
		    printf("记录已存在，请再次输入!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编号从小到大有序*/
	{
		if (!larger(sta[i],s,1))                    /*如果s大于当前元素sta[i]，则退出循环*/
		break;
		sta[i+1]=sta[i];                         /*否则元素sta[i]后移一个位置*/
	}
	sta[i+1]=s;                                /*在下标i+1处插入元素s*/
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteSta(Staff sta[],int n,Staff s)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(sta[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("记录不存在!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(sta[i],s,1)成立*/
		sta[j]=sta[j+1];                       /*通过移动覆盖删除下标为i的元素*/

	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}


 
int sellSta(Staff sta[],int n,Staff s)    /*修改指定编号元素的库存与销售量*/
{
	int i,m;
	printf("请输入商品编号：\n");
	scanf("%ld",&s.num);				 /*输入要修改的编号*/
	printf("请输入数量：");
	scanf("%d",&m);                     /*输入修改数量*/
	for (i=0;i<n;i++)					/*通过循环找到指定编号的元素*/
	{
		if (equal(sta[i],s,1))			/*调用equal函数比较输入的编号与已有的编号*/
		{
			sta[i].inventory=sta[i].inventory-m;			/*修改该元素的库存*/
			sta[i].account=sta[i].account+m;               /*修改该元素的销售量*/
		}
		if(i==n)
		{
			printf("未找到该商品");						/*已有的编号与输入的编号都不相同*/
			break;
		}
	}
	return n;
}

int check(char *ps)							/*判断输入的密码与预设密码是否一致*/
{
	char passwd[]="PLWRV";					/*设定的密码*/
	int i=0;
	int flag=0;								/*设定标志位*/
	for(;*ps!='\0';ps++)					/*对比输入的密码与设定的密码是否相符*/
	{
		if(*ps>='a'&&*ps<='z')
		{
		*ps=*ps-32+2;						/*解密规则*/
		flag=1;
		} 
		if(*ps!=passwd[i])
		flag=0;
		else
		i++;
	}
	return flag;                                  /*返回flag的值*/
}

