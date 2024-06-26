#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,s,r[100];
    printf("enter the number of req:\n");
    scanf("%d",&n);
    
    printf("enter the req:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&r[i]);
        }
        
    printf("enter the current position:\n");
    scanf("%d",&s);
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+abs(s-r[i]);
        s=r[i];
    }
    
    printf("total no of head movement=%d",sum);
    }
