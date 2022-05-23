#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
#define MAXV 10
typedef int Vertex;
typedef struct Graph{
    int Ne;//顶点数
    int Nv;//边数
    Vertex G[MAXV][MAXV];
}Graph,*Gra;
int visited[MAXV]={0};
Gra buildGraph(){
    Gra graph=new Graph;
    int N,E;
    int v1,v2;
    cin>>N>>E;
    graph->Ne=N;
    graph->Nv=E;
    for(int i=0;i<graph->Ne;i++){
        visited[i]=0;//初始化访问数组
        for(int j=0;j<N;j++)
            graph->G[i][j]=0;
    }
    for(int i=0;i<E;i++){
        cin>>v1>>v2;
        graph->G[v1][v2]=1;
        graph->G[v2][v1]=1;
    }
    return graph;
}
void DFS(Gra graph,Vertex v){
    visited[v]=1;
    cout<<" "<<v;
    for(int i=0;i<graph->Ne;i++){
        if(graph->G[v][i]==1 && visited[i]==0)
            DFS(graph,i);
    }
}
void BFS(Gra graph,Vertex v){
    queue<Vertex> q;
	// 改变状态 
	visited[v] = 1;
	cout<<" "<<v;
    q.push(v);
    Vertex temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(int i=0;i<graph->Ne;i++){
            if(graph->G[temp][i]==1 && visited[i]==0){
                visited[i]=1;
                cout<<" "<<i;
                q.push(i);
            }
        }
    }
}
void printComp(Gra graph){
    for(int i=0;i<graph->Ne;i++){
        if(visited[i]==0){
            cout<<"{";
            DFS(graph,i);
            cout<<" }"<<endl;
        }
    }
    for(int i=0;i<MAXV;i++)
        visited[i]=0;
    for(int i=0;i<graph->Ne;i++){
        if(visited[i]==0){
			cout<<"{";
			BFS(graph,i);
			cout<<" }"<<endl;
		}
    }
}
int main(){
    Gra graph=buildGraph();
    printComp(graph);
    return 0;
}
  
