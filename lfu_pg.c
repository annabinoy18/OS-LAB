#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,rs[25],f,pf,m[10],flag[25],count[10],freq[10],min,i,j;
    printf("Enter the length of reference string: ");
    scanf("%d",&n);
    printf("Enter the reference string: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the no.of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        m[i]=-1;
        count[i]=0;
        freq[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<f;j++)
        {
            if(m[j]==rs[i])
            {
                flag[i]=1;
                freq[j]++;
                break;
            }
        }
        if(flag[i]==0)
        {
            if(i<f)
            {
                m[i]=rs[i];
                freq[i]=1;
                count[i]=i;
            }
            else
            {
                min=0;
                for(j=1;j<f;j++)
                {
                    if(freq[min]>freq[j]||(freq[min]==freq[j]&&count[min]>count[j]))
                    {
                        min=j;
                    }
                }
                m[min]=rs[i];
                freq[min]=1;
                count[min]=i;
            }
            pf++;
        }
        for(j=0;j<f;j++)
        {
            printf("\t%d",m[j]);
        }
        if(flag[i]==0)
        {
            printf("\tPF no. %d",pf);
        }
        printf("\n");
    }
    printf("The no.of page faults using lfu: %d",pf);
}