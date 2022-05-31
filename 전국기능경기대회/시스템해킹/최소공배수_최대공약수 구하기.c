#include <stdio.h>

int min(int, int, int); // �Է��� ���� 3�� �� �� �ּҰ� ��ȯ 
int gcd(int, int, int); // �Է��� ���� 3�� �� �� �ִ����� ��ȯ 
int lcm(int, int, int); // �Է��� ���� 3�� �� �� �ּҰ���� ��ȯ 

int main() 
{
	int a, b, c; // 3�� ���� �Է� ���� 
   	int g, l; 	 // �ִ�����, �ּҰ���� 
   	printf("������ �Է� : ");
   	scanf("%d %d %d", &a, &b, &c); // 3�� ���� �Է� 
   
   	g = gcd(a, b, c); // �ִ� ����� �� ���� 
   	printf("�ִ����� : %d\n", g); 
   
   	l = lcm(a, b, c); // �ּ� ����� �� ���� 
   	printf("�ּҰ���� : %d\n", l); 
   	
   	return 0;
}

int min(int a, int b, int c) // �ּҰ� ���� �Լ� 
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

int gcd(int a, int b, int c) // �ִ����� ��ȯ 
{
   int g = 1; // �ִ����� ���� 
   int tmp, i = 2;
   tmp = min(a, b, c); // �ּҰ� ���� 
   
   while(i <= tmp){ 
   		// ����� ã�� 
      	if(a % i == 0 && b % i == 0 && c % i == 0){ // a,b,c ������ ���������� ��
		  	// i�� ����� 
         	g *= i; // i�� g�� ���Ͽ� ���� - g = g * i
         	a /= i; b /= i; c /= i; // a,b,c ������ i������ ���� 
         	tmp = min(a,b,c); // �ּҰ� ���� 

         	continue; //while ������ �ö� 
      	}
      	//������� ���� �� 
      	i++; // i +1 ���� 
   }
   
   return g; // i���� ��� ���� ���� ������ ����(����) 
}

int lcm(int a, int b, int c) // �ּҰ���� ��ȯ 
{
   	int l; // �ּҰ���� ���� 
	int tmp, i;
   
   	tmp = mid(a, b, c);
   	l = gcd(a, b, c); // �ִ����� 
   
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
