#include<stdio.h>

#include<stdlib.h>

#include<string.h>



#define true 1

#define false 0



typedef struct Food{

	char location[100]; // ����λ��

	char shopname[20]; // �������

	char foodname[20]; // ʳ������

	char photo[20]; // ��Ƭ

	float price; // �۸�

	int scoresum; // �ܷ�

	int scorenum; // ��������

}food;



void save(food *food, int size);//���ṹ�����������д���ļ�

int Login();//��½����½ʧ�ܷ���0



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

	char location[100]; // ����λ��

	char shopname[20]; // �������

	char foodname[20]; // ʳ������

	char photo[20]; // ��Ƭ

	float price; // �۸�

	float sum = 0;

	float a, b;

	int j = 1;

	char foname[20];

	int q=0;

	

    while(!q) q=Login();



	system("pause");



	while (true)

	{

		system("cls");

		printf("������Ҫʹ�õĹ��ܣ�\n��1.���/ɾ��/�޸�\n��2.��Ʒ��Ϣ��ѯ\n��3.ѡ���Ʒ\n��4.����ϵͳ\n");

		scanf("%d", &option);

		

		system("cls");

		if (option == 1)

		{

			printf("������Ҫʹ�õĹ��ܣ�\n��1.���\n��2.ɾ��\n��3.�޸�\n��0.����\n");

			scanf("%d", &option);

			if (option == 1)

			{

				char location[100]; // ����λ��

				char shopname[20]; // �������

				char foodname[20]; // ʳ������

				char photo[20]; // ��Ƭ

				float price; // �۸�

				printf("�����룺����λ��,�������,ʳ������,��Ƭ,�۸�\n");

				getchar();

				scanf("%[^,],%[^,],%[^,],%[^,],%f", location, shopname, foodname, photo, &price);

				

				fp = fopen("food.txt", "a+");//�Զ�д��ʽ��ָ���ļ�

				fprintf(fp, "%s %s %s %s %.2f 0 0\n", location, shopname, foodname, photo, price);//������Ϣ���ļ�

				fflush(fp);//�����ļ���Ϣ

				fclose(fp);//�ر��ļ�

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

				}

				fclose(fp);

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for ( i = 0; i < size; i++)

				{	

					printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

				}

				printf("������Ҫɾ���ı�ţ�\n");

				scanf("%d", &id);

				id--;

				size--;

				for (i = id; i < size; i++)

				{

					f[i] = f[i + 1];

				}

                system("cls");

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for ( i = 0; i < size; i++)

				{	

					printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

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

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for ( i = 0; i < size; i++)

				{	

					printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

				}

				printf("������Ҫ�޸ĵı�ţ�\n");

				scanf("%d", &id);

				id--;

				

				printf("�����룺����λ��,�������,ʳ������,��Ƭ,�۸�\n");

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

			int size=0;

			printf("������Ҫʹ�õĹ��ܣ�\n��1.����λ�ò�ѯ\n��2.���ݼ۸������ѯ\n��3.���ݲ�Ʒ���Ʋ�ѯ\n��0.����\n");

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

				printf("������λ����Ϣ��\n");

				

				scanf("%s", loc);

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for ( i = 0; i < size; i++)

				{

					if (strcmp(loc, f[i].location) == 0)

					{

						printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

					}

				}

			}

			else if (option == 2)

			{

				printf("������۸�����a-b��\n");

				

				scanf("%f-%f", &a, &b);

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for (i = 0; i < size; i++)

				{

					if (f[i].price >= a && f[i].price <= b)

					{

						printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

					}

				}

			}

			else if (option == 3)

			{

				printf("�������Ʒ���ƣ�\n");

			

				scanf("%s", foname);

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

				for (i = 0; i < size; i++)

				{

					if (strcmp(foname, f[i].foodname) == 0)

					{

						printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

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

			printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    �۸�\n");

			for (i = 0; i < size; i++)

			{

				printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, f[i].price);

			}

			printf("������Ҫѡ��ı�ţ�����0������\n");

			

			while (scanf("%d", &id) != EOF && id != 0)

			{

				sum += f[id - 1].price;

			}

			printf("ѡ��Ĳ�Ʒ�ܼ�Ϊ%.2f\n", sum);

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

			printf("������Ҫʹ�õĹ��ܣ�\n��1.����\n��2.��ѯ����\n��0.����\n");

			scanf("%d", &option);

			if (option == 1)

			{

				int id, score;

				printf("�������ź����֣�\n");

				scanf("%d %d", &id, &score);

				id--;

				f[id].scoresum += score;

				f[id].scorenum++;

				save(f, size);

			}

			else if (option == 2)

			{

				printf("���  ����λ��\t\t\t�������\tʳ������    ��Ƭ\t    ����\n");

				for (i = 0; i < size; i++)

				{

					printf("%-6d%-26.24s%-16.14s%-12.10s%-16.16s%.1f\n", (i + 1), f[i].location, f[i].shopname, f[i].foodname, f[i].photo, ((float)f[i].scoresum / (float)f[i].scorenum));

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



int Login()

{

	char user[20], userFile[20];

	char psw[20], pswFile[20];

	FILE* fp;



	system("cls");

	fflush(stdin);

	printf("===����Ա��½===\n");

	printf("�û���: ");

	scanf("%s", user);

	printf("��  ��: ");

	scanf("%s", psw);



	fp = fopen("user.txt", "r");

	while(!feof(fp))

	{

		fscanf(fp, "%s %s", userFile, pswFile);

		if(strcmp(user, userFile)==0 && strcmp(psw, pswFile)==0)

		{

			printf("��½�ɹ�!\n");

			return 1;

		}

	}

	fclose(fp);

	printf("��½ʧ��!\n");

	fflush(stdin);



	return 0;

}