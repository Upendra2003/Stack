#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct stack{
    int top;
    int element[MAX];
}stack;

void enqueue(stack *s,int n);

int main(){
    int ele,choice;
    stack *s;
    createStack(&s);
    printf("1.Print Queue.\n");
    printf("2.Enqueue an element.\n");
    while(1){
        printf("Enter an operation.");
        scanf("%d",&choice);
        switch(choice){
            case 1: printStack(&s);
                    break;
            case 2: printf("Enter an element: ");
                    scanf("%d",&ele);
                    enqueue(&s,ele);
                    break;
        }
    }
    return 0;
}

void createStack(stack *s){
    s->top=-1;
}

void enqueue(stack *s,int n){
    
}