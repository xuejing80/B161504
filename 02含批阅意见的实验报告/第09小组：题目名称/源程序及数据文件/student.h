/* ①student.h文件的完整内容 */
#ifndef _CAR            /*条件编译，防止重复包含的错误*/
#define _CAR
#include <string.h>
#define NUM 50                /*定义学生人数常量，此处可以根据实际需要修改常量值*/
struct CAR                   /*学生记录的数据域*/
{
		long num;
		char name[20];
	
		int p1;
		int p2;
		int p3;
};
typedef struct CAR CAR;
#define sizeC sizeof(CAR)      /*一个学生记录所需要的内存空间大小*/
int readC(CAR c[],int n);       /*读入学生记录值，学号为0或读满规定条数记录时停止*/
void printC(CAR  *c , int n);   /*输出所有学生记录的值*/

int equal(CAR c1,CAR c2,int condition);  /*根据condition条件判断两个Student类型数据相等否*/
int larger(CAR c1,CAR c2,int condition);  /*根据condition比较Student类型数据大小*/
void reverse(CAR c[],int n);             /*学生记录数组元素逆置*/



void sortC(CAR c[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchC(CAR c[],int n,CAR ca,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertC(CAR c[],int n,CAR ca);                   /*向数组中插入一个元素按学号有序*/
int deleteC(CAR c[],int n,CAR ca);                   /*从数组中删除一个指定学号的元素*/
#endif
