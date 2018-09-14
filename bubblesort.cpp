#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef struct{
	int key;
}Elemtype;


void bubblesort(Elemtype*a,int n) 
{
	int i=0,j=0;
	Elemtype bigger;
	for(i=n;i>=2;i--)
	{
		for(j=1;j<i;j++)
		{
			if(a[j].key>a[j+1].key)
			{
				bigger = a[j];
				a[j]=a[j+1];
				a[j+1]=bigger;//swap
			}//if
		}//for j
	}//for i
}


int main()
{
	int n;
	cout<<"输入n，产生n个0-99之间的随机数：";
	scanf("%d",&n); 
	Elemtype *a = NULL;
	a = (Elemtype *)malloc(sizeof(Elemtype)*(n+1));
	srand((unsigned)time(NULL));
	for(int i = 1;i<=n;i++)
	{
		a[i].key=rand()%100;
		printf("%d:%d ",i,a[i].key);
	}
	cout<<endl;
	
	//冒泡排序 
	bubblesort(a,n);
	cout<<"冒泡排序结果："<<endl;
	for(int i = 1;i<=n;i++)
	{
		printf("%d:%d ",i,a[i].key);
	}
	cout<<endl;
	
	
	return 0;
}


