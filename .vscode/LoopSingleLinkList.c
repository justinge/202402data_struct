#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node
{
    /* data */
    int data;
    struct Node * next;
}Node;

Node * initList(){
    Node * L = malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    return L;
}

void headInsert(Node *L, int data){
    // 构建新节点
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    // 执行插入
    node->next = L->next;
    L->next = node;
    L->data++;
}

void tailInsert(Node *L, int data){
    // 构建新节点
    Node * node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    // 寻找尾指针
    Node * cur = L->next;
    Node * pre = L;
    while(cur!=L){
        pre = cur;
        cur = cur->next;
    }
    // 新节点插入到尾部
    node->next = L;
    pre->next = node;
    L->data++;
}

int delete(Node * L, int data){
    Node * pre = L;
    Node * cur = L->next;
    while(cur!=L){
        if(cur->data==data){
            pre->next = cur->next;
            L->data--;
            free(cur);
            return TRUE;
        }
        pre = cur;
        cur=cur->next;
    }
    return FALSE;
}

void printList(Node *L){
    Node * cur = L->next;
    while(cur!=L){
        printf("->%d",cur->data);
        cur = cur->next;
    }
    printf("->NULL \n");
}

int main(){
    printf("hello world!\n");
    Node *L = initList();
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
    if(delete(L,4)){
        printf("delete success!\n");
    }else{
        printf("delete failed \n");
    }

    printList(L);

    if(delete(L,4)){
        printf("delete success!\n");
    }else{
        printf("delete failed \n");
    }
    printList(L);
}