#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int pid,at,bt,ct,tat,wt;
}process;

int Sort(process p[],int s){
    process temp;
    for(int i=0;i<s;i++){
        for(int j=0;j<s-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

int Comple_tym(process p[],int s){
    p[0].ct=p[0].bt+p[0].at;
    for(int i=0;i<s;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
    }
}

int turnarnd_tym(process p[],int s){
    float a=0;
    for(int i=0;i<s;i++){
        p[i].tat=p[i].ct-p[i].at;
        a=a+p[i].tat;
    }
    return a;
}

int waiting_tym(process p[],int s){
    float b=0;
    for(int i=0;i<s;i++){
        p[i].wt=p[i].tat-p[i].bt;
        b=b+p[i].wt;
    }
    return b;
}

int avgtym(process p[],int s){
    Comple_tym(p,s);
    float a=turnarnd_tym(p,s);
    float b=waiting_tym(p,s);
    
    float avg_tat=a/s;
    float avg_wt=b/s;
    printf("sjf:\n");
    printf("average waiting tym=%f\n",avg_wt);
    printf("average turnarnd_tym=%f\n",avg_tat);
    
}

void main(){
    /*process p1[]={{1,0,4},{2,1,3},{3,3,2},{4,5,1},{5,6,4}};
    int s=sizeof(p1)/sizeof(p1[0]);*/
    process p1[100];
    int s;
    printf("enter the no.of processes:\n");
    scanf("%d",&s);
    printf("enter the processes at & bt:\n");
    for(int i=0;i<s;i++){
        scanf("%d %d",&p1[i].at,&p1[i].bt);
        p1[i].pid=i;
    }
    Sort(p1,s);
    
    int total_bt=0,curr_tym=0,j=0;
    for(int i=0;i<s;i++){
        total_bt+=p1[i].bt;
    }
    
    process p[]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    
    while(curr_tym<=total_bt){
        for(int i=0;i<s;i++){
            if(p1[i].at<=curr_tym && p1[i].at!=-1){
                p[j]=p1[i];
                j++;
                p1[i].at=-1;
                break;
            }
        }
        curr_tym=curr_tym+p[j-1].bt;
    }
    avgtym(p,s);
    
}