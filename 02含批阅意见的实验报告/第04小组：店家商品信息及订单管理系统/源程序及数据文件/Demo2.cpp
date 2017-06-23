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

printf("还需要操作么？如果需要操作请输入：yes，否则请输入：no\n");

scanf("%s",biaozhi);

if(strcmp(biaozhi,"yes")==0)

{

menu();

}

else if(strcmp(biaozhi,"no")==0)

exit(0);

else

{

printf("请输入正确的字符，谢谢！\n");

fhzjm();

}

}

void DengJi()

{

int rs;

int i,k=1;

system("CLS");

printf("请输入需要输入几个商品信息：");

scanf("%d",&rs);

for(i=shuliang;i<shuliang+rs;i++,k++)

{

printf("请输入第%d个商品的编号：",k);

scanf("%d",&food[i].number);

printf("请输入商品的名称：");

scanf("%s",food[i].name);

printf("请输入销量：");

scanf("%d",&food[i].sale);

}

shuliang=shuliang+rs;

fhzjm();

}

void ShanChu()

{

char shanchuinfo[10];

system("CLS");

printf("删除全部商品信息请输入\"all\"，删除指定编号的商品信息请输入\"one\"\n");

scanf("%s",shanchuinfo);

if(strcmp(shanchuinfo,"all")==0)

{

int j;

printf("你删除的商品信息如下：\n");

printf("-----------编号-------------商品--------------销量\t\n");

for(j=0;j<shuliang;j++)

printf("----%d-------%s-------%d\t\n",food[j].number,food[j].name,food[j].sale);

shuliang=0;

printf("删除成功\n\n");

}

else if(strcmp(shanchuinfo,"one")==0)

{

struct food *p=NULL;

int choice;

int i,j,k=0;

printf("请输入你要删除的商品的编号:");

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

printf("删除成功\n\n");

}

else

{

printf("输入数据错误！\n");

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

printf("系统里面没有任何商品的信息！\n");

}

else
{
for(i=0;i<shuliang;i++)
{
printf("第%d个商品信息为:\t\n",i+1);

printf("-----------编号-------------商品--------------销量\t\n");

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

printf("系统里面没有任何商品的信息！\n");

fhzjm();

}

printf("三种查找方式：编号，名称，销量\n");

printf("如果按编号查找请输1\n如果按名称查找请输2\n如果按销量查找请输3\n");

printf("请输入您查找的方式：");

scanf("%s",&choice);

if(choice=='1')

{

printf("请输入需要查找商品的编号：");

scanf("%d",&xx);

printf("您所查找的商品的信息为：\n");

printf("----编号----名称----销量----\t\n");

for(i=0;i<shuliang;i++)

{

if(xx==food[i].number)

{

j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("输入信息有误：\n");

}

else if(choice=='2')

{

printf("请输入需要查找商品的名称：\n");

scanf("%s",yy);

printf("您所查找的商品的信息为：\n");

printf("----编号----名称----销量----\t\n");

for(i=0;i<shuliang;i++)

{

if(strcmp(yy,food[i].name)==0)

{

j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("输入信息有误：\n");

}

else if(choice=='3')

{
	
printf("请输入需要查找商品的销量：\n");

scanf("%d",&xx);

printf("您所查找的商品的信息为：\n");

printf("----编号----名称----销量----\t\n");

for(i=0;i<shuliang;i++)

{
	
if(xx==food[i].sale)

{
	
j=i;k=1;

printf("----%d-------%s-------%d----\t\n",food[j].number,food[j].name,food[j].sale);

}

}

if(k==0)

printf("输入信息有误：\n");

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

printf("按照销量排序之后的信息为：\n");

printf("--编号--名称--销量--\t\n");

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

perror("写文件失败！\n");

return;

}

printf("存储文件成功！\n");

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

perror("读取文件打开失败！\n");

return;

}

memset(food,0x0,sizeof(food));

while(1)

{

fread(&t,sizeof(t),1,fp);

if(ferror(fp))

{

fclose(fp);

perror("读文件过程失败！\n");

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

printf("导出文件成功！\n");

fhzjm();

}

void menu()

{

int n=0;

system("CLS");

printf(" 店家商品信息管理系统\n");

printf("---------MENU--------\n");

printf(" 1.登记商品信息\n");

printf(" 2.删除商品信息\n");

printf(" 3.浏览所有已经登记的商品\n");

printf(" 4.查找\n");

printf(" 5.根据销量排序\n");

printf(" 6.存储到文件\n");

printf(" 7.从文件导出\n");

printf(" 8.退出系统\n");

a:	printf(" 请选择：");

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

printf("请输入1-8之间的数字，谢谢！\n");

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

printf("请输入配送年份:"); 

scanf("%d",&p->deliver.year); 

printf("请输入配送月份:");
 
scanf("%d",&p->deliver.month);
 
if((p->deliver.month>0)&&(p->deliver.month<13))
 
{ 

printf("请输入配送日期:"); 

scanf("%d",&p->deliver.day);
 
printf("请输入物品名称:"); 

scanf("%s",p->name);
 
printf("请输入物品编号:"); 

scanf("%s",&p->num1); 

printf("请输入物品配送地:");
 
scanf("%s",p->dest); 

printf("请输入配送个数:");
 
scanf("%d",&p->num2); 

printf("请输入配送金额:");
 
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

printf("1按名称查找\n2按类型查找\n ");

printf("请输入你的选择：");

scanf("%d",&choice);

if(choice>=1&&choice<=2)

{

if(choice==1)

{

printf("请输入物品名称：");

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

printf("请输入物品编号\n ");

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

printf("请输入要删除的物品名称：");

scanf("%s",name);

printf("请输入金额：");

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

printf("确认删除？\n 1是\n 2否\n");

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

printf("确认删除？\n 1是\n 2否\n");

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
printf("欢迎使用商品配送管理系统\n");
printf("************************************\n");

printf("1:添加记录\n");

printf("2:显示记录\n");

printf("3:查询记录\n");

printf("4:删除记录\n");

printf("5:退出\n");

printf("请输入您的选择:\n");

scanf("%d", &n);

switch(n)

{case 1: add();break;

case 2: show();break;

case 3: search();break;

case 4: delete_rec();break;

case 5: exit(0);break;

default :printf("error\n");}

printf("是否返回主菜单? 0是 1否\n");

scanf("%d",&s);b=b+s;

}

}


int main()

{
	char nam[N];

	char password[N]; 		//用于存放密码

    char shop[N];

	char key[N];		//用于保存确认密码

	int tryAgain = 0;				//重试的次数

	

	//1.创建管理系统

	do

	{

		printf("----------创建用户---------\n");

	    printf("请输入你的用户名：");

		scanf("%s", nam);

		printf("请输入你的管理密码：");

		scanf("%s", password);

		printf("请确认你的管理密码：");

		scanf("%s", key);

	}
	while(strcmp(password, key));

	/*

		strcmp() string compare字符串比较函数，如果第一字符串比第二个字符串大返回1，

		如果第一字符串比第二个字符串小返回-1，两个字符串相等返回0

	*/

	printf("密码设置成功！\n您的用户名为%s\n你的密码为%s\n", nam,password);

	

	printf("按任意键开始登录系统.....\n");

	getch();	//阻塞函数，可以让程序停留在此，直到我们按下键盘上的某个按键

	system("cls");	//清屏

	

	//2.登录系统

	printf("----------登录系统---------\n");

	printf("请输入用户名：");

   while(scanf("%s", shop), strcmp(nam, shop))

	{

		tryAgain++;	//累加密码重试的次数

		//密码重试的次数限制在三次以内

		if(tryAgain < 3)

			printf("错误%d次！请重新输入：", tryAgain);

		else

			break;	//输入密码次数大于等于三次，退出循环

	}

	

	//3.输出结果

	system("cls");

	//两种情况 ：1输入了三次错误的密码 2输入了正确的密码

	if(tryAgain >= 3)

	{		

		printf("对不起，3次密码错误，系统退出！\n");

		exit(-1); //退出程序

	}

	else

	{

	printf("请输入密码：");

	while(scanf("%s", key), strcmp(password, key))

	{

		tryAgain++;	//累加密码重试的次数

		//密码重试的次数限制在三次以内

		if(tryAgain < 3)

			printf("错误%d次！请重新输入：", tryAgain);

		else

			break;	//输入密码次数大于等于三次，退出循环

	}

	

	//3.输出结果

	system("cls");

	//两种情况 ：1输入了三次错误的密码 2输入了正确的密码

	printf("----------输出结果---------\n");

	if(tryAgain >= 3)

	{		

		printf("对不起，3次密码错误，系统退出！\n");

		exit(-1); //退出程序

	}

	else

	{

		printf("欢迎你，管理员！\n");
		
		printf("现在进入功能选择\n");     //功能选择

lop:
		
		printf("输入1进入商品信息管理系统\n");
		
		printf("输入2进入订单管理系统\n");
		
		printf("输入3退出程序\n");
		
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
				
				printf("请输入1-3之间的数字，谢谢！\n");
				
				goto lop;
			
			}
		
		}


	}

	}



return 0;

}
