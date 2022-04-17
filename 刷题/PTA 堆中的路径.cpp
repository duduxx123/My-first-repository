#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXN 1001
#define MINH -10001
typedef struct HeapStruct{
    int H[MAXN];
    int size;
}*Heap;
Heap Create(){//建立空最小堆
    Heap P=new struct HeapStruct;
    P->size=0;
    P->H[0]=MINH;
    return P;
}
void Insert(int X,Heap P){
    int i;
    if(P->size==MAXN-1){
        cerr<<"最小堆已满"<<endl;
        return;
    }
    i=++P->size;
    for(;P->H[i/2]>X;i/=2)
        P->H[i]=P->H[i/2];
    P->H[i]=X;
}
void findandprint(int data,Heap p){
    for(int i=data;i>=1;i/=2){
        cout<<p->H[i];
        if(i!=1)
            cout<<" ";
    }
    cout<<endl;
}
int main(void){
    int num,finum;
    int data,find;
    Heap p=Create();
    cin>>num>>finum;
    for(int i=0;i<num;i++){
        cin>>data;
        Insert(data,p);
    }
    for(int i=0;i<finum;i++){
        cin>>find;
        findandprint(find,p);
    }
    return 0;
}