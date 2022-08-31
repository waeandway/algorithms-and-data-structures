/* 02 기본 자료구조 - 배열 동적 생성 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*------------------ Function ------------------*/
int main()
{
    int i;
    int *a;
    int na;
    printf("요소의 개수 : "); scanf("%d", &na);
    a = calloc(na, sizeof(int));

    if (a==NULL) 
        printf("메모리 확보 실패.");
    else {
        printf("%d개의 정수 입력\n", na);
        for(i = 0; i < na; i++) {
            printf("%a[%d] : ", i);
            scanf("%d", &a[i]);
        }
    }
    printf("▼ 각 요솟값 ▼\n");
    for(i = 0; i <na; i++) {
        printf("a[%d] = %d\n", i, a[i]);
        free(a);
    }
    return 0;
}
