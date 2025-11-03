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
    
    // We remove exactly K elements, so we keep (n - k) elements.
    // The optimal way is to remove some prefix and suffix such that total removed = k.
    // Try all possible combinations: remove i from left, k-i from right.
    long long ans = 1e18;
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        int remaining_left = left_removed;
        int remaining_right = n - 1 - right_removed;
        
        if (remaining_left <= remaining_right) {
            ans = min(ans, (long long)(a[remaining_right] - a[remaining_left]));
        }
    }
    
    cout << ans << endl;
    
    return 0;
}