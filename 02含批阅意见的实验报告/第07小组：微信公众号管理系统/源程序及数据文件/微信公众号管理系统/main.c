#include "WeChat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//登陆，登陆失败返回0
int Login();

//总菜单
void Menu();

//显示基本信息
void ShowInfo();

//基本信息管理菜单
void BasicInfoManageMenu();

//推送信息管理菜单
void PushInfoManageMenu();

//推送信息统计菜单
void PushInfoSumaryMenu();

//关键词筛选查询
void KeywordQuery();

//根据数据综合排名（加权排序）
void SortByWeight();

//显示最高阅读量
void ShowMostRead();
//显示最高点赞量
void ShowMostSupport();
//根据推送顺序绘制表
void ShowTableByTime();
void aValue();

int main()
{
// 	//没有登陆成功就一直登陆
 	while(Login()==0)
 	{
 		printf("按任意键重新登陆!\n");
 		getchar();
 	}

	Menu();

	system("pause");
	return 0;
}


//登陆，登陆失败返回0
int Login()
{
	char user[20], userFile[20];
	char psw[20], pswFile[20];
	FILE* fp;

	system("cls");
	fflush(stdin);
	printf("===管理员登陆===\n");
	printf("用户名: ");
	scanf("%s", user);
	printf("密  码: ");
	scanf("%s", psw);

	fp = fopen("user.txt", "r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s", userFile, pswFile);
		if(strcmp(user, userFile)==0 && strcmp(psw, pswFile)==0)
		{
			printf("登陆成功!\n");
			return 1;
		}
	}
	fclose(fp);
	printf("登陆失败!\n");
	fflush(stdin);

	return 0;
}


//总菜单
void Menu()
{
	int nFunc = -1;

	do 
	{
		system("cls");
		fflush(stdin);
		printf("======微信公众号管理系统======\n");
		printf("\t1 --> 显示基本信息\n");
		printf("\t2 --> 基本信息管理\n");
		printf("\t3 --> 按要求查询信息\n");
		printf("\t4 --> 推送信息统计\n");
		printf("\t5 --> 推送价值显示\n");
		printf("\t0 --> 退出\n");
		
		printf("请输入对应编号选择功能: ");
		scanf("%d", &nFunc);
		switch (nFunc)
		{
		case 1:
			ShowInfo();
			break;
		case 2:
			BasicInfoManageMenu();
			break;
		case 4:
			PushInfoManageMenu();
			break;
		case 3:
			PushInfoSumaryMenu();
			break;
		case 5:
			aValue();
			break;
		default:
			break;
		}

		if(nFunc != 0)
		{
			printf("按任意键继续!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}

//显示基本信息
void ShowInfo()
{
	OffiAccount info[NUM];
	int num;
	num = ReadFromFile(info);
	OutputToConsole(info, num);
}


//基本信息管理菜单
void BasicInfoManageMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======基本信息管理======\n");
		printf("\t1 --> 添加推送信息\n");
		printf("\t2 --> 修改推送管理\n");
		printf("\t3 --> 删除推送管理\n");
		printf("\t0 --> 返回上一级目录\n");
		
		printf("请输入对应编号选择功能: ");
		scanf("%d", &nFunc);
		switch (nFunc)
		{
		case 1:
			AddPushInfo();
			break;
		case 2:
			ModifyPushInfo();
			break;
		case 3:
			DeletePushInfo();
			break;
		default:
			break;
		}

		if(nFunc != 0)
		{
			printf("按任意键继续!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
	
}

//推送信息管理菜单
void PushInfoManageMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======推送信息统计======\n");
		printf("\t1 --> 根据关键词排序\n");
		printf("\t2 --> 按时间区间统计近期数据\n");
		printf("\t3 --> 根据数据综合排名\n");
		printf("\t0 --> 返回上一级目录\n");
		
		printf("请输入对应编号选择功能: ");
		scanf("%d", &nFunc);
		switch (nFunc)
		{
		case 1:
			KeywordQuery();
			break;
		case 2:
			SumaryRecentData();
			break;
		case 3:
			SortByWeight();
			break;
		default:
			break;
		}

		if(nFunc != 0)
		{
			printf("按任意键继续!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}

//推送信息统计菜单
void PushInfoSumaryMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======按要求查询信息======\n");
		printf("\t1 --> 显示最高阅读量推送\n");
		printf("\t2 --> 显示最高点赞量推送\n");
		printf("\t3 --> 根据时间顺序显示推送\n");
		printf("\t0 --> 返回上一级目录\n");
		
		printf("请输入对应编号选择功能: ");
		scanf("%d", &nFunc);
		switch (nFunc)
		{
		case 1:
			ShowMostRead();
			break;
		case 2:
			ShowMostSupport();
			break;
		case 3:
			ShowTableByTime();
			break;
		default:
			break;
		}

		if(nFunc != 0)
		{
			printf("按任意键继续!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}


//关键词筛选查询
void KeywordQuery()
{
	OffiAccount info[NUM];
	int n;
	int num = 0;
	num = ReadFromFile(info);
	printf("***按关键词排序***\n");
	printf("\t1 --> 阅读量\n");
	printf("\t2 --> 点赞量\n");
	printf("\t3 --> 转发量\n");
	printf("请输入关键词编号: ");
	scanf("%d", &n);

	//根据输入的不同选择不同的排序方式
	if(n==1)
		qsort(info, num, sizeof(OffiAccount), cmpByRead);
	else if(n==2)
		qsort(info, num, sizeof(OffiAccount), cmpBySupport);
	else if(n==3)
		qsort(info, num, sizeof(OffiAccount), cmpByTransfer);

	OutputToConsole(info, num);
}


//根据数据综合排名（加权排序）
void SortByWeight()
{
	OffiAccount info[NUM];
	int num = 0;
	num = ReadFromFile(info);
	
	printf("***根据数据综合排名***\n");
	qsort(info, num, sizeof(OffiAccount), cmpByWeight);
	
	OutputToConsole(info, num);
}

//显示最高阅读量
void ShowMostRead()
{
	OffiAccount info[NUM];
	int num = 0;
	int n;	//标记最高阅读量的推送位置
	int i, most=-1;
	num = ReadFromFile(info);
	
	printf("***显示最高阅读量***\n");
	for(i=0; i<num; i++)
	{
		if(info[i].score[0] > most)
		{
			n = i;
			most = info[i].score[0];
		}
	}
	
	printf("日期\t\t推送名称\t性别\t阅读量\t点赞数\t转发数\t排名\n");
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank);
}
//显示最高点赞量
void ShowMostSupport()
{
	OffiAccount info[NUM];
	int num = 0;
	int n;	//标记最高点赞量的推送位置
	int i, most=-1;
	num = ReadFromFile(info);
	
	printf("***显示最高点赞量***\n");
	for(i=0; i<num; i++)
	{
		if(info[i].score[1] > most)
		{
			n = i;
			most = info[i].score[1];
		}
	}
	
	printf("日期\t\t推送名称\t性别\t阅读量\t点赞数\t转发数\t排名\n");
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank);
}
//根据推送顺序绘制表
void ShowTableByTime()
{
	OffiAccount info[NUM];
	int num = 0;
	num = ReadFromFile(info);
	
	printf("***根据推送顺序绘制表***\n");
	qsort(info, num, sizeof(OffiAccount), cmpByTime);
	
	OutputToConsole(info, num);
}
void aValue()
{
	OffiAccount info[NUM];
	int n=0;
	int k;
	int num;
	int i;
	int j=0;
	num = ReadFromFile(info);
	printf("日期\t\t推送名称\t性别\t阅读量\t点赞数\t转发数\t排名\t价值\n");
	
for(i=1;i<num;i++)
{
	n=i;
	k=info[n].score[2]*1+info[n].score[1]*1;
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank,k);
	j=j+k;
}
    printf("微信推送的总价值为%d\n",j);
}

