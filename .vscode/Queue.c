/*
 * @Author: Justin GE 
 * @Date: 2024-02-02 22:14:12 
 * @Last Modified by: Justin GE
 * @Last Modified time: 2024-02-02 22:46:53
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
    struct Node * pre;
}Node;

Node * initQueue(){
    Node* Q = (Node *)malloc(sizeof(Node));
    Q->data = 0;
    Q->pre = Q;
    Q->next = Q;
    return Q;
}

void enQueue(Node * Q, int data){
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->pre = NULL;
    node->next = NULL;

    node->pre = Q->pre;
    node->next = Q;
    Q->pre->next = node;
    Q->pre= node;
    
    Q->data++;
}
int isEmpty(Node * Q){
    if(Q->data==0||Q->next==Q){
        return 1;
    }else{
        return 0;
    }
}
int deQueue(Node * Q){
    if(isEmpty(Q)){
        return 0;
    }else{
        Node* node = Q->next;
        Q->next = Q->next->next;
        Q->next->pre = Q;
        Q->data--;
        int data = node->data;
        free(node);
        return data;
    }
}

void printQueue(Node * Q){
    Node * node = Q->next;
    while(node!=Q){
        printf("%d->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    Node * Q = initQueue();
    enQueue(Q,1);
    enQueue(Q,2);
    enQueue(Q,3);
    enQueue(Q,4);
    enQueue(Q,5);
    printQueue(Q);
    printf("dequeue=%d\n", deQueue(Q));
    printf("dequeue=%d\n", deQueue(Q));
    printQueue(Q);
    return 0;
}