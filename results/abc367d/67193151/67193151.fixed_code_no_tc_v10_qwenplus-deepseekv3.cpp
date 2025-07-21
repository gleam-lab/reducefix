#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5; // Increased size to handle circular case
int n,m,d[N],cnt[N];
long long sum; // Changed to long long to prevent overflow

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        d[i+n]=d[i]; // Create circular array
    }
    
    // Compute prefix sums
    for(int i=1;i<=2*n;i++)
        d[i]=(d[i-1]+d[i])%m;
    
    cnt[0]=1; // Initialize with empty prefix sum
    sum=0;
    
    // Count for first n elements (non-circular case)
    for(int i=1;i<=n;i++)
    {
        sum += cnt[d[i]];
        cnt[d[i]]++;
    }
    
    // Now handle the circular case by sliding window
    for(int i=n+1;i<=2*n;i++)
    {
        cnt[d[i-n]]--; // Remove the prefix that's now outside window
        sum += cnt[d[i]];
        cnt[d[i]]++;
    }
    
    cout<<sum;
    return 0;
}