#include<stdio.h>
#include<string.h>

char a[]="\x6c\x30\x67\x31\x6e\x49\x64";
char b[]="\x43\x79\x62\x33\x72\x46\x69\x67\x68\x31\x6e\x47\x21";

// a : l0g1nId
// b : Cyb3rFigh1nG!

int f(char *id, char *pw)
{
	printf("input id : ");
	scanf("%s", id);
	printf("input password : ");
	scanf("%s", pw);
	if(!strcmp(a, id) && !strcmp(b, pw))
	return 1;
	return 0;
}
int main()
{
	char a[20];
	char b[20];
	if( f(a, b) ) printf("\n * Access * \n");
	else printf("\n * Fail *\n");
	return 0;
}
