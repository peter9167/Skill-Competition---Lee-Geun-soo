//p-homework3(�ݺ���).c
// �ݺ����� ����ؼ� ��
 
#include <stdio.h>
#include <conio.h>

#define ENTER 13

int isPhoneNumber(char *g)
{
	int i;
	int status1[14] = {0}; // �����ϱ����� ���� ����  0���� �ʱ�ȭ 
	int status2[14] = {0}; // ���ϰ�  0���� �ʱ�ȭ 
	if(g[0] == '0' && g[1] == '1' && g[2] == '0'){ // ��ȭ��ȣ ���ڸ� 010 �� 
		for(i = 3; i < 13; i++){ // ��ȭ��ȣ ���� �� �ݺ� ���� 
			if(i >= 4 && i <= 7 || i >= 9 && i <= 12) { // - ��ȣ ���� ���ϱ� ���� ���� 
				if(g[i] >= 48 && g[i] <= 57){ // ��ȭ��ȣ ���� 0-9 ������ ������ Ȯ�� 
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
		if(i >= 4 && i <= 7 || i >= 9 && i <= 12) { // - ��ȣ ���� ���ϱ� ���� ���� 
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
		printf("��ȭ��ȣ ������ �ٸ���");
	}
}
