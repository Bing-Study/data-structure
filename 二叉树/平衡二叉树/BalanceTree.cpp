#include<stdio.h>
#include <stdlib.h>

typedef struct AVL_Node{
	int data;
	struct AVL_Node *lchild,*rchild;
	int balance;
}AVL_Node,*AVL_Tree;

int Get_High(AVL_Tree T,int x);	//计算二叉树的高度 
bool Insert(AVL_Tree &T,int data);	//插入数据 
bool Left_Left(AVL_Tree &T);	//ll情况最小失衡树的左子树右旋一次 
bool Left_Right(AVL_Tree &T);	//LR,将最小失衡树A的左子树B的右子树C结点，先向左旋再向右旋转一次 
bool Right_Right(AVL_Tree &T);	//RR,最小失衡树的右子树左旋一次
bool Right_Left(AVL_Tree &T);	//RL,将最小失衡树A的右子树B的左子树C结点，先右旋，再左旋 
bool creat(AVL_Tree &T,int x[],int n);	//创建平衡二叉树 

int main(){
	return 0;
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
		T->lchild = T->rchild = NULL;
		T->data = x;
	}
	
	else if(x > T->data){ 
		Insert(T->rchild,x);//递归插入，并在递归完后重新计算balance平衡因子
		T->balance = Get_High(T->lchild)-Get_High(T->lchild);
		
		if(T->balance == 2 || T->balance == -2){	//如果T是否为最小失衡树 
		
			if(T->rchild->balance == 1){	//判断 T的情况需要哪种旋转 
				Right_Left(T);				//当balance为1时，证明新数据插如入在T的右子树的左子树上 
			}
			
			else if(T->rchild->balance == -1){//balance为-1时，证明新数据插如入在T的右子树的右子树上
				Right_Right(T);
			}
				
		} 
	}
	else if(x < T->data)
	{
		Insert(T->lchild,x);	//递归插入，并在递归完后重新计算balance平衡因子 
		T->balance = Get_High(T->lchild)-Get_High(T->lchild); 
		
		if(T->balance == 2 || T->balance == -2){
			
			if(T->lchild->balance == 1){
				Left_Left(T);
			}
			
			if(T->lchild->balance == -1){
				Left_Right(T);
			}
			
		}
	}
		
} 


bool Left_Left(AVL_Tree &T)		//ll情况最小失衡树左子树右旋一次 
{
	AVL_Node *K;
	K=T->lchild;
	T->lchild = K->rchild;
	K->rchild = T;
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	K->balance = Get_High(K->lchild)- Get_High(K->rchild);
	
} 

bool Left_Right(AVL_Tree &T)	
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
} 
bool Right_Right(AVL_Tree &T)	//RR,最小失衡树的右子树左旋一次
{
	AVL_Node *k;
	k=T->rchild;
	T->rchild = k->lchild;
	k->lchild = T; 
	
	T->balance = Get_High(T->lchild)- Get_High(T->rchild);
	k->balance = Get_High(k->lchild)- Get_High(k->rchild);
} 

bool Right_Left(AVL_Tree &T)	//RL,将最小失衡树A的右子树B的左子树C结点，先右旋，再左旋
{
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
} 

bool creat(AVL_Tree &T,int x[],int n)	//创建平衡二叉树 
{
	
	return true; 
} 
