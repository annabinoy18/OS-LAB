#include<stdio.h>
#include<stdlib.h>

void firstfit(int b[100],int m,int p[100],int n){
    int i=0,j=0;
    int a[100];
    int b_copy[100];
    
    for(i=0;i<m;i++){
        b_copy[i]=b[i];
    }
    
    for(i=0;i<n;i++){
        a[i]=-1;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(b_copy[j]>=p[i]){
                a[i]=j;
                b_copy[j]=b_copy[j]-p[i];
                break;
            }
        }
    }
    
    printf("\nfirstfit:\n");
    printf("process\t allocation\n");
    for(i=0;i<n;i++){
        if(a[i]!=-1){
        printf("p%d allocated to %d\n",i,a[i]);
        }
        else{
            printf("p%d is not allocated\n",i);
        }
    }
    
}

void worstfit(int b[100],int m,int p[100],int n){
    int i=0,j=0;
    int a[100];
    int b_copy[100];
    
    for(i=0;i<m;i++){
        b_copy[i]=b[i];
    }
    
    for(i=0;i<n;i++){
        a[i]=-1;
    }
    
    for(i=0;i<n;i++){
        int worst=-1;
        for(j=0;j<m;j++){
            if(b_copy[j]>=p[i]){
                if(worst==-1||b_copy[worst]<b_copy[j]){
                    worst=j;
                }
            }
        }
        if(worst!=-1){
                a[i]=worst;
                b_copy[worst]-=p[i];
        }
    }
    
    printf("\nworstfit:\n");
    printf("process\t allocation\n");
    for(i=0;i<n;i++){
        if(a[i]!=-1){
        printf("p%d allocated to %d\n",i,a[i]);
        }
        else{
            printf("p%d is not allocated\n",i);
        }
    }
    
}

void bestfit(int b[100],int m,int p[100],int n){
    int i=0,j=0;
    int a[100];
    int b_copy[100];
    
    for(i=0;i<m;i++){
        b_copy[i]=b[i];
    }
    
    for(i=0;i<n;i++){
        a[i]=-1;
    }
    
    for(i=0;i<n;i++){
        int best=-1;
        for(j=0;j<m;j++){
            if(b_copy[j]>=p[i]){
                if(best==-1||b_copy[best]>b_copy[j]){
                   best=j;
                }
            }
        }
        if(best!=-1){
                a[i]=best;
                b_copy[best]-=p[i];
        }
    }
    
    printf("\nbstfit:\n");
    printf("process\t allocation\n");
    for(i=0;i<n;i++){
        if(a[i]!=-1){
        printf("p%d allocated to %d\n",i,a[i]);
        }
        else{
            printf("p%d is not allocated\n",i);
        }
    }
    
}


void main(){
    int b[100],m,p[100],n;
    printf("enter the number of process:\n");
    scanf("%d",&n);
    printf("enter the process size:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    
    printf("enter the number of blocks:\n");
    scanf("%d",&m);
    printf("enter the block size:\n");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    
    firstfit(b,m,p,n);
    worstfit(b,m,p,n);
    bestfit(b,m,p,n);
}