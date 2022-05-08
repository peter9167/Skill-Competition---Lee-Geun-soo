//p1.c
#include<stdio.h>

int main(int argc, char *argv[])
{
	int s=0, data=-1;
	do{
		scanf("%d", &data);
		if(data>0) s+= data;
	} while(data);
	printf("%d",s);
	return 0;
}

 
