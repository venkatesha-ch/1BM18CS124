#include<stdio.h>
#include<conio.h>

int main()
{
	int mark_grd(int);	
	struct student
	{
		char usn[20];
		char name[20];
		int mark[20];
		int crd[20];
	}s1;
	int i;
	float tot=0,tot_crd=0,cgpa=0;
	clrscr();
	printf("Enter the name of student : \n");
	scanf("%s",s1.name);
	printf("Enter the USN : \n");
	scanf("%s",s1.usn);
	printf("Enter the marks of 5 subjects : \n");
	for(i=0;i<5;i++)
	scanf("%d",&s1.mark[i]);
	printf("Enter the credits of 5 subjects : \n");
	for(i=0;i<5;i++)
	scanf("%d",&s1.crd[i]);
	printf("NAME	: %s\n",s1.name);
	printf("USN	: %s\n",s1.usn);
	for(i=0;i<5;i++)
	printf("MARKS IN SUBJECT %d : %d\n",i+1,s1.mark[i]);
	for(i=0;i<5;i++)
	{ tot=tot+(mark_grd(s1.mark[i])*s1.crd[i]);
	  tot_crd=tot_crd+s1.crd[i];
	}
	cgpa=tot/tot_crd;
	printf("CGPA	: %.1f",cgpa);
	getch();
	return 0;
}
int mark_grd(int mark)
{
	if(mark>=90&&mark<=100)
	return 10;
	else if(mark<90&&mark>=75)
	return 9;
	else if(mark<75&&mark>=60)
	return 8;
	else if(mark<60&&mark>=50)
	return 7;
	else if(mark<50&&mark>=45)
	return 5;
	else if(mark<45&&mark>=40)
	return 4;
	else if(mark<40)
	return 0;
}


