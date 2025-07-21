#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,sum,a[N],prefix[2*N],cnt[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i+n] = a[i];  // Create circular array
    }
    
    // Compute prefix sums
    prefix[0] = 0;
    for(int i=1;i<=2*n;i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    // Initialize cnt[0] to 1 for prefix[0] = 0
    cnt[0] = 1;
    long long total = 0;
    
    // Count for non-circular case (first n elements)
    for(int i=1;i<=n;i++) {
        total += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    // Now handle the circular case by sliding window of size n
    // Subtract counts from the first window
    for(int i=1;i<=n;i++) {
        cnt[prefix[i]]--;
    }
    
    // Add counts for the remaining windows
    for(int i=n+1;i<=2*n;i++) {
        total += cnt[prefix[i]];
        cnt[prefix[i]]++;
        cnt[prefix[i-n]]--;
    }
    
    cout<<total;
    return 0;
}