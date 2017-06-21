#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
int mainMenu(){
	int n=-1;
	char a[25];
	printf("******** 1. 显示基本信息 ********\n");
	printf("******** 2. 查询相关信息 ********\n");
	printf("******** 3. 课程信息管理 ********\n");
	printf("******** 4. 学生信息管理 ********\n");
	printf("******** 5. 学生报名入口 ********\n");
	printf("******** 0. 退出         ********\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//防止输入字符串打乱程序执行 
		n=10;
	}
	return n;
}

int infMenu(){
	int n=-1;
	char a[25];
	printf("%%%%%%%%%%%%%%%% 1. 显示学生信息 %%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%% 2. 显示课程信息 %%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%% 0. 返回上层菜单 %%%%%%%%%%%%%%%%\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//防止输入字符串打乱程序执行 
		n=10;
	}
	return n;
}

int crsMngMenu(){
	int n=-1;
	char a[25];
	printf("@@@@@@@@ 1. 添加课程信息 @@@@@@@@\n");
	printf("@@@@@@@@ 2. 修改课程信息 @@@@@@@@\n");
	printf("@@@@@@@@ 3. 删除课程信息 @@@@@@@@\n");
	printf("@@@@@@@@ 4. 按课程号排序 @@@@@@@@\n");
	printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//防止输入字符串打乱程序执行 
		n=10;
	}
	return n;
}

int stdMngMenu(){
	int n=-1;
	char a[25];
	printf("$$$$$$$$ 1. 添加学生信息 $$$$$$$$\n");
	printf("$$$$$$$$ 2. 修改学生信息 $$$$$$$$\n");
	printf("$$$$$$$$ 3. 删除学生信息 $$$$$$$$\n");
	printf("$$$$$$$$ 0. 返回上层菜单 $$$$$$$$\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//防止输入字符串打乱程序执行 
		n=10;n=10;
	}
	return n;
}

int eryMenu(char ID[10]){
	int n=-1;
	char a[25];
	if(strcmp(ID,"")==0){//判断所报名的学生在学生库里是否存在 
		printf("Please input your student's ID:");
		scanf("%s",ID); 
		FILE *fp;
		student temp[NUM],*p=temp;
		int i=0;
		if((fp=fopen("statistic_s.dat","rb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
		}else{
			fread(temp,sizeof(temp[0]),1,fp);
			while(!feof(fp)){
				if(strcmp(ID,temp[i].ID)==0){
					printf("&&&&&&&& 1. 查看已选课程 &&&&&&&&\n");
					printf("&&&&&&&& 2. 选修课程管理 &&&&&&&&\n");
					printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
					printf("Please input your choice: ");
					scanf("%d",&n);
					if(n==-1){
						scanf("%s",a);//防止输入字符串打乱程序执行 
						n=10;
					}
					return n;
				}
				i++;
				p++;
				fread(p,sizeof(temp[0]),1,fp);
			}
			fclose(fp);
		}
		printf("Student not found!\n");
		system("pause");
		return 0;
	}else{
		printf("&&&&&&&& 1. 查看已选课程 &&&&&&&&\n");
		printf("&&&&&&&& 2. 选修课程管理 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
		printf("Please input your choice: ");
		scanf("%d",&n);
		if(n==-1){
			scanf("%s",a);//防止输入字符串打乱程序执行 
			n=10;
		}
		return n;
	}
}

int srhMenu(){
	int n=-1;
	char a[25];
	printf("######## 1. 查询课程信息 ########\n");
	printf("######## 2. 查询学生信息 ########\n");
	printf("######## 0. 返回上层菜单 ########\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//防止输入字符串打乱程序执行 
		n=10;
	}
	return n;
}
