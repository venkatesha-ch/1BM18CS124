
#include<stdio.h>
#include<conio.h>

int main()
{
int mark,age;
char name[20];
clrscr();
printf("Enter the name : ");
scanf("%s",name);
printf("Enter the age and marks : ");
scanf("%d%d",&age,&mark);
if((mark >=65 && mark <= 100) && (age>20))

         printf("Student %s qualified for admission",name);
      
else 
printf("Student %s  NOT qualified for admission",name);
getch();
return 0;
}
