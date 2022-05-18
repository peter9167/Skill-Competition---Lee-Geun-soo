#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

const char *ID();
const char *PW();
int ID_CHECK();
int PW_CHECK();
void Success_Login();


int chance = 3;
int member_check = 0;

char Id[20];
char Pw[50];

int main()
{
	int i, select;
	
	printf("원하시는 옵션을 입력해주세요. \n");
	printf("1. 회원가입\n2. 로그인\n0. 종료\n입력 (1 | 2 | 0) ");
	
	scanf("%d", &select);
	if (select == 1){
		if(member_check == 1){
			printf("이미 회원가입이 되어 있습니다. 로그인을 진행하세요\n\n");
			printf("ID : %s \n", Id);
			printf("PASSWORD : %sAggro\n\n", Pw); 
			//비밀번호 원본 출력X Aggro 문자열 추가 후 출력 
			main();
		}
		const char* id = ID();
		if(ID_CHECK() == 0){
			printf("\n회원가입을 취소하였습니다.\n\n");
			main();
		}
		const char* pw = PW();
		if(pw == 0){
			main();
		} 
		strcpy(Id, id);
		strcpy(Pw, pw);
		
		printf("\n회원가입을 완료되었습니다.\n\n");
		member_check = 1;
		main();
	}
	else if(select == 2){
		if(member_check == 0){
			printf("회원가입을 먼저 진행해주세요.\n\n");
			main();
		}
		int id_len, pw_len;
		int login_id[20], login_pw[50];
		
		printf("ID 입력 : ");
		for(i = 0; i < 20; i++){
			login_id[i] = getch();
			printf("%c", login_id[i]);
			if(login_id[i] == 13) break;
			if(login_id[i] != Id[i]){
				printf("\nID 또는 암호가 틀립니다. 다시 확인하시고 로그인해주세요.\n");
				main();
			}
		}
		login_id[i] = '\0';
		
		printf("\n");
		printf("PW 입력 : ");
		for(i = 0; i < 50; i++){
			login_pw[i] = getch();
			if(login_pw[i] == 13) break;
			if(login_pw[i] != Id[i]){
				printf("\nID 또는 암호가 틀립니다. 다시 확인하시고 로그인해주세요.\n");
				main();
			}
		}
		login_pw[i] = '\0';
		
		/*for(i = 0; i < 20; i++){
			if(login_id[i] != Id[i]){
				printf("ID 또는 암호가 틀립니다. 다시 확인하시고 로그인해주세요.");
				main();
			}
		}
		for(i = 0; i < 50; i++){
			if(login_pw[i] != Pw[i]){
				printf("ID 또는 암호가 틀립니다. 다시 확인하시고 로그인해주세요.");
				main();
			}
		}*/
		Success_Login();
	}
	else exit(0);
}

void Success_Login(){
	int s;
	
	printf("\n%s 님 로그인이 성공하였습니다. \n\n", Id);
	printf("1. 회원정보 수정  2. 로그아웃   0. 종료 : ");
	scanf("%d", &s);
	if(s == 1){
		//추후 수정? 
	}
	else if(s == 2){
		main();
	}
	else {
		exit(0);
	}
}


const char *ID()
{
	static char id[20];
	int i;
	
	printf("ID 입력 : ");
	for(i = 0; i < 20; i++){
		id[i] = getch();
		printf("%c", id[i]);
		if(id[i] == 13) break;
	}
	id[i] = '\0'; // id[i] 배열 값을 제외
	
	return id; // 입력한 ID 값을 return 
}

int ID_CHECK()
{
	char id_check[4];
	int i;
	
	printf("\n회원가입을 진행하겠습니까? (yes | no) ");
	for(i = 0; i < 4; i++) {
		id_check[i] = getch();
		printf("%c", id_check[i]);
		
		if(id_check[i] == 13) break; // 엔터를 포함하면 정지 
	}
	//id_check[i] = '\0';
	
	if(id_check[0] == 'y' && id_check[1] == 'e' && id_check[2] == 's') return 1;
	//if(id_check == "yes") return 1;
	else if(id_check[0] == 'n' && id_check[1] == 'o') return 0;
	//else if(id_check == "no") return 0;
	else {
		printf("\n잘못된 문자열을 포함하였습니다.\n");
		ID_CHECK();
	}
}

const char *PW()
{
	static char pw[50];
	int i, len;
	
	printf("\n\nPW 입력 : ");
	for(i = 0; i < 50; i++){
		pw[i] = getch();
		if(pw[i] == 13) break;
	}
	pw[i] = '\0'; // pw[i] 배열 값을 제외
	len = strlen(pw);
	
	if(PW_CHECK(pw, len)){
		return pw;
	} 
	else {
		return 0;
	} 
}

int PW_CHECK(char* pw, int len)
{
	char pw_check[50];
	int i;
	
	printf("\nPW 확인 : ");
	if(chance == 0) {
		printf("\n회원가입이 취소되었습니다. 다시 시도해 주세요.\n");
		chance = 4;
		// main(); //메인 함수를 호출 
		return 0; 
	}
	for(i = 0; i < len; i++){
		pw_check[i] = getch();
		if(pw_check[i] != pw[i]){
			chance--;
			PW_CHECK(pw, len);
		}
	}
	
	return 1;
}
