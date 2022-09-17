#include<stdio.h>

#define Maxsize 20

typedef int Elemtype;

typedef struct{
	Elemtype data[Maxsize];
	int top;
}SqStack;
 
bool Initstack(SqStack &S);	//初始化栈 
bool StackEmpty(SqStack S);	//判断栈空 
bool Push(SqStack &S,Elemtype data);	//进栈 
bool PrintStack(SqStack &S);	//打印当前栈顶元素 
bool Pop(SqStack &S);	//出栈 




int main(){
	SqStack S;
	Elemtype x;
	Initstack(S);
	printf("Input your data:");
	scanf("%d",&x);
	while(S.top==Maxsize-1 || x!=999){
		Push(S,x);
		scanf("%d",&x);
	}
	Pop(S);
	PrintStack(S);
	return 0;
}


bool Initstack(SqStack &S){	//初始化栈 
	S.top=-1;
	return true; 
} 
bool StackEmpty(SqStack S)	//判断栈空
{
	if(S.top==-1){
		printf("The stack is empty");
		return true;
	} 
	else 
		return false;
} 

bool Push(SqStack &S,Elemtype data)	//进栈
{
	if(S.top==Maxsize-1){
		printf("The stack is full");
		return false;
	} 
	S.data[++S.top]=data;
	return true;
} 

bool PrintStack(SqStack &S)	//打印当前栈顶元素
{
	printf("%d",S.data[S.top]);
} 

bool Pop(SqStack &S)	//出栈
{
	if(StackEmpty(S)){
		printf("The stack is empty!");
		return false; 
	} 
	S.top--;
	return false;
	
} 

