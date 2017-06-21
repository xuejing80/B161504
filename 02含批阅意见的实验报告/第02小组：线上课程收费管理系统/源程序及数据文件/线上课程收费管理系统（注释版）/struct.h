#include<stdio.h>
#define NUM 100
typedef struct course{//课程结构体 
	char name[25];
	int time[4];//包括开始时间的小时和分钟，结束时间的小时和分钟 
	int member[2];//包括课程已选人数和最大限制人数 
	float tuition;
	char category[20];
	int ID;
}course;
typedef struct student{//学生结构体 
	char ID[10];
	char name[10];
	char sex[7];
	course cor[2];//包括选课1和选课2 
	float fee;
}student;
