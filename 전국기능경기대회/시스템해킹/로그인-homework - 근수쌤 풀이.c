//login.c
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h> // strcmp(), strcpy()

void memberJoin(char *, char *);  // ȸ������ �Լ� 
void init_ID(char *); //���ڿ� �ʱ�ȭ �Լ� 
void login(char *, char *); //�α��� ó�� �Լ� 

int main()
{
	char memberID[14], memberPW[14]; // ������ ȸ������
	char loginID[14], loginPW[14]; // �α���(ID, PW) ó����  
	int menu;
	
	init_ID( memberID ); //memberID �ʱ�ȭ 
	
	while(1) // ���� ���� 
	{
		puts("====================================");
		printf("1. ȸ������ 2. �α��� 0. ���� : "); // ��� 
		scanf("%d", &menu); // menu1 ������ ���ϴ� â ����  
		switch(menu) // menu1 ���� 
		{
			case 1: // menu1 ���� ���� 1�̸� ���� 
				printf("ȸ�������� �����մϴ�.\n");
				memberJoin(memberID, memberPW); // ���ڿ�(�迭)�� �����ϸ� �ּҰ� ���޵� 
				break;
			case 2: // menu1 ���� ���� 2�� ����
				printf("�α����� �����մϴ�.\n");
				login(memberID, memberPW);
				break;
			case 0: // menu1 ���� ���� 0�̸� ����
				printf("�����մϴ�.\n");
				exit(0);
			default: // menu1 ���� ���� case ������ ���� ������ ����
				printf("�ٽ� �������ּ���.\n");
		}
		puts("---------------------------------\n");
	} // while
	return 0;
}

void init_ID(char *str)
{
	//���޹��� ���ڿ��� �ʱ�ȭ��
	strcpy(str, ""); // ������ ������ ȣ���Ͽ� ���� ���� NULL�� ��ȯ 
}

int isEmptyID(char *ID) // ID Ȯ�� �Լ� 
{
	//ID�� ��� ������ 1, �ƴϸ� 0�� ����
	/* ID ��Ȯ�� ���
		1) ID[0] == '\0' <- �迭 ù ���� NULL�� ���� Ȯ��
		2) strcmp(ID, "") <- strcmp �Լ��� ID ���� �������� Ȯ�� 
		
		strcmp(ID, ""); // ��������� 0 -> return 1
						// ������� ������ -1, 1 -> return 0; 
	*/
	return !(strcmp(ID, "")); // ��������� 1 ����, ������� ������ 0 ���� 
}

void memberEdit_ID(char *memberID)
{
	printf("������ ID �Է� : ");
	scanf("%s", memberID);
	return;
}

void memberEdit_PW(char *memberPW)
{
	printf("������ PW �Է� : ");
	scanf("%s", memberPW);
	return;
}

void memberEdit(char *memberID, char *memberPW)
{
	int Edit_menu;
	while(1) // ���� ���� 
	{
		puts("====================================");
		puts("������ ȸ�������� �����ϼ���. ");
		puts("1. ID ���� 2. PW ���� 0. ���");
		scanf("%d", &Edit_menu); // Edit_menu ������ ���ϴ� â ����  
		switch(Edit_menu) // Edit_menu ���� 
		{
			case 1: // Edit_menu ���� ���� 1�̸� ���� 
				printf("ID�� ������ �ϰڽ��ϴ�.\n");
				memberEdit_ID(memberID);
				return;
			case 2: // Edit_menu ���� ���� 2�� ����
				printf("PW�� ������ �ϰڽ��ϴ�.\n");
				memberEdit_PW(memberPW);
				return;
			case 0: // Edit_menu ���� ���� 0�̸� ����
				printf("�����մϴ�.\n");
				return;
			default: // Edit_menu ���� ���� case ������ ���� ������ ����
				printf("�ٽ� �������ּ���.\n");
		}
		puts("---------------------------------\n");
	} // while
}

/* 
	�α��� ó�� �Լ� 
	ID�� PW�� �Է¹޾Ƽ� ȸ�� ���� (memberID, memberPW)�� �� �� �α��� ó�� 
*/
void login(char *memberID, char *memberPW)
{
	char id[14], pw[14];
	int menu;
	
	if ( isEmptyID( memberID ) ){
		puts("ȸ�������� ���� �������ּ���.\n");
		return;
	}
	
	printf("\nID �Է� : ");
	scanf("%s", id);
	printf("\nPW �Է� : ");
	scanf("%s", pw);
	
	// id�� ���� �ٸ��� 1, -1 / ������ 0 
	// pw�� ���� �ٸ��� 1, -1 / ������ 0 
	if( strcmp (memberID, id) != 0 || strcmp (memberPW, pw) != 0 ){
		puts("ID �Ǵ� ��ȣ�� Ʋ���ϴ�. �ٽ� Ȯ���Ͻð� �α������ּ���."); 
		return; 
	} 
	
	printf("\n %s �� �α����� �����Ͽ����ϴ�. \n", id);
	
	while(1) // ���� ���� 
	{
		puts("====================================");
		printf("1. ȸ������ ���� 2. �α׾ƿ� 0. ���� : "); // ��� 
		scanf("%d", &menu); // menu1 ������ ���ϴ� â ����  
		switch(menu) // menu1 ���� 
		{
			case 1: // menu1 ���� ���� 1�̸� ���� 
				printf("ȸ�������� ������ �ϰڽ��ϴ�.\n");
				memberEdit(memberID, memberPW);
				break;
			case 2: // menu1 ���� ���� 2�� ����
				puts("�α׾ƿ� �մϴ�.\n");
				puts("���θ޴��� ���ư��ϴ�.\n");
				return; // �������� �̵� 
			case 0: // menu1 ���� ���� 0�̸� ����
				printf("�����մϴ�.\n");
				exit(0);
			default: // menu1 ���� ���� case ������ ���� ������ ����
				printf("�ٽ� �������ּ���.\n");
		}
		puts("---------------------------------\n");
	} // while
}

int inputPassword(char *PW)
{
	int cnt=0;
	char checkPW[14];
	
	printf("PW �Է� : ");
	scanf("%s", PW);
	while(cnt < 3){
		printf("PW Ȯ�� : ");
		scanf("%s", checkPW);
		if( strcmp(PW, checkPW) == 0) return 1;
		puts("Ȯ���ϴ� ��ȣ�� �ٽ� �Է��ϼ���.");
		cnt++;
	}
	return 0;
} 

void memberJoin(char *ID, char *PW)
{
	char yesNo[4]; // ȸ������ �� ID Ȯ�ο�
	/*ȸ�������� ó���̶��? ID�� ����ִٸ�?*/
	if( isEmptyID(ID) ) { // ID Ȯ�� �Լ� 
		// ȸ�������� ����
		puts("ȸ������ ����"); // printf�� ���� ��� 
		printf("ID �Է� : "); 
		scanf("%s", ID); // ID �Է� 
		
		while(1){ // ID �Է� Ȯ�� ���� ���� - yes�� no�� �� ���� ���� Ż�� 
			printf("ID�� %s (yes | no) : ", ID);
			scanf("%s", yesNo); // Yes / No �Է�
			if( strcmp(yesNo, "yes") == 0 ){
				break; // �ݺ��� Ż�� 
			}
			else if ( strcmp(yesNo, "no") == 0 ){
				init_ID( ID );
				return; // return �Լ� ���� 
			}
			else{
				puts("�ٽ� �Է��ϼ���.");
			}
		} //while
		
		/* ��ȣ �Է��ϴ� �κ� */
		if( inputPassword(PW) ) { // ��ȣ �Է��ϴ� �Լ� 
			// ���������� ��ȣ �Է�
			puts("���������� ȸ�������� ó���Ǿ����ϴ�."); 
		}
		else {
			// ��ȣ �Է��� 3�� Ʋ�� ���
			init_ID( ID );
			puts("ȸ�������� ��ҵǾ����ϴ�. �ٽ� �õ����ּ���."); 
		}
		
	} //if = ȸ������
	 
	else { // ���� ȸ���� �ִ� ���  
		
	} 
}




