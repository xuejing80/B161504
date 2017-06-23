 /*③ file.h文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include "car.h"        
int  createFile(CAR c[ ])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\student.dat", "wb")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("无法打开文件!\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    	}
	printf("请输入汽车的信息:\n");
	n=readC(c,NUM);                /*调用student.h中的函数读数据*/
fwrite(c,sizeC,n,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);                             /*关闭文件*/
	 return n;
}

int readFile(CAR c[ ] )                     /*将文件中的内容读出置于结构体数组stu中*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\student.dat", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("文件不存在，请先创建一个新文件:\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}	 
    	fread(&c[i],sizeC,1,fp);                   /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
	    	fread(&c[i],sizeC,1,fp);              /*再读出下一条记录*/
     }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}

void saveFile(CAR c[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\student.dat", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("无法打开文件!\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(c,sizeC,n,fp);        
	fclose(fp);                              /*关闭文件*/
}
