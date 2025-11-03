#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,a[N],d[N];
long long ans;
map<int,int> cnt;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    // Use prefix sum modulo m and count occurrences
    cnt[0]=1; // Empty subarray has sum 0
    int prefix=0;
    
    for(int i=1;i<=n;i++)
    {
        prefix=(prefix+a[i])%m;
        if(prefix<0) prefix+=m; // Handle negative modulo
        
        // All previous positions with same modulo contribute to answer
        ans+=cnt[prefix];
        cnt[prefix]++;
    }
    
    cout<<ans;
    return 0;
}