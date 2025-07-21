#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> a(n), b(n);
    long long sum = 0, max_votes = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        max_votes = max(max_votes, a[i]);
    }
    
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
    
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        c[i] = accumulate(b.begin(), b.begin() + i + 1, 0LL);
    }

    vector<long long> res(n, -1);
    
    for (int i = 0; i < n; ++i) {
        long long needed = max(0LL, m - c[n - 1] + a[i] + 1 - a[i]);
        if (needed <= k - sum + a[i]) {
            res[i] = needed;
        }
    }
    
    for (auto &r : res) {
        cout << r << " ";
    }
    
    return 0;
}