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
	
	printf("���Ͻô� �ɼ��� �Է����ּ���. \n");
	printf("1. ȸ������\n2. �α���\n0. ����\n�Է� (1 | 2 | 0) ");
	
	scanf("%d", &select);
	if (select == 1){
		if(member_check == 1){
			printf("�̹� ȸ�������� �Ǿ� �ֽ��ϴ�. �α����� �����ϼ���\n\n");
			printf("ID : %s \n", Id);
			printf("PASSWORD : %sAggro\n\n", Pw); 
			//��й�ȣ ���� ���X Aggro ���ڿ� �߰� �� ��� 
			main();
		}
		const char* id = ID();
		if(ID_CHECK() == 0){
			printf("\nȸ�������� ����Ͽ����ϴ�.\n\n");
			main();
		}
		const char* pw = PW();
		if(pw == 0){
			main();
		} 
		strcpy(Id, id);
		strcpy(Pw, pw);
		
		printf("\nȸ�������� �Ϸ�Ǿ����ϴ�.\n\n");
		member_check = 1;
		main();
	}
	else if(select == 2){
		if(member_check == 0){
			printf("ȸ�������� ���� �������ּ���.\n\n");
			main();
		}
		int id_len, pw_len;
		int login_id[20], login_pw[50];
		
		printf("ID �Է� : ");
		for(i = 0; i < 20; i++){
			login_id[i] = getch();
			printf("%c", login_id[i]);
			if(login_id[i] == 13) break;
			if(login_id[i] != Id[i]){
				printf("\nID �Ǵ� ��ȣ�� Ʋ���ϴ�. �ٽ� Ȯ���Ͻð� �α������ּ���.\n");
				main();
			}
		}
		login_id[i] = '\0';
		
		printf("\n");
		printf("PW �Է� : ");
		for(i = 0; i < 50; i++){
			login_pw[i] = getch();
			if(login_pw[i] == 13) break;
			if(login_pw[i] != Id[i]){
				printf("\nID �Ǵ� ��ȣ�� Ʋ���ϴ�. �ٽ� Ȯ���Ͻð� �α������ּ���.\n");
				main();
			}
		}
		login_pw[i] = '\0';
		
		/*for(i = 0; i < 20; i++){
			if(login_id[i] != Id[i]){
				printf("ID �Ǵ� ��ȣ�� Ʋ���ϴ�. �ٽ� Ȯ���Ͻð� �α������ּ���.");
				main();
			}
		}
		for(i = 0; i < 50; i++){
			if(login_pw[i] != Pw[i]){
				printf("ID �Ǵ� ��ȣ�� Ʋ���ϴ�. �ٽ� Ȯ���Ͻð� �α������ּ���.");
				main();
			}
		}*/
		Success_Login();
	}
	else exit(0);
}

void Success_Login(){
	int s;
	
	printf("\n%s �� �α����� �����Ͽ����ϴ�. \n\n", Id);
	printf("1. ȸ������ ����  2. �α׾ƿ�   0. ���� : ");
	scanf("%d", &s);
	if(s == 1){
		//���� ����? 
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
	
	printf("ID �Է� : ");
	for(i = 0; i < 20; i++){
		id[i] = getch();
		printf("%c", id[i]);
		if(id[i] == 13) break;
	}
	id[i] = '\0'; // id[i] �迭 ���� ����
	
	return id; // �Է��� ID ���� return 
}

int ID_CHECK()
{
	char id_check[4];
	int i;
	
	printf("\nȸ�������� �����ϰڽ��ϱ�? (yes | no) ");
	for(i = 0; i < 4; i++) {
		id_check[i] = getch();
		printf("%c", id_check[i]);
		
		if(id_check[i] == 13) break; // ���͸� �����ϸ� ���� 
	}
	//id_check[i] = '\0';
	
	if(id_check[0] == 'y' && id_check[1] == 'e' && id_check[2] == 's') return 1;
	//if(id_check == "yes") return 1;
	else if(id_check[0] == 'n' && id_check[1] == 'o') return 0;
	//else if(id_check == "no") return 0;
	else {
		printf("\n�߸��� ���ڿ��� �����Ͽ����ϴ�.\n");
		ID_CHECK();
	}
}

const char *PW()
{
	static char pw[50];
	int i, len;
	
	printf("\n\nPW �Է� : ");
	for(i = 0; i < 50; i++){
		pw[i] = getch();
		if(pw[i] == 13) break;
	}
	pw[i] = '\0'; // pw[i] �迭 ���� ����
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
	
	printf("\nPW Ȯ�� : ");
	if(chance == 0) {
		printf("\nȸ�������� ��ҵǾ����ϴ�. �ٽ� �õ��� �ּ���.\n");
		chance = 4;
		// main(); //���� �Լ��� ȣ�� 
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
