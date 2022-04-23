#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef struct AVLNode* Tree;
typedef struct AVLNode{
    int data;
    Tree left;
    Tree right;
    int height;
}Node;
int Max(int a,int b){
    return a>b ? a : b;
}
int getheight(Tree T){
    if(T)
        return T->height;
    else return -1;
}
Tree LLRotation(Tree A){
    Tree B=A->left;
    A->left=B->right;
    B->right=A;
    A->height = Max(getheight(A->left),getheight(A->right)) + 1;
	B->height = Max(getheight(B->left),A->height) + 1;
    return B;
}
Tree RRRotation(Tree A){
    Tree B=A->right;
    A->right=B->left;
    B->left=A;
    A->height=Max(getheight(A->left),getheight(A->right))+1;
    B->height=Max(getheight(B->left),A->height)+1;
    return B;
}
Tree RLRotation(Tree A){
    Tree B=A->right;
    A->right=LLRotation(B);
//     A->right=LLRotation(A->right);
    return RRRotation(A);
}
Tree LRRotation(Tree A){
    A->left=RRRotation(A->left);
    return LLRotation(A);
}
Tree Insert(Tree T,int data){
    if(NULL==T){
        T = new Node;
		T->data = data;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
    }else{
        if(data < T->data){//节点数比根节点小，往左边插入
            T->left=Insert(T->left,data);
            if(getheight(T->left)-getheight(T->right)==2){//平衡性被破坏
                if(data<T->left->data)//在左子树的左边，LL单旋
                    T=LLRotation(T);
                else if(T->left->data<data)//左子树的右边，LR双旋
                    T=LRRotation(T);
            }
        }
        else if(data > T->data){//节点数比根节点大，往右边插入
            T->right=Insert(T->right,data);
            if(getheight(T->right)-getheight(T->left)==2){//平衡性被破坏
                if(data<T->right->data)//破坏节点在右子树左边，RL双旋
                    T=RLRotation(T);
                else if(data>T->right->data)//破坏节点在右子树右边，RR单旋
                    T=RRRotation(T);
            }
        }
    }
    T->height=Max(getheight(T->left),getheight(T->right))+1;//更新树高
    return T;
}
int main()
{
    int N,data;
    cin>>N;
    Tree T=NULL;
    for(int i=0;i<N;i++){
        cin>>data;
        T=Insert(T,data);
    }
    cout<<T->data<<endl;
}
