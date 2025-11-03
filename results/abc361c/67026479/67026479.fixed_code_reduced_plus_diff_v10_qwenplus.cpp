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
    long long dmin = 1e18; // use large initial value to avoid issues
    
    // We need to choose a contiguous segment of length m in the sorted array
    // because removing non-contiguous elements would only increase the range
    for (int i = 0; i + m - 1 < n; i++) {
        long long d = a[i + m - 1] - a[i];
        dmin = min(dmin, d);
    }
    
    cout << dmin << endl;
    return 0;
}