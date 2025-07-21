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
    
    int ans = INT_MAX;
    // Try all possible splits: i elements from the start and k-i from the end
    for (int i = 0; i <= k; ++i) {
        int start = i;
        int end = n - (k - i);
        if (start >= end) continue; // Not enough elements left
        ans = min(ans, a[end - 1] - a[start]);
    }
    cout << ans << endl;
    return 0;
}