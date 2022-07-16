#include <stdio.h>
#include <string.h>

void f(char *pw) { pw[8] = '\0'; }

int main()
{
	char id[0x10]="hello",pw[0xa0];
	
	printf("id : ");
	printf("%s\n", id);
	printf("pw : ");
	scanf("%s", pw); // pw : p@ssw0rd hgasjkhd world
	f(pw);
	//printf("id : %s\n", id);
	//printf("pw : %s\n", pw);
	if( !strcmp(id, "world") && !strcmp(pw, "p@ssw0rd"))
		puts("Welcome to my program");
		
	else puts("Failed~!!");
	
	return 0;
}
