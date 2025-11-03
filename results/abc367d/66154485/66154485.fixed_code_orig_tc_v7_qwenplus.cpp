#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    
    // For each starting position
    for (int start = 0; start < n; start++) {
        int sum = 0;
        // Consider all possible lengths from 1 to n-1 (non-full circular subarrays)
        for (int len = 1; len < n; len++) {
            int idx = (start + len) % n;
            sum = (sum + arr[idx]) % m;
            if (sum % m == 0) {
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}