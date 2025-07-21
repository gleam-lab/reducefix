#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long a[N], prefix[N];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Create circular array
    }
    
    prefix[0] = 0;
    freq[0] = 1; // To count prefix sums that are 0 mod m
    
    long long res = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        if(prefix[i] < 0) prefix[i] += m; // Ensure positive
        
        // Only count if we're in the first n elements
        if(i <= n) {
            res += freq[prefix[i]];
            freq[prefix[i]]++;
        } else {
            // Remove the contribution from the element that's now out of window
            int idx = i - n;
            freq[prefix[idx-1]]--;
            res += freq[prefix[i]];
        }
    }
    
    cout << res;
    return 0;
}