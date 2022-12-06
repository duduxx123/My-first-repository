# N皇后问题
``` C++
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
int queen[100];
void NQueen(int k){
    int i;
    if(N==k){
        for(i=0;i<N;i++){
            cout<<queen[i]+1<<" ";
        }
        cout<<endl;
        return;
    }
    for(i=0;i<N;i++){
        int j;
        for(j=0;j<k;j++){
            if(i==queen[j] || (std::abs(i-queen[j]) == std::abs(k-j)))
            break;
        }
        if(j==k){
            queen[k]=i;
            NQueen(k+1);
        }
    }
    
}
int main(){
    cin>>N;
    NQueen(0);
    return 0;
}
```
