 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "staff.h"
int creatFile(Staff sta[]))              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
    if((fp=fopen("d:\\staff.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
		printf("can not open file!\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                           /*Ȼ���˳�*/
	}
	printf("input staffs\'information:\n");
	n=readSta(sta,NUM);                /*����staff.h�еĺ���������*/
	fwrite(sta,sizeSta,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
	fclose(fp);                             /*�ر��ļ�*/
	return n;
}
int readFile(Staff sta[])                     /*���ļ��е����ݶ������ڽṹ������sta��*/
{
	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\staff.dat","rb"))==NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
		printf("file does not exist,creat it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
		return 0;                              /*Ȼ�󷵻�0*/
	}
	fread(&sta[i],sizeSta,1,fp);                   /*������һ����¼*/
	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
		fread(&sta[i],sizeSta,1,fp);              /*�ٶ�����һ����¼*/
	}
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}
void saveFile(Staff sta[],int n)                  /*���ṹ�����������д���ļ�*/
{
	FILE *fp;
	if((fp=fopen("d:\\staff.dat","wb"))==NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file!\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(sta,sizeSta,n,fp);
	fclose(fp);                              /*�ر��ļ�*/
}

