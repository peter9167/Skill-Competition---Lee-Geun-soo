//p3.c
//DataType = 자료형 = 데이터의 형태(종류)
//나이, 성적을 처리하는 프로그램 
#include<stdio.h>

int main(void)
{
	int age;
	float score1;
	double score2;
	
	printf("input age: ");
	scanf("%d", &age); // &: 주소 연산 
	
	printf("input 1'st score : ");
	scanf("%f", &score1); //score 메모리 공간과 연결된 곳에 입력된 값 저장 
	
	printf("input 2'nd score': ");
	scanf("%lf", &score2);
	
	printf("%d %f %lf", age, score1, score2); 
	return 0;
}

 
