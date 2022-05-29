#include<stdio.h>
#include<string.h>

char a[]="\x2a\x36\x78\x78\x7f";
char b[]="\x65\x36\x6b\x64\x73\x73\x7c\x61\x61";

// a : $0rry
// b : b3happy^^

int checkId(char *id)
{
	int i=0;
	if( strlen(id) - strlen(a) != 0 ) return 0;
	while(a[i]){
		if(a[i]-6 == id[i]) i++;
		else return 0;
	}
	if( !a[i] && !id[i]) return 1;
	return 0;
}

int checkPw(char *pw)
{
	int i=0;
	if( strlen(pw) - strlen(b) != 0 ) return 0;
	while(b[i]){
		if(b[i]-3 == pw[i]) i++;
		else return 0;
	}
	if (!b[i] && !pw[i]) return 1;
	return 0;
}

int f(char *id, char *pw)
{
	int k;
	printf("input id : ");
	scanf("%s", id);
	printf("input password : ");
	scanf("%s", pw);
	k = checkId(id);
	k *= checkPw(pw);
	if(k) return 1;
	return 0;
}

int main()
{
	char id[20];
	char pw[20];
	if( f(id, pw) ) printf("\n * Access * \n");
	else printf("\n * Fail *\n");
	return 0;
}
