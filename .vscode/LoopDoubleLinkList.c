/*
 * @Author: Justin GE 
 * @Date: 2024-02-02 19:24:00 
 * @Last Modified by: Justin GE
 * @Last Modified time: 2024-02-02 19:54:43
 */
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node
{
    int data;
    struct Node * pre;
    struct Node * next;
} Node;

Node * initList(){
    Node * L = malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    L->pre = L;    
    return L;
}

void headInsert(Node *L, int data){
    // 构建新节点
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;

    // 新节点入队
    node->pre = L;
    node->next = L->next;
    L->next->pre = node;
    L->next = node;
    L->data++;

}

void tailInsert(Node *L, int data){
    // 构建新节点
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;

    // 寻找尾节点
    Node * tail = L->pre;
    // 入链表
    node->next = tail->next;
    node->pre = tail;
    tail->next = node;
    // 计数
    L->data++;
}

int delete(Node *L, int data){
    Node * cur = L->next;
    while(cur!=L){
        if(cur->data==data){
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            L->data--;
            return TRUE;
            free(cur);
        }
        cur = cur->next;
    }
    return FALSE;
}

void printList(Node *L){
    Node * cur = L->next;
    while(cur!=L){
        printf("->%d",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main(){
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
    tailInsert(L,10);
    printList(L);
    if(delete(L,3)){
        printf("delete ok!\n");
    }else{
        printf("delete failed\n");
    }
    printList(L);
}
