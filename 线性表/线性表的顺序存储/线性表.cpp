#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
typedef int Elemtype ;

typedef struct {
	Elemtype data[MaxSize];		//创建一个长度位MaxSize的表 
	int length;					//线性表的当前长度 
}SqList;


bool InitList(SqList &L);				//初始化线性表 
bool ListInsert(SqList &L,int i,Elemtype e);	//第i个位置插入元素e 
bool ListDelet(SqList &L,int i);	// 删除第i个元素，并将元素用e返回
int LocateElem(SqList L,Elemtype e);			//查找元素e，并返回位置。
void print(SqList);		//打印当前表 
void ListSort(SqList &L);	//排序算法 
Elemtype yi(SqList &L);		//22王道17页 二，1 题 删除最小元素，由最后一位元素补空。 
int er(SqList &L);			//22王道17页 二，2 题	将元素逆置，且空间复杂度为O(1)
int san(SqList &L,int x);	//22王道17页 二，3 题 时间复杂度为O(n),空间复杂度为O(1),删除所有值为x的元素 
int si(SqList &L,int s,int l);	//22王道17页 二，4 题 有序顺序表删除值在给定值s-l之间的所有元素
int liu(SqList &L);			//17页，第6题，删除顺序表中所有重复的元素。
int shi(SqList &L,int p);	//将L中保存的序列循环向左移动p个位置 时间和空间尽可能高效。 
int shiyi(SqList S1,SqList S2);//17页，11题，有升序序列S1和S2,寻找S1与S2合并后的中位数，即位置为length/2位置的数 
int main(){
	SqList L;
	int e=-1;
	int j;
	int place;
	if(!InitList(L))
		{
			printf("Init LIst false!\n");
			return 0;
		}
	printf("Init success!\n");
	
	for(int i=0,locate=0;i<6;i++,locate+=6){		//给前5个数据赋值 
//		printf("please input your data L1:");
//		scanf("%d",&j);
		ListInsert(L,i,locate);	
	}
	print(L); 
	
//	ListInsert(L,3,20);				//在第8位插入数据20 
//	ListInsert(L,80,20);			//测试非法位置 
	
/*	print(L)*/
	
//	ListDelet(L,8,e);				//删除第8位的数据并使用e带回 
//	printf("%d\n",e);
	
	 
//	print(L);
	
//	place=LocateElem(L,0);			//获取要查找的数据的位置 
//	if(place==0)
//		printf("The list dont have this data\n"); 
//	else
//		printf("%d\n",place);
			
//	printf("第一题：%d\n",yi(L));		//22王道17页 二，1 题 
//	er(L);			//22王道17页 二，2 题 
//	print(L);
	
//	san(L,3);
//	print(L);	
	
//	//第四题
//	int s,l;
//	printf("input:");
//	scanf("%d%d",&s,&l); 
//	si(L,s,l);


//	//第六题
//	liu(L); 
//	print(L);


//	//第十题
//	int p;
//	printf("p:");
//	scanf("%d",&p);
//	shi(L,p);
//	print(L); 


//	排序 
//	
//	ListSort(L);
//	print(L); 

//第11题
	SqList L2;
	InitList(L2); 
	for(int i=0,locate=8;i<6;i++,locate+=3){		//给前5个数据赋值 
//		printf("please input your data L2:");
//		scanf("%d",&j);
		ListInsert(L2,i,locate);	
	}
	print(L2); 

	shiyi(L,L2);
	


	return 0;





} 








bool InitList(SqList &L)				//初始化线性表 
{
	for(int i;i<MaxSize;i++)
	{
		L.data[i]=0;
	}
	L.length=0;
	return true;
} 
bool ListInsert(SqList &L,int i,Elemtype e)		//第i个位置插入元素e 
{
	 if(i<0||i>MaxSize){		//判断位置是否合法 
	 	printf("The place was false!\nInsert false!\n");
	 	return false;
	 }
	 if(L.length==MaxSize){		//判断线性表当前是否已满 
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
bool ListDelet(SqList &L,int i)		// 删除第i个元素，并将元素用e返回
{
	if(i<0||i>MaxSize){
	 	printf("The place was false!\n");
	 	return false;
	 }
	for(int j=i;j<MaxSize;j++){
	 	L.data[j]=L.data[j+1];
	 }
	L.length--;
	return true;
} 
int LocateElem(SqList L,Elemtype e)				//查找元素e，并返回位置。
{
	int i=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;		//位置从0开始计算，所以返回值加1，相当于位置从1开始计算 
							//便于观察 
	}
	i=0;
	return i; 
		
} 

void print(SqList L)			//打印当前线性表
{
	for(int i=0;i<L.length;i++){	//打印当前线性表 
		printf("%d   ",L.data[i]);	
	}
	printf("\n");

} 

//	1.从顺序表中删除具有最小值的元素，并由函数反回被删元素的值。空出的位置
//	   由最后一个元素填补，若顺序表为空，则显示出错信息并推出运行。

Elemtype yi(SqList &L){		//22王道17页 二，1 题
	if(L.length==0){
		printf("The list is empty!\n");
		exit(0);
	}
	
	Elemtype min=L.data[0];
	for(int i=0;i<L.length;i++){
		if(min>L.data[i]){
			min=L.data[i];
		}
	}
	return min; 
}
 

int er(SqList &L)			//22王道17页 二，2 题	将元素逆置，且空间复杂度为O(1)
{
	Elemtype x;
	for(int i=0;i<L.length/2;i++){
		x=L.data[i],L.data[i]=L.data[L.length-i-1],L.data[L.length-i-1]=x;
	}
	return 0;
}

int san(SqList &L,int x)	//时间复杂度为O(n),空间复杂度为O(1),删除所有值为x的元素
{
	int k=0;;
	for(int i=0;i<L.length;i++){
//		if(L.data[i]==x){		//错误，时间复杂度为O(n^2),ListDelt的复杂度也为n 
//			ListDelet(L,i,e);	//故时间复杂度不符合题目要求 
//			i--;
//		}
		if(L.data[i]!=x){
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
	return 0; 
} 

int si(SqList &L,int s,int l)	//22王道17页 二，4 题 
//								有序顺序表删除值在给定值s-l之间的所有元素
{
	int i=0,j=0;
	if(s>l){
		printf("the data is illegal!\n");
		return 0;	
	}		
	i=LocateElem(L,s);	//定位s。 
	j=i+(l-s);			//根据s的位置定位l的位置。 
	if(i==0){
		printf("the list dont have this data!\n");
		return 0;
	}  
	for(i=i-1;i<L.length;i++){
		L.data[i]=L.data[j];
		j++;
	}
	L.length=L.length-(l-s)-1; 
}

int liu(SqList &L){			//17页，第6题，删除顺序表中所有重复的元素。
	Elemtype temp; 
	for(int i=0;i<L.length;i++){
		temp=L.data[i];
		for(int j=i+1;j<L.length;j++){
				
			if(temp==L.data[j])		 
				ListDelet(L,j),j--;
				/*删减完一个数据后所有数据会前移一位
				 而j的指向的位置也会前移一位
				 故需将j-1; 
				 */ 
		}
	} 
	return 0;
} 

int shi(SqList &L,int p)	//将L中保存的序列循环向左移动p个位置，时间和空间尽可能高效 
{
//	Elemtype temp; 		//定义一个缓冲区 
//	//循环向左移。时间复杂度O(n*p),空间复杂度O(1)
//	//向左移p次，即向右移n-p次。 
//	for(int i=0;i<p;i++){
//		
//		for(int j=0;j<L.length-1;j++){
//			temp=L.data[j];
//			L.data[j]=L.data[(j+1)%L.length];
//			L.data[(j+1)%L.length]=temp; 
//		}
//		print(L);
//	}
//	 printf("\n");



	SqList temp;	//定义一个和线性表一样长的缓冲区。 
	InitList(temp);
	
	temp=L;		//赋值
	/*核心思想：将线性表赋值给缓冲区，从缓冲区中直接获取数据赋值到
	L中，使得时间复杂度为O(n),空间复杂度为O(n); */
	
	for(int i=0;i<L.length;i++){
			L.data[(i+p)%L.length]=temp.data[i];

	}	
}

Elemtype shiyi(SqList S1,SqList S2){
	//17页，11题，有升序序列S1和S2,寻找S1与S2合并后的中位数
	//即位置为length/2位置的数 要求算法尽量高效
	ListSort(S1);
	ListSort(S2); 
	int L1,L2,L;
	L1=S1.length;
	L2=S2.length;
	L=(L1+L2)/2;
	L1=0;L2=0; 
	Elemtype temp;
	for(int i=0;i<L;i++){
		if(S1.data[L1]<=S2.data[L2]){
			temp=S1.data[L1];
			L1++;
		}
		else{ 
			temp=S2.data[L2];
			L2++; 
			} 
	} 
	 
	 
	printf("%d\n",temp);
	
} 
void ListSort(SqList &L)	//排序算法
{
	Elemtype temp;
	for(int i=0;i<L.length;i++){
		for(int j=L.length-1;j>i-1;j--){
			if(L.data[j]<L.data[j-1]){
				temp=L.data[j];
				L.data[j]=L.data[j-1];
				L.data[j-1]=temp;
			}
		}
	}
} 
