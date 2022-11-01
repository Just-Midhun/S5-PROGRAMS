#include<stdio.h>

int allocation[100][100],available[100],maximum[100][100],needed[100][100];

void main() {

    int processes,resources,validity=0;


printf("enter the total number of processes:");
scanf("%d",&processes);
printf("\nenter the total number of resources:");
scanf("%d",&resources);

printf("\nenter the allocation matrix:");
for(int i=0;i<processes;i++)
{
    for(int j=0;j<resources;j++) 
    {
        scanf("%d",&allocation[i][j]);
    }   
}

printf("\nenter the maximum matrix:");
for(int i=0;i<processes;i++)
{
    for(int j=0;j<resources;j++) 
    {
        scanf("%d",&maximum[i][j]);
    }   
}

printf("\nenter the available matrix:");
for(int i=0;i<resources;i++)
{
    scanf("%d",&available[i]);
}

printf("\nNeeded matrix:");
for(int i=0;i<processes;i++)
{
    for(int j=0;j<resources;j++) 
    {   
        needed[i][j]=maximum[i][j]-allocation[i][j];
        printf("%d\t",needed[i][j]);
    }   
    printf("\n");
}

int flag=1,visited[100];

for(int i=0;i<processes;i++)
visited[i]=0;

while(flag==1)
{
    flag=0;

    for(int i=0;i<processes;i++)
    {   
        int num=0;
        if(visited[i]==0)
        {
            for(int j=0;j<resources;j++)
            {   
                if(needed[i][j]<=available[j])
                num++;      
            }

            if(num==resources)
                    {   
                        visited[i]=1;
                        flag=1;
                        validity++;

                        printf("P%d->",i+1);

                        for(int k=0;k<resources;k++)
                        available[k]+=allocation[i][k];
                        
                    }
        }    
    }
}

if(validity==processes)
printf("\nsystem in safe state");

else
printf("\nsystem not in safe state");

}