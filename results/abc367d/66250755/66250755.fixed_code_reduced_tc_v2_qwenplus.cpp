#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    vector<int> prefix(2 * n + 1, 0);
    map<int, int> count;
    long long ans = 0;
    
    // Initialize with prefix sum 0
    count[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        
        // When we reach beyond the first n elements, start removing old counts
        if (i > n) {
            count[prefix[i - n]]--;
        }
        
        // Add number of previous prefix sums that would form valid subarrays ending at i
        ans += count[prefix[i]];
        
        // Add current prefix sum to the map
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}