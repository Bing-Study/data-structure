
#include "Sort.h"

#define Maxsize 10

Elemtype NList[Maxsize] = {50,10,30,26,18,40,43,32,90,68};

int main(){

	
	
	printf("原数组："); 
	print(NList,Maxsize);
	
	printf("\n");
	
//	printf("直接插入排序：");
//	InsertSort(NList,Maxsize);		//直接插入排序 
	

//	printf("希尔排序：");
//	ShellSort(NList,Maxsize);		//希尔排序

//	printf("冒泡排序：");			//冒泡排序
//	BubbleSort(NList,Maxsize);		 

//	printf("快速排序:");				//快速排序 
//	QuickSort(NList,0,Maxsize-1);

	printf("二分插入排序：");
	BinarySort(NList,Maxsize); 

	print(NList,Maxsize);
	return 0; 
} 
