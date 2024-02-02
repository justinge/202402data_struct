// 单链表
/*
1.初始化
2.头插
3.尾插
4.删除
5.遍历
*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    /* data */
    int data;
    struct Node * next;
} Node;

Node * initList(){
    Node * L = malloc(sizeof(Node));
    // 头指引节点， data 用于计数使用
    L->data = 0;
    L->next = NULL;
    return L;
}

void headInsert(Node *L, int data){
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    node->next = L->next;
    L->next = node;
    L->data ++;
}

void tailInsert(Node *L, int data){
    // 寻找尾节点
    Node * pre = L;
    Node * cur = L->next;
    while(cur){
        pre = cur;
        cur = cur->next;
    }
    // 构建新节点
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    pre->next =  node;
    L->data++;
}

int delete(Node *L, int data){
    Node * pre = L;
    Node * cur = L->next;
    while (cur){
        if (cur->data==data){
            L->data--;
            pre->next = cur->next;
            // !!! 必须要free
            free(cur);
            return TRUE;
        }
        pre = cur;
        cur = cur->next;
    }
    return FALSE;
}
void printList(Node *L){
    Node * cur = L->next;
    printf("Len=%d\n",L->data);
    while(cur){
        printf("->%d",cur->data);
        cur = cur->next;
    }
    printf("NULL \n");
}

int main(){
    printf("Hello World \n");
    Node * L = initList();
    headInsert(L,1);
    headInsert(L,2);
    headInsert(L,3);
    headInsert(L,4);
    headInsert(L,5);
    printList(L);
    tailInsert(L,6);
    tailInsert(L,7);
    tailInsert(L,8);
    tailInsert(L,9);
    printList(L);
    if(delete(L,5)){
        printf("delete ok \n");
    }else{
        printf("delete failed \n");
    }
    printList(L);

    if(delete(L,8)){
        printf("delete ok \n");
    }else{
        printf("delete failed \n");
    }
    printList(L);
    return 0;
}