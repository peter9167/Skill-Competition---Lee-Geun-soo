// �μ��� ���� ����ϴ� ���(���� X, ��ȯX) 
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
