#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<long long, int>>> queries(q);
    for (int i = 0; i < q; ++i) {
        long long b;
        int k;
        cin >> b >> k;
        queries[i] = {{b, k}, i};
    }
    
    sort(queries.begin(), queries.end());
    sort(a.begin(), a.end());
    
    vector<long long> result(q);
    int ai = 0;
    int qi = 0;
    
    while (ai < n && qi < q) {
        auto [b, k] = queries[qi].first;
        auto idx = queries[qi].second;
        
        long long dist = abs(a[ai] - b);
        if (dist <= b) {
            ++ai;
        } else {
            long long left = 0, right = n;
            while (left < right) {
                long long mid = left + (right - left) / 2;
                if (abs(a[mid] - b) > dist) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left == 0) {
                result[idx] = dist;
            } else {
                result[idx] = min(dist, abs(a[left - 1] - b));
            }
            ++qi;
        }
    }
    
    for (int i = 0; i < q; ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}