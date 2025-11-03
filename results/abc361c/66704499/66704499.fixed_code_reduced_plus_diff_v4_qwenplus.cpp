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
    // The remaining elements must be contiguous in the sorted array to minimize range.
    // Try all possible contiguous subarrays of length (n - k)
    
    int min_range = a[n - 1] - a[0]; // worst case: keep everything
    
    for (int left = 0; left + (n - k) <= n; left++) {
        int right = left + (n - k) - 1;
        min_range = min(min_range, a[right] - a[left]);
    }
    
    cout << min_range << endl;
    
    return 0;
}