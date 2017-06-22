#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct carrental
{
	char bianhao[10];
	char num[10];
	char leixing[20];
	char brand[50];
	char color[50];
	char price[20];
	long zongshu;
	long shengyu;
}car;
struct rent
{
	char bianhao[10];
	char num[10];
	long nian;
	long borrowmonth;
	long borrowday;
	long returnedmonth;
	long returnedday;
	long limittime;
	char caruser[10];
}RENT;
void shan()                              //删除车辆信息
{
	FILE *fp;
	int i=0,j,n,m,l;
	char carnum[20];
	struct carrental cars[1000];
	if((fp=fopen("carrental.txt","r"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	while(fread(&cars[i],sizeof(car),1,fp))
	{
		i++;
		m=i;
	}
	printf("要删除几辆车：");
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		printf("输入车牌号：");
		gets(carnum);
		for(j=0;j<m;j++)
			if(strcmp(carnum,cars[j].num)==0)
				break;
		if(j<m)
		{
			for(l=0;l<m;l++)
				if(strcmp(cars[j].bianhao,cars[l].bianhao)==0)
				{
					cars[l].zongshu--;
					cars[l].shengyu--;
				}
				for(j;j<m;j++)
					cars[j]=cars[j+1];
		}
		else
		{
			printf("输入有误  重新输入\n");
			i--;
		}   
	}
	if((fp=fopen("carrental.txt","w"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	for(i=0;i<m-n;i++)
		fwrite(&cars[i],sizeof(car),1,fp);
	printf("删除成功！！");
}
void xiu()                                        //修改车辆信息
{
	FILE *fp;
	int i=0,m,n;
	char carnum[20],numchar[20];
	struct carrental cars[1000];
	if((fp=fopen("carrental.txt","r"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	while(fread(&cars[i],sizeof(car),1,fp))
	{
		i++;
		m=i;
	}
	if((fp=fopen("carrental.txt","w"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	printf("要修改几辆车:");
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		printf("输入要修改的车牌号：");
		gets(carnum);
		for(i=0;i<m;i++)
		{
			if(strcmp(carnum,cars[i].num)==0)
				break;
		}
		if(i<m)
		{ 
			printf("》》》输入修改后的\n\n");
			printf("》》》输入车辆编号:");  
			gets(cars[i].bianhao);
			printf("\n");
			printf("》》》车牌号:");  
			gets(cars[i].num);
			printf("\n");
			printf("》》》类型:"); 
			gets(cars[i].leixing);
			printf("\n");
			printf("》》》车牌:");  
			gets(cars[i].brand);
			printf("\n");
			printf("》》》颜色:");  
			gets(cars[i].color);
			printf("\n");
			printf("》》》价格:");  
			gets(cars[i].price);
			printf("\n");
			printf("》》》总数:");  
			gets(numchar);
			printf("\n");
			cars[i].zongshu=atol(numchar);
			printf("》》》剩余:");  
			gets(numchar);
			printf("\n");
			cars[i].shengyu=atol(numchar);
		}
		else
			printf("输入有误\n");
		for(i=0;i<m;i++)
			fwrite(&cars[i],sizeof(car),1,fp);
	}
	fclose(fp);
}
void putin()                                               //录入新车
{
	char numchar[20];
	FILE *fp;
	int i=0,m,n;
	struct carrental cars[1000];
	if((fp=fopen("carrental.txt","r"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	while(fread(&cars[i],sizeof(car),1,fp))
	{
		i++;
		m=i;
	}
	fclose(fp);
	if((fp=fopen("carrental.txt","w"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	for(i=0;i<m;i++)
	{
		fwrite(&cars[i],sizeof(car),1,fp);
	}
	printf("要录入几辆车：");
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{   
		printf("\n");
		printf("》》》输入编号:");  
		gets(car.bianhao);
		printf("\n");
		printf("》》》车牌号:");  
		gets(car.num);
		printf("\n");
		printf("》》》类型:"); 
		gets(car.leixing);
		printf("\n");
		printf("》》》车牌:");  
		gets(car.brand);
		printf("\n");
		printf("》》》颜色:");  
		gets(car.color);
		printf("\n");
		printf("》》》价格:");  
		gets(car.price);
		printf("\n");
		printf("》》》总数:");  
		gets(numchar);
		printf("\n");
		car.zongshu=atol(numchar);
		printf("》》》剩余:");  
		gets(numchar);
		printf("\n");
		car.shengyu=atol(numchar);
		fwrite(&car,sizeof(car),1,fp);
	}
	fclose(fp);
}
void print()                                           //打印车辆信息表
{  
	FILE *fp;
	if((fp=fopen("carrental.txt","r"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	puts("_______________________________________________________________________");
	puts("-----------------------------------------------------------------------");
	puts("| 编号  | 车牌号  |  类型  |  车品牌  |   价格   |   颜色  |   总数 |   剩余 |");                			 
	fseek(fp,0L,SEEK_SET);
	while(fread(&car,sizeof(car),1,fp)==1)
		printf("  %-9s%-10s%-10s%-10s%-10s%-10s%-10ld%-10ld\n",car.bianhao,car.num,car.leixing,car.brand,car.price,car.color,car.zongshu,car.shengyu);
	fclose(fp);
	system("pause");
}
void returned()                                              //还车
{
	FILE *fp,*fq;
	int i=0,m,flag=0,j,m1,q=0;
	char carnum[20];
	struct rent car1[1000];
	struct carrental cars[1000];
	if((fp=fopen("borrow.txt","r"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	while(fread(&car1[i],sizeof(RENT),1,fp))
	{
		i++;
		m=i;
	}
	fclose(fp);
	
	if((fq=fopen("carrental.txt", "r"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	//system("pause");
	i=0;
	while(fread(&cars[i],sizeof(car),1,fq))
	{
		i++;
		m1=i;
	}
	fclose(fq);
	
	
	if((fp=fopen("borrow.txt","w"))==NULL)
	{
		printf("can not open the borrow.txt.\n");
		exit(0);
	}
	printf("输入要还的车牌号：");
	gets(carnum);
	for(j=0;j<m;j++)
	{
		if(strcmp(carnum,car1[j].num)==0)
		{
			for(q=0;q<m1;q++)
			{
				if(strcmp(carnum,cars[q].num)==0)
				{
					cars[q].shengyu++;
					printf("please pay %s $\n", cars[q].price);
					system("pause");
				}
			}
			flag=1;
			break;
		}
	}
	if(flag)
	{ 
		if((fq=fopen("carrental.txt","w"))==NULL)
		{
			printf("can not open the carrental.txt.\n");
			exit(0);
		}
		for(j=0;j<m1;j++)
		{
			fwrite(&cars[j],sizeof(car),1,fq);
		}
		fclose(fq);
		flag=0;
		printf("输入还车月份：");
		scanf("%ld",&car1[i].returnedmonth);
		printf("输入还车日期：");
		scanf("%ld",&car1[i].returnedday);
		getchar();
		for(j=0;j<m;j++)
			fwrite(&car1[i],sizeof(RENT),1,fp);
		printf("还车成功");
		print();
		
	}
	else
	{
		printf("输入有误\n");
		system("pause");
	}
	fclose(fp);
	
}
void rent()                                                //创建车辆文件
{  
	FILE *fp;
	char numchar[50],ch='y';
	if((fp=fopen("carrental.txt","wt"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	while(ch=='y'||ch=='Y')
	{
		printf("\n");
		printf("》》》输入编号:");  
		gets(car.bianhao);
		printf("\n");
		printf("》》》车牌号:");  
		gets(car.num);
		printf("\n");
		printf("》》》类型:"); 
		gets(car.leixing);
		printf("\n");
		printf("》》》车品牌:");  
		gets(car.brand);
		printf("\n");
		printf("》》》颜色:");  
		gets(car.color);
		printf("\n");
		printf("》》》价格:");  
		gets(car.price);
		printf("\n");
		printf("》》》总数:");  
		gets(numchar);
		printf("\n");
		car.zongshu=atol(numchar);
		printf("》》》剩余:");  
		gets(numchar);
		printf("\n");
		car.shengyu=atol(numchar);
		fwrite(&car,sizeof(car),1,fp);
		do{
			printf("have another car record(y/n)?:");
			gets(numchar);  
			ch=numchar[0];
		}while(!(ch=='y'||ch=='n'||ch=='Y'||ch=='N'));

	}
	fclose(fp);
}
void borrowed()                                               //借车

{   
	struct carrental cars[1000];
	struct rent car1[1000];
	FILE *fp,*fq;
	char numchar[50];
	int i=0,j,m1,m2,n,flag=0,x;
	printf("借几辆车：");
	scanf("%d",&x);
	getchar();
	if((fq=fopen("carrental.txt", "r"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
		exit(0);
	}
	//system("pause");
	while(fread(&cars[i],sizeof(car),1,fq))
	{
		i++;
		m1=i;
	}
	//system("pause");
	i=0;
	if((fp=fopen("borrow.txt", "r"))!=NULL)
	{
		while(fread(&car1[i],sizeof(RENT),1,fp))
		{
			i++;
			m2=i;
		}
		/*
		printf("can not open the borrow.txt.\n");
		exit(0);
		*/
		fclose(fp);
	}
	
	for(i=0;i<x;i++)
	{
		printf("\n");
		printf("输入车牌号:"); 
		gets(numchar);
		for(j=0;j<m1;j++)
		{
			if(strcmp(numchar,cars[j].num)==0)
			{
				n=j;
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf("\n");
			printf("输入正确\n\n");
			flag=0;
			strcpy(RENT.num,numchar);
			printf("》》》输入编号");  gets(RENT.bianhao); printf("\n"); 
			printf("》》》借车年份:");   gets(numchar);  printf("\n");  RENT.nian=atol(numchar);
			printf("》》》借车月份:");  gets(numchar); printf("\n"); RENT.borrowmonth=atol(numchar);
			printf("》》》借车日期:"); gets(numchar); printf("\n"); RENT.borrowday=atol(numchar);
			printf("》》》还车月份:");  gets(numchar); printf("\n");  RENT.returnedmonth=atol(numchar);
			printf("》》》还车日期:");  gets(numchar);  printf("\n");  RENT.returnedday=atol(numchar);
			printf("》》》期限:");  gets(numchar); printf("\n");  RENT.limittime=atol(numchar);
			printf("》》》顾客姓名:");  gets(RENT.caruser);  printf("\n");
			
			if((fp=fopen("borrow.txt","w"))==NULL)
			{
				printf("can not open the borrow.txt.\n");
				exit(0);
			}
			fwrite(&RENT, sizeof(RENT), 1, fp);
			for(j=0;j<m2;j++)
			{
				fwrite(&car1[j], sizeof(RENT), 1, fp);
			}
			for(j=0;j<m1;j++)
			{
				if(strcmp(cars[n].bianhao,cars[j].bianhao)==0)
					cars[j].shengyu--;
			}
			if((fq=fopen("carrental.txt","w"))==NULL)
			{
				printf("can not open the carrental.txt.\n");
				exit(0);
			}
			for(j=0;j<m1;j++)
			{
				fwrite(&cars[j],sizeof(car),1,fq);
			}
			printf("借车成功\n");
		}
		else
		{
			printf("输入错误\n");
			i--;
		}
	}
	fclose(fq);
	fclose(fp);
	system("pause");
}
void main()
{   
	int flag=1;
	char a[20];
	char cUser[20];
	char cPasswd[20];

	memset(cUser, 0x00, sizeof(cUser));
	memset(cPasswd, 0x00, sizeof(cPasswd));
	puts("--------------欢迎使用租车信息管理系统------------------------");
	puts("请输入您的用户名：");
	scanf("%s", cUser);
	while(strcmp(cUser, "admin")!=0)
	{
		puts("请输入的用户名错误，请重新输入：[退出按0]");
		scanf("%s", cUser);
		if(strcmp(cUser, "0")==0)
			return ;
	}
	puts("请输入您的密码：");
	scanf("%s", cPasswd);
	while(strcmp(cPasswd, "admin123")!=0)
	{
		puts("请输入的密码错误，请重新输入：[退出按0]");
		scanf("%s", cPasswd);
		if(strcmp(cPasswd, "0")==0)
			return ;
	}
	system("cls");

	while(flag)
	{
		puts("┌──────────────────────────┐");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│           欢迎使用租车信息管理系统                 │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                       █                           │");
		puts("│                       █                           │");
		puts("│                       █                           │");
		puts("│                     █  █                         │");
		puts("│                   █      █                       │");
		puts("│                 █          █                     │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│      请选择您需要的功能 ：                         │");
		puts("│                                                    │");
		puts("│         （直接键入对应数字）                       │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│         1.汽车登记                                 │");
		puts("│                                                    │");
		puts("│         2.打印车辆信息表                           │"); 
		puts("│                                                    │");
		puts("│         3.车辆追加与录入                           │");
		puts("│                                                    │");
		puts("│         4.修改车辆信息                             │");   
		puts("│                                                    │");   
		puts("│         5.删除车辆信息                             │");
		puts("│                                                    │");
		puts("│         6.借车                                     │");   
		puts("│                                                    │");
		puts("│         7.还车                                     │");
		puts("│                                                    │");
		puts("│         0.退出                                     │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("│                                                    │");
		puts("└──────────────────────────┘");

		flag=0;
		scanf("%s",a);
		getchar();
		if(strcmp(a,"3")==0)
		{
			putin();
			flag=1;
		}
		else if(strcmp(a,"1")==0)  
		{	
			rent();
			flag=1;
		}
		else if(strcmp(a,"6")==0)
		{
			borrowed();
			flag=1;
		}
		else if(strcmp(a,"2")==0)
		{
			print();
			flag=1;
		}
		else if(strcmp(a,"7")==0)
		{		
			returned();
			flag=1;
		}
		else if(strcmp(a,"4")==0)
		{
			xiu();
			flag=1;
		}
		else if(strcmp(a,"5")==0)
		{	
			shan();
			flag=1;
		}
		else if(strcmp(a,"0")==0)
		{	
			flag=0;
		}
		else
		{
			printf("输入错误   请重新输入：");
			flag=1;
		}
	}
}

