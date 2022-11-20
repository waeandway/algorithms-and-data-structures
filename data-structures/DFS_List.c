/*
 그래프 구현 : 인접리스트
 DFS 구현 : 스택
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAX_VERTEX 7
int visited[MAX_VERTEX];
/*------------------ typedef --------------------*/
typedef struct GraphNode    // 연결리스트의 하나의 노드
{
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType    // 그래프에 관련된 변수들
{
    int n; // 정점의 개수
    GraphNode *adj_list[MAX_VERTEX]; // 헤드포인터 배열
} GraphType;
/*------------------ ProtoType -------------------*/
void graph_init(GraphType *g); // 그래프 초기화
void insert_vertex(GraphType *g); // 정점 삽입 연산
void insert_edge(GraphType *g, int u, int v);// 간선 삽입 연산
void dfs_list(GraphType *g, int v); // 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
/*-------------------- main() --------------------*/
int main(void)
{
    GraphType graphExample;
    graph_init(&graphExample); // 그래프 선언 및 초기화
    
    for(int i=0; i<MAX_VERTEX; i++)
        insert_vertex(&graphExample); // 정점 삽입
    
    insert_edge(&graphExample, 0, 1); // 간선 삽입
    insert_edge(&graphExample, 0, 2);
    insert_edge(&graphExample, 2, 3);
    insert_edge(&graphExample, 2, 5);
    insert_edge(&graphExample, 3, 4);
    insert_edge(&graphExample, 5, 6);
    
    dfs_list(&graphExample, 0);
    
    return 0;
}
/*---------------- Functions(Graph) ---------------*/
void graph_init(GraphType *g) // 그래프 초기화
{
    g->n = 0;
    for(int i=0; i<MAX_VERTEX; i++)
        g->adj_list[i] = NULL;
}
/*------------------------------------------------*/
void insert_vertex(GraphType *g) // 정점 삽입 연산
{
    if(g->n == MAX_VERTEX) {
        printf("그래프 정점 개수 : %d\n", g->n);
        printf("\n");
        return;
    }
    g->n++; // 정점의 개수 1씩 증가시키기
}
/*------------------------------------------------*/
void insert_edge(GraphType *g, int u, int v)// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
{
    GraphNode *node, *q;
    if(u > g->n || v > g->n) {
        printf("그래프 정점 번호 오류\n");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode)); // 동적할당 후 node에 주소 반환
    if(g->adj_list[u] == NULL) {
        node->vertex = v;
        node->link = g->adj_list[u];
        g->adj_list[u] = node;
    }
    else {
        node->vertex = v;
        q = g->adj_list[u];
        while(q->link != NULL)
            q = q->link;
        q->link = node;
    }
}
/*----------------  Function (DFS)  ---------------*/
void dfs_list(GraphType *g, int v) // 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
{
    GraphNode* w;
    visited[v] = TRUE; // 정점 v의 방문 표시
    printf("visited[%d]\n", v);
    for(w=g->adj_list[v]; w; w=w->link)
        if(!visited[w->vertex])
            dfs_list(g, w->vertex);
}
