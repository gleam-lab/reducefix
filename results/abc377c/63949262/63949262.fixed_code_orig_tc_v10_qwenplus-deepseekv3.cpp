#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> attacked;
    vector<pair<ll, ll>> pieces(M);

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = make_pair(a, b);
        attacked.insert(pieces[i]);
    }

    // Directions for knight moves
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (const auto &p : pieces) {
        ll x = p.first;
        ll y = p.second;
        for (int k = 0; k < 8; ++k) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert(make_pair(nx, ny));
            }
        }
    }

    ll total_safe = N * N - attacked.size();
    cout << total_safe << endl;

    return 0;
}