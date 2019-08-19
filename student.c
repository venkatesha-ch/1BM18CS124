
#include<stdio.h>
#include<conio.h>

int main()
{
struct
{int mark,age;
char name[20];
}s1;
clrscr();
printf("Enter the name : ");
scanf("%s",s1.name);
printf("Enter the age and marks : ");
scanf("%d%d",&s1.age,&s1.mark);
if((s1.mark >=65 && s1.mark <= 100) && (s1.age>20))
         printf("Student %s qualified for admission",s1.name);
else 
printf("Student %s  NOT qualified for admission",s1.name);
getch();
return 0;
}
