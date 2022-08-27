/* 01 기본 알고리즘 - 중간값들의 합*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*------------------ Function ------------------*/
int sumof(int a, int b)
{
	int min, max;
	int sum = 0;

	if (a > b) {
		max = a; min = b;
	}
	else {
		max = b; min = a;
	}
	for (int i = min; i <= max; i++)
		sum += i;
	return sum;		

	/*	직접 작성한 코드..
	int sum = a;
	for (int i = 0; i < b - a; i++)
		sum += a+i+1;
	return sum;
    */
}

int main()
{
	int a = 0, b = 0;
	printf("a값 입력 : "); scanf("%d", &a);
	printf("b값 입력 : "); scanf("%d", &b);
	printf("a부터 b까지의 합 : %d\n", sumof(a, b));
}