#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,s,r[100],curr,temp=0,sum=0;
    printf("Enter the no of requests:\n");
    scanf("%d",&n);
    printf("Enter the requests:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    printf("Enter the currect position:\n");
    scanf("%d",&s);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(r[j]>r[j+1]){
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    curr=r[0];
    
    if(s<r[0]){
        sum=abs(199-s);
    }
    else{
        for(int i=0;i<n;i++){
            if(curr<r[i] && r[i]<s){
                curr=r[i];
            }
        }
        sum=abs(199-s)+curr;
    }
    printf("sum:%d",sum);
}






