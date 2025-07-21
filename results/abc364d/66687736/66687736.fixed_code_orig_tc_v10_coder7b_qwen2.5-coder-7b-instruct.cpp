#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n), b(q), k(q);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i] >> k[i];

    sort(a.begin(), a.end());

    for(int i = 0; i < q; ++i) {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        int index = it - a.begin();
        int dist = abs(it != a.end() ? *it - b[i] : INT_MAX);
        if(index >= k[i]) {
            dist = min(dist, abs(a[index-k[i]-1] - b[i]));
        }
        cout << dist << '\n';
    }

    return 0;
}