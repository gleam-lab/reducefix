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
    
    // We are removing exactly K elements
    // The remaining sequence has size n - k
    // We want to minimize (max - min) of the remaining elements
    
    // Since array is sorted, any valid remaining subsequence must be contiguous
    // So we try all possible contiguous segments of length (n - k)
    long long ans = 1e18;
    int rem = n - k;
    
    for (int i = 0; i + rem - 1 < n; i++) {
        ans = min(ans, (long long)a[i + rem - 1] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}