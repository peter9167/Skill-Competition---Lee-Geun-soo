//p3.c
//DataType = �ڷ��� = �������� ����(����)
//����, ������ ó���ϴ� ���α׷� 
#include<stdio.h>

int main(void)
{
	int age;
	float score1;
	double score2;
	
	printf("input age: ");
	scanf("%d", &age); // &: �ּ� ���� 
	
	printf("input 1'st score : ");
	scanf("%f", &score1); //score �޸� ������ ����� ���� �Էµ� �� ���� 
	
	printf("input 2'nd score': ");
	scanf("%lf", &score2);
	
	printf("%d %f %lf", age, score1, score2); 
	return 0;
}

 
