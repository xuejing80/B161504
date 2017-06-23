/* ��student.h�ļ����������� */
#ifndef _STAFF             /*�������룬��ֹ�ظ������Ĵ���*/
#define _STAFF
#include<string.h>
#define NUM 20                /*������Ʒ��¼�������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Staff                   /*��Ʒ��¼��������*/
{
	long num;
	char name[20];
	char kind[20];
	double price;
	int inventory;
	int account;
	int rank;
};
typedef struct Staff Staff;
#define sizeSta sizeof(Staff)      /*һ����Ʒ��¼����Ҫ���ڴ�ռ��С*/
int readSta(Staff sta[],int n);       /*������Ʒ��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printSta(Staff *sta,int n);   /*���������Ʒ��¼��ֵ*/
int equal(Staff s1,Staff s2,int condition);  /*����condition�����ж�����Staff����������ȷ�*/
int larger(Staff s1,Staff s2,int condition);  /*����condition�Ƚ�Staff�������ݴ�С*/
void reverse(Staff sta[],int n);             /*��Ʒ��¼����Ԫ������*/
void calcuRank(Staff sta[],int n);           /*��������������Ʒ����*/
void sortSta(Staff sta[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
int searchSta(Staff sta[],int n,Staff s,int condition,int f[]);  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertSta(Staff sta[],int n,Staff s);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deleteSta(Staff sta[],int n,Staff s);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
int sellSta(Staff sta[],int n,Staff s);                     /*�޸�ָ�����Ԫ�صĿ����������*/
int check(char *ps);							/*�ж������������Ԥ�������Ƿ�һ��*/
#endif
