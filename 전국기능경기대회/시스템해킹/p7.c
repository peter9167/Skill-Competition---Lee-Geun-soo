//p7.c
//문자열 데이터 = 전화번호를 저장하고, 출력 
 
#include<stdio.h>
#include<string.h> //strcpy() 를 사용하기 위한 헤더파일. 

int main(void)
{
	char phone[14];
	//phone = "010-1234-1234"; <- 본과 같이 사용X 아래와 같이 사용O 
	strcpy(phone, "010-1234-1234"); // %s 는 문자열을 출력하는데, '\0' 를 만날 때까지 출력. 
	printf("%s", phone);
	
	return 0;
}

 
