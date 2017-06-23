/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"sightspot.h"

void printHead( )      /*��ӡ������Ϣ�ı�ͷ*/
{
printf("%8s%22s%27s%12s%8s%12s\n","���","����","�ص�","������","�·�","����");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. �������������� ********\n");
        printf("******** 4. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ���뾰���¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ�������¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸ľ����¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}
void menunum( )     /*3����������������˵�����*/
{
		printf("%%%%%%%% 1. �������������� %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuSearch()    /*4������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. �����Ʋ�ѯ   ########\n");
		printf("######## 3. �����β�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Sightspot sig[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Sightspot s;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readSig(&s,1);       /*����һ��������ľ����¼*/
					 n=insertSig(sig,n,s);   /*���ú������뾰���¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.number);  /*����һ����ɾ���ľ������*/
					 n=deleteSig(sig,n,s);   /*���ú���ɾ��ָ����ŵľ����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.number);  /*����һ�����޸ĵľ������*/
				      t=searchSig(sig,n,s,1,find) ; /*���ú�������ָ����ŵľ����¼*/
				      if (t)                 /*�������ŵļ�¼����*/
					 {
						  readSig(&s,1);   /*����һ�������ľ����¼��Ϣ*/
					      sig[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*�������ŵļ�¼������*/ 
 printf("this sightspot is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}
int numManage(Sightspot sig[],int n)          /*�ú�����ɾ���������������*/
{  
	int choice;
	do  
	{  
		menunum() ;
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuRank(sig,n);         /*�������о����������������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

int searchManage(Sightspot sig[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Sightspot s;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a sightspot\'s num will be searched:\n");
				      scanf("%ld",&s.number);         /*�������ѯ��������*/
					  break;
				case 2:   printf("Input a sightspot\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*�������ѯ���������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*�������ѯ���������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchSig(sig,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printSig(&sig[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Sightspot sig[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortSig(sig,n,1);         /*�������С�����˳�������¼*/ 
          	 printSig(sig,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(sig,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: numManage(sig,n);     /* 3. ��������������*/
					break;
			case 4: searchManage(sig,n);     /* 4. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}
int main( )
{
		Sightspot sig[NUM];                /*����ʵ��һά����洢�����¼*/
      int choice,n;
	 n=readFile(sig);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(sig);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(sig,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortSig(sig,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(sig,n);                   /*����������ļ�*/
      return 0;
}
