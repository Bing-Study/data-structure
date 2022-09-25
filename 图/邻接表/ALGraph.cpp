#include<stdio.h>
#include<stdlib.h>

#define MaxNum 100

typedef int Elemtype;


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

bool Init_Graph(ALGraph &G);	//初始化图 
bool Insert(ALGraph &G,Elemtype x);	//插入顶点 
int Search_Graph(ALGraph G,Elemtype x);		//查找图中是否存在x顶点
bool creat_Graph(ALGraph &G);		//创建邻接表 
void print_Graph(ALGraph G);	//按照邻接表的物理结构打印当前图 

int main(){
	ALGraph G;
	if(!Init_Graph(G)){
		printf("初始化失败!\n");
		return 0;
	}
	
	printf("初始化成功!\n");
	
	
	for(int j = 1;j <= 3;j++)
		Insert(G,j+96);
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
		printf("  %d  \n",G.vertices[G.vexnum].first->next->adjvex);
		if(G.vertices[G.vexnum].first->next->next != NULL){
			printf("  %d  \n",G.vertices[G.vexnum].first->next->next->adjvex);
		}
		
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

bool creat_Graph(ALGraph &G)		//创建邻接表 
{
	
}
