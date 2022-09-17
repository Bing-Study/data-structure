#include<stdio.h>

#define  Maxsize 10

typedef int Elemtype;

typedef struct {
	Elemtype data[Maxsize];
	int front,rear;
}SqQueue;

bool InitQueue(SqQueue &S);	//初始化队列 
bool QueueEmpty(SqQueue S);	//判空 
bool EnQueue(SqQueue &S,Elemtype data);	//入队 
bool printQueue(SqQueue S);		//打印队尾和队首 
bool PopQueue(SqQueue &S);		//出队 

int main(){
	int x;
	SqQueue S;
	InitQueue(S);
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		EnQueue(S,x);
		scanf("%d",&x); 
	}
	PopQueue(S);
	printQueue(S);
	return 0;
}

bool InitQueue(SqQueue &S){	//初始化队列 
	S.front=S.rear=0; 
	return true;
} 

bool QueueEmpty(SqQueue S){	//判空  
	if(S.front==S.rear)
		return true;
	else
		return false;
} 

bool EnQueue(SqQueue &S,Elemtype data){	//入队 
	if((S.rear+1)%Maxsize==S.front){
		printf("The queue is full!\n");
		return false;
	} 
	S.data[S.rear]=data;
	S.rear=(S.rear+1)%Maxsize;
	return true; 
} 
bool printQueue(SqQueue S)		//打印队尾和队首 
{
	if(QueueEmpty(S)){
		printf("The Queue is null!\n");
		return false;
	}
	printf("The front data is:%d\n",S.data[S.front]);
	printf("The rear data is:%d\n",S.data[S.rear-1]);
} 
bool PopQueue(SqQueue &S){		//出队
	if(QueueEmpty(S)){
		printf("The Queue is null!\n");
		return false;
	}
	S.front=(S.front+1)%Maxsize;
} 
