#include<stdio.h>
#include <stdlib.h>


#define Maxsize 10
typedef int Elemtype ;

typedef struct {
	Elemtype data[Maxsize];		//创建一个长度位MaxSize的表 
	int length;					//线性表的当前长度 
}SqList;

bool InitList(SqList &L);				//初始化线性表 
bool ListInsert(SqList &L,int i,Elemtype e);	//第i个位置插入元素e
bool CreatList(SqList &L);		//创建线性表 
int Binary_Search(SqList L,Elemtype x);	//折半查找 


int main(){
	SqList L;
	InitList(L);
	
	CreatList(L);
	printf("find :%d",Binary_Search(L,8));
	return 0; 
}


bool InitList(SqList &L)				//初始化线性表 
{
	for(int i;i<Maxsize;i++)
	{
		L.data[i]=0;
	}
	L.length=0;
	return true;
} 

bool ListInsert(SqList &L,int i,Elemtype e)		//第i个位置插入元素e 
{
	 if(i<0||i>Maxsize){		//判断位置是否合法 
	 	printf("The place was false!\nInsert false!\n");
	 	return false;
	 }
	 if(L.length==Maxsize){		//判断线性表当前是否已满 
	 	printf("List has full!\n");
	 	return false;
	 } 
	 for(int j=L.length;j>=i;j--){		//插入操作 
	 	L.data[j+1]=L.data[j];
	 }
	 L.data[i]=e;
	 L.length++;
	 return true;
	 
} 

bool CreatList(SqList &L)		//创建线性表 
{
	int temp[Maxsize] = {2,6,10,18,30,35,48,56,68,77};
	for(int i=0;i<Maxsize;i++){
		ListInsert(L,i,temp[i]);
	}
} 

int Binary_Search(SqList L,Elemtype x)	//折半查找 
{
	int i=0;
	int low = 0,high = L.length - 1;
	
	while(low<=high){
		i++;
		printf("%d");
		int mid = (low + high)/2;
		if(x>L.data[mid]){
			low = mid + 1;
		}
		else if(x<L.data[mid]){
			high = mid - 1;
		}
		else if (x == L.data[mid])
			return mid;
	}
	printf(" i = %d",i);
	return Maxsize;
	
} 
