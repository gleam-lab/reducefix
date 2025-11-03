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
    // The remaining sequence will have (n - k) elements
    // We want to minimize (max - min) of the remaining elements
    
    // Key insight: After sorting, the optimal remaining elements
    // will form a contiguous subarray of length (n-k)
    // So we try all possible contiguous subarrays of length (n-k)
    
    int min_diff = a[n-1] - a[0]; // worst case: keep everything
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        int diff = a[j] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}