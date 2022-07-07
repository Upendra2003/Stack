#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct node{
    int data;
    struct node *next;
}node;

int top=-1;
int stack[MAX];

void createList(node **head);
void addEle(node **head,int n);
void printList(node **head);
void reverseList(node **head,node **reversedList);
void push(int n);
int pop();

int main(){
    int n,choice;
    node *head,*reveredList;
    createList(&head);
    createList(&reveredList);
    printf("1.Print Linked List.\n");
    printf("2.Insert an element.\n");
    printf("3.Reverse the linked list.\n");
    while(1){
        printf("\nEnter operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printList(&head);
                    break;
            case 2: printf("Enter element to add : ");
                    scanf("%d",&n);
                    addEle(&head,n);
                    break;
            case 3: reverseList(&head,&reveredList);
                    break;
            case 4: exit(1);
                    break;
        }
    }
    return 0;
}

void createList(node **head){
    *head=NULL;
}

void addEle(node **head,int n){
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

void printList(node **head){
    node *ptr;
    if(*head==NULL)
        printf("Linked List is empty.");
    else{
        ptr=*head;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void reverseList(node **head,node **reversedList){
    int store,x;
    node *ptr=*head;
    while(ptr!=NULL){
        store=(ptr)->data;
        push(store);
        ptr=(ptr)->next;
    }
    printf("The reverse of the linked list is : \n");
    for(int i=0;i<MAX;i++){
        x=pop();
        printf("%d ",x);
    }
}

void push(int n){
    top++;
    stack[top]=n;
}

int pop(){
    int temp;
    temp=stack[top];
    top--;
    return temp;
}
