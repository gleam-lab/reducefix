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
    // we can only keep a contiguous segment in the sorted array.
    // Why? Because if we skip an element inside the range, we could potentially
    // get a smaller range by shifting the window.
    
    int min_diff = INT_MAX;
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}