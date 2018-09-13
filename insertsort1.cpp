#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef struct{int key;}Elemtype;

int binarysearch( Elemtype* a , int n ,Elemtype b)//����С�ڵ���b��Ԫ�ص�λ�� 
{
	int low = 1 , high = n;
	int mid = 0;
	while(low<=high)
	{
		mid = (low + high) /2;
		if(a[mid].key == b.key)return mid;//�ҵ���ȵ�Ԫ�ص��±� 
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
        if(a[i].key<a[i-1].key)//���Ԫ����ǰ�����н��бȽϲ��� 
        {
            a[0] = a[i];//�ڱ� 
            //�۰���ң��߽�[1...(i-1)] 
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
	cout<<"����n������n��0-99֮����������"; 
	scanf("%d",&n);
    Elemtype*a=(Elemtype*)malloc(sizeof(Elemtype)*(n+1));
    for(int i = 1;i<=n;i++)
    {
        a[i].key=rand()%100;//����n��0-99֮���������� 
        printf("%d:%d ",i,a[i].key);
    }
    printf("\n");
    
    //�۰��������
    cout<<"�����۰���������n������"<<endl; 
	insertsort1(a,n);
    for(int i = 1;i<=n;i++)
    {
        printf("%d:%d ",i,a[i].key);
    }
    printf("\n");
    
	/*
    //�۰���� 
    int c;
    Elemtype b;
    cout<<"����n�������������������۰���ҳ�С�ڵ���n��Ԫ���±�"<<endl; 
    scanf("%d",&b.key);
    c = binarysearch(a,n,b); 
    printf("result = %d\n",c);
	*/
	
    free(a);
    return 0;
}
