//p7.c
//���ڿ� ������ = ��ȭ��ȣ�� �����ϰ�, ��� 
 
#include<stdio.h>
#include<string.h> //strcpy() �� ����ϱ� ���� �������. 

int main(void)
{
	char phone[14];
	//phone = "010-1234-1234"; <- ���� ���� ���X �Ʒ��� ���� ���O 
	strcpy(phone, "010-1234-1234"); // %s �� ���ڿ��� ����ϴµ�, '\0' �� ���� ������ ���. 
	printf("%s", phone);
	
	return 0;
}

 
