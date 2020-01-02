#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct stu
{
	int num;
	char name[20];
	char sex[5];
	float score1, score2, score3, score4, score5, sum, aver;
	struct stu *next;
}Student;

void menu()
{
	printf("\n");
	printf("\t\t********************************\n");
	printf("\t\t\tѧ���ɼ�����ϵͳ\n");
	printf("\t\t********************************\n");
	printf("\t\t\t1.ѧ������\n");
	printf("\t\t\t2.ѧ������\n");
	printf("\t\t\t3.ѧ��ɾ��\n");
	printf("\t\t\t4.�޸���Ϣ\n");
	printf("\t\t\t5.ѧ����ѯ\n");
	printf("\t\t\t6.ѧ�����\n");
	printf("\t\t\t7.���ܷ�����\n");
	printf("\t\t\t8.��ѧ������\n");
	printf("\t\t\t9.����ÿ�Ƶ�ƽ���ֲ��������ƽ���ֵ�ѧ��\n");
	printf("\t\t\t10.��ʾ90�����ϵ�ͬѧ��������ͬѧ\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
}

void input() //¼��Ͳ���ѧ���ɼ���Ϣ��д���ļ��У��������⣬�޷�����ѧ����Ϣ����ѭ�����޷�д���ļ��� 
{
	FILE *fp;
	Student *person, *p, *head = NULL, *temp;
	int num, flag, count = 0;
	char c;
	
	if ((fp=fopen("data.txt", "a"))== NULL) //���ļ� 
	{
		printf("ERROR...");
		exit ;
	}
//	p = (Student *)malloc(sizeof(Student));
	p = NULL;
	do //ѭ������ѧ����Ϣ�������� 
	{
//		num = 0;
		person = (Student *)malloc(sizeof(Student)); //���������ռ䣬p��person�ĳ�ʼλ����ͬ 
		count++; //��ӵ�ѧ���ĸ�������ѭ�������Ӷ����� 
		flag = 1; //�ж�ѧ���Ƿ��Ѿ����ڵ���ʱ���� 
		printf("\t\t������Ҫ�����ѧ����ѧ�ţ�\n\t\t");
		scanf("%d", &num);
		while(fscanf(fp, "%d %s %s %f %f %f %f %f %f %f", &head->num, head->name, head->sex, &head->score1, &head->score2,
			&head->score3, &head->score4, &head->score5, &head->sum, &head->aver) == 10) //�ж��ļ����Ƿ��Ѿ����ڸ�ѧ������Ϣ 
		{
			if (temp->num == num)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("��ѧ����Ϣ�Ѵ���...����������...");
			printf("\t\t�Ƿ��������?(Y/N): ");
		    scanf("%*c%c", &c);
		    if(c == 'N' || c == 'n')
				break;
		}
		person->num = num; //��num��ֵ��person->num
		printf("\t\t������ѧ��������:               \n\t\t");
	    scanf("%s", person->name); 
	    printf("\t\t������ѧ�����Ա�:               \n\t\t");
	    scanf("%s", person->sex); 
	    printf("\t\t������ѧ���ĳɼ�1:             \n\t\t"); 
	    scanf("%f", &person->score1); 
	    printf("\t\t������ѧ���ĳɼ�2:               \n\t\t"); 
	    scanf("%f", &person->score2); 
	    printf("\t\t������ѧ���ĳɼ�3:               \n\t\t"); 
	    scanf("%f", &person->score3); 
	    printf("\t\t������ѧ���ĳɼ�4:               \n\t\t"); 
	    scanf("%f", &person->score4); 
	    printf("\t\t������ѧ���ĳɼ�5:               \n\t\t"); 
	    scanf("%f", &person->score5);
	    person->sum = person->score1 + person->score2 + person->score3 + person->score4 + person->score5; //�������ſε��ܳɼ� 
	    person->aver = person->sum / 5; //��ƽ���ɼ� 
	    if (count == 1) //��count=1��ʱ��headָ��person��headҲ�ͳ�Ϊ��һ��ͷ��㣨��ʱperson�ǵ�һ���ڵ㣩 
	    {
	    	head = person;
		}
		else //count!=1ʱ��p->nextָ��person
		{
			p->next = person;
		}
		p = person; //��p��λ���Ƶ�person�����ϼ��������γ���һ������ 
	    printf("\t\t�Ƿ��������?(Y/N): ");
	    scanf("%*c%c", &c);
	}while(c == 'y' || c == 'Y');
	person->next = NULL; //����ѭ��֮��p->next=NULL 
	while (head != NULL) //�������е���������д���ļ��У�����head�����������ͷ 
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
	fclose(fp);
}

Student *readfile() //���ļ��е���Ϣ�������ŵ������У��о����޷����ļ��е����ݿ�浽�����У� 
{
	FILE *fp;
	Student *head, *p1, *p2;
	int count = 0;
	
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
//	head = (Student *)malloc(sizeof(Student));
	if (fgetc(fp)==EOF)//feof
	{
		return NULL;
	}
	else
	{
		fp = fopen("data.txt", "r");
	}
	p1 = (Student *)malloc(sizeof(Student)); //���ٽṹ��ռ�
//	p1 = NULL;
	head = p2 = p1;
	while (fscanf(fp, "%d %s %s %f %f %f %f %f %f %f", &p1->num, p1->name, p1->sex, &p1->score1, &p1->score2,
			&p1->score3, &p1->score4, &p1->score5, &p1->sum, &p1->aver) == 10) //���ļ��ж������ݵ�p1��ʱ��ѭ�� 
	{	
		count++; //������ѧ����Ϣ������ 
		if (count == 1) //������ѧ����Ϣ����Ϊ1ʱ��head�ƶ���p1 
		{
			head = p1;
		}
		else //������ѧ����Ϣ������Ϊ1��ʱ��p2->nextָ��p1 
		{
			p2->next = p1;
		}
		p2 = p1; //��p2ָ���ƶ���p1��λ�� 

//		p2->next = p1;
//		p2 = p1;
		p1 = (Student *)malloc(sizeof(Student)); //Ϊp1���ٽṹ��ռ� 
	}
	p2 ->next = NULL; //���p2->nextָ��NULL
	
	fclose(fp);
	return head; //��������ͷhead
}

void del() //ɾ��ѧ����Ϣ���� 
{
	FILE *fp;
	Student *head, *p1, *p2, *p, *temp; //head�ǵ�һ���ڵ�(��ֵ) 
	int num, count = 0;
	
	head = readfile(); //�����ļ�����
	if ((fp=fopen("data.txt", "w")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
	p = p1 = p2 = head; //��p1��p2�ƶ���head��λ��
	p1 = p1->next; //p2ʼ����p1�ĺ�һλ��p2�Ǹ���ָ��
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d", &num);
	while (p2 != NULL) //��p2��ΪNULL��ʱ��ѭ��
	{
		count++;
		if (count == 1) //��һ���ڵ�ʱ 
		{
			if (p2->num == num) //�����һ���ڵ����Ҫɾ���ģ���ֱ��ɾ�� 
			{
				temp = p2;
				head = p2->next;
				free(temp);
				break;
			}
			else //�������ѭ�� 
			{
				continue;
			}
		}
		else //���ǵ�һ���ڵ�ʱ 
		{
			if (p1->num == num) //����ҵ�Ҫɾ���Ľڵ㣬ֱ��ɾ�� 
			{
				temp = p1;
				p2->next = p1->next;
				free(temp);
				break;
			}
			else //����p1��p2��ǰ�ƶ� 
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}
	while (head != NULL)
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
	fclose(fp);
}

void mod() //�޸�ѧ����Ϣ���� 
{
	FILE *fp;
	char name[20], message[20];
	Student *head, *p;
	int num, snum;
	float grade;
	
	p = head = readfile(); //���ļ��е����ݿ��������
	if ((fp=fopen("data.txt", "w")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
	printf("\t\t��������Ҫ�޸���Ϣ��ѧ����������"); 
	scanf("%s", name);
	while (head != NULL)
	{
		if(strcmp(head->name, name) == 0) //�ҵ���Ҫ�޸���Ϣ��ͬѧ֮����еĲ��� 
		{
			printf("\t\t1.����\n");
			printf("\t\t2.�Ա�\n");
			printf("\t\t3.ѧ��\n");
			printf("\t\t4.score1\n");
			printf("\t\t5.score2\n");
			printf("\t\t6.score3\n");
			printf("\t\t7.score4\n");
			printf("\t\t8.score5\n");
			printf("\t\t������Ҫ�޸õ���Ϣ�����(1-8)��");
			scanf("%d", &num);
			if (num < 1 || num > 8) //��num����ָ�Χ�ڵ�ʱ�򱨴�
			{
				printf("\t\tERROR...");
				break;
			}
			if (num >= 1 && num <= 2) //��numΪ1��2ʱ�����в��� 
			{
				printf("\t\t�������޸ĺ��ѧ���������Ա�");
				scanf("%s", message);
				switch (num)
				{
					case 1: strcpy(head->name, message); break;
					case 2: strcpy(head->sex, message); break;
				}
			}
			if(num == 3)
			{
				printf("\t\t�������޸ĺ��ѧ����ѧ�ţ�");
				scanf("%d", &snum);
				head->num = snum;
			}
			if(num >= 4 && num <= 8)
			{
				printf("\t\t�������޸�֮���ѧ���ĳɼ���");
				scanf("%f", &grade);
				switch(num)
				{
					case 4: head->score1 = grade; break;
					case 5: head->score2 = grade; break;
					case 6: head->score3 = grade; break;
					case 7: head->score4 = grade; break;
					case 8: head->score5 = grade; break;
				}
			}
			printf("�޸ĳɹ�...");
			break;
		}
		else
		{
			printf("�����ڸ�ѧ��...");
			return ;
		}
		head = head->next;
	}
	while (p != NULL)
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", p->num, p->name, p->sex, p->score1, p->score2,
			p->score3, p->score4, p->score5, p->sum, p->aver);
		p = p->next;
	}
	fclose(fp);
}

void query() //��ѯѧ����Ϣ
{
	Student *head;
	int num;
	
	head = readfile();
	printf("��������Ҫ��ѯ��ѧ����ѧ�ţ�");
	scanf("%d", &num);
	if (head == NULL)
	{
		printf("û���ҵ�ѧ���ɼ�...");
		return ;
	}
	while (head != NULL)
	{
		if (head->num == num)
		{
			printf("%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f", head->num, head->name, head->sex, head->score1, head->score2,
				head->score3, head->score4, head->score5, head->sum, head->aver);
			break;
		}
		head = head->next;
	}
}

void allquery() //��ѯ����ѧ����Ϣ
{
	Student *head;
	int num;
	
	head = readfile();
	if (head == NULL)
	{
		printf("û���ҵ�ѧ����Ϣ...");
		return ;
	}
	else
	{
		printf("ѧ����Ϣ���£�\n");
		printf("ѧ��\t����\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5\t�ܳɼ�\tƽ����\n");
		do
		{
			printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
				head->score3, head->score4, head->score5, head->sum, head->aver);
			head = head->next;
		}while(head != NULL);
	}
}

void sortoftotal() //���ܷ������жϽڵ����Ƿ����������������������Ļ���ֱ����������е����ݣ� 
{
	Student *head, *p1, *p2, temp;
	
	head = readfile();
	p1 = head;
	if (head == NULL)
	{
		printf("û��ѧ����Ϣ...");
		 return ;
	}
	if (p1->next == NULL)
	{
		printf("ֻ��һ��ѧ����Ϣ����������...");
		return ;
	}
	while (p1->next != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->sum > p2->sum)
			{
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;
				temp.next = p1->next;
				p1->next = p2->next;
				p2->next = temp.next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("ѧ����Ϣ���£�\n");
	printf("ѧ��\t����\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5\t�ܳɼ�\tƽ����\n");
	while(head != NULL)
	{
		printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
}

void sortofnum() //��ѧ������
{
	Student *head, *p1, *p2, temp;
	
	head = readfile();
	p1 = head;
	if (head == NULL)
	{
		printf("û��ѧ����Ϣ...");
		 return ;
	}
	if (p1->next == NULL)
	{
		printf("ֻ��һ��ѧ����Ϣ����������...");
		return ;
	}
	while (p1->next != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->num > p2->num)
			{
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;
				temp.next = p1->next;
				p1->next = p2->next;
				p2->next = temp.next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("ѧ����Ϣ���£�\n");
	printf("ѧ��\t����\t�Ա�\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5\t�ܳɼ�\tƽ����\n");
	while(head != NULL)
	{
		printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
}

void average() //�������ƽ���ֲ��������ƽ���ֵ�ͬѧ 
{
	Student *head, *p1, *p2, *p3, *p4, *p5;
	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	float aver1 = 0, aver2 = 0, aver3 = 0, aver4 = 0, aver5 = 0;
	int count = 0;
	
	head = p1 = p2 = p3 = p4 = p5 = readfile();
	while (head != NULL) //�����ƽ�����Լ��ܷ� 
	{
		count++;
		sum1 += head->score1;
		sum2 += head->score2;
		sum3 += head->score3;
		sum4 += head->score4;
		sum5 += head->score5;
		head = head->next;
	}
	aver1 = sum1 / count;
	aver2 = sum2 / count;
	aver3 = sum3 / count;
	aver4 = sum4 / count;
	aver5 = sum5 / count;
	
	printf("\t\tscore1�ɼ�����ƽ���ֵ�ͬѧ�У�\n");
	while (p1 != NULL)
	{
		if (p1->score1 < aver1)
		{
			printf("\t\t%d %s %s %f\n", p1->num, p1->name, p1->sex, p1->score1);
		}
		p1 = p1->next;
	}
	printf("\t\tscore2�ɼ�����ƽ���ֵ�ͬѧ�У�\n");
	while (p2 != NULL)
	{
		if (p2->score2 < aver2)
		{
			printf("\t\t%d %s %s %f\n", p2->num, p2->name, p2->sex, p2->score1);
		}
		p2 = p2->next;
	}
	printf("\t\tscore3�ɼ�����ƽ���ֵ�ͬѧ�У�\n");
	while (p3 != NULL)
	{
		if (p3->score3 < aver3)
		{
			printf("\t\t%d %s %s %f\n", p3->num, p3->name, p3->sex, p3->score1);
		}
		p3 = p3->next;
	}
	printf("\t\tscore4�ɼ�����ƽ���ֵ�ͬѧ�У�\n");
	while (p4 != NULL)
	{
		if (p4->score4 < aver4)
		{
			printf("\t\t%d %s %s %f\n", p4->num, p4->name, p4->sex, p4->score1);
		}
		p4 = p4->next;
	}
	printf("\t\tscore5�ɼ�����ƽ���ֵ�ͬѧ�У�\n");
	while (p5 != NULL)
	{
		if (p5->score5 < aver5)
		{
			printf("\t\t%d %s %s %f\n", p5->num, p5->name, p5->sex, p5->score1);
		}
		p5 = p5->next;
	}
}

void qua() //��ʾ���Ƴɼ�����60���Լ�����90�ֵ�ͬѧ�ĳɼ� 
{
	Student *head, *p1, *p2, *p3, *p4, *p5;
	
	head = p1 = p2 = p3 = p4 = p5 = readfile();
	printf("\t\tscore1�ɼ�����60������90��ͬѧ�У�\n");
	while (p1 != NULL)
	{
		if (p1->score1 < 60 || p1->score1 > 90)
		{
			printf("\t\t%d %s %s %f\n", p1->num, p1->name, p1->sex, p1->score1);
		}
		p1 = p1->next;
	}
	printf("\t\tscore2�ɼ�����60������90��ͬѧ�У�\n");
	while (p2 != NULL)
	{
		if (p2->score2 < 60 || p2->score2 > 90)
		{
			printf("\t\t%d %s %s %f\n", p2->num, p2->name, p2->sex, p2->score1);
		}
		p2 = p2->next;
	}
	printf("\t\tscore3�ɼ�����60������90��ͬѧ�У�\n");
	while (p3 != NULL)
	{
		if (p3->score3 < 60 || p3->score3 > 90)
		{
			printf("\t\t%d %s %s %f\n", p3->num, p3->name, p3->sex, p3->score1);
		}
		p3 = p3->next;
	}
	printf("\t\tscore4�ɼ�����60������90��ͬѧ�У�\n");
	while (p4 != NULL)
	{
		if (p4->score4 < 60 || p4->score4 > 90)
		{
			printf("\t\t%d %s %s %f\n", p4->num, p4->name, p4->sex, p4->score1);
		}
		p4 = p4->next;
	}
	printf("\t\tscore5�ɼ�����60������90��ͬѧ�У�\n");
	while (p5 != NULL)
	{
		if (p5->score5 < 60 || p5->score5 > 90)
		{
			printf("\t\t%d %s %s %f\n", p5->num, p5->name, p5->sex, p5->score1);
		}
		p5 = p5->next;
	}
}

int main()
{
	int num;
	
	while (1)
	{
		menu(); 
		printf("\t\t��������ȷ��ָ�0-10����");
		scanf("%d", &num);
		system("cls");
		switch (num)
		{
			case 1:
			case 2: input(); break;
			case 3: del(); break;
			case 4: mod(); break;
			case 5: query(); break;
			case 6: allquery(); break;
			case 7: sortoftotal(); break;
			case 8: sortofnum(); break;
			case 9: average(); break;
			case 10: qua(); break;
			case 0: printf("\t\tллʹ��..."); return 0;
			default: printf("\t\t��Чָ��..."); break;
		}
		printf("�����ɹ�...");
//		sleep(3);
//		system("cls");
	}
	return 0;
}
