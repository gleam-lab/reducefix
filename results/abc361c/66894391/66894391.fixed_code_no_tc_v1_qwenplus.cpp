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
    int min_diff = a[n-1] - a[0]; // worst case: keep all elements
    
    // Try all possible contiguous segments of length (n-k)
    // Since the array is sorted, the optimal remaining elements must be contiguous
    // to minimize max - min
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}