//p-homework1(반복문).c
// 반복문을 사용해서 복
 
#include<stdio.h>
#include<string.h> //strcpy() 를 사용하기 위한 헤더파일. 

int main(void)
{
	char phone1[15] = "010-0000-0000";
	char phone2[15];
	int i;
	for(i = 0; i < 14; i++){
		phone2[i] = phone1[i];
	} 
	printf("%s", phone2);
}

 
