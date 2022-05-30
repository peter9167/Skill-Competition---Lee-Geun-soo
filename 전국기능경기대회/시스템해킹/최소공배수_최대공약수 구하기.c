#include <stdio.h>

int min(int, int, int); // 입력한 정수 3개 값 중 최소값 반환 
int gcd(int, int, int); // 입력한 정수 3개 값 중 최대공약수 반환 
int lcm(int, int, int); // 입력한 정수 3개 값 중 최소공배수 반환 

int main() 
{
	int a, b, c; // 3개 정수 입력 변수 
   	int g, l; 	 // 최대공약수, 최소공배수 
   	printf("세정수 입력 : ");
   	scanf("%d %d %d", &a, &b, &c);
   
   	g = gcd(a, b, c); // 최대 공약수 값 리턴 
   	printf("최대공약수 : %d\n", g); 
   
   	l = lcm(a, b, c); // 최소 공배수 값 리턴 
   	printf("최소공배수 : %d\n", l); 
   	
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
   	L = gcd(a, b, c); // 최대공약수 
   
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
