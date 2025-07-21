#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> under_attack;
    vector<pair<ll, ll>> knights(M);

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        knights[i] = {a, b};
        under_attack.insert({a, b});
    }

    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (auto knight : knights) {
        ll a = knight.first;
        ll b = knight.second;
        for (int k = 0; k < 8; ++k) {
            ll x = a + dx[k];
            ll y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                under_attack.insert({x, y});
            }
        }
    }

    ll total_safe = N * N - under_attack.size();
    cout << total_safe << '\n';

    return 0;
}