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
    
    // We remove exactly K elements, leaving (n - k) elements
    // To minimize max - min of the remaining sequence,
    // we should consider contiguous segments of length (n - k) in the sorted array
    // because any non-contiguous selection can be improved by taking a contiguous block
    
    int min_diff = a[n - 1] - a[0]; // worst case: take everything
    int remaining = n - k;
    
    // Try all possible contiguous subarrays of length 'remaining'
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}