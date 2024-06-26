#include<stdio.h>
 #include<stdlib.h>
 void main(){
 int n,f,rs[100],m[20],k=0,count=0,pf=0;
 printf("enter the number of pages in rs:");
 scanf("%d",&n);
 
 printf("enter the reference string:");
 for(int i=0;i<n;i++){
     scanf("%d",&rs[i]);
 }
 
 printf("enter the no. of frames:");
 scanf("%d",&f);
 
 for(int i=0;i<n;i++){
     m[i]=-1;
 }
 
 for(int i=0;i<n;i++){
     for(k=0;k<f;k++){
         if(m[k]==rs[i]){
             break;
         }
     }
     if(k==f){
         m[count++]=rs[i];
         pf++;
     }
     for(int j=0;j<f;j++){
         printf("\t%d",m[j]);
     }
     if(k==f){
         printf("\tPF:%d",pf);
     }
     printf("\n");
     if(count==f){
         count=0;
     }
 }
     printf("No. of page fault in FIFO=%d",pf);
 }
 