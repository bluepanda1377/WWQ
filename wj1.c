#include<stdio.h>
struct student
{
  int num;
  char name[8];
  int math;
  int engl;
  int chin;
};
void sto()
{
  FILE *fp;  int yn=1;
  struct student stu;      /*stu存放学生的5项数据*/
  if((fp=fopen("文档\\student.odt","w"))==NULL)
    {
      printf("Can`t open file!\n");
      return;
    }
  while (yn==1)
    {
      printf ("请按顺序输入学生的学号，数学成绩，英语成绩，语文成绩，姓名：\n");
      scanf("%d,%d,%d,%d,%s",&stu.num,&stu.math,&stu.engl,&stu.chin,stu.name);
      fwrite(&stu,sizeof(struct student),1,fp);
      printf("若停止输入请按0，若继续输入请按1，然后按回车键。\n");
      scanf("%d",&yn);
    }
  fclose(fp);
  return;
}
void sea()
{
  FILE *fp;  int  bz=0,k=0,xh;
  struct student a;
  if((fp=fopen("文档\\student.odt","r"))==NULL)
    {
      printf("Can`t open file!\n");
      return;
    }
  printf("请输入学生的学号：");
  scanf("%d",&xh);
  fseek(fp,k*sizeof(struct student),SEEK_SET);
  while(!feof(fp))
    {
      fread(&a,sizeof(struct student),1,fp);
      if(xh==a.num)
	{
	  printf("查找成功！学生信息显示如下：\n");
	  printf("\n%d,%s,%d,%d,%d\n",a.num,a.name,a.math,a.engl,a.chin);
	  bz=1;
	  break;
	}
      k++;
      fseek(fp,k*sizeof(struct student),SEEK_SET);
    }
  if(bz==0)   printf("查找不到该学生！\n");
  fclose(fp);
  return;
}
void app()
{FILE *fp;  int  yn=1;
  struct student stu;
  if((fp=fopen("文档\\student.odt","a"))==NULL)
    {
      printf("Can`t open file!");
      return;
    }
  while (yn==1)
    {
      printf("请按顺序输入学生的学号，数学成绩，英语成绩，语文成绩，姓名：\n");
      scanf("%d,%d,%d,%d,%s",&stu.num,&stu.math,&stu.engl,&stu.chin,stu.name);
      fwrite(&stu,sizeof(struct student),1,fp);
      printf("若停止追加输入请按0，若继续追加输入请按1，然后按回车。\n");
      scanf("%d",&yn);
    }
  fclose(fp);
  return;
}
void ave()
{FILE *fp;int t=0,k,m;
  float aver;                     
  struct student stu;
  if((fp=fopen("文档\\student.odt","a"))==NULL)
    {
      printf("Can`t open file!");
      return;
    }
  while(!feof(fp))
    {
      fgetc(fp);
      t++;
    }
  m=t/sizeof(struct student);    
  rewind(fp);
  for(k=0;k<m;k++)
    {
      fread(&stu,sizeof(struct student),1,fp);
      aver=(stu.math+stu.engl+stu.chin)/3.0;
      printf("%d,%s,%d,%d,%d,平均分%f\n",stu.math,stu.name,stu.math,stu.engl,stu.chin,aver);
    }
  fclose(fp);
  return;
}
int main()
{int xz;
  while(1)
    {printf("************学生成绩管理****************\n");
      printf("1,将若干个学生的学号，三门课程的成绩和姓名存储到文件中\n");
      printf("2,根据给定的学号，查找并显示该学生的所有信息\n");
      printf("3,追加若干个学生的信息到文件的末尾\n");
      printf("4,计算并显示每个学生三门课程的平均分\n");
      printf("5,结束程序运行。\n");
      printf("请选择（1,2,3,4,5）:");
      scanf("%d",&xz);
      if (xz==5) break;
      switch(xz)
	{case  1:sto();break;
	 case  2:sea();break;
	 case  3:app();break;
	 case  4:ave();break;
	}
    }
  printf("程序运行结束，再见！");
  return 0;
}
    
	
      
  
