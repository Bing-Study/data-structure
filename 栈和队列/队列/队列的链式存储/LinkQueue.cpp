#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

typedef int Elemtype;

typedef struct LinkNode{
	Elemtype data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front,*rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q);	//初始化队列 
bool IsEmpty(LinkQueue &Q);		//判空 
bool EnQueue(LinkQueue &Q,Elemtype x);	//入队 
bool PopQueue(LinkQueue &Q);	//出队 
bool PrintQ(LinkQueue Q);	//打印队列头尾 



int main(){
	LinkQueue Q;
	int x;
	InitQueue(Q);
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		EnQueue(Q,x);
		scanf("%d",&x); 
	}
	PopQueue(Q);
	 PrintQ(Q);
	return 0; 
}

bool InitQueue(LinkQueue &Q){	//初始化队列 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
} 
bool IsEmpty(LinkQueue &Q){		//判空 
	if(Q.front==Q.rear){
		printf("The Queue is empty!\n");
		return true;
	}
	return false;
} 

bool EnQueue(LinkQueue &Q,Elemtype x)	//入队 
{
	LinkNode *L=(LinkNode *)malloc(sizeof(LinkNode));
	L->data=x;
	L->next=NULL;
	Q.rear->next=L;
	Q.rear=L;
} 

bool PopQueue(LinkQueue &Q)		//出队
{
	if(IsEmpty(Q)){
		return false;
	}
	LinkNode *p=Q.front->next;
	Q.front->next=p->next; 
	if(p==Q.rear){
		Q.front=Q.rear;
	}
	free(p);
	return true;
} 

bool PrintQ(LinkQueue Q)	//打印队列头尾 
{
	if(IsEmpty(Q))
		return false;
	printf("The front data is:%d\n",Q.front->next->data);
	printf("The rear data is:%d\n",Q.rear->data);
} 



