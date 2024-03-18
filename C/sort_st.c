//WAP to sort 5 students records on the basis of roll no,name and marks

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student 
{
    int roll;
    char name[20];
    float marks;
}ST;
ST s[5];
void roll_sort(ST *p);
void name_sort(ST *p);
void marks_sort(ST *p);
void scan(ST *);
void print(ST *);

int main()
{
    scan(s);
    roll_sort(s);
    name_sort(s);
    marks_sort(s);
}

void roll_sort(ST *p )
{
    printf("Roll Sorting\n");
    
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
           if(p[j].roll > p[j+1].roll)
           {
               ST temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
           }
        }
    }
    print(s);
}

void name_sort(ST *p )
{
    printf("Name Sorting\n");
    
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
           if(strcmp(p[j].name,p[j+1].name)>0)
           {
               ST temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
           }
        }
    }
    print(s);
}

void marks_sort(ST *p )
{
    printf("Marks Sorting\n");
    
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
           if(p[j].marks > p[j+1].marks)
           {
               ST temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
           }
        }
    }
    print(s);
}

void scan(ST *p)
{
    int i;
    printf("Enter the student details\n");
    for(i=0;i<5;i++)
    scanf("%d %s %f",&p[i].roll,p[i].name,&p[i].marks);
}

void print(ST *p)
{
    int i;
    printf("Display the student details\n");
    for(i=0;i<5;i++)
    printf("%d %s %f\n",p[i].roll,p[i].name,p[i].marks);
}
