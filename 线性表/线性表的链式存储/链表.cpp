#include<stdio.h>
#include<stdlib.h>

#define maxsize 20


typedef int Elemtype;

typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode,*LinkList;

bool InitLink(LinkList &L);	//初始化链表 
bool InitNHLink(LinkList &L);//初始化无头节点链表 
LinkList List_HeadInsert(LinkList &L);//前插法创建链表 
LinkList List_TailInsert(LinkList &L);//后插法创建链表 
bool List_NoHInsert(LinkList &L); //无头节点创建链表 
void printList(LinkList L);	//打印链表 
Elemtype GetELem(LinkList L,int number);//按序号查找 
Elemtype LocatElem(LinkList L,Elemtype x);//按数值查找并返回数据所在位置 
bool InsertELem(LinkList &L,Elemtype data,int number);//插入 
void DeletElem(LinkList &L,Elemtype x);//删除 
LNode *print_T_List(LinkList L);	//将链表逆序输出 
bool Delet_M_Elem(LinkList &L);		//删除最小节点(假设节点唯一) 
bool reverseLink(LinkList &L);	//将链表反向，要求：不能使用辅助进空间 

int main(){
	LinkList L;
	int number,x;	//x:获取数据  number：获取位置 
//	InitNHLink(L);
	if(InitLink(L)){
		printf("Init Link success!\n");
	}
	else{
		printf("Init Link failed!\n");
		exit(0);
	}
//	List_HeadInsert(L);		//头插法创建链表
	List_TailInsert(L);		//尾插法创建链表 
	printList(L);			//打印链表 
//	List_NoHInsert(L);		//创建无头节点链表	
	//按序号查找
//	printf("input the number:");
//	scanf("%d",&number); 
//	x=GetELem(L,number);


	//按数值查找并返回数据位置 
//	printf("input the data:");
//	scanf("%d",&x);
//	number=LocatElem(L,x);
//	printf("Number:%d\n",number); 


//	插入数据
//	printList(L);
//	printf("Input your data and number:");
//	scanf("%d%d",&x,&number);
//	InsertELem(L,x,number);

//	删除数据
//	printf("Input you want detet data:");
//	scanf("%d",&x);
//	DeletElem(L,x);

//	将链表逆序输出 
//	LNode *p=L->next;
//	printf("\n");
//	print_T_List(p);	


//	删除链表中的最小值(假设最小值唯一)
//	时间复杂度为O(n),空间复杂度为O(1)
	Delet_M_Elem(L);
	printList(L); 

//将链表逆置,要求:不使用辅助空间 
	reverseLink(L);
	
	printList(L); 
	return 0;
} 

bool InitLink(LinkList &L){
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL; 
	if(L->next==NULL)
		return  true;
	return false;
}

bool InitNHLink(LinkList &L){
	L=NULL;
	return true;
} 
LinkList List_HeadInsert(LinkList &L){
	LNode *S;
	int x;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		S=(LNode *)malloc(sizeof(LNode));
		S->data=x;
		S->next=L->next;
		L->next=S;	
		printf("Input your data:");
		scanf("%d",&x);
	}
	return L;
} 

LinkList List_TailInsert(LinkList &L){
	LNode *s,*r;
	int x;
	r=L;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);	
	}
	r->next=NULL;
	
	return L; 
} 

void printList(LinkList L){
	LNode *S=L->next;
	printf("\n");
	while(S){
		printf("%d   ",S->data);
		S=S->next;
	}
} 
Elemtype GetELem(LinkList L,int number){	//按序号查找 
	LNode *p=L->next;
	int i=1;
	if(!p){
		printf("The list is NULL!\n");
		return 0;
	} 

	while(p){
		if(i==number){
			printf("%d\n",p->data);
			return p->data;
		}
		p=p->next;
		i++;
	}
	return 0;
} 
Elemtype LocatElem(LinkList L,Elemtype x){
	LNode *p=L->next;
	int i=1;
	if(!p){
		printf("The list dont have this data!");
		return NULL;
	} 
	
	while(p){
		if(p->data==x){
			printf("data:%d\n",p->data); 
			return i;
		}
			
		i++;
		p=p->next;
	}
	return NULL;
} 

bool InsertELem(LinkList &L,Elemtype data,int number){		//插入到第number个位置
	LNode *P=L,*S;
	int i=1;
	while(P){
		if(i==number){
			S=(LNode *)malloc(sizeof(LNode));
			S->data=data;
			S->next=P->next;
			P->next=S;
			printf("Insert data success!\n"); 
			return true;
		}
		i++;
		P=P->next;
	} 
	return false;
} 

void DeletElem(LinkList &L,Elemtype x){
	LNode *s=L->next;
	LNode *r=L;
	int i=1;
	if(!s){
		printf("The list is NULL!\n");
		return;
	}
	while(s){
		if(s->data==x){
			r->next=s->next;
			free(s);
			s=r->next;
		}
		else{
			r=r->next;
			s=s->next;
		}
		
	}
}	
bool List_NoHInsert(LinkList &L){	//创建无头节点链表 
	LNode *p,*r;
	int x;
	printf("Input your data:");
	scanf("%d",&x);
	while(x!=999){
		p=(LNode *)malloc(sizeof(LNode));
		p->data=x;
		p->next=L;
		L=p;
		scanf("%d",&x);
	}
	r=L;
	while(r){
		printf("%d  ",r->data);
		r=r->next;
	}
	return true;
}

LNode *print_T_List(LinkList L){	//将链表逆序输出  采用递归思想 

	if(L->next!=NULL){
		print_T_List(L->next);
	}
	if(L->data!=NULL)
		printf("%d  ",L->data);
} 

bool Delet_M_Elem(LinkList &L){		//删除最小节点(假设节点唯一) 
	LNode *p,*prior,*r,*t;
	p = L->next;
	prior = L;
	r = p;		//r指针记录最小值节点 
	t = prior; 	//p记录最小值节点前驱 
	Elemtype temp=p->data;
	while(p){
		if(temp>p->data){
			r=p;
			t = prior; 
			temp=p->data;
		}
		prior = prior->next;
		p=p->next;
	}	//最小值节点为r,其前驱为t; 

	t->next = r->next;

	free(r);
	return true;
} 
bool reverseLink(LinkList &L)	//将链表反向，要求：不能使用辅助进空间 
{
	LNode *p=L->next,*r;
	L->next=NULL;
	int  i =0;
	while(p != NULL){
		r = p->next; 
		p->next = L->next;
		L->next = p;
		p = r;
		
	}
	return true;
} 
