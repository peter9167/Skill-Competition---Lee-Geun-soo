//p5.c
//문자열 데이터에 이해
 
#include<stdio.h>

int main(void)
{
	printf("%c %d\n", ' ', ' '); //출력 :  32 <- 공백 출력. 공백 정수로 변환했을 때 32(ASCII)
	printf("%c %d\n", '1', '1'); //출력 : 1 49 <- 1 출력. 1 정수로 변환했을 때 49(ASCII)
	printf("%c %d\n", 'A', 'A'); //출력 : A 65 <- A 출력. A 정수로 변환했을 때 65(ASCII)
	printf("%c %d\n", 'a', 'a'); //출력 : a 97 <- a 출력. a 정수로 변환했을 때 97(ASCII)
	
	// 문제 : 다음과 같이 출력하시오. 
	// 출력 : A1a1AaAa111 
	printf("%c%c%c%c%c%c%c%c%c%c%c",65,49,97,49,65,97,65,97,49,49,49);
	return 0;
}

 
