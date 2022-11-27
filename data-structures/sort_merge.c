/*
 복잡&효율 자료구조 -> 합병 정렬 (merge sort)
 */
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 6
/*------------ Prototype -------------*/
int list[MAX_SIZE];
int sorted[MAX_SIZE];
void print_list(int list[]);
void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);
/*-------------- main() --------------*/
int main(void)
{
    for(int i=0; i<MAX_SIZE;i++) {      // 난수 생성 및 출력
        list[i] = rand() % MAX_SIZE;    // 난수 발생 범위 0-n
    }
    printf("--- 정렬 전 list[] ---\n");
    print_list(list);
    
    merge_sort(list, list[0], list[MAX_SIZE-1]);
    merge(list, list[0], MAX_SIZE/2, list[MAX_SIZE-1]);
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
void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i=left; j=mid+1; k=left;
    
    while(i<=mid&&j<=right) {
        if(list[i]<=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid)
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    for(l=left; l<=right; l++)
        list[l] = sorted[l];
}
/*------------------------------------*/
void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right) {
        mid = (left+right)/2;        // 리스트의 균등 분할
        merge_sort(list, left, mid); // 부분 리스트 정렬
    }
}