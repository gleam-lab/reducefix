#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[N], prefix[N], cnt[N]; // Changed to long long to prevent overflow

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // Read input and compute prefix sums
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= m; // Take modulo immediately to prevent overflow
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    // For circular case, we consider the array as a[1..n] followed by a[1..n-1]
    // So total elements is 2n-1
    long long total = 0;
    cnt[0] = 1; // Initialize for empty prefix
    
    // Process the circular array (first n elements are original array)
    for(int i=1; i<=2*n-1; i++) {
        int idx = (i <= n) ? i : i - n;
        prefix[i] = (prefix[i-1] + a[idx]) % m;
        
        // Remove the count that's now out of range (when window size > n)
        if(i > n) {
            int out_idx = i - n;
            cnt[prefix[out_idx-1]]--;
        }
        
        total += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }
    
    cout << total;
    return 0;
}