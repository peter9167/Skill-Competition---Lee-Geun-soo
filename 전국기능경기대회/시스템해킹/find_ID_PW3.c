#include<stdio.h>
#include<string.h>

void f(char *pw){ pw[8] = '\0'; }

int main()
{
	char id[10]="hello", pw[10];
	
	printf("id : ");
	printf("%s\n", id);
	printf("pw : ");
	scanf("%s", pw);
	f(pw);
	if ( !strcmp(id, "world") && !strcmp(pw, "p@ssw0rd"))
		puts("Welcome to my program");
	
	else puts("Failed~!!");
	
	return 0;
}

