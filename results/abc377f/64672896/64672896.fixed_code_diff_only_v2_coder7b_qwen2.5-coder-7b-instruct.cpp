#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll, ll>> pieces(M);
    set<ll> rows, cols, diag1, diag2;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll count = 0;
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j <= N; ++j) {
            if (rows.find(i) != rows.end()) continue;
            if (cols.find(j) != cols.end()) continue;
            if (diag1.find(i + j) != diag1.end()) continue;
            if (diag2.find(i - j) != diag2.end()) continue;
            ++count;
        }
    }

    cout << count << '\n';

    return 0;
}