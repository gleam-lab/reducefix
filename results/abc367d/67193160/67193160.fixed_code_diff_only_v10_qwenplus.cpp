#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long sum;
int a[2*N],d[2*N];
map<int,int> b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i], a[i+n]=a[i];
    
    b[0]=1;
    for(int i=1;i<2*n;i++)
    {
        d[i]=(d[i-1]+a[i])%m;
        sum+=b[d[i]];
        b[d[i]]++;
    }
    cout<<sum;
    return 0;
}