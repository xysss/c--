# include <stdio.h>   
# include <string.h>  
# define LEN sizeof(struct Text)
# define DATA text[i].TM,text[i].A,text[i].B,text[i].C,text[i].D

struct Text
{
	char TM[100];
	char A[60];
	char B[60];
	char C[60];
	char D[60];	
};
struct Text text[50]; 

void PassWord();
void menu();

int main()
{
	menu();
	return 0;
}

void menu()
{
	int sore=0;
	//char ch,a[17],b[17];                          
	FILE *fp; 
	char MYDA[60]={'V'};
	char DA[60]={'A','D','D','D','A','D','D','C','C','D',
	'E','C','E','C','E','E','B','C','A','B',
	'A','A','E','E','A','A','A','E','B','C',
	'E','B','E','A','D','E','D','C','D','C',
	'B','A','C','D','E','E','C','C','E','E'};
	char ZZDA[60];
	//char PF[10];
	//int aa[50];//存储获取到的随机数。
    int f[50] = {0};//存储是否获取到过。
    int m=0,k=0; //计数器。
    fp=fopen("text.txt","rb");
	for(k=0;k<50;k++)
	{
		fread(&text[k],LEN,1,fp);
	}
    srand(time(NULL));//设置随机数种子。
    while(m<5)
    {
        int i = rand()%50; //获取一个0~49的随机数。
        if(f[i]) continue;//该数之前已经获取到过。
      //  aa[i++] = m;//将该数存入数组。
        f[i] = 1;//标记该数已经获取过。
        m++;
        ZZDA[m-1]=DA[i];
    	printf("\n\n\n");
		printf("|==================================★☆★考试系统★☆★==============================|\n\n\n\n");
		printf("   题目%d:%s\n\n   A:%s\n   B:%s\n   C:%s\n   D:%s\n\n\n\n",m,text[i].TM,text[i].A,text[i].B,text[i].C,text[i].D);
		printf("|====================================================================================|\n\n");
		printf("请输入你的选择：");
		scanf("%s",&MYDA[m-1]);
		while(1)
		{
			if(MYDA[m-1]>='a'&&MYDA[m-1]<='d')
			{
				MYDA[m-1]=MYDA[m-1]-32;
				break;
			}
			if(MYDA[m-1]>='A'&&MYDA[m-1]<='D')
			{
				break;
			}
			else
			{
				printf("请正确输入选项：");
				scanf("%s",&MYDA[m-1]); 
			}
		}
		system("cls");
	}
	
/*	if((fp=fopen("text.txt","a+"))==NULL)       //打开指定文件
	{
		printf("失败\n");
		return;
	}
	for(i=49;i<50;i++){
		printf("TM%d:",(i+1));
		scanf("%s",text[i].TM);            
		printf("A:");
		scanf(" %s",text[i].A);
		printf("B:");
		scanf(" %s",text[i].B);
		printf("C:");
		scanf(" %s",text[i].C);
		printf("D:");
		scanf(" %s",text[i].D);
		fwrite(&text[i],LEN,1,fp);               //向指定的磁盘文件写入信息
	}
	fclose(fp);	
*/	
	
	printf("你已全部答完，请输入密码查看分数\n");
	
	PassWord();
	
	printf("密码正确，按任意键查看分数\n\n");
	getch(); 
	for(k=0;k<5;k++)
	{
		//printf("%c %c\n",ZZDA[k],MYDA[k]);
		if(ZZDA[k]==MYDA[k])
		{
			sore=sore+2;
		}
	}
	printf("你的成绩为：%d分\n",sore);
	fclose(fp);	
}

void PassWord(){
	int i=0,flag=0;
	char ch,a[17],b[17];
	char PASSWORD[5]={'m','i','m','a'};  
	while(1)
	{
		while(1)
		{
			a[i]=getch();
			if(a[i]=='\r')
				break;	         
			printf("*"); 
			i++;	
		}
		a[i]='\0';
		printf("\n");
		if(strcmp(PASSWORD,a)!=0)
		{
			printf("密码输入有误，请重新输入:\n");
			i=0;
		}
		else
		{
			break;	
		}
	}
}







