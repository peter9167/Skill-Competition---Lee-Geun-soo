#include <stdio.h>

int main()
{
	char memberID[14], memberPW[14]; // 저장할 회원정보
	char checkPW[14]; // 회원가입 시 비번 확인용
	char yesNo[4]; // 회원가입 시 ID 확인용
	char loginID[14], loginPW[14]; // 로그인(ID, PW) 처리용  
	int menu1, menu2;
	
	while(1) // 무한 루프 
	{
		printf("1. 회원가입 2. 로그인 0. 종류"); // 출력 
	}
	return 0;
}

