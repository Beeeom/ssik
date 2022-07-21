#include<stdio.h>
extern int a;
extern int b;
int main()
{
	
	a++;
	printf("%d\n", a);
	up_print();
	printNum(a);
}
void printNum(int a)
{
	printf("\n%d", a);
}