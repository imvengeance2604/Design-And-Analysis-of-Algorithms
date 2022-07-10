#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
int N;
int* partition(int arr[],int l,int r)
{int p=arr[l],i,j,k,cnt=0;
int* c =(int*)malloc(sizeof(int)*2);
i=l;
j=r;
while(i<j&&i<r)
   {while(arr[i]<=p)
       {if(i==r)
       {break;}
       i=i+1;
           cnt++;
       }
   while(arr[j]>p)
       {j=j-1;
           cnt++;
       }
     k = arr[i];
     arr[i]=arr[j];
    arr[j]=k;}
    k=arr[i];
    arr[i]=arr[j];
    arr[j]=k;
    k=arr[l];
    arr[l]=arr[j];
    arr[j]=k;
    c[0]=j;
    c[1]=cnt;
    return c;}
int quicksort(int arr[],int l,int r)
{if(l<r)
{ int s,i,c1=0,c2=0,count=0,*c;
c=partition(arr,l,r);
s=c[0];
count = c[1];
c1=quicksort(arr,l,s-1);
c2=quicksort(arr,s+1,r);
    return count+c1+c2; 
}}
int main()
{ int arr[100];
 int s;
    printf("enter 1 for mergesort and 2 for complexity");
    scanf("%d",&s);
    switch(s)
    {case 1:{
     int i,n,c;
            printf("enter elements and tot no of elements");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                {scanf("%d",&arr[i]);}
            c=quicksort(arr,0,n-1);
            for(i=0;i<n;i++)
                {printf("\n%d %d",arr[i],c);}
        break;}
    case 2:{ int arr[32000],size,i,j,t1,t2,t3;
            float ln;
            printf("Enter size of array for complexity calculation of array of its next 5 multiples: ");
            scanf("%d",&size);
            printf("Size\tAscending\t(n*n)\t\tDescending\t(n*n)\tRandom \t(3nlogn)\n");
            int p=size;
            for(i=1;i<=5;i++,size+=p)
            {
                N=size;
                ln=3*size*log(size)/log(2);
                for(j=0;j<size;j++)
                    arr[j]=j;
                t1=quicksort(arr,0,size-1);
                for(j=0;j<size;j++)
                    arr[j]=size - j;
                t2=quicksort(arr,0,size-1);
                for(j=0;j<size;j++)
                    arr[j]=rand()%32000;
                t3=quicksort(arr,0,size-1);
                printf("%d\t%d\t\t%d\t\t%d\t\t%.d\t%d\t%.0f\n",size,t1,size*size,t2,size*size,t3,ln);
                
            }
            break;
        }
        default:
        {
            exit(0);
        }
    }
    return 0;
}
