#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef struct{int key;}Elemtype;

int binarysearch( Elemtype* a , int n ,Elemtype b)//返回小于等于b的元素的位置 
{
	int low = 1 , high = n;
	int mid = 0;
	while(low<=high)
	{
		mid = (low + high) /2;
		if(a[mid].key == b.key)return mid;//找到相等的元素的下标 
		if(a[mid].key < b.key)
		{
			low = mid+1;
		}else{
			high = mid - 1;
		}
	}
	if(low>mid){
		return mid;
	}else{
		return high; 
	}
}


void insertsort1( Elemtype* a , int n )
{
	int i=0;
	int j=0;
	int k;
    for(i=2;i<=n;i++)
    {
        if(a[i].key<a[i-1].key)//逐个元素与前面序列进行比较插入 
        {
            a[0] = a[i];//哨兵 
            //折半查找，边界[1...(i-1)] 
			k = binarysearch(a,i-1,a[0]);
	    	for(j=i-1;j>k;j--)
	    	{
	    	    a[j+1] = a[j];
	    	}
	    	a[j+1]=a[0];
		}
    }
}



int main()
{
	srand((unsigned)time(NULL));
	int n=0;
	cout<<"输入n，产生n个0-99之间的随机整数"; 
	scanf("%d",&n);
    Elemtype*a=(Elemtype*)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1;i<=n;i++)
    {
        a[i].key=rand()%100;//产生n个0-99之间的随机整数 
        printf("%d:%d ",i,a[i].key);
    }
    printf("\n");
    
    //折半插入排序
    cout<<"经过折半插入排序的n个整数"<<endl; 
	insertsort1(a,n);
    for(int i = 1;i<=n;i++)
    {
        printf("%d:%d ",i,a[i].key);
    }
    printf("\n");
    
	/*
    //折半查找 
    int c;
    Elemtype b;
    cout<<"输入n，在上述有序序列中折半查找出小于等于n的元素下标"<<endl; 
    scanf("%d",&b.key);
    c = binarysearch(a,n,b); 
    printf("result = %d\n",c);
	*/
	
    free(a);
    return 0;
}
