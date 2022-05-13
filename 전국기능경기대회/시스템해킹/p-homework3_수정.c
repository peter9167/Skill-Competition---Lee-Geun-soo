//p-homework3(반복문).c
// 반복문을 사용해서 복
 
#include <stdio.h>
#include <conio.h>

#define ENTER 13

int isPhoneNumber(char *g)
{
	int i;
	int status1[14] = {0}; // 전달하기위한 상태 변수  0으로 초기화 
	int status2[14] = {0}; // 리턴값  0으로 초기화 
	if(g[0] == '0' && g[1] == '1' && g[2] == '0'){ // 전화번호 앞자리 010 비교 
		for(i = 3; i < 13; i++){ // 전화번호 형식 비교 반복 구문 
			if(i >= 4 && i <= 7 || i >= 9 && i <= 12) { // - 기호 빼고 비교하기 위한 구문 
				if(g[i] >= 48 && g[i] <= 57){ // 전화번호 형식 0-9 사이의 값인지 확인 
					status1[i] = 1; 
				} else {
					status1[i] = 0;
				}
			} else {
				if(g[i] == '-'){
					status2[i] = 1;
				} else {
					status2[i] = 0;
				}
			}
		}
	} else {
		return 0;
	}
	for(i = 3; i < 13; i++){
		if(i >= 4 && i <= 7 || i >= 9 && i <= 12) { // - 기호 빼고 비교하기 위한 구문 
			if(status1[i] == 0){ 
				return 0;
			} 
		} 
		else {
			if(status2[i] == 0){
				return 0;
			}
		}
	}
	return 1;
}

int main(void)
{
	char s[14];
	int i;
	
	for(i = 0; i < 13; i++){
		s[i] = _getch();
		if(s[i] == ENTER){
			printf("%s\n", s);
			return 0;
		} 
	}
	if(isPhoneNumber(s) == 0){
		printf("전화번호 형식이 다르다");
	}
}
