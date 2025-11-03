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
    // To minimize (max - min) of the remaining sequence, we should consider
    // contiguous subarrays of length (n - k) in the sorted array
    // because non-contiguous selections would only increase the range
    
    int min_range = a[n - 1] - a[0]; // Initialize with worst case
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_range = min(min_range, a[j] - a[i]);
    }
    
    cout << min_range << endl;
    
    return 0;
}