#include<stdio.h>
#include<string.h>

int isPhoneNumber(char *phoneNum)
{
	int i;
	//형식이 틀린 경우
	//010 시작 안할 때, 길이가 13자리가 아닐 때
	//4=[3], 9=[8]자리가 '-'가 아닐  때 
	//x자리가 숫자가 아닐 때,
	//[4]~[7] . [9]~[12] 
	if( (phoneNum[0] != '0') || (phoneNum[1] != '1') || (phoneNum[2] != '0') )
		return 0;
		
	if( strlen(phoneNum) != 13 ) // 문자열 길이가 13이 아닐 때 return 0 
		return 0;
		
	for(i=4; i<7; i++)
		if(phoneNum[i] < '0' || phoneNum[i] > '9')
			return 0;
			
	for(i=9; i<12; i++)
		if(phoneNum[i] < '0' || phoneNum[i] > '9')
			return 0;
			
	return 1;
 } 

int main()
{
	char phoneNum[20];
	int i;
	for(i=0; i<20; i++){
		phoneNum[i] = getch();
		printf("%c", phoneNum[i]);
		if(phoneNum[i] == 13) break;
	}
	phoneNum[i] = '\0'; // = 0; // = NULL;
	printf("\n%s", phoneNum);
	
	if( isPhoneNumber(phoneNum) )
		printf("\n전화번호 형식이 맞습니다.\n");
	else
		printf("\n전화번호 형식이 다릅니다.\n");
}
