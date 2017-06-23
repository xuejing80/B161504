#include "WeChat.h"

//���Ķ���+������+ת�������ܺͽ���
int cmpByTotal(const void *a, const void *b)  
{  
    const OffiAccount *p = a;  
    const OffiAccount *q = b;  
	
    return (q->score[0]+q->score[1]+q->score[2])-(p->score[0]+p->score[1]+p->score[2]);
}  

//���Ķ���*50% +������*30% +ת����*20% �ļ�Ȩ����
int cmpByWeight(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b;  
	
    return (q->score[0]*0.5+q->score[1]*0.3+q->score[2]*0.2)-(p->score[0]*0.5+p->score[1]*0.3+p->score[2]*0.2);
}

//���Ķ�������
int cmpByRead(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[0] - p->score[0];
}

//������������
int cmpBySupport(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[1] - p->score[1];
}

//��ת��������
int cmpByTransfer(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b; 
	return q->score[2] - p->score[2];
}

//��ʱ������
int cmpByTime(const void *a, const void *b)
{
	const OffiAccount *p = a;  
    const OffiAccount *q = b;
	return p->date-q->date;
}

//�ж�����OffiAccount�Ƿ���ȣ��˴���Ҫ��rankһ��
int EqualExceptRank(const OffiAccount a, const OffiAccount b)
{
	if(a.date==b.date && strcmp(a.name, b.name)==0 && strcmp(a.gender, b.gender)==0
		&& a.score[0]==b.score[0] && a.score[1]==b.score[1] && a.score[2]==b.score[2])
		return 1;
	else
		return 0;
}

//����Ϣ
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

//д������̨
void OutputToConsole(OffiAccount acc[], int num)
{
	int i;
	printf("���\t����\t\t��������\t�Ա�\t�Ķ���\t������\tת����\t����\n");
	for(i=0; i<num; i++)
	{
		printf("%d\t%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n",i+1, acc[i].date, acc[i].name, acc[i].gender, acc[i].score[0], 
			acc[i].score[1], acc[i].score[2], acc[i].rank);
	}
}

//д���ļ�
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


//����rankֵ
void UpdateRank(OffiAccount acc[], int num)
{
	int i, j;
	OffiAccount* info_copy = (OffiAccount*)malloc(num*sizeof(OffiAccount));
	memcpy(info_copy, acc, num*sizeof(OffiAccount));

	//����
	qsort(info_copy, num, sizeof(OffiAccount), cmpByTotal);
	//������֮�󣬶�rank���¸�ֵ
	for(i=0; i<num; i++)
	{
		info_copy[i].rank = i+1;
	}

	//�����º��rankֵ�ָ���acc��
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

//�����Ϣ���ļ�
void AddPushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	
	int num = 0;
	num = ReadFromFile(info);

	printf("***���������Ϣ***\n");
	printf("���ڣ���ʽ��20170615��: ");
	scanf("%ld", &acc.date);
	printf("��������: ");
	scanf("%s", acc.name);
	printf("�������Ա�: ");
	scanf("%s", acc.gender);
	printf("�Ķ���: ");
	scanf("%d", &acc.score[0]);
	printf("������: ");
	scanf("%d", &acc.score[1]);
	printf("ת����: ");
	scanf("%d", &acc.score[2]);
	//������Ҫ�޸ģ���ȡ�����ļ����ٽ�������
	acc.rank = -1;

	info[num] = acc;

	UpdateRank(info, num+1);

	//���µĽ��д�뵽�ļ���
	OutputToFile(info, num+1);
}


//�޸���Ϣ���ļ�
void ModifyPushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	int num = 0;
	int n;
	num = ReadFromFile(info);
	
	printf("***�޸�������Ϣ***\n");
	OutputToConsole(info, num);	

	printf("������ѡ��Ҫ�޸ĵ�������Ϣ: ");
	scanf("%d", &n);

	printf("���ڣ���ʽ��20170615��: ");
	scanf("%ld", &acc.date);
	printf("��������: ");
	scanf("%s", acc.name);
	printf("�������Ա�: ");
	scanf("%s", acc.gender);
	printf("�Ķ���: ");
	scanf("%d", &acc.score[0]);
	printf("������: ");
	scanf("%d", &acc.score[1]);
	printf("ת����: ");
	scanf("%d", &acc.score[2]);
	//������Ҫ�޸ģ���ȡ�����ļ����ٽ�������
	acc.rank = -1;
	
	info[n-1] = acc;
	UpdateRank(info, num);
	
	//���µĽ��д�뵽�ļ���
	OutputToFile(info, num);
}

//ɾ����Ϣ���ļ�
void DeletePushInfo()
{
	OffiAccount acc;
	OffiAccount info[NUM];
	int num = 0;
	int n, i=0;
	FILE* fp;

	num = ReadFromFile(info);
	
	printf("***ɾ��������Ϣ***\n");
	OutputToConsole(info, num);	
	
	printf("������ѡ��Ҫɾ����������Ϣ: ");
	scanf("%d", &n);

	//�Ƚ�����ˢ��Ϊ0���������µ�rank��Ȼ���ٻָ�score
	acc = info[n-1];
	info[n-1].score[0] = 0;
	info[n-1].score[1] = 0;
	info[n-1].score[2] = 0;
	UpdateRank(info, num);
	info[n-1].score[0] = acc.score[0];
	info[n-1].score[1] = acc.score[1];
	info[n-1].score[2] = acc.score[2];
	
	//���µĽ��д�뵽�ļ���
	fp = fopen("data.txt", "w");
	for(i=0; i<num; i++)
	{
		if(!EqualExceptRank(acc, info[i]))
			fprintf(fp, "%ld\t%s\t%s\t%d\t%d\t%d\t%d\n", info[i].date, info[i].name, info[i].gender, info[i].score[0], 
				info[i].score[1], info[i].score[2], info[i].rank);
	}
	fclose(fp);
}


//ͳ�ƽ�������
void SumaryRecentData()
{
	long lStart, lEnd;
	OffiAccount info[NUM];
	int nPush=0, nRead=0, nSupport=0, nTransfer=0;	//�ܵ����������Ķ�������������ת����
	int i, num = 0;

	num = ReadFromFile(info);

	printf("***ͳ�ƽ�������***\n");
	printf("��ʼ���ڣ���ʽ��20170614��: ");
	scanf("%ld", &lStart);
	printf("�������ڣ���ʽ��20170615��: ");
	scanf("%ld", &lEnd);

	for(i=0; i<num; i++)
	{
		//��ʱ��������
		if(info[i].date>=lStart && info[i].date<=lEnd)
		{
			nPush ++;
			nRead += info[i].score[0];
			nSupport += info[i].score[1];
			nTransfer += info[i].score[2];
		}
	}

	printf("��%ld-%ld�����ڣ�������%d����Ϣ�����Ķ���:%d���ܵ�����:%d����ת����:%d\n",
		lStart, lEnd, nPush, nRead, nSupport, nTransfer);
}