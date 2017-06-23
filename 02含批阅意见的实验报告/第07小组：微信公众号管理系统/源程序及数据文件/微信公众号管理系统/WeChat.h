#ifndef _WECHAT_H_
#define _WECHAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 40

//���ںŽṹ��
typedef struct OffiAccount{
	long date;			//����
	char name[20];		//��������
	char gender[10];	//�������Ա�
	int score[3];		//�Ķ��� ���� ת��
	int rank;			//��������
}OffiAccount;

//���Ķ���+������+ת�������ܺͽ���
int cmpByTotal(const void *a, const void *b);

//���Ķ���*50% +������*30% +ת����*20% �ļ�Ȩ����
int cmpByWeight(const void *a, const void *b);

//���Ķ�������
int cmpByRead(const void *a, const void *b);

//������������
int cmpBySupport(const void *a, const void *b);

//��ת��������
int cmpByTransfer(const void *a, const void *b);

//��ʱ������
int cmpByTime(const void *a, const void *b);


//����Ϣ
int ReadFromFile(OffiAccount acc[]);

//д������̨
void OutputToConsole(OffiAccount acc[], int num);

//д���ļ�
void OutputToFile(OffiAccount acc[], int num);

//����rankֵ
void UpdateRank(OffiAccount acc[], int num);

//���������Ϣ
void AddPushInfo();

//�޸�������Ϣ
void ModifyPushInfo();

//ɾ��������Ϣ
void DeletePushInfo();

//ͳ�ƽ�������
void SumaryRecentData();

#endif