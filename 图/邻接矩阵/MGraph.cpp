#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 5	//顶点数目的最大值 

typedef char VertexType;	// 顶点的数据类型 
typedef int EdgeType;		//带权图种权值的数据类型

typedef struct {
	VertexType Vex[MaxVertexNum];	//顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];	//边表
	int vexnum,arcnum; 	//当前图的顶点数和弧数 
}MGraph;

bool InitGraph(MGraph &M);	//初始化图 
bool Insert(MGraph &M,VertexType x,int type);	//插入 
bool Creat_Graph(MGraph &M);	//创建图 

int main(){
	return 0;
} 
bool InitGraph(MGraph &M)	//初始化图 
{
	for(int i = 0;i < MaxVertexNum;i++){
		M.Vex[i] = NULL;
		for(int j = 0;j < MaxVertexNum;j++){
			M.Edge[i][j] = 0;
		}
	}
	return true;
}

bool Insert(MGraph &M,VertexType x,int type)	//插入
{
	if(M.Vex[MaxVertexNum] != NULL){
		printf("图已满！\n");
		return false;
	}
	int i = 1; 
	int j = 1;	
	VertexType m;	//与新顶点有边相连的顶点
	while(M.Vex[i] != NULL){	//定位第一个没有存储顶点的位置，用于存储新顶点 
		i++;
	}	
	M.Vex[i] = x;
	switch(type){
	case 1:
		// 1.无向图
		printf("请输入该顶点边连接的顶点:");
		scanf("%c%*c",&m);
		while(m != 'z'){
			
			while(M.Vex[j] != m || j < i){	//定位顶点 
				j++;
			}
		
			if(j >= i){
				printf("图中没有此顶点!\n");
				return false;
			}
			M.Edge[i][j] = M.Edge[j][i] = 1;	//给边赋值 
			printf("请输入下一个与该顶点相连接的顶点:");
			scanf("%c%*c",&m);
		} 
		break;
		
		//有向图 
		case 2:
			printf("请输入该顶点的弧尾:");
			scanf("%c%*c",&m);
			while(m != 'z'){				
				while(M.Vex[j] != m || j < i){	//定位顶点 
					j++;
				}
				M.Edge[i][j] = 1; 		
				printf("请输入下一个该顶点的弧尾:");
				scanf("%c%*c",&m);
			} 
			
			printf("请输入以该顶点为弧尾的顶点:"); 
			scanf("%c%*c",&m);
			
			while(m != 'z'){
				while(M.Vex[j] != m || j < i){	//定位顶点 
					j++;
				}
				M.Edge[j][i] = 1; 
				printf("请输入下一个");
				scanf("%c%*c",&m);
			}
			break;
	}
} 

bool Creat_Graph(MGraph &M)	//创建图 
{
	//1.创建无向图
	VertexType x;	//新顶点 
	while(x != 'z' || M.Vex[MaxVertexNum] == NULL){
		printf("请输入新顶点的值");
		scanf("%c%*c",&x); 	
		Insert(M,x,1);
	}
	return true;
	
	return true;
} 
