/* 01 기본 알고리즘 - 세 정수의 중앙값 구하기 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*------------------ Prototype ------------------*/
int mid1(int a, int b, int c);
int mid2(int a, int b, int c);

/*------------------ Function ------------------*/
int main()
{
	int a, b, c;

	printf("a의 값 입력 : "); scanf("%d", &a);
	printf("b의 값 입력 : "); scanf("%d", &b);
	printf("c의 값 입력 : "); scanf("%d", &c);

	printf("mid1 - 중앙값 : %d\n", mid1(a, b, c));
	printf("mid2 - 중앙값 : %d", mid1(a, b, c));
}

int mid1(int a, int b, int c)
{
	if (a >= b)
		if (b >= c)
			return b;        //  (a>b>c), (a>b=c), (a=b>c), (a=b=c)
		else if (a <= c)
			return a;        //  (c>a>b), (c>a=b), (c=a>b)
		else
			return c;        //  (a>c>b)
	else if (a > c)
		return a;            //  (b>a>c)
	else if (b > c)
		return c;            //  (b>c>a), (b>c=a)
	else
		return b;            //  (c>b>a), (c=b>a)
}

/*------------------ mid1()보다 비효율적 ------------------*/
int mid2(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))    //  (b>=a 및 b<=a)을 거꾸로 뒤집은 조건인
		return a;
	else if ((a > b && c < b) || (a<b && c>b))       //   (a>b 및 a<b)가 있음.
		return b;
	else
		return c;
}
/* 
따라서 첫 번째 if문이 성립하지 않는 경우,
두 번째 else if문에서도 같은 판단을 하므로 이 함수는 mid1()보다 덜 효율적이다.
*/ 