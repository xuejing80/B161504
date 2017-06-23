/* ①sightspot.h文件的完整内容 */
#ifndef _SIGHTSPOT             /*条件编译，防止重复包含的错误*/
#define _SIGHTSPOT
#include <string.h>
#define NUM 20                /*定义景点数目常量，此处可以根据实际需要修改常量值*/
struct Sightspot                   /*景点记录的数据域*/
{
		long number;          /*序号*/ 
		char place[20];       /*地点*/ 
		char name[20];        /*景点名称*/ 
		int num;              /*人流量*/ 
		int month;            /*月份*/ 
		int rank;             /*名次*/ 
};
typedef struct Sightspot Sightspot;
#define sizeSig sizeof(Sightspot)      /*一个景点记录所需要的内存空间大小*/
int readSig(Sightspot sig[],int n);       /*读入景点记录值，序号为0或读满规定条数记录时停止*/
void printSig(Sightspot *sig , int n);   /*输出所有景点记录的值*/
int equal(Sightspot s1,Sightspot s2,int condition);  /*根据condition条件判断两个Sight spot类型数据相等否*/
int larger(Sightspot s1,Sightspot s2,int condition);  /*根据condition比较Sight spot类型数据大小*/
void reverse(Sightspot sig[],int n);             /*景点记录数组元素逆置*/
void calcuRank(Sightspot sig[],int n);           /*根据人流量计算景点的名次，允许有并列名次*/
void calcuMark(double m[20][2],Sightspot sig[],int n); /*求二十个景点人流量的最高、最低，m数组第一维*/
/*表示哪个景点，第二维表示最高、最低*/
void sortSig(Sightspot sig[],int n,int condition);   /*选择法从小到大排序，按condition所规定的条件*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertSig(Sightspot sig[],int n,Sightspot s);                   /*向数组中插入一个元素按序号有序*/
int deleteSig(Sightspot sig[],int n,Sightspot s);                   /*从数组中删除一个指定序号的元素*/
int searchSig(Sightspot sig[], int n, Sightspot s, int condition, int f[]);/*根据条件找数组中与s相等的各元素*/
#endif


