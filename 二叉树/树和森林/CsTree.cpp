#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
	char data;
}Elemtype;

typedef struct CSNode{	//孩子兄弟表示法 
	Elemtype data;
	struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;

bool InitCS(CSTree &C);	//初始化树
bool CreateCS(CSTree &C);//创建树
void InOrder(CSTree C);	//先根遍历
void PostOrder(CSTree C);	//后根遍历 




int main(){
	CSTree C;
	Elemtype x;
	if(!InitCS(C)){
		printf("Init Tree false");
		return 0;
	}
	printf("Init success\n");
	
	
	printf("please input root data:");
	scanf("%c%*c",&x.data);	//%*c:消除输入完字符后的回车 
	C->data=x; 
	CreateCS(C);	//创建树 
	
	InOrder(C);
	printf("\n");
	
	PostOrder(C);
	printf("\n");
	return 0;
}


bool InitCS(CSTree &C)	//初始化树
{
	C = (CSNode *)malloc(sizeof(CSNode));
	C->firstchild=C->nextsibling=NULL;
	return true; 
}
bool CreateCS(CSTree &C)//创建树
{
	Elemtype x;
	CSNode *S;

	
	printf("请输入%c节点的第一个孩子的数据：",C->data.data);
	scanf("%c%*c",&x.data);
	if(x.data != '9'){
		InitCS(S);
		S->data = x;
		C->firstchild=S;
		CreateCS(S);
	}
	
	printf("请输入%c节点的右兄弟的数据：",C->data.data);
	scanf("%c%*c",&x.data);
	if(x.data != '9'){
		InitCS(S);
		S->data = x;
		C->nextsibling=S;
		CreateCS(S);
	}
} 

void InOrder(CSTree C)	//先根遍历
{
	if(C != NULL){
		printf("%c ",C->data.data);
		InOrder(C->firstchild);
		InOrder(C->nextsibling);
	} 
} 
void PostOrder(CSTree C)	//后根遍历
{
		if(C != NULL){
			InOrder(C->firstchild);
			printcf("%c ",C->data.data);
			InOrder(C->nextsibling);
	
	}
} 
