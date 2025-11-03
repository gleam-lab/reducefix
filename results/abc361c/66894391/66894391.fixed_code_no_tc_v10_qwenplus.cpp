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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // To minimize (max - min) of the remaining sequence,
    // we should consider contiguous segments of length (n - k) in the sorted array.
    // Because rearranging isn't allowed but we can choose which to remove,
    // and after sorting, the best choices are contiguous in sorted order.
    
    int min_diff = a[n - 1] - a[0]; // worst case: keep everything
    int keep = n - k;
    
    // Try all contiguous subarrays of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}