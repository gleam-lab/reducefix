#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],cnt[N];
long long ans;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    // Count prefix sums modulo m
    cnt[0]=1;  // Empty prefix has sum 0
    int prefix=0;
    for(int i=1;i<=n;i++)
    {
        prefix=(prefix+a[i])%m;
        ans+=cnt[prefix];
        cnt[prefix]++;
    }
    
    cout<<ans;
    return 0;
}