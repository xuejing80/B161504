 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"        
int  createFile(CAR c[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\student.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("�޷����ļ�!\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("��������������Ϣ:\n");
	n=readC(c,NUM);                /*����student.h�еĺ���������*/
fwrite(c,sizeC,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(CAR c[ ] )                     /*���ļ��е����ݶ������ڽṹ������c��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\student.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("�ļ������ڣ����ȴ���һ���µ��ļ�:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&c[i],sizeC,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&c[i],sizeC,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(CAR c[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\student.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("�ļ��޷���!\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(c,sizeC,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}
