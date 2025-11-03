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
    
    int m = n - k; // number of remaining elements
    long long min_diff = 1e18;
    
    // We need to choose a contiguous segment of length m in the sorted array
    // because removing K elements optimally means keeping a contiguous block
    for (int i = 0; i <= n - m; i++) {
        long long diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}