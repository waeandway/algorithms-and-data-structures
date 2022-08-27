/* 01 기본 알고리즘 - N까지의 합  */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*------------------ Prototype ------------------*/
Nsum_while(int n);
Nsum_for(int n);

/*------------------ Globar Var -----------------*/
int i = 1, sum = 0, n = 0;

/*------------------ Function ------------------*/
int main()
{
	printf("n값 입력 : ");  scanf("%d", &n);
	printf("\n");

	printf("1부터 n까지의 합 : %d (by Nsum_while())\n", Nsum_while(n));
	printf("i = %d이고, n+1 = %d와 %s\n", i, n + 1, ( i == n + 1 ) ? "같다." : "같지 않다.");

	printf("\n");
	sum = 0;

	printf("1부터 n까지의 합 : %d (by Nsum_for())\n", Nsum_for(n));
	printf("i = %d이고, n+1 = %d와 %s\n", i, n + 1, (i == n + 1) ? "같다." : "같지 않다.");
}

Nsum_while(int n)
{
	while (i <= n) {
		sum += i;
		i++;
	 }
	return sum;
}

Nsum_for(int n)
{
	for (i = 1; i <= n; i++)
		sum += i;
	return sum;
}