#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<queue>
using namespace std;

typedef int WeightType;//�ߵ�Ȩֵ����
typedef char DataType;//������Ϣ����

#define INFINITY 0x3f3f3f3f
#define MaxVertexNum 100


//���ݷ�װ
typedef struct GNode
{
	WeightType G[MaxVertexNum][MaxVertexNum];//����Ϣ���ڽӾ���
	DataType Data[MaxVertexNum];//������Ϣ
	int Nv;//������
	int Ne;//����
}GNode, *MGraph, *PtrToGNode;
int visited[MaxVertexNum]={0};
//����

//�̲�226ҳ
//����6.15
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

//������ȱ������ǵݹ飩
//��v�������������ȱ���ͼG���ǵݹ�
void DFS_stack(MGraph G, int v)
{
	int w;
	int s[MaxVertexNum];
	int top=-1;//ջ��
	int visited[MaxVertexNum]={0};//0δ�����ʣ�1�ѱ�����
	//����v
	printf("%c ", G->Data[v]);
	//��ʶv�Ѿ�������
	visited[v]=1;
	//v��ջ
	top++;
	s[top]=v;
	//ѭ����ջ��Ϊ�գ�
	while(top!=-1){
		//ȡջ����������ջ��������v
		v=s[top];
		//ȡv��һ��δ�����ʵ��ڽӶ���w
		int eixst=0;//������
		for(w=0;w<G->Nv;w++){
			if(G->G[v][w] >0 && G->G[v][w] < INFINITY && visited[w]==0){
				eixst=1;//�ҵ�v��δ�����ʵ��ڽӶ���w
				break;
			}
		}
		//���w����
		if( eixst==1 ){
			//����w
			printf("%c ", G->Data[w]);
			//��ʶw�ѱ�����
			visited[w]=1;
			//w��ջ
			top++;
			s[top]=w;
		}else{
			//���w������
			//��ջ
			top--;
		}
	}
	printf("\n");
}

//������ȱ������ݹ飩
//��v�������������ȱ���ͼG
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


//������ȱ���
//��v�������������ȱ���ͼG
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


//���� 
void test()
{
	MGraph G = example6_15();
	DFS_stack( G, 0);
	DFS(G,0);
	BFS(G,0);
	//printCom(G);
}



//���
int main()
{
	test();
	return 0;
}
