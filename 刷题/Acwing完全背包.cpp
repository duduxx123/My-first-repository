#include <iostream>
using namespace std;
const int MAX = 1010;
int N,V;
int tiji[MAX],value[MAX];
int f[MAX];
int main()
{
    cin>>N>>V;
    int i,j;
    for(i=1;i<=N;i++)
        cin>>tiji[i]>>value[i];
    for(i=1;i<=N;i++)
        for(j=tiji[i];j<=V;j++){
             f[j] = max(f[j], f[j-tiji[i]]+value[i]);
        }
    cout<<f[V]<<endl;
    return 0;
}
