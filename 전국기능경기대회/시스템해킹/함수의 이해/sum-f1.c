// �μ��� ���� ����ϴ� ���(���� 0, ��ȯ0) 
// sum-f1.c 
#include<stdio.h>

int sum(int, int);

int main(void)
{
	int num1, num2; // main �Լ����� �����ϴ� ���� 
	int hap;
	scanf("%d %d", &num1, &num2);
	
	//hap = sum(num1, num2); // �Լ� ȣ�� �� ���� ���̴� main �Լ� ���� �� ȣ���� �Լ� ���� 
	//printf("%d + %d = %d\n", num1, num2, hap);
	printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
	return 0;
 } 
 
 int sum(int num1, int num2) // sum �Լ����� �����ϴ� ���� 
 {
 	return num1 + num2;
 }
