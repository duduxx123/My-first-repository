#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<queue>
using namespace std;

typedef int WeightType;//边的权值类型
typedef char DataType;//顶点信息类型

#define INFINITY 0x3f3f3f3f
#define MaxVertexNum 100


//数据封装
typedef struct GNode
{
	WeightType G[MaxVertexNum][MaxVertexNum];//边信息（邻接矩阵）
	DataType Data[MaxVertexNum];//顶点信息
	int Nv;//顶点数
	int Ne;//边数
}GNode, *MGraph, *PtrToGNode;
int visited[MaxVertexNum]={0};
//操作

//教材226页
//例题6.15
MGraph example6_15()
{
	int i;
	int j;
	MGraph M=(MGraph)malloc(sizeof(GNode));
	M->Nv=10;
	M->Ne=17;
	memcpy(M->Data,"ZBWXDLHYFC",10);
	WeightType G[10][10]={
		/*0*/{0, 8, 5, INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
		/*1*/{8, 0, 5, INFINITY,5,4,INFINITY,INFINITY,INFINITY,INFINITY},
		/*2*/{5,5,0,8,INFINITY,INFINITY,4,INFINITY,INFINITY,INFINITY},
		/*3*/{INFINITY,INFINITY,8,0,INFINITY,INFINITY,7,5,INFINITY,INFINITY},
		/*4*/{INFINITY,5,INFINITY,INFINITY,0,4,INFINITY,INFINITY,INFINITY,INFINITY},
		/*5*/{INFINITY,4,INFINITY,INFINITY,4,0,4,INFINITY,2,INFINITY},
		/*6*/{INFINITY,INFINITY,4,7,INFINITY,4,0,5,3,6},
		/*7*/{INFINITY,INFINITY,INFINITY,5,INFINITY,INFINITY,5,0,INFINITY,6},
		/*8*/{INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,2,3,INFINITY,0,7},
		/*9*/{INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,6,6,7,0}
	};
	//WeightType G[10][10]={INFINITY};
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			M->G[i][j]=G[i][j];
	return M;
}

//深度优先遍历（非递归）
//从v顶点出发深度优先遍历图G，非递归
void DFS_stack(MGraph G, int v)
{
	int w;
	int s[MaxVertexNum];
	int top=-1;//栈顶
	int visited[MaxVertexNum]={0};//0未被访问，1已被访问
	//访问v
	printf("%c ", G->Data[v]);
	//标识v已经被访问
	visited[v]=1;
	//v入栈
	top++;
	s[top]=v;
	//循环（栈不为空）
	while(top!=-1){
		//取栈顶，（不出栈），付给v
		v=s[top];
		//取v的一个未被访问的邻接顶点w
		int eixst=0;//不存在
		for(w=0;w<G->Nv;w++){
			if(G->G[v][w] >0 && G->G[v][w] < INFINITY && visited[w]==0){
				eixst=1;//找到v的未被访问的邻接顶点w
				break;
			}
		}
		//如果w存在
		if( eixst==1 ){
			//访问w
			printf("%c ", G->Data[w]);
			//标识w已被访问
			visited[w]=1;
			//w入栈
			top++;
			s[top]=w;
		}else{
			//如果w不存在
			//出栈
			top--;
		}
	}
	printf("\n");
}

//深度优先遍历（递归）
//从v顶点出发深度优先遍历图G
void DFS(MGraph G, int v)
{
	if(visited[v]==0){
		visited[v]=1;
		printf("%c ",G->Data[v]);
		for(int i=0;i<G->Nv;i++){
			if(G->G[v][i]>0 && G->G[v][i]<INFINITY)
				DFS(G,i);
		}
	}
}


//广度优先遍历
//从v顶点出发广度优先遍历图G
void BFS(MGraph G, int v)
{
	printf("\n");
	for(int i=0;i<MaxVertexNum;i++)
		visited[i]=0;
	queue<int> q;
	visited[v]=1;
	printf("%c ",G->Data[v]);
	q.push(v);
	int idx;
	while(!q.empty()){
		idx=q.front();
		q.pop();
		for(int i=0;i<G->Nv;i++){
			if(G->G[idx][i]>0 && G->G[idx][i]<INFINITY && visited[i]==0){
				visited[i]=1;
				printf("%c ",G->Data[i]);
				q.push(i);
			}
		}
	}
}
void printCom(MGraph G){
	for(int i=0;i<G->Nv;i++)
		visited[i]=0;
	for(int i=0;i<G->Nv;i++){
		printf("{");
		DFS(G,i);
		printf("}");
		printf("\n");
	}
}


//测试 
void test()
{
	MGraph G = example6_15();
	DFS_stack( G, 0);
	DFS(G,0);
	BFS(G,0);
	//printCom(G);
}



//入口
int main()
{
	test();
	return 0;
}
