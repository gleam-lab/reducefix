#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
vector<ll> a, b;
vector<array<ll, 3>> queries;

bool cmp(const array<ll, 3>& x, const array<ll, 3>& y) {
    return x[2] < y[2];
}

void solve() {
    sort(queries.begin(), queries.end(), cmp);
    multiset<pair<ll, int>> s;
    int i = 0, n = a.size();
    for (auto [x, y, idx] : queries) {
        while (i < n && a[i] <= y) {
            s.insert({abs(a[i] - y), i});
            ++i;
        }
        while (!s.empty() && (*s.rbegin()).first > y) {
            s.erase(prev(s.end()));
        }
        if (!s.empty()) {
            cout << (*s.begin()).first << '\n';
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        ll y, k;
        cin >> y >> k;
        --k;
        queries.push_back({y, a[k], k});
    }
    
    solve();
    
    return 0;
}