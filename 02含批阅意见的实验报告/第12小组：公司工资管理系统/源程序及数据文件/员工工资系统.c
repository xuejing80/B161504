#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#include <conio.h>
#include <string.h>

#define NUM 20
#define ALL 100

char admin[NUM],password[NUM],cpassword[NUM],kong[11]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

struct  gz                      //�����·���Ϣ 
{
	int Jan;
	int Feb;
	int Mar;
	int Apr;
	int May;
	int Jun;
	int Jul;
	int Aug;
	int Sep;
	int Oct;
	int Nov;
	int Dec; 
};						//Ա����Ϣ 
typedef struct gz gz;

struct  xinxi
{ 
	char name[10];   //���� 
	char sex[3];    //�Ա� 
	char job[5];    //���� 
	int old;	    //���� 
	gz gongzi; 

};						//Ա����Ϣ 
typedef struct xinxi xinxi;



struct  zhanghao
{
	char adm[11];  //�������Ա�˺�����ѡ�� 
	char mima[11];
};
typedef struct zhanghao zhanghao; //�˺���Ϣ 

struct  yonghu  //�û��Һ����� 
{
	char adm[11];
	char mima[11];
};
typedef struct yonghu yonghu;


void gotoxy(int x ,int y)  //�������ã�����printf��ӡ��λ�� 
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD Ioc;
	Ioc.X = x;
	Ioc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,Ioc);
}


void jiemian()  //���溯�� 
{
	system("cls");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");//�����û����� 
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
    printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("*                                                                   *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

}


//�ж����������Ƿ�һ�£�һ�·���1����һֱ����0.
int check(char a[],char b[])
{
	int i=0,flag=0;

	for( ; a[i]!='\0' && b[i]!='\0' && flag==0;i++)
	{
		if( a[i] == b[i])
		{  flag=1;
		   break; 
		}	
		else flag=0;
	}
	return flag;

}


//****************************************�����п�ʼ���������**************************




void xiugai(xinxi a[],int N)//�޸��û���ͨ���û���������λ 
{
	char z[2]={' '},x[2]={'\12'};
	int kai;
	char zanshi[20];
//	yonghu d[1];
	FILE *fp2;
	fp2 = fopen("D:\\Ա����Ϣ.txt","w");
//	int i=0;
	jiemian();
	gotoxy(11,5);
	printf("��Ҫ�޸ĵ�����:");
	gotoxy(11,6);
	scanf("%s",zanshi);//�������� 
	getch;
	gotoxy(20,6);

	
	for(kai=0;kai<N;kai++)//��λ 
	{
		if(check(zanshi,a[kai].name))
		{
			break;
		}
	}

	getch;
	jiemian();
	gotoxy(11,5);
	printf("������Ա������:");
	scanf("%s",a[kai].name);//�����޸ĵĸ�����Ϣ 

	jiemian();
	gotoxy(11,5);
	printf("������Ա���Ա�:");
	scanf("%s",a[kai].sex);

	jiemian();
	gotoxy(11,5);
	printf("������Ա��ְҵ:");
	scanf("%s",a[kai].job);

	jiemian();
	gotoxy(11,5);
	printf("������Ա������:");
	scanf("%d",&a[kai].old);
		
	
	jiemian();
	gotoxy(11,5);
	printf("������Ա����1�µĹ���:");
	scanf("%d",&a[kai].gongzi.Jan);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����2�µĹ���:");
	scanf("%d",&a[kai].gongzi.Feb);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����3�µĹ���:");
	scanf("%d",&a[kai].gongzi.Mar);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����4�µĹ���:");
	scanf("%d",&a[kai].gongzi.Apr);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����5�µĹ���:");
	scanf("%d",&a[kai].gongzi.May);
	
	jiemian();
	gotoxy(11,5);
	printf("������Ա����6�µĹ���:");
	scanf("%d",&a[kai].gongzi.Jun);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����7�µĹ���:");
	scanf("%d",&a[kai].gongzi.Jul);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����8�µĹ���:");
	scanf("%d",&a[kai].gongzi.Aug);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����9�µĹ���:");
	scanf("%d",&a[kai].gongzi.Sep);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����10�µĹ���:");
	scanf("%d",&a[kai].gongzi.Oct);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����11�µĹ���:");
	scanf("%d",&a[kai].gongzi.Nov);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����12�µĹ���:");
	scanf("%d",&a[kai].gongzi.Dec);


//������뵼�����򣬽��������Ϣд�뵽�ļ� 
	int ji;
	for(ji=0;ji<kai;ji++)
	{
		fputs(a[ji].name,fp2);
		fputs(z,fp2);
		
		fputs(a[ji].sex,fp2);
		fputs(z,fp2);
		fputs(a[ji].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",a[ji].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Dec);
		
		fputs(x,fp2);
//printf("1");�����ļ�д���Ƿ�ɹ���д�뼸�Ρ��������޸���Ϣ֮ǰ����Ϣ 
	}
	{
		fputs(a[kai].name,fp2);//���޸ĵ���Ϣд���ļ� 
		fputs(z,fp2);
		
		fputs(a[kai].sex,fp2);
		fputs(z,fp2);
		fputs(a[kai].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",a[kai].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[kai].gongzi.Dec);
//printf("д��");�����޸���Ϣ�Ƿ�д�� 
		fputs(x,fp2);
	}
	ji=kai+1;
	for(ji;ji<N;ji++)//ͨ�����ѭ�����޸���Ϣ�������Ϣд���ļ� 
	{
		fputs(a[ji].name,fp2);
		fputs(z,fp2);
		
		fputs(a[ji].sex,fp2);
		fputs(z,fp2);
		fputs(a[ji].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",a[ji].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",a[ji].gongzi.Dec);
		
		fputs(x,fp2);
//printf("1");����д���Ƿ�ɹ���д�뼸�� 

	}
	jiemian();
	printf("�޸ĳɹ�"); 
	Sleep(3000);
}






void add(FILE *fp1,FILE *fp2)					//���ӻ�Ա
{
	char c[2]={' '},d[2]={'\12'};
	xinxi people;
	fp1 = fopen("D:\\�û�.txt","a+");
	fp2 = fopen("D:\\Ա����Ϣ.txt","a+");//����ָ��ֱ�д���û��ļ�����Ϣ�ļ� 

	int j=0;
	for( ; j<NUM ; j++ )
	{
		password[j]=0;
		admin[j]=0;
		cpassword[j]=0;
	}


//	admin[]
	jiemian();
	int i=0;
	gotoxy(11,5);
	printf("new admin:");
	gotoxy(11,6);
	printf("password:");
	gotoxy(11,7);
	printf("confirm password:");

//�����˺ź�����
	getchar();
	gotoxy(21,5);
	scanf("%s",admin);
	gotoxy(20,6);
	getchar;

//	password[0]='!';
//	while(getchar() != )
	while(password[i]=getch())
	{
		if(password[i]==13)  break;//�������������* 
        printf("*");
		i++;
	}
	getchar;
//	cpassword[0]=getch();
	i=0;
	gotoxy(28,7);
	while(cpassword[i]=getch())
	{
		if(cpassword[i]==13) break;//ȷ��������* 
        printf("*");
		i++;
	}

	if(check(password,cpassword)==0)			//�������֤
	{
		jiemian();
		gotoxy(28,7);
		printf("�������벻ͬ");
		Sleep(3000);
		getchar();
	}


	jiemian();
	gotoxy(11,5);
	printf("������Ա������:");
	scanf("%s",people.name);//����¼�� 

	jiemian();
	gotoxy(11,5);
	printf("������Ա���Ա�:");
	scanf("%s",people.sex);

	jiemian();
	gotoxy(11,5);
	printf("������Ա��ְҵ:");
	scanf("%s",people.job);

	jiemian();
	gotoxy(11,5);
	printf("������Ա������:");
	scanf("%d",&people.old);
	
	jiemian();
	gotoxy(11,5);
	printf("������Ա����1�µĹ���:");
	scanf("%d",&people.gongzi.Jan);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����2�µĹ���:");
	scanf("%d",&people.gongzi.Feb);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����3�µĹ���:");
	scanf("%d",&people.gongzi.Mar);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����4�µĹ���:");
	scanf("%d",&people.gongzi.Apr);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����5�µĹ���:");
	scanf("%d",&people.gongzi.May);
	
	jiemian();
	gotoxy(11,5);
	printf("������Ա����6�µĹ���:");
	scanf("%d",&people.gongzi.Jun);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����7�µĹ���:");
	scanf("%d",&people.gongzi.Jul);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����8�µĹ���:");
	scanf("%d",&people.gongzi.Aug);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����9�µĹ���:");
	scanf("%d",&people.gongzi.Sep);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����10�µĹ���:");
	scanf("%d",&people.gongzi.Oct);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����11�µĹ���:");
	scanf("%d",&people.gongzi.Nov);

	jiemian();
	gotoxy(11,5);
	printf("������Ա����12�µĹ���:");
	scanf("%d",&people.gongzi.Dec);
	
	jiemian();
	gotoxy(11,5);
	printf("��ӳɹ���"); 
	

//������뵼������
	
	fseek(fp1,0,2);			//��ָ��ָ���ļ�β
	fputs(d,fp1);
	fputs(admin,fp1);
	fputs(c,fp1);

	fputs(password,fp1);//д���û��ļ�		
	fseek(fp2,0,2); 
 	fputs(d,fp2);
	fputs(people.name,fp2);
	fputs(c,fp2);
	fputs(people.sex,fp2);
	fputs(c,fp2);
	fputs(people.job,fp2);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.old);	
	fputs(c,fp2);
		
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Jan);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Feb);		
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Mar);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Apr);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.May);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Jun);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Jul);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Aug);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Sep);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Oct);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Nov);
	fputs(c,fp2);
	fprintf(fp2,"%d",people.gongzi.Dec);
	


	jiemian();
	gotoxy(28,7);
	printf("��ӳɹ�!");
	Sleep(3000);

}



//ÿһ�ζ�ȡ����������ļ���д��Ȼ��ɾ��Ԫ��֮�������д��


void del(zhanghao a[],xinxi b[],int N)					//ɾ���˺ź�����
{
	char z[2]={' '},x[2]={'\12'};//��ӿո�ͻ������� 
	char y[6]={'no'}; //����������Ϣ������ ����warning��Ҫ��� 
	int kai;
	char zanshi[20];
//	yonghu d[1];
	FILE *fp2;
	fp2 = fopen("D:\\Ա����Ϣ.txt","w");
//	int i=0;
	jiemian();
	gotoxy(11,5);
	printf("��Ҫɾ��������:");//�����õ��Ĺ��ܺ����޸���ͬ��������������� 
	gotoxy(11,6);
	scanf("%s",zanshi);
	getch;
	gotoxy(20,6);
//	ch[i]='\0';
	
	for(kai=0;kai<N;kai++)
	{
		if(check(zanshi,b[kai].name))
		{
			break;
		}
	}
	int ji=0;
	for(ji;ji<kai;ji++)
	{
		fputs(b[ji].name,fp2);
		fputs(z,fp2);
		
		fputs(b[ji].sex,fp2);
		fputs(z,fp2);
		fputs(b[ji].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",b[ji].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Dec);
		
		fputs(x,fp2);
//printf("1");//ɾ����//�����Բ��Գ���д����� 

	}
{
strcpy(b[kai].name,y);//printf("a");���Ը�ֵ�Ƿ�ɹ�		
strcpy(b[kai].sex,y);

strcpy(b[kai].job,y);
b[kai].old=0;		
	
b[kai].gongzi.Jan=0;
	
b[kai].gongzi.Feb=0;	

b[kai].gongzi.Mar=0;

b[kai].gongzi.Apr=0;

b[kai].gongzi.May=0;

b[kai].gongzi.Jun=0;
	
b[kai].gongzi.Jul=0;

b[kai].gongzi.Aug=0;

b[kai].gongzi.Sep=0;

b[kai].gongzi.Oct=0;
	
b[kai].gongzi.Nov=0;
	
b[kai].gongzi.Dec=0;
//printf("1");���Ը�ֵ�ɹ��� 
}
	{
		fputs(b[kai].name,fp2);//�޸ĵ����ݣ���Ϊ�����岻����ʵ�ֺ����˳�θ��ǻ���ֻ��Һ�bug 
		fputs(z,fp2);		   //����ʹ�����޸�ԭʼ����Ϊ0�ķ�ʽ���� 
		
		fputs(b[kai].sex,fp2);
		fputs(z,fp2);
		fputs(b[kai].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",b[kai].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[kai].gongzi.Dec);
//printf("1");��������д�� 
		fputs(x,fp2);
}

	ji=kai+1;
	for(ji;ji<N;ji++)
	{		//printf("ha");����forѭ��ִ�д��� 
		fputs(b[ji].name,fp2);
		fputs(z,fp2);
		
		fputs(b[ji].sex,fp2);
		fputs(z,fp2);
		fputs(b[ji].job,fp2);
		fputs(z,fp2);		
		fprintf(fp2,"%d",b[ji].old);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jan);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Feb);		
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Mar);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Apr);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.May);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jun);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Jul);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Aug);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Sep);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Oct);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Nov);
		fputs(z,fp2);
		fprintf(fp2,"%d",b[ji].gongzi.Dec);
		
		fputs(x,fp2);
//printf("1");���� 

	}


	gotoxy(25,7);
	printf("ɾ���ɹ�");
	getch(); 
	sleep(3000);		
}


void findall(xinxi a[],int N)		//������Ϣ			����ֻ��ʾ���һ����(12��)�Ĺ��ʣ����Ҫ��ʾ�����µĹ��ʣ�ֻ��Ҫ�Լ����϶�Ӧ���·ݾ����ˣ���a[i].gongzi.Dec
{
	int i=0; 
	jiemian();
	gotoxy(11,4);
	printf("�� Ա ��       �� ��        ְ ҵ     �� ��   �� ��\n");
	for( ; i<N ; i++ )
	{
		gotoxy(11,5+i);
		printf("%-14s%4s%16s    %4d   %6d\n",a[i].name,a[i].sex,a[i].job,a[i].old,a[i].gongzi.Dec);
	}
	//sleep��3000�� 
	getch();
}


void findmyself(xinxi a[],int i)		//ͬ�� 
{
	jiemian();
	gotoxy(11,4);
	printf("�� Ա ��       �� ��        ְ ҵ     �� ��   �� ��\n");
	gotoxy(11,5);
	printf("%-14s%4s%16s    %4d   %6d\n",a[i].name,a[i].sex,a[i].job,a[i].old,a[i].gongzi.Dec);
	getch();
} 



int sui(int shouru)//˰�ռ��� 
{
	int suishou=0;
	if(shouru<1500)
	{
		suishou=0;
	}
	else if(shouru<2500)
	{
		suishou=0.1*(shouru-1500);
	}
	else if(shouru<3500)
	{
		suishou=(shouru-2500)*0.15+100;
	}
	else if(shouru<5000)
	{
		suishou=(shouru-3500)*0.2+250;
	}
	else if(shouru<10000)
	{
		suishou=(shouru-5000)*0.3+550;
	}
	else if(shouru>10000)
	{
		suishou=(shouru-10000)*0.4+2050;
	}
	return suishou;
}


void shuishou(xinxi a[],int i)
{		
	jiemian();
	
	gotoxy(11,4);
	printf("���1��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Jan));
	gotoxy(11,5);
	printf("���2��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Feb));
	gotoxy(11,6);
	printf("���3��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Mar));
	gotoxy(11,7);
	printf("���4��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Apr));
	gotoxy(11,8);
	printf("���5��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.May));
	gotoxy(11,9);
	printf("���6��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Jun));
	gotoxy(11,10);
	printf("���7��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Jul));
	gotoxy(11,11);
	printf("���8��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Aug));
	gotoxy(11,12);
	printf("���9��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Sep));
	gotoxy(11,13);
	printf("���10��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Oct));
	gotoxy(11,14);
	printf("���11��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Nov));
	gotoxy(11,15);
	printf("���12��Ӧ��֧����%d��˰�ա�",sui(a[i].gongzi.Dec));
   
	
 
	getch();
		//sleep(3000);
}



void tongji(xinxi a[],int n)
{
	int gongji=0,shouru=0,i;
	for( i=0;i<n;i++)
	{
		gongji=gongji+sui(a[i].gongzi.Jan)+sui(a[i].gongzi.Feb)+sui(a[i].gongzi.Mar)+sui(a[i].gongzi.Apr)+sui(a[i].gongzi.May)+sui(a[i].gongzi.Jun)+sui(a[i].gongzi.Jul)+sui(a[i].gongzi.Aug)+sui(a[i].gongzi.Sep)+sui(a[i].gongzi.Oct)+sui(a[i].gongzi.Nov)+sui(a[i].gongzi.Dec);
		shouru=shouru+a[i].gongzi.Jan+a[i].gongzi.Feb+a[i].gongzi.Mar+a[i].gongzi.Apr+a[i].gongzi.May+a[i].gongzi.Jun+a[i].gongzi.Jul+a[i].gongzi.Aug+a[i].gongzi.Sep+a[i].gongzi.Oct+a[i].gongzi.Nov+a[i].gongzi.Dec;
	}
	jiemian();
	gotoxy(8,4);
	printf("��һ�꣬����Ա��%d�ˣ���������Ϊ%d��˰������Ϊ%d",n,shouru,gongji);


	getch();
		//sleep(3000);
}






//********************************�����￪ʼ���ܺ�������*************************************



//�����ǽ��淵������

void daoshu()
{
	int x=4;
	while(x--)
	{
		gotoxy(25,7);
		printf("%d��󷵻�������",x);
		Sleep(1000);
	}
}


//void aaaa





int main()
{
	xinxi people[ALL];
	zhanghao hao[ALL];
	yonghu yh[ALL];
	int i=0,xuanze=1,N,M,ren;
	char weizhi;
	FILE *fp1,*fp2,*daochu,*fp3;


	
	fp1 = fopen("D:\\����Ա�˺�����.txt","a+");	//�����˺ź��������֤������ɾ
	if(fp1 == 0)
	{
		exit(0);		//�˳�����
	}					//�ļ�У��

//********************������˺ź����븳���ṹ��****************
	while( !feof(fp1) && i < ALL)
	{
		fscanf(fp1,"%s%s",hao[i].adm,hao[i].mima);
		i++ ;
		
	}
	M = i-1;
	i = 0;

	fp2 = fopen("D:\\Ա����Ϣ.txt","a+");
	if(fp2 == 0)
	{
		exit(0);
	}

//*****************��������ļ�fp2�������ݸ����ṹ��**********************************


	while( !feof(fp2) && i < ALL )
	{
		fscanf(fp2,"%s%s%s%d%",people[i].name,people[i].sex,people[i].job,&people[i].old);
		
		fscanf(fp2,"%d%d%d%d%d%d%d%d%d%d%d%d",&people[i].gongzi.Jan,&people[i].gongzi.Feb,&people[i].gongzi.Mar,&people[i].gongzi.Apr,&people[i].gongzi.May,&people[i].gongzi.Jun,&people[i].gongzi.Jul,&people[i].gongzi.Aug,&people[i].gongzi.Sep,&people[i].gongzi.Oct,&people[i].gongzi.Nov,&people[i].gongzi.Dec);
		
		i++;
	}
	
	
	N = i-1;
	i = 0;





//*********************************************************************************




	daochu = fopen("D:\\output.txt","w");

	fp3 = fopen("D:\\�û�.txt","a+");
	while( !feof(fp3) && i < ALL )
	{
		fscanf(fp3,"%s%s",yh[i].adm,yh[i].mima);
		i++;
	}
	
	i=0;

begin:

//��ʼ����
	
	jiemian();
	gotoxy(11,2);
	printf("��ӭʹ��Ա�����ʹ���ϵͳ!");
	gotoxy(11,5);
	printf("admin:");
	gotoxy(11,6);
	printf("password:");

//�˺ź���������
	gotoxy(17,5);
	scanf("%s",admin);
	gotoxy(20,6);

	while(password[i]=getch())
	{
		if(password[i]==13) break;
        printf("*");
		i++;
	}





//�˺ź��������֤
	while(1)
	{
	//	static int zou=0;
		int kai=0,ji=0,suan=0;
		for(;kai<ALL;kai++)
		{
			if(check(admin,hao[kai].adm) && check(password,hao[kai].mima)) 
			{
				ji=20;
				break;
			}
			else if(check(admin,yh[kai].adm) && check(password,yh[kai].mima))
			{
				ji=10;
				ren=kai;
				break;
			}
		}
		if(ji==20) 
		{
			jiemian();
			gotoxy(11,7);
			printf("��½�ɹ�!");
			Sleep(2000);
			break;		
		}
		if(ji==10)
			goto ziji;
		if(ji!=20 && ji!=10) 
		{		
			goto begin;
		}
	}


	kaishi:
//������
	do
	{
		jiemian();
		gotoxy(20,2);
		printf("------------------");
		gotoxy(20,3);
		printf("Ա�����ʹ���ϵͳ");
		gotoxy(20,4);
		printf("------------------");
		gotoxy(20,5);
		printf("��ѡ����Ҫ�Ĺ���:");
		gotoxy(20,6);
		printf("1.�����Ա��");
		gotoxy(20,7);
		printf("2.ע��Ա��");
		gotoxy(20,8);
		printf("3.��ѯԱ����Ϣ");			//����Ʒ�ƺͳ���
		gotoxy(20,9);
		printf("4.�޸�Ա����Ϣ");
		gotoxy(20,10);
		printf("5.��ʾͳ������");
		gotoxy(20,11);
		printf("6.�رճ���");
		gotoxy(20,21);
		printf("��w��s���Ʒ��򣬰�zȷ��");


//����ѡ��
		gotoxy(17,xuanze+5);
		printf("��");
		weizhi=getch();
		switch( weizhi )			//�����жϣ��������W����ô�������ƣ��������S����ô�������� 
		{
		default: break;
		case 'w': xuanze--;break;
		case 's': xuanze++;break;
		}


	if(xuanze<1)
		xuanze=1;
	else if(xuanze>7)
		xuanze=7;

	}while(weizhi != 'z');//�����жϣ����������Z����ô�ͽ�����Ӧ���� 


	jiemian();

//���滮��
	switch(xuanze)
	{
		case 1:add(fp3,fp2);break;
		case 2:del(hao,people,N);break;
		case 3:findall(people,N);break;
		case 4:xiugai(people,N);break;
		case 5:tongji(people,N);break;
		case 6:system("cls");
	}

//	Sleep(3000);
	if(xuanze != 6) 
	{
		jiemian();
		daoshu();
		goto kaishi;

	}
	else return 0;


//����д�û��Լ��Ľ���
ziji:
	do
	{
		jiemian();
		gotoxy(20,2);
		printf("------------------");
		gotoxy(20,3);
		printf("Ա�����ʹ���ϵͳ");
		gotoxy(20,4);
		printf("------------------");
		gotoxy(20,5);
		printf("��ѡ����Ҫ�Ĺ���:");
		gotoxy(20,6);
		printf("1.��ѯ�Լ���Ϣ");
		gotoxy(20,7);
		printf("2.��ѯӦ��˰");
		gotoxy(20,8);
		printf("3.�޸���Ϣ.");			
		gotoxy(20,9);
		printf("4.�رճ���");

		gotoxy(20,21);
		printf("��w��s���Ʒ��򣬰�zȷ��");


//����ѡ��
		gotoxy(17,xuanze+5);
		printf("��");
		weizhi=getch();
		switch( weizhi )
		{
		default: break;
		case 'w': xuanze--;break;
		case 's': xuanze++;break;
		}


	if(xuanze<1)
		xuanze=1;
	else if(xuanze>4)
		xuanze=4;

	}while(weizhi != 'z');//�����ж�


	jiemian();

//���滮��
	switch(xuanze)
	{
		case 1:findmyself(people,ren);break;
		case 2:shuishou(people,ren);break;
		case 3:xiugai(people,N);
		case 4:system("cls");
	}


	if(xuanze != 4) 
	{
		jiemian();
		daoshu();
		goto ziji;

	}	


	return 0;
} 
