#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <conio.h>

#define N 1000
 
typedef struct food

{

int number;

char name[20];

int sale;

int sum;

}FOOD;

FOOD food[N];

int shuliang=0;

void menu();

void fhzjm()

{

char biaozhi[20];

printf("\n");

printf("����Ҫ����ô�������Ҫ���������룺yes�����������룺no\n");

scanf("%s",biaozhi);

if(strcmp(biaozhi,"yes")==0)

{

menu();

}

else if(strcmp(biaozhi,"no")==0)

exit(0);

else

{

printf("��������ȷ���ַ���лл��\n");

fhzjm();

}

}

void DengJi()

{

int rs;

int i,k=1;

system("CLS");

printf("��������Ҫ���뼸����Ʒ��Ϣ��");

scanf("%d",&rs);

for(i=shuliang;i<shuliang+rs;i++,k++)

{

printf("�������%d����Ʒ�ı�ţ�",k);

scanf("%d",&food[i].number);

printf("��������Ʒ�����ƣ�");

scanf("%s",food[i].name);

printf("������������");

scanf("%d",&food[i].sale);

}

shuliang=shuliang+rs;

fhzjm();

}

void ShanChu()

{

char shanchuinfo[10];

system("CLS");

printf("ɾ��ȫ����Ʒ��Ϣ������\"all\"��ɾ��ָ����ŵ���Ʒ��Ϣ������\"one\"\n");

scanf("%s",shanchuinfo);

if(strcmp(shanchuinfo,"all")==0)

{

int j;

printf("��ɾ������Ʒ��Ϣ���£�\n");

printf("-----------���-------------��Ʒ--------------����\t\n");

for(j=0;j<shuliang;j++)

printf("----%d-------%s-------%d\t\n",food[j].number,food[j].name,food[j].sale);

shuliang=0;

printf("ɾ���ɹ�\n\n");

}

else if(strcmp(shanchuinfo,"one")==0)

{

struct food *p=NULL;

int choice;

int i,j,k=0;

printf("��������Ҫɾ������Ʒ�ı��:");

scanf("%d",&choice);

for(i=0;i<shuliang;i++)

{

if(choice==food[i].number)

{

k=1;j=i;break;

}

}

if(k)

{

if(shuliang==1)

{

p=&food[0];

free(p);

shuliang=0;

}

else

{

for(i=j;i<shuliang;i++)

{

food[i]=food[i+1];

}

shuliang=shuliang-1;

}

printf("ɾ���ɹ�\n\n");

}

else

{

printf("�������ݴ���\n");

}

}

fhzjm();

}

void LiuLan()

{

int i;

system("CLS");

if(shuliang==0)

{

printf("ϵͳ����û���κ���Ʒ����Ϣ��\n");

}

else
{
for(i=0;i<shuliang;i++)
{
printf("��%d����Ʒ��ϢΪ:\t\n",i+1);

printf("-----------���-------------��Ʒ--------------����\t\n");

printf("------------%d--------------%s--------------%d\t\n",food[i].number,food[i].name,food[i].sale);

}

}

fhzjm();

}

void ChaZhao()

{

int xx;

char choice,yy[20];

int i,j,k=0;

system("CLS");

if(shuliang==0)

{

printf("ϵͳ����û���κ���Ʒ����Ϣ��\n");

fhzjm();

}

printf("���ֲ��ҷ�ʽ����ţ����ƣ�����\n");

printf("�������Ų�������1\n��������Ʋ�������2\n�����������������3\n");

printf("�����������ҵķ�ʽ��");

scanf("%s",&choice);

if(choice=='1')

{

printf("��������Ҫ������Ʒ�ı�ţ�");

scanf("%d",&xx);

printf("�������ҵ���Ʒ����ϢΪ��\n");

printf("----���----����----����----\t\n");

for(i=0;i<shuliang;i++)

{

if(xx==food[i].number)

{

j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("������Ϣ����\n");

}

else if(choice=='2')

{

printf("��������Ҫ������Ʒ�����ƣ�\n");

scanf("%s",yy);

printf("�������ҵ���Ʒ����ϢΪ��\n");

printf("----���----����----����----\t\n");

for(i=0;i<shuliang;i++)

{

if(strcmp(yy,food[i].name)==0)

{

j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("������Ϣ����\n");

}

else if(choice=='3')

{
	
printf("��������Ҫ������Ʒ��������\n");

scanf("%d",&xx);

printf("�������ҵ���Ʒ����ϢΪ��\n");

printf("----���----����----����----\t\n");

for(i=0;i<shuliang;i++)

{
	
if(xx==food[i].sale)

{
	
j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("������Ϣ����\n");

}


fhzjm();

}

void PaiXu()

{

struct food*p1[N],**p2,*temp;

int i,j;

system("CLS");

p2=p1;

for( i=0;i<shuliang;i++)

{

p1[i]=food+i;

}

for( i=0;i<shuliang;i++)

{

for( j=i+1;j<shuliang;j++)

{

if((*(p2+i))->sum<(*(p2+j))->sum)


{temp=*(p2+i);*(p2+i)=*(p2+j);*(p2+j)=temp;}

}

}

printf("������������֮�����ϢΪ��\n");

printf("--���--����--����--\t\n");

for( i=0;i<shuliang;i++)

{

food[i].sum=food[i].sale;

printf("--%d--%s--%d--\n",(*(p2+i))->number,(*(p2+i))->name,(*(p2+i))->sum);

}

fhzjm();

}

void CunChu()

{

int i;

FILE *rs;

if((rs=fopen("food.txt","w"))==NULL)

{

printf("not open");

exit(0);

}

for(i=0;i<shuliang;i++)

{

fwrite(&food[i], sizeof(food[i]), 1, rs);

}

if(ferror(rs))

{

fclose(rs);

perror("д�ļ�ʧ�ܣ�\n");

return;

}

printf("�洢�ļ��ɹ���\n");

fclose(rs);

fhzjm();

}

void DaoChu()

{

struct food t;

int i=0;

FILE* fp = fopen("food.txt", "r");

shuliang=0;

if(NULL==fp)

{

perror("��ȡ�ļ���ʧ�ܣ�\n");

return;

}

memset(food,0x0,sizeof(food));

while(1)

{

fread(&t,sizeof(t),1,fp);

if(ferror(fp))

{

fclose(fp);

perror("���ļ�����ʧ�ܣ�\n");

return;

}

if(feof(fp))

{

break;

}

food[i]=t;

i++;

}

fclose(fp);
shuliang=i;

printf("�����ļ��ɹ���\n");

fhzjm();

}

void menu()

{

int n=0;

system("CLS");

printf(" �����Ʒ��Ϣ����ϵͳ\n");

printf("---------MENU--------\n");

printf(" 1.�Ǽ���Ʒ��Ϣ\n");

printf(" 2.ɾ����Ʒ��Ϣ\n");

printf(" 3.��������Ѿ��Ǽǵ���Ʒ\n");

printf(" 4.����\n");

printf(" 5.������������\n");

printf(" 6.�洢���ļ�\n");

printf(" 7.���ļ�����\n");

printf(" 8.�˳�ϵͳ\n");

a:	printf(" ��ѡ��");

scanf("%d",&n);

switch (n)

{

case 1:

DengJi();break;

case 2:

ShanChu();break;

case 3:

LiuLan();break;

case 4:

ChaZhao();break;

case 5:

PaiXu();break;

case 6:

CunChu();break;

case 7:

DaoChu();break;

case 8:

exit(0);break;

default:

{

printf("������1-8֮������֣�лл��\n");

goto a;

}

}

}

struct date

{ int year;

  int month;

  int day;

};

struct article

{ char name[20];

int num1;

char dest[20];

int num2;

float money;

struct date deliver;

struct article *next;

};

struct article *head;

int Recordcount;

void add()
 
{ 

system("cls");
 
struct article *p=NULL;
 
p=(struct article*)malloc(sizeof(struct article)); 

printf("�������������:"); 

scanf("%d",&p->deliver.year); 

printf("�����������·�:");
 
scanf("%d",&p->deliver.month);
 
if((p->deliver.month>0)&&(p->deliver.month<13))
 
{ 

printf("��������������:"); 

scanf("%d",&p->deliver.day);
 
printf("��������Ʒ����:"); 

scanf("%s",p->name);
 
printf("��������Ʒ���:"); 

scanf("%s",&p->num1); 

printf("��������Ʒ���͵�:");
 
scanf("%s",p->dest); 

printf("���������͸���:");
 
scanf("%d",&p->num2); 

printf("���������ͽ��:");
 
scanf("%f",&p->money); 

p->next=head; 

head=p; 

Recordcount++;
 
} 

system("PAUSE"); 

} 

void show()

{

system("cls");

struct article *p=NULL;

for(p=head;p!=NULL;p=p->next)

{

printf("%s\t",p->name);

printf("%d\t",p->num1);

printf("%s\t",p->dest);

printf("%d\t",p->num2);

printf("%f\n",p->money);

printf("%d\t",p->deliver.year);

printf("%d\t",p->deliver.month);

printf("%d\t",p->deliver.day);

}

}

void search()

{

system("cls");

char namesea[30];

int type;

int choice;

struct article *p=NULL;

printf("1�����Ʋ���\n2�����Ͳ���\n ");

printf("���������ѡ��");

scanf("%d",&choice);

if(choice>=1&&choice<=2)

{

if(choice==1)

{

printf("��������Ʒ���ƣ�");

scanf("%s",namesea);

for(p=head;p!=NULL;p=p->next)

if(strcmp(p->name,namesea)==0)

{

printf("%s\t",p->name);

printf("%d\t",p->num1);

printf("%s\t",p->dest);

printf("%d\t",p->num2);

printf("%f\n",p->money);

printf("%d\t",p->deliver.year);

printf("%d\t",p->deliver.month);

printf("%d\t",p->deliver.day);

}

}

else

{

printf("��������Ʒ���\n ");

scanf("%d",&type);

for(p=head;p!=NULL;p=p->next)

if(p->num1==type)

{

printf("%s\t",p->name);

printf("%d\t",p->num1);

printf("%s\t",p->dest);

printf("%d\t",p->num2);

printf("%f\n",p->money);

printf("%d\t",p->deliver.year);

printf("%d\t",p->deliver.month);

printf("%d\t",p->deliver.day);

}

}

}

else exit(0);

system("PAUSE");

}

void delete_rec()

{

system("cls");

char name[20];

float money;

int choice;

struct article *p=NULL,*q=NULL;

p=head;

q=head;

printf("������Ҫɾ������Ʒ���ƣ�");

scanf("%s",name);

printf("�������");

scanf("%f",&money);

for(;q!=NULL;q=q->next)

{

if((head->money==money)&&(strcmp(head->name,name)==0))

{

printf("%d\t",q->deliver.year);

printf("%d\t",q->deliver.month);

printf("%d\t",q->deliver.day);

printf("%d\t",q->num1);

printf("%s\t",q->name);

printf("%s\t",q->dest);

printf("%d\t",q->num2);

printf("%.2f\t",q->money);

printf("ȷ��ɾ����\n 1��\n 2��\n");

scanf("%d",&choice);

if(choice==1)

{

head=q->next;

Recordcount--;

}

else break;

}

else

{

if((q->money==money)&&(strcmp(q->name,name)==0))

{

printf("%d\t",q->deliver.year);

printf("%d\t",q->deliver.month);

printf("%d\t",q->deliver.day);

printf("%d\t",q->num1);

printf("%s\t",q->name);

printf("%s\t",q->dest);

printf("%d\t",q->num2);

printf("%.2f\t",q->money);

}

printf("ȷ��ɾ����\n 1��\n 2��\n");

scanf("%d",&choice);

if(choice==1)

{

p->next=q->next;

Recordcount--;

}

else break;

}

}

}
void logistic()

{

char ch;

FILE *fp;

char filename[10];

scanf("%s",filename);

if((fp=fopen(filename,"w"))==NULL)

{

printf("cannot open file\n");

exit(0);

}

while(ch=getchar()!='\n')

fputc(ch,fp);

fclose(fp);

ch=fgetc(fp);

while(ch!=EOF)

{ putchar(ch);

ch=fgetc(fp);

}

fclose(fp);

}

void order()

{ int n,b=1,s;

struct article *head=NULL;

void add();

void show();

void logistic();

void search();

void change();

void delete_rec();

while(b==1)

{

system("cls");

printf("************************************\n");
printf("��ӭʹ����Ʒ���͹���ϵͳ\n");
printf("************************************\n");

printf("1:��Ӽ�¼\n");

printf("2:��ʾ��¼\n");

printf("3:��ѯ��¼\n");

printf("4:ɾ����¼\n");

printf("5:�˳�\n");

printf("����������ѡ��:\n");

scanf("%d", &n);

switch(n)

{case 1: add();break;

case 2: show();break;

case 3: search();break;

case 4: delete_rec();break;

case 5: exit(0);break;

default :printf("error\n");}

printf("�Ƿ񷵻����˵�? 0�� 1��\n");

scanf("%d",&s);b=b+s;

}

}


int main()

{
	char nam[N];

	char password[N]; 		//���ڴ������

    char shop[N];

	char key[N];		//���ڱ���ȷ������

	int tryAgain = 0;				//���ԵĴ���

	

	//1.��������ϵͳ

	do

	{

		printf("----------�����û�---------\n");

	    printf("����������û�����");

		scanf("%s", nam);

		printf("��������Ĺ������룺");

		scanf("%s", password);

		printf("��ȷ����Ĺ������룺");

		scanf("%s", key);

	}
	while(strcmp(password, key));

	/*

		strcmp() string compare�ַ����ȽϺ����������һ�ַ����ȵڶ����ַ����󷵻�1��

		�����һ�ַ����ȵڶ����ַ���С����-1�������ַ�����ȷ���0

	*/

	printf("�������óɹ���\n�����û���Ϊ%s\n�������Ϊ%s\n", nam,password);

	

	printf("���������ʼ��¼ϵͳ.....\n");

	getch();	//���������������ó���ͣ���ڴˣ�ֱ�����ǰ��¼����ϵ�ĳ������

	system("cls");	//����

	

	//2.��¼ϵͳ

	printf("----------��¼ϵͳ---------\n");

	printf("�������û�����");

   while(scanf("%s", shop), strcmp(nam, shop))

	{

		tryAgain++;	//�ۼ��������ԵĴ���

		//�������ԵĴ�����������������

		if(tryAgain < 3)

			printf("����%d�Σ����������룺", tryAgain);

		else

			break;	//��������������ڵ������Σ��˳�ѭ��

	}

	

	//3.������

	system("cls");

	//������� ��1���������δ�������� 2��������ȷ������

	if(tryAgain >= 3)

	{		

		printf("�Բ���3���������ϵͳ�˳���\n");

		exit(-1); //�˳�����

	}

	else

	{

	printf("���������룺");

	while(scanf("%s", key), strcmp(password, key))

	{

		tryAgain++;	//�ۼ��������ԵĴ���

		//�������ԵĴ�����������������

		if(tryAgain < 3)

			printf("����%d�Σ����������룺", tryAgain);

		else

			break;	//��������������ڵ������Σ��˳�ѭ��

	}

	

	//3.������

	system("cls");

	//������� ��1���������δ�������� 2��������ȷ������

	printf("----------������---------\n");

	if(tryAgain >= 3)

	{		

		printf("�Բ���3���������ϵͳ�˳���\n");

		exit(-1); //�˳�����

	}

	else

	{

		printf("��ӭ�㣬����Ա��\n");
		
		printf("���ڽ��빦��ѡ��\n");     //����ѡ��

lop:
		
		printf("����1������Ʒ��Ϣ����ϵͳ\n");
		
		printf("����2���붩������ϵͳ\n");
		
		printf("����3�˳�����\n");
		
		int GN;
		
		scanf("%d",&GN);
		
		switch (GN)
		
		{
		
		case 1:
			
			menu();break;
		
		case 2:
			
			order();break;
		
		case 3:
			
			exit(0);break;
		
		default:
			
			{
				
				printf("������1-3֮������֣�лл��\n");
				
				goto lop;
			
			}
		
		}


	}

	}



return 0;

}
