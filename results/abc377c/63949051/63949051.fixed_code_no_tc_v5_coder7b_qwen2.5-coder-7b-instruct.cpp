#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<ll, ll>> board;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            board.insert({i, j});
        }
    }

    for (auto& piece : pieces) {
        ll x = piece.first, y = piece.second;
        if (x + 2 < n && y + 1 < n) board.erase({x + 2, y + 1});
        if (x + 1 < n && y + 2 < n) board.erase({x + 1, y + 2});
        if (x - 1 >= 0 && y + 2 < n) board.erase({x - 1, y + 2});
        if (x - 2 >= 0 && y + 1 < n) board.erase({x - 2, y + 1});
        if (x - 2 >= 0 && y - 1 >= 0) board.erase({x - 2, y - 1});
        if (x - 1 >= 0 && y - 2 >= 0) board.erase({x - 1, y - 2});
        if (x + 1 < n && y - 2 >= 0) board.erase({x + 1, y - 2});
        if (x + 2 < n && y - 1 >= 0) board.erase({x + 2, y - 1});
    }

    cout << board.size() << endl;

    return 0;
}