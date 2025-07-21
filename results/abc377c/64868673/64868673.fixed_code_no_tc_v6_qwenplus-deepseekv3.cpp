#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> forbidden;

    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        for (int j = 0; j < 8; ++j) {
            ll x = a + dx[j];
            ll y = b + dy[j];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    ll total = N * N;
    ll unsafe = forbidden.size();
    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}