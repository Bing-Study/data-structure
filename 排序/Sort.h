#include<stdio.h>

#define Maxsize 10

typedef int Elemtype;


/***************************************
		数组下标从0开始
***************************************/ 

void InsertSort(Elemtype A[],int n);	//直接插入排序 
void print(Elemtype A[],int n);			//打印数组 
void ShellSort(Elemtype A[],int n);		//希尔排序
void BubbleSort(Elemtype A[],int n);	//冒泡排序
void QuickSort(Elemtype A[],int low,int high);	//快速排序
int Partition(Elemtype A[],int low,int high);	//快速排序的一趟划分

void Swap(int *a,int *b);	//交换 
void BinarySort(Elemtype A[],int n);	//二分插入排序 
void ColorSort(int A[],int n);	//荷兰国旗问题 
void Heapify(int A[],int start,int end);	//调整堆函数 
void HeapSort(int A[],int len);		//堆排序 
 

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

void QuickSort(Elemtype A[],int low,int high)	//快速排序
{//参数:A位数组,low为数组第一个位置,high为数组最后一个位置 
	if(low<high){
		int pivotpos = Partition(A,low,high);	//划分
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	} 
} 
int Partition(Elemtype A[],int low,int high)	//快速排序的一趟划分 
{
	Elemtype pivot = A[low];
	while(low<high){
		while(pivot <= A[high] && low < high){//如果piovt的值达于A[high]位置上的值	
			high-=1;							//则说明，high位置上的值应该在pivot之前，
		}
		A[low] = A[high];				//将A[high]的数据放到low的位置上
		while(pivot >= A[low] && low < high){
			low+=1;
		}
		A[high] = A[low];
	}
	A[low] = pivot;	//循环结束后，low位置的值就是pivot最后的位置 
	return low;		//返回low的值，将表划分位两个子表 
} 

void BinarySort(Elemtype A[],int n)	//二分插入排序 
{
	int low,high,mid; 
	int temp;		//临时变量，存储待排序关键字。
	
	for(int i = 1;i < n;i++){	//依次排序 
		low = 0;
		high = i-1;
		temp = A[i]; //记录该关键字，防止关键字插入后移导致关键字消失。
		
		while(low <= high){
			mid = (low + high) / 2;
			if(A[mid] > temp){
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		
		for(int j = i - 1;j >= low;j--){
			A[j+1] = A[j];
		}
		A[low] = temp;
	} 
}
void ColorSort(int A[],int n)	//荷兰国旗问题
{
	const int Red = 1,White = 2,Blue = 3;
	//1为红色,2为白色，3为蓝色
	
	int Insert_Red = 0, Insert_White = 0, i;
	for(i = 0 ; i < n ; i++){
		if(A[i] == White){
			//当前条块为白色，与白色条块插入位置的条块作交换 
			A[i] = A[Insert_White];
			A[Insert_White] = White;
			Insert_White++;
		}
		if(A[i] == Red){
			//当前条块为红色，与红色条块插入位置的条块作交换
			//再与白色条块插入位置的条块作交换	
			A[i] = A[Insert_White];
			A[Insert_White] = A[Insert_Red];
			A[Insert_Red] = Red;
			Insert_Red++;
			Insert_White++;
		}
	}
}

void Swap(int *a,int *b)	//交换
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void Heapify(int A[],int start,int end)		//调整堆函数 
{
	int dad = start;
	int son = dad * 2 + 1;
	
	
	/*********************************************
				创建大根堆 
				从上至下依次调整堆的结构 
	**********************************************/
//	while(son <= end){
//		//先比较两个子节点的大小，选出大的一个 
//		if(son + 1 <= end && A[son] < A[son + 1])
//			son++;
//		//若父节点大于子节点，则符合大根堆，跳出循环 
//		if(A[dad] > A[son])
//			return; 
//		else{
//		//否则，交换节点数据 
//			Swap(&A[dad],&A[son]);
//			dad = son;
//			son = dad * 2 + 1; 
//		} 
//	}
	
	/*********************************************
					创建小根堆 
			从上至下依次调整堆的结构
			代码结构与大根堆基本一样 
	**********************************************/
	while(son <= end){
		//先比较两个子节点的大小，选出大的一个 
		if(son + 1 <= end && A[son] > A[son + 1])
			son++;
		//若父节点大于子节点，则符合大根堆，跳出循环 
		if(A[dad] < A[son])
			return; 
		else{
		//否则，交换节点数据 
			Swap(&A[dad],&A[son]);
			dad = son;
			son = dad * 2 + 1; 
		} 
	}

	
}

void HeapSort(int A[],int len)		//堆排序
{
	int i;
	
	/*
		创建大根堆，并经行大根堆的堆排序 
	*/
	for(i = (len / 2) - 1; i >= 0; i--){
		//从最后一个带有子节点的节点从下往上开始调整堆的结构 
		Heapify(A,i,len-1);	
	} 
	
	//调整完一遍后,最大值在堆的顶部,即位于A[0]处
	//将第一个位置，即已排好的位置与最后一位互换
	//并重新进行排序 
	for(i = len - 1; i > 0; i--){
		Swap(&A[0],&A[i]);
		//由于大根堆已建立完毕
		//在交换完数据后，只可能有一位数据不符合大根堆要求，
		//即交换后的堆顶元素，在调整一次堆即可
		//调整位置从0开始(堆顶)。 
		Heapify(A,0,i-1);
		

	} 
}
