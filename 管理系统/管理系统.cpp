#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct student
{
	char xuehao[15];
	char xingming[15];
	char xingbie[10];
	float score1,score2,score3,score4,score5;
	float average,total;
	struct student *next;
};

void write(struct student *Head);
struct student* read();
void ListInsert(struct student* L1,struct student* L2);
void Print_St(struct student* p1);
void Login();
void menu();
void exit();
void search_record();
void insert_record();
void modify_record();
void delete_record();
void students_order();
void output_below();
void screening();

int main()
{
	int n;
	char accept;
	//Login();
	menu();
	scanf("%d",&n);
	accept=getchar();
	switch(n)
	{
		case 0:
			exit();
			break;
		case 1:
			search_record();
			break;
		case 2:
			insert_record();
			break;
		case 3:
			modify_record();
			break;
		case 4:
			delete_record();
			break;
		case 5:
			students_order();
			break;
		case 6:
			output_below();
			break;
		case 7:
			screening();
			break;
		default:
			printf("\t\t\t您输入的请求有误,请稍后重试!\n");
			exit(0);
	}
		return 0;
}

void write(struct student *Head)
{
	struct student *p1;
	FILE *fp;
	char judge,accept;
	p1=Head;
	printf("是否需要建立新文件 Y/N:");
	judge=getchar();
	accept=getchar();
	if(judge=='Y' || judge=='y')
	{
		if((fp=fopen("Re_Data.txt","w"))==NULL)
		{
			printf("文件打开错误,请终止程序运行!");
			exit(0);
		}
	}
	else
	{
		if((fp=fopen("Data.txt","w"))==NULL)
		{
			printf("文件打开错误,请终止程序运行!");
			exit(0);
		}
	}
	while(p1!=NULL)
	{
		fprintf(fp,"%s %s %s %.1f %.1f %.1f %.1f %.1f",p1->xuehao,p1->xingming,p1->xingbie,p1->score1,p1->score2,p1->score3,p1->score4,p1->score5);
		if(p1->next!=NULL)
		{
			fprintf(fp,"\n");
		}
		p1=p1->next;
	}
	fclose(fp);
}

struct student* read()
{
	FILE *fp;
	struct student *head,*p1,*p2;
	head=NULL;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	if((fp=fopen("Data.txt","r"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fscanf(fp,"%s%s%s%f%f%f%f%f",p1->xuehao,p1->xingming,p1->xingbie,&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5)==8)
		{
			if(head==NULL)
			{
				head=p1;
			}
			else
			{
				p2->next=p1;
			}
	}
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
	}
	p2->next=NULL;
	fclose(fp);
	return head;
}

void ListInsert(struct student* L1,struct student* L2)
{
	
	struct student* temp;
	struct student* p;
	p=L1;
	temp=(struct student*)malloc(sizeof(struct student));
	while(p->next!=NULL)
	{
		p=p->next;
	}
	
	strcpy(temp->xuehao,L2->xuehao);
	strcpy(temp->xingming,L2->xingming);
	strcpy(temp->xingbie,L2->xingbie);
	temp->score1=L2->score1;
	temp->score2=L2->score2;
	temp->score3=L2->score3;
	temp->score4=L2->score4;
	temp->score5=L2->score5;
	p->next=temp;
	temp->next=NULL;
}

void Print_St(struct student* p1)
{
	p1=p1->next;
	while(p1!=NULL)
	{
		printf("学号:%s,  姓名:%s,  性别:%s,  \n课程一:%.1f,  课程二:%.1f,  课程三:%.1f,  \n课程四:%.1f,  课程五:%.1f\n",
			p1->xuehao,p1->xingming,p1->xingbie,p1->score1,p1->score2,p1->score3,p1->score4,p1->score5);
		p1=p1->next;
	}
}

void Login()
{
	char accept,ID[20],password[20];
	char O_ID[]={"C_Program"},O_password[]={"2016051210"};
	int flag=1;
	printf("请输入您的用户名:");
	scanf("%s",ID);
	accept=getchar();
	printf("请输入您的密码:");
	scanf("%s",password);
	accept=getchar();
	while(1)
	{
		if(strcmp(ID,O_ID)==0 && strcmp(O_password,password)==0)
		{
			printf("您已登录成功,欢迎!");
			break;
		}
		else
		{
			printf("请重新输入您的用户名:");
			scanf("%s",ID);
			accept=getchar();
			printf("请重新输入您的密码:");
			scanf("%s",password);
			accept=getchar();
			flag++;
		}

		if(flag >= 3)
		{
			printf("您输入的次数已超过三次,请稍后重试!");
			exit(0);
		}
	}
}

void menu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|--------------------STUDENT--------------------|\n");
	printf("\t\t|\t 0.exit                                 |\n");
	printf("\t\t|\t 1.search record                        |\n");
	printf("\t\t|\t 2.insert record                        |\n");
	printf("\t\t|\t 3.modify record                        |\n");
	printf("\t\t|\t 4.delete record                        |\n");
	printf("\t\t|\t 5.students order                       |\n");
	printf("\t\t|\t 6.output below                         |\n");
	printf("\t\t|\t 7.screening                            |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-7):");
}

void exit()
{
	system("cls");
	printf("感谢您使用该程序!");
	exit(0);
}

void search_record()
{
	system("cls");
	FILE *fp;
	int choose,flag=0;
	char S_xuehao[15],S_xingming[15];
	struct student stu;
	if((fp=fopen("Data.txt","r"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	printf("请选择按学号/姓名进行查找 1/2:");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("请输入您要查找的学号:");
		scanf("%s",S_xuehao);
		while(!feof(fp))
		{
			if(fscanf(fp,"%s%s%s%f%f%f%f%f",stu.xuehao,stu.xingming,stu.xingbie,&stu.score1,&stu.score2,&stu.score3,&stu.score4,&stu.score5)==8)
			{
				if(strcmp(S_xuehao,stu.xuehao)==0)
				{
					printf("%s  %s  %s  %.1f  %.1f  %.1f  %.1f  %.1f",stu.xuehao,stu.xingming,stu.xingbie,stu.score1,stu.score2,stu.score3,stu.score4,stu.score5);
					flag++;
				}
			}
		}
	}
	else if(choose==2)
	{
		printf("请输入您要查找的姓名:");
		scanf("%s",S_xingming);
		while(!feof(fp))
		{
			if(fscanf(fp,"%s%s%s%f%f%f%f%f",stu.xuehao,stu.xingming,stu.xingbie,&stu.score1,&stu.score2,&stu.score3,&stu.score4,&stu.score5)==8)
			{
				if(strcmp(S_xingming,stu.xingming)==0)
				{
					printf("%s  %s  %s  %.1f  %.1f  %.1f  %.1f  %.1f\n",stu.xuehao,stu.xingming,stu.xingbie,stu.score1,stu.score2,stu.score3,stu.score4,stu.score5);
					flag++;
				}
			}
		}
	}
	if(flag==0)
	{
		printf("未找到您需要查询的学生信息!");
	}
	fclose(fp);
}

void insert_record()
{
	system("cls");
	FILE *fp;
	char judge,accept;
	struct student stu;
	int count=0;
	if((fp=fopen("Data.txt","a+"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(1)
	{
		printf("是否需要继续增加学生信息 Y/N:");
		judge = getchar();
		if(judge=='N' || judge =='n')
		{
			break;
		}
		printf("请输入您要增加的学生的学号:");
		scanf("%s",stu.xuehao);
		accept=getchar();
		printf("请输入您要增加的学生的姓名:");
		scanf("%s",stu.xingming);
		accept=getchar();
		printf("请输入您要增加的学生的性别:");
		scanf("%s",stu.xingbie);
		accept=getchar();
		printf("请输入您要增加的学生的五门课的成绩:");
		scanf("%f %f %f %f %f",&stu.score1,&stu.score2,&stu.score3,&stu.score4,&stu.score5);
		accept=getchar();
		fprintf(fp,"\n");
		fprintf(fp,"%s %s %s %.1f %.1f %.1f %.1f %.1f",stu.xuehao,stu.xingming,stu.xingbie,stu.score1,stu.score2,stu.score3,stu.score4,stu.score5);
		count++;
	}
	if(count==0)
	{
		printf("您未添加任何学生的信息!");
	}
	else
	{
		printf("学生信息增加成功，共增加%d名学生的信息!",count);
	}
	fclose(fp);
}

void modify_record()
{
	system("cls");
	char judge,accept,M_xuehao[15];
	struct student *head,*p1;
	int flag=0;
	head=read();
	while(1)
	{
		p1=head;
		printf("是否需要继续增加学生信息 Y/N:");
		judge = getchar();
		accept=getchar();
		if(judge=='N' || judge =='n')
		{
			break;
		}
		printf("请输入需要修改信息的学生学号:");
		scanf("%s",M_xuehao);
		accept=getchar();
		while(1)
		{
			if(strcmp(p1->xuehao,M_xuehao)==0)
			{
				printf("请输入您要修改信息的学生修改后的学号:");
				scanf("%s",p1->xuehao);
				accept=getchar();
				printf("请输入您要修改信息的学生修改后的姓名:");
				scanf("%s",p1->xingming);
				accept=getchar();
				printf("请输入您要修改信息的学生修改后的性别:");
				scanf("%s",p1->xingbie);
				accept=getchar();
				printf("请输入您要修改信息的学生修改后的五门课的成绩:");
				scanf("%f %f %f %f %f",&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5);
				accept=getchar();
				flag++;
				break;
			}
			p1=p1->next;
			if(p1==NULL)
			{
				printf("您输入的信息有误,请重新开始输入!");
				break;
			}
		}
	}
	write(head);
	if(flag==0)
	{
		printf("您未修改任何学生的信息!");
	}
	else
	{
		printf("学生信息修改成功，共修改%d名学生的信息!",flag);
	}
}

void delete_record()
{
	system("cls");
	char judge,accept,M_xuehao[15];
	struct student *head,*p1,*p2;
	int flag=0;
	head=read();
	while(1)
	{
		p1=head;
		p2=p1->next;
		printf("是否需要继续删除学生信息 Y/N:");
		judge = getchar();
		if(judge=='N' || judge =='n')
		{
			break;
		}
		printf("请输入需要删除信息的学生学号:");
		scanf("%s",M_xuehao);
		accept=getchar();
		while(1)
		{
			if(strcmp(head->xuehao,M_xuehao)==0)
			{
				head=head->next;
				flag++;
				break;
			}
			else if(strcmp(p2->xuehao,M_xuehao)==0)
			{
				p1->next=p2->next;
				flag++;
				break;
			}
			p1=p1->next;
			p2=p1->next;
			if(p2==NULL)
			{
				printf("您输入的信息有误,请重新开始输入!");
				break;
			}
		}
	}
	write(head);
	if(flag==0)
	{
		printf("您未删除任何学生的信息!");
	}
	else
	{
		printf("学生信息删除成功，共删除%d名学生的信息!",flag);
	}
}

void students_order()
{
	system("cls");
	FILE *fp;
	struct student *head,*p1,*p2;
	int i=0,sum=0;
	char T_xuehao[15];
	char T_xingming[15];
	char T_xingbie[10];
	float T_score1,T_score2,T_score3,T_score4,T_score5;
	float T_average,T_total;
	head=NULL;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	if((fp=fopen("Data.txt","r"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fscanf(fp,"%s%s%s%f%f%f%f%f",p1->xuehao,p1->xingming,p1->xingbie,&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5)==8)
		{
			sum++;
			p1->total=p1->score1+p1->score2+p1->score3+p1->score4+p1->score5;
			p1->average=p1->total/5;
			if(head==NULL)
			{
				head=p1;
			}
			else
			{
				p2->next=p1;
			}
	}
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
	}
	p2->next=NULL;
	p1=head;
	for(i=0;i<=sum;i++)
	{
		p1=head;
		while(p1->next!=NULL)
		{
			if(p1->average < p1->next->average)
			{
				strcpy(T_xuehao,p1->xuehao);
				strcpy(T_xingming,p1->xingming);
				strcpy(T_xingbie,p1->xingbie);
				T_score1=p1->score1;
				T_score2=p1->score2;
				T_score3=p1->score3;
				T_score4=p1->score4;
				T_score5=p1->score5;
				T_average=p1->average;
				T_total=p1->total;
				strcpy(p1->xuehao,p1->next->xuehao);
				strcpy(p1->xingming,p1->next->xingming);
				strcpy(p1->xingbie,p1->next->xingbie);
				p1->score1=p1->next->score1;
				p1->score2=p1->next->score2;
				p1->score3=p1->next->score3;
				p1->score4=p1->next->score4;
				p1->score5=p1->next->score5;
				p1->average=p1->next->average;
				p1->total=p1->next->total;
				strcpy(p1->next->xuehao,T_xuehao);
				strcpy(p1->next->xingming,T_xingming);
				strcpy(p1->next->xingbie,T_xingbie);
				p1->next->score1=T_score1;
				p1->next->score2=T_score2;
				p1->next->score3=T_score3;
				p1->next->score4=T_score4;
				p1->next->score5=T_score5;
				p1->next->average=T_average;
				p1->next->total=T_total;
			}
			p1=p1->next;
		}
	}
	p1=head;
	i=1;
	while(p1!=NULL)
	{
		printf("学号:%s,  姓名:%s,  性别:%s,  课程一:%.1f,  课程二:%.1f,  课程三:%.1f,  课程四:%.1f,  课程五:%.1f,  平均分:%.1f,  总分:%.1f,  名次:%d\n",
			p1->xuehao,p1->xingming,p1->xingbie,p1->score1,p1->score2,p1->score3,p1->score4,p1->score5,p1->average,p1->total,i);
		i++;
		p1=p1->next;
	}
	fclose(fp);
}

void output_below()
{
	system("cls");
	FILE *fp;
	struct student *head,*p1,*p2;
	struct student *P_s1,*P_s2,*P_s3,*P_s4,*P_s5;
	int flag=0;
	float A_score1=0,A_score2=0,A_score3=0,A_score4=0,A_score5=0;
	head=NULL;
	p1=p2=(struct student *)malloc(sizeof(struct student));
	P_s5=(struct student *)malloc(sizeof(struct student));
	P_s4=(struct student *)malloc(sizeof(struct student));
	P_s3=(struct student *)malloc(sizeof(struct student));
	P_s2=(struct student *)malloc(sizeof(struct student));
	P_s1=(struct student *)malloc(sizeof(struct student));
	P_s5->next=NULL;
	P_s4->next=NULL;
	P_s3->next=NULL;
	P_s2->next=NULL;
	P_s1->next=NULL;
	if((fp=fopen("Data.txt","r"))==NULL)
	{
		printf("文件打开错误,请终止程序运行!");
		exit(0);
	}
	while(!feof(fp))
	{
		if(fscanf(fp,"%s%s%s%f%f%f%f%f",p1->xuehao,p1->xingming,p1->xingbie,&p1->score1,&p1->score2,&p1->score3,&p1->score4,&p1->score5)==8)
		{
			if(head==NULL)
			{
				head=p1;
			}
			else
			{
				p2->next=p1;
			}
			A_score1=A_score1+p1->score1;
			A_score2=A_score2+p1->score2;
			A_score3=A_score3+p1->score3;
			A_score4=A_score4+p1->score4;
			A_score5=A_score5+p1->score5;
		}
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
	}
	p2->next=NULL;
	A_score1=A_score1 / 5;
	A_score2=A_score2 / 5;
	A_score3=A_score3 / 5;
	A_score4=A_score4 / 5;
	A_score5=A_score5 / 5;
	p1=head;
	while(p1!=NULL)
	{
		if(p1->score1 < A_score1)
		{
			ListInsert(P_s1,p1);
		}
		if(p1->score2 < A_score2)
		{
			ListInsert(P_s2,p1);
		}
		if(p1->score3 < A_score3)
		{
			ListInsert(P_s3,p1);
		}
		if(p1->score4 < A_score4)
		{
			ListInsert(P_s4,p1);
		}
		if(p1->score5 < A_score5)
		{
			ListInsert(P_s5,p1);	
		}
		p1=p1->next;
	}
	if(P_s1->next!=NULL)
	{
		printf("##以下为科目一低于均分的学生的信息##\n");
		Print_St(P_s1);
	}
	if(P_s2->next!=NULL)
	{
		printf("##以下为科目二低于均分的学生的信息##\n");
		Print_St(P_s2);
	}
	if(P_s3->next!=NULL)
	{
		printf("##以下为科目三低于均分的学生的信息##\n");
		Print_St(P_s3);
	}
	if(P_s4->next!=NULL)
	{
		printf("##以下为科目四低于均分的学生的信息##\n");
		Print_St(P_s4);
	}
	if(P_s5->next!=NULL)
	{
		printf("##以下为科目五低于均分的学生的信息##\n");
		Print_St(P_s5);
	}
	fclose(fp);
}

void screening()
{
	system("cls");
	struct student *head,*p1;
	struct student *P1_90,*P2_90,*P3_90,*P4_90,*P5_90,*P1_60,*P2_60,*P3_60,*P4_60,*P5_60;
	int flag=0;
	head=read();
	p1=head;
	P1_90=(struct student *)malloc(sizeof(struct student));
	P2_90=(struct student *)malloc(sizeof(struct student));
	P3_90=(struct student *)malloc(sizeof(struct student));
	P4_90=(struct student *)malloc(sizeof(struct student));
	P5_90=(struct student *)malloc(sizeof(struct student));
	P1_60=(struct student *)malloc(sizeof(struct student));
	P2_60=(struct student *)malloc(sizeof(struct student));
	P3_60=(struct student *)malloc(sizeof(struct student));
	P4_60=(struct student *)malloc(sizeof(struct student));
	P5_60=(struct student *)malloc(sizeof(struct student));
	P1_90->next=NULL;
	P2_90->next=NULL;
	P3_90->next=NULL;
	P4_90->next=NULL;
	P5_90->next=NULL;
	P1_60->next=NULL;
	P2_60->next=NULL;
	P3_60->next=NULL;
	P4_60->next=NULL;
	P5_60->next=NULL;
	while(p1!=NULL)
	{
		if(p1->score1 >= 90)
		{
			ListInsert(P1_90,p1);
		}
		if(p1->score2 >= 90)
		{
			ListInsert(P2_90,p1);
		}
		if(p1->score3 >= 90)
		{
			ListInsert(P3_90,p1);
		}
		if(p1->score4 >= 90)
		{
			ListInsert(P4_90,p1);
		}
		if(p1->score5 >= 90)
		{
			ListInsert(P5_90,p1);
		}
		if(p1->score1 <= 60)
		{
			ListInsert(P1_60,p1);
		}
		if(p1->score2 <= 60)
		{
			ListInsert(P2_60,p1);
		}
		if(p1->score3 <= 60)
		{
			ListInsert(P3_60,p1);
		}
		if(p1->score4 <= 60)
		{
			ListInsert(P4_60,p1);
		}
		if(p1->score5 <= 60)
		{
			ListInsert(P5_60,p1);
		}
		p1=p1->next;
	}
	if(P1_90->next!=NULL)
	{
		printf("##以下为科目一高于九十分的学生的信息##\n");
		Print_St(P1_90);
	}
	if(P2_90->next!=NULL)
	{
		printf("##以下为科目二高于九十分的学生的信息##\n");
		Print_St(P2_90);
	}
	if(P3_90->next!=NULL)
	{
		printf("##以下为科目三高于九十分的学生的信息##\n");
		Print_St(P3_90);
	}
	if(P4_90->next!=NULL)
	{
		printf("##以下为科目四高于九十分的学生的信息##\n");
		Print_St(P4_90);
	}
	if(P5_90->next!=NULL)
	{
		printf("##以下为科目五高于九十分的学生的信息##\n");
		Print_St(P5_90);
	}
	if(P1_60->next!=NULL)
	{
		printf("##以下为科目一低于六十分的学生的信息##\n");
		Print_St(P1_60);
	}
	if(P2_60->next!=NULL)
	{
		printf("##以下为科目二低于六十分的学生的信息##\n");
		Print_St(P2_60);
	}
	if(P3_60->next!=NULL)
	{
		printf("##以下为科目三低于六十分的学生的信息##\n");
		Print_St(P3_60);
	}
	if(P4_60->next!=NULL)
	{
		printf("##以下为科目四低于六十分的学生的信息##\n");
		Print_St(P4_60);
	}
	if(P5_60->next!=NULL)
	{
		printf("##以下为科目五低于六十分的学生的信息##\n");
		Print_St(P5_60);
	}
}
