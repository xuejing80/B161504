#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
void showInf_s(){//显示学生信息 
	FILE *fp;
	student st;
	printf("%-12s%-11s%-11s%-25s%-25s%-9s\n","学号","姓名","性别","所选课程1","所选课程2","总费用");
	printf("-------------------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//读取二进制形式文件 （学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&st,sizeof(st),1,fp);
		while(!feof(fp)){
			printf("%-12s%-11s%-11s%-25s%-25s%-9.1f\n",st.ID,st.name,st.sex,st.cor[0].name,st.cor[1].name,st.fee);
			fread(&st,sizeof(st),1,fp);
		}
	}
	fclose(fp);
}

void showInf_c(){//显示课程信息 
	FILE *fp;
	course crs;
	printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","课程号","课程名称","上课时段","报名人数","学费","课程分类");
	printf("-------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//读取二进制形式文件 （课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&crs,sizeof(crs),1,fp);
		while(!feof(fp)){//逐行打出课程信息 
			printf("%-9d%-25s%",crs.ID,crs.name);
			if(crs.time[1]<10){//调整时间输出格式 
				printf("%2d:0%d-",crs.time[0],crs.time[1]);
			}
			if(crs.time[1]>=10){
				printf("%2d:%d-",crs.time[0],crs.time[1]);
			}
			if(crs.time[3]<10){
				printf("%2d:0%-5d",crs.time[2],crs.time[3]);
			}
			if(crs.time[3]>=10){
				printf("%2d:%-6d",crs.time[2],crs.time[3]);
			}
			printf("%2d/%-9d%-9.1f%-7s\n",crs.member[0],crs.member[1],crs.tuition,crs.category);
			fread(&crs,sizeof(crs),1,fp);
		}
	}
	fclose(fp);
}

int judge(char ID[10],student temp[NUM]){//判断学号是否重复 增加学生信息时调用（addStdInf()） 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//读取二进制形式文件（学生0 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//逐条对比学号判断是否重复 
			if(strcmp(ID,temp[i].ID)==0)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_2(int ID,course temp[NUM]){//判断课程号是否重复 增加课程信息时调用（addCrsInf()） 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//读取二进制形式文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//逐行对比课程号判断是否重复 
			if(ID==temp[i].ID)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_3(char ID[10],student temp[NUM],char num[10]){//判断学号是否重复 修改学生信息时调用（cngStdInf()） 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//读取二进制形式文件（学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//逐行对比学号判断是否重复 
			if(strcmp(ID,temp[i].ID)==0&&strcmp(num,temp[i].ID)!=0)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_4(int ID,course temp[NUM],int num){//判断课程是否重复 修改课程信息时调用（cngStdInf()）
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//读取二进制形式文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//逐行对比课程号判断是否重复 
			if(ID==temp[i].ID&&num!=temp[i].ID)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int addStdInf(){//添加学生信息 
	FILE *fp;
	student st;
	student temp[NUM];
	if((fp=fopen("statistic_s.dat","ab"))==NULL){//以追加的方式写入二进制形式文件（学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input information of the student:\n");
			printf("ID: ");
			scanf("%s",&st.ID);
			if(judge(st.ID,temp)){//判断学号是否重复 
				printf("Name: ");
				scanf("%s",&st.name);
				printf("Sex: ");
				scanf("%s",&st.sex);
				strcpy(st.cor[0].name,"");
				strcpy(st.cor[1].name,"");
				st.fee=0;
				fwrite(&st,sizeof(st),1,fp);
				fclose(fp);
			}else{
				fclose(fp);
				printf("This record exist, you can not insert again!\n");
				return 0;
			}	
	}
	return 1;
}

int addCrsInf(){//添加课程信息 
	FILE *fp;
	course crs;
	course temp[NUM];
    crs.ID=-100;
    crs.time[1]=-1;
    crs.time[3]=-1;
    crs.member[1]=-100;
    crs.tuition=-100;
	char b[25];
	if((fp=fopen("statistic_c.dat","ab"))==NULL){//以追加的方式写入二进制形式文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input information of the course:\n");
			do{
				printf("ID: ");
				scanf("%d",&crs.ID);
				if(crs.ID<=0){//防止输入字符串打乱程序执行 
					if(crs.ID==-100){
						scanf("%s",b);
					}
					printf("Error of input!\n");
					system("pause");
				}
			}while(crs.ID<=0);
			if(judge_2(crs.ID,temp)){//判断课程号是否重复 
				printf("Name: ");
				scanf("%s",&crs.name);
				do{
					start:
					printf("Start time: ");
					scanf("%d:%d",&crs.time[0],&crs.time[1]);
					if(crs.time[1]==-1){//防止输入字符串打乱程序执行 
						scanf("%s",b);
					    printf("Error of input!\n");
					    system("pause");
					    goto start;
					}
					if(crs.time[0]>24||crs.time[0]<0||crs.time[1]>60||crs.time[1]<0){//判断时间格式 
						printf("Error format of time!\n");
						system("pause");
					}
				}while(crs.time[0]>24||crs.time[0]<0||crs.time[1]>60||crs.time[1]<0);
				do{
					action:
					printf("End time: ");
					scanf("%d:%d",&crs.time[2],&crs.time[3]);
					if(crs.time[3]==-1){//防止输入字符串打乱程序执行 
						scanf("%s",b);
					    printf("Error of input!\n");
					    system("pause");
					    goto action;
					}
					if(crs.time[2]>24||crs.time[2]<0||crs.time[3]>60||crs.time[3]<0){//判断时间格式 
						printf("Error format of time!\n");
						system("pause");
					}
					if(crs.time[2]<crs.time[0]||(crs.time[2]==crs.time[0]&&crs.time[3]<=crs.time[1])){//判断课程结束时间是否大于开始时间 
						printf("Ending time must be larger than start time!\n");
						system("pause");
					}
				}while(crs.time[2]>24||crs.time[2]<0||crs.time[3]>60||crs.time[3]<0||(crs.time[2]<crs.time[0]||(crs.time[2]==crs.time[0]&&crs.time[3]<=crs.time[1])));
				begin:
				printf("Max member: ");
				scanf("%d",&crs.member[1]);
				if(crs.member[1]<=0){//防止输入字符串打乱程序执行  判断限制人数是否小于等于0 
					if(crs.member[1]==-100){
						scanf("%s",b);
					}
					crs.member[1]=-100;
					printf("Error of input!\n");
					system("pause");
					goto begin;
				}
				crs.member[0]=0;
				loop:
				printf("Tuition: ");
				scanf("%f",&crs.tuition);
				if(crs.tuition<=0){//防止输入字符串打乱程序执行  判断学费是否小于等于0 
					if(crs.tuition==-100){
						scanf("%s",b);
					}
					crs.tuition=-100;
					printf("Error of input!\n");
					system("pause");
					goto loop;
				}
				printf("Category: ");
				scanf("%s",&crs.category);
				fwrite(&crs,sizeof(crs),1,fp);
				fclose(fp);
			}else{
				fclose(fp);
				printf("This record exist, you can not insert again!\n");
				return 0;
			}	
	}
	return 1;
}

void srhStudent(){//查询学生信息 
	FILE *fp;
	char inf[10];
	int i,rank,count=0;
	student temp[NUM];
	student *p=temp;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//读取二进制形式文件（学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//把数据库中的学生信息赋给temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
				printf("Input the information will be searched: ");
				scanf("%s",inf);
				printf("%-12s%-11s%-11s%-25s%-25s%-9s\n","学号","姓名","性别","所选课程1","所选课程2","总费用");
				printf("-------------------------------------------------------------------------------------------\n");
				for(i=0;i<count;i++){//根据学生学号、姓名、性别、所选课程、查询结果并显示 
					if(strcmp(inf,temp[i].ID)==0||strcmp(inf,temp[i].name)==0||strcmp(inf,temp[i].sex)==0||strcmp(inf,temp[i].cor[0].name)==0||strcmp(inf,temp[i].cor[1].name)==0)
						printf("%-12s%-11s%-11s%-25s%-25s%-9.1f\n",temp[i].ID,temp[i].name,temp[i].sex,temp[i].cor[0].name,temp[i].cor[1].name,temp[i].fee);
				}
	}
}

void srhCourse(){//查询课程信息 
	FILE *fp;
	char inf[10];
	int i,rank,count=0;
	course temp[NUM];
	course *p=temp;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//读取二进制形式文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//把数据库中的课程信息赋给temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
				printf("Input the information will be searched: ");
				scanf("%s",inf);
				printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","课程号","课程名称","上课时段","报名人数","学费","课程分类");
				printf("-------------------------------------------------------------------------------\n");
				for(i=0;i<count;i++){//根据课程号、课程名称、课程类别查询并输出结果 
					if(atoi(inf)==temp[i].ID||strcmp(inf,temp[i].name)==0||strcmp(inf,temp[i].category)==0){
							printf("%-9d%-25s%",temp[i].ID,temp[i].name);
							if(temp[i].time[1]<10){//输出时间格式 
								printf("%2d:0%d-",temp[i].time[0],temp[i].time[1]);
							}
							if(temp[i].time[1]>=10){
								printf("%2d:%d-",temp[i].time[0],temp[i].time[1]);
							}
							if(temp[i].time[3]<10){
								printf("%2d:0%-5d",temp[i].time[2],temp[i].time[3]);
							}
							if(temp[i].time[3]>=10){
								printf("%2d:%-6d",temp[i].time[2],temp[i].time[3]);
							}
							printf("%2d/%-9d%-9.1f%-7s\n",temp[i].member[0],temp[i].member[1],temp[i].tuition,temp[i].category);
					}
				}
	}
}

int cngStdInf(){//修改学生信息 
	FILE *fp;
	char num[10];
	int i,rank,count=0,j;
	student temp[NUM],reput,st[NUM];
	student *p=temp;
	if((fp=fopen("statistic_s.dat","rb+"))==NULL){//读取、写入二进制形式文件（学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//把数据库中的学生信息赋给temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		printf("Input the student's ID: ");
		scanf("%s",num);
		for(i=0;i<count;i++){//逐行对比找到要修改的学生 
			if(strcmp(num,temp[i].ID)==0){ 
				reput=temp[i];
				printf("ID: ");
				scanf("%s",&reput.ID);
				if(judge_3(reput.ID,st,num)){//判断学号是否重复 
					printf("Name: ");
					scanf("%s",&reput.name);
					printf("Sex: ");
					scanf("%s",&reput.sex);
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//覆盖重写文件 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}
					
					fclose(fp);
					return 1;
				}else{
					fclose(fp);
					printf("This ID is used by another student, you can not insert again!\n");
					return 0;
				}	
			}	
		}
		printf("Student not found!\n");
		return 0;
	}
}

int cngCrsInf(){//修改课程信息 
	FILE *fp;
	FILE *dp;
	int num=-1;
	char a[25];
	char b[25];
	int i,rank,count=0,j,l,cnt=0;
	course temp[NUM],reput,crs[NUM];
	course *p=temp;
	student tmp[NUM],*q=tmp;
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//写入、读取二进制形式文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//把数据库中的课程信息赋给temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		begin:
		printf("Input the ID of the course: ");
		scanf("%d",&num);
		if(num==-1){//防止输入字符串打乱程序执行 
			scanf("%s",a);
			printf("Error of input!\n");
			system("pause");
			goto begin;
		}
		for(i=0;i<count;i++){//逐行对比找到课程 
			if(num==temp[i].ID){
				reput=temp[i];
				start:
				printf("New ID: ");
				scanf("%s",&b);
				if((reput.ID=atoi(b))<=0){//防止输入字符串打乱程序执行 
					printf("Error of input!\n");
			        system("pause");
			        goto start;
				}
				if(judge_4(reput.ID,crs,num)){//判断课程号是否重复 
					printf("Name: ");
					scanf("%s",&reput.name);
					do{
						reput.time[1]=-1;
						action:
						printf("Start time: ");
						scanf("%d:%d",&reput.time[0],&reput.time[1]);
						if(reput.time[1]==-1){//防止输入字符串打乱程序执行 
					        scanf("%s",a);
					        printf("Error of input!\n");
					        system("pause");
			                goto action;
				         }
						if(reput.time[0]>24||reput.time[0]<0||reput.time[1]>60||reput.time[1]<0){//判断时间格式 
							printf("Error format of time!\n");
						}
					}while(reput.time[0]>24||reput.time[0]<0||reput.time[1]>60||reput.time[1]<0);
					do{
						reput.time[3]=-1;
						loop:
						printf("End time: ");
						scanf("%d:%d",&reput.time[2],&reput.time[3]);
						if(reput.time[3]==-1){//防止输入字符串打乱程序执行 
					        scanf("%s",a);
					        printf("Error of input!\n");
					        system("pause");
			                goto loop;
				         }
						if(reput.time[2]>24||reput.time[2]<0||reput.time[3]>60||reput.time[3]<0){//判断时间格式 
							printf("Error format of time!\n");
						}
						if(reput.time[2]<reput.time[0]||(reput.time[2]==reput.time[0]&&reput.time[3]<=reput.time[1])){//判断结束时间是否大于初始时间 
						    printf("Ending time must be larger than start time!\n");
						    system("pause");
					    }
					}while(reput.time[2]>24||reput.time[2]<0||reput.time[3]>60||reput.time[3]<0||(reput.time[2]<reput.time[0]||(reput.time[2]==reput.time[0]&&reput.time[3]<=reput.time[1])));
					start_2:
					printf("Max member: ");
					scanf("%s",&b);
				    if((reput.member[1]=atoi(b))<=0){//防止输入字符串打乱程序执行 判断限制人数是否小于等于0 
					    printf("Error of input!\n");
			            system("pause");
			            goto start_2;
			     	}
			     	reput.tuition=-100;
			     	start_3:
					printf("Tuition: ");
					scanf("%f",&reput.tuition);
					if(reput.tuition<=0){//防止输入字符串打乱程序执行  判断学费是否小于等于0 
					    if(reput.tuition==-100){
						    scanf("%s",a);
					    }
					    reput.tuition=-100;
					    printf("Error of input!\n");
					    system("pause");
					    goto start_3;
				    }
					printf("Category: ");
					scanf("%s",&reput.category);
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//覆盖写入课程信息 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}
					fclose(fp);
					if((dp=fopen("statistic_s.dat","rb+"))==NULL){//修改选择该课程对应的学生的课程信息包括总费用 
						printf("Can not open the file!Please check your disk!\n\a");
				    }else{
					    fread(q,sizeof(tmp[0]),1,dp);
					    while(!feof(dp)){ //把数据库中的 学生信息赋给tmp 
					    	cnt++;
					    	q++;
					    	fread(q,sizeof(tmp[0]),1,dp);
				    	}
					    fseek(dp,0L,0);
					    for(l=0;l<cnt;l++){//覆盖重写选择该课程对应的学生的课程信息包括总费用 
						    if(reput.ID==tmp[l].cor[0].ID){//逐行搜索找到受影响的学生 
						    	tmp[l].cor[0]=reput;
						    	tmp[l].fee=tmp[l].cor[0].tuition+tmp[l].cor[1].tuition;
					    	}
					    	if(reput.ID==tmp[l].cor[1].ID){//逐行搜索找到受影响的学生 
						    	tmp[l].cor[1]=reput;
								tmp[l].fee=tmp[l].cor[0].tuition+tmp[l].cor[1].tuition;	
					    	}
					    	fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
				    	}
				        fclose(dp);
		   	        }
					return 1;
				}else{
					fclose(fp);
					printf("This ID is used by another course, you can not insert again!\n");
					return 0;
				}	
			}	
		}
		printf("Course not found!\n");
		return 0;
	}
}

int delStdInf(){//删除学生信息 
	FILE *fp;
	FILE *dp; 
	int i,j,k,count=0,l;
	student st[NUM];
	student temp;
	course tmp[NUM],*p=tmp;
	char input[10],charge;
	loop:
	i=0;
	j=0;
	k=0;
	if((fp=fopen("statistic_s.dat","rb+"))==NULL){//写入、读取二进制形式文件 （学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input the student's ID or name you want to delete: ");
			scanf("%s",input);
			scanf:
			printf("Are you sure to delete student %s ?(Y/N): ",input);//确认是否删除 
				getchar();
				scanf("%c",&charge);
				switch(charge){
					case 'n':
					case 'N':return 0;
					case 'y':
					case 'Y':break;
					default: printf("Error of input!\n");
							 goto scanf;
				}
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //把数据库中的学生信息赋给st 
				if(strcmp(input,temp.ID)!=0&&strcmp(input,temp.name)!=0){//判断学生是否存在 
					st[i]=temp;
					i++;
				}else{
					k++;
					--temp.cor[0].member[0];
					--temp.cor[1].member[0];
					if((dp=fopen("statistic_c.dat","rb+"))==NULL){//修改课程中选课人数 
						printf("Can not open the file!Please check your disk!\n\a");
					}else{
						fread(p,sizeof(tmp[0]),1,dp);
						while(!feof(dp)){ //把数据库中的课程信息赋给tmp 
							count++;
							p++;
							fread(p,sizeof(tmp[0]),1,dp);
						}
						fseek(dp,0L,0);
						for(l=0;l<count;l++){//逐行搜索收影响的课程并覆盖修改其中的选课人数 
							if(temp.cor[0].ID==tmp[l].ID){
								fwrite(&temp.cor[0],sizeof(tmp[0]),1,dp);
							}
							else if(temp.cor[1].ID==tmp[l].ID){
								fwrite(&temp.cor[1],sizeof(tmp[0]),1,dp);
							}else{
								fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
							}
						}
						fclose(dp);
		   	    	}	
				}
				fread(&temp,sizeof(temp),1,fp);
			} 
			fclose(fp);
			if(k==0){
				printf("Student not found!\n");
				goto loop;
			}else{
				if((fp=fopen("statistic_s.dat","wb"))==NULL){
					printf("Can not open the file!Please check your disk!\n\a");
				}else{
					for(;j<i;j++){//覆盖写入删除后的学生信息 
						fwrite(&st[j],sizeof(st[j]),1,fp);
					}
				fclose(fp);
		   	    }	
			}	
	}
	return 1;
}

int delCrsInf(){//删除课程信息 
	FILE *fp;
	FILE *dp;
	int i,j,k,count=0,l;
	course crs[NUM];
	course temp,temp_2;
	student tmp[NUM],*p=tmp;
	char input[20],charge;
	loop:
	i=0;
	j=0;
	k=0;
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//读取、写入二进制形式文件 （课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input ID or name of the course you want to delete: ");
			scanf("%s",input);
			scanf:
			printf("Are you sure to delete course %s ?(Y/N): ",input);//确认删除操作 
				getchar();
				scanf("%c",&charge);
				switch(charge){
					case 'n':
					case 'N':return 0;
					case 'y':
					case 'Y':break;
					default: printf("Error of input!\n");
							 goto scanf;
				}
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //把数据库中的课程信息赋给 crs 
				if(atoi(input)!=temp.ID&&strcmp(input,temp.name)!=0){//覆盖删除学生信息并判断要删除的课程是否存在 
					crs[i]=temp;     //把不是要删除的课程信息输入crs[] 
					i++;
				}else{
					k++;  //如果找到了要删除的课程则 k++   要删除的课程就不会写入crs[]里了 
					temp_2=temp;  //temp_2即为要删除的课程 
					
				}
				fread(&temp,sizeof(temp),1,fp);  //读下一条课程信息，接着执行找的工作 
			} 
			fclose(fp);
			if(k==0){
				printf("Course not found!\n");
				goto loop;
			}else{
				if((fp=fopen("statistic_c.dat","wb"))==NULL){//写入二进制形式文件 （课程） 
					printf("Can not open the file!Please check your disk!\n\a");
				}else{
					for(;j<i;j++){ //将crs[]课程信息逐条写入文件 
						fwrite(&crs[j],sizeof(crs[j]),1,fp);  //将不含要删除课程的crs[]写入文件，从而删除了课程 
					}
				fclose(fp);
		   	    }	
		   	    if((dp=fopen("statistic_s.dat","rb+"))==NULL){//删除学生信息中的该课程 
						printf("Can not open the file!Please check your disk!\n\a");
				}else{
					fread(p,sizeof(tmp[0]),1,dp);
					while(!feof(dp)){ 
						count++;
						p++;
						fread(p,sizeof(tmp[0]),1,dp);
					}
					fseek(dp,0L,0);
					for(l=0;l<count;l++){//逐行对比找到受影响的学生并修改其选课信息 
						if(temp_2.ID==tmp[l].cor[0].ID){
							tmp[l].cor[0].ID=0;
							tmp[l].cor[0].tuition=0;
							tmp[l].fee-=temp_2.tuition;
							strcpy(tmp[l].cor[0].name,"");	
						}
						if(temp_2.ID==tmp[l].cor[1].ID){
							tmp[l].cor[1].ID=0;
							tmp[l].cor[0].tuition=0;
							tmp[l].fee-=temp_2.tuition;
							strcpy(tmp[l].cor[1].name,"");	
						}
						fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
					}
				    fclose(dp);
		   	    }	
		    }	
	}
	return 1;
}

int rnkCourse(){//根据课程号课程排序 
	FILE *fp;
	int i=0,j=0,k,l=0,count=1;
	course crs[NUM];
	course temp,tmp;
	int tmp_course[NUM];
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//读取、写入二进制形式的文件（课程） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //把数据库中的课程信息赋值给crs 
				crs[i]=temp;
				tmp_course[i]=temp.ID;
				i++;
				fread(&temp,sizeof(temp),1,fp);
			} 
			fseek(fp,0L,0);
			for(;j<i;j++){
				for(k=1;k<i;k++){
					if(crs[k].ID<crs[k-1].ID){
						tmp=crs[k-1];
						crs[k-1]=crs[k];
						crs[k]=tmp;
					}
				}
			}
			for(j=0;j<i;j++){
				fwrite(&crs[j],sizeof(crs[0]),1,fp);
			}
			fclose(fp);
	}
	return 1;
}

int cngStdCrs(char num[10]){//修改学生选课信息 
	FILE *fp,*dp;
	int i,rank,count=0,j,cnt=0,k,l,m;
	char lesson[25];
	student temp[NUM],reput,st[NUM];
	student *p=temp;
	course tmp[NUM],*b=tmp;
	if((dp=fopen("statistic_c.dat","rb"))==NULL){//读取二进制形式的文件 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(b,sizeof(tmp[0]),1,dp);
		while(!feof(dp)){//把数据库中的课程信息赋给tmp 
			cnt++;
			b++;
			fread(b,sizeof(tmp[0]),1,dp);
		}
		fclose(dp);
		}
	
		if((fp=fopen("statistic_s.dat","rb+"))==NULL){//写入、读取二进制形式的文件（学生） 
			printf("Can not open the file!Please check your disk!\n\a");
		}else{
			fread(p,sizeof(temp[0]),1,fp);
			while(!feof(fp)){//把数据库中的学生信息赋给temp 
				count++;
				p++;
				fread(p,sizeof(temp[0]),1,fp);
			}
			for(i=0;i<count;i++){//逐行对比找到需报名的学生 
				if(strcmp(num,temp[i].ID)==0){
					reput=temp[i];
					for(m=0;m<cnt;m++){//逐行对比找到受影响的课程并调整其选课人数 
						if(reput.cor[0].ID==tmp[m].ID){
							--tmp[m].member[0];
						}
						if(reput.cor[1].ID==tmp[m].ID){
							--tmp[m].member[0];
						}
					}
					first:
						printf("The first course you choose:");
						scanf("%s",lesson);
						for(k=0;k<cnt;k++){
							if(strcmp(lesson,tmp[k].category)==0){//判断是否是课程类型，是的话提示该类型下可选课程 
								printf("You can choose the following courses under this category:\n");
								for(l=0;l<cnt;l++){
									if(strcmp(tmp[l].category,lesson)==0){
										printf("%d   %s\n",tmp[l].ID,tmp[l].name);
									}
								}
								goto first;
							}
							if(atoi(lesson)==tmp[k].ID||strcmp(lesson,tmp[k].name)==0){  //如果输入的是课程号或者是课程名 
								if(tmp[k].member[0]<tmp[k].member[1]){//判断课程是否满员 
									++tmp[k].member[0];
									reput.cor[0]=tmp[k];
									goto second;
								}else{
									printf("The course is full!\n");
									goto first;
								}
							}
						}
						printf("Course not found!\n");
						goto first;
					second:
						printf("The second course you choose:");
						scanf("%s",lesson);
						for(k=0;k<cnt;k++){
							if(strcmp(lesson,tmp[k].category)==0){//判断是否是课程类型，是的话提示该类型下可选课程 
								printf("You can choose the following courses under this category:\n");
								for(l=0;l<cnt;l++){
									if(strcmp(tmp[l].category,lesson)==0){
										printf("%d   %s\n",tmp[l].ID,tmp[l].name);
									}
								}
								goto second;
							}
							if(atoi(lesson)==tmp[k].ID||strcmp(lesson,tmp[k].name)==0){//防止输入字符串打乱程序执行 判断课程是否存在 
								if(tmp[k].ID==reput.cor[0].ID){//判断课程2和课程1是否重复 
									printf("Please choose different courses!\n");
									goto second;
								}
								if(tmp[k].member[0]<tmp[k].member[1]){//判断课程时间是否冲突 
									if(((tmp[k].time[0]>reput.cor[0].time[2])||((tmp[k].time[0]==reput.cor[0].time[2])&&(tmp[k].time[1]>=reput.cor[0].time[3])))||((tmp[k].time[2]<reput.cor[0].time[0])||((tmp[k].time[2]==reput.cor[0].time[0])&&(tmp[k].time[3]<=reput.cor[0].time[1])))){
										//判断课程冲突的判断语句 
										++tmp[k].member[0];
										reput.cor[1]=tmp[k];
										goto continious;
									}else{
										printf("Class time conflict!\n");
										goto second;
									}
								}else{
									printf("The course is full!\n");
									goto second;
								}
							}
						}
						printf("Course not found!\n");
						goto second;
					continious:
					reput.fee=reput.cor[0].tuition+reput.cor[1].tuition;
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//覆盖写入学生信息 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}	
					fclose(fp);
					if((dp=fopen("statistic_c.dat","wb"))==NULL){//写入二进制形式的文件（课程） 
						printf("Can not open the file!Please check your disk!\n\a");
					}else{
						for(j=0;j<cnt;j++){//覆盖写入课程信息 
							fwrite(&tmp[j],sizeof(tmp[0]),1,dp);
						}
						fclose(dp);	
					}
					return 1;	
				}	
			}
			return 0;
		}
}

void showCrsInf(char num[10]){
	FILE *fp;
	int i;
	student st;
	printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","课程号","课程名称","上课时段","报名人数","学费","课程分类");
	printf("-------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//读取二进制形式的文件（学生） 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&st,sizeof(st),1,fp);
		while(!feof(fp)){//逐行对比查找相应的学生并输出其信息 
			if(strcmp(st.ID,num)==0){
				for(i=0;i<2;i++){
					if(st.cor[i].ID!=0){
						printf("%-9d%-25s%",st.cor[i].ID,st.cor[i].name);
						if(st.cor[i].time[1]<10){//输出时间格式 
							printf("%2d:0%d-",st.cor[i].time[0],st.cor[i].time[1]);
						}
						if(st.cor[i].time[1]>=10){
							printf("%2d:%d-",st.cor[i].time[0],st.cor[i].time[1]);
						}
						if(st.cor[i].time[3]<10){
							printf("%2d:0%-5d",st.cor[i].time[2],st.cor[i].time[3]);
						}
						if(st.cor[i].time[3]>=10){
							printf("%2d:%-6d",st.cor[i].time[2],st.cor[i].time[3]);
						}
						printf("%2d/%-9d%-9.1f%-7s\n",st.cor[i].member[0],st.cor[i].member[1],st.cor[i].tuition,st.cor[i].category);
					}	
				}
				break;	
			}
			fread(&st,sizeof(st),1,fp);	
		}
	}
	fclose(fp);
}
