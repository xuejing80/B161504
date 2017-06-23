/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"sightspot.h"

void printHead( )      /*打印景点信息的表头*/
{
printf("%8s%22s%27s%12s%8s%12s\n","序号","名称","地点","人流量","月份","名次");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 景点人流量管理 ********\n");
        printf("******** 4. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入景点记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 删除景点记录 %%%%%%%%\n");
		printf("%%%%%%%% 3. 修改景点记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}
void menunum( )     /*3、景点人流量管理菜单函数*/
{
		printf("%%%%%%%% 1. 根据人流量排名 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuSearch()    /*4、根据条件查询菜单函数*/
{
		printf("######## 1. 按序号查询   ########\n");
		printf("######## 2. 按名称查询   ########\n");
		printf("######## 3. 按名次查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

int baseManage(Sightspot sig[],int n)    	     /*该函数完成基本信息管理*/
/*按序号进行插入删除修改，序号不能重复*/
{  
		int choice,t,find[NUM];
     Sightspot s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readSig(&s,1);       /*读入一条待插入的景点记录*/
					 n=insertSig(sig,n,s);   /*调用函数插入景点记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.number);  /*读入一个待删除的景点序号*/
					 n=deleteSig(sig,n,s);   /*调用函数删除指定序号的景点记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.number);  /*读入一个待修改的景点序号*/
				      t=searchSig(sig,n,s,1,find) ; /*调用函数查找指定序号的景点记录*/
				      if (t)                 /*如果该序号的记录存在*/
					 {
						  readSig(&s,1);   /*读入一条完整的景点记录信息*/
					      sig[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该序号的记录不存在*/ 
 printf("this sightspot is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}
int numManage(Sightspot sig[],int n)          /*该函数完成景点人流量管理功能*/
{  
	int choice;
	do  
	{  
		menunum() ;
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuRank(sig,n);         /*根据所有景点的人流量排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

int searchManage(Sightspot sig[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Sightspot s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a sightspot\'s num will be searched:\n");
				      scanf("%ld",&s.number);         /*输入待查询景点的序号*/
					  break;
				case 2:   printf("Input a sightspot\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询景点的名称*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*输入待查询景点的名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchSig(sig,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printSig(&sig[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Sightspot sig[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortSig(sig,n,1);         /*按序号由小到大的顺序排序记录*/ 
          	 printSig(sig,n);          /*按序号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(sig,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: numManage(sig,n);     /* 3. 景点人流量管理*/
					break;
			case 4: searchManage(sig,n);     /* 4. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}
int main( )
{
		Sightspot sig[NUM];                /*定义实参一维数组存储景点记录*/
      int choice,n;
	 n=readFile(sig);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(sig);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(sig,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortSig(sig,n,1);                   /*存入文件前按序号由小到大排序*/ 
	     saveFile(sig,n);                   /*将结果存入文件*/
      return 0;
}
