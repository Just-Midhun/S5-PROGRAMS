#include<stdio.h>
#include<stdlib.h>
void main()
{
    int disk[100],i,n,Displacement=0,initial,head;
   
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter initial head position\n");
    scanf("%d",&head);
    printf("Enter the sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&disk[i]);
    
    initial=head;
    for(i=0;i<n;i++)
    {
        Displacement+=abs(disk[i]-initial);
        initial=disk[i];
    }
    
    printf("Total head moment is %d",Displacement);
    
}