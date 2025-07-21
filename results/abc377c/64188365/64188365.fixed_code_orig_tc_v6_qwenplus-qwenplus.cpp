#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> attacked;

    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        occupied.emplace(a, b);
        // Mark all squares this piece can attack
        for (auto& [dx, dy] : moves) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                attacked.emplace(na, nb);
            }
        }
    }

    // Remove occupied squares from attacked set
    for (auto& p : occupied) {
        attacked.erase(p);
    }

    // Total empty squares = total squares - occupied squares
    ll total_empty = N * N - occupied.size();
    // Subtract the number of attacked squares
    ll result = total_empty - attacked.size();

    cout << result << endl;

    return 0;
}