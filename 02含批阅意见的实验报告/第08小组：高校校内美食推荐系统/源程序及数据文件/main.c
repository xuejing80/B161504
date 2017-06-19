
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct Food{
	char location[100]; // 地理位置
	char shopname[20]; // 店家名称
	char foodname[20]; // 食物名称
	char photo[20]; // 照片
	float price; // 价格
	int scoresum; // 总分
	int scorenum; // 评价条数
}food;

void save(food *food, int size);
int Login();

int main()
{
	int option;
	FILE *fp;
	char loc[20];
	int i;
	int size = 0;
	int id;
	food *f = (food *)malloc(size);
	food ftemp;
	char location[100]; // 地理位置
	char shopname[20]; // 店家名称
	char foodname[20]; // 食物名称
	char photo[20]; // 照片
	float price; // 价格
	float sum = 0;
	float a, b;
	int j = 1;
	char foname[20];
	int q;
	
	q=Login();
    while(q==0)
	{
		q=Login();
	}
	system("pause");

	while (true)
	{
		system("cls");
		printf("请输入要使用的功能：\n1.添加/删除/修改\n2.菜品信息查询\n3.选择菜品\n4.评分系统\n");
		scanf("%d", &option);
		// 增删改

		system("cls");
		if (option == 1)
		{
			printf("请输入要使用的功能：\n1.添加\n2.删除\n3.修改\n0.返回\n");
			scanf("%d", &option);
			if (option == 1)
			{
				char location[100]; // 地理位置
				char shopname[20]; // 店家名称
				char foodname[20]; // 食物名称
				char photo[20]; // 照片
				float price; // 价格
				printf("请输入：地理位置,店家名称,食物名称,照片,价格\n");
				getchar();
				scanf("%[^,],%[^,],%[^,],%[^,],%f", location, shopname, foodname, photo, &price);
				
				fp = fopen("food.txt", "a+");
				fprintf(fp, "%s %s %s %s %.2f 0 0\n", location, shopname, foodname, photo, price);
				fflush(fp);
				fclose(fp);
			}
			else if (option == 2)
			{
				int size = 0;
				food *f = (food *)malloc(size);
				food ftemp;
				FILE *fp;
				fp = fopen("food.txt", "r+");
				while (fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^ ] %f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, &ftemp.price, &ftemp.scoresum, &ftemp.scorenum) != EOF)
				{
					f = (food *)realloc(f, (size + 1) * sizeof(food));
					f[size] = ftemp;
					size++;
					//printf("%s %s %s %s %.2f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, ftemp.price, ftemp.scoresum, ftemp.scorenum);
				}
				fclose(fp);
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
				for ( i = 0; i < size; i++)
				{
					printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
				}
				printf("请输入要删除的编号：\n");
				scanf("%d", &id);
				id--;
				size--;
				for (i = id; i < size; i++)
				{
					f[i] = f[i + 1];
				}
				for (i = 0; i < size; i++)
				{
					printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
				}
				save(f, size);
			}
			else if (option == 3)
			{
				int size = 0;
				food *f = (food *)malloc(size);
				food ftemp;
				FILE *fp;
				fp = fopen("food.txt", "r+");
				while (fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^ ] %f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, &ftemp.price, &ftemp.scoresum, &ftemp.scorenum) != EOF)
				{
					f = (food *)realloc(f, (size + 1) * sizeof(food));
					f[size] = ftemp;
					size++;
					//printf("%s %s %s %s %.2f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, ftemp.price, ftemp.scoresum, ftemp.scorenum);
				}
				fclose(fp);
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
				for (i = 0; i < size; i++)
				{
					printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
				}
				printf("请输入要修改的编号：\n");
				scanf("%d", &id);
				id--;
				
				printf("请输入：地理位置,店家名称,食物名称,照片,价格\n");
				getchar();
				scanf("%[^,],%[^,],%[^,],%[^,],%f", location, shopname, foodname, photo, &price);
				strcpy(f[id].location, location);
				strcpy(f[id].shopname, shopname);
				strcpy(f[id].foodname, foodname);
				strcpy(f[id].photo, photo);
				f[id].price = price;
				save(f, size);
			}
		}
		else if (option == 2)
		{
			printf("请输入要使用的功能：\n1.根据位置查询\n2.根据价格区间查询\n3.根据菜品名称查询\n0.返回\n");
			scanf("%d", &option);
			

			fp = fopen("food.txt", "r+");
			while (fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^ ] %f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, &ftemp.price, &ftemp.scoresum, &ftemp.scorenum) != EOF)
			{
				f = (food *)realloc(f, (size + 1) * sizeof(food));
				f[size] = ftemp;
				size++;
				//printf("%s %s %s %s %.2f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, ftemp.price, ftemp.scoresum, ftemp.scorenum);
			}
			fclose(fp);
			if (option == 1)
			{
				printf("请输入位置信息：\n");
				
				scanf("%s", loc);
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
			j=1;
				for ( i = 0; i < size; i++)
				{
					if (strcmp(loc, f[i].location) == 0)
					{
						printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (j++), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
					}
				}
			}
			else if (option == 2)
			{
				printf("请输入价格区间a-b：\n");
				
				scanf("%f-%f", &a, &b);
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
			j = 1;
				for (i = 0; i < size; i++)
				{
					if (f[i].price >= a && f[i].price <= b)
					{
						printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (j++), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
					}
				}
			}
			else if (option == 3)
			{
				printf("请输入菜品名称：\n");
			
				scanf("%s", foname);
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
				j = 1;
				for (i = 0; i < size; i++)
				{
					if (strcmp(foname, f[i].foodname) == 0)
					{
						printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (j++), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
					}
				}
			}
		}
		else if (option == 3)
		{
			int size = 0;
			food *f = (food *)malloc(size);
			food ftemp;
			FILE *fp;
			fp = fopen("food.txt", "r+");
			while (fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^ ] %f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, &ftemp.price, &ftemp.scoresum, &ftemp.scorenum) != EOF)
			{
				f = (food *)realloc(f, (size + 1) * sizeof(food));
				f[size] = ftemp;
				size++;
				//printf("%s %s %s %s %.2f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, ftemp.price, ftemp.scoresum, ftemp.scorenum);
			}
			fclose(fp);
			printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\n");
			for (i = 0; i < size; i++)
			{
				printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);
			}
			printf("请输入要选择的编号，输入0结束：\n");
			
			while (scanf("%d", &id) != EOF && id != 0)
			{
				sum += f[id - 1].price;
			}
			printf("选择的菜品总价为%.2f\n", sum);
		}
		else if (option == 4)
		{
			int size = 0;
			food *f = (food *)malloc(size);
			food ftemp;
			FILE *fp;
			fp = fopen("food.txt", "r+");
			while (fscanf(fp, "%[^ ] %[^ ] %[^ ] %[^ ] %f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, &ftemp.price, &ftemp.scoresum, &ftemp.scorenum) != EOF)
			{
				f = (food *)realloc(f, (size + 1) * sizeof(food));
				f[size] = ftemp;
				size++;
				//printf("%s %s %s %s %.2f %d %d\n", ftemp.location, ftemp.shopname, ftemp.foodname, ftemp.photo, ftemp.price, ftemp.scoresum, ftemp.scorenum);
			}
			fclose(fp);
			printf("请输入要使用的功能：\n1.评分\n2.查询评分\n0.返回\n");
			scanf("%d", &option);
			if (option == 1)
			{
				int id, score;
				printf("请输入编号和评分：\n");
				scanf("%d %d", &id, &score);
				id--;
				f[id].scoresum += score;
				f[id].scorenum++;
				save(f, size);
			}
			else if (option == 2)
			{
				printf("编号\t地理位置\t店家名称\t食物名称\t照片\t价格\t评分\n");
				for (i = 0; i < size; i++)
				{
					printf("%d\t%s\t%s\t%s\t%s\t%.2f\t%.2f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price, ((float)f[i].scoresum / (float)f[i].scorenum));
				}
			}
		}
		system("pause");
	}
	return 0;
}

void save(food *food, int size) 
{
	FILE *fp;
	int i;
	fp = fopen("food.txt", "w+");
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%s %s %s %s %.2f %d %d\n", food[i].location, food[i].shopname, food[i].foodname, food[i].photo, food[i].price, food[i].scoresum, food[i].scorenum);
	}
	fflush(fp);
	fclose(fp);
}

//登陆，登陆失败返回0
int Login()
{
	char user[20], userFile[20];
	char psw[20], pswFile[20];
	FILE* fp;

	system("cls");
	fflush(stdin);
	printf("===管理员登陆===\n");
	printf("用户名: ");
	scanf("%s", user);
	printf("密  码: ");
	scanf("%s", psw);

	fp = fopen("user.txt", "r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s", userFile, pswFile);
		if(strcmp(user, userFile)==0 && strcmp(psw, pswFile)==0)
		{
			printf("登陆成功!\n");
			return 1;
		}
	}
	fclose(fp);
	printf("登陆失败!\n");
	fflush(stdin);

	return 0;
}