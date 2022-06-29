#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top=-1;
int element[MAX];

void displayStack();
void push(int n);
void pop();
void update(int n,int loc);
int peep();

int main(){
    int choose,ele,loc;
    printf("1.Print stack.\n");
    printf("2.Push an element.\n");
    printf("3.Pop an element.\n");
    printf("4.Update an element.\n");
    printf("5.Display top element.\n");
    while(1){
        printf("\nChoose an operation: ");
        scanf("%d",&choose);
        switch(choose){
            case 1: displayStack();
                    break;
            case 2: printf("Enter an element to push: ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 3: pop();
                    break;
            case 4: printf("Enter an element : ");
                    scanf("%d",&ele);
                    printf("Enter the location from top of the stack : ");
                    scanf("%d",&loc);
                    update(ele,loc);
                    break;
            case 5: printf("The topmost element is : %d",peep());
                    break;
        }
    }
    return 0;
}

void displayStack(){
    int temp=top;
    if(temp==-1)
        printf("Stack is empty.\n");
    else{
        while(temp>=0){
            printf("%d ",element[temp]);
            temp--;
        }
    }
}

void push(int n){
    int temp=top;
    top++;
    element[top]=n;
}

void pop(){
    int temp;
    temp=element[top];
    top--;
}

void update(int n,int loc){
    int i,temp;
    element[top-loc+1]=temp;
    element[top-loc+1]=n;
}

int peep(){
    int temp=top;
    return element[temp];
}