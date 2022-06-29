#include <stdio.h>
#include <stdlib.h>

int stack[20];
int top=-1;

void push(int n);
int pop();
int perform(int x,int y,int z);

int main(){
    int expression[9]= {3,4,5,'*',4,'-',8,'/','+'};
    int i;
    i=0;
    while(i<=9){
        if(expression[i]=='*' || expression[i]=='/' || expression[i]=='+' || expression[i]=='-'){
            int x,y,result;
            x=pop();
            y=pop();
            result=perform(x,y,expression[i]);
            push(result);
        }else{
            push(expression[i]);
        }
        i++;
    }
    printf("\nThe resultant of the postfix is : %d\n",stack[top]);
    return 0;
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

int perform(int x,int y,int z){
    switch(z){
        case '*': return y*x;
                  break;
        case '/': return y/x;
                  break;
        case '+': return y+x;
                  break;
        case '-': return y-x;
                  break;
    }
}
