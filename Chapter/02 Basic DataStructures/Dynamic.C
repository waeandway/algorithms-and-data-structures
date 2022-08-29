/* 02 기본 자료구조 - 동적 메모리 할당 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*------------------ Function ------------------*/
int main()
{
	int *x = NULL;
    x = caaloc(1, sizeof(int));
    if(x==NULL) 
        printf("메모리할당 실패\n");
    else {
        *x = 57;
        printf("*x = %d\n", *x);
        free(X);
    }
    return 0;
}