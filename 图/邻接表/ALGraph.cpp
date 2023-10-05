#include<stdio.h>
#include<stdlib.h>

#define MaxNum 100

typedef int Elemtype;

bool visited[MaxNum];		//访问标记数组 

typedef struct ArcNode{		//边表结点 
	int adjvex;				//该弧所指向的顶点位置
	struct ArcNode *next;	//指向下一条弧的指针
	//int Info  			//权值	
}ArcNode;

typedef struct VNode{		//顶点表 
	Elemtype data;			//顶点信息
	ArcNode *first;			//指向第一个与该顶点相连的顶点指针 
}VNode,AdjList[MaxNum];	

typedef struct{				//邻接表 
	AdjList vertices;		//图的顶点表
	int vexnum,arcnum;		//图的顶点数和弧数 
}ALGraph;

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front,*rear;
}LinkQueue;





bool Init_Graph(ALGraph &G);	//初始化图 
bool Insert(ALGraph &G,Elemtype x);	//插入顶点 
int Search_Graph(ALGraph G,Elemtype x);		//查找图中是否存在x顶点
bool Creat_Graph(ALGraph &G);		//创建邻接表 
void print_Graph(ALGraph G);	//按照邻接表的物理结构打印当前图 
bool Insert_Edge(ALGraph &G,Elemtype x,Elemtype y);	//插入与x,y相连的边
void BFSTraverse(ALGraph G);		//对图G进行广度优先搜索遍历 
void BFS(ALGraph G,Elemtype v,LinkQueue &Q);	//从v顶点出发，广度优先搜索遍历
void DFS_Judge_Circle(ALGraph G);		//深度优先搜索判断是否存在回路 

bool InitQueue(LinkQueue &Q);	//初始化队列
bool IsEmpty(LinkQueue &Q);		//判空 
bool EnQueue(LinkQueue &Q,Elemtype x);	//入队 
int PopQueue(LinkQueue &Q);	//出队 


int main(){
	ALGraph G;
	if(!Init_Graph(G)){
		printf("初始化失败!\n");
		return 0;
	}
	
	printf("初始化成功!\n");
	
	
	Creat_Graph(G);
	
	BFSTraverse(G);
	
	
	print_Graph(G);
	return 0;
} 

bool Init_Graph(ALGraph &G)		//初始化图
{
	for(int i = 1;i <= MaxNum;i++)
	{
		G.vertices[i].data=0;
		G.vertices[i].first = (ArcNode *)malloc(sizeof(ArcNode));
		G.vertices[i].first->next = NULL;
	}
	G.arcnum = G.vexnum = 0;
	return true;
}

bool Insert(ALGraph &G,Elemtype x)	//插入顶点 
{
	if(G.vexnum == MaxNum){
		printf("图已满，插入失败!");
		return false;
	}
	
	Elemtype temp;
	int j;
	
	
	G.vexnum++;
	G.vertices[G.vexnum].data=x;	//赋值 
	ArcNode *S = G.vertices[G.vexnum].first;
	
	while(S->next != NULL){		//找到最后一个指针结点 
			S = S->next;
	}
	
	printf("请输入与%c点相连接的顶点:",x);
	scanf("%c%*c",&temp);

	while(temp != 'z'){
		j = Search_Graph(G,temp);
		printf("j = %d\n",j);
		if(j > MaxNum){
			printf("图中没有此顶点！");
			return false;
		}
		
		else if(temp == x){
			printf("禁止与当前结点相连！\n");
			return 0;
		}
		
		ArcNode *A = (ArcNode *)malloc(sizeof(ArcNode));
		A->adjvex=j;
		
		A->next =S->next;
		S->next = A; 
		
		G.arcnum++;	
		
		printf("请输入下一个与%c点相连接的顶点:",x);
		scanf("%c%*c",&temp);
	} 
	
	return true; 
} 

int Search_Graph(ALGraph G,Elemtype x)		//查找图中是否存在x顶点
{
	for(int i = 1;i<=G.vexnum;i++){
		if(x == G.vertices[i].data)
			return i;
	}
	return MaxNum+1;
}
void print_Graph(ALGraph G)	//按照邻接表的物理结构打印当前图 
{
	ArcNode *S;
	printf("顶点 \n");
	for(int i = 1;i <= G.vexnum;i++){
		printf(" %c ->",G.vertices[i].data);
		S = G.vertices[i].first->next;
		while(S != NULL){
			//printf("%d",S->adjvex);
			printf("%c",G.vertices[S->adjvex].data);
			printf("->");
			S=S->next;
		}
		printf("NULL\n");
	}
}

bool Creat_Graph(ALGraph &G)		//创建邻接表 
{
	int x,y;
	//创建无向图 
	Elemtype data[MaxNum]={'a','b','c','d','e'};	//顶点表
	//关系表 
	Elemtype Edge[MaxNum*2][2]={{'a','b'},{'a','c'},{'b','d'},{'d','c'},{'c','e'},};
	
	for(int i = 0;i <= MaxNum;i++){	//插入顶点 
		if(data[i] == NULL)
			break;
		G.vertices[i+1].data = data[i];
		G.vexnum++;
		printf("%c ",G.vertices[i+1].data);
	}
	
	
	printf("\n");
	
	for(int i = 0;i <= MaxNum;i++){	//插入关系 
		if(Edge[i][0] == NULL){
			break;
		}
	
		
	//插入关系 
	Insert_Edge(G,Edge[i][0],Edge[i][1]);
	Insert_Edge(G,Edge[i][1],Edge[i][0]);
	}

	
}

bool Insert_Edge(ALGraph &G,Elemtype x,Elemtype y)	//插入与x,y相连的边
{
	int i,j;
	i=Search_Graph(G,x);	//获取边上两个顶点在表中的位置 
	j=Search_Graph(G,y);
	
	ArcNode *S=G.vertices[i].first;
	
	ArcNode *A=(ArcNode *)malloc(sizeof(ArcNode));
	
	A->adjvex = j;
	A->next = S->next;
	S->next = A;
	G.arcnum++;
	
} 


void BFSTraverse(ALGraph G)		//对图G进行广度优先搜索遍历 
{
	LinkQueue Q;
	for(int i = 1;i <= G.vexnum;i++){
		visited[i] = false;
	}
	
	InitQueue(Q);	//初始化队列 
	for(int i = 1;i <= G.vexnum;i++){
		if(!visited[i]){
			BFS(G,G.vertices[i].data,Q);
		}
	} 
} 

void BFS(ALGraph G,Elemtype v,LinkQueue &Q)	//从v顶点出发，广度优先搜索遍历
{
	int j;
	ArcNode *S;
	int i = Search_Graph(G,v);
	
	printf("%c ",G.vertices[i].data);
	visited[i] = true;
	
	
	EnQueue(Q,i);	//将v传入队列 
	
	while(!IsEmpty(Q)){
		j = PopQueue(Q);	//出队，并获取出队的值 
		S= G.vertices[j].first->next;	//获取出队数据在图中的指针 
		while(S != NULL){
			if(!visited[S->adjvex]){
				EnQueue(Q,S->adjvex);
				printf("%c ",G.vertices[S->adjvex].data);
				visited[S->adjvex] = true;
			}//if
			S = S->next; 
			
		} 
	}
	printf("\n");
} 















bool InitQueue(LinkQueue &Q){	//初始化队列 
	Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
} 
bool IsEmpty(LinkQueue &Q){		//判空 
	if(Q.front==Q.rear){
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

int PopQueue(LinkQueue &Q)		//出队
{
	int x;
	if(IsEmpty(Q)){
		return false;
	}
	LinkNode *p=Q.front->next;
	x = p->data;
	Q.front->next=p->next; 
	if(p==Q.rear){
		Q.front=Q.rear;
	}
	free(p);
	return x;
} 

void DFS_Judge_Circle(ALGraph G)		//深度优先搜索判断是否存在回路 
{
	visited[MaxNum] = false; 
	int S[MaxNum];	//栈，用于存储顶点信息，进行遍历
	int top = 0;//栈顶指针 
	VNode p = G.vertices[0];//从第一个顶点开始遍历 
	if(p == NULL){
		return 0;
	}
	
	
	while(p != NULL || top > 0){
		if(p != NULL){
			S[++top] = p->data;	//将节点信息存入栈中 
			p=p.first->next; 
		}
		else{
			p = S[top--];
			if(visited[p->data] == true)
				return false;
			
		}
	}
}
