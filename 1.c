#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct carrental
    {
        char bianhao[10];
        char num[10];
        char leixing[20];
        char brand[50];
        char color[50];
        char price[20];
        long zongshu;
        long shengyu;
    }car;
struct rent
     {
	     char bianhao[10];
         char num[10];
         long nian;
         long borrowmonth;
         long borrowday;
         long returnedmonth;
         long returnedday;
         long limittime;
         char caruser[10];
     }RENT;
void shan()                              //ɾ��������Ϣ
{
    FILE *fp;
    int i=0,j,n,m,l;
    char carnum[20];
    struct carrental cars[1000];
    if((fp=fopen("carrental.txt","r"))==NULL)
    {
        printf("can not open the carrental.txt.\n");
        exit(0);
    }
    while(fread(&cars[i],sizeof(car),1,fp))
    {
        i++;
        m=i;
    }
    printf("Ҫɾ����������");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        printf("���복�ƺţ�");
        gets(carnum);
        for(j=0;j<m;j++)
            if(strcmp(carnum,cars[j].num)==0)
            	break;
        if(j<m)
		{
			for(l=0;l<m;l++)
				if(strcmp(cars[j].bianhao,cars[l].bianhao)==0)
				{
					cars[l].zongshu--;
				    cars[l].shengyu--;
				}
            for(j;j<m;j++)
                cars[j]=cars[j+1];
		}
        else
    	{
            printf("��������  ��������\n");
            i--;
        }   
    }
    if((fp=fopen("carrental.txt","w"))==NULL)
    {
        printf("can not open the carrental.txt.\n");
        exit(0);
    }
    for(i=0;i<m-n;i++)
        fwrite(&cars[i],sizeof(car),1,fp);
	printf("ɾ���ɹ�����");
}
void xiu()                                        //�޸ĳ�����Ϣ
{
    FILE *fp;
    int i=0,m,n;
    char carnum[20],numchar[20];
    struct carrental cars[1000];
    if((fp=fopen("carrental.txt","r"))==NULL)
    {
        printf("can not open the borrow.txt.\n");
        exit(0);
    }
    while(fread(&cars[i],sizeof(car),1,fp))
    {
        i++;
        m=i;
    }
    if((fp=fopen("carrental.txt","w"))==NULL)
    {
        printf("can not open the borrow.txt.\n");
        exit(0);
    }
    printf("Ҫ�޸ļ�����:");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        printf("����Ҫ�޸ĵĳ��ƺţ�");
        gets(carnum);
        for(i=0;i<m;i++)
    	{
            if(strcmp(carnum,cars[i].num)==0)
            	break;
    	}
        if(i<m)
    	{ 
            printf("�����������޸ĺ��\n\n");
            printf("���������복�����:");  
            gets(cars[i].bianhao);
			printf("\n");
            printf("���������ƺ�:");  
            gets(cars[i].num);
			printf("\n");
            printf("����������:"); 
            gets(cars[i].leixing);
			printf("\n");
            printf("����������:");  
            gets(cars[i].brand);
			printf("\n");
            printf("��������ɫ:");  
            gets(cars[i].color);
			printf("\n");
            printf("�������۸�:");  
            gets(cars[i].price);
			printf("\n");
            printf("����������:");  
            gets(numchar);
			printf("\n");
            cars[i].zongshu=atol(numchar);
            printf("������ʣ��:");  
            gets(numchar);
			printf("\n");
            cars[i].shengyu=atol(numchar);
    	}
        else
            printf("��������\n");
        for(i=0;i<m;i++)
            fwrite(&cars[i],sizeof(car),1,fp);
    }
    fclose(fp);
}
void putin()                                               //¼���³�
{
    char numchar[20];
    FILE *fp;
    int i=0,m,n;
    struct carrental cars[1000];
    if((fp=fopen("carrental.txt","r"))==NULL)
    {
        printf("can not open the borrow.txt.\n");
        exit(0);
    }
    while(fread(&cars[i],sizeof(car),1,fp))
    {
        i++;
        m=i;
    }
    if((fp=fopen("carrental.txt","w"))==NULL)
    {
        printf("can not open the borrow.txt.\n");
        exit(0);
    }
    for(i=0;i<m;i++)
    {
        fwrite(&cars[i],sizeof(car),1,fp);
    }
    printf("Ҫ¼�뼸������");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {   
		printf("\n");
        printf("������������:");  
        gets(car.bianhao);
	    printf("\n");
        printf("���������ƺ�:");  
        gets(car.num);
	    printf("\n");
        printf("����������:"); 
        gets(car.leixing);
	    printf("\n");
        printf("����������:");  
        gets(car.brand);
	    printf("\n");
        printf("��������ɫ:");  
        gets(car.color);
	    printf("\n");
        printf("�������۸�:");  
        gets(car.price);
	    printf("\n");
        printf("����������:");  
        gets(numchar);
	    printf("\n");
        car.zongshu=atol(numchar);
        printf("������ʣ��:");  
        gets(numchar);
	    printf("\n");
        car.shengyu=atol(numchar);
        fwrite(&car,sizeof(car),1,fp);
    }
    fclose(fp);
}
void print()                                           //��ӡ������Ϣ��
{  
    FILE *fp;
    if((fp=fopen("carrental.txt","r"))==NULL)
    {
        printf("can not open the carrental.txt.\n");
        exit(0);
    }
    puts("_______________________________________________________________________");
    puts("-----------------------------------------------------------------------");
    puts("| ���  | ���ƺ�  |  ����  |  ��Ʒ��  |   �۸�   |   ��ɫ  |   ���� |   ʣ�� |");                			 
    fseek(fp,0L,SEEK_SET);
    while(fread(&car,sizeof(car),1,fp)==1)
        printf("  %-9s%-10s%-10s%-10s%-10s%-10s%-10ld%-10ld\n",car.bianhao,car.num,car.leixing,car.brand,car.price,car.color,car.zongshu,car.shengyu);
}
void returned()                                              //����
{
    FILE *fp;
    int i=0,m,flag=0,j;
    char carnum[20];
    struct rent car1[1000];
    if((fp=fopen("borrow.txt","r"))==NULL)
    {
    printf("can not open the borrow.txt.\n");
        exit(0);
    }
    while(fread(&car1[i],sizeof(car),1,fp))
    {
        i++;
        m=i;
    }
    if((fp=fopen("borrow.txt","w"))==NULL)
    {
        printf("can not open the borrow.txt.\n");
        exit(0);
    }
    printf("����Ҫ���ĳ��ƺţ�");
    gets(carnum);
    for(j=0;j<m;j++)
    {
		if(strcmp(carnum,car1[j].num)==0)
		{
			flag=1;
            break;
		}
    }
    if(flag)
    { 
		flag=0;
        printf("���뻹���·ݣ�");
        scanf("%ld",&car1[i].returnedmonth);
        printf("���뻹�����ڣ�");
        scanf("%ld",&car1[i].returnedday);
	    getchar();
        for(j=0;j<m;j++)
		fwrite(&car1[i],sizeof(car),1,fp);
        printf("�����ɹ�");
    }
    else
		printf("��������\n");
    fclose(fp);
}
void rent()                                                //���������ļ�
{  
   FILE *fp;
   char numchar[50],ch='y';
   if((fp=fopen("carrental.txt","wt"))==NULL)
   {
       printf("can not open the carrental.txt.\n");
       exit(0);
   }
   while(ch=='y'||ch=='Y')
   {
	   printf("\n");
       printf("������������:");  
       gets(car.bianhao);
	   printf("\n");
       printf("���������ƺ�:");  
       gets(car.num);
	   printf("\n");
       printf("����������:"); 
       gets(car.leixing);
	   printf("\n");
       printf("��������Ʒ��:");  
       gets(car.brand);
	   printf("\n");
       printf("��������ɫ:");  
       gets(car.color);
	   printf("\n");
       printf("�������۸�:");  
       gets(car.price);
	   printf("\n");
       printf("����������:");  
       gets(numchar);
	   printf("\n");
       car.zongshu=atol(numchar);
       printf("������ʣ��:");  
       gets(numchar);
	   printf("\n");
       car.shengyu=atol(numchar);
       fwrite(&car,sizeof(car),1,fp);
       do{
          printf("have another car record(y/n)?:");
          gets(numchar);  
          ch=numchar[0];
       }while(!(ch=='y'||ch=='n'||ch=='Y'||ch=='N'));

   }
   fclose(fp);
}
void borrowed()                                               //�賵

{   
	struct carrental cars[1000];
    struct rent car1[1000];
    FILE *fp,*fq;
    char numchar[50];
    int i=0,j,m1,m2,n,flag=0,x;
	printf("�輸������");
	scanf("%d",&x);
	getchar();
    if((fq=fopen("carrental.txt","r"))==NULL)
	{
		printf("can not open the carrental.txt.\n");
        exit(0);
	}
    while(fread(&cars[i],sizeof(car),1,fq))
	{
		i++;
        m1=i;
	}
    if((fp=fopen("borrow.txt","r"))==NULL)
    {
       printf("can not open the borrow.txt.\n");
       exit(0);
    }
    while(fread(&car1[i],sizeof(car),1,fp))
    {
        i++;
        m2=i;
    }
	for(i=0;i<x;i++)
	{
		printf("\n");
		printf("���복�ƺ�:"); 
	    gets(numchar);
        for(j=0;j<m1;j++)
		{
			if(strcmp(numchar,cars[j].num)==0)
			{
				n=j;
				flag=1;
			    break;
			}
		}
        if(flag)
		{
			printf("\n");
			printf("������ȷ\n\n");
			flag=0;
			strcpy(RENT.num,numchar);
			printf("������������");  gets(RENT.bianhao); printf("\n"); 
            printf("�������賵���:");   gets(numchar);  printf("\n");  RENT.nian=atol(numchar);
            printf("�������賵�·�:");  gets(numchar); printf("\n"); RENT.borrowmonth=atol(numchar);
            printf("�������賵����:"); gets(numchar); printf("\n"); RENT.borrowday=atol(numchar);
            printf("�����������·�:");  gets(numchar); printf("\n");  RENT.returnedmonth=atol(numchar);
            printf("��������������:");  gets(numchar);  printf("\n");  RENT.returnedday=atol(numchar);
            printf("����������:");  gets(numchar); printf("\n");  RENT.limittime=atol(numchar);
            printf("�������˿�����:");  gets(RENT.caruser);  printf("\n");
        	printf("�賵�ɹ�");
            if((fp=fopen("borrow.txt","w"))==NULL)
			{
				printf("can not open the borrow.txt.\n");
                exit(0);
			}
			fwrite(&RENT,sizeof(RENT),1,fp);
            for(j=0;j<m2;j++)
			{
				fwrite(&car1[j],sizeof(RENT),1,fp);
			}
			for(j=0;j<m1;j++)
			{
				if(strcmp(cars[n].bianhao,cars[j].bianhao)==0)
					cars[j].shengyu--;
			}
            if((fq=fopen("carrental.txt","w"))==NULL)
			{
				printf("can not open the carrental.txt.\n");
                exit(0);
			}
			for(j=0;j<m1;j++)
			{
				fwrite(&cars[j],sizeof(RENT),1,fq);
			}
		}
		else
		{
			printf("�������\n");
		    i--;
		}
	}
    fclose(fq);
    fclose(fp);
}
void main()
{   
    int flag=1;
    char a[20];
    puts("��������������������������������������������������������");
    puts("��                                                    ��");
    puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
    puts("��                                                    ��");
    puts("��           ��ӭʹ���⳵��Ϣ����ϵͳ                 ��");
    puts("��                                                    ��");
    puts("��                                                    ��");
    puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                       ��                           ��");
	puts("��                       ��                           ��");
	puts("��                       ��                           ��");
	puts("��                     ��  ��                         ��");
	puts("��                   ��      ��                       ��");
	puts("��                 ��          ��                     ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
    puts("��                                                    ��");
    puts("��      ��ѡ������Ҫ�Ĺ��� ��                         ��");
    puts("��                                                    ��");
    puts("��         ��ֱ�Ӽ����Ӧ���֣�                       ��");
    puts("��                                                    ��");
    puts("��                                                    ��");
    puts("��                                                    ��");
    puts("��         1.�����Ǽ�                                 ��");
    puts("��                                                    ��");
    puts("��         2.��ӡ������Ϣ��                           ��"); 
    puts("��                                                    ��");
    puts("��         3.����׷����¼��                           ��");
    puts("��                                                    ��");
    puts("��         4.�޸ĳ�����Ϣ                             ��");   
    puts("��                                                    ��");   
    puts("��         5.ɾ��������Ϣ                             ��");
    puts("��                                                    ��");
    puts("��         6.�賵                                     ��");   
    puts("��                                                    ��");
	puts("��         7.����                                     ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
	puts("��                                                    ��");
    puts("��������������������������������������������������������");
    while(flag)
    {
        flag=0;
        scanf("%s",a);
        getchar();
        if(strcmp(a,"3")==0)
            putin();
        else if(strcmp(a,"1")==0)  
            rent();
        else if(strcmp(a,"6")==0)  
            borrowed();
        else if(strcmp(a,"2")==0)
            print();
        else if(strcmp(a,"7")==0)
            returned();
        else if(strcmp(a,"4")==0)
            xiu();
        else if(strcmp(a,"5")==0)
            shan();
        else
        {
            printf("�������   ���������룺");
            flag=1;
        }
    }
}


