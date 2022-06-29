#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int stack[MAX];
int top=-1;

void printList(int (*stack)[MAX]);
void push(int (*stack)[MAX],int n);
void pop(int (*stack)[MAX]);
void peek(int (*stack)[MAX]);
void update(int (*stack)[MAX],int n,int loc);

int main(){
    int choice,ele,loc;
    printf("1.Print stack .\n");
    printf("2.Push an element.\n");
    printf("3.Pop an element.\n");
    printf("4.The peek element.\n");
    printf("5.Update element.\n");
    printf("6.EXIT.\n");
    while(1){
        printf("\nchoose an operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printList(&stack);
                    break;
            case 2: printf("\nEnter an element to push : ");
                    scanf("%d",&ele);
                    push(&stack,ele);
                    break;
            case 3: pop(&stack);
                    break;
            case 4: peek(&stack);
                    break;
            case 5: printf("Enter an element : ");
                    scanf("%d",&ele);
                    printf("Enter location : ");
                    scanf("%d",&loc);
                    update(&stack,ele,loc);
                    break;
            case 6: exit(1);
        }
    }

    return 0;
}

void printList(int (*stack)[MAX]){
    if(top==-1){
        printf("stack is empty");
    }else{
        int temp=top;
        while(temp>=0){
            printf("%d ",*stack[temp]);
            temp--;
    }
    }
}

void push(int (*stack)[MAX],int n){
    top++;
    *stack[top]=n;
    printf("Element is pushed.");
}

void pop(int (*stack)[MAX]){
    int temp;
    temp=*stack[top];
    top--;
    printf("The element is poped.\nThe poped element is : %d",temp);
}

void peek(int (*stack)[MAX]){
    int peekNum;
    peekNum=*stack[top-1];
    printf("The peek value of the stack is : %d",peekNum);
}

void update(int (*stack)[MAX],int n,int loc){
    int temp=top;
    for(int i=temp;i<loc;i--){
        *stack[i]=n;
    }
    printf("Element is updated.");
}

