#include<stdio.h>
#include <stdlib.h>

typedef struct AVL_Node{
	int data;
	struct AVL_Node *lchild,*rchild;
	int balance;
}AVL_Node,*AVL_Tree;

AVL_Node *father;	//定义一个父结点，用于删除数据时定位父结点 

bool InitTree(AVL_Tree &T);		//初始化平衡二叉树 
int Get_High(AVL_Tree T);	//计算二叉树的高度 
bool Insert(AVL_Tree &T,int data);	//插入数据 
AVL_Node *Left_Left(AVL_Tree &T);	//ll情况最小失衡树的左子树右旋一次 
AVL_Node *Left_Right(AVL_Tree &T);	//LR,将最小失衡树A的左子树B的右子树C结点，先向左旋再向右旋转一次 
AVL_Node *Right_Right(AVL_Tree &T);	//RR,最小失衡树的右子树左旋一次
AVL_Node *Right_Left(AVL_Tree &T);	//RL,将最小失衡树A的右子树B的左子树C结点，先右旋，再左旋 
bool creat(AVL_Tree &T,int x[],int n);	//创建平衡二叉树 
void InOrder(AVL_Tree T);	//中序遍历平衡二叉树 
AVL_Node *AVL_Search(AVL_Tree B,int x);	//平衡树的查找
AVL_Node *AVL_Delete(AVL_Tree &T,int x);	//平衡树的删除 


int main(){
	AVL_Tree T;
	int x[10]={5,10,12,25,35,40,50,60,63,90};
	InitTree(T);
	
	creat(T,x,10);
	InOrder(T);
	printf("\nTree High:%d\n",Get_High(T));
	return 0;
} 

bool InitTree(AVL_Tree &T)		//初始化平衡二叉树 
{
	T=NULL; 
} 
int Get_High(AVL_Tree T)	//计算二叉树的高度 
{
	int MAXH,LH,RH;
	if(T != NULL){
		LH=Get_High(T->lchild);
		RH=Get_High(T->rchild);
		MAXH=LH > RH ? LH : RH;
		return MAXH+1;
	}
	else return 0;

}

bool Insert(AVL_Tree &T,int x)	//插入数据 
{
	if(T == NULL){
		T = (AVL_Node *)malloc(sizeof(AVL_Node));
		T->lchild=T->rchild=NULL;
		T->data = x;
	}
	
	else if(x > T->data){ 
		Insert(T->rchild,x);//递归插入，并在递归完后重新计算该路径中所有节点的balance平衡因子
		T->balance = Get_High(T->lchild)-Get_High(T->rchild);
		if(T->balance == 2 || T->balance == -2){	//如果T是否为最小失衡树 
			if(T->rchild->balance == 1){	//判断 T的情况需要哪种旋转 
				T=Right_Left(T);				//当balance为1时，证明新数据插如入在T的右子树的左子树上 
			}
			
			else if(T->rchild->balance == -1){//balance为-1时，证明新数据插如入在T的右子树的右子树上
				T=Right_Right(T);
			}
		} 
	}
	else if(x < T->data)
	{
		Insert(T->lchild,x);	//递归插入，并在递归完后重新计算balance平衡因子 
		T->balance = Get_High(T->lchild)-Get_High(T->rchild); 
		
		if(T->balance == 2 || T->balance == -2){
			
			if(T->lchild->balance == 1){
				T=Left_Left(T);
			}
			
			if(T->lchild->balance == -1){
				T=Left_Right(T);
			}
			
		}
	}
		
} 


AVL_Node *Left_Left(AVL_Tree &T)		//ll情况最小失衡树左子树右旋一次 
{
	AVL_Node *K;
	K=T->lchild;
	T->lchild = K->rchild;
	K->rchild = T;
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	K->balance = Get_High(K->lchild)- Get_High(K->rchild);
	return K;
} 

AVL_Node *Left_Right(AVL_Tree &T)	
{//LR,将最小失衡树A的左子树B的右子树C结点，先向左旋再向右旋转一次 

	AVL_Node *k,*m;
	k=T->lchild->rchild;
	m=T->lchild;
	
	//1.先左旋一次
	m->rchild = k->lchild;
	T->lchild = k;	
	k->lchild = m;
	
	//2. 再右旋一次 
	T->lchild = k->rchild;
	k->rchild = T; 
 
 
 	//重新计算balance平衡因子
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	m->balance = Get_High(m->lchild)- Get_High(m->rchild);
	return k;
} 
AVL_Node *Right_Right(AVL_Tree &T)	//RR,最小失衡树的右子树左旋一次
{
	AVL_Node *k;
	k=T->rchild;
	T->rchild = k->lchild;
	k->lchild = T; 
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	return k;
} 

AVL_Node *Right_Left(AVL_Tree &T)	//RL,将最小失衡树A的右子树B的左子树C结点，先右旋，再左旋
{
	printf("4\n");
	AVL_Node *k,*m;
	m=T->rchild;
	k=m->lchild;
	
	//右旋
	m->lchild = k->rchild;
	T->rchild = k;
	k->rchild = m;
	
	//左旋
	T->rchild = k->lchild;
	k->lchild = T;
	
	//重新计算balance平衡因子 
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
	m->balance = Get_High(m->lchild)- Get_High(m->rchild);
	return k;
} 

bool creat(AVL_Tree &T,int x[],int n)	//创建平衡二叉树 
{
	for(int i=0;i<n;i++){
		Insert(T,x[i]);
	} 
	return true; 
} 

void InOrder(AVL_Tree T)	//中序遍历平衡二叉树 
{
	if(T != NULL){
		InOrder(T->lchild);
		printf("%d  ",T->data);
		InOrder(T->rchild);
	}
} 
AVL_Node *AVL_Search(AVL_Tree B,int x)	//排序树的查找 
{
	while(B != NULL && B->data != x){
		if(B->data > x){
			B=B->lchild;
		}
		if(B->data < x){
			B=B->rchild;
		}
	} 
	return B;
} 

AVL_Node *AVL_Delete(AVL_Tree &T,int x)	//平衡树的删除 
{
	/*
	共4种情况： 
	1. 删除叶子结点
	2.删除的结点有左子树
	3.删除的结点有右子树
	4.删除的结点有两个子树 
	*/ 
	
	if(T->data == x)
	{
		if()
	}
	if(x>T->data){
		AVL_Delete(T->rchild,x);	
		
	} 
} 
