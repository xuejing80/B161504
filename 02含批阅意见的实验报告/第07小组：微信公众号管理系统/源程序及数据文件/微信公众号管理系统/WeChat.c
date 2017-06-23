#include "WeChat.h"

//按阅读量+点赞量+转发量的总和降序
int cmpByTotal(const void *a, const void *b)  
{  
    const OffiAccount *p = a;  
    const OffiAccount *q = b;  
	
    return (q->score[0]+q->score[1]+q->score[2])-(p->score[0]+p->score[1]+p->score[2]);
}  

//按阅读量*50% +点赞量*30% +转发量*20% 的加权降序
int cmpByWeight(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b;  
	
    return (q->score[0]*0.5+q->score[1]*0.3+q->score[2]*0.2)-(p->score[0]*0.5+p->score[1]*0.3+p->score[2]*0.2);
}

//按阅读量降序
int cmpByRead(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[0] - p->score[0];
}

//按点赞量降序
int cmpBySupport(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[1] - p->score[1];
}

//按转发量降序
int cmpByTransfer(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[2] - p->score[2];
}

//按时间升序
int cmpByTime(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b;
	return p->date-q->date;
}

//判断两个OffiAccount是否相等，此处不要求rank一样
int EqualExceptRank(const OffiAccount a, const OffiAccount b)
{
	if(a.date==b.date && strcmp(a.name, b.name)==0 && strcmp(a.gender, b.gender)==0
		&& a.score[0]==b.score[0] && a.score[1]==b.score[1] && a.score[2]==b.score[2])
		return 1;
	else
		return 0;
}

//读信息
int ReadFromFile(OffiAccount acc[])
{
	FILE* fp = fopen("data.txt", "r");
	int num = 0;

	while(fscanf(fp, "%ld\t%s\t%s\t%d\t%d\t%d\t%d\n", &acc[num].date, acc[num].name, acc[num].gender, &acc[num].score[0], 
			&acc[num].score[1], &acc[num].score[2], &acc[num].rank) != EOF)
	{
// 		fscanf(fp, "%ld\t%s\t%s\t%d\t%d\t%d\t%d", &acc[num].date, acc[num].name, acc[num].gender, &acc[num].score[0], 
// 			&acc[num].score[1], &acc[num].score[2], &acc[num].rank);
		num ++;
	}

	fclose(fp);
	return num;
}

//写到控制台
void OutputToConsole(OffiAccount acc[], int num)
{
	int i;
	printf("编号\t日期\t\t推送名称\t性别\t阅读量\t点赞数\t转发数\t排名\n");
	for(i=0; i<num; i++)
	{
		printf("%d\t%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n",i+1, acc[i].date, acc[i].name, acc[i].gender, acc[i].score[0], 
			acc[i].score[1], acc[i].score[2], acc[i].rank);
	}
}

//写到文件
void OutputToFile(OffiAccount acc[], int num)
{
	int i;
	FILE* fp = fopen("data.txt", "w");
	for(i=0; i<num; i++)
	{
		fprintf(fp, "%ld\t%s\t%s\t%d\t%d\t%d\t%d\n", acc[i].date, acc[i].name, acc[i].gender, acc[i].score[0], 
			acc[i].score[1], acc[i].score[2], acc[i].rank);
	}
	fclose(fp);
}


//更新rank值
void UpdateRank(OffiAccount acc[], int num)
{
	int i, j;
	OffiAccount* info_copy = (OffiAccount*)malloc(num*sizeof(OffiAccount));
	memcpy(info_copy, acc, num*sizeof(OffiAccount));

	//排序
	qsort(info_copy, num, sizeof(OffiAccount), cmpByTotal);
	//排序完之后，对rank重新赋值
	for(i=0; i<num; i++)
	{
		info_copy[i].rank = i+1;
	}

	//将更新后的rank值恢复到acc中
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			if(EqualExceptRank(acc[i], info_copy[j]))
			{
				acc[i].rank = info_copy[j].rank;
				break;
			}
		}
	}

	free(info_copy);
}

//添加信息到文件
void AddPushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	
	int num = 0;
	num = ReadFromFile(info);

	printf("***添加推送消息***\n");
	printf("日期（格式如20170615）: ");
	scanf("%ld", &acc.date);
	printf("推送名称: ");
	scanf("%s", acc.name);
	printf("推送者性别: ");
	scanf("%s", acc.gender);
	printf("阅读量: ");
	scanf("%d", &acc.score[0]);
	printf("点赞量: ");
	scanf("%d", &acc.score[1]);
	printf("转发量: ");
	scanf("%d", &acc.score[2]);
	//后面需要修改，读取整个文件，再进行排名
	acc.rank = -1;

	info[num] = acc;

	UpdateRank(info, num+1);

	//将新的结果写入到文件中
	OutputToFile(info, num+1);
}


//修改信息到文件
void ModifyPushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	int num = 0;
	int n;
	num = ReadFromFile(info);
	
	printf("***修改推送消息***\n");
	OutputToConsole(info, num);	

	printf("输入编号选择要修改的推送消息: ");
	scanf("%d", &n);

	printf("日期（格式如20170615）: ");
	scanf("%ld", &acc.date);
	printf("推送名称: ");
	scanf("%s", acc.name);
	printf("推送者性别: ");
	scanf("%s", acc.gender);
	printf("阅读量: ");
	scanf("%d", &acc.score[0]);
	printf("点赞量: ");
	scanf("%d", &acc.score[1]);
	printf("转发量: ");
	scanf("%d", &acc.score[2]);
	//后面需要修改，读取整个文件，再进行排名
	acc.rank = -1;
	
	info[n-1] = acc;
	UpdateRank(info, num);
	
	//将新的结果写入到文件中
	OutputToFile(info, num);
}

//删除信息到文件
void DeletePushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	int num = 0;
	int n, i=0;
	FILE* fp;

	num = ReadFromFile(info);
	
	printf("***删除推送消息***\n");
	OutputToConsole(info, num);	
	
	printf("输入编号选择要删除的推送消息: ");
	scanf("%d", &n);

	//先将数据刷新为0，方便获得新的rank，然后再恢复score
	acc = info[n-1];
	info[n-1].score[0] = 0;
	info[n-1].score[1] = 0;
	info[n-1].score[2] = 0;
	UpdateRank(info, num);
	info[n-1].score[0] = acc.score[0];
	info[n-1].score[1] = acc.score[1];
	info[n-1].score[2] = acc.score[2];
	
	//将新的结果写入到文件中
	fp = fopen("data.txt", "w");
	for(i=0; i<num; i++)
	{
		if(!EqualExceptRank(acc, info[i]))
			fprintf(fp, "%ld\t%s\t%s\t%d\t%d\t%d\t%d\n", info[i].date, info[i].name, info[i].gender, info[i].score[0], 
				info[i].score[1], info[i].score[2], info[i].rank);
	}
	fclose(fp);
}


//统计近期数据
void SumaryRecentData()
{
	long lStart, lEnd;
	OffiAccount info[NUM];
	int nPush=0, nRead=0, nSupport=0, nTransfer=0;	//总的推送数、阅读量、点赞量、转发量
	int i, num = 0;

	num = ReadFromFile(info);

	printf("***统计近期数据***\n");
	printf("开始日期（格式如20170614）: ");
	scanf("%ld", &lStart);
	printf("结束日期（格式如20170615）: ");
	scanf("%ld", &lEnd);

	for(i=0; i<num; i++)
	{
		//在时间区间内
		if(info[i].date>=lStart && info[i].date<=lEnd)
		{
			nPush ++;
			nRead += info[i].score[0];
			nSupport += info[i].score[1];
			nTransfer += info[i].score[2];
		}
	}

	printf("在%ld-%ld区间内，共推送%d条消息，总阅读量:%d，总点赞量:%d，总转发量:%d\n",
		lStart, lEnd, nPush, nRead, nSupport, nTransfer);
}