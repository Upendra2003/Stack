#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void printStack(node **head);
void pop(node **head);
void push(node **head,int n);
void createStack(node **head);
void deleteList(node **head);

int main(){
    node *head;
    int choice,ele;
    createStack(&head);
    printf("1.Print stack.\n");
    printf("2.Push an element.\n");
    printf("3.Pop an element.\n");
    printf("4.Delete stack.\n");
    while(1){
        printf("\nEnter an operation :");
        scanf("%d",&choice);
        switch (choice){
        case 1: printStack(&head);
                break;
        case 2: printf("Enter an element to push : ");
                scanf("%d",&ele);
                push(&head,ele);
                break;
        case 3: pop(&head);
                break;
        case 4: deleteList(&head);
                exit(1);
        }
    }
    return 0;
}

void createStack(node **head){
    *head=NULL;
}

void push(node **head,int n){
    node *ptr;
    ptr=malloc(sizeof(node));
    ptr->data=n;
    ptr->next=NULL;
    if(*head==NULL){
        *head=ptr;
    }else{
        ptr->next=*head;
        *head=ptr;
    }
}

void pop(node **head){
    if(*head==NULL){
        printf("No linked stack.");
    }else{
        *head=(*head)->next;
    }
}

void printStack(node **head){
    node *ptr;
    if(*head==NULL)
        printf("Linked stack is empty.");
    else{
        ptr=*head;
        while(ptr!=NULL){
            printf("| %d |\n------  \n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void deleteList(node **head){
    node *ptr;
    while(*head!=NULL){
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}