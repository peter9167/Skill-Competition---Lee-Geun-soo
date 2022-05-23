#include<stdio.h>

int main()
{
	int data, n;
	scanf("%d", &data);
	n = 1;
	while(n<=data){
		if(data % n == 0) printf("%d ", n);
		n++;
	}
	return 0;
}
