#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 11


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
int GetWidth(BiTree B);		//求树宽 
int Get_Total(BiTree B);	//计算树的节点数 
void Find_Ancestor(BiTree B,int x,BiNode *S[]);	//寻找 data=x节点的祖先 (普通二叉树查找x的路径)
BiNode *Find_Parent(BiTree B,int x);	//寻找x节点的祖先 
bool Judge_Same(BiTree A,BiTree B);		//判断两颗二叉树是否相同 
void Order(BiTree B);	//非递归遍历二叉树  


/**********************
		二叉树结构 
			   50
		    /     \
		   30      70
		  / \     /  \
 		 20 36   63  76
 		   / \   /    \
 		  31 40 72     80
*********************/






int main(){
	int x[MAXSIZE]={50,30,70,20,36,63,76,31,40,72,80};
	int x2[MAXSIZE]={50,30,70,20,36,63,76,31,40,72,80};
	BiNode *Stack[100];	//非递归遍历栈 
	BiTree B;
	BiTree A;
	BiNode *S;
	BiNode *s;
	int i=1;
	int depth;
	
	int data = 100;
	
	BST_Creat(B,x,MAXSIZE);
	BST_Creat(A,x2,MAXSIZE);
	
	
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
	printf("非递归："); 
	Order(B);
	printf("\n");
	
//	printf("非递归二叉树高为：%d\n",GetDepth(B));
//	printf("二叉树宽为：%d\n",GetWidth(B));
//	printf("二叉树的总结点数为%d\n",Get_Total(B));
//	Order(B);
//	printf("\n");
//	

/********************************
	寻找所有祖先节点（寻找路径） 
********************************/
//	Find_Ancestor(B,80,Stack);

/*****************************
		寻找父亲节点 
********************************/
	if(Find_Parent(B,data))
		printf("data = %d 的父节点为：%d",data,Find_Parent(B,data)->data);
	else	
		printf("该节点不存在(或该节点为根节点)");
	return 0;

/*****************************
		判断两个二叉树是否相同。 
********************************/

//	if(Judge_Same(B,A))
//		printf("SAME\n");
//	
//	else
//		printf("NOT SAME\n"); 

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
/*
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
*/
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

int GetWidth(BiTree B)		//求树宽 
{
	BiNode *p = B;
	BiNode *Q[100];
	int front = -1,rear = -1;
	int last;
	int i = 0,max = 0;
	
	if(!p)
		return max;
	Q[++rear] = p;
	last = rear;
	
	while(front < rear)	//p非空或队列不为空
	{
		p = Q[++front];	//出队
		i++;
		if(p->lchild)
			Q[++rear] = p->lchild;
		if(p->rchild)
			Q[++rear] = p->rchild;
		
		if(front == last){
			last = rear;
			if(i > max)
				max = i;
			i = 0;
		} 

	 }
	return max; 
}

int Get_Total(BiTree B)	//计算树的节点数
{
	BiNode *p = B;
	if(!p)
		return 0;
	
	int lnum,rnum,total;
	lnum = Get_Total(p->lchild);
	rnum = Get_Total(p->rchild);
	total = lnum + rnum + 1;
	
	return total;
}

void Find_Ancestor(BiTree B,int x,BiNode *S[])	//寻找 data=x节点的祖先 
{
/*	int top = 0;
	BiNode *r = NULL;
	int test = 0;
	BiNode *p = B;
	while(p != NULL || top > 0){
		test++;
		if(p != NULL){
			if(p->data == x){
				printf("top = %d\n",top); 
				break;	//找到该节点，退出循环 
			}
			S[++top] = p;
			p = p->lchild;
			
		}
		
		else {	//该节点为空
			p = S[top];		//读取栈顶元素
			if(p->rchild != NULL && p->rchild != r)	{//右子树存在且没有被访问过 
				p=p->rchild;
				if(p->data == x){		//检查该节点是否为x节点 
					printf("top = %d\n",top); 
					break;
				}
				S[++top] = p;
				p = p->lchild;
			}
			
			else{	//右子树不存在或被访问过
				p = S[top--];
				r = p;
				p = NULL;	
				 //标记上次访问过的节点，进入下次循环 
			}
			
		}
	}
	
*/	
	
	
//	printf("test = %d\n",test);
//	for(int i = 1;i<=top;i++){
//		p = S[i];
//		printf("%d  ",p->data);	//自栈低向栈顶打印栈 
//	}
//	printf("\n"); 



}

BiNode *Find_Parent(BiTree B,int x) //寻找data = x节点的父节点
{
/*	BiTree S[MAXSIZE];
	int top = 0;
	BiNode *p = B;
	BiNode *r = NULL;
	int i = 0;
	if(!p){	//空树或x节点为根节点 
		return NULL;
	}
	
	while(top > 0 || p){
		if(p){
			S[++top] = p;
			if(p->lchild && p->lchild->data == x)
				return p;
			if(p->rchild && p->rchild->data == x)
				return p;
			p = p->lchild;
		}
		else{
			p = S[top];	//读取栈顶元素
			if(p->rchild && p->rchild != r){
				p = p->rchild;
				if(p->lchild && p->lchild->data == x)
					return p;
				if(p->rchild && p->rchild->data == x)
					return p;
				S[++top] = p;
				p = p->rchild;
			} 
			else{
				p = S[top--];
				//visite(p);
				r = p;
				p = NULL;
			}
		}
	}
	
	return NULL;
	
	*/
	
	if(!B)
		return NULL;
		
	BiNode *left,*right;
	
	if(B->lchild && B->lchild->data == x)
		return B;
	
	else if(B->rchild && B->rchild->data == x)
		return B; 
	
	left = Find_Parent(B->lchild,x);
    right = Find_Parent(B->rchild,x);
	
	if(left)
		return left;
	else if(right)
		return right;
	

}


bool Judge_Same(BiTree A,BiTree B)		//判断两颗二叉树是否相同
{
	
	if(!A && !B)	//A,B 均为空 
		return true;
		
	if(A == NULL || B == NULL)	//A或B为空 
		return false;
		
	if(A->data != B->data)	//A，B节点值不相同 
		return false;
		
	bool pl,pr;
	
	pl = Judge_Same(A->lchild,B->lchild);
	pr = Judge_Same(A->rchild,B->rchild);
	return pl&&pr; 		

}
