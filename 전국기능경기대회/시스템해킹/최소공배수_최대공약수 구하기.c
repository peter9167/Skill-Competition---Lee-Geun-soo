#include <stdio.h>

int min(int, int, int); // 입력한 정수 3개 값 중 최소값 반환 
int gcd(int, int, int); // 입력한 정수 3개 값 중 최대공약수 반환 
int lcm(int, int, int); // 입력한 정수 3개 값 중 최소공배수 반환 

int main() 
{
	int a, b, c; // 3개 정수 입력 변수 
   	int g, l; 	 // 최대공약수, 최소공배수 
   	printf("세정수 입력 : ");
   	scanf("%d %d %d", &a, &b, &c); // 3개 정수 입력 
   
   	g = gcd(a, b, c); // 최대 공약수 값 리턴 
   	printf("최대공약수 : %d\n", g); 
   
   	l = lcm(a, b, c); // 최소 공배수 값 리턴 
   	printf("최소공배수 : %d\n", l); 
   	
   	return 0;
}

int min(int a, int b, int c) // 최소값 리턴 함수 
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

int gcd(int a, int b, int c) // 최대공약수 반환 
{
   int g = 1; // 최대공약수 저장 
   int tmp, i = 2;
   tmp = min(a, b, c); // 최소값 저장 
   
   while(i <= tmp){ 
   		// 공약수 찾기 
      	if(a % i == 0 && b % i == 0 && c % i == 0){ // a,b,c 정수가 나눠떨어질 때
		  	// i가 공약수 
         	g *= i; // i와 g를 곱하여 저장 - g = g * i
         	a /= i; b /= i; c /= i; // a,b,c 정수를 i값으로 나눔 
         	tmp = min(a,b,c); // 최소값 저장 

         	continue; //while 문으로 올라감 
      	}
      	//공약수가 없을 때 
      	i++; // i +1 증가 
   }
   
   return g; // i값을 모두 곱한 값을 저장후 리턴(전달) 
}

int lcm(int a, int b, int c) // 최소공배수 반환 
{
   	int l; // 최소공배수 저장 
	int tmp, i;
   
   	tmp = mid(a, b, c);
   	l = gcd(a, b, c); // 최대공약수 
   
   	a /= l;  b /= l;  c /= l;
   
   	i=2;
   	while(i <= tmp){
      
      	if(a % i == 0 && b % i == 0){
         	l *= i;
         	a /= i; b /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      	else if(a % i == 0 && c % i == 0){
         	l *= i;
         	a /= i; c /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      
      	else if(a % i == 0 && c % i == 0){
         	l *= i;
         	a /= i; c /= i;
         	tmp = mid(a, b, c);
         	continue;
      	}
      	i++;
   	}
   	return l * a * b *c;
}
