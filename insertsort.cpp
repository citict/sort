#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{int key;}Elemtype;

void insertsort( Elemtype* a , int n )
{
	int i=0;
	int j=0;
    for(i=2;i<=n;i++)
    {
        if(a[i].key<a[i-1].key)
        {
            a[0] = a[i];
	    	for(j=i-1;a[j].key>a[0].key;j--)
	    	{
	    	    a[j+1] = a[j];
	    	}
	    	a[j+1]=a[0];
		}
    }
}



int main()
{
	int n=0;
	scanf("%d",&n);
    Elemtype*a=(Elemtype*)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1;i<=n;i++)
    {
        a[i].key=rand()%100;
        printf("%d,",a[i].key);
    }
    printf("\n");
    insertsort(a,n);
    for(int i = 1;i<=n;i++)
    {
        printf("%d,",a[i].key); 
    }
    printf("\n");
    free(a);
    return 0;
}
