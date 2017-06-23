/* ��student.h�ļ����������� */
#ifndef _STUDENT             /*�������룬��ֹ�ظ������Ĵ���*/
#define _STUDENT
#include <string.h>
#define NUM 20                /*����ѧ�������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Student                   /*ѧ����¼��������*/
{
		long num;
		char name[20];
		char sex[10];
		int score[3];
		int total;
		int rank;
};
typedef struct Student Student;
#define sizeStu sizeof(Student)      /*һ��ѧ����¼����Ҫ���ڴ�ռ��С*/
int readStu(Student stu[],int n);       /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
void printStu(Student  *stu , int n);   /*�������ѧ����¼��ֵ*/

int equal(Student s1,Student s2,int condition);  /*����condition�����ж�����Student����������ȷ�*/
int larger(Student s1,Student s2,int condition);  /*����condition�Ƚ�Student�������ݴ�С*/
void reverse(Student stu[],int n);             /*ѧ����¼����Ԫ������*/

void calcuTotal(Student stu[],int n);           /*��������ѧ�����ܷ�*/
void calcuRank(Student stu[],int n);           /*�����ּܷ���ѧ�������Σ������в�������*/
void calcuMark(double m[3][3],Student stu[],int n); /*�����ſε���ߡ���͡�ƽ���֣�m�����һά*/
/*��ʾ���ſΣ��ڶ�ά��ʾ��ߡ���͡�ƽ����*/

void sortStu(Student stu[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchStu(Student stu[],int n,Student s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertStu(Student stu[],int n,Student s);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deleteStu(Student stu[],int n,Student s);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
#endif
