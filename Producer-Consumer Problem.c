#include <stdio.h>
int empty,n,a[10],full=0,mutex=1,i=1,x=1;
int wait(int s)
{
 return(--s); 
}
int signal(int s)
{
 return(++s);
}
void producer()
{
  if((mutex==1)&&(empty!=0))
  {
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    printf("\nproducer produces the item:");
    scanf("%d",&a[i]);
    i++;
    mutex=signal(mutex);
  }
  else
  {
    printf("buffer is full!!");
    choice();
  }

}
void consumer()
{
  if((mutex==1)&&(full!=0))
  {
   mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    if(x<=i)
    { 
      printf("\nconsumer consume the item: %d",a[x]);
      
    }
    x++;
    mutex=signal(mutex); 
  }
  else
  {
    printf("buffer is empty!!");
    choice();
  }
}
int choice()
{
  do
   {
    printf("\n1.Producer\n2.Consumer\n3.Exit\nenter the choice: ");
    scanf("%d",&n);
    switch(n)
     {
      case 1 : producer();
              break;
      case 2 : consumer();
              break;
      case 3 : break;
     }
   }while(n!=3);
 return 0;
}
int main()
{
  printf("enter the limit: ");
  scanf("%d",&empty);
  choice(); 
  return 0;
}
