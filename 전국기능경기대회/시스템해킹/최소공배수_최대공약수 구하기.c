#include <stdio.h>

int min(int, int, int); // �Է��� ���� 3�� �� �� �ּҰ� ��ȯ 
int gcd(int, int, int); // �Է��� ���� 3�� �� �� �ִ����� ��ȯ 
int lcm(int, int, int); // �Է��� ���� 3�� �� �� �ּҰ���� ��ȯ 

int main() 
{
	int a, b, c; // 3�� ���� �Է� ���� 
   	int g, l; 	 // �ִ�����, �ּҰ���� 
   	printf("������ �Է� : ");
   	scanf("%d %d %d", &a, &b, &c);
   
   	g = gcd(a, b, c); // �ִ� ����� �� ���� 
   	printf("�ִ����� : %d\n", g); 
   
   	l = lcm(a, b, c); // �ּ� ����� �� ���� 
   	printf("�ּҰ���� : %d\n", l); 
   	
   	return 0;
}

int min(int a, int b, int c)
{
   int tmp;
   
   tmp = (a > b) ? b : a;
   tmp = (tmp > c) ? c : tmp;
   return tmp;
}

int mid(int a, int b, int c)
{
   int tmp;

   if (a > b) {
      	if (b > c) {
         	tmp = b;
      	} else {
         	if (a > c) tmp = c;
        	else tmp = a;
      	}
   }
   else {
      	if (a > c) tmp = a;
      	else {
         	if (b > c) tmp = c;
         	else tmp = b;
      	}
   	}

   return tmp;
}

int gcd(int a, int b, int c)
{
   int g = 1, tmp, i = 2;
   tmp = min(a, b, c);
   
   while(i <= tmp){
      	if(a % i == 0 && b % i == 0 && c % i == 0){
         	g *= i;
         	a /= i; b /= i; c /= i;
         	tmp = min(a,b,c);

         	continue;
      	}
      	i++;
   }
   
   return g;
}

int lcm(int a, int b, int c)
{
   	int L, tmp, i;
   
   	tmp = mid(a, b, c);
   	L = gcd(a, b, c); // �ִ����� 
   
   	a /= L;  b /= L;  c /= L;
   
   	i=2;
   	while(i <= tmp){
      
      	if(a % i == 0 && b % i == 0){
         	L *= i;
         	a /= i; b /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      	else if(a % i == 0 && c % i == 0){
         	L *= i;
         	a /= i; c /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      
      	else if(a % i == 0 && c % i == 0){
         	L *= i;
         	a /= i; c /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      	i++;
   	}
   	return L * a * b *c;
}
