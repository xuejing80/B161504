#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#include <conio.h>
#include <string.h>

#define NUM 20
#define ALL 100

char admin[NUM],password[NUM],cpassword[NUM],kong[11]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

struct  gz                      //定义月份信息 
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
};						//员工信息 
typedef struct gz gz;

struct  xinxi
{ 
	char name[10];   //姓名 
	char sex[3];    //性别 
	char job[5];    //工作 
	int old;	    //年龄 
	gz gongzi; 

};						//员工信息 
typedef struct xinxi xinxi;



struct  zhanghao
{
	char adm[11];  //定义管理员账号密码选项 
	char mima[11];
};
typedef struct zhanghao zhanghao; //账号信息 

struct  yonghu  //用户找好密码 
{
	char adm[11];
	char mima[11];
};
typedef struct yonghu yonghu;


void gotoxy(int x ,int y)  //界面设置，定义printf打印的位置 
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD Ioc;
	Ioc.X = x;
	Ioc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,Ioc);
}


void jiemian()  //界面函数 
{
	system("cls");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");//定义用户界面 
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


//判断两次密码是否一致，一致返回1，不一直返回0.
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


//****************************************从这行开始输入各功能**************************




void xiugai(xinxi a[],int N)//修改用户，通过用户的姓名定位 
{
	char z[2]={' '},x[2]={'\12'};
	int kai;
	char zanshi[20];
//	yonghu d[1];
	FILE *fp2;
	fp2 = fopen("D:\\员工信息.txt","w");
//	int i=0;
	jiemian();
	gotoxy(11,5);
	printf("需要修改的姓名:");
	gotoxy(11,6);
	scanf("%s",zanshi);//输入姓名 
	getch;
	gotoxy(20,6);

	
	for(kai=0;kai<N;kai++)//定位 
	{
		if(check(zanshi,a[kai].name))
		{
			break;
		}
	}

	getch;
	jiemian();
	gotoxy(11,5);
	printf("请输入员工姓名:");
	scanf("%s",a[kai].name);//输入修改的各种信息 

	jiemian();
	gotoxy(11,5);
	printf("请输入员工性别:");
	scanf("%s",a[kai].sex);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工职业:");
	scanf("%s",a[kai].job);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工年龄:");
	scanf("%d",&a[kai].old);
		
	
	jiemian();
	gotoxy(11,5);
	printf("请输入员工第1月的工资:");
	scanf("%d",&a[kai].gongzi.Jan);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第2月的工资:");
	scanf("%d",&a[kai].gongzi.Feb);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第3月的工资:");
	scanf("%d",&a[kai].gongzi.Mar);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第4月的工资:");
	scanf("%d",&a[kai].gongzi.Apr);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第5月的工资:");
	scanf("%d",&a[kai].gongzi.May);
	
	jiemian();
	gotoxy(11,5);
	printf("请输入员工第6月的工资:");
	scanf("%d",&a[kai].gongzi.Jun);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第7月的工资:");
	scanf("%d",&a[kai].gongzi.Jul);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第8月的工资:");
	scanf("%d",&a[kai].gongzi.Aug);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第9月的工资:");
	scanf("%d",&a[kai].gongzi.Sep);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第10月的工资:");
	scanf("%d",&a[kai].gongzi.Oct);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第11月的工资:");
	scanf("%d",&a[kai].gongzi.Nov);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第12月的工资:");
	scanf("%d",&a[kai].gongzi.Dec);


//这里加入导出程序，将输入的信息写入到文件 
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
//printf("1");测试文件写入是否成功，写入几次。上面是修改信息之前的信息 
	}
	{
		fputs(a[kai].name,fp2);//将修改的信息写入文件 
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
//printf("写入");测试修改信息是否写入 
		fputs(x,fp2);
	}
	ji=kai+1;
	for(ji;ji<N;ji++)//通过最后循环将修改信息后面的信息写入文件 
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
//printf("1");测试写入是否成功，写入几次 

	}
	jiemian();
	printf("修改成功"); 
	Sleep(3000);
}






void add(FILE *fp1,FILE *fp2)					//增加会员
{
	char c[2]={' '},d[2]={'\12'};
	xinxi people;
	fp1 = fopen("D:\\用户.txt","a+");
	fp2 = fopen("D:\\员工信息.txt","a+");//两个指针分别写入用户文件和信息文件 

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

//输入账号和密码
	getchar();
	gotoxy(21,5);
	scanf("%s",admin);
	gotoxy(20,6);
	getchar;

//	password[0]='!';
//	while(getchar() != )
	while(password[i]=getch())
	{
		if(password[i]==13)  break;//将输入的密码变成* 
        printf("*");
		i++;
	}
	getchar;
//	cpassword[0]=getch();
	i=0;
	gotoxy(28,7);
	while(cpassword[i]=getch())
	{
		if(cpassword[i]==13) break;//确认密码变成* 
        printf("*");
		i++;
	}

	if(check(password,cpassword)==0)			//密码的验证
	{
		jiemian();
		gotoxy(28,7);
		printf("两次密码不同");
		Sleep(3000);
		getchar();
	}


	jiemian();
	gotoxy(11,5);
	printf("请输入员工姓名:");
	scanf("%s",people.name);//数据录入 

	jiemian();
	gotoxy(11,5);
	printf("请输入员工性别:");
	scanf("%s",people.sex);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工职业:");
	scanf("%s",people.job);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工年龄:");
	scanf("%d",&people.old);
	
	jiemian();
	gotoxy(11,5);
	printf("请输入员工第1月的工资:");
	scanf("%d",&people.gongzi.Jan);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第2月的工资:");
	scanf("%d",&people.gongzi.Feb);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第3月的工资:");
	scanf("%d",&people.gongzi.Mar);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第4月的工资:");
	scanf("%d",&people.gongzi.Apr);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第5月的工资:");
	scanf("%d",&people.gongzi.May);
	
	jiemian();
	gotoxy(11,5);
	printf("请输入员工第6月的工资:");
	scanf("%d",&people.gongzi.Jun);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第7月的工资:");
	scanf("%d",&people.gongzi.Jul);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第8月的工资:");
	scanf("%d",&people.gongzi.Aug);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第9月的工资:");
	scanf("%d",&people.gongzi.Sep);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第10月的工资:");
	scanf("%d",&people.gongzi.Oct);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第11月的工资:");
	scanf("%d",&people.gongzi.Nov);

	jiemian();
	gotoxy(11,5);
	printf("请输入员工第12月的工资:");
	scanf("%d",&people.gongzi.Dec);
	
	jiemian();
	gotoxy(11,5);
	printf("添加成功！"); 
	

//这里加入导出程序
	
	fseek(fp1,0,2);			//让指针指向文件尾
	fputs(d,fp1);
	fputs(admin,fp1);
	fputs(c,fp1);

	fputs(password,fp1);//写入用户文件		
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
	printf("添加成功!");
	Sleep(3000);

}



//每一次读取这个函数，文件用写，然后将删除元素之后的数组写入


void del(zhanghao a[],xinxi b[],int N)					//删除账号和密码
{
	char z[2]={' '},x[2]={'\12'};//添加空格和换行数组 
	char y[6]={'no'}; //用来擦出信息的数组 存在warning需要解答 
	int kai;
	char zanshi[20];
//	yonghu d[1];
	FILE *fp2;
	fp2 = fopen("D:\\员工信息.txt","w");
//	int i=0;
	jiemian();
	gotoxy(11,5);
	printf("需要删除的姓名:");//这里用到的功能和有修改相同，因个人能力有限 
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
//printf("1");//删除‘//’可以测试程序写入次数 

	}
{
strcpy(b[kai].name,y);//printf("a");测试赋值是否成功		
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
//printf("1");测试赋值成功？ 
}
	{
		fputs(b[kai].name,fp2);//修改的数据，因为函数体不容易实现后面的顺次覆盖会出现混乱和bug 
		fputs(z,fp2);		   //所以使用了修改原始数据为0的方式擦出 
		
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
//printf("1");测试数据写入 
		fputs(x,fp2);
}

	ji=kai+1;printf("e");
	for(ji;ji<N;ji++)
	{		//printf("ha");测试for循环执行次数 
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
//printf("1");测试 

	}


	gotoxy(25,7);
	printf("删除成功");
	sleep(3000);		
}


void findall(xinxi a[],int N)		//查找信息			这里只显示最后一个月(12月)的工资，如果要显示其他月的工资，只需要自己加上对应的月份就行了，即a[i].gongzi.Dec
{
	int i=0; 
	jiemian();
	gotoxy(11,4);
	printf("  会  员  名     性别      职       业    年龄  工资\n");
	for( ; i<N ; i++ )
	{
		gotoxy(11,5+i);
		printf("%-14s%4s%16s    %4d   %6d\n",a[i].name,a[i].sex,a[i].job,a[i].old,a[i].gongzi.Dec);
	}
	//sleep（3000） 
	getch();
}


void findmyself(xinxi a[],int i)		//同上 
{
	jiemian();
	gotoxy(11,4);
	printf("会  员  名     性别      职       业    年龄  工资\n");
	gotoxy(11,5);
	printf("%-14s%4s%16s    %4d   %6d\n",a[i].name,a[i].sex,a[i].job,a[i].old,a[i].gongzi.Dec);
	getch();
} 



int sui(int shouru)//税收计算 
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
	printf("你第1月应该支付：%d的税收。",sui(a[i].gongzi.Jan));
	gotoxy(11,5);
	printf("你第2月应该支付：%d的税收。",sui(a[i].gongzi.Feb));
	gotoxy(11,6);
	printf("你第3月应该支付：%d的税收。",sui(a[i].gongzi.Mar));
	gotoxy(11,7);
	printf("你第4月应该支付：%d的税收。",sui(a[i].gongzi.Apr));
	gotoxy(11,8);
	printf("你第5月应该支付：%d的税收。",sui(a[i].gongzi.May));
	gotoxy(11,9);
	printf("你第6月应该支付：%d的税收。",sui(a[i].gongzi.Jun));
	gotoxy(11,10);
	printf("你第7月应该支付：%d的税收。",sui(a[i].gongzi.Jul));
	gotoxy(11,11);
	printf("你第8月应该支付：%d的税收。",sui(a[i].gongzi.Aug));
	gotoxy(11,12);
	printf("你第9月应该支付：%d的税收。",sui(a[i].gongzi.Sep));
	gotoxy(11,13);
	printf("你第10月应该支付：%d的税收。",sui(a[i].gongzi.Oct));
	gotoxy(11,14);
	printf("你第11月应该支付：%d的税收。",sui(a[i].gongzi.Nov));
	gotoxy(11,15);
	printf("你第12月应该支付：%d的税收。",sui(a[i].gongzi.Dec));
   
	
 
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
	gotoxy(11,4);
	printf("这一年，共有员工%d人，工资总数为%d，税收总数为%d",n,shouru,gongji);


	getch();
		//sleep(3000);
}






//********************************从这里开始功能函数结束*************************************



//这里是界面返回数字

void daoshu()
{
	int x=4;
	while(x--)
	{
		gotoxy(25,7);
		printf("%d秒后返回主界面",x);
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


	
	fp1 = fopen("D:\\管理员账号密码.txt","a+");	//用于账号和密码的验证或者添删
	if(fp1 == 0)
	{
		exit(0);		//退出程序
	}					//文件校验

//********************这里把账号和密码赋给结构体****************
	while( !feof(fp1) && i < ALL)
	{
		fscanf(fp1,"%s%s",hao[i].adm,hao[i].mima);
		i++ ;
		
	}
	M = i-1;
	i = 0;

	fp2 = fopen("D:\\员工信息.txt","a+");
	if(fp2 == 0)
	{
		exit(0);
	}

//*****************在这里把文件fp2里面内容赋给结构体**********************************


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

	fp3 = fopen("D:\\用户.txt","a+");
	while( !feof(fp3) && i < ALL )
	{
		fscanf(fp3,"%s%s",yh[i].adm,yh[i].mima);
		i++;
	}
	
	i=0;

begin:

//开始界面
	
	jiemian();
	gotoxy(11,2);
	printf("欢迎使用员工工资管理系统!");
	gotoxy(11,5);
	printf("admin:");
	gotoxy(11,6);
	printf("password:");

//账号和密码输入
	gotoxy(17,5);
	scanf("%s",admin);
	gotoxy(20,6);

	while(password[i]=getch())
	{
		if(password[i]==13) break;
        printf("*");
		i++;
	}





//账号和密码的验证
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
			printf("登陆成功!");
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
//主界面
	do
	{
		jiemian();
		gotoxy(20,2);
		printf("------------------");
		gotoxy(20,3);
		printf("员工工资管理系统");
		gotoxy(20,4);
		printf("------------------");
		gotoxy(20,5);
		printf("请选择您要的功能:");
		gotoxy(20,6);
		printf("1.添加新员工");
		gotoxy(20,7);
		printf("2.注销员工");
		gotoxy(20,8);
		printf("3.查询员工信息");			//按照品牌和车款
		gotoxy(20,9);
		printf("4.修改员工信息");
		gotoxy(20,10);
		printf("5.显示统计数据");
		gotoxy(20,11);
		printf("6.关闭程序");
		gotoxy(20,21);
		printf("按w与s控制方向，按z确认");


//功能选择
		gotoxy(17,xuanze+5);
		printf("→");
		weizhi=getch();
		switch( weizhi )			//进行判断，如果输入W，那么坐标上移，如果输入S，那么坐标下移 
		{
		default: break;
		case 'w': xuanze--;break;
		case 's': xuanze++;break;
		}


	if(xuanze<1)
		xuanze=1;
	else if(xuanze>7)
		xuanze=7;

	}while(weizhi != 'z');//输入判断，如果输入了Z，那么就进入相应功能 


	jiemian();

//界面划分
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


//这里写用户自己的界面
ziji:
	do
	{
		jiemian();
		gotoxy(20,2);
		printf("------------------");
		gotoxy(20,3);
		printf("员工工资管理系统");
		gotoxy(20,4);
		printf("------------------");
		gotoxy(20,5);
		printf("请选择您要的功能:");
		gotoxy(20,6);
		printf("1.查询自己信息");
		gotoxy(20,7);
		printf("2.查询应交税");
		gotoxy(20,8);
		printf("3.修改信息.");			
		gotoxy(20,9);
		printf("4.关闭程序");

		gotoxy(20,21);
		printf("按w与s控制方向，按z确认");


//功能选择
		gotoxy(17,xuanze+5);
		printf("→");
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

	}while(weizhi != 'z');//输入判断


	jiemian();

//界面划分
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
