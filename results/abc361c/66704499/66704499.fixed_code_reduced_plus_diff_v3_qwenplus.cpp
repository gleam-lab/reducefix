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
    
    // We remove exactly K elements, so we keep (n - k) elements.
    // To minimize (max - min) of the remaining sequence,
    // we can only keep a contiguous segment of length (n - k) in the sorted array.
    // Why? Because if we skip some element inside the range, we could potentially get a smaller range.
    
    int min_range = INT_MAX;
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_range = min(min_range, a[j] - a[i]);
    }
    
    cout << min_range << endl;
    
    return 0;
}