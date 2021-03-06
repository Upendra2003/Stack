#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 11

int stack[MAX];
int top=-1;

void infixToPostfix(char infix[MAX],char postfix[MAX]);
int isOperator(int n);
int precedence(int n);
void push(int n);
int pop();

int main(){
    char infix[MAX];
    printf("\nEnter Infix expression : ");
	gets(infix);
    char postfix[MAX];
    infixToPostfix(infix,postfix);
    return 0;
}

void infixToPostfix(char infix[],char postfix[]){
    int i=0,j=0,x;
    int temp=infix[i];
    push('(');
    infix[MAX]=')';
    while(temp!='\0'){
        if(temp=='('){
            push(temp);
        }
        else if(isalpha(temp) || isdigit(temp)){
            postfix[j]=temp;
            j++;
            
        }else if(isOperator(temp)){
            x=pop();
            if(isOperator(temp) && precedence(x)>=precedence(temp)){
                postfix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(temp);
            
        }else if(temp==')'){
            x=pop();
            while(x!='('){
                postfix[j]=x;
                j++;
                x=pop();
            }
        }
        i++;
        temp=infix[i];
    }
    printf("The postfix expression is : ");
    for(int i=0;i<MAX-2;i++){
        printf("%c",postfix[i]);
    }
}

int isOperator(int n){
    if( n=='*' || n=='*' || n=='/' || n=='+' || n=='-'){
        return 1;
    }else{
        return 0;
    }
}

int precedence(int n){
    if(n=='/' || n=='*'){
        return 2;
    }else if(n=='+' || n=='-'){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    top++;
    stack[top]=n;
}

int pop(){
    int temp=stack[top];
    top--;
    return temp;
}