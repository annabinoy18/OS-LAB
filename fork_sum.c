#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int calcsum(int start,int end){
    int sum=0;
    for(int i=start;i<=end;i++){
    sum=sum+i;
    }
    return sum;
}

int main(){
    int n=10;
    pid_t p1,p2;
    
    p1=fork();
    
     
        if(p1<0){
            printf("fork failed");
            exit(EXIT_FAILURE);
        }
        else if(p1==0){
            int sum1;
            sum1=calcsum(0,n/2);
            printf("sum1=%d",sum1);
            exit(sum1);
        }
        else if(p1>0){
            p2=fork();
            
            if(p2<0){
            printf("fork failed");
            exit(EXIT_FAILURE);
            }
            else if(p2==0){
            int sum2;
            sum2=calcsum((n/2)+1,n);
            printf("sum2=%d",sum2);
            exit(sum2);
            }
            else if(p2>0){
                int status1,status2;
                waitpid(p1,&status1,0);
                waitpid(p2,&status2,0);
                
                int totalsum=WEXITSTATUS(status1)+WEXITSTATUS(status2);
                printf("total sum=%d",totalsum);
            }
        }
        
    return 0;
}
