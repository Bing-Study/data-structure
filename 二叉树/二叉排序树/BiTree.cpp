#include<stdio.h>
#include<stdlib.h>


typedef struct BiNode{	
	int data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

BiNode *father;	//父结点 

bool InitTree(BiTree &B);	//初始化二叉树 
bool BST_Creat(BiTree &B,int x[],int n);	//创建二叉排序树 
int  BST_Insert(BiTree &B,int x);	//排序树的插入
BiNode *BST_Search(BiTree B,int x);	//排序树的查找 
void InOrder(BiTree B);	//中序遍历二叉树 
bool BST_Delet(BiTree &B,int x);	//删除数据 
BiNode *Search_Next(BiTree B);	//寻找节点的后继  
int GetDepth(BiTree B);		//非递归求树高 
int Get_Depth(BiTree B);	//递归求树高 

void Order(BiTree B);	//非递归遍历二叉树  



int main(){
	int x[10]={50,30,70,20,36,63,76,31,40,80};
	BiTree B;
	BiNode *S;
	int i=0;
	int depth;
	
	BST_Creat(B,x,10);
	
	
/*	
	InOrder(B);
	printf("\n");
	S = BST_Search(B,20);
	printf("S->data:%d\n",S->data);
	printf("S's father->data:%d\n",father->data);
	printf("next->data:%d\n",Search_Next(S->rchild)->data);
	
	BST_Delet(B,30);
	InOrder(B);
*/
//	printf("非递归："); 
//	Order(B);
//	printf("\n");
	
	printf("非递归二叉树高为：%d",GetDepth(B));
	printf("递归二叉树高为：%d",Get_Depth(B));
	
	return 0;
}

bool InitTree(BiTree &B)		//初始化二叉树
{
	B = (BiNode *)malloc(sizeof(BiNode));
	B->rchild=B->rchild=NULL;
	return true;
}

int  BST_Insert(BiTree &B,int x)	//排序树的插入
{
	if(B == NULL){
		B = (BiNode *)malloc(sizeof(BiNode));
		B->data = x;
		B->lchild = B->rchild = NULL;
		return 1;
	}
	else if(x == B->data)
		return 0;
	else if(x > B->data)
		return BST_Insert(B->rchild,x);
	else if(x < B->data)
		return BST_Insert(B->lchild,x);
}

BiNode *BST_Search(BiTree B,int x)	//排序树的查找 
{
	while(B != NULL && B->data != x){
		if(B->data > x){
			father = B;
			B=B->lchild;
		}
		if(B->data < x){
			father = B;
			B=B->rchild;
			
		}
	} 
	return B;
} 

bool BST_Creat(BiTree &B,int x[],int n)	//创建二叉排序树 
{
	B = NULL;
	int i=0;
	while(i < n){
		BST_Insert(B,x[i]);
		i++;
		
	}
}

void InOrder(BiTree B)	//中序遍历二叉树 
{
	if(B != NULL){
		InOrder(B->lchild);
		printf("%d ",B->data);
		InOrder(B->rchild);
	} 
} 

BiNode *Search_Next(BiTree B)	//寻找节点的后继 
{
	if(B->lchild == NULL){
		return B;
	}
	return Search_Next(B->lchild);
} 

bool BST_Delet(BiTree &B,int x)	//删除数据 
{
/*
分三种情况
(1)该节点是一个叶子节点，
	直接删除即可
(2)该节点有一个左子树或者右子树
	用左子树或者右子树直接替代该节点并删除原子节点
(3)该节点有两个子节点
	用该节点的直接后继替代即可,(直接后继为该节点的右子树的最左边的节点)
*/ 

	BiNode *S; //找到需删除的节点
	S = BST_Search(B,x);
	
	if(S->lchild == NULL && S->rchild == NULL)	//情况1
	{
		if(father->lchild == S){
			father->lchild = NULL;
		}
		else if(father->rchild == S){
			father->rchild = NULL;
		}
		free(S);
		return true;
	}
	
	else if(S->lchild == NULL && S->rchild != NULL) //情况2 
	{
		S->data = S->rchild->data;
		free(S->rchild);
		S->rchild = NULL;
		return true;
	} 
	else if(S->lchild != NULL && S->rchild == NULL) //情况2 
	{
		S->data = S->lchild->data;
		free(S->lchild);
		S->lchild = NULL;
		return true;
	} 
	
	else if(S->lchild != NULL && S->rchild != NULL){//情况3 
		BiNode *next = Search_Next(S->rchild); 
		BST_Search(B,next->data);	//寻找next的父结点 
		S->data = next->data;
		if(father == S){	//如果next的父结点与S是同一结点 
			father->rchild = next->rchild; 
		}
		else 
		{
			father->rchild = next->rchild;
		}
		free(next);
		return true;
	}
	return false;
} 

void Order(BiTree B){	//非递归遍历二叉树
	
	//初始化 
	BiNode *p=B;
	BiNode *r = NULL; 
	BiNode *S[50];	//栈 
	int top = 0;	//栈顶指针
	
	
/************************************************
					先序遍历 
************************************************/
/*	
	if(p == NULL)
		exit(0);
	
	while(top > 0 || p != NULL){	//栈非空或节点非空时 
		if(p != NULL){
			printf("%d ",p->data);
			S[++top] = p;	//若节点不为空，则入栈
			p = p->lchild;
		}
		else{
			p = S[top--];
			p = p->rchild;
		}
	} 
*/



/************************************************
					中序遍历 
************************************************/

/*	if(B == NULL)
		exit(0);
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p;
			p = p->lchild;
		}
		else{
			p = S[top--];
			printf("%d ",p->data);
			p = p->rchild;
		}
	}
*/

/************************************************
					后序遍历 
************************************************/
	if(p == NULL)
		exit(0);
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p;
			p = p->lchild;
		}
		else{
			p = S[top];	//读取栈顶节点
			//如果未对右子树进行过操作 
			if(p->rchild != NULL && p->rchild != r){
				//将p的右子树入栈
				p = p->rchild; 
				S[++top] = p;
				//继续访问p的左子树 
				p = p->lchild;
			}
			else {	//右子树不存在或已经访问过
				p = S[top--];	//出栈 
				printf("%d ",p->data);	//访问节点 
				r = p;		//标记上次访问节点 
				p = NULL;	//将p置空，进入下一次循环 
			}
		}
		 
	}

}

int GetDepth(BiTree B)	//非递归求树高
{
	BiNode *p = B;
	BiNode *Q[100];
	int front = -1,rear = -1;
	int last = 0,depth = 0;
	
	if(!p)
		return depth;
	Q[++rear] = p;
	
	while(front < rear)	//p非空或队列不为空
	{
		p = Q[++front];	//出队
		
		if(p->lchild)
			Q[++rear] = p->lchild;
		if(p->rchild)
			Q[++rear] = p->rchild;
		
		if(front == last){
			depth++;
			last = rear;
		} 

	 }
	return depth; 
}
int Get_Depth(BiTree B)	//递归求树高
{
	int ldepth;
	int rdepth;
	
	if(!B)
		return 0;
	ldepth = Get_Depth(B->lchild);
	rdepth = Get_Depth(B->rchild);
	return ldepth>rdepth?ldepth + 1:rdepth + 1;
}
