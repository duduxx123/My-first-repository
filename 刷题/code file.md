//Acwing 01背包问题(优化后)

//注释部分为优化为一维数组前
``` C++
#include <iostream>
using namespace std;
const int MAX = 1010;
int N,V;
int tiji[MAX],value[MAX];
//int dp[MAX][MAX];
int f[MAX];
int main()
{
    cin>>N>>V;
    int i,j;
    for(i=1;i<=N;i++)
        cin>>tiji[i]>>value[i];
    // for(i=1;i<=N;i++)
    //     for(j=1;j<=V;j++)
    //     {
    //         if(j<tiji[i])
    //             dp[i][j]=dp[i-1][j];
    //         else dp[i][j]=max(dp[i-1][j-tiji[i]]+value[i],dp[i-1][j]);
    //     }
    for(i=1;i<=N;i++)
        for(j=V;j>=tiji[i];j--){
             f[j] = max(f[j], f[j-tiji[i]]+value[i]);
        }
    //cout<<dp[N][V]<<endl;
    cout<<f[V]<<endl;
    return 0;
}
```
