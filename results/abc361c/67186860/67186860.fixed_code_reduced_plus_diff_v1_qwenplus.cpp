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
    
    // We are going to remove exactly K elements
    // The remaining sequence has length m = n - k
    // To minimize max - min in the remaining array,
    // we can only keep a contiguous subarray of length m from the sorted array
    // because if gaps exist, we could get a smaller range by shifting
    
    int m = n - k;
    long long ans = 1e18;
    
    // Try all possible contiguous subarrays of length m
    for (int i = 0; i + m - 1 < n; i++) {
        ans = min(ans, (long long)a[i + m - 1] - a[i]);
    }
    
    cout << ans << endl;
    return 0;
}