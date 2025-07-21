#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;
vector<pair<int, int>> queries;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) {
        cin >> b[i] >> queries[i].second;
        queries[i].first = i;
    }

    sort(a.begin(), a.end());
    sort(queries.begin(), queries.end());

    vector<long long> res(q);
    int ai = 0;
    for(auto& [qi, k]: queries) {
        while(ai < n && abs(a[ai] - b[qi]) < abs(a[ai - 1] - b[qi])) ai++;
        res[qi] = abs(a[ai - k] - b[qi]);
    }

    for(auto& x: res) cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}