#include <stdio.h>
#include<stdlib.h>
int n=0,i=0,d[50],head,temp[50],input,end,k=0,j=0,d2[50],c[50],l=0,m;

int cscan()
{
 for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
      { 
       if(d[j]>d[i])
        {
          temp[j]=d[i];
          d[i]=d[j];
          d[j]=temp[j];
        }
      }
    }
  while(head>d[k])
   {
     k++;
   }
  
  printf("Order of CSCAN: ");
  printf("%d ",head);
  for(i=k;i<n;i++)
  {
   if(d[i]>head)
    {
     printf(" %d ",d[i]);
    }
  }
  printf("%d ",end);
  printf("%d ",0);

  for(j=0;j<k;j++)
  {
   if(d[j]<=head && d[j]!=0)
    {
     printf("%d ",d[j]);
    }
  }
  m=((end-head)+(end-0)+(d[k-1]-0));
  printf("\nTotal seek time of cscan: %d",m);
  printf("\nAvg seek time of cscan= %d\n",m/n);
  return 0;
}
void scan() 
{
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   { 
    if(d[j]>d[i])
    {
     temp[j]=d[i];
     d[i]=d[j];
     d[j]=temp[j];
    }
   }
  }
  
  while(head>d[k])
   {
     k++;
   }
  
  
  printf("Order of SCAN: ");
  printf("%d ",head);
  
  for(i=k;i<n;i++)
  {
   if(d[i]>head)
    {
     printf(" %d ",d[i]);
    }
  }
  printf("%d ",end);
  
  for(i=k;i>=0;i--)
  {
   if(d[i]<head && d[i]!=0)
    {
     printf("%d ",d[i]);
    }
  }
  printf("%d ",0);
  m=((end-head)+(end-d[0]));
  printf("\nTotal seek time of scan: %d",m);
  printf("\nAvg seek time of scan= %d\n",m/n);
 }  
void fcfs()
 {
  printf("Order of FCFS: ");
  printf("%d ",head);
  for(i=0;i<n;i++)
    printf("%d ",d2[i]);
  for(i=1;i<=n;i++)
   {
     c[i]=d2[i-1];
   }
  c[0]=head;
  
  printf("\nTotal seek time of fcfs=");
  for(i=0;i<n;i++)
   {
     l=l+ abs(c[i+1]-c[i]);
   }
  printf(" %d",l);
  m=l/n;
  printf("\nAvg seek time of fcfs= %d\n",m);
 }

int main()
 {
  printf("enter the limit: " );
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    printf("enter the values: ");
    scanf("%d",&d[i]);
    d2[i]=d[i];
  }
  printf("\n\nEnter final position of the disk: ");
  scanf("%d",&end);
    
  printf("Enter head location: ");
  scanf("%d",&head); 
  do
  {
   printf("\n1.FCFS\n2.SCAN\n3.CSCAN\nSELECT AN ALGORITHM:(1-3) ");
   scanf("%d",&input);
   printf("\n\n");
    switch(input)
    {
        case 1:fcfs();
            break;
        case 2:scan();
            break;
        case 3:cscan();
            break;
        default:break;
    }
    }while(input!=3);
  return 0;
}
