#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int pid,at,bt,pr,ct,tat,wt;
}Process;

int SortProcess(Process p1[],int s)
{
    Process temp;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s-i-1;j++)
        {
            if(p1[j].pr>p1[j+1].pr)
            {
                temp=p1[j];
                p1[j]=p1[j+1];
                p1[j+1]=temp;
            }
        }
    }
}

int CompletionTime(Process p2[],int s)
{
    p2[0].ct=p2[0].bt;
    for(int i=1;i<s;i++)
    {
        p2[i].ct=p2[i-1].ct+p2[i].bt;
    }
}

int TurnAroundTime(Process p2[],int s)
{
    for(int i=0;i<s;i++)
    {
        p2[i].tat=p2[i].ct-p2[i].at;
    }
}

int WaitingTime(Process p2[],int s)
{
    for(int i=0;i<s;i++)
    {
        p2[i].wt=p2[i].tat-p2[i].bt;
    }
}

int AverageTime(Process p2[],int s)
{
    CompletionTime(p2,s);
    TurnAroundTime(p2,s);
    WaitingTime(p2,s);
    
    int total_tat=0,total_wt=0;
    
    for(int i=0;i<s;i++)
    {
        total_tat=total_tat+p2[i].tat;
        total_wt=total_wt+p2[i].wt;
    }
    printf("priority:\n");
    printf("Average tat=%f",(float)total_tat/s);
    printf("Average wt=%f",(float)total_wt/s);
}

void main()
{
    /*Process p1[]={{1,0,4,2},{2,1,3,4},{3,3,2,1},{4,5,1,2},{5,6,4,3}};
    int s=sizeof(p1)/sizeof(p1[0]);*/
    Process p1[100];
    int s;
    printf("enter the no.of processes:\n");
    scanf("%d",&s);
    printf("enter the processes at & bt & pr:\n");
    for(int i=0;i<s;i++){
        scanf("%d %d  %d",&p1[i].at,&p1[i].bt,&p1[i].pr);
        p1[i].pid=i;
    }
    SortProcess(p1,s);
    
    int j=0,current_time=0,total_bt=0;
    
    for(int i=0;i<s;i++)
    {
      total_bt=total_bt+p1[i].bt;  
    }
    
    Process p2[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    while(current_time<=total_bt)
    {
        for(int i=0;i<s;i++)
        {
            if(p1[i].at<=current_time&&p1[i].at!=-1)
            {
                p2[j]=p1[i];
                j++;
                p1[i].at=-1;
                break;
            }
        }
        current_time=current_time+p2[j-1].bt;
    }
    AverageTime(p2,s);
}