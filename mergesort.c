#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int N;
int merge(int b[],int c[],int a[],int p,int q)
    {int i=0,j=0,k=0,cnt=0;
    while((i<p)&&(j<q))
        {if(b[i]<=c[j])
            {a[k]=b[i];
            i++;}
        else
            {a[k]=c[j];
            j++;}
    k++;
    cnt++;}
    if(i==p)
        {
        while(j<q)
            {a[k]=c[j];
            j++;
            k++;
            cnt++;
            }}
    else
        {
        while(i<p)
            {a[k]=b[i];
            i++;
            k++;
            cnt++;
            }}
        return cnt;
    }
int mergesort(int a[],int n)
    {if(n>1)
    {int c1=0,c2=0,c3=0,count=0;
    if(n%2==0)
        {int b[n/2];
        int c[n/2];
        int i,j=0;
        for(i=0;i<n/2;i++,count++)
            {b[i]=a[i];}
        for(i=n/2;i<n;i++,count++)
            {c[j]=a[i];
                j++;
            }
       c1=mergesort(b,n/2);
        c2=mergesort(c,n/2);
        c3=merge(b,c,a,n/2,n/2);}
      else
        {int b[n/2];
        int c[(n/2)+1];
        int i,j=0;
        for(i=0;i<n/2;i++,count++)
            {b[i]=a[i];}
        for(i=n/2;i<n;i++,count++)
            {c[j]=a[i];
                j++;
            }
        c1=mergesort(b,n/2);
        c2=mergesort(c,(n/2)+1);
        c3=merge(b,c,a,n/2,(n/2)+1);}
         return count+c3+c1+c2;
    }}
int main()
    {int arr[100];
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
            c=mergesort(arr,n);
            for(i=0;i<n;i++)
                {printf("\n%d ",arr[i]);}
        break;
    }
    case 2:{int arr[32000],size,i,j,t1,t2,t3;
            float ln;
            printf("Enter size of array for complexity calculation of array of its next 5 multiples: ");
            scanf("%d",&size);
            printf("Size\tAscending\tcnlog(n)\tDescending\tcnlog(n)\tRandom\tcnlog(n)\n");
            int p=size;
            for(i=1;i<=5;i++,size+=p)
            {
                N=size;
                ln=2*size*log(size)/log(2);
                //printf("Entered\n");
                for(j=0;j<size;j++)
                    arr[j]=j;
                t1=mergesort(arr,size);
                //printf("t1=%d\n",t1);
                for(j=0;j<size;j++)
                    arr[j]=size - j;
                t2=mergesort(arr,size);
                for(j=0;j<size;j++)
                    arr[j]=rand()%32000;
                t3=mergesort(arr,size);
                printf("%d\t%d\t\t%.0f\t\t%d\t\t%.0f\t\t%d\t%.0f\n",size,t1,ln,t2,ln,t3,ln);
                
            }
            printf("(Considering c as 2 here)\n");
            break;
        }}}
