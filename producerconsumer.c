#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int empty=5;
int full=0;
int x=0;

void producer(){
    --empty;
    --mutex;
    x++;
    printf("the producer produce item %d:",x);
    ++mutex;
    ++full;
}

void consumer(){
    --full;
    --mutex;
    printf("the consumer consumes item %d ",x);
    x--;
    ++mutex;
    ++empty;
}
void main(){
    int n;
    printf("press 1.Producer , 2.Consumer & 3.Exit\n");
    for(int i=1;i>0;i++){
        printf("\nenter ur choice:\n");
        scanf("%d",&n);
        switch(n){
            case 1:
            if(mutex==1 && empty!=0){
                producer();
            }
            else{
                printf("buffer is full\n");
            }
            break;
            case 2:
            if(mutex==1 && full!=0){
                consumer();
            }
            else{
                printf("buffer is empty\n");
            }
            break;
            case 3:
            exit(0);
            break;
            
        }
        
    }
}














