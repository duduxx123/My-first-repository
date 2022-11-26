#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
int isPrime(int n){//判断是否为素数
    if(n<2)
        return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0)
            return 0;//如果不是素数返回0
    }
    return 1;
}
int main(){
    int N;
    cin>>N;
    int count=0;
    int pri=2;
    for(int i=3;i<=N;i++){
        if(isPrime(i)){
            if(i-pri == 2){
                count++;
            }
            pri=i;
        }
    }
    cout<<count<<endl;
    return 0;
}
