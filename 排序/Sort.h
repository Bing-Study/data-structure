#include<stdio.h>

typedef int Elemtype;


void InsertSort(Elemtype A[],int n);	//直接插入排序 
void print(Elemtype A[],int n);			//打印数组 
void ShellSort(Elemtype A[],int n);		//希尔排序
void BubbleSort(Elemtype A[],int n);	//冒泡排序
 

void InsertSort(Elemtype A[],int n)	//直接插入排序
{//排序位置从0开始 
	int i = 1,j;
	Elemtype temp; 
	for(i;i < n ;i++){
		j = i-1;		 
		if(A[i]<A[i-1]){		//找到后一位的数比前一位的数小 
			temp = A[i];
			while(A[j] > temp && j >= 0){	//找到有序序列中第一个比temp值小的位置 
				A[j+1]=A[j];		//向后腾出一个位置 
				j--;
			}
			A[j+1] = temp;		//插入 
		}
	} 
} 

void print(Elemtype A[],int n)		//打印数组
{
	for(int i = 0;i<n;i++){
		printf("%d  ",A[i]);
	} 
} 


void ShellSort(Elemtype A[],int n)		//希尔排序
{
	int dk;		//定义希尔排序的增量 
	Elemtype temp;	//定义临时变量
	int i,j; 
	for(dk = n/2;dk >= 1;dk = dk/2){
		for(i = dk;i<n;i++){
			if(A[i]<A[i-dk]){
				temp = A[i];
				for(j = i-dk;j >= 0 && temp<A[j];j-=dk)
					A[j+dk] = A[j];
				A[j+dk] =temp;
			}
			
			
		}
	}
} 

void BubbleSort(Elemtype A[],int n)		//冒泡排序
{
	Elemtype temp;
	int i,j; 
	bool flag;	//表示一趟排序中是否发生交换 
	for(j = n-1;j >= 0;j--){
		flag = false;
		for(i = 0;i < j;i++){	//
			if(A[i]>A[i+1]){	//交换 
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				flag = true;
			}
		}

		if(flag == false)
			return;
	}

} 
