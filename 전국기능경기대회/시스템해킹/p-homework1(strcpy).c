//p-homework1(�ݺ���).c
// �ݺ����� ����ؼ� ��
 
#include<stdio.h>
#include<string.h> //strcpy() �� ����ϱ� ���� �������. 

int main(void)
{
	char phone1[15] = "010-XXXX-XXXX";
	char phone2[15];
	int i;
	
	strcpy(phone2, phone1);
	
	printf("%s", phone2);
}

 
