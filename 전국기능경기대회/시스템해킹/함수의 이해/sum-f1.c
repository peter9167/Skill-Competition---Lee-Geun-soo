// 두수의 합을 계산하는 경우(전달 0, 반환0) 
// sum-f1.c 
#include<stdio.h>

int sum(int, int);

int main(void)
{
	int num1, num2; // main 함수에만 존재하는 변수 
	int hap;
	scanf("%d %d", &num1, &num2);
	
	//hap = sum(num1, num2); // 함수 호출 시 실행 중이던 main 함수 정지 후 호출한 함수 실행 
	//printf("%d + %d = %d\n", num1, num2, hap);
	printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
	return 0;
 } 
 
 int sum(int num1, int num2) // sum 함수에만 존재하는 변수 
 {
 	return num1 + num2;
 }
