#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e9;

int n, m;
vector<pair<int, int>> pieces;

bool canPlace(int i, int j) {
    for (auto [x, y] : pieces) {
        if (i == x || j == y || i + j == x + y || i - j == x - y) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for (auto& p : pieces) {
        cin >> p.first >> p.second;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (canPlace(i, j)) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}