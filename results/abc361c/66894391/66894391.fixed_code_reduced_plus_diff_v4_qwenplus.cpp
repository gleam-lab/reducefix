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
    
    // We are removing exactly K elements
    // So we keep (n - k) elements
    int keep = n - k;
    long long min_diff = 1e18;
    
    // Try all possible contiguous subarrays of length 'keep'
    // in the sorted array
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, (long long)(a[j] - a[i]));
    }
    
    cout << min_diff << endl;
    
    return 0;
}