/*
 * @Author: Justin GE 
 * @Date: 2024-02-02 21:15:34 
 * @Last Modified by: Justin GE
 * @Last Modified time: 2024-02-02 21:47:12
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
}Node;


Node * initList(){
    Node * L = malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    L->pre = L;
    return L;
}

void headInsert(Node * L, int data){
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    // 链接
    node->next = L->next;
    node->pre = L;
    L->next->pre = node;
    L->next = node;
    // 加1
    L->data++;
}

void tailInsert(Node *L, int data){
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    // 链接
    node->next = L;
    node->pre = L->pre;
    L->pre->next = node;
    L->pre = node; 
    
    // 加1
    L->data++;
}

int delete(Node *L, int data){
    Node * cur = L->next;
    while (cur!=L){
        if (cur->data == data){
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            L->data--;
            free(cur);
            return TRUE;
        }
        cur = cur->next;
    } 
    return FALSE;
}

void printList(Node *L){
    Node *cur = L->next;
    while(cur!=L){
        printf("->%d",cur->data);
        cur = cur->next;
    }
    printf("NULL \n");

}
int main(){
    printf("hello world\n");
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
    if(delete(L,4)){
        printf("delete success!\n");
    }else{
        printf("delete failed!\n");
    }
    printList(L);
    if(delete(L,4)){
        printf("delete success!\n");
    }else{
        printf("delete failed!\n");
    };
    return 0;
}