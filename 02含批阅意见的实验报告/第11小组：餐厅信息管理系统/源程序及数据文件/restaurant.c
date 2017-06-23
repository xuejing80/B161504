#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Custome
{
	int num;
    char name[20];
	char sex[6];
	char tel[12];
	char id[5];
	int food[20];
	int service;
	int total;
}Custome;


typedef struct Food
{
	int num;
	char name[20];
	char taste[10];
	char category[10];
    int cost;
}Food;

typedef struct Database//数据库结构体 存放菜品和顾客
{
	Food f[30];
	Custome c[20];
}Database;
Database database={0};

void gotoxy(int x ,int y)
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD Ioc;
	Ioc.X = x;
	Ioc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,Ioc);
}

void saveFile(void)
{
	FILE *fp = fopen("database.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	fwrite(&database, sizeof(database), 1, fp);//将结构体写入文件
	fclose(fp);
	return;
}

void startup(void)
{
	FILE *fp = fopen("database.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("database.info", "wb+");
		if(fp != NULL)
			fclose(fp);
		return;
	}
	fread(&database, sizeof(database), 1, fp);//将文件读入结构体
	fclose(fp);
	return;
}

void tableNum()//按桌号查找
{
	int num,i=0,j=0,k,sum=0,m=11;
	gotoxy(25,10);
	printf("请输入桌号:");
	scanf("%d",&num);
	fflush(stdin);
	while(database.c[i].num!=0)
	{
		if (database.c[i].num==num)
		{
           while(database.c[i].food[j]!=0)
		   {
			   for (k=0;k<=20;k++)
			   {
				   if (database.f[k].num==database.c[i].food[j])
				   {
					   gotoxy(15,m);
					   printf("%-10s  %-10s  %-10s  %d元\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
					   sum+=database.f[k].cost;
					   m++;
					   break;
				   }
			   }
			   j++;
		   }
		   gotoxy(15,m++);
		   printf("顾客信息:  %-5s  %-5s 会员卡号:%-5s  手机号:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
		   gotoxy(15,m);
		   printf("总价为:%d元\n",sum);
		   return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("此桌顾客不存在！请检查");
}

void telNum()//按手机号查找
{
	int i=0,j=0,k,sum=0,m=11;
	char tel[12];
	gotoxy(25,10);
	printf("请输入手机号:");
	gets(tel);
	while(database.c[i].num!=0)
	{
		if (strcmp(tel,database.c[i].tel)==0)
		{
			while(database.c[i].food[j]!=0)
			{
				for (k=0;k<=20;k++)
				{
					if (database.f[k].num==database.c[i].food[j])
					{
						gotoxy(15,m);
						printf("%-10s  %-10s  %-10s  %d元\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
						sum+=database.f[k].cost;
						m++;
						break;
					}
				}
				j++;
			}
			gotoxy(15,m++);
			printf("顾客信息:  %-5s  %-5s 会员卡号:%-5s  手机号:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
			gotoxy(15,m);
			printf("总价为:%d元\n",sum);
			return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("此顾客不存在！请检查");
}

void id()//按id查找
{
	int i=0,j=0,k,sum=0,m=11;
	char id[5];
	gotoxy(25,10);
	printf("请输入卡号:");
	gets(id);
	while(database.c[i].num!=0)
	{
		if (strcmp(id,database.c[i].id)==0)
		{
			while(database.c[i].food[j]!=0)
			{
				for (k=0;k<=20;k++)
				{
					if (database.f[k].num==database.c[i].food[j])
					{
						gotoxy(15,m);
						printf("%-10s  %-10s  %-10s  %d元\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
						sum+=database.f[k].cost;
						m++;
						break;
					}
				}
				j++;
			}
		    gotoxy(15,m++);
			printf("顾客信息:  %-5s  %-5s 会员卡号:%-5s  手机号:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
			gotoxy(15,m);
			printf("总价为:%d元\n",sum);
			return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("此顾客不存在！请检查");
}

void Jm()
{
	system("cls");
	printf("###########################################################################\n");//定义用户界面
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("###########################################################################\n");

}

void add()					//增加并保存会员信息 
{
	FILE *fp; 
	char c[2]={' '},d[2]={'\n'},e[2]={'#'};
	Custome people;
	fp = fopen("member.txt","a+");
	gotoxy(25,10);
	printf("请输入会员姓名:");
	gets(people.name);

	gotoxy(25,11);
	printf("请输入会员性别:");
	scanf("%s",people.sex);

	gotoxy(25,12);
	printf("请输入会员卡号:");
	scanf("%s",people.id);

	gotoxy(25,13);
	printf("请输入会员手机:");
	scanf("%s",people.tel);

	fputs(e,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
    fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(people.name,fp);
	fputs(c,fp);
	fputs(people.sex,fp);
	fputs(c,fp);
	fputs(people.id,fp);
	fputs(c,fp);
	fputs(people.tel,fp);
	fputs(d,fp);
	fclose(fp);

	gotoxy(25,18);
	printf("添加成功!");
	Sleep(3000);
}

void draw()
{
    FILE *f1;
    char c;
    f1 = fopen("member.txt","r");
    gotoxy(25,10);
    printf("会员信息表 \n");
    while((c=getc(f1)) != EOF)
    printf("%c",c);
    fclose(f1);
}

void delet()
{
	FILE *f1;
    char c[2]={' '};
    f1 = fopen("database.txt","w+");
    while((getc(f1)) != EOF)
    fputs(c,f1);
    fclose(f1);
}

void main()
{
    /*Food p[30]={{1,"土豆丝","酸辣","热菜",15},
	{2,"红烧肉","红烧","热菜",30},
	{3,"时蔬拼盘","甜味","凉菜",12},
	{4,"糖醋里脊","酸甜","热菜",28},
	{5,"孜然羊肉","咸辣","热菜",24},
	{6,"松仁玉米","甜味","热菜",15},
	{7,"凉拌牛肉","咸辣","凉菜",18},
	{8,"银耳汤","甜味","汤",13},
	{9,"水果拼盘1","甜味","甜品",13},
	{10,"干贝苦瓜羹","咸味","汤",25},
	{11,"爆炒酸脆","酸甜","热菜",38},
	{12,"蒜香小龙虾","咸味","热菜",98},
	{13,"一桶天下","咸味","热菜",83},
	{14,"红烧秋刀鱼","红烧","热菜",53},
	{15,"油炸大虾","咸味","热菜",45},
	{16,"西湖牛肉羹","咸味","汤",33},
	{17,"一品甜牛","甜味","凉菜",18},
	{18,"源氏扣肉","咸味","热菜",30},
	{19,"水果拼盘2","甜味","甜品",13},
	{20,"杨枝甘露","甜味","甜品",28}};
	Custome q[20]={{1,"陈志腾","男","18750176089","28",{1,2,5,7,8,20,19,5},0,0},
	{2,"王楠","男","17766107049","5",{1,3,6,7,8,9},0,0},
	{3,"李光","女","18851821076","18",{2,3,7,8},0,0},
	{4,"张嘉豪","男","13681452850","21",{4,13,17,9,7,8},0,0},
	{5,"陈雪瑞","女","13657421048","270",{4,5,6,7,8},0,0},
	{6,"张秩序","男","13123161269","2701",{4,5,8,20},0,0},
	{7,"刘一夫","男","13799434844","2991",{14,15,16,7,8},0,0},
	{8,"张梦洁","女","13802501687","2837",{4,5,16,7,18},0,0},
	{9,"吴梅芳","女","13654807040","2741",{4,11,12,17,8},0,0},
	{10,"陈一天","男","13985252850","1264",{4,13,16,7,20},0,0},
	{11,"侯正","男","13210522450","689",{4,5,6,7,8,11,13,15,17,19},0,0},
	{12,"张良","男","13628282584","656",{1,2,3,7,8,20},0,0},
	{13,"张帅","男","13513662584","2375",{4,5,6,17,18,20},0,0},
	{14,"吴广","男","13315345314","3678",{4,5,16,7,18,20},0,0},
	{15,"江峰","男","13628435143","227",{14,5,16,7,8,20},0,0},
	{16,"姜子旭","男","13668738566","70",{14,5,16,7,18,20},0,0},
	{17,"孟浩然","男","138388282584","5027",{4,5,20},0,0},
	{18,"张越","男","13776842584","27",{4,5,8,20},0,0},
	{19,"张额","男","13628282996","127",{1,7,8,20},0,0},
	{20,"黄光宇","男","13625492584","527",{8,20},0,0}};
	FILE *fp = fopen("database.txt", "w");
	fwrite(p, sizeof(p), 1, fp);
	fwrite(q, sizeof(q), 1, fp);*/ 
  int flag,k=1;
  char a[12],adm[12]="18750176089";
  char b[7],key[7]="980829";
  Jm();
  gotoxy(25,2);
  printf("请输入账号:");
  scanf("%s",a);
  gotoxy(25,3);
  printf("请输入密码:");
  scanf("%s",b);
  if(!strcmp(a,adm)&&!strcmp(b,key))
  {
	  gotoxy(25,4);
	  printf("输入正确");
	  startup();
  while(k)
  {
  Jm();
  gotoxy(25,2);
  printf("Chaiman餐厅管理系统\n");
  gotoxy(25,3);
  printf("1.输入桌号查询点单\n");
  gotoxy(25,4);
  printf("2.输入手机号查询点单\n");
  gotoxy(25,5);
  printf("3.输入会员卡号查询点单\n");
  gotoxy(25,6);
  printf("4.添加会员\n");
  gotoxy(25,7);
  printf("5.打印会员信息表\n");
  gotoxy(25,8);
  printf("6.清空当天点菜清单\n");
  gotoxy(25,9);
  scanf("%d",&flag);
  fflush(stdin);
  switch(flag)
  {
  case 1:tableNum();system("pause");system("cls");break;
  case 2:telNum();system("pause");system("cls");break;
  case 3:id();system("pause");system("cls");break;
  case 4:add();system("pause");system("cls");break;
  case 5:draw();system("pause");system("cls");break;
  case 6:delet();system("pause");system("cls");break;
  case 7:k=0;break;
  }
  }
  }
  else
  {
	  gotoxy(25,4);
      printf("密码错误");
  }
}
