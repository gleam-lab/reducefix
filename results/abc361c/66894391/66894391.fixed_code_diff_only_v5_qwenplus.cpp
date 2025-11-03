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
    // The remaining sequence will have n-k elements
    // We want to minimize (max - min) of the remaining elements
    
    // Key insight: The optimal remaining subsequence must be contiguous in the sorted array
    // Why? Because if we skip some element in the middle, we could potentially get a smaller range
    // So we try all possible contiguous subarrays of length (n-k)
    
    int min_range = a[n-1] - a[0]; // worst case: keep everything
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        min_range = min(min_range, a[j] - a[i]);
    }
    
    cout << min_range << endl;
    
    return 0;
}