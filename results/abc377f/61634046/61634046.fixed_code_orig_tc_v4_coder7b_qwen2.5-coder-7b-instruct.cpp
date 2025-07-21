#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 1e3;

ll n, m;
vector<int> row(MAX_N + 1), col(MAX_N + 1), up[2], down[2];
set<ll> captured;

void addCaptured(ll x, ll y, bool dir) {
    if (dir) {
        captured.insert(x);
    } else {
        captured.insert(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        row[i] = y, col[i] = x, up[(x + y) & 1].push_back(y - x), down[(x + y) & 1].push_back(x + y);
    }

    sort(row.begin(), row.end());
    row.erase(unique(row.begin(), row.end()), row.end());
    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());

    sort(up[0].begin(), up[0].end());
    up[0].erase(unique(up[0].begin(), up[0].end()), up[0].end());
    sort(up[1].begin(), up[1].end());
    up[1].erase(unique(up[1].begin(), up[1].end()), up[1].end());

    sort(down[0].begin(), down[0].end());
    down[0].erase(unique(down[0].begin(), down[0].end()), down[0].end());
    sort(down[1].begin(), down[1].end());
    down[1].erase(unique(down[1].begin(), down[1].end()), down[1].end());

    ll totalSquares = n * n;
    ll occupiedSquares = m;

    for (int i = 1; i <= m; ++i) {
        int x = row[i], y = col[i], d = (x + y) & 1;
        addCaptured(x, y, true);
        addCaptured(y, x, false);
        addCaptured(y - x, d, true);
        addCaptured(x + y, d, false);
    }

    for (auto& c : captured) {
        totalSquares -= 1;
    }

    cout << totalSquares << endl;

    return 0;
}