#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> unsafe;
    vector<pair<ll, ll>> pieces(M);

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unsafe.insert({a, b});
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto [a, b] : pieces) {
        for (int k = 0; k < 8; ++k) {
            ll ni = a + dx[k];
            ll nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                unsafe.insert({ni, nj});
            }
        }
    }

    cout << N * N - unsafe.size() << endl;
    return 0;
}