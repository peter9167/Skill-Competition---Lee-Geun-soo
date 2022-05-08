//p2.c
//#(해시문자)란 : 먼저 처리하는 동작(전처리 기호) 
#include<stdio.h> // include를 먼저 동작 실행 

// .c 파일은 소스(Source) | .h 파일은 헤더(Header) 

// main 함수의 매개변수
/*
C에서 main 함수는 프로그램의 진입점. 즉 최초로 함수로 구동되어 실행되는 시점. 
함수의 매개변수(파라미터, 전달인자)는 이 함수를 호출할 때 전달해주는 정보를 뜻함. 

int argc : 이것은 메인함수에 전달되는 정보의 갯수를 의미한다.
char *argv[] :  이것은 메인함수에 전달되는 실질적인 정보로, 문자열의 배열을 의미한다. 
첫번째 문자열은 프로그램의 실행경로로 항상 고정이 되어 있다.
*/ 
int main(int argc, char *argv[])
{
	int i;
	
	for(i = 0; i < argc; i++){
		printf("%d : %s\n", i, argv[i]);
	}
	return 0;
}



