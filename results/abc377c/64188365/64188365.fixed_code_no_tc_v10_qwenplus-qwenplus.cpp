#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;

    vector<pair<ll, ll>> move_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (auto [dx, dy] : move_offsets) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                occupied.insert({nx, ny});
            }
        }
    }

    cout << (N * N - (ll)occupied.size()) << endl;
}