#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
#include"menu.h"
#include"file.h"
#include"method.h"
int main(){
	createFile();//创建学生和课程数据库 
	printf("---------------------------------\n");
	printf("\n    欢迎使用课程收费管理系统\n");
	printf("           Welcome to\n");
	printf("the course fee management system!\n");
	printf("\n---------------------------------\n\n");
	printf("%35s","作者：孙璐、谭迪文、张懋涵\n\n");//打印欢迎菜单 
	mainMenu: 
	switch(mainMenu()){//打印主菜单 
		case 5: {
			char ID[10];
			strcpy(ID,""); 
			eryMenu:
			switch(eryMenu(ID)){//学生报名入口   传入报名学生ID 
				case 1: {
					showCrsInf(ID);//已选课程查询 
					system("pause");
					goto eryMenu;
					break;
				}
				case 2:{
					if(cngStdCrs(ID)){//修改选课报名 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto eryMenu;
					break;
				}
				case 0: strcpy(ID,"");////返回主菜单并清空学生ID 
						goto mainMenu;
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto eryMenu;
			}
			break;
		}
		case 1:{
			infMenu: 
			switch(infMenu()){//打印基本信息菜单
				case 1: {
					showInf_s();//显示学生信息 
					system("pause");
					goto infMenu;
				}
				case 2:{
					showInf_c();//显示课程信息 
					system("pause");
					goto infMenu;
				}
				case 0: goto mainMenu;//返回主菜单 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto infMenu;
			}
			break;
		}	
		case 3:{
			crsMngMenu:
			switch(crsMngMenu()){//课程管理菜单 
				case 1:{
					if(addCrsInf()){//添加课程信息 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}
				case 2:{
					if(cngCrsInf()){//修改课程信息 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					} 
					system("pause");
					goto crsMngMenu;
				} 
				case 3:{
					if(delCrsInf()){//删除课程信息 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}	
				case 4:{
					if(rnkCourse()){//根据课程号排序 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}	
				case 0: goto mainMenu;//返回主菜单 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto crsMngMenu;
			}
			break;
		} 
		case 4:{
			stdMngMenu:
			switch(stdMngMenu()){//学生信息管理 
				case 1: {
					if(addStdInf()){//添加学生 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto stdMngMenu;
				}
				case 2: {
					if(cngStdInf()){//修改学生信息 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					} 
					system("pause");
					goto stdMngMenu;
				} 
				case 3: {
					if(delStdInf()){//删除学生 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto stdMngMenu;
				}		
				case 0: goto mainMenu;//返回主菜单 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto stdMngMenu;
			}
			break;
		}	
		case 2:{
			srhMenu:
			switch(srhMenu()){//打印查询菜单 
				case 1: srhCourse();//查询课程 
						system("pause");
						goto srhMenu;
				case 2: srhStudent();//查询学生 
						system("pause");
						goto srhMenu;
				case 0: goto mainMenu;//返回主菜单 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto srhMenu;
			}
			break;
		}	
		case 0: printf("\n感谢您的使用，再见！\n\n");//告别信息 
				system("pause");
				return 0;
		default:printf("Error of input!\n");
				system("pause");
				goto mainMenu;
	}
}
