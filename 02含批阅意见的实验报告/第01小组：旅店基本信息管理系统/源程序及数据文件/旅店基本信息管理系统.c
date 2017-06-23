#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MIN 1				//�궨�巿����ŵ���Сֵ
#define MAX 30				//�궨�巿����ŵ����ֵ
#define LEN sizeof(struct Hotel)					//��LEN����ṹ���"����"

char menu_select();			//�������� 
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
					       
struct Hotel					    //����ȫ�ֽṹ�����
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
char menu_select ()						//����menu_select������������ɲ˵�����
{
	char select ;
	printf ("\n\n--------------------------��ӭʹ���õ���Ϣ����ϵͳ---------------------------\n\n");
	printf ("1.�����õ���Ϣ\n2.�鿴�õ���Ϣ\n3.�鿴ĳһ������Ϣ\n4.�鿴�����ÿ���Ϣ\n");
	printf ("5.����ĳһ�ÿ���Ϣ\n6.�ÿ���ס\n7.�ÿͻ���\n8.�ÿ��˷�\n9.�˳�����ϵͳ\n");
	printf ("\n-----------------------------------------------------------------------------\n");
	select=getch();
	return select ;						//����select��ֵ
}

void in_information()					//����in_information��������ɴ����õ���Ϣ����
{
	FILE *fp;							//�����ļ�ָ��
	char ch,choice[2];
	printf ("\nȷ�������µ��õ���Ϣ��?�ò�����������е��õ���Ϣ��(y/n):");
	scanf  ("%s",choice);
	if((strcmp(choice,"Y")!=0)&&(strcmp(choice,"y")!=0))
		return ;
	if ((fp=fopen("information.txt","wb"))==NULL)
	{
		printf ("�޷����ļ���\n");
		getch();
		system("pause");system("cls");main();     //pause ����ͣ���������������һ�������ڡ�Press any key to exit�����֣��ȴ��û���һ������Ȼ�󷵻ء�clsΪ���������������������Ļ�����ļ� 
	}
	printf("\n�봴���µ��õ���Ϣ(��#����)��\n");		//��ʾ�����õ���Ϣ
	ch=getchar();
	while (ch!='#')						//�ж��Ƿ����������Ϣ
	{
		fputc(ch,fp);          
		ch=getchar();
	}
	fclose (fp);
	printf ("\n������Ϣ�ɹ���");		//��ʾ������Ϣ�ɹ�
}

void out_information()				//����out_information��������ɲ鿴�õ���Ϣ����
{
	FILE *fp;
	char ch ;
	if ((fp=fopen("information.txt","rb"))==NULL)     
	{
		printf ("�޷����ļ���\n");
		getch();
	    system("pause");system("cls");main();
	}
	ch=fgetc(fp);
	system("cls");
	printf("\n\n\t\t\t�õ���Ϣ���ܣ� (��û����Ϣ�뷵�ش���)");	//��ʼ����õ���Ϣ
	printf ("\n-------------------------------------------------------------------------------\n\n\t");
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);					//�ļ��ú�һ��Ҫ�ر� 
}

struct Hotel * regeist ()				//����regeist��������������ÿ���ס����
{
	FILE *fp ;			//�����ļ�ָ��
	char ch[2] ;
	int number ;
	struct Hotel *head,*p1,*p2 ;
	head=NULL ;
	if((fp=fopen("resturant.txt","ab+"))==NULL)
	{
		printf ("�޷����ļ���\n");
		getch();
		system("pause");system("cls");main();
	}
	do
	{
	p1=(struct Hotel *)malloc(LEN);		//�����µĽڵ�
	p2=(struct Hotel *)malloc(LEN);	
	if ((p1==NULL)||(p2==NULL))
	{
		printf ("��̬�ڴ����ʧ�ܣ�\n");	//�����̬�ڴ����ʧ�ܣ�����ʧ����Ϣ
		getch();
		system("pause");system("cls");main();
	}
		printf ("\n��Ǽ���ס��Ϣ��\n");			//��ʼ�Ǽ��ÿ���Ϣ
		printf ("roomnumber(%d~%d)��",MIN,MAX);
		scanf  ("%d",&number);			
		if (number<MIN||number>MAX)					//������õ�ֻ��1~30�䷿��
		{
			printf ("\a\nError ��");
			return;
		}
		check (number);					//���÷����Ƿ��Ѿ����ÿ���ס��
		p1->room_number=number ;		//�ڸ÷���û���ÿ�ʱ���Ǽ���ס
		printf ("name:\t");
		scanf  ("%s",&p1->name);
		printf ("sex��\t");
		scanf  ("%s",&p1->sex);
		printf ("ID��\t");
        scanf  ("%s",&p1->ID);
		printf ("paid��\t");
		scanf  ("%s",&p1->paid);
		printf ("date(�����տո����)��");
		scanf ("%d %d %d",&p1->inyear,&p1->inmonth,&p1->inday);
		p1->next=NULL ;
		if(head==NULL)		//���������Ϣ���浽����
		{
			head=p1;
			p2=p1 ;
		}
		else
		{
			p2->next=p1;
			p2=p1 ;
		}
	fwrite(p2,LEN,1,fp);			//��������Ϣ���浽�����ļ�
	printf ("\n��ѡ���Ƿ�����Ǽ���Ϣ (y/n):");		//�ж��Ƿ�����Ǽ��ÿ���Ϣ
	scanf  ("%s",ch);
	if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
	{
		fclose (fp);
		printf ("\n�Ǽ��ÿ���ס��Ϣ�ɹ���");
		return(0);
	}
	}while(1) ;
	return (head) ;			//�Ǽ���ɺ󷵻�ͷ����ָ��
}

void search_number ()		//����search_number������������ɲ鿴ĳһ�������Ϣ
{
	char ch[2] ;
	int room_number ;		//room_number����������Ҫ��ѯ��roomnumber
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n��������Ҫ�鿴�ķ�����ţ�(%d~%d)��",MIN,MAX);
	scanf  ("%d",&room_number);
	pa= head->next;
	if (room_number<MIN||room_number>MAX)		//Errorʱ���ݴ��ж�
	{
		printf ("\a\nError��");
		return ;
	}
	for(;;)			//for���ѭ��
	{
		if (pa)
		{
			if(room_number==pa->room_number)		//������������ҵ���Ӧ��Ϣ�������
			{
			
				printf ("\n");
				printf ("roomnumber:\t%d",pa->room_number);
				printf ("\n");
				printf ("name��\t\t%s",pa->name);
				printf ("\n");
				printf ("sex��\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid��\t\t%s",pa->paid);
				printf ("\n");
				printf ("%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n��ѡ���Ƿ�����鿴��Ϣ(y/n):\n");		//��ʾ�Ƿ�����鿴
				scanf  ("%s",ch);
				if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
				{
					getch();
					return;
				}
				else
				{
					printf ("\n��������Ҫ�鿴�ķ�����ţ�(%d~%d)��",MIN,MAX);
					scanf  ("%d",&room_number);
					pa= head->next;
					if (room_number<MIN||room_number>MAX)
					{
						printf ("\a Error ��");
						return;
					}
					continue ;		//�����ò�ѭ��
				}
			}
			pa = pa->next;		//ʱpa����һ��ָ�븳ֵ��pa
		}
		else
		{
			printf ("\n�÷��仹û���ÿ���ס");		//����÷��仹û���ÿ���ס��������Ӧ��Ϣ
			return;
		}
	}
}

void show_all()						//������show_all������������ʾ�����ÿ���Ϣ
{
	struct Hotel *head, *pa ;
	head=load();
	pa= head->next;
	printf ("\n������ס�ÿ͵���Ϣ���£�\n");
	printf ("roomnumber:	");
	printf ("name��		");
	printf ("sex��		");
	printf ("ID:		     ");
	printf ("paid��	      ");
	printf ("date��		\n");
	while (pa)										//��ʾ���е��ÿ���Ϣ
	{		
		printf ("%d		",pa->room_number);		
		printf ("%s		",pa->name);		
		printf ("%s		",pa->sex);		
		printf ("%s    ",pa->ID);		
		printf ("%3s         ",pa->paid);
		printf ("%8d %d %d",pa->inyear,pa->inmonth,pa->inday);
		printf ("\n");
		pa = pa->next;
	}
}
void search_name ()			//����search_name������������ɲ鿴ĳһ�ÿ͵���Ϣ
{
	char ch[2] ;
	char inname[20] ;		//������inname[20]��������Ҫ��ѯ���ÿ�name
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n��������Ҫ�鿴���ÿ�������");
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
				printf ("name��\t\t%s",pa->name);
				printf ("\n");
				printf ("sex��\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid��\t\t%s",pa->paid);
				printf ("\n");
				printf ("date��\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n��ѡ���Ƿ�����鿴��Ϣ(y/n):\n");
				scanf  ("%s",ch);
				if((strcmp(ch,"Y")!=0)&&(strcmp(ch,"y")!=0))
				{
					getch();
					return;
				}
				else
				{
					printf ("\n��������Ҫ�鿴���ÿ�������");
					scanf  ("%s",inname);
					pa= head->next;
					continue ;
				}
			}
			pa = pa->next;
		}
		else 
		{
			printf ("\nû�в鵽���ÿ͵���Ϣ");		//û�д���ʱ��������Ӧ��Ϣ
			return ;
		}
	}
}

void change()
{
	struct Hotel *M ;
	M=change_change();
	change_save(M);
}
struct Hotel * change_change ()
{
	int room_number ;		//room_number����������Ҫ������roomnumber
	int newroom_number ;
	struct Hotel *head, *pa ;
	head=load();
	printf ("\n��������Ҫ�����ķ�����ţ�(%d~%d)��",MIN,MAX);
	scanf  ("%d",&room_number);
	if (room_number<MIN||room_number>MAX)		//�ݴ��ж�
	{
		printf ("\aError��");
		exit(0) ;
	}
	pa= head->next;
	for (;;)			//for���ѭ��
	{
		if (pa)
		{
			if(room_number==pa->room_number)
			{
				printf ("\n");
				printf ("roomnumber:\t%d",pa->room_number);
				printf ("\n");
				printf ("name��\t\t%s",pa->name);
				printf ("\n");
				printf ("sex��\t\t%s",pa->sex);
				printf ("\n");
				printf ("ID:\t\t%s",pa->ID);
				printf ("\n");
				printf ("paid��\t\t%s",pa->paid);
				printf ("\n");
				printf ("date��\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
				printf ("\n");
				printf ("\n��������Ҫ�����ķ�����ţ�(%d~%d):",MIN,MAX);
				scanf  ("%d",&newroom_number);
				if (newroom_number<MIN||newroom_number>MAX)
				{
					printf ("\aError��");
					system("pause");system("cls");main();
				}
				check (newroom_number);
				pa->room_number=newroom_number ;
				break ;
			}
			pa = pa->next;
		}
		else
		{
			printf ("\n�÷��仹û���ÿ���ס��\n");
			system("pause");system("cls");main();
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
		printf ("�޷����ļ���\n");
		getch();
		system("pause");system("cls");main();
	}
	while(L)
	{
		fwrite(L,LEN,1,fp);
		L=L->next ;
	}
	fclose(fp);
	printf ("\n�����ɹ���");
}


void fire()
{
	struct Hotel *M ;
	M=fire_delet();
	fire_save(M);
}

struct Hotel * fire_delet()
{
	char inname[20] ;		//������inname[20]��������Ҫ�˷��ÿ�name
	struct Hotel *head, *previous,*pa ;
	head=load();
	previous=(struct Hotel *)malloc(LEN);    //�����µĽڵ�
	if (previous==NULL)
	{
		printf ("��̬�ڴ����ʧ�ܣ�\n");	//�����̬�ڴ����ʧ�ܣ�����ʧ����Ϣ
		getch();
		system("pause");system("cls");main();
	}
	printf ("\n��������Ҫ�˷����ÿ�������");
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
			printf ("name��\t\t%s",pa->name);
			printf ("\n");
			printf ("sex��\t\t%s",pa->sex);
			printf ("\n");
			printf ("ID:\t\t%s",pa->ID);
			printf ("\n");
			printf ("paid��\t\t%s",pa->paid);
			printf ("\n");
			printf ("date��\t\t%d %d %d",pa->inyear,pa->inmonth,pa->inday);
			printf ("\n");
				if(pa==head)
				{
					head=pa->next;
					return head ;
				}
				else 
				{
					previous=head ;
					while(previous->next != pa)        //�ҵ���Ҫ���ҽڵ��ǰһ���ڵ�
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
			printf ("\nû�в��ҵ����ÿ͵���Ϣ��\n");
			getch();
			system("pause");system("cls");main();
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
		printf ("�޷����ļ���\n");
		getch();
		system("pause");system("cls");main();
	}
	while(L)
	{
		fwrite(L,LEN,1,fp);
		L=L->next ;
	}
	fclose(fp);
	printf ("\n�˷��ɹ���");
}

void check(int n)			//����check�������������Ǽ�ʱ�����Ƿ��Ѿ����ÿ���ס
{
	FILE *fp ;			
	struct Hotel *head, *pa,*pb, *s ;
	pa=(struct Hotel *)malloc(LEN);    //�����µĽڵ�
	pb=(struct Hotel *)malloc(LEN);
	s =(struct Hotel *)malloc(LEN);
	head = pb;
	if((pa==NULL)||(pb==NULL)||(s==NULL))
	{
		printf ("�ڴ����ʧ�ܣ�\n");
		getch();
		system("pause");system("cls");main();
	}
	if((fp=fopen("resturant.txt","rb"))==NULL)
	{
		printf ("�޷����ļ���\n");
		getch();
		change();
	}
	while (fread (s,LEN,1,fp))    //��ȡ��ǰ����Ϣ�����浽������
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
		printf ("\n%d�ŷ����Ѿ����ÿ���ס�ˣ�\n",n);
		getch();
		change();
		}
	pa=pa->next ;
}
}


struct Hotel *load()		 //����load������ȡ��ǰ����Ϣ�����浽������
{
	FILE *fp ;			
	struct Hotel *head,*pb, *s ;
	pb=(struct Hotel *)malloc(LEN);    //�����µĽڵ�
	s =(struct Hotel *)malloc(LEN);
	if((pb==NULL)||(s==NULL))
	{
		printf ("��̬�ڴ����ʧ�ܣ�\n");
		getch();
		system("pause");system("cls");main();
	}
	if((fp=fopen("resturant.txt","rb"))==NULL)
	{
		printf ("�޷����ļ���\n");
		getch();
		system("pause");system("cls");main();
	}
	head = pb;
	while (fread (s,LEN,1,fp))    //��ȡ��ǰ����Ϣ�����浽������
	{
		pb->next = s;
		pb = s;
		s = (struct Hotel *)malloc(LEN);
	}
	pb->next =NULL;
	return head ;			//���������ͷָ��
}

int main ()												//���������֣����������Ӻ��������Ӧ�Ĺ���
{
	char choice ;
	do {
		choice=menu_select();
		switch (choice)									//switch ��䣬ѡ���ж�               
		{
		  case '1':in_information();break;
		  case '2':out_information();break;
		  case '3':search_number();break;
		  case '4':show_all();break;
		  case '5':search_name();break;
		  case '6':regeist();break;
		  case '7':change();break;
		  case '8':fire();break;
		  case '9':exit(0);break;							//�˳��õ���Ϣ����ϵͳ
		  default :printf ("\aError ��");break ;	//default ���
		}
		printf ("\n\n�밴��������� ��\n");
		getch();
		system("cls");
	}while(1);
	return 0 ;
}
