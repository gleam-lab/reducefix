#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long min_range = LLONG_MAX;
    for (int i = 0; i <= k; ++i) {
        long long current_range = a[i + n - k - 1] - a[i];
        min_range = min(min_range, current_range);
    }
    
    cout << min_range << endl;
    
    return 0;
}