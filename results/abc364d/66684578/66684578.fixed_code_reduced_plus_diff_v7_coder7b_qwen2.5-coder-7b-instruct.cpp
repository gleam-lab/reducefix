#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n), b(q);
    vector<int> k(q);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; ++i) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int dist = min(abs(it - a.begin()), abs(it - a.end()));
        
        if (dist == 0) {
            dist = a[0] > b[i] ? a[0] - b[i] : b[i] - a.back();
        } else if (it == a.begin()) {
            dist = a[0] - b[i];
        } else if (it == a.end()) {
            dist = b[i] - a.back();
        } else {
            dist = min(b[i] - *(it - 1), *it - b[i]);
        }
        
        for (int j = 1; j < k[i]; ++j) {
            if (it == a.begin()) {
                dist += a[0] - b[i];
            } else if (it == a.end()) {
                dist += b[i] - a.back();
            } else {
                dist += min(b[i] - *(it - 1), *it - b[i]);
                if (it != a.begin() && it != a.end()) {
                    ++it;
                }
            }
        }
        
        cout << dist << '\n';
    }
    
    return 0;
}