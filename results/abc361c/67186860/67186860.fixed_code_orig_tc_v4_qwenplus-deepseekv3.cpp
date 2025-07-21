#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int ans = a[n-1] - a[0];  // Initialize with the maximum possible difference
    
    for (int i = 0; i <= k; ++i) {
        // Remove i elements from the start and (k - i) elements from the end
        int current_diff = a[n - 1 - (k - i)] - a[i];
        if (current_diff < ans) {
            ans = current_diff;
        }
    }
    
    cout << ans << endl;
    return 0;
}