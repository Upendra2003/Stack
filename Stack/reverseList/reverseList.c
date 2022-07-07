#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int main(){
    node *head,*ptr,*temp;
    int n,ele;
    printf("Enter the no of nodes : ");
    scanf("%d",&n);
    printf("Enter element : ");
    scanf("%d",&ele);
    ptr=malloc(sizeof(node));
    ptr->data=ele;
    ptr->link=NULL;
    head=ptr;
    temp=head;
    for(int i=1;i<n;i++){
        printf("Enter element : ");
        scanf("%d",&ele);
        ptr=malloc(sizeof(node));
        ptr->data=ele;
        ptr->link=NULL;
        temp->link=ptr;
        temp=temp->link;
    }
    printf("The Linked List is : \n");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    // Reversing the Linked List
    //ptr=head;
    node *next=NULL;
    node *prev=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    printf("\nThe Reverse of the Linked List is : \n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
}

