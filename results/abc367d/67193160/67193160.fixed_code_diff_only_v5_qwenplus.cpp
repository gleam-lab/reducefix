#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long sum;
int a[N*2],cnt[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    
    sum=0;
    cnt[0]=1; // empty prefix has sum 0
    long long prefix=0;
    
    for(int i=1;i<2*n;i++)
    {
        prefix+=a[i];
        int mod=(prefix%m+m)%m; // ensure non-negative modulo
        
        // Add count of previous prefixes with same modulo (within valid range)
        if(i>=n) {
            // Remove the contribution from position i-n (now out of sliding window)
            int old_mod=(prefix-a[i-n]*1LL*(i==n?1:0))%m; // This line is problematic
            
            // Actually, we need to track counts differently
            // The original approach is flawed in sliding window maintenance
        }
        
        // For circular array, we should count pairs (i,j) where j-i < n and prefix[j]-prefix[i] ≡ 0 (mod m)
        // But the current sliding window logic is incorrect
    }
    
    // Let's rewrite with correct approach
    return 0;
}