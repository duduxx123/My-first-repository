# 使用c++编写
``` C++
#include<iostream>
using namespace std;
#define maxsize 1000
typedef struct Node{
    int top;
    int data[maxsize];
    int large;
}*stack;
int IsPopPossible(int Arry[],int M,int N);
int main()
{
    int M,N,K;
    int i,j;
    cin>>M>>N>>K;
    int arr[maxsize];
    for(i=0;i<K;i++){
        for(j=0;j<N;j++)
            cin>>arr[j];//读入一串数列
        if(IsPopPossible(arr,M,N))//非零时表示可能存在 
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
    }
    return 0;
}
int IsPopPossible(int Arry[],int M,int N)
{
    int i;
    int cout=0;
    stack Pile=new struct Node;
    Pile->large=M;
    Pile->top=-1;
    for(i=1;i<=N;i++){
        if(Pile->large==Pile->top+1)
            return 0;
        else
            Pile->data[++Pile->top]=i;
        while(Arry[cout]==Pile->data[Pile->top]){
            Pile->top--;
            cout++;
        }
    }
    if(cout==N)
        return 1;
    else return 0;
}

```
