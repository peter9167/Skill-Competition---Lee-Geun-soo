//p-homework1(�ݺ���).c
// �ݺ����� ����ؼ� ��
 
#include<stdio.h>
#include<string.h> //strcpy() �� ����ϱ� ���� �������. 

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

 
