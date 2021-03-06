#include<iostream>
#include<string>
using namespace std;
typedef struct treenode* Tree;
typedef struct treenode{
    int data;
    Tree left;
    Tree right;
    int flag;
}Treenode;
Tree newnode(int da){
    Tree p=new Treenode;
    p->data=da;
    p->left=NULL;
    p->right=NULL;
    p->flag=0;
    return p;
}
Tree insert(Tree T,int V){
//     if(head->data > node->data)
//         insert(node,head->right);
//     if(head->data < node->data)
//         insert(node,head->left);
    if(!T)
        T=newnode(V);
    else{
        if(V>T->data)
            T->right=insert(T->right,V);
        else
            T->left=insert(T->left,V);
    }
    return T;
}
Tree buildtree(int N){
    int data;
    Tree T;
    cin>>data;
    T=newnode(data);
    for(int i=1;i<N;i++){
        cin>>data;
        insert(T,data);
    }
    return T;
}
void Resete(Tree T){
    if(T->left)
        Resete(T->left);
    if(T->right)
        Resete(T->right);
    T->flag=0;
}
int check(Tree T,int V){
    if(T->flag){
        if(V>T->data)
            return check(T->right,V);
        if(V<T->data)
            return check(T->left,V);
        else return 0;
    }
    else{
        if(T->data==V){
            T->flag=1;
            return 1;
        }
        else return 0;
    }
}
void freetree(Tree T){
    if(T->left)
        freetree(T->left);
    if(T->right)
        freetree(T->right);
    delete(T);
}
int Judge(Tree T,int N){
    int i,V;
    int idx=0;
    cin>>V;
    if(T->data==V)
        T->flag=1;
    else idx=1;
    for(i=1;i<N;i++){
        cin>>V;
        if(check(T,V)==0 && idx==0){
            idx=1;
        }
    }
    if(!idx)
        return 1;
    else return 0;
}
int main()
{
    int N,L;
    int data;
    Tree T;
    cin>>N;
    while(N!=0){
        cin>>L;
        T=buildtree(N);
        for(int i=0;i<L;i++){
            if(Judge(T,N))
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            Resete(T);
        }
        freetree(T);
        cin>>N;
    }
    return 0;
}
