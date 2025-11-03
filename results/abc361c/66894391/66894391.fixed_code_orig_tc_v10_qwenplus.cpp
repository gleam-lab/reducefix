#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long ans = a[n-1] - a[0];
    
    // We remove exactly K elements
    // Try all possible ways: remove i from left, K-i from right
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        
        int new_left = left_removed;
        int new_right = n - 1 - right_removed;
        
        if (new_left <= new_right) {
            ans = min(ans, (long long)(a[new_right] - a[new_left]));
        }
    }
    
    cout << ans << endl;
    
    return 0;
}