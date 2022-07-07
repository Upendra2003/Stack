#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    if(n==0)
        return 1;
    return (n*fact(n-1));
}
int main(){
    int n,result;
    printf("Enter a number : ");
    scanf("%d",&n);
    result=fact(n);
    printf("The factorial of the number is : %d",result);
    return 0;
}
