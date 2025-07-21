#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    vector<long long> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[n - i];
    }
    
    vector<long long> results(n);
    for (int i = 0; i < n; ++i) {
        long long needed = 0;
        if (prefix_sum[m - 1] + a[i] < k) {
            needed = k - prefix_sum[m - 1] - a[i];
        }
        results[i] = needed;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}