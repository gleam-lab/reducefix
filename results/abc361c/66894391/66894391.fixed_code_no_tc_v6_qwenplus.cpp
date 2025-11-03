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
    
    // We need to keep (n - k) elements
    int keep = n - k;
    int min_diff = a[keep - 1] - a[0]; // Initial case: first 'keep' elements
    
    // Try all possible contiguous subarrays of length (n-k)
    // We can remove k elements, so we keep a contiguous segment of (n-k) elements
    for (int i = 0; i + keep <= n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}