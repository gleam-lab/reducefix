#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],prefix[2*N+1],cnt[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i+n] = a[i]; // create circular array
    }
    
    // Compute prefix sums
    prefix[0] = 0;
    for(int i=1;i<=2*n;i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m; // ensure positive
    }
    
    long long result = 0;
    cnt[0] = 1; // empty prefix
    
    for(int i=1;i<=2*n;i++) {
        if(i > n) {
            // Remove the element that is sliding out of the window
            cnt[prefix[i-n]]--;
        }
        result += cnt[prefix[i]];
        if(i <= n) {
            // Only add to count for the first half (original array)
            cnt[prefix[i]]++;
        }
    }
    
    cout<<result;
    return 0;
}