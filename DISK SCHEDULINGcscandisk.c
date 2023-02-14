#include<stdio.h>
#include<stdlib.h>

void main()
{
    int disk[100],i,j,n,Displacement=0,initial,head,roll_size,temp,sorted_disk[100];
    
    printf("Enter the total size of disk roll:");
    scanf("%d",&roll_size);
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter initial head position\n");
    scanf("%d",&head);
    printf("Enter the sequence\n");
    for(i=0;i<n;i++)
    scanf("%d",&disk[i]);

    initial=head;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(disk[j]>disk[j+1])
            {
                temp = disk[j];
                disk[j] = disk[j+1];
                disk[j+1] = temp;
            }
        }
    }

    int mid;
    for(i=0;i<n;i++)
    {
        if(initial<disk[i])
        {
            mid=i;
            break;
        }
    }

    i=0;
    for(int j=mid;j<n;j++,i++)
    sorted_disk[i] = disk[j];
    sorted_disk[i] = roll_size-1;
    i++;
    sorted_disk[i] = 0;
    i++;


    for(int j=0;j<=mid-1;j++,i++)
    sorted_disk[i] = disk[j];

    printf("\norder of execution:\n");
    printf("%d\t",head);

    for(i=0;i<=n+1;i++)
    {
        Displacement+=abs(sorted_disk[i]-initial);
        initial=sorted_disk[i];
        printf("%d\t",sorted_disk[i]);
    }

    printf("\nTotal head moment is %d",Displacement);
}
