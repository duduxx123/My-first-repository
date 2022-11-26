#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    if(M>N)//考虑M比N大的情况
        M=M%N;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int b[N];
    int flag=M-1;
    for(int i=N-1;i>N-M-1 && flag>=0;i--){
        b[flag]=arr[i];
        flag--;
    }
    flag=M;
    for(int i=0;i<N && flag<N;i++){
        b[flag]=arr[i];
        flag++;
    }
    
    for(int i=0;i<N;i++){
        if(i!=N-1)
            cout<<b[i]<<" ";
        else cout<<b[i];
    }
    return 0;
}
