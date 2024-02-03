#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct String{
    char *data;
    int len;
}String;

String *initString(){
    String * s = (String *) malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}
void stringAssign(String *s, char *data){
    if(s->data){
        free(s->data);
    }
    s->len = strlen(data);
    s->data = (char *)malloc((s->len + 1) * sizeof(char));
    strcpy(s->data,data);
}
void forceMatch(String *master, String *sub){
    int i=0,j=0;
    while (i<master->len && j<sub->len)
    {
        if(master->data[i] == sub->data[j]){
            i++;
            j++;
        }else{
            i = i-j+1;
            j = 0;
        }
    }
    if(j==sub->len){
        printf("force match success.\n");
    }else{
        printf("force match fail.\n");
    }
    
}
void printString(String *s){
    for (int i = 0; i < s->len; i++)
    {
        printf(i==0?"%c":"->%c",s->data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    String *s = initString();
    String *s1 = initString();
    stringAssign(s,"hello");
    stringAssign(s1,"he1");
    printString(s);
    printString(s1);
    forceMatch(s,s1);
}