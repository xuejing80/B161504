#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void createFile(){
	FILE *fp;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//如果学生数据库不存在则建立学生数据库 
		if((fp=fopen("statistic_s.dat","wb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
			exit(1);
		}
		fclose(fp);
	}
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//如果课程数据库不存在则建立课程数据库 
		if((fp=fopen("statistic_c.dat","wb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
			exit(1);
		}
		fclose(fp);
	}	
}
