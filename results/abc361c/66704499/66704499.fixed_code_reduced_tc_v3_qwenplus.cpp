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
    
    long long ans = 1e18;
    
    // Try all possible ways to remove k elements from the ends
    // Remove i elements from left and (k - i) elements from right
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = n - 1 - (k - i);
        
        if (left <= right) {
            ans = min(ans, (long long)a[right] - a[left]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}