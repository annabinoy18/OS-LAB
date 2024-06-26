#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pid,at,bt,ct,tat,wt;
}process;

int Srtprocess(process p[],int s){
    process temp;
    for(int i=0;i<s;i++){
        for(int j=0;j<s-i-1;j++){
            if (p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

int Completion_time(process p[],int s){
    p[0].ct=p[0].bt;
    for(int i=1;i<s;i++){
        p[i].ct=p[i-1].ct+p[i].bt;
    }
}

int Turnarndtym(process p[],int s){
    float a=0;
    for(int i=0;i<s;i++){
        p[i].tat=p[i].ct-p[i].at;
        //printf("%d\n",p[i].tat);
        a=a+p[i].tat;
    }
    return a;
}


int Waiting_time(process p[],int s){
    float b=0;
    for(int i=0;i<s;i++){
        p[i].wt=p[i].tat-p[i].bt;
        b=b+p[i].wt;
    }
    return b;
}

int avg_tym(process p[],int s){
    Completion_time(p,s);
    float a=Turnarndtym(p,s);
    float b=Waiting_time(p,s);
    printf("%f\n",a);
    printf("%f\n",b);
    
    float avgtat=a/s;
    float avgwt=b/s;
    printf("fcfs:\n");
    printf("average Turnarndtym=%f\n",avgtat);
    printf("average waitingtym=%f\n",avgwt);
}
void main(){
   /* process p1[]={{1,0,8},{2,1,1},{3,2,3},{4,3,2},{5,4,6}};
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
    //printf("%d",s);
    Srtprocess(p1,s);
    avg_tym(p1,s);
}