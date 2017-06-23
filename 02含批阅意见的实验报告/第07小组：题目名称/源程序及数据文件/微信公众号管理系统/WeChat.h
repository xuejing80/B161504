#ifndef _WECHAT_H_
#define _WECHAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40

//公众号结构体
typedef struct OffiAccount{
	long date;			//日期
	char name[20];		//推送名称
	char gender[10];	//推送者性别
	int score[3];		//阅读量 点赞 转发
	int rank;			//推送排名
}OffiAccount;

//按阅读量+点赞量+转发量的总和降序
int cmpByTotal(const void *a, const void *b);

//按阅读量*50% +点赞量*30% +转发量*20% 的加权降序
int cmpByWeight(const void *a, const void *b);

//按阅读量降序
int cmpByRead(const void *a, const void *b);

//按点赞量降序
int cmpBySupport(const void *a, const void *b);

//按转发量降序
int cmpByTransfer(const void *a, const void *b);

//按时间升序
int cmpByTime(const void *a, const void *b);


//读信息
int ReadFromFile(OffiAccount acc[]);

//写到控制台
void OutputToConsole(OffiAccount acc[], int num);

//写到文件
void OutputToFile(OffiAccount acc[], int num);

//更新rank值
void UpdateRank(OffiAccount acc[], int num);

//添加推送信息
void AddPushInfo();

//修改推送信息
void ModifyPushInfo();

//删除推送信息
void DeletePushInfo();

//统计近期数据
void SumaryRecentData();

#endif