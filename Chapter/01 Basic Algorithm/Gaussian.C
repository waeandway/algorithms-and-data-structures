/* 01 기본 알고리즘 - 가우스의 덧셈 

1 ~ n 까지의 덧셈을 할 때 훨씬 효율적.
자세한 내용은 블로그에 정리 :  https://waeandway.tistory.com/entry/알고리즘-가우스의-덧셈
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*------------------ Function ------------------*/
int GaussianSum(int n)
{
	int sum = 0;
	sum = ((1 + n) * (n / 2)) + (n % 2 == 0 ? 0 : (n + 1) / 2);
	return sum;
/*  직접 작성한 코드..
    if (n % 2 == 0)       //  n이 짝수라면
		return (n + 1) * (n / 2);
	else                  //  n이 홀수라면
		return ((n + 1) * (n / 2)) + ((n / 2) + 1);
*/
}

int main()
{
	int n = 0;
	printf("n값 입력 : "); scanf("%d", &n);
	printf("1부터 n까지의 합 : %d\n", GaussianSum(n));
}