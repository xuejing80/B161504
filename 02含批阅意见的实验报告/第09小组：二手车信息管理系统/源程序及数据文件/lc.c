/*lc.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"car.h"

void printHead( )      /*打印汽车信息的表头*/
{
printf("%7s%10s%13s%7s%7s%8s\n","编号","车型","原价","现价","差价","名次");
}

void menu( )         /*顶层菜单函数*/
{       printf("********|------------------------|********\n");
	    printf("********|      汽车编号对应      |********\n");
        printf("********|              0.奔驰    |********\n");
        printf("********|              1.宝马    |********\n");
		printf("********|              2.捷达    |********\n");
		printf("********| 0.南京       3.奥迪    |********\n");
		printf("********| 1.上海       4.路虎    |********\n");
		printf("********| 2.北京       5.五菱宏光|********\n");
		printf("********| 3.广州       6.捷豹    |********\n");
		printf("********| 4.深圳       7.桑塔纳  |********\n");
		printf("********|              8.君越    |********\n");
		printf("********|              9.马自达  |********\n");
		printf("********|------------------------|********\n");
		printf("*************     主菜单      ************\n");
		printf("********     1. 显示基本信息      ********\n");
		printf("********     2. 基本信息管理      ********\n");
        printf("********     3. 根据条件查询      ********\n");
		printf("********     4. 汽车价格管理      ********\n");
		printf("********     0. 退出              ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入汽车记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除汽车记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改汽车记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}
 
void menuSearch()    /*3、根据条件查询菜单函数*/
{
		printf("######## 1. 按编号查询   ########\n");
		printf("######## 2. 按车型查询   ########\n");
	    printf("######## 3. 按差价查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

void menuPrice()
{
	printf("$$$$$$$$ 1. 根据差价排名 $$$$$$$$\n");
	printf("$$$$$$$$ 0. 返回上层菜单 $$$$$$$$\n");
}

int baseManage(CAR c[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
		int choice,t,find[NUM];
     CAR ca;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("请选择一个选项:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readC(&ca,1);       /*读入一条待插入的汽车记录*/
					 n=insertC(c,n,ca);   /*调用函数插入汽车记录*/
					 break;
			   case 2:  printf("请输入您要删除的编号\n");
					 scanf("%ld",&ca.num);  /*读入一个待删除的汽车编号*/
					 n=deleteC(c,n,ca);   /*调用函数删除指定编号的汽车记录*/
					 break;
			   case 3:  printf("请输入您要修改的编号\n");
					 scanf("%ld",&ca.num);  /*读入一个待修改的汽车编号*/
				      t=searchC(c,n,ca,1,find) ; /*调用函数查找指定编号的汽车记录*/
				      if (t)                 /*如果该编号的记录存在*/
					 {
						  readC(&ca,1);   /*读入一条完整的汽车记录信息*/
					      c[find[0]]=ca;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
 printf("这辆车不存在，无法修改\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void priceManage(CAR c[],int n)
{
	int choice;
	do
	{
		menuPrice();
		printf("请输入一个选项：\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: calcuRank(c,n);
			break;
		case 0: break;
		}
	}while(choice);
}

void dispManage(CAR c[],int n)       /*该函数完成汽车信息显示功能*/
{
	int choiced;
	do
	{
		printf("@@@@@@@@ 1. 按汽车编号顺序显示 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 按差价排名顺序显示 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单       @@@@@@@@\n");
		scanf("%d",&choiced);
		printHead();
		if(choiced==1)
		{
			sortC(c,n,1);
			printC(c,n);
		}
		else if(choiced==2)
		{
			sortC(c,n,3);
			printC(c,n);
		}
		else
			break;
	}while(choiced!=0);
}

void searchManage(CAR c[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
CAR ca;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("请选择一个选项:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("输入一辆您要查询的汽车编号:\n");
				      scanf("%ld",&ca.num);         /*输入待查询汽车的编号*/
					  break;
				case 2:   printf("输入一辆您要查询的汽车型号:\n");
				      scanf("%s",ca.name);	          /*输入待查询汽车的型号*/		  
				      break;   
				case 3:   printf("输入一辆您要查询的差价名次:\n");
					  scanf("%d",&ca.rank);           /*输入待查询差价的名次*/
					  break;                          
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchC(c,n,ca,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printC(&c[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("这条记录不存在!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(CAR c[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: dispManage(c,n);           /* 1. 显示基本信息*/
					break;
			case 2: n=baseManage(c,n);    /* 2. 基本信息管理*/
			   	     break;		
			case 3: searchManage(c,n);   /* 3. 根据条件查询*/
				     break;
			case 4: priceManage(c,n);
				break;
          case 0: break;
		}
		return n;
}

int main( )
{
		CAR c[NUM];                /*定义实参一维数组存储汽车记录*/
      int choice,n;
	 n=readFile(c);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(c);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("请输入您的选择: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(c,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("输入错误，请您再次输入您的选择!\n");
	} while (choice);
	sortC(c,n,1);                   /*存入文件前按编号由小到大排序*/ 
	     saveFile(c,n);                   /*将结果存入文件*/
      return 0;
}
