#include "WeChat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��½����½ʧ�ܷ���0
int Login();

//�ܲ˵�
void Menu();

//��ʾ������Ϣ
void ShowInfo();

//������Ϣ����˵�
void BasicInfoManageMenu();

//������Ϣ����˵�
void PushInfoManageMenu();

//������Ϣͳ�Ʋ˵�
void PushInfoSumaryMenu();

//�ؼ���ɸѡ��ѯ
void KeywordQuery();

//���������ۺ���������Ȩ����
void SortByWeight();

//��ʾ����Ķ���
void ShowMostRead();
//��ʾ��ߵ�����
void ShowMostSupport();
//��������˳����Ʊ�
void ShowTableByTime();
void aValue();

int main()
{
// 	//û�е�½�ɹ���һֱ��½
 	while(Login()==0)
 	{
 		printf("����������µ�½!\n");
 		getchar();
 	}

	Menu();

	system("pause");
	return 0;
}


//��½����½ʧ�ܷ���0
int Login()
{
	char user[20], userFile[20];
	char psw[20], pswFile[20];
	FILE* fp;

	system("cls");
	fflush(stdin);
	printf("===����Ա��½===\n");
	printf("�û���: ");
	scanf("%s", user);
	printf("��  ��: ");
	scanf("%s", psw);

	fp = fopen("user.txt", "r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s", userFile, pswFile);
		if(strcmp(user, userFile)==0 && strcmp(psw, pswFile)==0)
		{
			printf("��½�ɹ�!\n");
			return 1;
		}
	}
	fclose(fp);
	printf("��½ʧ��!\n");
	fflush(stdin);

	return 0;
}


//�ܲ˵�
void Menu()
{
	int nFunc = -1;

	do 
	{
		system("cls");
		fflush(stdin);
		printf("======΢�Ź��ںŹ���ϵͳ======\n");
		printf("\t1 --> ��ʾ������Ϣ\n");
		printf("\t2 --> ������Ϣ����\n");
		printf("\t3 --> ��Ҫ���ѯ��Ϣ\n");
		printf("\t4 --> ������Ϣͳ��\n");
		printf("\t5 --> ���ͼ�ֵ��ʾ\n");
		printf("\t0 --> �˳�\n");
		
		printf("�������Ӧ���ѡ����: ");
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
			printf("�����������!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}

//��ʾ������Ϣ
void ShowInfo()
{
	OffiAccount info[NUM];
	int num;
	num = ReadFromFile(info);
	OutputToConsole(info, num);
}


//������Ϣ����˵�
void BasicInfoManageMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======������Ϣ����======\n");
		printf("\t1 --> ���������Ϣ\n");
		printf("\t2 --> �޸����͹���\n");
		printf("\t3 --> ɾ�����͹���\n");
		printf("\t0 --> ������һ��Ŀ¼\n");
		
		printf("�������Ӧ���ѡ����: ");
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
			printf("�����������!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
	
}

//������Ϣ����˵�
void PushInfoManageMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======������Ϣͳ��======\n");
		printf("\t1 --> ���ݹؼ�������\n");
		printf("\t2 --> ��ʱ������ͳ�ƽ�������\n");
		printf("\t3 --> ���������ۺ�����\n");
		printf("\t0 --> ������һ��Ŀ¼\n");
		
		printf("�������Ӧ���ѡ����: ");
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
			printf("�����������!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}

//������Ϣͳ�Ʋ˵�
void PushInfoSumaryMenu()
{
	int nFunc = -1;
	
	do 
	{
		system("cls");
		fflush(stdin);
		printf("======��Ҫ���ѯ��Ϣ======\n");
		printf("\t1 --> ��ʾ����Ķ�������\n");
		printf("\t2 --> ��ʾ��ߵ���������\n");
		printf("\t3 --> ����ʱ��˳����ʾ����\n");
		printf("\t0 --> ������һ��Ŀ¼\n");
		
		printf("�������Ӧ���ѡ����: ");
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
			printf("�����������!\n");
			fflush(stdin);
			getchar();
		}
	} while (nFunc!=0);
}


//�ؼ���ɸѡ��ѯ
void KeywordQuery()
{
	OffiAccount info[NUM];
	int n;
	int num = 0;
	num = ReadFromFile(info);
	printf("***���ؼ�������***\n");
	printf("\t1 --> �Ķ���\n");
	printf("\t2 --> ������\n");
	printf("\t3 --> ת����\n");
	printf("������ؼ��ʱ��: ");
	scanf("%d", &n);

	//��������Ĳ�ͬѡ��ͬ������ʽ
	if(n==1)
		qsort(info, num, sizeof(OffiAccount), cmpByRead);
	else if(n==2)
		qsort(info, num, sizeof(OffiAccount), cmpBySupport);
	else if(n==3)
		qsort(info, num, sizeof(OffiAccount), cmpByTransfer);

	OutputToConsole(info, num);
}


//���������ۺ���������Ȩ����
void SortByWeight()
{
	OffiAccount info[NUM];
	int num = 0;
	num = ReadFromFile(info);
	
	printf("***���������ۺ�����***\n");
	qsort(info, num, sizeof(OffiAccount), cmpByWeight);
	
	OutputToConsole(info, num);
}

//��ʾ����Ķ���
void ShowMostRead()
{
	OffiAccount info[NUM];
	int num = 0;
	int n;	//�������Ķ���������λ��
	int i, most=-1;
	num = ReadFromFile(info);
	
	printf("***��ʾ����Ķ���***\n");
	for(i=0; i<num; i++)
	{
		if(info[i].score[0] > most)
		{
			n = i;
			most = info[i].score[0];
		}
	}
	
	printf("����\t\t��������\t�Ա�\t�Ķ���\t������\tת����\t����\n");
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank);
}
//��ʾ��ߵ�����
void ShowMostSupport()
{
	OffiAccount info[NUM];
	int num = 0;
	int n;	//�����ߵ�����������λ��
	int i, most=-1;
	num = ReadFromFile(info);
	
	printf("***��ʾ��ߵ�����***\n");
	for(i=0; i<num; i++)
	{
		if(info[i].score[1] > most)
		{
			n = i;
			most = info[i].score[1];
		}
	}
	
	printf("����\t\t��������\t�Ա�\t�Ķ���\t������\tת����\t����\n");
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank);
}
//��������˳����Ʊ�
void ShowTableByTime()
{
	OffiAccount info[NUM];
	int num = 0;
	num = ReadFromFile(info);
	
	printf("***��������˳����Ʊ�***\n");
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
	printf("����\t\t��������\t�Ա�\t�Ķ���\t������\tת����\t����\t��ֵ\n");
	
for(i=1;i<num;i++)
{
	n=i;
	k=info[n].score[2]*1+info[n].score[1]*1;
	printf("%ld\t%s\t\t%s\t%d\t%d\t%d\t%d\t%d\n", info[n].date, info[n].name, info[n].gender, info[n].score[0], 
			info[n].score[1], info[n].score[2], info[n].rank,k);
	j=j+k;
}
    printf("΢�����͵��ܼ�ֵΪ%d\n",j);
}

