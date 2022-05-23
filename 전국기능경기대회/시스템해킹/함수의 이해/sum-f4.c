// 두수의 합을 계산하는 경우(전달 X, 반환X) 
// sum-f4.c 
#include<stdio.h>

void sum(void);

int main(void)
{
	sum();
	
	return 0;
 } 
 
 void sum(void)
 {
 	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
 	return num1+num2;
 }
