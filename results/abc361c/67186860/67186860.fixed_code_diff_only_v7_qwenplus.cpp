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
    
    // We need to remove exactly K elements
    // The remaining sequence has n-k elements
    // We want to minimize (max - min) of the remaining elements
    // Since the array is sorted, we can only keep a contiguous subarray
    // Try all possible contiguous subarrays of length n-k
    
    int ans = a[n-1] - a[0]; // worst case: keep everything
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        ans = min(ans, a[j] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}