//login.c
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h> // strcmp(), strcpy()

void memberJoin(char *, char *);  // 회원가입 함수 
void init_ID(char *); //문자열 초기화 함수 
void login(char *, char *); //로그인 처리 함수 

int main()
{
	char memberID[14], memberPW[14]; // 저장할 회원정보
	char loginID[14], loginPW[14]; // 로그인(ID, PW) 처리용  
	int menu;
	
	init_ID( memberID ); //memberID 초기화 
	
	while(1) // 무한 루프 
	{
		puts("====================================");
		printf("1. 회원가입 2. 로그인 0. 종류 : "); // 출력 
		scanf("%d", &menu); // menu1 변수로 원하는 창 선택  
		switch(menu) // menu1 변수 
		{
			case 1: // menu1 변수 값이 1이면 실행 
				printf("회원가입을 시작합니다.\n");
				memberJoin(memberID, memberPW); // 문자열(배열)을 전달하면 주소가 전달됨 
				break;
			case 2: // menu1 변수 값이 2면 실행
				printf("로그인을 시작합니다.\n");
				login(memberID, memberPW);
				break;
			case 0: // menu1 변수 값이 0이면 실행
				printf("종료합니다.\n");
				exit(0);
			default: // menu1 변수 값이 case 구문과 맞지 않으면 실행
				printf("다시 선택해주세요.\n");
		}
		puts("---------------------------------\n");
	} // while
	return 0;
}

void init_ID(char *str)
{
	//전달받은 문자열을 초기화함
	strcpy(str, ""); // 포인터 변수로 호출하여 문자 값을 NULL로 변환 
}

int isEmptyID(char *ID) // ID 확인 함수 
{
	//ID가 비어 있으며 1, 아니면 0을 리턴
	/* ID 값확인 방법
		1) ID[0] == '\0' <- 배열 첫 값이 NULL인 것을 확인
		2) strcmp(ID, "") <- strcmp 함수로 ID 값이 공백인지 확인 
		
		strcmp(ID, ""); // 비어있으면 0 -> return 1
						// 비어있지 않으면 -1, 1 -> return 0; 
	*/
	return !(strcmp(ID, "")); // 비어있으면 1 리턴, 비어있지 않으면 0 리턴 
}

void memberEdit_ID(char *memberID)
{
	printf("변경할 ID 입력 : ");
	scanf("%s", memberID);
	return;
}

void memberEdit_PW(char *memberPW)
{
	printf("변경할 PW 입력 : ");
	scanf("%s", memberPW);
	return;
}

void memberEdit(char *memberID, char *memberPW)
{
	int Edit_menu;
	while(1) // 무한 루프 
	{
		puts("====================================");
		puts("수정할 회원정보를 선택하세요. ");
		puts("1. ID 수정 2. PW 수정 0. 취소");
		scanf("%d", &Edit_menu); // Edit_menu 변수로 원하는 창 선택  
		switch(Edit_menu) // Edit_menu 변수 
		{
			case 1: // Edit_menu 변수 값이 1이면 실행 
				printf("ID를 수정을 하겠습니다.\n");
				memberEdit_ID(memberID);
				return;
			case 2: // Edit_menu 변수 값이 2면 실행
				printf("PW를 수정을 하겠습니다.\n");
				memberEdit_PW(memberPW);
				return;
			case 0: // Edit_menu 변수 값이 0이면 실행
				printf("종료합니다.\n");
				return;
			default: // Edit_menu 변수 값이 case 구문과 맞지 않으면 실행
				printf("다시 선택해주세요.\n");
		}
		puts("---------------------------------\n");
	} // while
}

/* 
	로그인 처리 함수 
	ID와 PW를 입력받아서 회원 정보 (memberID, memberPW)와 비교 후 로그인 처리 
*/
void login(char *memberID, char *memberPW)
{
	char id[14], pw[14];
	int menu;
	
	if ( isEmptyID( memberID ) ){
		puts("회원가입을 먼저 진행해주세요.\n");
		return;
	}
	
	printf("\nID 입력 : ");
	scanf("%s", id);
	printf("\nPW 입력 : ");
	scanf("%s", pw);
	
	// id가 서로 다르면 1, -1 / 같으면 0 
	// pw가 서로 다르면 1, -1 / 같으면 0 
	if( strcmp (memberID, id) != 0 || strcmp (memberPW, pw) != 0 ){
		puts("ID 또는 암호가 틀립니다. 다시 확인하시고 로그인해주세요."); 
		return; 
	} 
	
	printf("\n %s 님 로그인이 성공하였습니다. \n", id);
	
	while(1) // 무한 루프 
	{
		puts("====================================");
		printf("1. 회원정보 수정 2. 로그아웃 0. 종류 : "); // 출력 
		scanf("%d", &menu); // menu1 변수로 원하는 창 선택  
		switch(menu) // menu1 변수 
		{
			case 1: // menu1 변수 값이 1이면 실행 
				printf("회원정보를 수정을 하겠습니다.\n");
				memberEdit(memberID, memberPW);
				break;
			case 2: // menu1 변수 값이 2면 실행
				puts("로그아웃 합니다.\n");
				puts("메인메뉴로 돌아갑니다.\n");
				return; // 메인으로 이동 
			case 0: // menu1 변수 값이 0이면 실행
				printf("종료합니다.\n");
				exit(0);
			default: // menu1 변수 값이 case 구문과 맞지 않으면 실행
				printf("다시 선택해주세요.\n");
		}
		puts("---------------------------------\n");
	} // while
}

int inputPassword(char *PW)
{
	int cnt=0;
	char checkPW[14];
	
	printf("PW 입력 : ");
	scanf("%s", PW);
	while(cnt < 3){
		printf("PW 확인 : ");
		scanf("%s", checkPW);
		if( strcmp(PW, checkPW) == 0) return 1;
		puts("확인하는 암호를 다시 입력하세요.");
		cnt++;
	}
	return 0;
} 

void memberJoin(char *ID, char *PW)
{
	char yesNo[4]; // 회원가입 시 ID 확인용
	/*회원가입이 처음이라면? ID가 비어있다면?*/
	if( isEmptyID(ID) ) { // ID 확인 함수 
		// 회원가입이 시작
		puts("회원가입 시작"); // printf와 같은 기능 
		printf("ID 입력 : "); 
		scanf("%s", ID); // ID 입력 
		
		while(1){ // ID 입력 확인 루프 구문 - yes나 no일 때 루프 구문 탈출 
			printf("ID는 %s (yes | no) : ", ID);
			scanf("%s", yesNo); // Yes / No 입력
			if( strcmp(yesNo, "yes") == 0 ){
				break; // 반복문 탈출 
			}
			else if ( strcmp(yesNo, "no") == 0 ){
				init_ID( ID );
				return; // return 함수 종료 
			}
			else{
				puts("다시 입력하세요.");
			}
		} //while
		
		/* 암호 입력하는 부분 */
		if( inputPassword(PW) ) { // 암호 입력하는 함수 
			// 정상적으로 암호 입력
			puts("정상적으로 회원가입이 처리되었습니다."); 
		}
		else {
			// 암호 입력이 3번 틀린 경우
			init_ID( ID );
			puts("회원가입이 취소되었습니다. 다시 시도해주세요."); 
		}
		
	} //if = 회원가입
	 
	else { // 기존 회원이 있는 경우  
		
	} 
}




