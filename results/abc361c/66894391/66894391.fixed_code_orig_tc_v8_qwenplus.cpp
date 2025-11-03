#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We need to remove exactly K elements, leaving N-K elements.
    // The remaining elements must be contiguous in the sorted array to minimize range.
    // Try all possible contiguous subarrays of length (n - k)
    int min_diff = INT_MAX;
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}