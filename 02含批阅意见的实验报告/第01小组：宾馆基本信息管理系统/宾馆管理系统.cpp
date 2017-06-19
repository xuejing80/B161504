#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN 1				//宏定义房间序号的最小值
#define MAX 30				//宏定义房间序号的最大值
#define LEN sizeof(struct Hotel)					//用LEN代替结构体的"长度"

char menu_select();			//函数声明 
struct Hotel * regeist();
void in_information();				
void out_information();				
void search_number();				
void show_all();						
void search_name();
struct Hotel * change_change();	
void change_save();					
void change();				
void fire();						
struct Hotel * fire_delet();		
void fire_save(struct Hotel *Q);
void check(int n);
struct Hotel *load();	
					       
struct Hotel					    //定义全局结构体变量
{
	int room_number;
	char name [20];
	char sex[10];
	char ID [20];
	float paid[10];
	int inyear ;
	int inmonth ;
	int inday ;
	struct Hotel *next ;
};
char menu_select ()						//定义menu_select函数，用来完成菜单功能
{
	char select ;
	printf ("\n\n--------------------------欢迎使用旅店信息管理系统---------------------------\n\n");
	printf ("1.创建旅店信息\n2.查看旅店信息\n3.查看某一房间信息\n4.查看房客信息\n");
	printf ("5.查找某一房客信息\n6.房客入住\n7.旅客退房\n8.退出管理系统\n");
	printf ("\n-----------------------------------------------------------------------------\n");
	select=getch();
	return select ;						//返回select的值
}

void in_information()					//定义in_information函数，完成创建旅店信息功能
{
	FILE *fp;							//定义文件指针
	char ch,choice[2];
	printf ("\n确定创建新的旅店信息吗?该操作将清除现有的旅店信息！(y/n):");
	scanf  ("%s",choice);
	if((strcmp(choice,"Y")!=0)&&(strcmp(choice,"y")!=0))
		return;
	if ((fp=fopen("information.txt","w"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	printf("\n请创建新的旅店信息(以#结束)：\n");		//提示输入旅店信息
	ch=getchar();
	while (ch!='#')						//判断是否结束输入信息
	{
		fputc(ch,fp);          
		ch=getchar();
	}
	fclose (fp);
	printf ("\n创建信息成功！");		//提示创建信息成功
}

void out_information()				//定义out_information函数，完成查看旅店信息功能
{
	FILE *fp;
	char ch ;
	if ((fp=fopen("information.txt","r"))==NULL)     
	{
		printf ("无法打开文件！\n");
		getch();
	    exit(0);
	}
	ch=fgetc(fp);
	system("cls");
	printf("\n\n\t\t\t旅店信息介绍： (若没有信息请返回创建)");	//开始输出旅店信息
	printf ("\n-------------------------------------------------------------------------------\n\n\t");
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);					//文件用后一定要关闭 
}

struct Hotel * regeist ()				//定义regeist函数，用来完成旅客入住功能
{
	FILE *fp ;			//定义文件指针
	char ch[2] ;
	int number ;
	struct Hotel *head,*p1,*p2 ;
	head=NULL ;
	if((fp=fopen("resturant.txt","a+"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	do
	{
	p1=(struct Hotel *)malloc(LEN);		//开辟新的节点
	p2=(struct Hotel *)malloc(LEN);	
	if ((p1==NULL)||(p2==NULL))
	{
		printf ("动态内存分配失败！\n");	//如果动态内存分配失败，返回失败信息
		getch();
		exit(0);
	}
		printf ("\n请登记入住信息！\n");			//开始登记旅客信息
		printf ("roomnumber(%d~%d)：",MIN,MAX);
		scanf  ("%d",&number);			
		if (number<MIN||number>MAX)					//假设该旅店只有1~30间房间
		{
			printf ("\a\nError ！");
		}
		check (number);					//检查该房间是否已经有旅客入住了
		p1->room_number=number ;		//在该房间没有旅客时，登记入住
		printf ("name:\t");
		scanf  ("%s",&p1->name);
		printf ("sex：\t");
		scanf  ("%s",&p1->sex);
		printf ("ID：\t");
        scanf  ("%s",&p1->ID);
		printf ("paid：\t");
		scanf  ("%s",&p1->paid);
		printf ("date(年月日空格隔开)：");
		scanf ("%d %d %d",&p1->inyear,&p1->inmonth,&p1->inday);
		p1->next=NULL ;
		if(head==NULL)		//将输入的信息保存到链表
		{
			head=p1;
			p2=p1 ;
		}
		else
		{
			p2->next=p1;
			p2=p1 ;
		}
	fwrite(p2,LEN,1,fp);			//将链表信息保存到磁盘文件
	printf ("\n请选择是否继续登记信息 (y/n):");		//判断是否继续登记旅客信息
	scanf  ("%s",ch);
	if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
	{
		fclose (fp);
		printf ("\n登记旅客入住信息成功！");
		return(0);
	}
	}while(1) ;
	return (head) ;			//登记完成后返回头链表指针
}

void search_number ()		//定义search_number函数，用来完成查看某一房间的信息
{
	char ch[2] ;
	int room_number ;		//room_number用来储存需要查询的roomnumber
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n请输入需要查看的房间序号：(%d~%d)：",MIN,MAX);
	scanf  ("%d",&room_number);
	pa= head->next;
	if (room_number<MIN||room_number>MAX)		//Error时，容错判断
	{
		printf ("\a\nError！");
		return ;
	}
	for(;;)			//for语句循环
	{
		if (pa)
		{
			if(room_number==pa->room_number)		//遍历链表，如果找到相应信息，则输出
			{
			
				printf ("\n");
				printf ("roomnumber:\t%d",pa->room_number);
				printf ("\n");
				printf ("name：\t\t%s",pa->name);
				printf ("\n");
				printf ("sex：\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid：\t\t%s",pa->paid);
				printf ("\n");
				printf ("%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n请选择是否继续查看信息(y/n):\n");		//提示是否继续查看
				scanf  ("%s",ch);
				if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
				{
					getch();
					return;
				}
				else
				{
					printf ("\n请输入需要查看的房间序号：(%d~%d)：",MIN,MAX);
					scanf  ("%d",&room_number);
					pa= head->next;
					if (room_number<MIN||room_number>MAX)
					{
						printf ("\a Error ！");
						return;
					}
					continue ;		//跳出该层循环
				}
			}
			pa = pa->next;		//时pa的下一个指针赋值给pa
		}
		else
		{
			printf ("\n该房间还没有旅客入住");		//如果该房间还没有旅客入住，返回相应信息
			return;
		}
	}
}

void show_all()						//定义是show_all函数，用来显示所有旅客信息
{
	struct Hotel *head, *pa ;
	head=load();
	pa= head->next;
	printf ("\n所有入住旅客的信息如下：\n");
	while (pa)										//显示所有的旅客信息
	{
		printf ("\n");
		printf ("roomnumber:\t%d",pa->room_number);
		printf ("\n");
		printf ("name：\t\t%s",pa->name);
		printf ("\n");
		printf ("sex：\t\t%s",pa->sex);
		printf ("\n");
		printf ("ID:\t\t%s",pa->ID);
		printf ("\n");
		printf ("paid：\t\t%s",pa->paid);
		printf ("\n");
		printf ("date：\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
		printf ("\n");
		pa = pa->next;
	}
}
void search_name ()			//定义search_name函数，用来完成查看某一旅客的信息
{
	char ch[2] ;
	char inname[20] ;		//用数组inname[20]来储存需要查询的旅客name
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n请输入需要查看的旅客姓名：");
	scanf  ("%s",inname);
	pa= head->next;
	for (;;)
	{
		if (pa)
		{
			if(strcmp(inname,pa->name)==0)
			{
				printf ("\n");
				printf ("roomnumber:\t%d",pa->room_number);
				printf ("\n");
				printf ("name：\t\t%s",pa->name);
				printf ("\n");
				printf ("sex：\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid：\t\t%s",pa->paid);
				printf ("\n");
				printf ("date：\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n请选择是否继续查看信息(y/n):\n");
				scanf  ("%s",ch);
				if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
				{
					getch();
					return;
				}
				else
				{
					printf ("\n请输入需要查看的旅客姓名：");
					scanf  ("%s",inname);
					pa= head->next;
					continue ;
				}
			}
			pa = pa->next;
		}
		else 
		{
			printf ("\n没有查到该旅客的信息");		//没有此人时，返回相应信息
			return ;
		}
	}
}

void change()
{
	struct Hotel *M ;
	M=change_change();
}
struct Hotel * change_change ()
{
	int room_number ;		//room_number用来储存需要换房的roomnumber
	int newroom_number ;
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n请输入需要换房的房间序号：(%d~%d)：",MIN,MAX);
	scanf  ("%d",&room_number);
	if (room_number<MIN||room_number>MAX)		//容错判断
	{
		printf ("\aError！");
		exit(0) ;
	}
	pa= head->next;
	for (;;)			//for语句循环
	{
		if (pa)
		{
			if(room_number==pa->room_number)
			{
				printf ("\n");
				printf ("roomnumber:\t%d",pa->room_number);
				printf ("\n");
				printf ("name：\t\t%s",pa->name);
				printf ("\n");
				printf ("sex：\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid：\t\t%s",pa->paid);
				printf ("\n");
				printf ("date：\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n请输入需要换到的房间序号：(%d~%d):",MIN,MAX);
				scanf  ("%d",&newroom_number);
				if (newroom_number<MIN||newroom_number>MAX)
				{
					printf ("\aError！");
					exit(0);
				}
				check (newroom_number);
				pa->room_number=newroom_number ;
				break ;
			}
			pa = pa->next;
		}
		else
		{
			printf ("\n该房间还没有旅客入住！\n");
			exit(0);
		}
	}
	return (head) ;
}
void change_save(struct Hotel *Q)
{
	FILE *fp ;
	struct Hotel *L ;
	L=Q->next ;
	if((fp=fopen("resturant.txt","wb"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	while(L)
	{
		fwrite(L,LEN,1,fp);
		L=L->next ;
	}
	fclose(fp);
	printf ("\n换房成功！");
}


void fire()
{
	struct Hotel *M ;
	M=fire_delet();
	fire_save(M);
}

struct Hotel * fire_delet()
{
	char inname[20] ;		//用数组inname[20]来储存需要退房旅客name
	struct Hotel *head, *previous,*pa ;
	head=load();
	previous=(struct Hotel *)malloc(LEN);    //开辟新的节点
	if (previous==NULL)
	{
		printf ("动态内存分配失败！\n");	//如果动态内存分配失败，返回失败信息
		getch();
		exit(0);
	}
	printf ("\n请输入需要退房的旅客姓名：");
	scanf  ("%s",inname);
	pa=head->next ;
	for(;;)
	{
		if (pa)
		{
			if(strcmp(inname,pa->name)==0)
			{
			printf ("\n");
			printf ("roomnumber:\t%d",pa->room_number);
			printf ("\n");
			printf ("name：\t\t%s",pa->name);
			printf ("\n");
			printf ("sex：\t\t%s",pa->sex);
			printf ("\n");
			printf ("ID:\t\t%s",pa->ID);
			printf ("\n");
			printf ("paid：\t\t%s",pa->paid);
			printf ("\n");
			printf ("date：\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
			printf ("\n");
				if(pa==head)
				{
					head=pa->next;
					return head ;
				}
				else 
				{
					previous=head ;
					while(previous->next != pa)        //找到需要查找节点的前一个节点
						previous=previous->next ;
					if (pa->next==NULL)
						previous->next=NULL ;
					else
						previous->next=pa->next ;
						break ;
				}
			}
			pa = pa->next;
		}
		else 
		{
			printf ("\n没有查找到该旅客的信息！\n");
			getch();
			exit(0);
		}
	}
	return (head) ;
}

void fire_save(struct Hotel *Q)
{
	
	FILE *fp ;
	struct Hotel *L ;
	L=Q->next ;
	if((fp=fopen("resturant.txt","wb"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	while(L)
	{
		fwrite(L,LEN,1,fp);
		L=L->next ;
	}
	fclose(fp);
	printf ("\n退房成功！");
}

void check(int n)			//定义check函数，用来检查登记时房间是否已经有旅客入住
{
	FILE *fp ;			
	struct Hotel *head, *pa,*pb, *s ;
	pa=(struct Hotel *)malloc(LEN);    //开辟新的节点
	pb=(struct Hotel *)malloc(LEN);
	s =(struct Hotel *)malloc(LEN);
	head = pb;
	if((pa==NULL)||(pb==NULL)||(s==NULL))
	{
		printf ("内存分配失败！\n");
		getch();
		exit(0);
	}
	if((fp=fopen("resturant.txt","rb"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	while (fread (s,LEN,1,fp))    //读取当前的信息，并存到链表中
	{
		pb->next = s;
		pb = s;
		s = (struct Hotel *)malloc(LEN);
	}
	pb->next =NULL;
	pa=head ;
while (pa)
{
	if (pa->room_number==n)
	{
		printf ("\n%d号房间已经有旅客入住了！\n",n);
		getch();
		exit(0);
	}
	pa=pa->next ;
}
}


struct Hotel *load()		 //定义load函数读取当前的信息，并存到链表中
{
	FILE *fp ;			
	struct Hotel *head,*pb, *s ;
	pb=(struct Hotel *)malloc(LEN);    //开辟新的节点
	s =(struct Hotel *)malloc(LEN);
	if((pb==NULL)||(s==NULL))
	{
		printf ("动态内存分配失败！\n");
		getch();
		exit(0);
	}
	if((fp=fopen("resturant.txt","rb"))==NULL)
	{
		printf ("无法打开文件！\n");
		getch();
		exit(0);
	}
	head = pb;
	while (fread (s,LEN,1,fp))    //读取当前的信息，并存到链表中
	{
		pb->next = s;
		pb = s;
		s = (struct Hotel *)malloc(LEN);
	}
	pb->next =NULL;
	return head ;			//返回链表的头指针
}

int main ()												//主函数部分，调用若干子函数完成相应的功能
{
	char choice ;
	do {
		choice=menu_select();
		switch (choice)									//switch 语句，选择判断               
		{
		  case '1':in_information();break;
		  case '2':out_information();break;
		  case '3':search_number();break;
		  case '4':show_all();break;
		  case '5':search_name();break;
		  case '6':regeist();break;
		  case '7':change();break;
		  case '8':fire();break;
		  case '9':exit(0);break;							//退出旅店信息管理系统
		  default :printf ("\aError ！");break ;	//default 语句
		}
		printf ("\n\n请按任意键继续 ！\n");
		getch();
		system("cls");
	}while(1);
	return 0 ;
}
