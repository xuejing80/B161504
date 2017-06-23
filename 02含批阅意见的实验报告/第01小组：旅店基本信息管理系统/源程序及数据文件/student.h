/* ①student.h文件的完整内容 */
#ifndef _STUDENT             /*条件编译，防止重复包含的错误*/
#define _STUDENT
#include <string.h>
#define NUM 20                /*定义学生人数常量，此处可以根据实际需要修改常量值*/
struct Student                   /*学生记录的数据域*/
{
		long num;
		char name[20];
		char sex[10];
		int score[3];
		int total;
		int rank;
};
typedef struct Student Student;
#define sizeStu sizeof(Student)      /*一个学生记录所需要的内存空间大小*/
int readStu(Student stu[],int n);       /*读入学生记录值，学号为0或读满规定条数记录时停止*/
void printStu(Student  *stu , int n);   /*输出所有学生记录的值*/

int equal(Student s1,Student s2,int condition);  /*根据condition条件判断两个Student类型数据相等否*/
int larger(Student s1,Student s2,int condition);  /*根据condition比较Student类型数据大小*/
void reverse(Student stu[],int n);             /*学生记录数组元素逆置*/

void calcuTotal(Student stu[],int n);           /*计算所有学生的总分*/
void calcuRank(Student stu[],int n);           /*根据总分计算学生的名次，允许有并列名次*/
void calcuMark(double m[3][3],Student stu[],int n); /*求三门课的最高、最低、平均分，m数组第一维*/
/*表示哪门课，第二维表示最高、最低、平均分*/

void sortStu(Student stu[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/

int searchStu(Student stu[],int n,Student s,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertStu(Student stu[],int n,Student s);                   /*向数组中插入一个元素按学号有序*/
int deleteStu(Student stu[],int n,Student s);                   /*从数组中删除一个指定学号的元素*/
#endif
