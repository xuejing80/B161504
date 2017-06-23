 /*③ file.h文件的内容如下：*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"staff.h"
void printHead()      /*打印商品信息的表头*/
{
	printf("%10s%10s%12s%10s%10s%10s%8s\n","编号","名称","类型","价格","库存","销售量","排名");
}
void menu()         /*顶层菜单函数*/
{
	printf("*******1.显示商品基本信息*******\n");
	printf("*******2.商品基本信息管理*******\n");
	printf("*******3.按销售量排名*******\n");
	printf("*******4.查询商品信息*******\n");
	printf("*******5.商品结算*******\n");
	printf("*******0.退出*******\n");
}
void menuBase()     /*2、基本信息管理菜单函数*/
{
	printf("*******1.添加商品信息*******\n");
	printf("*******2.删除商品信息*******\n");
	printf("*******3.修改商品信息*******\n");
	printf("*******0.返回上层菜单*******\n");
}
void menuSearch()    /*3、根据条件查询菜单函数*/
{
	printf("*******1.按编号查询*******\n");
	printf("*******2.按名称查询*******\n");
	printf("*******3.按类别查询*******\n");
	printf("*******0.返回上层菜单*******\n");
}
int baseManage(Staff sta[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{
	int choice,t,find[NUM];
	Staff s;
	do
	{
		menuBase();                  /*显示对应的二级菜单*/
		printf("请选择要执行的操作:\n");
		scanf("%d",&choice);	          /*读入选项*/
		switch(choice)
		{
		case 1: readSta(&s,1);       /*读入一条待插入的商品记录*/
			n=insertSta(sta,n,s);   /*调用函数插入商品记录*/
			break;
		case 2:printf("请输入要删除的商品编号：\n");
			scanf("%ld",&s.num);  /*读入一个待删除的商品编号*/
			n=deleteSta(sta,n,s);  /*调用函数删除指定学号的学生记录*/
			break;
		case 3:
			printf("请输入要修改的商品编号：\n");
			scanf("%ld",&s.num);  /*读入一个待修改的商品编号*/
			t=searchSta(sta,n,s,1,find); /*调用函数查找指定编号的商品记录*/
			if(t)                 /*如果该编号的记录存在*/
			{
				readSta(&s,1);   /*读入一条完整的商品记录信息*/
				sta[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/
			}
			else                 /*如果该编号的记录不存在*/
				printf("该商品不存在\n"); /*输出提示信息*/
			break;
		case 0:break;
		}
	}while(choice);
	return n;                             /*返回当前操作结束后的实际记录条数*/
}

void searchManage(Staff sta[],int n)               /*该函数完成根据条件查询功能*/
{
	int i,choice,findnum,f[NUM];
Staff s;
	do
	{
		menuSearch();                         /*显示对应的二级菜单*/
		printf("请选择要执行的操作:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("请输入要查询的商品编号:\n");
			scanf("%ld",&s.num);         /*输入待查询商品的编号*/
			break;
		case 2:printf("请输入要查询的商品名称:\n");
			scanf("%s",s.name);	          /*输入待查询商品的名称*/
			break;
		case 3:printf("请输入要查询的商品类别:\n");
			scanf("%s",s.kind);          /*输入待查询商品的类别*/
			break;
		case 0:break;
		}
		if(choice>=1&&choice<=3)
		{
			findnum=searchSta(sta,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
			if(findnum)				     /*如果查找成功*/
			{
				printHead();                  /*打印表头*/
				for(i=0;i<findnum;i++)         /*循环控制f数组的下标*/
		printSta(&sta[f[i]],1);      /*每次输出一条记录*/
			}
			else
				printf("该记录不存在!\n"); /*如果查找不到元素，则输出提示信息*/
		}
	}while(choice);
}
int runMain(Staff sta[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
	Staff s;
	switch(choice)
	{
	case 1:printHead();           /* 1. 显示基本信息*/
		sortSta(sta,n,1);         /*按编号由小到大的顺序排序记录*/ 
		printSta(sta,n);          /*按编号由小到大的顺序输出所有记录*/
		break;
	case 2:n=baseManage(sta,n);    /* 2. 基本信息管理*/
		break;
	case 3:calcuRank(sta,n);      /* 3. 按销售量排名*/
	    break;
	case 4:searchManage(sta,n);     /* 4. 根据条件查询*/
		break;
	case 5:sellSta(sta,n,s);     /* 5. 商品结算*/
			break;
	case 0:break;
	}
	return n;
}

int main()
{
	char str[10];    /*定义一个数组用来存储输入的字符串*/
	char *gets(char *p);    
    do
	{	
	    int i=0;
		printf("请输入密码：");
		gets(str);
	}while(check(str)==0);    /*调用check函数比较输入的密码与设定好的密码*/
	Staff sta[NUM];                /*定义实参一维数组存储商品记录*/
	int choice,n;
	n=readFile(sta);                  /*首先读取文件，记录条数返回赋值给n*/
	if(!n)                          /*如果原来的文件为空*/
	{
		n=creatFile(sta);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
	}
	do
	{
		menu();                      /*显示主菜单*/
		printf("请输入你的选择:");
		scanf("%d",&choice);
		if(choice>=0&&choice<=5)
			n=runMain(sta,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
		else
			printf("输入错误，请再次输入!\n");
	}while(choice);
	sortSta(sta,n,1);                   /*存入文件前按编号由小到大排序*/
	saveFile(sta,n);                   /*将结果存入文件*/
	
	return 0;
}


			



	


