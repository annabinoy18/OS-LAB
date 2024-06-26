#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pid,at,bt,ct,rt,tat,wt;
}process;

int TurnAroundTime(process p[],int s){
    float a=0;
    for(int i=0;i<s;i++){
        p[i].tat=p[i].ct-p[i].at;
        a+=p[i].tat;
    }
    return a;
}

int WaitingTime(process p[],int s){
    float b=0;
    for(int i=0;i<s;i++){
        p[i].wt=p[i].tat-p[i].bt;
        b+=p[i].wt;
    }
    return b;
}

int AverageTime(process p[],int s){
    float a=TurnAroundTime(p,s);
    float b=WaitingTime(p,s);
    
    float avg_tat=a/s;
    float avg_wt=b/s;
    printf("round robin:\n");
    printf("avg_tat=%f",avg_tat);
    printf("avg_wt=%f",avg_wt);
}
void main(){
   // printf("hi1");
    /*process p1[]={{1,0,8},{2,1,4},{3,2,9},{4,3,5}};
    int s=sizeof(p1)/sizeof(p1[0]);
    int quantum=4;*/
     process p1[100];
    int s,quantum;
    printf("enter the no.of processes:\n");
    scanf("%d",&s);
    printf("enter the processes at & bt:\n");
    for(int i=0;i<s;i++){
        scanf("%d %d",&p1[i].at,&p1[i].bt);
        p1[i].pid=i;
    }
    printf("enter the quantum:");
    scanf("%d",&quantum);
  
    
    int j=0,current_time=0,total_bt=0;
    for(int i=0;i<s;i++){
        total_bt+=p1[i].bt;
        p1[i].rt=p1[i].bt;
    }
    
    process p2[]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    
    while(current_time<total_bt){
        for(int i=0;i<s;i++){
            if(p1[i].at<=current_time && p1[i].rt!=0){
                if(p1[i].rt<=quantum){
                    p2[j]=p1[i];
                    current_time+=p1[i].rt;
                    p2[j].ct=current_time;
                    j++;
                    p1[i].rt=0;
                }
                else{
                    p1[i].rt=p1[i].rt-quantum;
                    current_time+=quantum;
                }
            }
        }
    }
    //printf("hi 2");
    AverageTime(p2,s);
}
