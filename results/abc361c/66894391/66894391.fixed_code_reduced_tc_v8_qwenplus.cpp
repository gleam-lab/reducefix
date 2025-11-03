#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long ans = a[n-1] - a[0];
    
    // Try all possible ways to remove k elements from left and right
    // We can remove i elements from the left and (k-i) elements from the right
    for (int i = 0; i <= k; i++) {
        int left_idx = i;
        int right_idx = n - 1 - (k - i);
        
        if (left_idx <= right_idx) {
            ans = min(ans, (long long)a[right_idx] - a[left_idx]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}