/* ①car.h文件的完整内容 */
#ifndef _CAR            /*条件编译，防止重复包含的错误*/
#define _CAR
#include <string.h>
#define NUM 50                /*定义汽车数量常量，此处可以根据实际需要修改常量值*/
struct CAR                   /*汽车记录的数据域*/
{
		long num;
		char name[20];	
		int p1;
		int p2;
		int p3;
		int rank;
};
typedef struct CAR CAR;
#define sizeC sizeof(CAR)      /*一个汽车记录所需要的内存空间大小*/
int readC(CAR c[],int n);       /*读入汽车记录值，编号为0或读满规定条数记录时停止*/
void printC(CAR  *c , int n);   /*输出所有汽车记录的值*/

int equal(CAR c1,CAR c2,int condition);  /*根据condition条件判断两个CAR类型数据相等否*/
int larger(CAR c1,CAR c2,int condition);  /*根据condition比较CAR类型数据大小*/
void reverse(CAR c[],int n);             /*汽车记录数组元素逆置*/
void calcuRank(CAR c[],int n);        /*根据差价计算车辆的名次，允许有并列名次*/

void sortC(CAR c[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchC(CAR c[],int n,CAR ca,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertC(CAR c[],int n,CAR ca);                   /*向数组中插入一个元素按编号有序*/
int deleteC(CAR c[],int n,CAR ca);                   /*从数组中删除一个指定编号的元素*/
#endif
