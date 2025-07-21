#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Precompute the prefix sums modulo m
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (arr[i] + prefix[i]) % m;
    }
    
    // Count the number of valid subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((prefix[j] - prefix[i]) % m == 0) {
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}