#include<stdio.h>
#include<string.h>

int isPhoneNumber(char *phoneNum)
{
	int i;
	//������ Ʋ�� ���
	//010 ���� ���� ��, ���̰� 13�ڸ��� �ƴ� ��
	//4=[3], 9=[8]�ڸ��� '-'�� �ƴ�  �� 
	//x�ڸ��� ���ڰ� �ƴ� ��,
	//[4]~[7] . [9]~[12] 
	if( (phoneNum[0] != '0') || (phoneNum[1] != '1') || (phoneNum[2] != '0') )
		return 0;
		
	if( strlen(phoneNum) != 13 ) // ���ڿ� ���̰� 13�� �ƴ� �� return 0 
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
		printf("\n��ȭ��ȣ ������ �½��ϴ�.\n");
	else
		printf("\n��ȭ��ȣ ������ �ٸ��ϴ�.\n");
}
