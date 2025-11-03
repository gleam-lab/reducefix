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
    // The remaining elements must be contiguous in the sorted array to minimize the range.
    // Try all possible contiguous segments of length (n - k)
    int min_range = INT_MAX;
    int keep = n - k;
    
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_range = min(min_range, a[j] - a[i]);
    }
    
    cout << min_range << endl;
    
    return 0;
}