/* ��student.h�ļ����������� */
#ifndef _CAR            /*�������룬��ֹ�ظ������Ĵ���*/
#define _CAR
#include <string.h>
#define NUM 50                /*�������������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct CAR                   /*������¼��������*/
{
		long num;
		char name[20];
	
		int p1;
		int p2;
		int p3;
		int rank;                                                                                                                                                                                                                                                                                                                                                            
};
typedef struct CAR CAR;
#define sizeC sizeof(CAR)      /*һ��������¼����Ҫ���ڴ�ռ��С*/
int readC(CAR c[],int n);       /*����������¼ֵ�������涨������¼ʱֹͣ*/
void printC(CAR  *c , int n);   /*�������������¼��ֵ*/

int equal(CAR c1,CAR c2,int condition);  /*����condition�����ж�����CAR����������ȷ�*/
int larger(CAR c1,CAR c2,int condition);  /*����condition�Ƚ�CAR�������ݴ�С*/
void reverse(CAR c[],int n);             /*������¼����Ԫ������*/
void calcuRank(CAR c[],int n);
void printrank(CAR c[],int n);

void sortC(CAR c[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchC(CAR c[],int n,CAR ca,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertC(CAR c[],int n,CAR ca);                   /*�������в���һ��Ԫ�ذ��������*/
int deleteC(CAR c[],int n,CAR ca);                   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/
#endif
