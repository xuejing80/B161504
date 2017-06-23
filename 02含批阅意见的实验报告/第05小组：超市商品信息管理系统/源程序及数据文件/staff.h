/* ①student.h文件的完整内容 */
#ifndef _STAFF             /*条件编译，防止重复包含的错误*/
#define _STAFF
#include<string.h>
#define NUM 20                /*定义商品记录常量，此处可以根据实际需要修改常量值*/
struct Staff                   /*商品记录的数据域*/
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
#define sizeSta sizeof(Staff)      /*一件商品记录所需要的内存空间大小*/
int readSta(Staff sta[],int n);       /*读入商品记录值，编号为0或读满规定条数记录时停止*/
void printSta(Staff *sta,int n);   /*输出所有商品记录的值*/
int equal(Staff s1,Staff s2,int condition);  /*根据condition条件判断两个Staff类型数据相等否*/
int larger(Staff s1,Staff s2,int condition);  /*根据condition比较Staff类型数据大小*/
void reverse(Staff sta[],int n);             /*商品记录数组元素逆置*/
void calcuRank(Staff sta[],int n);           /*根据销售量给商品排名*/
void sortSta(Staff sta[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/
int searchSta(Staff sta[],int n,Staff s,int condition,int f[]);  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertSta(Staff sta[],int n,Staff s);                   /*向数组中插入一个元素按学号有序*/
int deleteSta(Staff sta[],int n,Staff s);                   /*从数组中删除一个指定学号的元素*/
int sellSta(Staff sta[],int n,Staff s);                     /*修改指定编号元素的库存与销售量*/
int check(char *ps);							/*判断输入的密码与预设密码是否一致*/
#endif
