 /*
 단순&비효율 자료구조 -> 선택 정렬 (selection sort)
*/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) {int tmp=x; x=y; y=tmp;}
#define MAX_SIZE 5
/*------------ Prototype -------------*/
int list[MAX_SIZE];
void print_list(int list[]);
void selection_sort(int list[], int n); // 선택 정렬
/*-------------- main() --------------*/
int main(void)
{
    for(int i=0; i<MAX_SIZE;i++) {      // 난수 생성 및 출력
        list[i] = rand() % MAX_SIZE;    // 난수 발생 범위 0-n
    }
    printf("--- 정렬 전 list[] ---\n");
    print_list(list);
    
    selection_sort(list, MAX_SIZE);     // 선택 정렬
    printf("--- 정렬 후 list[] ---\n");
    print_list(list);
}
/*------------------------------------*/
void print_list(int list[])
{
    for(int i=0; i<MAX_SIZE; i++)
        printf("list[%d]=%d ", i, list[i]);
    printf("\n");
    printf("\n");
}
/*------------------------------------*/
void selection_sort(int list[], int n)
{
    int least;
    for(int i=0; i<n-1; i++) {
        least = i;
        for(int j=i+1; j<n; j++) // 최소값 탐색
            if(list[j]<list[least]) least = j;
        SWAP(list[i], list[least]);
    }
}
