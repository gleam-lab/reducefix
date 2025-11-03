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
    
    // We need to remove exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    int min_diff = a[keep - 1] - a[0]; // Initial case: keep first 'keep' elements
    
    // Try all possible contiguous subarrays of length (n-k)
    // We can only keep contiguous elements in sorted order to minimize the range
    for (int i = 0; i + keep <= n; i++) {
        int current_diff = a[i + keep - 1] - a[i];
        min_diff = min(min_diff, current_diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}