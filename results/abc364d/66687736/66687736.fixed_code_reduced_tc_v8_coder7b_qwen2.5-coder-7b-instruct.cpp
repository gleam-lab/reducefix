#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<ll, int>>> queries(q);
    for (int i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        queries[i] = {{abs(a[j] - b), j} for j in range(n)};
        sort(queries[i].begin(), queries[i].end());
    }
    
    for (auto& query : queries) {
        cout << query[k - 1].first << '\n';
    }
    
    return 0;
}