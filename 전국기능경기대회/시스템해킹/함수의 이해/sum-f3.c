// �μ��� ���� ����ϴ� ���(���� X, ��ȯ0) 
// sum-f3.c 
#include<stdio.h>

int sum();

int main(void)
{
	int hap;
	hap = sum();
	
	printf("%d\n", hap);
	return 0;
 } 
 
 int sum()
 {
 	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
 	return num1+num2;
 }
