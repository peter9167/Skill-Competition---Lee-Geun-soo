// 두수의 합을 계산하는 경우(전달 0, 반환x) 
// sum-f2.c 
#include<stdio.h>

void sum(int, int);

int main(void)
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	sum(num1, num2); 
	
	return 0;
 } 
 
 void sum(int num1, int num2)
 {
 	printf("%d + %d = %d\n", num1, num2, num1 + num2);
 }
