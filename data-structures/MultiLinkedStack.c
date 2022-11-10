#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

// 초기화
void init(LinkedStackType *s, int i)
{
    s[i].top = NULL;
}

// 공백 상태 검출
int is_empty(LinkedStackType *s, int i)
{
    return (s[i].top == NULL);
}

// 포화 상태 검출
int is_full(LinkedStackType *s) 
{
    return 0;
}

// PUSH
void push(LinkedStackType *s, element item, int i)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s[i].top;
    s[i]top = tem;
    free(temp);
}

void print_stack(LinkedStackType *s, int i)
{
    for(StackNode *p = s[i]top;p!=NULL;p=p->link)
        printf("%d(%d)->", p->data, p->link);
    printf("NULL\n");
}

// 삭제 함수
element pop(LinkedStackType *s, int i)
{
    if (is_empty(s,i)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode *temp = s[i].top;
        int data = temp->data;
        s[i].top = s[i].top->link;
        free(temp);
        return data;
    }
}
/*-------------------------- main --------------------------*/
int main(void)
{
    LinkedStackType s[3];
    for(int i=0;i<3;i++) 
        init(&s, i);
    push(&s, 1, i); print_stack(&s, i);
    push(&s, 2, i); print_stack(&s, i);
    push(&s, 3, i); print_stack(&s, i);
    for(int i=0;i<3;i++) 
        pop(&s, i); print_stack(&s, i);
    return 0;
}