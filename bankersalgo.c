#include<stdio.h>
int main(){
    int i,j,k,y,m,n, alloc[20][20], max[20][20], avail[50], ind=0;
    printf("\nEnter no. of processes: ");
    scanf("%d",&n);
    printf("\nEnter no. of resources: ");
    scanf("%d",&m);
    
    printf("Enter the allocation matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("Enter the maximum matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    
    printf("Enter the available matrix: \n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);
        
    int finish[n], safesequence[n], work[m], need[n][m];
    
    for(i=0;i<m;i++)
        work[i]=avail[i];
        
    for(i=0;i<n;i++)
        finish[i]=0;
        
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }   
    printf("NEED matrix is: \n");
    for(i=0;i<n;i++){
        printf("\n");
            for(j=0;j<m;j++){
                printf("%d ",need[i][j]);
            }
    }
    
   /* for(i=0;i<m;i++)
        work[i]=avail[i];
        
    for(i=0;i<n;i++)
        finish[i]=0;*/
        
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag =0;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        flag = 1;
                        break;
                    }    
                    
                }
                if(flag==0){
                    safesequence[ind++]=i;
                    for(y=0;y<m;y++)
                        work[y] += alloc[i][y];
                    finish[i]=1;    
                }
            }
        }
    }    
    printf("\nFollowing is the safesequence:\n");
    for(i=0;i<n;i++){
        printf("P%d ",safesequence[i]);
    }
    
}
