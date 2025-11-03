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
    // This means we keep (n - k) consecutive elements in the sorted array
    // The optimal remaining segment will be a contiguous subarray of length (n-k)
    // We try all possible contiguous subarrays of length (n-k)
    
    int min_diff = a[n-1] - a[0]; // Initialize with worst case
    
    for (int i = 0; i + (n - k) - 1 < n; i++) {
        int j = i + (n - k) - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}