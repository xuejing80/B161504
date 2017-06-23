/* ��sightspot.h�ļ����������� */
#ifndef _SIGHTSPOT             /*�������룬��ֹ�ظ������Ĵ���*/
#define _SIGHTSPOT
#include <string.h>
#define NUM 20                /*���徰����Ŀ�������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Sightspot                   /*�����¼��������*/
{
		long number;          /*���*/ 
		char place[20];       /*�ص�*/ 
		char name[20];        /*��������*/ 
		int num;              /*������*/ 
		int month;            /*�·�*/ 
		int rank;             /*����*/ 
};
typedef struct Sightspot Sightspot;
#define sizeSig sizeof(Sightspot)      /*һ�������¼����Ҫ���ڴ�ռ��С*/
int readSig(Sightspot sig[],int n);       /*���뾰���¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printSig(Sightspot *sig , int n);   /*������о����¼��ֵ*/
int equal(Sightspot s1,Sightspot s2,int condition);  /*����condition�����ж�����Sight spot����������ȷ�*/
int larger(Sightspot s1,Sightspot s2,int condition);  /*����condition�Ƚ�Sight spot�������ݴ�С*/
void reverse(Sightspot sig[],int n);             /*�����¼����Ԫ������*/
void calcuRank(Sightspot sig[],int n);           /*�������������㾰������Σ������в�������*/
void calcuMark(double m[20][2],Sightspot sig[],int n); /*���ʮ����������������ߡ���ͣ�m�����һά*/
/*��ʾ�ĸ����㣬�ڶ�ά��ʾ��ߡ����*/
void sortSig(Sightspot sig[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertSig(Sightspot sig[],int n,Sightspot s);                   /*�������в���һ��Ԫ�ذ��������*/
int deleteSig(Sightspot sig[],int n,Sightspot s);                   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/
int searchSig(Sightspot sig[], int n, Sightspot s, int condition, int f[]);/*������������������s��ȵĸ�Ԫ��*/
#endif


